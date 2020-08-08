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
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"



VT_Namespace
{
	namespace V1
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
			struct CreateInfo : V0::VKStruct_Base<VkCommandPoolCreateInfo, EStructureType::CommandPool_CreateInfo>
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
				      Handle&                      _commandPool
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
			struct AllocateInfo : V0::VKStruct_Base<VkCommandBufferAllocateInfo, EStructureType::CommandBuffer_AllocateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      CommandPool::Handle Pool       ;
					  EBufferLevel        Level      ;
				      uint32              BufferCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferImageCopy">Specification</a>  */
			struct BufferImageRegion : V0::VKStruct_Base<VkBufferImageCopy>
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
			struct InheritanceWindow : V0::VKStruct_Base<VkCommandBufferInheritanceInfo, EStructureType::CommandBuffer_InheritanceInfo>
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
				struct ConditionalRenderingInfo : V0::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT, EStructureType::CommandBuffer_Inheritance_ConditionalRendering_Info_EXT>
				{
					      EType SType ;
					const void* Next  ;
					      Bool  Enable;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 
				 */
				struct PassTransformInfo : V0::VKStruct_Base
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
			struct BeginInfo : V0::VKStruct_Base<VkCommandBufferBeginInfo, EStructureType::CommandBuffer_BeginInfo>
			{
				      EType              SType          ;
				const void*              Next           ;
				      UsageFlags         Flags          ;
				const InheritanceWindow* InheritanceInfo;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			 */
			struct SubmitInfo : V0::VKStruct_Base<VkSubmitInfo, EStructureType::SubmitInfo>
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
				struct TimelineSemaphore : V0::VKStruct_Base<VkTimelineSemaphoreSubmitInfo>
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
				struct D3D12Fence : V0::VKStruct_Base<VkD3D12FenceSubmitInfoKHR>
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
				struct Win32KeyedMutexAcquireRelease : V0::VKStruct_Base<VkWin32KeyedMutexAcquireReleaseInfoKHR>
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
				struct Protected : V0::VKStruct_Base<VkProtectedSubmitInfo>
				{
					      EType SType          ;
					const void* Next           ;
					      Bool  ProtectedSubmit;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupSubmitInfo">Specification</a>
				 */
				struct DeviceGroup : V0::VKStruct_Base<VkDeviceGroupSubmitInfo>
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
				struct PerformanceQuery : V0::VKStruct_Base<VkPerformanceQuerySubmitInfoKHR>
				{
					      EType  Type            ;
					const void*  Next            ;
					      uint32 CounterPassIndex;
				};
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupCommandBufferBeginInfo">Specification</a> 
			 */
			struct DeviceGroupBeginInfo : V0::VKStruct_Base<VkDeviceGroupCommandBufferBeginInfo>
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
				return EResult(vkAllocateCommandBuffers(_deviceHandle, _allocateInfo.operator const VkCommandBufferAllocateInfo*(), _commandBuffers));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBeginCommandBuffer">Specification</a> 
			 * 
			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult BeginRecord(Handle _commandBuffer, const BeginInfo& _info)
			{
				return EResult(vkBeginCommandBuffer(_commandBuffer, _info.operator const VkCommandBufferBeginInfo*()));
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
				const Buffer::Handle* _buffers      ,
				const DeviceSize*     _offsets
			)
			{
				vkCmdBindVertexBuffers(_commandBuffer, _firstBinding, _bindingCount, _buffers, _offsets);
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

	namespace V2
	{
		struct CommandPool : public V1::CommandPool
		{
			using Parent = V1::CommandPool;

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _createInfo  ,
				      Handle&                      _commandPool
			)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _commandPool);
			}

			using Parent::Create;

			static void Destroy
			(
				      LogicalDevice::Handle        _deviceHandle,
				      Handle                       _commandPool 
			)
			{
				Parent::Destroy(_deviceHandle, _commandPool, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		struct CommandBuffer : public V1::CommandBuffer
		{
			using Parent = V1::CommandBuffer;

			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct InheritanceWindow : public Parent::InheritanceWindow
			{
				using Parent = Parent::InheritanceWindow;

				InheritanceWindow()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct ConditionalRenderingInfo : public Parent::ConditionalRenderingInfo
				{
					ConditionalRenderingInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct PassTransformInfo : public Parent::PassTransformInfo
				{
					PassTransformInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct BeginInfo : public Parent::BeginInfo
			{
				BeginInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct SubmitInfo : public Parent::SubmitInfo
			{
				using Parent = Parent::SubmitInfo;

				SubmitInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct TimelineSemaphore : public Parent
				{
					TimelineSemaphore()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct D3D12Fence : public Parent
				{
					D3D12Fence()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
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

				LogicalDevice::Queue::SubmitToQueue(_queue, 1, submitInfo, Null<Fence::Handle>);

				LogicalDevice::Queue::WaitUntilIdle(_queue);

				Parent::Free(_device, _commandPool, 1, &_commandBuffer);
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

			static void Free
			(
				      LogicalDevice::Handle _device        ,
				const AllocateInfo&         _info          ,
				const Handle*               _commandBuffers
			)
			{
				Parent::Free(_device, _info.Pool, _info.BufferCount, _commandBuffers);	
			}
		};
	}

	namespace V4
	{
		class CommandPool : public V2::CommandPool
		{
		public:
			using Parent = V2::CommandPool;

			EResult Create(LogicalDevice& _device, CreateInfo& _info)
			{
				device    = &_device;
				info      = _info   ;
				allocator = nullptr ;

				return Parent::Create(device->GetHandle(), info, allocator, handle);	
			}

			EResult Create(LogicalDevice& _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = &_device;
				info      = _info   ;
				allocator = nullptr ;

				return Parent::Create(device->GetHandle(), info, allocator, handle);	
			}

			void Destroy()
			{
				Parent::Destroy(device->GetHandle(), handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult Reset(ResetFlags _flags)
			{
				Parent::Reset(device->GetHandle(), handle, _flags);
			}

			EResult Trim(TrimFlags _flags)
			{
				Parent::Trim(device->GetHandle(), handle, _flags);
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice* device;
		};

		class CommandBuffer : public V2::CommandBuffer
		{
		public:

			using Parent = V2::CommandBuffer;

			const DataSize& GetIndex() const
			{
				return index;
			}

			Handle* GetHandles() const
			{
				return (Handle*)(handle - index);
			}

			const AllocateInfo& GetAllocateInfo() const
			{
				return info;
			}

			const Handle& GetHandle() const
			{
				return *handle;
			}

			void Assign(LogicalDevice& _device, AllocateInfo& _info, Handle& _handle, DeviceSize _index)
			{
				device = &_device ;
				info   = _info    ;
				handle = &_handle ;
				index  = _index   ;
			}

			static EResult Allocate
			(
				LogicalDevice& _device, 
				AllocateInfo& _info, 
				std::vector<CommandBuffer>& _commandBuffers,
				std::vector<Handle>& _handles
			)
			{
				_commandBuffers.resize(_info.BufferCount); _handles.resize(_info.BufferCount);

				EResult returnCode = Parent::Allocate(_device.GetHandle(), _info, _handles.data());

				if (returnCode != EResult::Success) return returnCode;

				for (DeviceSize index = 0; index < _info.BufferCount; index++)
				{
					_commandBuffers[index].Assign(_device, _info, _handles[index], index);
				}

				return returnCode;
			}

			EResult BeginRecord(const BeginInfo& _info)
			{
				return Parent::BeginRecord(*handle, _info);
			}

			void BeginRenderPass(const RenderPass::BeginInfo& _info, ESubpassContents _contents)
			{
				Parent::BeginRenderPass(*handle, _info, _contents);
			}

			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint          ,
				      Pipeline::Layout&      _layout            ,
				      uint32                 _firstSet          ,
				      uint32                 _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets
			)
			{
				Parent::BindDescriptorSets(*handle, _bindPoint, _layout.GetHandle(), _firstSet, _descritporSetCount, _descriptorSets, 0, nullptr);
			}

			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint         ,
				      Pipeline::Layout&      _layout            ,
				      uint32                 _firstSet          ,
				      uint32                 _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets    ,
				      uint32                 _dynamicOffsetCount,
				const uint32*                _dynamicOffsets
			)
			{
				Parent::BindDescriptorSets(*handle, _bindPoint, _layout.GetHandle(), _firstSet, _descritporSetCount, _descriptorSets, _dynamicOffsetCount, _dynamicOffsets);
			}

			void BindIndexBuffer(Buffer& _buffer, DeviceSize _offset, EIndexType _type)
			{
				Parent::BindIndexBuffer(*handle, _buffer.GetHandle(), _offset, _type);
			}

			void BindVertexBuffers(uint32 _firstBinding, uint32 _bindingCount, const Buffer::Handle* _buffers)
			{
				Parent::BindVertexBuffers(*handle, _firstBinding, _bindingCount, _buffers, 0);
			}

			void BindVertexBuffers(uint32 _firstBinding, uint32 _bindingCount, const Buffer::Handle* _buffers, const DeviceSize* _offsets)
			{
				Parent::BindVertexBuffers(*handle, _firstBinding, _bindingCount, _buffers, _offsets);
			}

			void BindPipeline(EPipelineBindPoint _bindPoint, Pipeline& _pipeline)
			{
				Parent::BindPipeline(*handle, _bindPoint, _pipeline.GetHandle());
			}

			void BlitImage(Image& _src, EImageLayout _srcLayout, Image& _dst, EImageLayout _dstLayout, uint32 _regionCount, const Image::Blit* _regions, EFilter _filter)
			{
				Parent::BlitImage(*handle, _src.GetHandle(), _srcLayout, _dst.GetHandle(), _dstLayout, _regionCount, _regions, _filter);
			}

			void CopyBuffer
			(
				Buffer& _sourceBuffer,
				Buffer& _destinationBuffer,
				uint32                _regionCount,
				const Buffer::CopyInfo* _regions
			)
			{
				Parent::Parent::CopyBuffer(*handle, _sourceBuffer.GetHandle(), _destinationBuffer.GetHandle(), _regionCount, _regions);
			}

			static void CopyBuffer
			(
				Buffer               _sourceBuffer     , 
				Buffer _destinationBuffer, 
				Buffer::CopyInfo& _regionInfo       ,
				LogicalDevice& _device           ,
				CommandPool& _pool             ,
				LogicalDevice::Queue& _queue
			)
			{
				CommandBuffer commandBuffer; commandBuffer.BeginSingleTimeCommands(_device, _pool);

				commandBuffer.CopyBuffer(_sourceBuffer, _destinationBuffer, 1, &_regionInfo);

				commandBuffer.EndSingleTimeCommands(_queue);
			}

			void CopyBufferToImage
			(
				Buffer       _srcBuffer     ,
				Image        _dstImage      ,
				EImageLayout _dstImageLayout,
				uint32		 _regionCount   ,
				const BufferImageRegion* _regions
			)
			{
				Parent::CopyBufferToImage(*handle, _srcBuffer.GetHandle(), _dstImage.GetHandle(), _dstImageLayout, _regionCount, _regions);
			}

			void Draw
			(
				uint32 _firstVertex  ,
				uint32 _vertexCount  , 
				uint32 _firstInstance,
				uint32 _instanceCount
			)
			{
				Parent::Draw(*handle, _firstVertex, _vertexCount, _firstInstance, _instanceCount);
			}

			void DrawIndexed
			(
				uint32 _indexCount   ,
				uint32 _instanceCount,
				uint32 _firstIndex   ,
				sint32 _vertexOffset ,
				uint32 _firstInstance
			)
			{
				Parent::DrawIndexed(*handle, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			EResult EndRecord()
			{
				return Parent::EndRecord(*handle);
			}

			void EndRenderPass()
			{
				Parent::EndRenderPass(*handle);
			}

			void Execute
			(
				      uint32   _secondaryBufferCount,
				const Handle* _secondaryBuffers
			)
			{
				Parent::Execute(*handle, _secondaryBufferCount, _secondaryBuffers);
			}

			void Free()
			{
				Parent::Free(device->GetHandle(), info, handle - index);	
			}

			void ResetEvent(Event& _event, Pipeline::StageFlags _stageMask)
			{
				Parent::ResetEvent(*handle, _event.GetHandle(), _stageMask);
			}

		#pragma region SubmitPipelineBarrier_OO

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			)
			{
				Parent::SubmitPipelineBarrier
				(
					*handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers,
					0,
					nullptr,
					0,
					nullptr
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			)
			{
				Parent::SubmitPipelineBarrier
				(
					*handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					0, 
					nullptr, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers, 
					0,
					nullptr
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				Parent::SubmitPipelineBarrier
				(
					*handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					0, 
					nullptr, 
					0, 
					nullptr, 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			void SubmitPipelineBarrier
			(
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
				Parent::SubmitPipelineBarrier
				(
					*handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers, 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

		#pragma endregion SubmitPipelineBarrier_OO

			void SetDeviceMask(uint32 _deviceMask)
			{
				Parent::SetDeviceMask(*handle, _deviceMask);
			}

			void SetEvent(Event& _event, Pipeline::StageFlags _stageMask)
			{
				Parent::SetEvent(*handle, _event.GetHandle(), _stageMask);
			}

		#pragma region WaitForEvents_OO

			EResult WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			)
			{
				Parent::WaitForEvents
				(
					*handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers, 
					0, 
					nullptr,
					0,
					nullptr
				);
			}

			EResult WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			)
			{
				Parent::WaitForEvents
				(
					*handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					0, 
					nullptr, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers,
					0,
					nullptr
				);
			}

			EResult WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					*handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					0, 
					nullptr, 
					0, 
					nullptr,
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			EResult WaitForEvents
			(
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
				Parent::WaitForEvents
				(
					*handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers,
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

		#pragma endregion WaitForEvents_OO

		#pragma region SingleTimeCommands

			/**
			 * @brief.
			 */
			void BeginSingleTimeCommands(LogicalDevice& _device, CommandPool& _commandPool)
			{
				device = &_device;

				AllocateInfo allocationInfo{};

				allocationInfo.Level       = ECommandBufferLevel::Primary;
				allocationInfo.Pool        = _commandPool.GetHandle()    ;
				allocationInfo.BufferCount = 1                           ;

				Parent::Allocate(device->GetHandle(), allocationInfo, handle);

				index = 0;

				BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				BeginRecord(beginInfo);
			}

			/**
			 * @brief.
			 */
			void EndSingleTimeCommands(LogicalDevice::Queue& _queue)
			{
				EndRecord();

				SubmitInfo submitInfo{};

				submitInfo.CommandBufferCount = 1      ;
				submitInfo.CommandBuffers     = handle ;

				_queue.SubmitToQueue(1, submitInfo, Null<Fence::Handle>);

				_queue.WaitUntilIdle();

				Parent::Free(device->GetHandle(), info, handle - index);
			}

		#pragma endregion SingleTimeCommands

		protected:

			Handle* handle;

			DeviceSize index;

			AllocateInfo info;

			LogicalDevice* device;
		};
	}
}
