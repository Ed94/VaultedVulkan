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
#include "VT_Memory.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
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
			struct CreateInfo : Vault_00::VKStruct_Base<VkCommandPoolCreateInfo, EStructureType::CommandPool_CreateInfo>
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
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _createInfo  ,
				const AllocationCallbacks*  _allocator   ,
				      CommandPool::Handle&  _commandPool
			)
			{
				return EResult(vkCreateCommandPool(_deviceHandle, (const VkCommandPoolCreateInfo*)(&_createInfo), _allocator, &_commandPool));
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
			static EResult Reset
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _commandPool ,
				ResetFlags            _flags
			)
			{
				return EResult(vkResetCommandPool(_deviceHandle, _commandPool, _flags));
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
			struct AllocateInfo : Vault_00::VKStruct_Base<VkCommandBufferAllocateInfo, EStructureType::CommandBuffer_AllocateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      CommandPool::Handle Pool       ;
					  EBufferLevel        Level      ;
				      uint32              BufferCount;
			};

			struct BufferImageRegion : Vault_00::VKStruct_Base<VkBufferImageCopy>
			{
				DeviceSize               bufferOffset;
				uint32                   bufferRowLength;
				uint32                   bufferImageHeight;
				Image::SubresourceLayers imageSubresource;
				Offset3D                 imageOffset;
				Extent3D                 imageExtent;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceInfoURL">Specification</a>
			 */
			struct InheritanceWindow : Vault_00::VKStruct_Base<VkCommandBufferInheritanceInfo, EStructureType::CommandBuffer_InheritanceInfo>
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
				struct ConditionalRenderingInfo : Vault_00::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT, EStructureType::CommandBuffer_Inheritance_ConditionalRendering_Info_EXT>
				{
					      EType SType ;
					const void* Next  ;
					      Bool  Enable;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 
				 */
				struct PassTransformInfo : Vault_00::VKStruct_Base
					<VkCommandBufferInheritanceRenderPassTransformInfoQCOM, EStructureType::CommandBufferInheritance_RenderPassTransform_Info_QCOM>
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
			struct BeginInfo : Vault_00::VKStruct_Base<VkCommandBufferBeginInfo, EStructureType::CommandBuffer_BeginInfo>
			{
				      EType              SType          ;
				const void*              Next           ;
				      UsageFlags         Flags          ;
				const InheritanceWindow* InheritanceInfo;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			 */
			struct SubmitInfo : Vault_00::VKStruct_Base<VkSubmitInfo, EStructureType::SubmitInfo>
			{
				      EType                 SType               ;
				const void*                 Next                ;
				      uint32                WaitSemaphoreCount  ;
				const Semaphore::Handle*    WaitSemaphores      ;   
				const Pipeline::StageFlags* WaitDstStageMask    ;
				      uint32                CommandBufferCount  ;
				const Handle*               CommandBuffers      ;
				      uint32                SignalSemaphoreCount;
				const Semaphore::Handle*    SignalSemaphores    ;   


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
				return EResult(vkAllocateCommandBuffers(_deviceHandle, (const VkCommandBufferAllocateInfo*)(&_allocateInfo), _commandBuffers));
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
			static EResult BeginRecord(Handle _commandBuffer, const BeginInfo& _flags)
			{
				return EResult(vkBeginCommandBuffer(_commandBuffer, _flags.operator const VkCommandBufferBeginInfo*()));
			}

			static void BeginRenderPass
			(
				      CommandBuffer::Handle  _commandBuffer,
				const RenderPass::BeginInfo& _beginInfo    ,
				      ESubpassContents       _contents
			)
			{
				vkCmdBeginRenderPass(_commandBuffer, _beginInfo.operator const VkRenderPassBeginInfo*(), VkSubpassContents(_contents));
			}

			static void BindDescriptorSets
			(
				      CommandBuffer::Handle    _commandBuffer     ,
				      EPipelineBindPoint       _pipelineBindPoint ,
				      Pipeline::Layout::Handle _layout            ,
				      uint32                   _firstSet          ,
				      uint32                   _descriptorSetCount,
				const DescriptorSet::Handle*   _descriptorSets    ,
				      uint32                   _dynamicOffsetCount,
				const uint32*                  _dynamicOffsets
			)
			{
				vkCmdBindDescriptorSets
				(
					_commandBuffer                         , 
					VkPipelineBindPoint(_pipelineBindPoint), 
					_layout                                , 
					_firstSet                    , 
					_descriptorSetCount                              ,
					_descriptorSets                        , 
					_dynamicOffsetCount                    , 
					_dynamicOffsets
				);
			}

			static void BindIndexBuffer
			(
				CommandBuffer::Handle _commandBuffer,
				Buffer::Handle        _buffer       ,
				DeviceSize            _offset       ,
				EIndexType            _indexType
			)
			{
				vkCmdBindIndexBuffer(_commandBuffer, _buffer, _offset, VkIndexType(_indexType));
			}

			static void BindVertexBuffers
			(
				      Handle          _commandBuffer,
				      uint32          _firstBinding ,
				      uint32          _bindingCount ,
				const Buffer::Handle& _buffers      ,
				const DeviceSize&     _offsets
			)
			{
				vkCmdBindVertexBuffers(_commandBuffer, _firstBinding, _bindingCount, &_buffers, &_offsets);
			}

			static void BindPipeline
			(
				CommandBuffer::Handle _commandBuffer    ,
				EPipelineBindPoint    _pipelineBindPoint,
				Pipeline::Handle      _pipeline
			)
			{
				vkCmdBindPipeline(_commandBuffer, VkPipelineBindPoint(_pipelineBindPoint), _pipeline);
			}

			static void BlitImage
			(
				      CommandBuffer::Handle _commandBuffer,
				      Image::Handle         _srcImage,
				      EImageLayout          _srcImageLayout,
				      Image::Handle         _dstImage,
				      EImageLayout          _dstImageLayout,
				      uint32                _regionCount,
				const Image::Blit*          _regions,
				      EFilter               _filter
			)
			{
				vkCmdBlitImage
				(
					_commandBuffer, 
					_srcImage, 
					VkImageLayout(_srcImageLayout), 
					_dstImage, 
					VkImageLayout(_dstImageLayout), 
					_regionCount, 
					_regions->operator const VkImageBlit*(), 
					VkFilter(_filter)
				);
			}

			static void Draw
			(
				CommandBuffer::Handle _commandBuffer,
				uint32                _firstVertex  ,
				uint32                _vertexCount  , 
				uint32                _firstInstance,
				uint32                _instanceCount
			)
			{
				vkCmdDraw(_commandBuffer, _vertexCount, _instanceCount, _firstVertex, _firstInstance);
			}

			static void DrawIndexed
			(
				CommandBuffer::Handle _commandBuffer,
				uint32                _indexCount   ,
				uint32                _instanceCount,
				uint32                _firstIndex   ,
				sint32                _vertexOffset ,
				uint32                _firstInstance
			)
			{
				vkCmdDrawIndexed(_commandBuffer, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			/**
			 * .
			 * 
			 * \param _commandBuffer
			 * \return 
			 */
			static EResult EndRecord(Handle _commandBuffer)
			{
				return EResult(vkEndCommandBuffer(_commandBuffer));
			}

			static void EndRenderPass(CommandBuffer::Handle _commandBuffer)
			{
				vkCmdEndRenderPass(_commandBuffer);
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
				return EResult(vkResetCommandBuffer(_commandBuffer, _flags));
			}

			/**
			 * @brief.
			 *
			 * @todo Should this be in LogicalDevice::Queue?
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
				      Fence::Handle                _fence
			)
			{
				return EResult(vkQueueSubmit(_queue, _submitCount, _submissions->operator const VkSubmitInfo*(), _fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdCopyBuffer">Specification</a>
			 * 
			 * \return 
			 */
			static void CopyBuffer
			(
				      CommandBuffer::Handle _commandBuffer    ,
				      Buffer::Handle        _sourceBuffer     ,
				      Buffer::Handle        _destinationBuffer,
				      uint32                _regionCount      ,
				const Buffer::CopyInfo*     _regions
			)
			{
				vkCmdCopyBuffer(_commandBuffer, _sourceBuffer, _destinationBuffer, _regionCount, _regions->operator const VkBufferCopy*());
			}

			static void CopyBufferToImage
			(
				      Handle             _commandBuffer ,
				      Buffer::Handle     _srcBuffer     ,
				      Image::Handle      _dstImage      ,
				      EImageLayout       _dstImageLayout,
				      uint32			 _regionCount   ,
				const BufferImageRegion* _regions
			)
			{
				vkCmdCopyBufferToImage(_commandBuffer, _srcBuffer, _dstImage, VkImageLayout(_dstImageLayout), _regionCount, _regions->operator const VkBufferImageCopy*());
			}

			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				vkCmdPipelineBarrier
				(
					_commandBuffer, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers->operator const VkMemoryBarrier*(), 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers->operator const VkBufferMemoryBarrier*(), 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers->operator const VkImageMemoryBarrier*()
				);
			}

			///**
			// * @todo Implement.
			// * 
			// */
			//static void SetDeviceMask()
			//{

			//}

			//static EResult ResetEvent
			//(
			//	VkCommandBuffer                             commandBuffer,
			//	VkEvent                                     event,
			//	VkPipelineStageFlags                        stageMask
			//)
			//{

			//}

			//static EResult SetEvent
			//(
			//	VkCommandBuffer                             commandBuffer,
			//	VkEvent                                     event,
			//	VkPipelineStageFlags                        stageMask
			//)
			//{

			//}

			//static EResult WaitForEvents
			//(
			//	VkCommandBuffer                             commandBuffer,
			//	uint32_t                                    eventCount,
			//	const VkEvent*                              pEvents,
			//	VkPipelineStageFlags                        srcStageMask,
			//	VkPipelineStageFlags                        dstStageMask,
			//	uint32_t                                    memoryBarrierCount,
			//	const VkMemoryBarrier*                      pMemoryBarriers,
			//	uint32_t                                    bufferMemoryBarrierCount,
			//	const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
			//	uint32_t                                    imageMemoryBarrierCount,
			//	const VkImageMemoryBarrier*                 pImageMemoryBarriers
			//)
			//{

			//}
		};
	}
}
