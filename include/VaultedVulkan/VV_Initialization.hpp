/*!
@file VV_Initialization.hpp

@brief Vaulted Vulkan: Initialization

@details Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">
Initialization Specification
</a> 
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



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
	namespace Corridors
	{
		/**
		@addtogroup Corridors
		@{
		*/

		/**
		@ingroup Extending_Vulkan
		@brief Construct an API version number.
		
		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_MAKE_VERSION">Specification</a> 

		@param _major Major version number.
		@param _minor Minor version number.
		@param _patch Patch version number.
		*/
		inline u32 MakeVersion(u32 _major, u32 _minor, u32 _patch)
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
			@brief Opaque handle to an instance object.
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Specification</a>
			 
			@ingroup APISpec_Initialization
			*/
			using Handle = VkInstance;

			/**
			@ingroup APISpec_Initialization
			@brief Reserved for future use...
			 
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateFlags">Specification</a>
			 */
			using CreateFlags = Bitfield<EUndefined, VkInstanceCreateFlags>;

			/**
			@ingroup APISpec_Initialization
			@brief A structure that specifies to the Vulkan driver information about an application that will run an instance.
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkApplicationInfo">Application Info Specification</a> 
			*/
			struct AppInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::ApplicationInformation>
			{
				      EType        SType         = STypeEnum         ;
				const void*        Next          = nullptr           ;
				      RoCStr       AppName       = nullptr           ;
				      ui32         AppVersion    = 0                 ;
				      RoCStr       EngineName    = nullptr           ;
				      ui32         EngineVersion = 0                 ;
				      EAPI_Version API_Version   = EAPI_Version::_1_2;
			};

			/**
			@ingroup APISpec_Initialization
			@brief Structure specifying parameters of a newly created instance.
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateInfo">Create Info Specification</a> 
			*/
			struct CreateInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::Instance_CreateInfo>
			{
				      EType             SType                 = STypeEnum;
				const void*             Next                  = nullptr  ;
				      CreateFlags       Flags                ;
				const AppInfo*          AppInfo               = nullptr  ;
				      ui32              EnabledLayerCount     = 0        ;
				      RoArray_of_RoCStr EnabledLayerNames     = nullptr  ;
				      ui32              EnabledExtensionCount = 0        ;
					  RoArray_of_RoCStr EnabledExtensionNames = nullptr  ;
			};

			/**
			@brief Used when creating a Vulkan app instance and want to enable specific validation features. (Added to the Next chain).
			 
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFeaturesEXT">Specification</a> 
				
			@ingroup APISpec_Initialization
			*/
			struct ValidationFeatures : V0::VKStruct_Base<VkValidationFeaturesEXT, EStructureType::ValidationFeatures_EXT>
			{
					  EType                     SType                          = STypeEnum;
				const void*                     Next                           = nullptr  ;
					  ui32                      EnabledValidationFeatureCount  = 0        ;
				const EValidationFeatureEnable* EnabledValidationFeatures      = nullptr  ;
					  ui32                      DisabledValidationFeatureCount = 0        ;
				const EValidationFeatureEnable* DisabledValidationFeatures     = nullptr  ;
			};

			/**
			@brief Used when creating a Vulkan app instance and want to disable validation checks.
			 
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFlagsEXT">Specification</a> 
			 
			@ingroup APISpec_Initialization
			*/
			struct ValidationFlags : V0::VKStruct_Base<VkValidationFlagsEXT, EStructureType::ValidationFlags_EXT>
			{
					  EType             SType                        = STypeEnum;
				const void*             Next                         = nullptr  ;
					  ui32              DisabledValidationCheckCount = 0        ;
				const EValidationCheck* DisabledValidationChecks     = nullptr  ;
			};

			/**
			@ingroup APISpec_Initialization
			@brief Create a new Vulkan application instance.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateInstance">Create Instance Specification</a> 

			@param _info      The creation specification structure to use.
			@param _allocator Allocator desired (Memory::DefaultAllocator if default desired).
			@param _handle    Reference to object that will have the created object's handle written to (if successful).

			@return Returns EResult code (Indicating how the creation went).
			*/
			static EResult Create(const CreateInfo& _info, const Memory::AllocationCallbacks* _allocator, Handle& _handle)
			{
				return EResult(vkCreateInstance( _info, *_allocator, &_handle));
			}

			/**
			@ingroup APISpec_Initialization
			@brief Destroy an application instance of Vulkan.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyInstance">Destroy Instance Specification</a> 

			@param _handle    Handle of the AppInstance.
			@param _allocator Optional: Allocator to use (Memory::DefaultAllocator if default desired).
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
			 * @param _versionContainer The value of version will be written to this object referenced.
			 * 
			 * @return Returns EResult code (Indicating the version was able to be retrieved).
			 */
			static EResult GetVersion(ui32& _versionContainer)
			{
				return EResult(vkEnumerateInstanceVersion(&_versionContainer));
			}

			/** 
			@ingroup APISpec_Extending_Vulkan
			@brief Query the available layers.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceLayerProperties">Specification</a>  

			@param _numContainer         Referenced object that will either specify the number of available layers to retrieve (if _propertiesContainer is not null), 
			                             or be written to with the number of available layers (if _propertiesContainer is null).
			@param _propertiesContainer	 Pointer to a properties container array that will be populated if the pointer is not null.

			@return Returns EResult code (Indicating whether query was successful)
			*/
			static EResult QueryAvailableLayers(ui32& _numContainer, LayerProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceLayerProperties(&_numContainer, *_propertiesContainer));
			}

			/**
			@ingroup APISpec_Extending_Vulkan
			* @brief Query the available instance extensions.
			 
			@details 
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceExtensionProperties">Specification</a>.
			  
			*/
			static EResult QueryAvailableAppExtensions(RoCStr _layerName, ui32& _numProperties, ExtensionProperties* _propertiesContainer)
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
			static EResult QueryPhysicalDeviceListing(Handle _handle, ui32* _numDevices, PhysicalDevice::Handle* _deviceListing)
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
				ui32*                _numGroups      ,
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
				ui32 layerCount;

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
				ui32 layerCount;

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

				for (ui32 index = 0; index < layers.size(); index++)
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
				ui32 count; 
				
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
				ui32 count;

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
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.

		@ingroup APISpec_Initialization
		*/
		class AppInstance : public V2::AppInstance
		{
		public:
			using Parent = V2::AppInstance;

			/**
			@brief Will construct an AppInstance host object with a null handle and allocator set to default.
			*/
			AppInstance() : handle(Null<Handle>), allocator(Memory::DefaultAllocator)
			{}

			/**
			@brief Will construct an AppInstance host object with a null handle a the allocator set to the specified allocator.
			*/
			AppInstance(const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			AppInstance(AppInstance&& _other) noexcept :
				handle(_other.handle), allocator(_other.allocator)
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
			}

			/**
			@brief If the handle is found to not be null, this device will attempt to destroy the device object that corresponds to it.
			*/
			~AppInstance()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			 * @brief Create an application instance.
			 * 
			 * @param _appInfo
			 * @param _creationSpec
			 */
			EResult Create(const AppInstance::CreateInfo& _createinfo)
			{
				return Parent::Create(_createinfo, handle);
			}

			/**
			 * @brief Create an application instance.
			 * 
			 * @param _appInfo
			 * @param _creationSpec
			 * @param _allocator
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

				handle    = Null<Handle>;
				allocator = nullptr     ;
			}

			/** 
			@brief Provides the handles of all available physical devices.
			*/
			EResult GetAvailablePhysicalDevices(DynamicArray<PhysicalDevice>& _deviceListing) const 
			{
				ui32 count; DynamicArray<PhysicalDevice::Handle> handleList;

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
				ui32 count;

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
			EResult QueryPhysicalDeviceListing(ui32* _numDevices, PhysicalDevice::Handle* _deviceListing) const
			{
				return Parent::QueryPhysicalDeviceListing(handle, _numDevices, _deviceListing);
			}

			/**
			@brief Retrieve a list of physical device groups.
			*/
			EResult QueryPhysicalDeviceGroups(ui32* _numGroups, PhysicalDevice::Group* _groupProperties) const
			{
				return Parent::QueryPhysicalDeviceGroups(handle, _numGroups, _groupProperties);
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
			bool operator== (const AppInstance& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			AppInstance& operator= (AppInstance&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = _other.handle   ;
				allocator = _other.allocator;

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;
		};

		/** @} */
	}
}
