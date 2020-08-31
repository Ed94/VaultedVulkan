/** 
@file VT_LogicalDevice.hpp

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
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"



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
	namespace V1
	{
		/**
		 * @brief Represent logical connections to physical devices. 
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Specification</a> 
		 */
		struct LogicalDevice
		{
			using Memory = V0::Memory;

			using Handle = VkDevice;   ///< Opaque handle to a device object.  

			using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigCreateInfoNV">Specification</a> 
			*/
			struct DiagnosticsConfigCreateInfo : V0::VKStruct_Base<VkDeviceDiagnosticsConfigCreateInfoNV, EStructureType::DeviceDiagnosticsConfig_CreateInfo_NV>
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

				using PresentationInfo = VkPresentInfoKHR;   ///< Proper structure is defined later. (See VT_Swapchain.hpp)

				using SubmitInfo = VkSubmitInfo;   ///< Proper structure is defined later. (See VT_Command.hpp)

				using Fence_Handle = VkFence;

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateInfo">Specification</a> 
				 * 
				 * @details
				 * 
				 * A queue is allocated by the family, as in each queue allocated must have their index in the family tracked.
				 * This means that the logical device is passed a queue's create info by the family with its specified index,
				 * queue count from that family to be associated with the logical device, and the family's priority.
				 * 
				 * If a queue family is to be used for a specific task (transfer, etc), it is advantageous that that queue family 
				 * have as little flags for other functionality as possible.
				 */
				struct CreateInfo : V0::VKStruct_Base<VkDeviceQueueCreateInfo, EStructureType::DeviceQueue_CreateInfo>
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
				static void Get(LogicalDevice::Handle _device, uint32 _queueFamilyIndex, uint32 _queueIndex, Handle& _queueReturn)
				{
					vkGetDeviceQueue(_device, _queueFamilyIndex, _queueIndex, &_queueReturn);
				}

				/**
				* @brief.
				* 
				* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueuePresentKHR">Specification</a> 
				* 
				* \param _queue
				* \param _presentation
				* \return 
				*/
				static EResult QueuePresentation(LogicalDevice::Queue::Handle _queue, const PresentationInfo& _presentation)
				{
					return EResult(vkQueuePresentKHR(_queue, &_presentation));
				}

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueSubmit">Specification</a> 
				 *
				 * \param _queue
				 * \param _submitCount
				 * \param _submissions
				 * \param _fence
				 * \return 
				 */
				static EResult SubmitToQueue
				(
					      LogicalDevice::Queue::Handle _queue      ,
					      uint32                       _submitCount,
					const SubmitInfo*                  _submissions,
					      Fence_Handle                 _fence
				)
				{
					return EResult(vkQueueSubmit(_queue, _submitCount, _submissions, _fence));
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
			struct Queue2 : V0::VKStruct_Base<VkDeviceQueueInfo2, EStructureType::DeviceQueueInfo2>
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
			struct GroupCreateInfo : V0::VKStruct_Base<VkDeviceGroupDeviceCreateInfo, EStructureType::Device_GroupDevice_CreateInfo>
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
			struct MemoryOverallocationCreateInfo : V0::VKStruct_Base<VkDeviceMemoryOverallocationCreateInfoAMD, EStructureType::DeviceMemory_Overallocation_CreateInfo_AMD>
			{
				      EType                            SType                 ;
				const void*                            Next                  ;
				      EMemoryOverallocationBehaviorAMD OverallocationBehavior;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDevicePrivateDataCreateInfoEXT">Specification</a> 
			*/
			struct PrivateDataCreateInfo : V0::VKStruct_Base<VkDevicePrivateDataCreateInfoEXT, EStructureType::Device_PrivateData_CreateInfo_EXT>
			{
				      EType  SType                      ;
				const void*  Next                       ;
				      uint32 PrivateDataSlotRequestCount;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceCreateInfo">Specification</a> 
			 */
			struct CreateInfo : V0::VKStruct_Base<VkDeviceCreateInfo, EStructureType::Device_CreateInfo>
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
				const CreateInfo&                  _info          ,
				const Memory::AllocationCallbacks* _allocator     ,
				      Handle&                      _device
			)
			{
				return EResult(vkCreateDevice(_physicalDevice, _info.operator const VkDeviceCreateInfo *(), _allocator->operator const VkAllocationCallbacks*(), &_device));
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
			static void Destroy(Handle _device, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyDevice(_device, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDeviceWaitIdle">Specification</a> .
			 * 
			 * \param _device
			 * \return 
			 */
			static EResult WaitUntilIdle(Handle _device)
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
			static typename std::enable_if
			<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

			ReturnType>::type GetProcedureAddress(Handle& _appInstance, RoCStr _procedureName)
			{
				return reinterpret_cast<ReturnType>(vkGetDeviceProcAddr(_appInstance, _procedureName));
			}
		};
	}

	namespace V2
	{
		struct LogicalDevice : public V1::LogicalDevice
		{
			using Parent = V1::LogicalDevice;

			struct DiagnosticsConfigCreateInfo : public Parent::DiagnosticsConfigCreateInfo
			{
				DiagnosticsConfigCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct Queue : public Parent::Queue
			{
				struct CreateInfo : public Parent::Queue::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Queue2 : public Parent::Queue2
			{
				Queue2()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct GroupCreateInfo : public Parent::GroupCreateInfo
			{
				GroupCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct MemoryOverallocationCreateInfo : public Parent::MemoryOverallocationCreateInfo
			{
				MemoryOverallocationCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct PrivateDataCreateInfo : public Parent::PrivateDataCreateInfo
			{
				PrivateDataCreateInfo()
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

			/**
			 * @brief A logical device is created as a connection to a physical device. (Uses default allocator)
			 * 
			 * \param _physicalDevice
			 * \param _createSpec
			 * \param _allocator
			 * \param _device
			 * \return 
			 */
			static EResult Create
			(
				      PhysicalDevice::Handle _physicalDevice,
				const CreateInfo&            _createSpec    ,
				      Handle&                _device
			)
			{
				return Create(_physicalDevice, _createSpec, Memory::DefaultAllocator, _device);
			}

			using Parent::Create;

			/**
			* @brief Destroy a logical device. (Uses default allocator)
			* 
			* \param _handle
			* \param _allocator
			*/
			static void Destroy(Handle _device)
			{
				vkDestroyDevice(_device, Memory::DefaultAllocator->operator const VkAllocationCallbacks*());
			}

			using Parent::Destroy;
		};
	}

	namespace V3
	{
		class LogicalDevice : public V2::LogicalDevice
		{
		public:
			using Parent = V2::LogicalDevice;

			struct Queue : public Parent::Queue
			{
				using Parent = Parent::Queue;

				Queue() { assignment = EQueueFlag::MaxEnum; }

				void Assign(const LogicalDevice& _logicalDevice, CreateInfo& _info)
				{
					device = &_logicalDevice;
					info   = &_info         ;
					//info   = _info         ;

					queueIndex = 0;
				}

				void Assign(const LogicalDevice& _logicalDevice, CreateInfo& _info, uint32 _queueIndex, EQueueFlag _type)
				{
					device = &_logicalDevice;
					info   = &_info         ;
					//info   = _info         ;

					queueIndex = _queueIndex;

					assignment = _type;
				}

				uint32 GetFamilyIndex() const
				{
					return info->QueueFamilyIndex;
				}

				uint32 GetQueueIndex() const
				{
					return queueIndex;
				}

				const Handle& GetHandle() const
				{
					return handle;
				}

				const CreateInfo& GetInfo() const
				{
					return *info;
				}

				const EQueueFlag& GetType() const
				{
					return assignment;
				}

				void Retrieve()
				{
					Parent::Get(*device, info->QueueFamilyIndex, queueIndex, handle);
				}

				bool FamilySpecified() const
				{
					return assignment != EQueueFlag::MaxEnum ? true : false;
				}

				EResult QueuePresentation(const PresentationInfo& _presentationInfo) const
				{
					return Parent::QueuePresentation(handle, _presentationInfo);
				}

				/**
				 * 
				 * @todo remove.
				 * 
				 * \param _index
				 * \param _type
				 */
				void SpecifyFamily(uint32 _index, EQueueFlag _type)
				{
					queueIndex = _index; 
					assignment = _type ;
				}

				EResult SubmitToQueue(uint32 _submitCount, const SubmitInfo* _submissions, Fence_Handle _fence) const
				{
					return Parent::SubmitToQueue(handle, _submitCount, _submissions, _fence);
				}

				EResult WaitUntilIdle() const
				{
					return Parent::WaitUntilIdle(handle);
				}

				operator const Handle&() const
				{
					return handle;
				}
				
			protected:

				Handle handle;

				//CreateInfo* info;   // TODO Change to this
				CreateInfo* info;

				EQueueFlag assignment;

				const LogicalDevice* device;

				uint32 queueIndex;
			};

			void AssignPhysicalDevice(const PhysicalDevice& _physicalDevice)
			{
				physicalDevice = &_physicalDevice;
			}

			EResult Create(CreateInfo& _createInfo)
			{
				info      = _createInfo             ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*physicalDevice, info, handle);
			}

			EResult Create(CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				info      = _createInfo     ;
				allocator = _allocator      ;

				return Parent::Create(*physicalDevice, info, allocator, handle);
			}

			EResult Create(const PhysicalDevice& _physicalDevice, CreateInfo& _createInfo)
			{
				physicalDevice = &_physicalDevice        ;
				info           = _createInfo             ;
				allocator      = Memory::DefaultAllocator;

				return Parent::Create(*physicalDevice, info, handle);
			}

			EResult Create(const PhysicalDevice& _physicalDevice, CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				physicalDevice = &_physicalDevice;
				info           = _createInfo     ;
				allocator      = _allocator      ;

				return Parent::Create(*physicalDevice, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			const PhysicalDevice& GetPhysicalDevice() const
			{
				return *physicalDevice;
			}

			EResult WaitUntilIdle() const
			{
				return Parent::WaitUntilIdle(handle);
			}
			
			template<typename ReturnType>
			typename std::enable_if
			<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,
			ReturnType>::type GetProcedureAddress(RoCStr _procedurename) const
			{
				return Parent::GetProcedureAddress<ReturnType>(handle, _procedurename);
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			CreateInfo info;

			const PhysicalDevice* physicalDevice;

			const Memory::AllocationCallbacks* allocator;
		};
	}
}
