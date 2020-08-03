/**

*/

#pragma once



#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Corridors.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_SyncAndCacheControl.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Command.hpp"
#include "VT_Surface.hpp"
#include "VT_SwapChain.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		using CallbackDataFlags = Bitmask<EUndefined , Flags>;   ///< TODO: Add comment on what this is for.

		// Pointer to the Create Debug Messenger Command.
		using FPtr_CreateMessenger = PFN_vkCreateDebugUtilsMessengerEXT;

		using MessageServerityFlags = Bitmask<EDebugUtilities_MessageSeverity, Flags>;
		using MessageTypeFlags      = Bitmask<EDebugUtilities_MessageType    , Flags>;



		constexpr const char* Extension_DebugUtility = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;



		struct Label : Vault_00::VKStruct_Base<VkDebugUtilsLabelEXT, EStructureType::DebugUtils_Label_EXT>
		{
				  EType   SType    ;
			const void*   Extension;
			const char*   Name     ;
				  float32 Color[4] ;
		};

		struct ObjectInfo : Vault_00::VKStruct_Base<VkDebugUtilsObjectNameInfoEXT, EStructureType::DebugUtils_ObjectName_Info_EXT>
		{
				  EType       SType    ;
			const void*       Extension;
				  EObjectType Type     ;
				  uInt64      Handle   ;
			const char*       Name     ;
		};

		struct DebugMessenger
		{
		public:
			using Handle = VkDebugUtilsMessengerEXT;

			struct CallbackData : Vault_00::VKStruct_Base<VkDebugUtilsMessengerCallbackDataEXT, EStructureType::DebugUtils_MessengerCallback_Data_EXT>
			{
				using FlagsMask = Bitmask<EUndefined, Flags>;

					  EType       SType               ;
				const void*       Extension           ;
					  FlagsMask   Flags               ;
				const char*       MesssageIDName      ;
					  sint32      MessageIDNumber     ;
				const char*       Message             ;
					  uint32      QueueLabelCount     ;
				const Label*      QueueLabels         ;
					  uint32      CMDBufferLabel_Count;
				const Label*      CMDBufferLabels     ;
					  uint32      ObjectCount         ;
				const ObjectInfo* Objects             ;
			};

			using CallbackDelegate = VK_FPtr<Bool,
				MessageServerityFlags, MessageTypeFlags, const CallbackData, void* >;

			struct CreateInfo : Vault_00::VKStruct_Base<VkDebugUtilsMessengerCreateInfoEXT, EStructureType::DebugUtils_Messenger_CreateInfo_EXT>
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

					  EType                 SType       ;
				const void*                 Extension   ;
					  CreateFlags           Flags       ;
					  MessageServerityFlags Serverity   ;
					  MessageTypeFlags      Type        ;
					  CallbackDelegate      UserCallback;
					  void*                 UserData    ;
			};


			static EResult Create
			(
					  AppInstance::Handle         _appInstance,
				const DebugMessenger::CreateInfo& _createSpec ,
				const AllocationCallbacks*        _allocator  ,
					  DebugMessenger::Handle&     _messenger
			)
			{
				FPtr_CreateMessenger delegate = GetProcedureAddress<FPtr_CreateMessenger>(_appInstance, "vkCreateDebugUtilsMessengerEXT");

				if (delegate != nullptr)
				{
					return EResult
					(
						delegate
						(
							_appInstance,
							(const VkDebugUtilsMessengerCreateInfoEXT*)(&_createSpec),
							(const VkAllocationCallbacks*             )( _allocator ),
							(      VkDebugUtilsMessengerEXT*          )(&_messenger )
						)
					);
				}
				else
				{
					return EResult::Error_ExtensionNotPresent;
				}
			}

			static void Destroy
			(
					  AppInstance::Handle  _appInstance,
					  DebugMessenger::Handle    _messenger  ,
				const AllocationCallbacks* _allocator
			)
			{
				using FPtr_DestroyMessenger = PFN_vkDestroyDebugUtilsMessengerEXT;

				FPtr_DestroyMessenger delegate = GetProcedureAddress<FPtr_DestroyMessenger>(_appInstance, "vkDestroyDebugUtilsMessengerEXT");

				if (delegate != nullptr)
				{
					delegate(_appInstance, _messenger, _allocator);
				}
			}
		}; 


		struct ValidationLayers
		{
			struct LayerProperties : Vault_00::VKStruct_Base<VkLayerProperties>
			{
				ExtensionNameStr LayerName;
				uint32           SpecVersion;
				uint32           ImplementationVersion;
				DescrptionStr    Descrption;
			};

			static EResult QueryAvailableLayers(uint32* _numContainer, LayerProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceLayerProperties(_numContainer, (VkLayerProperties*)(_propertiesContainer)));
			}

			static uint32 GetNumberOfLayers()
			{
				uint32 layerCount;

				vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

				return layerCount;
			}

			static EResult GetAvailableLayers(LayerProperties* _container)
			{
				uint32 layerCount = GetNumberOfLayers();

				return EResult(vkEnumerateInstanceLayerProperties(&layerCount, (VkLayerProperties*)(_container)));
			}
		};
	}
}
