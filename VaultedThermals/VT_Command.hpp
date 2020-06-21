/**
@file VT_Command.hpp

@brief Vaulted Thermals: Command Buffers

@details

<a href="linkURL">Specification</a> 
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
#include "VT_Initialization.hpp"
#include "VT_Sampler.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Resource.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		/**
		 * @brief.
		 */
		struct CommandPool
		{
			using Handle = VkCommandPool;

			using CreateFlgas = Bitmask<ECommandPoolCreateFlag, VkCommandPoolCreateFlags>;
			using ResetFlags  = Bitmask<ECommandPoolResetFlags, VkCommandPoolResetFlags >;
			using TrimFlags   = Bitmask<EUndefined            , VkCommandPoolTrimFlags  >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkCommandPoolCreateInfo>
			{
				      EType       SType           ;
				const void*       Next            ;
				      CreateFlgas Flags           ;
				      uint32      QueueFamilyIndex;
			};

			/**
			 * @brief Create a command pool.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateCommandPool">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _commandPool
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle  _deviceHandle,
				const CreateInfo&            _createInfo  ,
				const VkAllocationCallbacks* _allocator   ,
				      CommandPool::Handle&   _commandPool
			)
			{
				return EResult(vkCreateCommandPool(_deviceHandle, _createInfo.operator const VkCommandPoolCreateInfo*(), _allocator, &_commandPool));
			}

			/**
			 * @brief.
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle _deviceHandle,
				      Handle                _commandPool ,
				const AllocationCallbacks*  _allocator
			)
			{
				vkDestroyCommandPool(_deviceHandle, _commandPool, _allocator);
			}

			/**
			 * @brief.
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _flags
			 */
			static void Reset
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _commandPool ,
				ResetFlags            _flags
			)
			{
				vkResetCommandPool(_deviceHandle, _commandPool, _flags);
			}

			/**
			 * @brief.
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _flags
			 */
			static void Trim
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _commandPool ,
				TrimFlags             _flags
			)
			{
				vkTrimCommandPool(_deviceHandle, _commandPool, _flags);	
			}
		};

		/**
		 * @brief.
		 */
		struct CommandBuffer
		{
			using Handle = VkCommandBuffer;

			using EBufferLevel = ECommandBufferLevel;

			using QueryControlFlags           = Bitmask<EQueryControlFlags         , VkQueryControlFlags          >;
			using QueryPipelineStatisticFlags = Bitmask<EQueryPipelineStatisticFlag, VkQueryPipelineStatisticFlags>;
			using ResetFlags                  = Bitmask<ECommandBufferResetFlag    , VkCommandBufferResetFlags    >;
			using UsageFlags                  = Bitmask<ECommandBufferUsageFlag    , VkCommandBufferUsageFlags    >;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferAllocateInfo">Specification</a> .
			 */
			struct AllocateInfo : Vault_00::VKStruct_Base<VkCommandBufferAllocateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      CommandPool::Handle Pool       ;
					  EBufferLevel        Level      ;
				      uint32              BufferCount;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceInfoURL">Specification</a>
			 */
			struct InheritanceWindow : Vault_00::VKStruct_Base<VkCommandBufferInheritanceInfo>
			{
				      EType                       SType               ;
				const void*                       Next                ;
				      RenderPass::Handle          RenderPass          ;
				      uint32                      Subpass             ;
				      Framebuffer::Handle         Framebuffer         ;
				      Bool                        OcclusionQueryEnable;
				      QueryControlFlags           QueryFlags          ;
				      QueryPipelineStatisticFlags PipelineStatistics  ;

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceConditionalRenderingInfoEXT">Specification</a>
				 */
				struct ConditionalRenderingInfo : Vault_00::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT>
				{
					      EType SType ;
					const void* Next  ;
					      Bool  Enable;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 
				 */
				struct PassTransformInfo : Vault_00::VKStruct_Base<VkCommandBufferInheritanceRenderPassTransformInfoQCOM >
				{
					EType                 SType     ;
					void*                 Next      ;
					ESurfaceTransformFlag Transform ;
					Rect2D                RenderArea;
				};
			};	

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferBeginInfo">Specification</a>
			 */
			struct BeginInfo : Vault_00::VKStruct_Base<VkCommandBufferBeginInfo>
			{
				      EType              SType          ;
				const void*              Next           ;
				      UsageFlags         Flags          ;
				const InheritanceWindow* InheritanceInfo;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			 */
			struct SubmitInfo : Vault_00::VKStruct_Base<VkSubmitInfo>
			{
				      EType                 SType               ;
				const void*                 Next                ;
				      uint32                WaitSemaphoreCount  ;
				const VkSemaphore*          WaitSemaphores      ;   ///< @todo Replace with proper later.
				const Pipeline::StageFlags* WaitDstStageMask    ;
				      uint32                CommandBufferCount  ;
				const Handle*               CommandBuffers      ;
				      uint32                SignalSemaphoreCount;
				const VkSemaphore*          SignalSemaphores    ;   ///< @todo Replace with proper later.


				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkTimelineSemaphoreSubmitInfo">Specification</a>
				 * 
				 * @todo Implement.
				 */
				struct TimelineSemaphore : Vault_00::VKStruct_Base<VkTimelineSemaphoreSubmitInfo>
				{

				};	

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkD3D12FenceSubmitInfoKHR">Specification</a>	
				 * 
				 * @todo Implement.
				 */
				struct D3D12Fence : Vault_00::VKStruct_Base<VkD3D12FenceSubmitInfoKHR>
				{

				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32KeyedMutexAcquireReleaseInfoKHR">Specification</a> 
				 * 
				 * @todo Implement.
				 */
				struct Win32KeyedMutexAcquireRelease : Vault_00::VKStruct_Base<VkWin32KeyedMutexAcquireReleaseInfoKHR>
				{

				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkProtectedSubmitInfo">Specification</a> 
				 * 
				 * @todo Implement.
				 */
				struct Protected : Vault_00::VKStruct_Base<VkProtectedSubmitInfo>
				{

				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupSubmitInfo">Specification</a>
				 * 
				 * @todo Implement.
				 */
				struct DeviceGroup : Vault_00::VKStruct_Base<VkDeviceGroupSubmitInfo>
				{

				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceQuerySubmitInfoKHR">Specification</a> 
				 * 
				 * @todo Implement.
				 */
				struct PerformanceQuery : Vault_00::VKStruct_Base<VkPerformanceQuerySubmitInfoKHR>
				{

				};
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupCommandBufferBeginInfo">Specification</a> 
			 * 
			 * @todo Implement.
			 */
			struct DeviceGroupBeginInfo : Vault_00::VKStruct_Base<VkDeviceGroupCommandBufferBeginInfo>
			{

			};



			/**
			 * .
			 * 
			 * \param _deviceHandle
			 * \param _allocateInfo
			 * \param _commandBuffers
			 * \return 
			 */
			static EResult Allocate
			(
				      LogicalDevice::Handle _deviceHandle  ,
				const AllocateInfo&         _allocateInfo  ,
				      Handle*               _commandBuffers
			)
			{
				return EResult(vkAllocateCommandBuffers(_deviceHandle, _allocateInfo.operator const VkCommandBufferAllocateInfo*(), _commandBuffers));
			}

			/**
			 * @brief.
			 * 
			 * \param _primaryCommandBuffer
			 * \param _secondaryBufferCount
			 * \param _secondaryBuffers
			 */
			static void Execute
			(
				Handle        _primaryCommandBuffer,
				uint32        _secondaryBufferCount,
				const Handle* _secondaryBuffers
			)
			{
				vkCmdExecuteCommands(_primaryCommandBuffer, _secondaryBufferCount, _secondaryBuffers);
			}

			/**
			 * .
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _bufferCount
			 * \param _commandBuffers
			 */
			static void Free
			(
				      LogicalDevice::Handle _deviceHandle  ,
				      CommandPool::Handle   _commandPool   ,
				      uint32                _bufferCount   ,
				const Handle*               _commandBuffers
			)
			{
				vkFreeCommandBuffers(_deviceHandle, _commandPool, _bufferCount, _commandBuffers);
			}

			/**
			 * .
			 * 
			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult BeginRecord(Handle _commandBuffer, BeginInfo _flags)
			{
				vkBeginCommandBuffer(_commandBuffer, _flags);
			}

			/**
			 * .
			 * 
			 * \param _commandBuffer
			 * \return 
			 */
			static EResult EndRecord(Handle _commandBuffer)
			{
				vkEndCommandBuffer(_commandBuffer);
			}

			/**
			 * .
			 * 
			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult Reset(Handle _commandBuffer, ResetFlags _flags)
			{
				vkResetCommandBuffer(_commandBuffer, _flags);
			}

			/**
			 * @brief.
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
				const SubmitInfo*            _submissions,
				VkFence                      _fence
			)
			{
				vkQueueSubmit(_queue, _submitCount, _submissions->operator const VkSubmitInfo*(), _fence);
			}

			/**
			 * @todo Implement.
			 * 
			 */
			static void SetDeviceMask()
			{

			}
		};
	}
}
