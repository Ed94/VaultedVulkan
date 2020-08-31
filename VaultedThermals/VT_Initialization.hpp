/*!
@file VT_Initialization.hpp

@brief Vaulted Thermals: Initialization

@details Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">
Initialization Specification
</a> 
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
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"



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
	namespace Corridors
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
	}

	namespace V1
	{
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
			using Memory = V0::Memory;

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
			struct AppInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::ApplicationInformation>
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
			struct CreateInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::Instance_CreateInfo>
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
				struct Features : V0::VKStruct_Base<VkValidationFeaturesEXT, EStructureType::ValidationFeatures_EXT>
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
				struct Flags : V0::VKStruct_Base<VkValidationFlagsEXT, EStructureType::ValidationFlags_EXT>
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
				const CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle&                      _handle
			)
			{
				return EResult(vkCreateInstance( _info, _allocator->operator const VkAllocationCallbacks*(), &_handle));
			}

			/**
			@brief Destroy an application instance of Vulkan.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyInstance">Destroy Instance Specification</a> 
			*/
			static void Destroy(Handle _handle , const Memory::AllocationCallbacks* _callbacks)
			{
				vkDestroyInstance(_handle, _callbacks->operator const VkAllocationCallbacks*());
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

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceLayerProperties">Specification</a>  */
			static EResult QueryAvailableLayers(uint32& _numContainer, LayerProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceLayerProperties(&_numContainer, _propertiesContainer->operator VkLayerProperties * ()));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceExtensionProperties">Specification</a> .
			 */
			static EResult QueryAvailableAppExtensions(RoCStr _layerName, uint32& _numProperties, ExtensionProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceExtensionProperties(_layerName, &_numProperties, _propertiesContainer->operator VkExtensionProperties*()));
			}

			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
			*/
			static EResult QueryPhysicalDeviceListing(Handle _handle, uint32* _numDevices, PhysicalDevice::Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_handle, _numDevices, _deviceListing));
			}

			/**
			* @brief 
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceGroups">Specification</a> 
			*/
			static EResult QueryPhysicalDeviceGroups
			(
				Handle                 _handle         ,
				uint32*                _numGroups      ,
				PhysicalDevice::Group* _groupProperties
			)
			{
				return EResult(vkEnumeratePhysicalDeviceGroups(_handle, _numGroups, _groupProperties->operator VkPhysicalDeviceGroupProperties*()));
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
			static typename std::enable_if
			<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

			ReturnType>::type GetProcedureAddress(Handle& _handle, RoCStr _procedureName)
			{
				return reinterpret_cast<ReturnType>(vkGetInstanceProcAddr(_handle, _procedureName));
			}
		};
	}

	namespace V2
	{
		struct AppInstance : public V1::AppInstance
		{
			using Parent = V1::AppInstance;

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
			@brief Create a new Vulkan application instance. (Use default allocator)
			*/
			static EResult Create(const CreateInfo& _info, Handle& _handle)
			{
				return Parent::Create(_info, Memory::DefaultAllocator, _handle);
			}
			
			using Parent::Create;

			/**
			@brief Destroy an application instance of Vulkan. (Use Default allocator)
			*/
			static void Destroy(Handle _handle)
			{
				Parent::Destroy(_handle, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			static EResult GetAvailableLayers(DynamicArray<LayerProperties>& _container)
			{
				uint32 layerCount;

				EResult result = QueryAvailableLayers(layerCount, nullptr);

				if (result != EResult::Success) return result;

				_container.resize(layerCount);

				result = QueryAvailableLayers(layerCount, _container.data());

				return result;
			}

			static EResult GetAvailableLayerExtensions(RoCStr _layerName, DynamicArray<ExtensionProperties>& _propertiesContainer)
			{
				uint32 layerCount;

				EResult result = QueryAvailableAppExtensions(_layerName, layerCount, nullptr);

				if (result != EResult::Success) return result;

				_propertiesContainer.resize(layerCount);

				result = QueryAvailableAppExtensions(_layerName, layerCount, _propertiesContainer.data());

				return result;
			}

			static EResult GetAvailableLayersAndExtensions(DynamicArray<LayerAndExtensionProperties>& _layersAndExtensions)
			{
				DynamicArray<LayerProperties> layers; EResult result = EResult::Incomplete;

				GetAvailableLayers(layers);

				_layersAndExtensions.resize(layers.size());

				for (uint32 index = 0; index < layers.size(); index++)
				{
					_layersAndExtensions[index].Layer = layers[index];

					result = GetAvailableLayerExtensions(_layersAndExtensions[index].Layer.Name, _layersAndExtensions[index].Extensions);

					if (result != EResult::Success) return result;
				}

				return result;
			}

			/** 
			@brief Provides the handles of all available physical devices.

			@todo Make the device listing container type specifiable using an interface.
			*/
			static EResult GetAvailablePhysicalDevices(Handle _handle, DynamicArray<PhysicalDevice::Handle>& _deviceListing)
			{
				uint32 count; 
				
				//auto casted = reinterpret_cast<Vault_0::IDynamicArray<PhysicalDevice::Handle>*>(_deviceListing);

				EResult returnCode = QueryPhysicalDeviceListing(_handle, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_deviceListing.resize(count);

				returnCode = QueryPhysicalDeviceListing(_handle, &count, _deviceListing.data());

				return returnCode;
			}

			/**
			 * @brief Provides a list of the device groups present in the system.
			 * 
			 * @todo Make the group listing container type specifiable using an interface.
			 * 
			 * \param _instance
			 * \param _groupListing
			 * \return 
			 */
			static EResult GetAvailablePhysicalDeviceGroups(Handle _handle, DynamicArray<PhysicalDevice::Group>& _groupListing)
			{
				uint32 count;

				EResult returnCode = QueryPhysicalDeviceGroups(_handle, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_groupListing.resize(count);

				returnCode = QueryPhysicalDeviceGroups(_handle, &count, _groupListing.data());

				return returnCode;
			}
		};
	}

	namespace V3
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
		class AppInstance : public V2::AppInstance
		{
		public:
			using Parent = V2::AppInstance;

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 */
			EResult Create(AppInstance::AppInfo& _appInfo, AppInstance::CreateInfo& _createinfo)
			{
				appInfo      = _appInfo   ;
				createInfo   = _createinfo;
				allocator    = nullptr    ;

				if (createInfo.AppInfo != &appInfo) createInfo.AppInfo = &appInfo;

				EResult returnCode = Parent::GetVersion(version);

				if (returnCode != EResult::Success) return returnCode;

				return Parent::Create(createInfo, handle);
			}

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 * \param _allocator
			 */
			EResult Create(AppInstance::AppInfo& _appInfo, AppInstance::CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				appInfo    = _appInfo   ;
				createInfo = _createInfo;
				allocator  = _allocator ;

				EResult returnCode = Parent::GetVersion(version);

				if (returnCode != EResult::Success) return returnCode;

				return Parent::Create(createInfo, allocator, handle);
			}

			/**
			 * @brief Destroy an application instance.
			 */
			void Destroy()
			{
				Parent::Destroy(handle, allocator);
			}

			/** 
			@brief Provides the handles of all available physical devices.

			@todo Make the device listing container type specifiable using an interface.
			*/
			EResult GetAvailablePhysicalDevices(DynamicArray<PhysicalDevice>& _deviceListing) const 
			{
				uint32 count; DynamicArray<PhysicalDevice::Handle> handleList;

				EResult returnCode = QueryPhysicalDeviceListing(&count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				handleList    .resize(count);
				_deviceListing.resize(count);

				returnCode = QueryPhysicalDeviceListing(&count, handleList.data());
				
				for (DeviceSize index = 0; index < count; index++)
				{
					_deviceListing[index].AssignHandle(handleList[index]);
				}

				return returnCode;
			}

			/**
			 * @brief Provides a list of the device groups present in the system.
			 * 
			 * @todo Make the group listing container type specifiable using an interface.
			 * 
			 * \param _instance
			 * \param _groupListing
			 * \return 
			 */
			EResult GetAvailablePhysicalDeviceGroups(DynamicArray<PhysicalDevice::Group>& _groupListing) const
			{
				uint32 count;

				EResult returnCode = QueryPhysicalDeviceGroups(&count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_groupListing.resize(count);

				returnCode = QueryPhysicalDeviceGroups(&count, _groupListing.data());

				return returnCode;
			}

			const Handle& GetHandle() const
			{ 
				return handle; 
			}

			/**
			 * @brief Get application version.
			 * 
			 * \return 
			 */
			uint32 GetVersion() const
			{
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

			ReturnType>::type GetProcedureAddress(RoCStr _procedureName) const
			{
				return Parent::GetProcedureAddress(handle, _procedureName);  // reinterpret_cast<ReturnType>(vkGetInstanceProcAddr(handle, _procedureName));
			}

			EResult QueryPhysicalDeviceListing(uint32* _numDevices, PhysicalDevice::Handle* _deviceListing) const
			{
				return Parent::QueryPhysicalDeviceListing(handle, _numDevices, _deviceListing);
			}

			EResult QueryPhysicalDeviceGroups(uint32* _numGroups, PhysicalDevice::Group* _groupProperties) const
			{
				return Parent::QueryPhysicalDeviceGroups(handle, _numGroups, _groupProperties);
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

			Handle     handle    ;
			AppInfo    appInfo   ;
			CreateInfo createInfo;
			uint32     version   ;

			const Memory::AllocationCallbacks* allocator;
		};
	}
}
