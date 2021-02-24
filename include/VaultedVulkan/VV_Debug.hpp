/*!
@file VV_Debug.hpp

@brief Vaulted Vulkan: Debug

@details
*/

#pragma once



// VV
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"
#include "VV_Backend.hpp"
#include "VV_Types.hpp"
#include "VV_Constants.hpp"
#include "VV_Memory_Backend.hpp"
#include "VV_PhysicalDevice.hpp"
#include "VV_Initialization.hpp"
#include "VV_LogicalDevice.hpp"
#include "VV_Memory.hpp"
#include "VV_Sampler.hpp"
#include "VV_Resource.hpp"
#include "VV_SyncAndCacheControl.hpp"
#include "VV_Shaders.hpp"
#include "VV_Pipelines.hpp"
#include "VV_RenderPass.hpp"
#include "VV_Command.hpp"
#include "VV_Surface.hpp"
#include "VV_SwapChain.hpp"



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
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
			/** 
			@brief Used in conjunction with labeling queues, and commands.
			
			@details 
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsLabelEXT">Specification</a> 
			
			@ingroup APISpec_Debugging
			*/
			struct Label : V0::VKStruct_Base<VkDebugUtilsLabelEXT, EStructureType::DebugUtils_Label_EXT>
			{
					  EType   SType    = STypeEnum;
				const void*   Next     = nullptr  ;
				const char*   Name     = nullptr  ;
					  f32     Color[4];
			};

			/** 
			@brief Used for annotating objects with user defined information.
			
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsObjectNameInfoEXT">Specification</a> 

			@ingroup APISpec_Debugging 
			*/
			struct ObjectInfo : V0::VKStruct_Base<VkDebugUtilsObjectNameInfoEXT, EStructureType::DebugUtils_ObjectName_Info_EXT>
			{
					  EType       SType  = STypeEnum;
				const void*       Next   = nullptr  ;
					  EObjectType Type  ;
					  u64        Handle;
				const char*       Name   = nullptr  ;
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

				using CreateFlags = Bitfield<EUndefined, Flags>;   ///< Reserved for future use.

				using EServerity   = EDebugUtils_MessageSeverity;
				using EMessageType = EDebugUtils_MessageType    ;

				/** 
				@ingroup APISpec_Debugging
				@brief Pointer to the create debug messenger function.

				@details
				The create messenger function is not provided automatically from the Vulkan API and must be
				retrieved with AppInstance's GetProcedureAddress function.
				*/ 
				using FPtr_Create = PFN_vkCreateDebugUtilsMessengerEXT;

				/**
				@ingroup APISpec_Debugging
				@brief Pointer to the destroy debug messenger function.

				@details
				The destroy messenger function is not provided automatically from the Vulkan API and must be
				retrieved with AppInstance's GetProcedureAddress function.
				*/
				using FPtr_Destroy = PFN_vkDestroyDebugUtilsMessengerEXT;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageSeverityFlagsEXT">Specification</a>  
				@ingroup APISpec_Debugging 
				*/
				using ServerityFlags = Bitfield<EServerity, VkDebugUtilsMessageSeverityFlagsEXT>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageTypeFlagsEXT">Specification</a>  
				@ingorup APISpec_Debugging 
				*/
				using TypeFlags = Bitfield<EMessageType, VkDebugUtilsMessageTypeFlagsEXT>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCallbackDataEXT">Specification</a> @ingroup APISpec_Debugging */
				struct CallbackData : V0::VKStruct_Base<VkDebugUtilsMessengerCallbackDataEXT, EStructureType::DebugUtils_MessengerCallback_Data_EXT>
				{
					using FlagsMask = Bitfield<EUndefined, Flags>;

						  EType       SType                = STypeEnum;
					const void*       Next                 = nullptr  ;
						  FlagsMask   Flags;
					const char*       MesssageIDName       = nullptr  ;
						  si32        MessageIDNumber      = 0        ;
					const char*       Message              = nullptr  ;
						  ui32        QueueLabelCount      = 0        ;
					const Label*      QueueLabels          = nullptr  ;
						  ui32        CMDBufferLabel_Count = 0        ;
					const Label*      CMDBufferLabels      = nullptr  ;
						  ui32        ObjectCount          = 0        ;
					const ObjectInfo* Objects              = nullptr  ;
				};

				/** 
				@brief The prototype for the CreateInfo::UserCallback function implemented by the application.

				@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkDebugUtilsMessengerCallbackEXT">Specification</a> 
				
				@ingroup APISpec_Debugging
				*/
				struct CallbackDelegate
				{
					using Delegate = PFN_vkDebugUtilsMessengerCallbackEXT;

					using VT_Type = VK_FPtr<Bool, EServerity, EMessageType, TypeFlags, const CallbackData*, void* >;

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
						  EType            SType        = STypeEnum;
					const void*            Next         = nullptr  ;
						  CreateFlags      Flags       ;
						  ServerityFlags   Serverity   ;
						  TypeFlags        Type        ;
						  CallbackDelegate UserCallback;
						  void*            UserData     = nullptr  ;
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
					static FPtr_Create delegate = nullptr;

					if (delegate == nullptr) delegate = AppInstance::GetProcedureAddress<FPtr_Create>(_appInstance, "vkCreateDebugUtilsMessengerEXT");

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
					static FPtr_Destroy delegate = nullptr;
					
					if (delegate == nullptr) delegate = AppInstance::GetProcedureAddress<FPtr_Destroy>(_appInstance, "vkDestroyDebugUtilsMessengerEXT");

					if (delegate != nullptr)
					{
						delegate(_appInstance, _messenger, *_allocator);
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
			@brief 
			Vulkan allows an application to register multiple callbacks with any Vulkan component wishing to report debug information.
			Some callbacks may log the information to a file, others may cause a debug break point or other application defined behavior.
			*/
			struct Messenger : public Parent::Messenger
			{
				using Parent = Parent::Messenger;

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
		@ingroup APISpec_Debugging
		@brief Debug Utilities: Flexible utilities for debugging an application.

		@details
		Currently only defines the object-oriented version of the Debug messenger.
		*/
		struct DebugUtils : public V2::DebugUtils 
		{
			using Parent = V2::DebugUtils;

			/**
			@brief 
			Vulkan allows an application to register multiple callbacks with any Vulkan component wishing to report debug information.
			Some callbacks may log the information to a file, others may cause a debug break point or other application defined behavior.

			@details
			This object represents a device created object on the host. As such ownership is tied to this host object.
			Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
			*/
			class Messenger : public Parent::Messenger
			{
			public:

				using Parent = V2::DebugUtils::Messenger;

				/**
				@brief Default constructor.
				*/
				Messenger() : handle(Null<Handle>), app(nullptr), allocator(Memory::DefaultAllocator)
				{}

				/**
				@brief Default constructor with app instance specified.
				*/
				Messenger(const AppInstance& _appInstance) : handle(Null<Handle>), app(&_appInstance), allocator(Memory::DefaultAllocator)
				{}

				/**
				@brief Default constructor with app instance and allocator specified.
				*/
				Messenger(const AppInstance& _appInstance, const Memory::AllocationCallbacks& _allocator) :
					handle(Null<Handle>), app(&_appInstance), allocator(&_allocator)
				{}

				/**
				@brief Performs a move operation to transfer ownership of the device object to this host object.
				*/
				Messenger(Messenger&& _other) noexcept :
					handle(std::move(_other.handle)), app(std::move(_other.app)), allocator(std::move(_other.allocator))
				{
					_other.handle    = Null<Handle>            ;
					_other.app       = nullptr                 ;
					_other.allocator = Memory::DefaultAllocator;
				}

				/**
				@brief If the handle is found to not be null, this device will attempt to destroy the device object that corresponds to it.
				*/
				~Messenger()
				{
					if (handle != Null<Handle>) Destroy();
				}

				/**
				@brief Create a debug messenger.
				*/
				EResult Create(const CreateInfo& _createSpec)
				{
					if (app == nullptr) return EResult::Not_Ready;

					return Parent::Create(*app, _createSpec, handle);
				}

				/**
				@brief Create a debug messenger. (Specify app instance)
				*/
				EResult Create(const AppInstance& _appInstance, const CreateInfo& _createSpec)
				{
					app = &_appInstance;

					return Parent::Create(*app, _createSpec, handle);
				}

				/**
				@brief Create a debug messenger. (Specify app instance and allocator)
				*/
				EResult Create(const AppInstance& _appInstance, const CreateInfo& _createSpec, const Memory::AllocationCallbacks& _allocator)
				{
					app       = &_appInstance;
					allocator = &_allocator  ;

					return Parent::Create(*app, _createSpec, allocator, handle);
				}

				/**
				@brief Destroy a debug messenger.	
				*/
				void Destroy()
				{
					Parent::Destroy(*app, handle, allocator);

					handle    = Null<Handle>            ;
					app       = nullptr                 ;
					allocator = Memory::DefaultAllocator;
				}

				/**
				@brief Implicit conversion to give a reference to its handle.
				*/
				operator Handle&()
				{
					return handle;
				}

				/**
				@brief Implicit conversion to give a readonly reference to its handle.
				*/
				operator const Handle&() const
				{
					return handle;
				}

				/**
				@brief Implicit conversion to give a pointer to its handle.
				*/
				operator const Handle*() const
				{
					return &handle;
				}

				/**
				@brief Checks to see if its the same object by checking to see if its the same handle.
				*/
				bool operator== (const Messenger& _other) const
				{
					return handle == _other.handle;
				}

				/**
				@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
				*/
				Messenger& operator= (Messenger&& _other) noexcept
				{
					if (this == &_other)
						return *this;

					handle    = std::move(_other.handle   );
					app       = std::move(_other.app      );
					allocator = std::move(_other.allocator);

					_other.handle    = Null<Handle>            ;
					_other.app       = nullptr                 ;
					_other.allocator = Memory::DefaultAllocator;

					return *this;
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
