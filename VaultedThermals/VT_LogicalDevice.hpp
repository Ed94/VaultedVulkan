/** @file VT_LogicalDevice.hpp

@brief Vaulted Thermals: Logical Device
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
#include "VT_Initialization.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_1
	{
		/**
		 * @brief Represent logical connections to physical devices. 
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Specification</a> 
		 */
		struct LogicalDevice
		{
			using Memory = Vault_0::Memory;

			using Handle = VkDevice;   ///< Opaque handle to a device object.  

			using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigCreateInfoNV">Specification</a> 
			*/
			struct DiagnoisticsConfigCreateInfo : Vault_0::VKStruct_Base<VkDeviceDiagnosticsConfigCreateInfoNV, EStructureType::DeviceDiagnosticsConfig_CreateInfo_NV>
			{
				using ConfigFlags = Bitmask<EDeviceDiagnosticConfigFlag, VkDeviceDiagnosticsConfigFlagsNV>;

				      EType       SType;
				const void*       Next ;
				      ConfigFlags Flags;
			};

			/**
			 * @brief Queues handle different types of batched commands for the GPU to complete.
			 * 
			 * @details 
			 * Vulkan queues provide an interface to the execution engines of a device. 
			 * Commands for these execution engines are recorded into command buffers ahead of execution time.
			 * These command buffers are then submitted to queues with a queue submission command for execution in a number of batches. 
			 * Once submitted to a queue, these commands will begin and complete execution without further application intervention,
			 * though the order of this execution is dependent on a number of implicit and explicit ordering constraints.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-queueoperation">Specification</a> 
			 */
			struct Queue
			{
				using Handle = VkQueue;   ///< Opaque handle to a queue object

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateInfo">Specification</a> 
				 */
				struct CreateInfo : Vault_0::VKStruct_Base<VkDeviceQueueCreateInfo, EStructureType::DeviceQueue_CreateInfo>
				{
					using ECreateFlag = ELogicalDeviceQueueCreateFlag                 ;
					using CreateFlags = Bitmask<ECreateFlag, VkDeviceQueueCreateFlags>;

						  EType       SType           ;
					const void*       Next            ;
						  CreateFlags Flags           ;
						  uint32      QueueFamilyIndex;
						  uint32      QueueCount      ;
					const float*      QueuePriorities ;
				};

				/**
				* @brief Get a queue handle from a device.
				* 
				* @details
				* vkGetDeviceQueue must only be used to get queues that were created with the flags parameter of VkDeviceQueueCreateInfo set to zero. 
				* To get queues that were created with a non-zero flags parameter use vkGetDeviceQueue2.
				* 
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDeviceQueue">Specification</a> 
				* 
				* \param _handle
				* \param _queueFamilyIndex
				* \param _queueIndex
				* \param _queueReturn
				*/
				static void Get(LogicalDevice::Handle _handle, uint32 _queueFamilyIndex, uint32 _queueIndex, Handle& _queueReturn)
				{
					vkGetDeviceQueue(_handle, _queueFamilyIndex, _queueIndex, &_queueReturn);
				}

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueWaitIdle">Specification</a> 
				 * 
				 * \param _queue
				 * \return 
				 */
				static EResult WaitUntilIdle(Handle _queue)
				{
					return EResult(vkQueueWaitIdle(_queue));
				}
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueInfo2">Specification</a> 
			* 
			* @todo Implement.
			*/
			struct Queue2 : Vault_0::VKStruct_Base<VkDeviceQueueInfo2, EStructureType::DeviceQueueInfo2>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EDeviceQueueCreateFlag ,VkDeviceQueueCreateFlags>;

				      EType       SType           ;
				const void*       Next            ;
				      CreateFlags Flags           ;
				      uint32      QueueFamilyIndex;
				      uint32      QueueIndex      ;

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDeviceQueue2">Specification</a> 
				* 
				* @todo Implement.
				*/
				static void Get
				(
					      Handle         _device   ,
					const Queue2*        _queueInfo,
					      Queue::Handle* _queue
				)
				{
					vkGetDeviceQueue2(_device, _queueInfo->operator const VkDeviceQueueInfo2*(), _queue);
				}
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupDeviceCreateInfo">Specification</a> 
			*/
			struct GroupCreateInfo : Vault_0::VKStruct_Base<VkDeviceGroupDeviceCreateInfo, EStructureType::Device_GroupDevice_CreateInfo>
			{
				      EType   SType              ;
				const void*   Next               ;
				      uint32  PhysicalDeviceCount;
				const Handle* PhysicalDevices    ;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemoryOverallocationCreateInfoAMD">Specification</a> 
			*/
			struct MemoryOverallocationCreateInfo : Vault_0::VKStruct_Base<VkDeviceMemoryOverallocationCreateInfoAMD, EStructureType::DeviceMemory_Overallocation_CreateInfo_AMD>
			{
				      EType                            SType                 ;
				const void*                            Next                  ;
				      EMemoryOverallocationBehaviorAMD OverallocationBehavior;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDevicePrivateDataCreateInfoEXT">Specification</a> 
			*/
			struct PrivateDataCreateInfo : Vault_0::VKStruct_Base<VkDevicePrivateDataCreateInfoEXT, EStructureType::Device_PrivateData_CreateInfo_EXT>
			{
				      EType  SType                      ;
				const void*  Next                       ;
				      uint32 PrivateDataSlotRequestCount;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceCreateInfo">Specification</a> 
			 */
			struct CreateInfo : Vault_0::VKStruct_Base<VkDeviceCreateInfo, EStructureType::Device_CreateInfo>
			{
					  EType                     SType                ;
				const void*                     Next                 ;
					  CreateFlags               Flags                ;
					  uint32                    QueueCreateInfoCount ;
				const Queue::CreateInfo*        QueueCreateInfos     ;
					  uint32                    EnabledLayerCount    ;
				      RoSCtr_roArray_Array      EnabledLayerNames    ;
					  uint32                    EnabledExtensionCount;
				      RoSCtr_roArray_Array      EnabledExtensionNames;
				const PhysicalDevice::Features* EnabledFeatures      ;
			};

			/**
			 * @brief A logical device is created as a connection to a physical device.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDevice">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _createSpec
			 * \param _allocator
			 * \param _device
			 * \return 
			 */
			static EResult Create
			(
				      PhysicalDevice::Handle       _physicalDevice,
				const LogicalDevice::CreateInfo&   _createSpec    ,
				const Memory::AllocationCallbacks* _allocator     ,
				      LogicalDevice::Handle&       _device
			)
			{
				return EResult(vkCreateDevice(_physicalDevice, _createSpec.operator const VkDeviceCreateInfo *(), _allocator->operator const VkAllocationCallbacks*(), &_device));
			}

			/**
			 * @brief Destroy a logical device.
			 * 
			 * @details
			 * To ensure that no work is active on the device, vkDeviceWaitIdle can be used to gate the destruction of the device. 
			 * Prior to destroying a device, an application is responsible for destroying/freeing any Vulkan objects that were created 
			 * using that device as the first parameter of the corresponding vkCreate* or vkAllocate* command.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDevice">Specification</a> 
			 * 
			 * \param _handle
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _handle, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyDevice(_handle, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDeviceWaitIdle">Specification</a> .
			 * 
			 * \param _device
			 * \return 
			 */
			static EResult WaitUntilIdle(LogicalDevice::Handle _device)
			{
				return EResult(vkDeviceWaitIdle(_device));
			}

			template<typename ReturnType>
			/** 
			@brief Function pointers for all Vulkan commands directly addressed from the device.

			@details
			In order to support systems with multiple Vulkan implementations, the function pointers returned by vkGetInstanceProcAddr
			may point to dispatch code that calls a different real implementation for different VkDevice objects or their child objects.
			The overhead of the internal dispatch for VkDevice objects can be avoided by obtaining device-specific function pointers
			for any commands that use a device or device-child object as their dispatchable object.

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

			ReturnType>::type GetProcedureAddress(LogicalDevice::Handle& _appInstance, RoCStr _procedureName)
			{
				return reinterpret_cast<ReturnType>(vkGetDeviceProcAddr(_appInstance, _procedureName));
			}
		};
	}

	namespace Vault_2
	{
		struct LogicalDevice : public Vault_1::LogicalDevice
		{
			using Parent = Vault_1::LogicalDevice;

			struct Queue : public Parent::Queue
			{
				
			};
		};
	}

	namespace Vault_5
	{
		class LogicalDevice : public Vault_1::LogicalDevice
		{
		public:
			using Parent = Vault_1::LogicalDevice;


		protected:

			Handle handle;
		};
	}
}
