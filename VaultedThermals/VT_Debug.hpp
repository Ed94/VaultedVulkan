/*!
@file VT_Debug.hpp

@brief Vaulted Thermals: Debug

@details
*/

#pragma once



#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Backend.hpp"
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



#ifndef VT_Option__Use_Long_Namespace
/**
@namespace VaultedThermals

@brief Main library namespace for Vaulted Thermals (Vulkan Wrapper)

@details For long namespace: #define VT_Option__Use_Long_Namespace
*/
namespace VT
#else
/**
@namespace VaultedThermals

@brief Main library namespace for Vaulted Thermals (Vulkan Wrapper)

@details VT_Option__Use_Long_Namespace in use.
*/
namespace VaultedThermals
#endif
{
	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		using CallbackDataFlags = Bitmask<EUndefined , Flags>;   ///< TODO: Add comment on what this is for.

		/** @brief Pointer to the Create Debug Messenger Command. */ 
		using FPtr_CreateMessenger = PFN_vkCreateDebugUtilsMessengerEXT;

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageSeverityFlagsEXT">Specification</a>  */
		using MessageServerityFlags = Bitmask<EDebugUtilities_MessageSeverity, VkDebugUtilsMessageSeverityFlagsEXT>;
		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageTypeFlagsEXT">Specification</a>  */
		using MessageTypeFlags      = Bitmask<EDebugUtilities_MessageType    , VkDebugUtilsMessageTypeFlagsEXT>;



		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsLabelEXT">Specification</a>  */
		struct Label : V0::VKStruct_Base<VkDebugUtilsLabelEXT, EStructureType::DebugUtils_Label_EXT>
		{
			      EType   SType    ;
			const void*   Next     ;
			const char*   Name     ;
			      float32 Color[4] ;
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsObjectNameInfoEXT">Specification</a>  */
		struct ObjectInfo : V0::VKStruct_Base<VkDebugUtilsObjectNameInfoEXT, EStructureType::DebugUtils_ObjectName_Info_EXT>
		{
			      EType       SType    ;
			const void*       Next     ;
			      EObjectType Type     ;
			      uInt64      Handle   ;
			const char*       Name     ;
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#debugging-debug-utils">Specification</a>
		 */
		struct DebugMessenger
		{
		public:
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerEXT">Specification</a>  */
			using Handle = VkDebugUtilsMessengerEXT;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCallbackDataEXT">Specification</a>  */
			struct CallbackData : V0::VKStruct_Base<VkDebugUtilsMessengerCallbackDataEXT, EStructureType::DebugUtils_MessengerCallback_Data_EXT>
			{
				using FlagsMask = Bitmask<EUndefined, Flags>;

				      EType       SType               ;
				const void*       Next                ;
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

			using CallbackDelegate = VK_FPtr<Bool, MessageServerityFlags, MessageTypeFlags, const CallbackData, void* >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCreateInfoEXT">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkDebugUtilsMessengerCreateInfoEXT, EStructureType::DebugUtils_Messenger_CreateInfo_EXT>
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				      EType                 SType       ;
				const void*                 Next        ;
				      CreateFlags           Flags       ;
				      MessageServerityFlags Serverity   ;
				      MessageTypeFlags      Type        ;
				      CallbackDelegate      UserCallback;
				      void*                 UserData    ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDebugUtilsMessengerEXT">Specification</a> 
			 * 
			 * \param _appInstance
			 * \param _createSpec
			 * \param _allocator
			 * \param _messenger
			 * \return 
			 */
			static EResult Create
			(
				      AppInstance::Handle          _appInstance,
				const DebugMessenger::CreateInfo&  _createSpec ,
				const Memory::AllocationCallbacks* _allocator  ,
				      DebugMessenger::Handle&      _messenger
			)
			{
				static FPtr_CreateMessenger delegate = nullptr;

				if (delegate == nullptr) delegate = AppInstance::GetProcedureAddress<FPtr_CreateMessenger>(_appInstance, "vkCreateDebugUtilsMessengerEXT");

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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDebugUtilsMessengerEXT">Specification</a> .
			 * 
			 * \param _appInstance
			 * \param _messenger
			 * \param _allocator
			 */
			static void Destroy
			(
				      AppInstance::Handle          _appInstance,
				      DebugMessenger::Handle       _messenger  ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				using FPtr_DestroyMessenger = PFN_vkDestroyDebugUtilsMessengerEXT;

				static FPtr_DestroyMessenger delegate = nullptr;
				
				if (delegate == nullptr) delegate = AppInstance::GetProcedureAddress<FPtr_DestroyMessenger>(_appInstance, "vkDestroyDebugUtilsMessengerEXT");

				if (delegate != nullptr)
				{
					delegate(_appInstance, _messenger, _allocator->operator const VkAllocationCallbacks*());
				}
			}
		}; 

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		using V1::CallbackDataFlags;
		using V1::FPtr_CreateMessenger;
		using V1::MessageServerityFlags;
		using V1::MessageTypeFlags;

		struct Label : V1::Label
		{
			Label()
			{
				SType = STypeEnum;
				Next  = nullptr  ;
			}
		};

		struct ObjectInfo : V1::ObjectInfo
		{
			ObjectInfo()
			{
				SType = STypeEnum;
				Next  = nullptr  ;
			}
		};

		struct DebugMessenger : public V1::DebugMessenger
		{
			using Parent = V1::DebugMessenger;

			struct CallbackData : Parent::CallbackData
			{
				CallbackData()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			static EResult Create
			(
				      AppInstance::Handle          _appInstance,
				const DebugMessenger::CreateInfo&  _createSpec ,
				      DebugMessenger::Handle&      _messenger
			)
			{
				return Parent::Create(_appInstance, _createSpec, Memory::DefaultAllocator,_messenger);
			}

			using Parent::Create;

			static void Destroy
			(
				AppInstance::Handle          _appInstance,
				DebugMessenger::Handle       _messenger  
			)
			{
				Parent::Destroy(_appInstance, _messenger, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup
		@{
		*/

		using V2::CallbackDataFlags;
		using V2::FPtr_CreateMessenger;
		using V2::MessageServerityFlags;
		using V2::MessageTypeFlags;

		class DebugMessenger : public V2::DebugMessenger
		{
		public:

			using Parent = V2::DebugMessenger;

			void AssignInfo(const CreateInfo& _info)
			{
				info = _info;
			}

			EResult Create
			(
				AppInstance::Handle _appInstance
			)
			{
				app       = _appInstance ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(app, info, handle);
			}

			EResult Create
			(
					  AppInstance::Handle          _appInstance,
				const Memory::AllocationCallbacks* _allocator  
			)
			{
				app       = _appInstance;
				allocator = _allocator  ;

				return Parent::Create(app, info, allocator, handle);
			}

			EResult Create
			(
				      AppInstance::Handle _appInstance,
				const CreateInfo&         _createSpec 
			)
			{
				app       = _appInstance ;
				info      = _createSpec  ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(app, _createSpec, handle);
			}

			EResult Create
			(
				      AppInstance::Handle          _appInstance,
				const CreateInfo&                  _createSpec ,
				const Memory::AllocationCallbacks* _allocator  
			)
			{
				app       = _appInstance ;
				info      = _createSpec  ;
				allocator = _allocator   ;

				return Parent::Create(app, _createSpec, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(app, handle, allocator);
			}

			const CreateInfo& GetInfo() const
			{
				return info;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			AppInstance::Handle app;

			CreateInfo info;

			const Memory::AllocationCallbacks* allocator;

			Handle handle;
		};

		/** @} */
	}
}
