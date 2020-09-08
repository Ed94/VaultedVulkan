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
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace Corridors
	{
		/**
		@addtogroup Corridors
		@{
		*/

		/**
		 * @brief Construct an API version number.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_MAKE_VERSION">Specification</a> 
		 * 
		 * \param _major
		 * \param _minor
		 * \param _patch
		 * \return 
		 * 
		 * @ingroup Extending_Vulkan
		 */
		inline uInt32 MakeVersion(uInt32 _major, uInt32 _minor, uInt32 _patch)
		{
			return VK_MAKE_VERSION(_major, _minor, _patch);
		}

		/** @} */
	}

	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		@brief An object that manages the represented application process state within the GPU.

		Other Name: Application State Container

		@details
		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Application Instance Specification</a> 

		@ingroup APISpec_Initialization
		*/
		struct AppInstance
		{
			using Memory = V0::Memory;

			/**
			 * @brief Opaque handle to an instance object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Specification</a>
			 * 
			 * @ingroup APISpec_Initialization
			 */
			using Handle = VkInstance;

			/**
			 * @brief Reserved for future use...
			 * 
			 @details
			 <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateFlags">Specification</a>

			 @ingroup APISpec_Initialization
			 */
			using CreateFlags = Bitmask<EUndefined, VkInstanceCreateFlags>;

			/**
			@brief 
			A structure that specifies to the Vulkan driver information about an
			application that will run an instance.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkApplicationInfo">Application Info Specification</a> 

			@ingroup APISpec_Initialization
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

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateInfo">Create Info Specification</a> 

			@ingroup APISpec_Initialization
			*/
			struct CreateInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::Instance_CreateInfo>
			{
				      EType             SType                ;
				const void*             Next                 ;
				      CreateFlags       Flags                ;
				const AppInfo*          AppInfo              ;
				      uint32            EnabledLayerCount    ;
				      RoArray_of_RoCStr EnabledLayerNames    ;
				      uint32            EnabledExtensionCount;
					  RoArray_of_RoCStr EnabledExtensionNames;
			};

			/**
			@brief Used when creating a Vulkan app instance and want to enable specific validation features. (Added to the Next chain).
			 
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFeaturesEXT">Specification</a> 
				
			@ingroup APISpec_Initialization
			*/
			struct ValidationFeatures : V0::VKStruct_Base<VkValidationFeaturesEXT, EStructureType::ValidationFeatures_EXT>
			{
					  EType                     SType                         ;
				const void*                     Next                          ;
					  uint32                    EnabledValidationFeatureCount ;
				const EValidationFeatureEnable* EnabledValidationFeatures     ;
					  uint32                    DisabledValidationFeatureCount;
				const EValidationFeatureEnable* DisabledValidationFeatures    ;
			};

			/**
			@brief Used when creating a Vulkan app instance and want to disable validation checks.
			 
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFlagsEXT">Specification</a> 
			 
			@ingroup APISpec_Initialization
			*/
			struct ValidationFlags : V0::VKStruct_Base<VkValidationFlagsEXT, EStructureType::ValidationFlags_EXT>
			{
					  EType             SType                       ;
				const void*             Next                        ;
					  uint32            DisabledValidationCheckCount;
				const EValidationCheck* DisabledValidationChecks    ;
			};

			/**
			@brief Create a new Vulkan application instance.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateInstance">Create Instance Specification</a> 

			@ingroup APISpec_Initialization
			*/
			static EResult Create
			(
				const CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle&                      _handle
			)
			{
				return EResult(vkCreateInstance( _info, *_allocator, &_handle));
			}

			/**
			@brief Destroy an application instance of Vulkan.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyInstance">Destroy Instance Specification</a> 

			@ingroup APISpec_Initialization
			*/
			static void Destroy(Handle _handle , const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyInstance(_handle, *_allocator);
			}

			/**
			 * @brief Query the version of application instance-level functionality supported by the implementation.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceVersion">Specification</a> 
			 * 
			 * @ingroup APISpec_Initialization
			 * 
			 * \param _versionContainer
			 * \return 
			 */
			static EResult GetVersion(uint32& _versionContainer)
			{
				return EResult(vkEnumerateInstanceVersion(&_versionContainer));
			}

			/** 
			@brief Query the available layers.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceLayerProperties">Specification</a>  

			@ingroup APISpec_Extending_Vulkan
			*/
			static EResult QueryAvailableLayers(uint32& _numContainer, LayerProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceLayerProperties(&_numContainer, *_propertiesContainer));
			}

			/**
			 * @brief Query the available instance extensions.
			 
			 @details 
			 <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceExtensionProperties">Specification</a>.
			  
			 @ingroup APISpec_Extending_Vulkan
			 */
			static EResult QueryAvailableAppExtensions(RoCStr _layerName, uint32& _numProperties, ExtensionProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceExtensionProperties(_layerName, &_numProperties, *_propertiesContainer));
			}

			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 

			@ingroup APISpec_Devices_and_Queues
			*/
			static EResult QueryPhysicalDeviceListing(Handle _handle, uint32* _numDevices, PhysicalDevice::Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_handle, _numDevices, _deviceListing));
			}

			/**
			* @brief Retrieve a list of physical device groups.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceGroups">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			static EResult QueryPhysicalDeviceGroups
			(
				Handle                 _handle         ,
				uint32*                _numGroups      ,
				PhysicalDevice::Group* _groupProperties
			)
			{
				return EResult(vkEnumeratePhysicalDeviceGroups(_handle, _numGroups, *_groupProperties));
			}

			template<typename ReturnType>
			/**
			
			@brief
			Function pointers for all Vulkan commands can be obtained with this command.

			@details
			vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
			Typically, the loader library will export this command as a function symbol, 
			so applications can link against the loader library, or load it dynamically 
			and look up the symbol using platform-specific APIs.

			Note: ReturnType is restricted to only function pointing types.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetInstanceProcAddr">Specification</a> 

			@ingroup APISpec_Initialization
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

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief An object that manages the represented application process state within the GPU.

		@details
		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		@ingroup APISpec_Initialization
		*/
		struct AppInstance : public V1::AppInstance
		{
			using Parent = V1::AppInstance;

			/**
			@brief Offers a default constructor.
			*/
			struct AppInfo : public Parent::AppInfo
			{
				AppInfo() 
				{ 
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo() 
				{
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct ValidationFeatures : public Parent::ValidationFeatures
			{
				ValidationFeatures() 
				{ 
					SType = STypeEnum; 
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct ValidationFlags : public Parent::ValidationFlags
			{
				ValidationFlags() 
				{ 
					SType = STypeEnum; 
				}
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

			/**
			@brief Get available layers into a dynamic array. 
			*/
			static EResult GetAvailableLayers(DynamicArray<LayerProperties>& _container)
			{
				uint32 layerCount;

				EResult result = QueryAvailableLayers(layerCount, nullptr);

				if (result != EResult::Success) return result;

				_container.resize(layerCount);

				result = QueryAvailableLayers(layerCount, _container.data());

				return result;
			}

			/**
			@brief Get available layer extensions into a dynamic array with the specified layer name.
			*/
			static EResult GetAvailableLayerExtensions(RoCStr _layerName, DynamicArray<ExtensionProperties>& _propertiesContainer)
			{
				uint32 layerCount;

				EResult result = QueryAvailableAppExtensions(_layerName, layerCount, nullptr);

				if (result != EResult::Success) return result;

				_propertiesContainer.resize(layerCount);

				result = QueryAvailableAppExtensions(_layerName, layerCount, _propertiesContainer.data());

				return result;
			}

			/**
			Get the layers and their extensions in a dynamic array of the layer and extensions properties struct.
			*/
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

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@brief An object that manages the represented application process state within the GPU.

		@details
		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		@ingroup APISpec_Initialization
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
			EResult Create(const AppInstance::CreateInfo& _createinfo)
			{
				allocator = nullptr;

				return Parent::Create(_createinfo, handle);
			}

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 * \param _allocator
			 */
			EResult Create(const AppInstance::CreateInfo& _createInfo, const Memory::AllocationCallbacks& _allocator)
			{
				allocator = &_allocator;

				return Parent::Create(_createInfo, allocator, handle);
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

			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.
			*/
			EResult QueryPhysicalDeviceListing(uint32* _numDevices, PhysicalDevice::Handle* _deviceListing) const
			{
				return Parent::QueryPhysicalDeviceListing(handle, _numDevices, _deviceListing);
			}

			/**
			@brief Retrieve a list of physical device groups.
			*/
			EResult QueryPhysicalDeviceGroups(uint32* _numGroups, PhysicalDevice::Group* _groupProperties) const
			{
				return Parent::QueryPhysicalDeviceGroups(handle, _numGroups, _groupProperties);
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

			bool operator== (const AppInstance& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;
		};

		/** @} */
	}
}