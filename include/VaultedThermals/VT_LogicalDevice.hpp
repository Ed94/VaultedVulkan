/*!
@file VT_LogicalDevice.hpp

@brief Vaulted Thermals: Logical Device
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
#include "VT_Initialization.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		@ingroup APISpec_Devices_and_Queues
		@brief Represent logical connections to physical devices. 
		 
		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Specification</a> 
		*/
		struct LogicalDevice
		{
			using Memory = V0::Memory;

			/**
			@ingroup APISpec_Devices_and_Queues
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDevice">Specification</a> 
			*/
			using Handle = VkDevice;

			using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

			/**
			@ingroup APISpec_Devices_and_Queues
			@brief 
			When using the Nsight� Aftermath SDK, to configure how device crash dumps are created, add a VkDeviceDiagnosticsConfigCreateInfoNV structure 
			to the pNext chain of the VkDeviceCreateInfo structure.
			 
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigCreateInfoNV">Specification</a> 
			*/
			struct DiagnosticsConfigCreateInfo : V0::VKStruct_Base<VkDeviceDiagnosticsConfigCreateInfoNV, EStructureType::DeviceDiagnosticsConfig_CreateInfo_NV>
			{
				using ConfigFlags = Bitmask<EDeviceDiagnosticConfigFlag, VkDeviceDiagnosticsConfigFlagsNV>;

				      EType       SType = STypeEnum;
				const void*       Next  = nullptr  ;
				      ConfigFlags Flags;
			};

			/**
			@ingroup APISpec_Devices_and_Queues
			@brief Queues handle different types of batched commands for the GPU to complete.
			@details 
			Vulkan queues provide an interface to the execution engines of a device. 
			Commands for these execution engines are recorded into command buffers ahead of execution time.
			These command buffers are then submitted to queues with a queue submission command for execution in a number of batches. 
			Once submitted to a queue, these commands will begin and complete execution without further application intervention,
			though the order of this execution is dependent on a number of implicit and explicit ordering constraints.
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-queueoperation">Specification</a> 
			*/
			struct Queue
			{
				/**
				@ingroup APISpec_Devices_and_Queues
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueue">Specification</a> 
				*/
				using Handle = VkQueue;

				using ECreateFlag = ELogicalDeviceQueueCreateFlag;

				/** @ingroup APISpec_Devices_and_Queues @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlags">Specification</a> */
				using CreateFlags = Bitmask<ECreateFlag, VkDeviceQueueCreateFlags>;

				/**
				@ingroup APISpec_Window_System_Integration_WSI
				@brief Used to specify parameters for a presentation.
				@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPresentInfoKHR">Specification</a> 
				*/
				using PresentationInfo = VkPresentInfoKHR;

				/**
				@ingroup APISpec_Command_Buffers
				@brief Specifies a command buffer submission batch
				@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a> 
				*/
				using SubmitInfo = VkSubmitInfo;

				/**
				@brief Internal definition of a fence (not defined yet...)
				*/
				using Fence_Handle = VkFence;

				/**
				@ingroup APISpec_Devices_and_Queues
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateInfo">Specification</a> 
				@details A queue is allocated by the family, as in each queue allocated must have their index in the family tracked.
				This means that the logical device is passed a queue's create info by the family with its specified index,
				queue count from that family to be associated with the logical device, and the family's priority.
				If a queue family is to be used for a specific task (transfer, etc), it is advantageous that that queue family 
				have as little flags for other functionality as possible.
				*/
				struct CreateInfo : V0::VKStruct_Base<VkDeviceQueueCreateInfo, EStructureType::DeviceQueue_CreateInfo>
				{
					      EType       SType            = STypeEnum       ;
					const void*       Next             = nullptr         ;
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
				* @ingroup APISpec_Devices_and_Queues
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
				* @brief Queue an image for presentation.
				* 
				* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueuePresentKHR">Specification</a> 
				* 
				* @ingroup APISpec_Window_System_Integration_WSI
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
				@brief Submit command buffers to the queue.
				 
				@details
				<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueSubmit">Specification</a>
				  
				@ingroup APISpec_Command_Buffers
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
				 * @brief To wait on the host for the completion of outstanding queue operations for a given queue.
				 * 
				 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueWaitIdle">Specification</a> 
				 * 
				 * @ingroup APISpec_Synchronization_and_Cache_Control
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
			* @ingroup APISpec_Devices_and_Queues
			* 
			* @todo #TODO: Add a brief comment.
			*/
			struct Queue2 : V0::VKStruct_Base<VkDeviceQueueInfo2, EStructureType::DeviceQueueInfo2>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlags">Specification</a> @ingroup APISpec_Devices_and_Queues */
				using CreateFlags = Bitmask<EDeviceQueueCreateFlag ,VkDeviceQueueCreateFlags>;

				      EType       SType            = STypeEnum;
				const void*       Next             = nullptr  ;
				      CreateFlags Flags           ;
				      uint32      QueueFamilyIndex;
				      uint32      QueueIndex      ;

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDeviceQueue2">Specification</a> 
				* 
				* @ingroup APISpec_Devices_and_Queues
				*/
				static void Get
				(
					      Handle         _device   ,
					const Queue2*        _queueInfo,
					      Queue::Handle* _queue
				)
				{
					vkGetDeviceQueue2(_device, *_queueInfo, _queue);
				}
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupDeviceCreateInfo">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct GroupCreateInfo : V0::VKStruct_Base<VkDeviceGroupDeviceCreateInfo, EStructureType::Device_GroupDevice_CreateInfo>
			{
				      EType   SType               = STypeEnum;
				const void*   Next                = nullptr  ;
				      uint32  PhysicalDeviceCount = 0        ;
				const Handle* PhysicalDevices     = nullptr  ;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemoryOverallocationCreateInfoAMD">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct MemoryOverallocationCreateInfo : V0::VKStruct_Base<VkDeviceMemoryOverallocationCreateInfoAMD, EStructureType::DeviceMemory_Overallocation_CreateInfo_AMD>
			{
				      EType                            SType                  = STypeEnum                                ;
				const void*                            Next                   = nullptr                                  ;
				      EMemoryOverallocationBehaviorAMD OverallocationBehavior = EMemoryOverallocationBehaviorAMD::Default;
			};

			/**
			* @brief Used to reserve private data storage slots.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDevicePrivateDataCreateInfoEXT">Specification</a>
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct PrivateDataCreateInfo : V0::VKStruct_Base<VkDevicePrivateDataCreateInfoEXT, EStructureType::Device_PrivateData_CreateInfo_EXT>
			{
				      EType  SType                       = STypeEnum;
				const void*  Next                        = nullptr  ;
				      uint32 PrivateDataSlotRequestCount;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceCreateInfo">Specification</a> 
			 * 
			 * @ingroup APISpec_Devices_and_Queues
			 */
			struct CreateInfo : V0::VKStruct_Base<VkDeviceCreateInfo, EStructureType::Device_CreateInfo>
			{
				      EType                     SType                 = STypeEnum;
				const void*                     Next                  = nullptr  ;
				      CreateFlags               Flags                ;
				      uint32                    QueueCreateInfoCount  = 0        ;
				const Queue::CreateInfo*        QueueCreateInfos      = nullptr  ;
				      uint32                    EnabledLayerCount     = 0        ;
					  RoArray_of_RoCStr         EnabledLayerNames     = nullptr  ;
				      uint32                    EnabledExtensionCount = 0        ;
					  RoArray_of_RoCStr         EnabledExtensionNames = nullptr  ;
				const PhysicalDevice::Features* EnabledFeatures       = nullptr  ;
			};

			/**
			 * @brief A logical device is created as a connection to a physical device.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDevice">Specification</a> 
			 * 
			 * @ingroup APISpec_Devices_and_Queues
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
				return EResult(vkCreateDevice(_physicalDevice, _info, *_allocator, &_device));
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
			 * @ingroup APISpec_Devices_and_Queues
			 * 
			 * \param _handle
			 * \param _allocator
			 */
			static void Destroy(Handle _device, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyDevice(_device, *_allocator);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDeviceWaitIdle">Specification</a> .
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
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

			@ingroup APISpec_Initialization
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

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		* @brief Represent logical connections to physical devices. 
		* 
		* @details
		* 
		* @ingroup APISpec_Devices_and_Queues
		*/
		struct LogicalDevice : public V1::LogicalDevice
		{
			using Parent = V1::LogicalDevice;

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
				vkDestroyDevice(_device, *Memory::DefaultAllocator);
			}

			using Parent::Destroy;
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
		@todo #TODO: Add documentation.
		*/
		class LogicalDevice : public V2::LogicalDevice
		{
		public:
			using Parent = V2::LogicalDevice;

			struct Queue : public Parent::Queue
			{
				using Parent = Parent::Queue;

				Queue() { assignment = EQueueFlag::VT_SpecifyBitmaskable; }

				Queue(EQueueFlag _type, const LogicalDevice& _device, uint32 _familyIndex, uint32 _queueIndex) :
					assignment(_type), device(&_device), familyIndex(_familyIndex), queueIndex(_queueIndex)
				{}

				void Assign(const LogicalDevice& _logicalDevice, uint32 _familyIndex, uint32 _queueIndex, EQueueFlag _type)
				{
					device      = &_logicalDevice;
					familyIndex = _familyIndex   ;
					queueIndex  = _queueIndex    ;
					assignment  = _type          ;
				}

				uint32 GetFamilyIndex() const
				{
					return familyIndex;
				}

				uint32 GetQueueIndex() const
				{
					return queueIndex;
				}

				const Handle& GetHandle() const
				{
					return handle;
				}

				const EQueueFlag& GetType() const
				{
					return assignment;
				}

				void Retrieve()
				{
					Parent::Get(*device, familyIndex, queueIndex, handle);
				}

				bool FamilySpecified() const
				{
					return assignment != EQueueFlag::VT_SpecifyBitmaskable ? true : false;
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

				EQueueFlag assignment;

				const LogicalDevice* device;

				uint32 familyIndex;

				uint32 queueIndex;
			};

			/*LogicalDevice() : handle(Null<Handle>), physicalDevice(nullptr), allocator(Memory::DefaultAllocator)
			{}

			LogicalDevice(const PhysicalDevice& _physicalDevice) : handle(Null<Handle>), physicalDevice(&_physicalDevice), allocator(Memory::DefaultAllocator)
			{}

			LogicalDevice(const PhysicalDevice& _physicalDevice, const Memory::AllocationCallbacks& _allocator) : 
				handle(Null<Handle>), physicalDevice(&_physicalDevice), allocator(&_allocator) 
			{}

			~LogicalDevice()
			{
				if (handle != Null<Handle>) Destroy();
			}*/

			void AssignPhysicalDevice(const PhysicalDevice& _physicalDevice) 
			{
				physicalDevice = &_physicalDevice;
			}

			EResult Create(const CreateInfo& _createInfo)
			{
				if (physicalDevice == nullptr) return EResult::Not_Ready;

				allocator = Memory::DefaultAllocator;

				return Parent::Create(*physicalDevice, _createInfo, handle);
			}

			EResult Create(const CreateInfo& _createInfo, const Memory::AllocationCallbacks& _allocator)
			{
				if (physicalDevice == nullptr) return EResult::Not_Ready;

				allocator = &_allocator;

				return Parent::Create(*physicalDevice, _createInfo, allocator, handle);
			}

			EResult Create(const PhysicalDevice& _physicalDevice, const CreateInfo& _createInfo)
			{
				physicalDevice = &_physicalDevice        ;
				allocator      = Memory::DefaultAllocator;

				return Parent::Create(*physicalDevice, _createInfo, handle);
			}

			EResult Create(const PhysicalDevice& _physicalDevice, const CreateInfo& _createInfo, const Memory::AllocationCallbacks& _allocator)
			{
				physicalDevice = &_physicalDevice;
				allocator      = &_allocator     ;

				return Parent::Create(*physicalDevice, _createInfo, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(handle, allocator);

				handle    = Null<Handle>;
				allocator = nullptr     ;
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

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const LogicalDevice& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const PhysicalDevice* physicalDevice;

			const Memory::AllocationCallbacks* allocator;
		};

		/** @} */
	}
}
