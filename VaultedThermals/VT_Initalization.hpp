/*
Vaulted Thermals: Initialization

Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization
*/

#pragma once


#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"



namespace Vulkan
{
	#pragma region Application Instancing

	namespace Vault_01
	{
		/*
		An object that manages the represented application process state within the GPU.

		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstance.html
		*/
		struct AppInstance
		{
			using Handle = VkInstance;   // VkInstance - Opaque handle to an instance object

			using CreateFlags = Bitmask<EUndefined, Flags>;   // VkInstanceCreateFlags - Reserved for future use

			/*
			A structure that specifies to the Vulkan driver information about an
			application that will run an instance.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkApplicationInfo.html
			*/
			struct AppInfo : Vault_00::VKStruct_Base<VkInstanceCreateInfo>
			{
				EStructureType SType        ;
				const void*    Extension    ;
				RoCStr         AppName      ;
				uint32         AppVersion   ;
				RoCStr         EngineName   ;
				uint32         EngineVersion;
				EAPI_Version   API_Version  ;
			};

			/*
			Structure specifying parameters of a newly created instance.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstanceCreateInfo.html
			*/
			struct CreateInfo : Vault_00::VKStruct_Base<VkInstanceCreateInfo>
			{
				EStructureType       SType                ;
				const void*          Extension            ;
				CreateFlags          Flags                ;
				const AppInfo*       AppInfo              ;
				uint32               EnabledLayerCount    ;
				RoSCtr_roArray_Array EnabledLayerNames    ;
				uint32               EnabledExtensionCount;
				RoSCtr_roArray_Array EnabledExtensionNames;
			};


			/*
			Create a new Vulkan application instance.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateInstance.html
			*/
			static EResult Create
			(
				const AppInstance::CreateInfo& _appSpec        ,
				const AllocationCallbacks*     _customAllocator,
				      AppInstance::Handle&     _handleContainer
			)
			{
				return EResult(vkCreateInstance( _appSpec, _customAllocator, &_handleContainer));
			}

			/*
			Destroy an application instance of Vulkan.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyInstance.html
			*/
			static void Destory
			(
				AppInstance::Handle  _instance ,
				AllocationCallbacks* _callbacks
			)
			{
				vkDestroyInstance(_instance, _callbacks);
			}
		};
	}

	namespace Vault_05
	{
		/*
		An object that manages the represented application process state within the GPU.

		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstance.html

		Note: This class is a singleton. There should really not be more than one app instance per process...
		*/
		class AppInstance : Vault_01::AppInstance
		{
		public:

			void Create(const AppInstance::CreateInfo& _creationSpec)
			{
				creationSpec = _creationSpec;
				allocator    = nullptr      ;

				Vault_01::AppInstance::Create(creationSpec, allocator, handle);
			}

			void Create(const AppInstance::CreateInfo& _creationSpec, AllocationCallbacks* _allocator)
			{
				creationSpec = _creationSpec;
				allocator    = _allocator   ;

				Vault_01::AppInstance::Create(creationSpec, allocator, handle);
			}

			void Destroy()
			{
				Vault_01::AppInstance::Destory(handle, allocator);
			}


			template<typename ReturnType>
			/*
			Function pointers for all Vulkan commands can be obtained with this command.

			vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
			Typically, the loader library will export this command as a function symbol, 
			so applications can link against the loader library, or load it dynamically 
			and look up the symbol using platform-specific APIs.

			Note: ReturnType is restricted to only function pointing types.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html
			*/
			typename std::enable_if
			<
				std::bool_constant
				< 
					std::is_pointer <                             ReturnType       >::value &&
					std::is_function<typename std::remove_pointer<ReturnType>::type>::value
				>::value,

			ReturnType>::type GetProcedureAddress(RoCStr _procedureName)
			{
				return reinterpret_cast<ReturnType>(vkGetInstanceProcAddr(handle, _procedureName));
			}

		private:

			static Handle               handle      ;
			static AppInfo              appInfo     ;
			static CreateInfo           creationSpec;
			static AllocationCallbacks* allocator   ;
		};
	}

	#pragma endregion Application Instancing


	#pragma region Command Function Pointers
	/*
	Vulkan commands are not necessarily exposed by static linking on a platform. 
	Commands to query function pointers for Vulkan commands are described below.

	https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization-functionpointers
	*/

	namespace Vault_01
	{
		template<typename ReturnType>
		/*
		Function pointers for all Vulkan commands can be obtained with this command.

		vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
		Typically, the loader library will export this command as a function symbol, 
		so applications can link against the loader library, or load it dynamically 
		and look up the symbol using platform-specific APIs.

		Note: ReturnType is restricted to only function pointing types.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html
		*/
		inline typename std::enable_if
		<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

		ReturnType>::type GetProcedureAddress(AppInstance::Handle& _appInstance, RoCStr _procedureName)
		{
			return reinterpret_cast<ReturnType>(vkGetInstanceProcAddr(_appInstance, _procedureName));
		};

		template<typename ReturnType>
		/*
		Function pointers for all Vulkan commands directly addressed from the device.

		In order to support systems with multiple Vulkan implementations, the function pointers returned by vkGetInstanceProcAddr 
		may point to dispatch code that calls a different real implementation for different VkDevice objects or their child objects. 
		The overhead of the internal dispatch for VkDevice objects can be avoided by obtaining device-specific function pointers 
		for any commands that use a device or device-child object as their dispatchable object. 
		
		Note: ReturnType is restricted to only function pointing types.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html

		// TODO: Move this to Logical Device... (its technically part of this but it needs the logical device definition... just do a forward declaration for organization's sake.
		*/
		/*inline typename std::enable_if
		<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

		ReturnType>::type GetDeviceProcedureAddress(LogicalDevice::Handle& _appInstance, RoCStr _procedureName)
		{
			return reinterpret_cast<ReturnType>(vkGetDeviceProcAddr(_appInstance, _procedureName));
		}*/
	}

	#pragma endregion Command Function Pointers
}
