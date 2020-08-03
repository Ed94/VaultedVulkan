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
	namespace Vault_01
	{
		/**
		 * @brief Represent logical connections to physical devices. 
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Specification</a> 
		 */
		struct LogicalDevice
		{
			using Handle = VkDevice;   ///< Opaque handle to a device object.  

			using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

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
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceQueueCreateInfo.html">Specification</a> 
				 */
				struct CreateInfo : Vault_00::VKStruct_Base<VkDeviceQueueCreateInfo, EStructureType::DeviceQueue_CreateInfo>
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
				* <a href="linkURL">Specification</a> 
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
				 * @brief <a href="linkURL">Specification</a> 
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
			struct Queue2
			{
				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDeviceQueue2">Specification</a> 
				* 
				* @todo Implement.
				*/
				static void Get();
			};

			struct Group
			{
				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupDeviceCreateInfo">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct CreateInfo
				{

				};
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceCreateInfo.html">Specification</a> 
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkDeviceCreateInfo, EStructureType::Device_CreateInfo>
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

			struct Diagnoistics
			{
				struct Config
				{
					/**
					* @details
					* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigCreateInfoNV">Specification</a> 
					* 
					* @todo Implement.
					*/
					struct CreateInfo
					{

					};
				};
			};

			struct MemoryOverallocation
			{
				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemoryOverallocationCreateInfoAMD">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct CreateInfo
				{

				};
			};	

			struct PrivateData
			{
				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDevicePrivateDataCreateInfoEXT">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct CreateInfo
				{

				};
			};

			/**
			 * @brief A logical device is created as a connection to a physical device.
			 * 
			 * \param _physicalDevice
			 * \param _createSpec
			 * \param _allocator
			 * \param _device
			 * \return 
			 */
			static EResult Create
			(
				      PhysicalDevice::Handle     _physicalDevice,
				const LogicalDevice::CreateInfo& _createSpec    ,
				const Memory::AllocationCallbacks*       _allocator     ,
				      LogicalDevice::Handle&     _device
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
			 * \param _handle
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _handle, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyDevice(_handle, _allocator->operator const VkAllocationCallbacks*());
			}

			static EResult WaitUntilIdle(LogicalDevice::Handle _device)
			{
				return EResult(vkDeviceWaitIdle(_device));
			}

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
		};
	}

	namespace Vault_02
	{
		using Vault_01::LogicalDevice;
	}

	namespace Vault_05
	{

	}
}
