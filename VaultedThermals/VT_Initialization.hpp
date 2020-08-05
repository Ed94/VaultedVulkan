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
#include "VT_Memory_Corridors.hpp"
#include "VT_PhysicalDevice.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
#pragma region Application Instancing

	namespace Vault_1
	{
		/**
		 * @brief Construct an API version number.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_MAKE_VERSION">Specification</a> 
		 * 
		 * \param _major
		 * \param _minor
		 * \param _patch
		 * \return 
		 */
		inline uInt32 MakeVersion(uInt32 _major, uInt32 _minor, uInt32 _patch)
		{
			return VK_MAKE_VERSION(_major, _minor, _patch);
		}
		
		/**
		@brief An object that manages the represented application process state within the GPU.

		Other Name: Application State Container

		@details
		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.
		
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Application Instance Specification</a> 
		*/
		struct AppInstance
		{
			using Memory = Vault_0::Memory;

			/**
			 * @brief Opaque handle to an instance object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Specification</a> 
			 */
			using Handle = VkInstance;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateFlags">Specification</a>
			 */
			using CreateFlags = Bitmask<EUndefined, VkInstanceCreateFlags>;

			/**
			@brief 
			A structure that specifies to the Vulkan driver information about an
			application that will run an instance.

			@details
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkApplicationInfo">Application Info Specification</a> 
			*/
			struct AppInfo : Vault_0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::ApplicationInformation>
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

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateInfo">Create Info Specification</a> 
			*/
			struct CreateInfo : Vault_0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::Instance_CreateInfo>
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
				struct Features : Vault_0::VKStruct_Base<VkValidationFeaturesEXT, EStructureType::ValidationFeatures_EXT>
				{
					      EType                     SType                         ;
					const void*                     Next                          ;
					      uint32                    EnabledValidationFeatureCount ;
					const EValidationFeatureEnable* EnabledValidationFeatures     ;
					      uint32                    DisabledValidationFeatureCount;
					const EValidationFeatureEnable* DisabledValidationFeatures    ;
				};

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFlagsEXT">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Flags : Vault_0::VKStruct_Base<VkValidationFlagsEXT, EStructureType::ValidationFlags_EXT>
				{
					      EType             SType                       ;
					const void*             Next                        ;
					      uint32            DisabledValidationCheckCount;
					const EValidationCheck* DisabledValidationChecks    ;
				};
			};

			

			/**
			@brief Create a new Vulkan application instance.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateInstance">Create Instance Specification</a> 
			*/
			static EResult Create
			(
				const AppInstance::CreateInfo&     _appSpec        ,
				const Memory::AllocationCallbacks* _customAllocator,
				      AppInstance::Handle&         _handleContainer
			)
			{
				return EResult(vkCreateInstance( _appSpec, _customAllocator->operator const VkAllocationCallbacks*(), &_handleContainer));
			}

			/**
			@brief Destroy an application instance of Vulkan.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyInstance">Destroy Instance Specification</a> 
			*/
			static void Destroy
			(
				AppInstance::Handle          _instance ,
				Memory::AllocationCallbacks* _callbacks
			)
			{
				vkDestroyInstance(_instance, _callbacks->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief Query the version of application instance-level functionality supported by the implementation.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceVersion">Specification</a> 
			 * 
			 * \param _versionContainer
			 * \return 
			 */
			static EResult GetVersion(uint32& _versionContainer)
			{
				return EResult(vkEnumerateInstanceVersion(&_versionContainer));
			}

			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
			*/
			static EResult QueryPhysicalDeviceListing(AppInstance::Handle _instance, uint32* _numDevices, PhysicalDevice::Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_instance, _numDevices, _deviceListing));
			}

			/**
			* @brief 
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceGroups">Specification</a> 
			*/
			static EResult QueryPhysicalDeviceGroups
			(
				Handle                 _instance       ,
				uint32*                _groupCount     ,
				PhysicalDevice::Group* _groupProperties
			)
			{
				vkEnumeratePhysicalDeviceGroups(_instance, _groupCount, _groupProperties->operator VkPhysicalDeviceGroupProperties*());
			}
		};
	}

	namespace Vault_2
	{
		struct AppInstance : public Vault_1::AppInstance
		{
			using Parent = Vault_1::AppInstance;

			struct AppInfo : public Parent::AppInfo
			{
				AppInfo() 
				{ 
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo() 
				{
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			struct Validation : public Parent::Validation
			{
				struct Features : public Parent::Validation::Features
				{
					Features() 
					{ 
						SType = STypeEnum; 
					}
				};

				struct Flags : public Parent::Validation::Flags
				{
					Flags() 
					{ 
						SType = STypeEnum; 
					}
				};
			};

			/** 
			@brief Provides the handles of all available physical devices.
			*/
			static EResult GetAvailablePhysicalDevices(Handle _instance, PhysicalDevice::List& _deviceListing)
			{
				uint32 count;

				EResult&& returnCode = QueryPhysicalDeviceListing(_instance, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_deviceListing.resize(count);

				returnCode = QueryPhysicalDeviceListing(_instance, &count, _deviceListing.data());

				return returnCode;
			}

			/**
			 * @brief Provides a list of the device groups present in the system.
			 * 
			 * \param _instance
			 * \param _groupListing
			 * \return 
			 */
			static EResult GetAvailablePhysicalDeviceGroups(Handle _instance, PhysicalDevice::GroupList& _groupListing)
			{
				uint32 count;

				EResult&& returnCode = QueryPhysicalDeviceGroups(_instance, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_groupListing.resize(count);

				returnCode = QueryPhysicalDeviceGroups(_instance, &count, _groupListing.data());

				return returnCode;
			}
		};
	}

	namespace Vault_5
	{
		/**
		@brief An object that manages the represented application process state within the GPU.

		@details
		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Application Instance Specification</a> 

		Note: This class is a singleton. There should really not be more than one app instance per process...
		*/
		class AppInstance : public Vault_2::AppInstance
		{
		public:
			using Parent = Vault_2::AppInstance;

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 */
			EResult Create(AppInstance::AppInfo _appInfo, AppInstance::CreateInfo _creationSpec)
			{
				appInfo      = _appInfo     ;
				creationSpec = _creationSpec;
				allocator    = nullptr      ;

				if (_creationSpec.AppInfo != &appInfo) _creationSpec.AppInfo = &appInfo;

				return Vault_1::AppInstance::Create(creationSpec, allocator, handle);
			}

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 * \param _allocator
			 */
			EResult Create(AppInstance::AppInfo _appInfo, AppInstance::CreateInfo _creationSpec, Memory::AllocationCallbacks* _allocator)
			{
				appInfo      = _appInfo     ;
				creationSpec = _creationSpec;
				allocator    = _allocator   ;

				return Vault_1::AppInstance::Create(creationSpec, allocator, handle);
			}

			/**
			 * @brief Destroy an application instance.
			 */
			void Destroy()
			{
				Vault_1::AppInstance::Destroy(handle, allocator);
			}

			/** 
			@brief Provides the handles of all available physical devices.
			*/
			EResult GetAvailablePhysicalDevices(PhysicalDevice::List& _deviceListing)
			{
				uint32 count; std::vector<PhysicalDevice::Handle> handleList;

				EResult&& returnCode = Parent::QueryPhysicalDeviceListing(handle, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				handleList    .resize(count);
				_deviceListing.resize(count);

				returnCode = Parent::QueryPhysicalDeviceListing(handle, &count, handleList.data());
				
				for (DeviceSize index = 0; index < count; index++)
				{
					_deviceListing[index].AssignHandle(handleList[index]);
				}

				return returnCode;
			}

			/**
			 * @brief Provides a list of the device groups present in the system.
			 * 
			 * \param _instance
			 * \param _groupListing
			 * \return 
			 */
			EResult GetAvailablePhysicalDeviceGroups(PhysicalDevice::GroupList& _groupListing)
			{
				uint32 count;

				EResult&& returnCode = QueryPhysicalDeviceGroups(handle, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_groupListing.resize(count);

				returnCode = QueryPhysicalDeviceGroups(handle, &count, _groupListing.data());

				return returnCode;
			}

			Handle GetHandle() const
			{
				return handle;
			}

			/**
			 * @brief Get application version.
			 * 
			 * \return 
			 */
			uint32 GetVersion()
			{
				if (version == 0) returnCodeReference = Parent::GetVersion(version);

				returnCodeReference = EResult::Success;

				return version;
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

			Handle                       handle      ;
			AppInfo                      appInfo     ;   
			CreateInfo                   creationSpec;
			Memory::AllocationCallbacks* allocator   ;
			uint32                       version     ;

			EResult returnCodeReference;
		};
	}

#pragma endregion Application Instancing


#pragma region Command Function Pointers
		
	/*
	Vulkan commands are not necessarily exposed by static linking on a platform. 
	Commands to query function pointers for Vulkan commands are described below.

	https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization-functionpointers
	*/

	namespace Vault_1
	{
		template<typename ReturnType>
		/**
		Function pointers for all Vulkan commands can be obtained with this command.

		vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
		Typically, the loader library will export this command as a function symbol, 
		so applications can link against the loader library, or load it dynamically 
		and look up the symbol using platform-specific APIs.

		Note: ReturnType is restricted to only function pointing types.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetInstanceProcAddr">Specification</a> 
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
	}

#pragma endregion Command Function Pointers
}
