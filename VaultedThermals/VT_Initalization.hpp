/*
Vaulted Thermals: Initialization

Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization
*/

#pragma once


#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
//#include "VT.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"



namespace Vulkan
{
	#pragma region Command Function Pointers

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
		*/
		inline typename std::enable_if
		<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

		ReturnType>::type GetProcedureAddress(AppInstance::Handle& _appInstance, const char* _procedureName)
		{
			return ReturnType(vkGetInstanceProcAddr(_appInstance, _procedureName));
		};
	}

	#pragma endregion Command Function Pointers


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
			using Handle = VkInstance;

			using CreateFlags = Bitmask<EUndefined, Flags>;

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
			*/
			static void Destory
			(
				AppInstance::Handle  _instance,
				AllocationCallbacks* _callbacks
			)
			{
				vkDestroyInstance(_instance, _callbacks);
			}
		};
	}

	#pragma endregion Application Instancing

	
}
