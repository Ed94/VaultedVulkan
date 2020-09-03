/*!
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
#include "VT_SyncAndCacheControl.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"
#include "VT_RenderPass.hpp"



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
		 @brief Command buffers are objects used to record commands which can be subsequently submitted to a device queue for execution.
		 
		 @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 

		 @ingroup APISpec_Command_Buffers
		 */
		struct CommandBuffer
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBuffer">Specification</a> @ingroup APISpec_Command_Buffers */
			using Handle = VkCommandBuffer;

			using EBufferLevel = ECommandBufferLevel;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryControlFlags">Specification</a> @ingroup APISpec_Queries */
			using QueryControlFlags           = Bitmask<EQueryControlFlags         , VkQueryControlFlags          >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryPipelineStatisticFlags">Specification</a> @ingroup APISpec_Queries */
			using QueryPipelineStatisticFlags = Bitmask<EQueryPipelineStatisticFlag, VkQueryPipelineStatisticFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using ResetFlags                  = Bitmask<ECommandBufferResetFlag    , VkCommandBufferResetFlags    >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferUsageFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using UsageFlags                  = Bitmask<ECommandBufferUsageFlag    , VkCommandBufferUsageFlags    >;


			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferImageCopy">Specification</a> 
			@ingroup APISpec_Copy_Commands 
			
			@todo #TODO: Make == and != operators
			*/
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
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceInfo">Specification</a> 
			@ingroup APISpec_Command_Buffers

			@todo #TODO: Make == and != operators
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
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceConditionalRenderingInfoEXT">Specification</a>
				
				@ingroup APISpec_Command_Buffers
				*/
				struct ConditionalRenderingInfo : V0::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT, EStructureType::CommandBuffer_Inheritance_ConditionalRendering_Info_EXT>
				{
					      EType SType ;
					const void* Next  ;
					      Bool  Enable;

					bool operator== (const ConditionalRenderingInfo& _other)
					{
						return
						Next   == _other.Next   &&
						Enable == _other.Enable
						? true : false;
					}

					bool operator!= (const ConditionalRenderingInfo& _other)
					{
						return
						Next   != _other.Next   &&
						Enable != _other.Enable
						? true : false;
					}
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 

				@ingroup APISpec_Command_Buffers

				@todo #TODO: Make == and != operators
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
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferBeginInfo">Specification</a>

			@ingroup APISpec_Command_Buffers

			@todo #TODO: Make == and != operators
			*/
			struct BeginInfo : V0::VKStruct_Base<VkCommandBufferBeginInfo, EStructureType::CommandBuffer_BeginInfo>
			{
				      EType              SType          ;
				const void*              Next           ;
				      UsageFlags         Flags          ;
				const InheritanceWindow* InheritanceInfo;
			};

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			
			@ingroup APISpec_Command_Buffers

			@todo #TODO: Make == and != operators
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
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkTimelineSemaphoreSubmitInfo">Specification</a>

				@ingroup APISpec_Command_Buffers

				@todo #TODO: Make == and != operators
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
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkD3D12FenceSubmitInfoKHR">Specification</a>	

				@ingroup APISpec_Command_Buffers

				@todo #TODO: Make == and != operators
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
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32KeyedMutexAcquireReleaseInfoKHR">Specification</a> 

				@ingroup APISpec_Command_Buffers

				@todo #TODO: Make == and != operators
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
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkProtectedSubmitInfo">Specification</a> 

				@ingoup APISpec_Command_Buffers
				*/
				struct Protected : V0::VKStruct_Base<VkProtectedSubmitInfo>
				{
					      EType SType          ;
					const void* Next           ;
					      Bool  ProtectedSubmit;

					bool operator== (const Protected& _other) { return Next == _other.Next && ProtectedSubmit == _other.ProtectedSubmit ? true : false; }
					bool operator!= (const Protected& _other) { return Next != _other.Next && ProtectedSubmit != _other.ProtectedSubmit ? true : false; }
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupSubmitInfo">Specification</a>

				@ingroup APISpec_Command_Buffers

				@todo #TODO: Make == and != operators
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
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceQuerySubmitInfoKHR">Specification</a>

				@ingroup APISpec_Command_Buffers

				@todo #TODO: Make == and != operators
				*/
				struct PerformanceQuery : V0::VKStruct_Base<VkPerformanceQuerySubmitInfoKHR>
				{
					      EType  Type            ;
					const void*  Next            ;
					      uint32 CounterPassIndex;
				};
			};

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupCommandBufferBeginInfo">Specification</a> 
			
			@ingroup APISpec_Command_Buffers

			@todo #TODO: Make == and != operators
			*/
			struct DeviceGroupBeginInfo : V0::VKStruct_Base<VkDeviceGroupCommandBufferBeginInfo>
			{
				      EType  SType     ;
				const void*  Next      ;
				      uint32 DeviceMask;
			};


			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBeginCommandBuffer">Specification</a> 
			
			@ingroup APISpec_Command_Buffers

			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult BeginRecord(const Handle _commandBuffer, const BeginInfo& _info)
			{
				return EResult(vkBeginCommandBuffer(_commandBuffer, _info.operator const VkCommandBufferBeginInfo*()));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBeginRenderPass">Specification</a>
			 * 
			 * @ingroup APISpec_Render_Pass
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _bufferCount
			 * \param _commandBuffers
			 */
			static void BeginRenderPass
			(
				const Handle                 _commandBuffer,
				const RenderPass::BeginInfo& _beginInfo    ,
				      ESubpassContents       _contents
			)
			{
				vkCmdBeginRenderPass(_commandBuffer, _beginInfo.operator const VkRenderPassBeginInfo*(), VkSubpassContents(_contents));
			}

			
			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindDescriptorSets">Specification</a> 

			@ingroup APISpec_Resource_Descriptors
			*/
			static void BindDescriptorSets
			(
				      Handle                   _commandBuffer     ,
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
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindIndexBuffer">Specification</a> 

			@ingroup APISpec_Drawing_Commands
			*/
			static void BindIndexBuffer
			(
				Handle         _commandBuffer,
				Buffer::Handle _buffer       ,
				DeviceSize     _offset       ,
				EIndexType     _indexType
			)
			{
				vkCmdBindIndexBuffer(_commandBuffer, _buffer, _offset, VkIndexType(_indexType));
			}

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindVertexBuffers">Specification</a>

			@ingroup APISpec_Fixed-Function_Vertex_Processing
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
			 * @ingroup APISpec_Pipelines
			 * 
			 * \param commandBuffer
			 * \param event
			 * \param stageMask
			 * \return 
			 */
			static void BindPipeline
			(
				Handle             _commandBuffer    ,
				EPipelineBindPoint _pipelineBindPoint,
				Pipeline::Handle   _pipeline
			)
			{
				vkCmdBindPipeline(_commandBuffer, VkPipelineBindPoint(_pipelineBindPoint), _pipeline);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBlitImage">Specification</a>
			 * 
			 * @ingroup APISpec_Copy_Commands
			 * 
			 * \param commandBuffer
			 * \param event
			 * \param stageMask
			 * \return 
			 */
			static void BlitImage
			(
				      Handle        _commandBuffer ,
				      Image::Handle _srcImage      ,
				      EImageLayout  _srcImageLayout,
				      Image::Handle _dstImage      ,
				      EImageLayout  _dstImageLayout,
				      uint32        _regionCount   ,
				const Image::Blit*  _regions       ,
				      EFilter       _filter
			)
			{
				vkCmdBlitImage
				(
					_commandBuffer                         ,
					_srcImage                              ,
					VkImageLayout(_srcImageLayout)         ,
					_dstImage                              ,
					VkImageLayout(_dstImageLayout)         ,
					_regionCount                           ,
					_regions->operator const VkImageBlit*(),
					VkFilter(_filter)
				);
			}

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdCopyBuffer">Specification</a>
			 
			@ingroup APISpec_Copy_Commands
			*/
			static void CopyBuffer
			(
				      Handle            _commandBuffer    ,
				      Buffer::Handle    _sourceBuffer     ,
				      Buffer::Handle    _destinationBuffer,
				      uint32            _regionCount      ,
				const Buffer::CopyInfo* _regions
			)
			{
				vkCmdCopyBuffer(_commandBuffer, _sourceBuffer, _destinationBuffer, _regionCount, _regions->operator const VkBufferCopy*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdCopyBufferToImage">Specification</a> 
			 * 
			 * @ingroup APISpec_Copy_Commands
			 */
			static void CopyBufferToImage
			(
				      Handle             _commandBuffer ,
				      Buffer::Handle     _srcBuffer     ,
				      Image::Handle      _dstImage      ,
				      EImageLayout       _dstImageLayout,
				      uint32             _regionCount   ,
				const BufferImageRegion* _regions
			)
			{
				vkCmdCopyBufferToImage(_commandBuffer, _srcBuffer, _dstImage, VkImageLayout(_dstImageLayout), _regionCount, _regions->operator const VkBufferImageCopy*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDraw">Specification</a> 
			 * 
			 * @ingroup APISpec_Drawing_Commands
			 */
			static void Draw
			(
				Handle _commandBuffer,
				uint32 _firstVertex  ,
				uint32 _vertexCount  ,
				uint32 _firstInstance,
				uint32 _instanceCount
			)
			{
				vkCmdDraw(_commandBuffer, _vertexCount, _instanceCount, _firstVertex, _firstInstance);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDrawIndexed">Specification</a> 
			 * 
			 * @ingroup APISpec_Drawing_Commands
			 */
			static void DrawIndexed
			(
				Handle _commandBuffer,
				uint32 _indexCount   ,
				uint32 _instanceCount,
				uint32 _firstIndex   ,
				sint32 _vertexOffset ,
				uint32 _firstInstance
			)
			{
				vkCmdDrawIndexed(_commandBuffer, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEndCommandBuffer">Specification</a> 
			 * 
			 * @ingroup https://www.alienbrain.com/
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
			 * 
			 * @ingroup APISpec_Render_Pass
			 * 
			 * @param _commandBuffer
			 * @return
			 */
			static void EndRenderPass(Handle _commandBuffer)
			{
				vkCmdEndRenderPass(_commandBuffer);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdExecuteCommands">Specification</a>
			 * 
			 * @ingroup APISpec_Command_Buffers
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetCommandBuffer">Specification</a> 
			 * 
			 * @ingroup APISpec_Command_Buffers
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
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
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
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
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
					_commandBuffer                                                ,
					_sourceStageMask                                              ,
					_destinationStageMask                                         ,
					_dependencyFlags                                              ,
					_memoryBarrierCount                                           ,
					_memoryBarriers->operator const VkMemoryBarrier*()            ,
					_bufferMemoryBarrierCount                                     ,
					_bufferMemoryBarriers->operator const VkBufferMemoryBarrier*(),
					_imageMemoryBarrierCount                                      ,
					_imageMemoryBarriers->operator const VkImageMemoryBarrier*()
				);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetDeviceMask">Specification</a> 
			 * 
			 * @ingroup APISpec_Command_Buffers
			 */
			static void SetDeviceMask(Handle _commandBuffer, uint32 _deviceMask)
			{
				vkCmdSetDeviceMask(_commandBuffer, _deviceMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetEvent">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
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
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			static void WaitForEvents
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
					_commandBuffer                                                ,
					_eventCount                                                   ,
					_events                                                       ,
					_srcStageMask                                                 ,
					_dstStageMask                                                 ,
					_memoryBarrierCount                                           , 
					_memoryBarriers->operator const VkMemoryBarrier*()            ,
					_bufferMemoryBarrierCount                                     ,
					_bufferMemoryBarriers->operator const VkBufferMemoryBarrier*(),
					_imageMemoryBarrierCount                                      ,
					_imageMemoryBarriers->operator const VkImageMemoryBarrier*()
				);
			}
		};

		/**
		@brief 
		Command pools are opaque objects that command buffer memory is allocated from, and
        which allow the implementation to amortize the cost of resource creation across
        multiple command buffers. Command pools are externally synchronized, meaning that a
        command pool must not be used concurrently in multiple threads. That includes use
        via recording commands on any command buffers allocated from the pool, as well as
        operations that allocate, free, and reset command buffers or the pool itself.
		
		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers-pools">Specification</a>
		 
		@ingroup APISpec_Command_Buffers
		*/
		struct CommandPool
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPool">Specification</a> @ingroup APISpec_Command_Buffers */
			using Handle = VkCommandPool;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using CreateFlgas = Bitmask<ECommandPoolCreateFlag, VkCommandPoolCreateFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolResetFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using ResetFlags  = Bitmask<ECommandPoolResetFlags, VkCommandPoolResetFlags >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolTrimFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using TrimFlags   = Bitmask<EUndefined            , VkCommandPoolTrimFlags  >;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferAllocateInfo">Specification</a> 
			 * 
			 * @ingroup APISpec_Command_Buffers
			 * 
			@todo #TODO: Make == and != operators.
			 */
			struct AllocateInfo : V0::VKStruct_Base<VkCommandBufferAllocateInfo, EStructureType::CommandBuffer_AllocateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      Handle              Pool       ;
				      ECommandBufferLevel Level      ;
				      uint32              BufferCount;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateInfo">Specification</a> 
			
			@ingroup APISpec_Command_Buffers 

			@todo #TODO: Make == and != operators.
			*/
			struct CreateInfo : V0::VKStruct_Base<VkCommandPoolCreateInfo, EStructureType::CommandPool_CreateInfo>
			{
				      EType       SType           ;
				const void*       Next            ;
				      CreateFlgas Flags           ;
				      uint32      QueueFamilyIndex;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateCommandBuffers">Specification</a>
			 * 
			 * @ingroup APISpec_Command_Buffers
			 * 
			 * \param _deviceHandle
			 * \param _allocateInfo
			 * \param _commandBuffers
			 * \return 
			 */
			static EResult Allocate
			(
				      LogicalDevice::Handle  _deviceHandle  ,
				const AllocateInfo&          _allocateInfo  ,
				      CommandBuffer::Handle* _commandBuffers
			)
			{
				return EResult(vkAllocateCommandBuffers(_deviceHandle, _allocateInfo.operator const VkCommandBufferAllocateInfo*(), _commandBuffers));
			}

			/**
			 * @brief Create a command pool.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateCommandPool">Specification</a>
			 * 
			 * @ingroup APISpec_Command_Buffers
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
			 * @ingroup APISpec_Command_Buffers
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeCommandBuffers">Specification</a>
			 * 
			 * @ingroup APISpec_Command_Buffers
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _bufferCount
			 * \param _commandBuffers
			 */
			static void Free
			(
				      LogicalDevice::Handle _deviceHandle   ,
				      Handle                 _commandPool   ,
				      uint32                 _bufferCount   ,
				const CommandBuffer::Handle* _commandBuffers
			)
			{
				vkFreeCommandBuffers(_deviceHandle, _commandPool, _bufferCount, _commandBuffers);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetCommandPool">Specification</a> 
			 * 
			 * @ingroup APISpec_Command_Buffers
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
			 * @ingroup APISpec_Command_Buffers
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

		/** @} */	// Vault_1
	}

	namespace V2
	{
		/** 
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief 
		Command pools are opaque objects that command buffer memory is allocated from,
        and which allow the implementation to amortize the cost of resource creation across multiple command buffers. 
		
		@details
		Command pools are externally synchronized, meaning that a command pool must not be used concurrently in multiple threads. 
		That includes use via recording commands on any command buffers allocated from the pool, as well as operations that allocate, 
		free, and reset command buffers or the pool itself.
		 
		@ingroup APISpec_Command_Buffers
		*/
		struct CommandPool : public V1::CommandPool
		{
			using Parent = V1::CommandPool;

			using CommandBuffer = V1::CommandBuffer;
			
			/**
			@brief Offers a default constructor of the struct.

			@details
			Default Constructor:
			Pool is set to null handle.
			The command buffer level is set to Primary.
			*/
			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo()
				{
					SType       = STypeEnum                   ;
					Next        = nullptr                     ;
					Pool        = Null<Handle>                ;
					Level       = ECommandBufferLevel::Primary;
					BufferCount = 1                           ;
				}
			};

			/**
			@brief Offers a default constructor of the struct.
			*/
			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			@brief Uses the VulkanAPI's default allocator.
			*/
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

			/**
			@brief Uses the VulkanAPI's default allocator.
			*/
			static void Destroy
			(
				      LogicalDevice::Handle        _deviceHandle,
				      Handle                       _commandPool 
			)
			{
				Parent::Destroy(_deviceHandle, _commandPool, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			@brief Allows for the passing of the allocate info to specify the pool and buffer count alternatively.
			*/
			static void Free
			(
				      LogicalDevice::Handle  _device        ,
				const AllocateInfo&          _info          ,
				const CommandBuffer::Handle* _commandBuffers
			)
			{
				Parent::Free(_device, _info.Pool, _info.BufferCount, _commandBuffers);	
			}

			using Parent::Free;

		#pragma region SingleTimeCommands

			/**
			 * @brief Will auto-allocate a command buffer on the specified pool and begin recording commands on the buffer. 
			 * 
			 * @details
			 * The handle to the command buffer will be returned.
			 * 
			 * Expected to be used with the EndSingleTimeCommands function (defined below it).
			 */
			static CommandBuffer::Handle BeginSingleTimeCommands(LogicalDevice::Handle _device, CommandPool::Handle _commandPool)
			{
				AllocateInfo allocationInfo{};

				allocationInfo.Pool = _commandPool;

				CommandBuffer::Handle commandBuffer;

				Allocate(_device, allocationInfo, &commandBuffer);

				CommandBuffer::BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				CommandBuffer::BeginRecord(commandBuffer, beginInfo);

				return commandBuffer;
			}

			/**
			 * @brief Will end the recording and submit the command buffer created with the BeginSingleTimeCommands function.
			 * 
			 * @details
			 * Will wait until the queue is idle that the commands were submitted to. Will also free the command buffer after completion.
			 * 
			 * Expected to be used with the BeginSingleTimeCommands function (defined above it).
			 */
			static void EndSingleTimeCommands
			(
				CommandBuffer       ::Handle _commandBuffer, 
				CommandPool         ::Handle _commandPool  , 
				LogicalDevice       ::Handle _device       , 
				LogicalDevice::Queue::Handle _queue
			)
			{
				CommandBuffer::EndRecord(_commandBuffer);

				CommandBuffer::SubmitInfo submitInfo{};

				submitInfo.CommandBufferCount = 1              ;
				submitInfo.CommandBuffers     = &_commandBuffer;

				LogicalDevice::Queue::SubmitToQueue(_queue, 1, submitInfo, Null<Fence::Handle>);

				LogicalDevice::Queue::WaitUntilIdle(_queue);

				Parent::Free(_device, _commandPool, 1, &_commandBuffer);
			}

		#pragma endregion SingleTimeCommands	
		};

		/**
		@brief Command buffers are objects used to record commands which can be subsequently submitted to a device queue for execution.

		@ingroup APISpec_Command_Buffers
		*/
		struct CommandBuffer : public V1::CommandBuffer
		{
			using Parent = V1::CommandBuffer;

			/**
			@brief Offers a default constructor of the struct.
			*/
			struct InheritanceWindow : public Parent::InheritanceWindow
			{
				using Parent = Parent::InheritanceWindow;

				InheritanceWindow()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				/**
				@brief Offers a default constructor of the struct.
				*/
				struct ConditionalRenderingInfo : public Parent::ConditionalRenderingInfo
				{
					ConditionalRenderingInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				@brief Offers a default constructor of the struct.
				*/
				struct PassTransformInfo : public Parent::PassTransformInfo
				{
					PassTransformInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			/**
			@brief Offers a default constructor of the struct.
			*/
			struct BeginInfo : public Parent::BeginInfo
			{
				BeginInfo()
				{
					SType           = STypeEnum;
					Next            = nullptr  ;
					InheritanceInfo = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor of the struct.
			*/
			struct SubmitInfo : public Parent::SubmitInfo
			{
				using Parent = Parent::SubmitInfo;

				SubmitInfo()
				{
					SType                = STypeEnum;
					Next                 = nullptr  ;
					WaitSemaphoreCount   = 0        ;
					WaitSemaphores       = nullptr  ;
					WaitDstStageMask     = nullptr  ;
					CommandBufferCount   = 0        ;
					CommandBuffers       = 0        ;
					SignalSemaphoreCount = 0        ;
					SignalSemaphores     = nullptr  ;
				}

				/**
				@brief Offers a default constructor of the struct.
				*/
				struct TimelineSemaphore : public Parent
				{
					TimelineSemaphore()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				@brief Offers a default constructor of the struct.
				*/
				struct D3D12Fence : public Parent
				{
					D3D12Fence()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			/** @brief Uses a single-time command buffer to copy a buffer */
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
				Handle commandBuffer = CommandPool::BeginSingleTimeCommands(_device, _pool);

				Parent::CopyBuffer(commandBuffer, _sourceBuffer, _destinationBuffer, 1, &_regionInfo);

				CommandPool::EndSingleTimeCommands(commandBuffer, _pool, _device, _queue);
			}	

			using Parent::CopyBuffer;

			/**
			@brief A version of SubmitPipelineBarrier where only a set of regular memory barriers are submitted.
			*/
			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer,
					_sourceStageMask,
					_destinationStageMask,
					_dependencyFlags,
					_memoryBarrierCount,
					_memoryBarriers,
					0, nullptr,
					0, nullptr
				);
			}

			/**
			@brief A version where only a set of buffer memory barriers are submitted.
			*/
			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer,
					_sourceStageMask,
					_destinationStageMask,
					_dependencyFlags,
					0, nullptr,
					_bufferMemoryBarrierCount,
					_bufferMemoryBarriers,
					0, nullptr
				);
			}

			/**
			@brief A version of SubmitPipelineBarrier where only a set of image memory barriers are submitted.
			*/
			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer,
					_sourceStageMask,
					_destinationStageMask,
					_dependencyFlags,
					0, nullptr,
					0, nullptr,
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			using Parent::SubmitPipelineBarrier;

			/**
			@brief A version of WaitForEvents where only a set of memory barriers are waited on.
			*/
			static void WaitForEvents
			(
				      Handle               _commandBuffer,
				      uint32               _eventCount,
				const Event::Handle*       _events,
				      Pipeline::StageFlags _srcStageMask,
				      Pipeline::StageFlags _dstStageMask,
				      uint32               _memoryBarrierCount,
				const Memory::Barrier*     _memoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount, _events,
					_srcStageMask, _dstStageMask,
					_memoryBarrierCount, _memoryBarriers,
					0, nullptr, 
					0, nullptr
				);
			}

			/**
			@brief A version of WaitForEvents where only a set of buffer memory barriers are waited on.
			*/
			static void WaitForEvents
			(
				      Handle                  _commandBuffer,
				      uint32                  _eventCount,
				const Event::Handle*          _events,
				      Pipeline::StageFlags    _srcStageMask,
				      Pipeline::StageFlags    _dstStageMask,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount, _events,
					_srcStageMask, _dstStageMask,
					0, nullptr,
					_bufferMemoryBarrierCount, _bufferMemoryBarriers,
					0, nullptr
				);
			}

			/**
			@brief A version of WaitForEvents where only a set of image memory barriers are waited on.
			*/
			static void WaitForEvents
			(
				      Handle                 _commandBuffer,
				      uint32                 _eventCount,
				const Event::Handle*         _events,
				      Pipeline::StageFlags   _srcStageMask,
				      Pipeline::StageFlags   _dstStageMask,
				      uint32                 _imageMemoryBarrierCount,
				const Image::Memory_Barrier* _imageMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount, _events,
					_srcStageMask, _dstStageMask,
					0, nullptr,
					0, nullptr,
					_imageMemoryBarrierCount, _imageMemoryBarriers
				);
			}

			using Parent::WaitForEvents;
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
		@ingroup APISpec_Command_Buffers

		@todo #TODO: Needs documentation.
		*/
		class CommandBuffer : public V2::CommandBuffer
		{
		public:

			using Parent = V2::CommandBuffer;

			using AllocateInfo = V2::CommandPool::AllocateInfo;

			void Assign(const LogicalDevice& _device, AllocateInfo& _info, Handle& _handle)
			{
				device = &_device ;
				info   = _info    ;
				handle = _handle  ;
			}

			EResult BeginRecord(const BeginInfo& _info) const
			{
				return Parent::BeginRecord(handle, _info);
			}

			void BeginRenderPass(const RenderPass::BeginInfo& _info, ESubpassContents _contents) const
			{
				Parent::BeginRenderPass(handle, _info, _contents);
			}

			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint          ,
				      Pipeline::Layout&      _layout            ,
				      uint32                 _firstSet          ,
				      uint32                 _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets
			) const
			{
				Parent::BindDescriptorSets(handle, _bindPoint, _layout.GetHandle(), _firstSet, _descritporSetCount, _descriptorSets, 0, nullptr);
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
			) const
			{
				Parent::BindDescriptorSets(handle, _bindPoint, _layout.GetHandle(), _firstSet, _descritporSetCount, _descriptorSets, _dynamicOffsetCount, _dynamicOffsets);
			}

			void BindIndexBuffer(Buffer& _buffer, DeviceSize _offset, EIndexType _type) const
			{
				Parent::BindIndexBuffer(handle, _buffer.GetHandle(), _offset, _type);
			}

			void BindVertexBuffers(uint32 _firstBinding, uint32 _bindingCount, const Buffer::Handle* _buffers) const
			{
				Parent::BindVertexBuffers(handle, _firstBinding, _bindingCount, _buffers, 0);
			}

			void BindVertexBuffers(uint32 _firstBinding, uint32 _bindingCount, const Buffer::Handle* _buffers, const DeviceSize* _offsets) const
			{
				Parent::BindVertexBuffers(handle, _firstBinding, _bindingCount, _buffers, _offsets);
			}

			void BindPipeline(EPipelineBindPoint _bindPoint, Pipeline& _pipeline) const
			{
				Parent::BindPipeline(handle, _bindPoint, _pipeline.GetHandle());
			}

			void BlitImage(Image& _src, EImageLayout _srcLayout, Image& _dst, EImageLayout _dstLayout, uint32 _regionCount, const Image::Blit* _regions, EFilter _filter) const
			{
				Parent::BlitImage(handle, _src.GetHandle(), _srcLayout, _dst.GetHandle(), _dstLayout, _regionCount, _regions, _filter);
			}

			void CopyBuffer
			(
				      Buffer&                 _sourceBuffer     ,
				      Buffer&                 _destinationBuffer,
				      uint32                  _regionCount      ,
				const Buffer::CopyInfo*       _regions
			) const
			{
				Parent::Parent::CopyBuffer(handle, _sourceBuffer.GetHandle(), _destinationBuffer.GetHandle(), _regionCount, _regions);
			}

			void CopyBufferToImage
			(
				      Buffer&            _srcBuffer     ,
				      Image&             _dstImage      ,
				      EImageLayout       _dstImageLayout,
				      uint32		     _regionCount   ,
				const BufferImageRegion* _regions
			) const
			{
				Parent::CopyBufferToImage(handle, _srcBuffer.GetHandle(), _dstImage.GetHandle(), _dstImageLayout, _regionCount, _regions);
			}

			void Draw
			(
				uint32 _firstVertex  ,
				uint32 _vertexCount  , 
				uint32 _firstInstance,
				uint32 _instanceCount
			) const
			{
				Parent::Draw(handle, _firstVertex, _vertexCount, _firstInstance, _instanceCount);
			}

			void DrawIndexed
			(
				uint32 _indexCount   ,
				uint32 _instanceCount,
				uint32 _firstIndex   ,
				sint32 _vertexOffset ,
				uint32 _firstInstance
			) const
			{
				Parent::DrawIndexed(handle, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			EResult EndRecord() const
			{
				return Parent::EndRecord(handle);
			}

			void EndRenderPass() const
			{
				Parent::EndRenderPass(handle);
			}

			void Execute
			(
				      uint32   _secondaryBufferCount,
				const Handle* _secondaryBuffers
			) const
			{
				Parent::Execute(handle, _secondaryBufferCount, _secondaryBuffers);
			}

			const AllocateInfo& GetAllocateInfo() const { return info; }

			const Handle& GetHandle() const { return handle; }

			void ResetEvent(Event& _event, Pipeline::StageFlags _stageMask) const
			{
				Parent::ResetEvent(handle, _event.GetHandle(), _stageMask);
			}

		#pragma region SubmitPipelineBarrier_OO

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
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
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
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

			void SetDeviceMask(uint32 _deviceMask) const
			{
				Parent::SetDeviceMask(handle, _deviceMask);
			}

			void SetEvent(Event& _event, Pipeline::StageFlags _stageMask) const
			{
				Parent::SetEvent(handle, _event.GetHandle(), _stageMask);
			}

		#pragma region WaitForEvents_OO

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers
				);
			}

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers
				);
			}

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			void WaitForEvents
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
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
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

			bool operator== (const CommandBuffer& _other)
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			AllocateInfo info;

			const LogicalDevice* device;
		};

		/**
		@ingroup APISpec_Command_Buffers

		@todo #TODO: Add documentation.
		*/
		class CommandPool : public V2::CommandPool
		{
		public:
			using Parent = V2::CommandPool;

			using CommandBuffer = V3::CommandBuffer;

			EResult Allocate(AllocateInfo& _info, CommandBuffer& _buffer)
			{
				CommandBuffer::Handle bufferHandle;

				EResult returnCode = Parent::Allocate(*device, _info, &bufferHandle);

				if (returnCode != EResult::Success) return returnCode;

				_buffer.Assign(*device, _info, bufferHandle);

				return returnCode;
			}

			EResult Allocate(AllocateInfo& _info, CommandBuffer::Handle* _handles)
			{
				EResult returnCode = Parent::Allocate(*device, _info, _handles);

				return returnCode;
			}

			EResult Allocate(ECommandBufferLevel _level, uint32 _count, CommandBuffer::Handle* _handles)
			{
				AllocateInfo allocInfo; 

				allocInfo.Level       = _level;
				allocInfo.Pool        = handle;
				allocInfo.BufferCount = _count;

				EResult returnCode = Parent::Allocate(*device, allocInfo, _handles);

				return returnCode;
			}

			EResult Allocate
			(
				ECommandBufferLevel                  _level         ,
				uint32                               _count         ,
				DynamicArray<CommandBuffer>&         _commandBuffers,
				DynamicArray<CommandBuffer::Handle>& _handles
			)
			{
				AllocateInfo allocInfo; 
				
				allocInfo.Level       = _level;
				allocInfo.Pool        = handle;
				allocInfo.BufferCount = _count;

				_commandBuffers.resize(_count); _handles.resize(_count);

				EResult returnCode = Parent::Allocate(*device, allocInfo, _handles.data());

				if (returnCode != EResult::Success) return returnCode;

				for (DeviceSize index = 0; index < _count; index++)
				{
					_commandBuffers[index].Assign(*device, allocInfo, _handles[index]);
				}

				return returnCode;
			}

			EResult Create(const LogicalDevice& _device, CreateInfo& _info)
			{
				device    = &_device                ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*device, info, handle);	
			}

			EResult Create(const LogicalDevice& _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = &_device  ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(*device, info, allocator, handle);	
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			void Free(uint32 _bufferCount, const CommandBuffer::Handle* _commandBuffers)
			{
				Parent::Free(*device, handle, _bufferCount, _commandBuffers);
			}

			void Free
			(
				const AllocateInfo&          _info          ,
				const CommandBuffer::Handle* _commandBuffers
			)
			{
				Parent::Free(*device, handle, _info.BufferCount, _commandBuffers);	
			}

			void Free(CommandBuffer& _commandBuffer)
			{
				Parent::Free(*device, handle, 1, &_commandBuffer.GetHandle());
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult Reset(ResetFlags _flags)
			{
				return Parent::Reset(*device, handle, _flags);
			}

			void Trim(TrimFlags _flags)
			{
				Parent::Trim(*device, handle, _flags);
			}

		#pragma region SingleTimeCommands

			/**
			 * @brief.
			 */
			CommandBuffer BeginSingleTimeCommands(EResult& _result)
			{
				AllocateInfo allocationInfo{};

				allocationInfo.Level       = ECommandBufferLevel::Primary;
				allocationInfo.Pool        = handle                      ;
				allocationInfo.BufferCount = 1                           ;

				CommandBuffer commandBuffer;

				_result = Allocate(allocationInfo, commandBuffer);

				if (_result != EResult::Success) return commandBuffer;

				CommandBuffer::BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				_result = commandBuffer.BeginRecord(beginInfo);

				return commandBuffer;
			}

			/**
			 * @brief.
			 */
			EResult EndSingleTimeCommands
			(
				      CommandBuffer&        _commandBuffer, 
				const LogicalDevice::Queue& _queue
			)
			{
				EResult result = EResult::Incomplete;

				result = _commandBuffer.EndRecord();

				if (result != EResult::Success) return result;

				CommandBuffer::SubmitInfo submitInfo{};

				submitInfo.CommandBufferCount = 1                          ;
				submitInfo.CommandBuffers     = &_commandBuffer.GetHandle();

				result = _queue.SubmitToQueue(1, submitInfo, Null<Fence::Handle>);

				if (result != EResult::Success) return result;

				result = _queue.WaitUntilIdle();

				if (result != EResult::Success) return result;

				Free(_commandBuffer);

				return result;
			}

			EResult CopyBuffer
			(
				      Buffer&               _sourceBuffer     , 
				      Buffer&               _destinationBuffer, 
				      Buffer::CopyInfo&     _regionInfo       ,
				const LogicalDevice::Queue& _queue
			) 
			{
				EResult result;

				CommandBuffer commandBuffer = BeginSingleTimeCommands(result);

				if (result != EResult::Success) return result;

				commandBuffer.CopyBuffer(_sourceBuffer, _destinationBuffer, 1, &_regionInfo);

				result = EndSingleTimeCommands(commandBuffer, _queue);

				return result;
			}

		#pragma endregion SingleTimeCommands

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

			bool operator== (const CommandPool& _other)
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			const LogicalDevice* device;
		};

		/** @} */	// Vault_3
	}
}
