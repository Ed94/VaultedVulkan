/**
@file VT_Command.hpp

@brief Vaulted Thermals: Command Buffers

@details

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
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
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
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
	namespace Vault_1
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers-pools">Specification</a> 
		 */
		struct CommandPool
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPool">Specification</a>  */
			using Handle = VkCommandPool;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateFlags">Specification</a>  */
			using CreateFlgas = Bitmask<ECommandPoolCreateFlag, VkCommandPoolCreateFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolResetFlags">Specification</a>  */
			using ResetFlags  = Bitmask<ECommandPoolResetFlags, VkCommandPoolResetFlags >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolTrimFlags">Specification</a>  */
			using TrimFlags   = Bitmask<EUndefined            , VkCommandPoolTrimFlags  >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_0::VKStruct_Base<VkCommandPoolCreateInfo, EStructureType::CommandPool_CreateInfo>
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
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _createInfo  ,
				const Memory::AllocationCallbacks* _allocator   ,
				      CommandPool::Handle&         _commandPool
			)
			{
				return EResult(vkCreateCommandPool(_deviceHandle, (const VkCommandPoolCreateInfo*)(&_createInfo), _allocator->operator const VkAllocationCallbacks*(), &_commandPool));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyCommandPool">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _deviceHandle,
				      Handle                       _commandPool ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyCommandPool(_deviceHandle, _commandPool, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetCommandPool">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkTrimCommandPool">Specification</a> 
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
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
		 */
		struct CommandBuffer
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBuffer">Specification</a>  */
			using Handle = VkCommandBuffer;

			using EBufferLevel = ECommandBufferLevel;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryControlFlags">Specification</a>  */
			using QueryControlFlags           = Bitmask<EQueryControlFlags         , VkQueryControlFlags          >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryPipelineStatisticFlags">Specification</a>  */
			using QueryPipelineStatisticFlags = Bitmask<EQueryPipelineStatisticFlag, VkQueryPipelineStatisticFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlags">Specification</a>  */
			using ResetFlags                  = Bitmask<ECommandBufferResetFlag    , VkCommandBufferResetFlags    >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferUsageFlags">Specification</a>  */
			using UsageFlags                  = Bitmask<ECommandBufferUsageFlag    , VkCommandBufferUsageFlags    >;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferAllocateInfo">Specification</a> .
			 */
			struct AllocateInfo : Vault_0::VKStruct_Base<VkCommandBufferAllocateInfo, EStructureType::CommandBuffer_AllocateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      CommandPool::Handle Pool       ;
					  EBufferLevel        Level      ;
				      uint32              BufferCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferImageCopy">Specification</a>  */
			struct BufferImageRegion : Vault_0::VKStruct_Base<VkBufferImageCopy>
			{
				DeviceSize               BufferOffset     ;
				uint32                   BufferRowLength  ;
				uint32                   BufferImageHeight;
				Image::SubresourceLayers ImageSubresource ;
				Offset3D                 ImageOffset      ;
				Extent3D                 ImageExtent      ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceInfoURL">Specification</a>
			 */
			struct InheritanceWindow : Vault_0::VKStruct_Base<VkCommandBufferInheritanceInfo, EStructureType::CommandBuffer_InheritanceInfo>
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
				struct ConditionalRenderingInfo : Vault_0::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT, EStructureType::CommandBuffer_Inheritance_ConditionalRendering_Info_EXT>
				{
					      EType SType ;
					const void* Next  ;
					      Bool  Enable;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 
				 */
				struct PassTransformInfo : Vault_0::VKStruct_Base
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
			struct BeginInfo : Vault_0::VKStruct_Base<VkCommandBufferBeginInfo, EStructureType::CommandBuffer_BeginInfo>
			{
				      EType              SType          ;
				const void*              Next           ;
				      UsageFlags         Flags          ;
				const InheritanceWindow* InheritanceInfo;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			 */
			struct SubmitInfo : Vault_0::VKStruct_Base<VkSubmitInfo, EStructureType::SubmitInfo>
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
				 */
				struct TimelineSemaphore : Vault_0::VKStruct_Base<VkTimelineSemaphoreSubmitInfo>
				{
					      EType   SType                    ;
					const void*   Next                     ;
					      uint32  WaitSemaphoreValueCount  ;
					const uInt64* WaitSemaphoreValues      ;
					      uint32  SignalSemaphoreValueCount;
					const uInt64* SignalSemaphoreValues    ;
				};	

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkD3D12FenceSubmitInfoKHR">Specification</a>	
				 */
				struct D3D12Fence : Vault_0::VKStruct_Base<VkD3D12FenceSubmitInfoKHR>
				{
					      EType   SType                     ;
					const void*   Next                      ;
					      uint32  WaitSemaphoreValuesCount  ;
					const uInt64* WaitSemaphoreValues       ;
					      uint32  SignalSemaphoreValuesCount;
					const uInt64* SignalSemaphoreValues     ;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32KeyedMutexAcquireReleaseInfoKHR">Specification</a> 
				 */
				struct Win32KeyedMutexAcquireRelease : Vault_0::VKStruct_Base<VkWin32KeyedMutexAcquireReleaseInfoKHR>
				{
					      EType           SType          ;
					const void*           Next           ;
					      uint32          AcquireCount   ;
					const Memory::Handle* AcquireSyncs   ;
					const uInt64*         AcquireKeys    ;
					const uint32*         AcquireTimeouts;
					      uint32          ReleaseCount   ;
					const Memory::Handle* ReleaseSyncs   ;
					const uInt64*         ReleaseKeys    ;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkProtectedSubmitInfo">Specification</a> 
				 */
				struct Protected : Vault_0::VKStruct_Base<VkProtectedSubmitInfo>
				{
					      EType SType          ;
					const void* Next           ;
					      Bool  ProtectedSubmit;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupSubmitInfo">Specification</a>
				 */
				struct DeviceGroup : Vault_0::VKStruct_Base<VkDeviceGroupSubmitInfo>
				{
					      EType   SType                       ;
					const void*   Next                        ;
					      uint32  WaitSemaphoreCount          ;
					const uint32* WaitSemaphoreDeviceIndices  ;
					      uint32  CommandBufferCount          ;
					const uint32* CommandBufferDeviceMasks    ;
					      uint32  SignalSemaphoreCount        ;
					const uint32* SignalSemaphoreDeviceIndices;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceQuerySubmitInfoKHR">Specification</a> 
				 */
				struct PerformanceQuery : Vault_0::VKStruct_Base<VkPerformanceQuerySubmitInfoKHR>
				{
					      EType  Type            ;
					const void*  Next            ;
					      uint32 CounterPassIndex;
				};
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupCommandBufferBeginInfo">Specification</a> 
			 */
			struct DeviceGroupBeginInfo : Vault_0::VKStruct_Base<VkDeviceGroupCommandBufferBeginInfo>
			{
				      EType  SType     ;
				const void*  Next      ;
				      uint32 DeviceMask;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateCommandBuffers">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBeginCommandBuffer">Specification</a> 
			 * 
			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult BeginRecord(Handle _commandBuffer, const BeginInfo& _flags)
			{
				return EResult(vkBeginCommandBuffer(_commandBuffer, _flags.operator const VkCommandBufferBeginInfo*()));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBeginRenderPass">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _bufferCount
			 * \param _commandBuffers
			 */
			static void BeginRenderPass
			(
				      CommandBuffer::Handle  _commandBuffer,
				const RenderPass::BeginInfo& _beginInfo    ,
				      ESubpassContents       _contents
			)
			{
				vkCmdBeginRenderPass(_commandBuffer, _beginInfo.operator const VkRenderPassBeginInfo*(), VkSubpassContents(_contents));
			}

			
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindDescriptorSets">Specification</a> 
			 */
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
					_firstSet                              , 
					_descriptorSetCount                    ,
					_descriptorSets                        , 
					_dynamicOffsetCount                    , 
					_dynamicOffsets
				);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindIndexBuffer">Specification</a> 
			 */
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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindVertexBuffers">Specification</a>.
			 */
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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindPipeline">Specification</a>
			 * 
			 * \param commandBuffer
			 * \param event
			 * \param stageMask
			 * \return 
			 */
			static void BindPipeline
			(
				CommandBuffer::Handle _commandBuffer    ,
				EPipelineBindPoint    _pipelineBindPoint,
				Pipeline::Handle      _pipeline
			)
			{
				vkCmdBindPipeline(_commandBuffer, VkPipelineBindPoint(_pipelineBindPoint), _pipeline);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBlitImage">Specification</a> .
			 * 
			 * \param commandBuffer
			 * \param event
			 * \param stageMask
			 * \return 
			 */
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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdCopyBufferToImage">Specification</a> 
			 */
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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDraw">Specification</a> 
			 */
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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDrawIndexed">Specification</a> 
			 */
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEndCommandBuffer">Specification</a> 
			 * 
			 * \param _commandBuffer
			 * \return 
			 */
			static EResult EndRecord(Handle _commandBuffer)
			{
				return EResult(vkEndCommandBuffer(_commandBuffer));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdEndRenderPass">Specification</a> .
			 */
			static void EndRenderPass(CommandBuffer::Handle _commandBuffer)
			{
				vkCmdEndRenderPass(_commandBuffer);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdExecuteCommands">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeCommandBuffers">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetCommandBuffer">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueSubmit">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdPipelineBarrier">Specification</a>
			 */
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

			/**
			 * 
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetDeviceMask">Specification</a> 
			 * 
			 */
			static void SetDeviceMask(Handle _commandBuffer, uint32 _deviceMask)
			{
				vkCmdSetDeviceMask(_commandBuffer, _deviceMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdResetEvent">Specification</a> 
			 */
			static void ResetEvent
			(
				Handle               _commandBuffer,
				Event::Handle        _event        ,
				Pipeline::StageFlags _stageMask
			)
			{
				vkCmdResetEvent(_commandBuffer, _event, _stageMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetEvent">Specification</a> 
			 */
			static void SetEvent
			(
				Handle               _commandBuffer,
				Event::Handle        _event        ,
				Pipeline::StageFlags _stageMask
			)
			{
				vkCmdSetEvent(_commandBuffer, _event, _stageMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdWaitEvents">Specification</a> 
			 */
			static EResult WaitForEvents
			(
				      Handle                  _commandBuffer           ,
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				vkCmdWaitEvents
				(
					_commandBuffer, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers->operator const VkMemoryBarrier*(), 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers->operator const VkBufferMemoryBarrier*(),
					_imageMemoryBarrierCount,
					_imageMemoryBarriers->operator const VkImageMemoryBarrier*()
				);
			}
		};
	}

	namespace Vault_2
	{
		struct CommandPool : public Vault_1::CommandPool
		{

		};

		struct CommandBuffer : public Vault_1::CommandBuffer
		{
			using Parent = Vault_1::CommandBuffer;

			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo() 
				{ 
					SType       = STypeEnum                   ; 
					Next        = nullptr                     ;
					Pool        = 0                           ;
					Level       = ECommandBufferLevel::Primary;
					BufferCount = 0                           ;
				}
			};

			struct BeginInfo : public Parent::BeginInfo
			{
				BeginInfo() 
				{
					SType           = STypeEnum; 
					Next            = nullptr  ;
					Flags           = 0        ;
					InheritanceInfo = nullptr  ;
				}
			};

			struct SubmitInfo : public Parent::SubmitInfo
			{
				SubmitInfo() 
				{
					SType                = STypeEnum;  
					Next                 = nullptr  ;
					WaitSemaphoreCount   = NULL     ;
					WaitSemaphores       = nullptr  ;
					WaitDstStageMask     = nullptr  ;
					CommandBufferCount   = NULL     ;
					CommandBuffers       = nullptr  ;
					SignalSemaphoreCount = NULL     ;
					SignalSemaphores     = nullptr  ;
				}
			};

			#pragma region SingleTimeCommands

			/**
			 * @brief.
			 */
			static Handle BeginSingleTimeCommands(LogicalDevice::Handle _device, CommandPool::Handle _commandPool)
			{
				AllocateInfo allocationInfo{};

				allocationInfo.Level       = ECommandBufferLevel::Primary;
				allocationInfo.Pool        = _commandPool                ;
				allocationInfo.BufferCount = 1                           ;

				Handle commandBuffer;

				Allocate(_device, allocationInfo, &commandBuffer);

				BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				BeginRecord(commandBuffer, beginInfo);

				return commandBuffer;
			}

			/**
			 * @brief.
			 */
			static void EndSingleTimeCommands
			(
				CommandBuffer       ::Handle _commandBuffer, 
				CommandPool         ::Handle _commandPool  , 
				LogicalDevice       ::Handle _device       , 
				LogicalDevice::Queue::Handle _queue
			)
			{
				EndRecord(_commandBuffer);

				SubmitInfo submitInfo{};

				submitInfo.CommandBufferCount = 1              ;
				submitInfo.CommandBuffers     = &_commandBuffer;

				SubmitToQueue(_queue, 1, &submitInfo, Null<Fence::Handle>);

				LogicalDevice::Queue::WaitUntilIdle(_queue);

				Free(_device, _commandPool, 1, &_commandBuffer);
			}

		#pragma endregion SingleTimeCommands

			/** @brief  */
			static void CopyBuffer
			(
				Buffer::Handle               _sourceBuffer     , 
				Buffer::Handle               _destinationBuffer, 
				Buffer::CopyInfo             _regionInfo       ,
				LogicalDevice::Handle        _device           ,
				CommandPool::Handle          _pool             ,
				LogicalDevice::Queue::Handle _queue
			)
			{
				Handle commandBuffer = BeginSingleTimeCommands(_device, _pool);

				Parent::CopyBuffer(commandBuffer, _sourceBuffer, _destinationBuffer, 1, &_regionInfo);

				EndSingleTimeCommands(commandBuffer, _pool, _device, _queue);
			}
		};
	};
}
