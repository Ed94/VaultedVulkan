// Parent Header
#include "Renderer.hpp"



namespace Backend
{
    // Utility Functions

    void AquireSupportedValidationLayers
    (
        std::vector<LayerAndExtensionProperties>& _installedAppExtensions,
        std::vector<const char*>&                 _desiredLayers
    )
    {
        bool found = false;

		// Ideal

		for (const auto& layerAndExtenions : _installedAppExtensions)
		{
			if (strcmp(Layer::Khronos_Validation, layerAndExtenions.Layer.Name) == 0)
			{
				_desiredLayers.push_back(Layer::Khronos_Validation);

				std::cout << "Validation Layer Enabled: Khronos" << std::endl;

				found = true;

				break;
			}
		}

		// Fallback 1

		if (!found)
		{
			for (const auto& layerAndExtenions : _installedAppExtensions)
			{
				if (strcmp(Layer::LunarG_StandardValidation, layerAndExtenions.Layer.Name) == 0)
				{
					_desiredLayers.push_back(Layer::LunarG_StandardValidation);

					std::cout << "Validation Layer Enabled: LunarG Standard" << std::endl;

					found = true;

					break;
				}
			}
		}

		// Fallback 2

		if (!found)
		{
			std::array<const char*, 4> Fallback2Layers 
			{
				Layer::LunarG_ParameterValidation,
				Layer::LunarG_ObjectTracker      ,
				Layer::Google_Threading          ,
				Layer::Google_UniqueObjedcts
			};

			std::size_t layersFound = 0;

			for (auto validationLayerName : Fallback2Layers)
			{
				for (const auto& layerAndExtenions : _installedAppExtensions)
				{
					if (strcmp(validationLayerName, layerAndExtenions.Layer.Name) == 0)
					{
						layersFound++;

						break;
					}
				}
			}

			if (layersFound == Fallback2Layers.size()) 
			{
				for (auto validationLayerName : Fallback2Layers)
				{
					_desiredLayers.push_back(validationLayerName);

					std::cout << "Validation Layer Enabled: " + std::string(validationLayerName) << std::endl;
				}

				found = true;
			}
		}

		// Fallback 3

		if (!found)
		{
			for (const auto& layerAndExtenions : _installedAppExtensions)
			{
				if (strcmp(Layer::LunarG_CoreValidation, layerAndExtenions.Layer.Name) == 0)
				{
					_desiredLayers.push_back(Layer::LunarG_CoreValidation);

					std::cout << "Validation Layer Enabled: LunarG Core" << std::endl;

					found = true;

					break;
				}
			}
		}
    }

    bool CheckLayerSupport
    (
        std::vector<LayerAndExtensionProperties>& _installedAppExtensions, 
        std::vector<const char*>                  _layersSpecified
    )
	{
		std::size_t layersFound = 0;

		for (auto validationLayerName : _layersSpecified)
		{
			for (const auto& layerAndExtenions : _installedAppExtensions)
			{
				if (strcmp(validationLayerName, layerAndExtenions.Layer.Name) == 0)
				{
					layersFound++;

					break;
				}
			}
		}

		if (!layersFound == _layersSpecified.size())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	using Messenger = DebugUtils::Messenger;

    Bool DebugCallback
	(
		      Messenger::ServerityFlags  _messageServerity, 
		      Messenger::TypeFlags       /*_messageType*/ ,
		const Messenger::CallbackData    _callbackData    , 
		      void*                                  /*_userData*/
	)
	{
		using EServerity = Messenger::EServerity;

		std::cerr << _callbackData.Message << std::endl;

		return EBool::True;
	}


    // VKGPU

    VKGPU::VKGPU(Window& _window) : messenger(appGPU)
    {
		std::cout << "Creating Vulkan GPU backend." << std::endl;

        InitalizeCommunication(_window);

        // InitalizeResources();

        // SetupCommands();

        start = std::chrono::high_resolution_clock::now();
    }

    VKGPU::~VKGPU()
    {
        device.WaitUntilIdle();   

        // DestroyCommands();

        // DestroyResources();

        // DestroyAPI();
    }

    void VKGPU::InitalizeCommunication(Window& _window)
    {


        std::vector<LayerAndExtensionProperties> installedAppExtensions;

        AppInstance::GetAvailableLayersAndExtensions(installedAppExtensions);

        std::vector<const char*> desiredExtensions =
        {
            InstanceExt::DebugUtility,   // Enables debugging features.
            InstanceExt::Surface     ,   // Enables surface presentation support.
            Surface    ::OS_Extension    // Enables os specific surface support.
        };

        std::vector<const char*> desiredDeviceExtensions = 
        {
            DeviceExt::Swapchain
        };

        std::vector<const char*> desiredLayers;

        // Get the validation layer support for the debug messenger callbacks.
        AquireSupportedValidationLayers(installedAppExtensions, desiredLayers);

        CheckLayerSupport(installedAppExtensions, desiredLayers);

        AppInstance::AppInfo appInfo;

        appInfo.AppName       = "VT Seed GPU"       ;
        appInfo.AppVersion    = MakeVersion(0, 1, 0);
        appInfo.EngineName    = "VT Seed Engine"    ;
        appInfo.EngineVersion = MakeVersion(0, 1, 0);
        appInfo.API_Version   = EAPI_Version::_1_0  ;

        AppInstance::CreateInfo info;

        info.AppInfo = &appInfo;

        info.EnabledExtensionCount = static_cast<uint32>(desiredExtensions.size());
        info.EnabledExtensionNames = desiredExtensions.data();

        info.EnabledLayerCount = static_cast<uint32>(desiredLayers.size());
        info.EnabledLayerNames = desiredLayers.data();

		Messenger::CreateInfo messengerInfo;

		using EServerity   = Messenger::EServerity  ;
		using EMessageType = Messenger::EMessageType;

		messengerInfo.Serverity.Set(EServerity  ::Verbose, EServerity  ::Warning   , EServerity  ::Error      );
		messengerInfo.Type     .Set(EMessageType::General, EMessageType::Validation, EMessageType::Performance);

		messengerInfo.UserCallback = GetVTAPI_Call(DebugCallback);
		messengerInfo.UserData     = nullptr;

		EResult returnCode = appGPU.Create(info);

		if (returnCode != EResult::Success) throw std::runtime_error("Failed to create the vulkan application instance.");

		returnCode = messenger.Create(messengerInfo);

		if (returnCode != EResult::Success) throw std::runtime_error("Failed to create the debug messenger.");	

        std::vector<const char*> deviceExtensions;

		std::cout << "Vulkan application handshake complete!" << std::endl;
    }
}