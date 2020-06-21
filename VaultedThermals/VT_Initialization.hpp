/** @file VT_Initialization.hpp

@brief Vaulted Thermals: Initialization

@details
Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">Initialization Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"



namespace VaultedThermals
{
	#pragma region Application Instancing

	namespace Vault_01
	{
		/**
		@brief An object that manages the represented application process state within the GPU.

		Other Name: Application State Container

		@details
		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.
		
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstance.html">Application Instance Specification</a> 
		*/
		struct AppInstance
		{
			using Handle = VkInstance;   ///< VkInstance - Opaque handle to an instance object

			using CreateFlags = Bitmask<EUndefined, VkInstanceCreateFlags>;   ///< VkInstanceCreateFlags - Reserved for future use

			/**
			@brief 
			A structure that specifies to the Vulkan driver information about an
			application that will run an instance.

			@details
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkApplicationInfo.html">Application Info Specification</a> 
			*/
			struct AppInfo : Vault_00::VKStruct_Base<VkInstanceCreateInfo>
			{
				      EType        SType        ;
				const void*        Next         ;
				      RoCStr       AppName      ;
				      uint32       AppVersion   ;
				      RoCStr       EngineName   ;
				      uint32       EngineVersion;
				      EAPI_Version API_Version  ;
			};

			/**
			@brief Structure specifying parameters of a newly created instance.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstanceCreateInfo.html">Create Info Specification</a> 
			*/
			struct CreateInfo : Vault_00::VKStruct_Base<VkInstanceCreateInfo>
			{
				      EType                SType                ;
				const void*                Next                 ;
				      CreateFlags          Flags                ;
				const AppInfo*             AppInfo              ;
				      uint32               EnabledLayerCount    ;
				      RoSCtr_roArray_Array EnabledLayerNames    ;
				      uint32               EnabledExtensionCount;
				      RoSCtr_roArray_Array EnabledExtensionNames;
			};

			struct Validation
			{
				/**
				* @brief.
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFeaturesEXT">Specification</a> 
				*/
				struct Features
				{

				};

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFlagsEXT">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Flags
				{

				};
			};

			/**
			@brief Create a new Vulkan application instance.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateInstance.html">Create Instance Specification</a> 
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

			/**
			@brief Destroy an application instance of Vulkan.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyInstance.html">Destroy Instance Specification</a> 
			*/
			static void Destroy
			(
				AppInstance::Handle  _instance ,
				AllocationCallbacks* _callbacks
			)
			{
				vkDestroyInstance(_instance, _callbacks);
			}

			/**
			 * @brief Query the version of application instance-level functionality supported by the implementation.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkEnumerateInstanceVersion.html">Specification</a> 
			 * 
			 * \param _versionContainer
			 * \return 
			 */
			static EResult GetVersion(uint32& _versionContainer)
			{
				vkEnumerateInstanceVersion(&_versionContainer);
			}
		};
	}

	namespace Vault_02
	{
		using Vault_01::AppInstance;
	}

	namespace Vault_05
	{
		/**
		@brief An object that manages the represented application process state within the GPU.

		@details
		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstance.html">Application Instance Specification</a> 

		Note: This class is a singleton. There should really not be more than one app instance per process...
		*/
		class AppInstance : Vault_01::AppInstance
		{
		public:

			void Create(AppInstance::AppInfo _appInfo, AppInstance::CreateInfo& _creationSpec)
			{
				appInfo      = _appInfo     ;
				creationSpec = _creationSpec;
				allocator    = nullptr      ;

				if (_creationSpec.AppInfo != &appInfo) _creationSpec.AppInfo = &appInfo;

				EResult&& result = Vault_01::AppInstance::Create(creationSpec, allocator, handle);

				if (result != EResult::Success) throw std::runtime_error("Failed to create application instance.");
			}

			void Create(AppInstance::AppInfo _appInfo, AppInstance::CreateInfo& _creationSpec, AllocationCallbacks* _allocator)
			{
				appInfo      = _appInfo     ;
				creationSpec = _creationSpec;
				allocator    = _allocator   ;

				if (_creationSpec.AppInfo != &appInfo) _creationSpec.AppInfo = &appInfo;

				EResult&& result = Vault_01::AppInstance::Create(creationSpec, allocator, handle);

				if (result != EResult::Success) throw std::runtime_error("Failed to create application instance.");
			}

			void Destroy()
			{
				Vault_01::AppInstance::Destroy(handle, allocator);
			}


			template<typename ReturnType>
			/**
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

		protected:

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
		/**
		Function pointers for all Vulkan commands can be obtained with this command.

		vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
		Typically, the loader library will export this command as a function symbol, 
		so applications can link against the loader library, or load it dynamically 
		and look up the symbol using platform-specific APIs.

		Note: ReturnType is restricted to only function pointing types.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html">Specification</a> 
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

		/*
		template<typename ReturnType>
		
		Function pointers for all Vulkan commands directly addressed from the device.

		In order to support systems with multiple Vulkan implementations, the function pointers returned by vkGetInstanceProcAddr 
		may point to dispatch code that calls a different real implementation for different VkDevice objects or their child objects. 
		The overhead of the internal dispatch for VkDevice objects can be avoided by obtaining device-specific function pointers 
		for any commands that use a device or device-child object as their dispatchable object. 
		
		Note: ReturnType is restricted to only function pointing types.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html">Specification</a> 

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
