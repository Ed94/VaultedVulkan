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
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		@brief Debug Utilities: Flexible utilities for debugging an application.

		@details
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#debugging-debug-utils">Specification</a> 

		@ingroup APISpec_Debugging
		*/
		struct DebugUtils
		{
			using EMessageServerity = EDebugUtils_MessageSeverity;
			using EMessageType      = EDebugUtils_MessageType    ;

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageSeverityFlagsEXT">Specification</a>  
			@ingroup APISpec_Debugging 
			*/
			using MessageServerityFlags = Bitmask<EMessageServerity, VkDebugUtilsMessageSeverityFlagsEXT>;

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageTypeFlagsEXT">Specification</a>  
			@ingorup APISpec_Debugging 
			*/
			using MessageTypeFlags = Bitmask<EMessageType , VkDebugUtilsMessageTypeFlagsEXT>;

			/** 
			@brief Pointer to the create debug messenger function.

			@details
			The create messenger function is not provided automatically from the Vulkan API and must be
			retrieved with AppInstance's GetProcedureAddress function.

			@ingroup APISpec_Debugging
			*/ 
			using FPtr_CreateMessenger = PFN_vkCreateDebugUtilsMessengerEXT;

			/** 
			@brief Used in conjunction with labeling queues, and commands.
			
			@details 
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsLabelEXT">Specification</a> 
			
			@ingroup APISpec_Debugging
			*/
			struct Label : V0::VKStruct_Base<VkDebugUtilsLabelEXT, EStructureType::DebugUtils_Label_EXT>
			{
					  EType   SType   ;
				const void*   Next    ;
				const char*   Name    ;
					  float32 Color[4];
			};

			/** 
			@brief Used for annotating objects with user defined information.
			
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsObjectNameInfoEXT">Specification</a> 

			@ingroup APISpec_Debugging 
			*/
			struct ObjectInfo : V0::VKStruct_Base<VkDebugUtilsObjectNameInfoEXT, EStructureType::DebugUtils_ObjectName_Info_EXT>
			{
					  EType       SType ;
				const void*       Next  ;
					  EObjectType Type  ;
					  uInt64      Handle;
				const char*       Name  ;
			};

			/**
			@brief 
			Vulkan allows an application to register multiple callbacks with any Vulkan component wishing to report debug information. 
			Some callbacks may log the information to a file, others may cause a debug break point or other application defined behavior. 
			 
			@details 
			The debug messenger will provide detailed feedback on the application's use
            of Vulkan when events of interest occur. When an event of interest does
            occur, the debug messenger will submit a debug message to the debug callback
            that was provided during its creation. Additionally, the debug messenger is
            responsible with filtering out debug messages that the callback is not
            interested in and will only provide desired debug messages.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#debugging-debug-utils">Specification</a>
			 
			@ingroup APISpec_Debugging
			*/
			struct Messenger
			{
			public:
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerEXT">Specification</a> @ingroup APISpec_Debugging */
				using Handle = VkDebugUtilsMessengerEXT;

				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCallbackDataEXT">Specification</a> @ingroup APISpec_Debugging */
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

				/** 
				@brief The prototype for the CreateInfo::UserCallback function implemented by the application.

				@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkDebugUtilsMessengerCallbackEXT">Specification</a> 
				
				@ingroup APISpec_Debugging
				*/
				struct CallbackDelegate
				{
					using Delegate = PFN_vkDebugUtilsMessengerCallbackEXT;

					template<typename FuncType>
					void operator=(FuncType _function) 
					{
						Callback = reinterpret_cast<Delegate>(_function);
					}

					Delegate Callback;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCreateInfoEXT">Specification</a> */
				struct CreateInfo : V0::VKStruct_Base<VkDebugUtilsMessengerCreateInfoEXT, EStructureType::DebugUtils_Messenger_CreateInfo_EXT>
				{ 
						  EType                 SType       ;
					const void*                 Next        ;
						  CreateFlags           Flags       ;
						  MessageServerityFlags Serverity   ;
						  MessageTypeFlags      Type        ;
						  CallbackDelegate      UserCallback;
						  void*                 UserData    ;
				};

				/**
				 * @brief Creates a debug messenger. 
				 
				 @details
				 <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDebugUtilsMessengerEXT">Specification</a> 
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
					const CreateInfo&                  _createSpec ,
					const Memory::AllocationCallbacks* _allocator  ,
						  Handle&                      _messenger
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
				 * @brief Destroys a debug messenger. 
				 
				 @details
				 <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDebugUtilsMessengerEXT">Specification</a> .
				 * 
				 * \param _appInstance
				 * \param _messenger
				 * \param _allocator
				 */
				static void Destroy
				(
						  AppInstance::Handle          _appInstance,
						  Handle                       _messenger  ,
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
		};
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief Debug Utilities: Flexible utilities for debugging an application.

		@ingroup APISpec_Debugging
		*/
		struct DebugUtils : public V1::DebugUtils 
		{
			using Parent = V1::DebugUtils;

			/**
			@brief Offers a default constructor.
			*/
			struct Label : public Parent::Label
			{
				Label()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
					Name  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct ObjectInfo : public Parent::ObjectInfo
			{
				ObjectInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
					Name  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct Messenger : public Parent::Messenger
			{
				using Parent = Parent::Messenger;

				/**
				
				*/
				struct CallbackData : Parent::CallbackData
				{
					CallbackData()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : Parent::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				@brief Create a debug messenger with the default memory allocator.
				*/
				static EResult Create
				(
						  AppInstance::Handle _appInstance,
					const CreateInfo&         _createSpec ,
						  Handle&             _messenger
				)
				{
					return Parent::Create(_appInstance, _createSpec, Memory::DefaultAllocator,_messenger);
				}

				using Parent::Create;

				/**
				@brief Destroy a debug messenger that used the default memory allocator.
				*/
				static void Destroy(AppInstance::Handle _appInstance, Handle _messenger)
				{
					Parent::Destroy(_appInstance, _messenger, Memory::DefaultAllocator);
				}

				using Parent::Destroy;
			};
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@brief

		@ingroup

		@todo 
		#TODO: Add documentation.
		*/
		struct DebugUtils : public V2::DebugUtils 
		{
			using Parent = V2::DebugUtils;

			class Messenger : public Parent::Messenger
			{
			public:

				using Parent = V2::DebugUtils::Messenger;

				EResult Create
				(
					const AppInstance& _appInstance,
					const CreateInfo&  _createSpec 
				)
				{
					app       = &_appInstance           ;
					allocator = Memory::DefaultAllocator;

					return Parent::Create(*app, _createSpec, handle);
				}

				EResult Create
				(
					const AppInstance&                 _appInstance,
					const CreateInfo&                  _createSpec ,
					const Memory::AllocationCallbacks* _allocator  
				)
				{
					app       = &_appInstance;
					allocator = _allocator   ;

					return Parent::Create(*app, _createSpec, allocator, handle);
				}

				void Destroy()
				{
					Parent::Destroy(*app, handle, allocator);
				}

				operator Handle()
				{
					return handle;
				}

				operator Handle*()
				{
					return &handle;
				}

				operator const Handle&() const
				{
					return handle;
				}

				operator const Handle*() const
				{
					return &handle;
				}

				bool operator== (const Messenger& _other) const
				{
					return handle == _other.handle;
				}

			protected:

				Handle handle;

				const AppInstance* app;

				const Memory::AllocationCallbacks* allocator;
			};
		};

		/** @} */
	}
}
