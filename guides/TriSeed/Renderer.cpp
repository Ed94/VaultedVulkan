// Parent Header
#include "Renderer.hpp"



namespace Backend
{
    // Utility Functions (Don't be afraid to take these with you!)

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

				LOG("Validation Layer Enabled: Khronos");

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

					LOG("Validation Layer Enabled: LunarG Standard");

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

					LOG(std::string("Validation Layer Enabled: ") + std::string(validationLayerName));
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

					LOG("Validation Layer Enabled: LunarG Core");

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
		      void*                      /*_userData*/
	)
	{
		using EServerity = Messenger::EServerity;

		LOG(_callbackData.Message);

		return EBool::True;
	}


    // VKGPU

    VKGPU::VKGPU(Window& _window) : messenger(appGPU)
    {
		LOG("Creating Vulkan GPU backend.");

		StartCommunication();

		EngageSuitableDevice(_window);

        // InitalizeResources();

        // SetupCommands();

        start = std::chrono::high_resolution_clock::now();
    }

    VKGPU::~VKGPU()
    {
        device.WaitUntilIdle();   

        // DestroyCommands();

        // DestroyResources();

        CeaseCommunication();
    }

    void VKGPU::StartCommunication()
    {
		LOG("Preparing for GPU app handshake...");

        std::vector<LayerAndExtensionProperties> installedAppExtensions;

		// Gives us all available layers and extensions for all vulkan compatible devices on this machine.
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
        AquireSupportedValidationLayers(installedLayerAndExtensions, desiredLayers);

		// Make sure the layers we are going to use are available to enable.
        if (CheckLayerSupport(installedLayerAndExtensions, desiredLayers)) LOG("Layers desired supported!");

        else throw std::runtime_error("Error: Layers desired not supported.");

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

		// Were going to add a debug call back for vulkan related validation logs.
		Messenger::CreateInfo messengerInfo;

		using EServerity   = Messenger::EServerity  ;
		using EMessageType = Messenger::EMessageType;

		messengerInfo.Serverity.Set(EServerity  ::Verbose, EServerity  ::Warning   , EServerity  ::Error      );
		messengerInfo.Type     .Set(EMessageType::General, EMessageType::Validation, EMessageType::Performance);

		messengerInfo.UserCallback = GetVTAPI_Call(DebugCallback);
		                             // A debug callback must follow the vulkan calling convention.

		EResult 
        returnCode = appVk.Create(info);   // Create the application instance.

		if (returnCode != EResult::Success) throw std::runtime_error("Failed to create the vulkan application instance.");

        LOG("Vulkan application instance created!");

		returnCode = messenger.Create(messengerInfo);   // Create the messenger object.

		if (returnCode != EResult::Success) throw std::runtime_error("Failed to create the debug messenger.");	

        LOG("Debug messenger created!");

		// Populating physical devices...

        std::vector<PhysicalDevice> physicalDevices;

		returnCode = appVk.GetAvailablePhysicalDevices(physicalDevices);

        if (returnCode != EResult::Success) throw std::runtime_error("Failed to get any physical devices.");

        LOG("\nSupported physical devices aquired:");

        // gpus.resize(phsyicalDevices.size());

        std::stringstream gpuHandle;

        // Cycle through the gpu listing and populate/print out some information.
        for (auto& physicalDevice : physicalDevices)
        {
            gpus.push_back( PhysicalGPU(physicalDevice, installedLayerAndExtensions) );

            // Populate information

            auto& gpu = gpus.back();

            returnCode = EResult::Incomplete;

            for (auto& layerAndExtensions : gpu.LayersAndExtensions)
            {
                physicalDevice.GetAvailableExtensions(layerAndExtensions.Layer.Name, layerAndExtensions.Extensions);
            }

            gpu.QueueFamilyProperties = physicalDevice.GetAvailableQueueFamilies();

            // Log info

            gpuHandle.str(std::string());

            gpuHandle << physicalDevice;

            LOG(physicalDevice.GetProperties().Name + std::string(" Handle: ") + gpuHandle.str() + std::string("\n"));
        }

		LOG("Vulkan application handshake complete!");
    }

	void VKGPU::CeaseCommunication()
	{

	}

	void VKGPU::EngageSuitableDevice(Window& _window)
	{
        std::vector<const char*> deviceExtensions;
	}
}