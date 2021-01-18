/*!
@file VV_Command.hpp

@brief Vaulted Vulkan: Command Buffers

@details

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
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
#include "VV_Initialization.hpp"
#include "VV_LogicalDevice.hpp"
#include "VV_Memory.hpp"
#include "VV_Sampler.hpp"
#include "VV_Resource.hpp"
#include "VV_SyncAndCacheControl.hpp"
#include "VV_Shaders.hpp"
#include "VV_Pipelines.hpp"
#include "VV_RenderPass.hpp"



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
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
			using QueryControlFlags           = Bitfield<EQueryControlFlags         , VkQueryControlFlags          >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryPipelineStatisticFlags">Specification</a> @ingroup APISpec_Queries */
			using QueryPipelineStatisticFlags = Bitfield<EQueryPipelineStatisticFlag, VkQueryPipelineStatisticFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using ResetFlags                  = Bitfield<ECommandBufferResetFlag    , VkCommandBufferResetFlags    >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferUsageFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using UsageFlags                  = Bitfield<ECommandBufferUsageFlag    , VkCommandBufferUsageFlags    >;


			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferImageCopy">Specification</a> 
			@ingroup APISpec_Copy_Commands 
			*/
			struct BufferImageRegion : V0::VKStruct_Base<VkBufferImageCopy>
			{
				DeviceSize               BufferOffset      = Memory::ZeroOffset;
				ui32                     BufferRowLength   = 0                 ;
				ui32                     BufferImageHeight = 0                 ;
				Image::SubresourceLayers ImageSubresource ;
				Offset3D                 ImageOffset      ;
				Extent3D                 ImageExtent      ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceInfo">Specification</a> 
			@ingroup APISpec_Command_Buffers
			*/
			struct InheritanceWindow : V0::VKStruct_Base<VkCommandBufferInheritanceInfo, EStructureType::CommandBuffer_InheritanceInfo>
			{
				      EType                       SType                = STypeEnum                ;
				const void*                       Next                 = nullptr                  ;
				      RenderPass::Handle          RenderPass           = Null<RenderPass::Handle> ;
				      ui32                        Subpass              = 0                        ;
				      Framebuffer::Handle         Framebuffer          = Null<Framebuffer::Handle>;
				      Bool                        OcclusionQueryEnable = false                    ;
				      QueryControlFlags           QueryFlags          ;
				      QueryPipelineStatisticFlags PipelineStatistics  ;


				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceConditionalRenderingInfoEXT">Specification</a>
				
				@ingroup APISpec_Command_Buffers
				*/
				struct ConditionalRenderingInfo : V0::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT, EStructureType::CommandBuffer_Inheritance_ConditionalRendering_Info_EXT>
				{
					      EType SType  = STypeEnum;
					const void* Next   = nullptr  ;
					      Bool  Enable = false    ;

					bool operator== (const ConditionalRenderingInfo& _other) { return Next == _other.Next && Enable == _other.Enable ? true : false; }
					bool operator!= (const ConditionalRenderingInfo& _other) { return Next != _other.Next || Enable != _other.Enable ? true : false; }
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 

				@ingroup APISpec_Command_Buffers
				*/
				struct PassTransformInfo : V0::VKStruct_Base
					<VkCommandBufferInheritanceRenderPassTransformInfoQCOM, EStructureType::CommandBufferInheritance_RenderPassTransform_Info_QCOM>
				{
					EType                 SType      = STypeEnum                      ;
					void*                 Next       = nullptr                        ;
					ESurfaceTransformFlag Transform  = ESurfaceTransformFlag::Identity;
					Rect2D                RenderArea;
				};
			};	

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferBeginInfo">Specification</a>

			@ingroup APISpec_Command_Buffers
			*/
			struct BeginInfo : V0::VKStruct_Base<VkCommandBufferBeginInfo, EStructureType::CommandBuffer_BeginInfo>
			{
				      EType              SType           = STypeEnum;
				const void*              Next            = nullptr  ;
				      UsageFlags         Flags;
				const InheritanceWindow* InheritanceInfo = nullptr  ;
			};

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			
			@ingroup APISpec_Command_Buffers
			*/
			struct SubmitInfo : V0::VKStruct_Base<VkSubmitInfo, EStructureType::SubmitInfo>
			{
				      EType                 SType                = STypeEnum;
				const void*                 Next                 = nullptr  ;
				      ui32                  WaitSemaphoreCount   = 0        ;
				const Semaphore::Handle*    WaitSemaphores       = nullptr  ;
				const Pipeline::StageFlags* WaitDstStageMask     = nullptr  ;
				      ui32                  CommandBufferCount   = 0        ;
				const Handle*               CommandBuffers       = nullptr  ;
				      ui32                  SignalSemaphoreCount = 0        ;
				const Semaphore::Handle*    SignalSemaphores     = nullptr  ;


				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkTimelineSemaphoreSubmitInfo">Specification</a>

				@ingroup APISpec_Command_Buffers
				*/
				struct TimelineSemaphore : V0::VKStruct_Base<VkTimelineSemaphoreSubmitInfo>
				{
					      EType SType                     = STypeEnum;
					const void* Next                      = nullptr  ;
					      ui32  WaitSemaphoreValueCount   = 0        ;
					const uI64* WaitSemaphoreValues       = nullptr  ;
					      ui32  SignalSemaphoreValueCount = 0        ;
					const uI64* SignalSemaphoreValues     = nullptr  ;
				};	

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkD3D12FenceSubmitInfoKHR">Specification</a>	

				@ingroup APISpec_Command_Buffers
				*/
				struct D3D12Fence : V0::VKStruct_Base<VkD3D12FenceSubmitInfoKHR>
				{
					      EType SType                      = STypeEnum;
					const void* Next                       = nullptr  ;
					      ui32  WaitSemaphoreValuesCount   = 0        ;
					const uI64* WaitSemaphoreValues        = nullptr  ;
					      ui32  SignalSemaphoreValuesCount = 0        ;
					const uI64* SignalSemaphoreValues      = nullptr  ;
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32KeyedMutexAcquireReleaseInfoKHR">Specification</a> 

				@ingroup APISpec_Command_Buffers
				*/
				struct Win32KeyedMutexAcquireRelease : V0::VKStruct_Base<VkWin32KeyedMutexAcquireReleaseInfoKHR>
				{
					      EType           SType           = STypeEnum;
					const void*           Next            = nullptr  ;
					      ui32            AcquireCount    = 0        ;
					const Memory::Handle* AcquireSyncs    = nullptr  ;
					const uI64*           AcquireKeys     = nullptr  ;
					const ui32*           AcquireTimeouts = nullptr  ;
					      ui32            ReleaseCount    = 0        ;
					const Memory::Handle* ReleaseSyncs    = nullptr  ;
					const uI64*           ReleaseKeys     = nullptr  ;
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkProtectedSubmitInfo">Specification</a> 

				@ingoup APISpec_Command_Buffers
				*/
				struct Protected : V0::VKStruct_Base<VkProtectedSubmitInfo>
				{
					      EType SType           = STypeEnum;
					const void* Next            = nullptr  ;
					      Bool  ProtectedSubmit = false    ;

					bool operator== (const Protected& _other) { return Next == _other.Next && ProtectedSubmit == _other.ProtectedSubmit ? true : false; }
					bool operator!= (const Protected& _other) { return Next != _other.Next && ProtectedSubmit != _other.ProtectedSubmit ? true : false; }
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupSubmitInfo">Specification</a>

				@ingroup APISpec_Command_Buffers
				*/
				struct DeviceGroup : V0::VKStruct_Base<VkDeviceGroupSubmitInfo>
				{
					      EType SType                        = STypeEnum;
					const void* Next                         = nullptr  ;
					      ui32  WaitSemaphoreCount           = 0        ;
					const ui32* WaitSemaphoreDeviceIndices   = nullptr  ;
					      ui32  CommandBufferCount           = 0        ;
					const ui32* CommandBufferDeviceMasks     = nullptr  ;
					      ui32  SignalSemaphoreCount         = 0        ;
					const ui32* SignalSemaphoreDeviceIndices = nullptr  ;
				};

				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceQuerySubmitInfoKHR">Specification</a>

				@ingroup APISpec_Command_Buffers
				*/
				struct PerformanceQuery : V0::VKStruct_Base<VkPerformanceQuerySubmitInfoKHR>
				{
					      EType SType            = STypeEnum;
					const void* Next             = nullptr  ;
					      ui32  CounterPassIndex = 0        ;
				};
			};

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupCommandBufferBeginInfo">Specification</a> 
			
			@ingroup APISpec_Command_Buffers
			*/
			struct DeviceGroupBeginInfo : V0::VKStruct_Base<VkDeviceGroupCommandBufferBeginInfo>
			{
				      EType SType      = STypeEnum;
				const void* Next       = nullptr  ;
				      ui32  DeviceMask = 0        ;
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
				return EResult(vkBeginCommandBuffer(_commandBuffer, _info));
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
			static void BeginRenderPass(const Handle _commandBuffer, const RenderPass::BeginInfo& _beginInfo, ESubpassContents _contents)
			{
				vkCmdBeginRenderPass(_commandBuffer, _beginInfo, VkSubpassContents(_contents));
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
				      ui32                     _firstSet          ,
				      ui32                     _descriptorSetCount,
				const DescriptorSet::Handle*   _descriptorSets    ,
				      ui32                     _dynamicOffsetCount,
				const ui32*                    _dynamicOffsets
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
			static void BindIndexBuffer(Handle _commandBuffer, Buffer::Handle _buffer, DeviceSize _offset, EIndexType _indexType)
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
				      ui32            _firstBinding ,
				      ui32            _bindingCount ,
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
			static void BindPipeline(Handle _commandBuffer, EPipelineBindPoint _pipelineBindPoint, Pipeline::Handle _pipeline)
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
				      ui32          _regionCount   ,
				const Image::Blit*  _regions       ,
				      EFilter       _filter
			)
			{
				vkCmdBlitImage
				(
					_commandBuffer                ,
					_srcImage                     ,
					VkImageLayout(_srcImageLayout),
					_dstImage                     ,
					VkImageLayout(_dstImageLayout),
					_regionCount                  ,
					*_regions                     ,
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
				      ui32              _regionCount      ,
				const Buffer::CopyInfo* _regions
			)
			{
				vkCmdCopyBuffer(_commandBuffer, _sourceBuffer, _destinationBuffer, _regionCount, *_regions);
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
				      ui32               _regionCount   ,
				const BufferImageRegion* _regions
			)
			{
				vkCmdCopyBufferToImage(_commandBuffer, _srcBuffer, _dstImage, VkImageLayout(_dstImageLayout), _regionCount, *_regions);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDraw">Specification</a> 
			 * 
			 * @ingroup APISpec_Drawing_Commands
			 */
			static void Draw(Handle _commandBuffer, ui32 _firstVertex, ui32 _vertexCount, ui32 _firstInstance, ui32 _instanceCount)
			{
				vkCmdDraw(_commandBuffer, _vertexCount, _instanceCount, _firstVertex, _firstInstance);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDrawIndexed">Specification</a> 
			 * 
			 * @ingroup APISpec_Drawing_Commands
			 */
			static void DrawIndexed(Handle _commandBuffer, ui32 _indexCount, ui32 _instanceCount, ui32 _firstIndex, si32 _vertexOffset, ui32 _firstInstance)
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
			static void Execute(Handle _primaryCommandBuffer, ui32 _secondaryBufferCount, const Handle* _secondaryBuffers)
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
			static void ResetEvent(Handle _commandBuffer, Event::Handle _event, Pipeline::StageFlags _stageMask)
			{
				vkCmdResetEvent(_commandBuffer, _event, _stageMask);
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetDeviceMask">Specification</a> 
			* 
			* @ingroup APISpec_Command_Buffers
			*/
			static void SetDeviceMask(Handle _commandBuffer, ui32 _deviceMask)
			{
				vkCmdSetDeviceMask(_commandBuffer, _deviceMask);
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetEvent">Specification</a>
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			*/
			static void SetEvent(Handle _commandBuffer, Event::Handle _event, Pipeline::StageFlags _stageMask)
			{
				vkCmdSetEvent(_commandBuffer, _event, _stageMask);
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetScissor">Specification</a>
			*/
			static void SetScissor(Handle _commandBuffer, ui32 _firstScissor, ui32 _scissorCount, const Rect2D* _scissors)
			{
				vkCmdSetScissor(_commandBuffer, _firstScissor, _scissorCount, *_scissors);
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetViewport">Specification</a>
			* 
			* @ingroup APISpec_Fixed-Function_Vertex_Post-Processing
			*/
			static void SetViewport(Handle _commandBuffer, ui32 _firstViewport, ui32 _viewportCount, const Viewport* _viewports)
			{
				vkCmdSetViewport(_commandBuffer, _firstViewport, _viewportCount, *_viewports);
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
				      ui32                    _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      ui32                    _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				vkCmdPipelineBarrier
				(
					_commandBuffer           ,
					_sourceStageMask         ,
					_destinationStageMask    ,
					_dependencyFlags         ,
					_memoryBarrierCount      ,
					*_memoryBarriers         ,
					_bufferMemoryBarrierCount,
					*_bufferMemoryBarriers   ,
					_imageMemoryBarrierCount ,
					*_imageMemoryBarriers
				);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdWaitEvents">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			static void WaitForEvents
			(
				      Handle                  _commandBuffer           ,
				      ui32                    _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      ui32                    _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      ui32                    _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				vkCmdWaitEvents
				(
					_commandBuffer           ,
					_eventCount              ,
					_events                  ,
					_srcStageMask            ,
					_dstStageMask            ,
					_memoryBarrierCount      , 
					*_memoryBarriers         ,
					_bufferMemoryBarrierCount,
					*_bufferMemoryBarriers   ,
					_imageMemoryBarrierCount ,
					*_imageMemoryBarriers
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
			using CreateFlgas = Bitfield<ECommandPoolCreateFlag, VkCommandPoolCreateFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolResetFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using ResetFlags  = Bitfield<ECommandPoolResetFlags, VkCommandPoolResetFlags >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolTrimFlags">Specification</a> @ingroup APISpec_Command_Buffers */
			using TrimFlags   = Bitfield<EUndefined            , VkCommandPoolTrimFlags  >;

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferAllocateInfo">Specification</a> 
			 
			@ingroup APISpec_Command_Buffers
			*/
			struct AllocateInfo : V0::VKStruct_Base<VkCommandBufferAllocateInfo, EStructureType::CommandBuffer_AllocateInfo>
			{
				      EType               SType       = STypeEnum                   ;
				const void*               Next        = nullptr                     ;
				      Handle              Pool        = Null<Handle>                ;
				      ECommandBufferLevel Level       = ECommandBufferLevel::Primary;
				      ui32                BufferCount = 1                           ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateInfo">Specification</a> 
			
			@ingroup APISpec_Command_Buffers 
			*/
			struct CreateInfo : V0::VKStruct_Base<VkCommandPoolCreateInfo, EStructureType::CommandPool_CreateInfo>
			{
				      EType       SType            = STypeEnum;
				const void*       Next             = nullptr  ;
				      CreateFlgas Flags           ;
				      ui32        QueueFamilyIndex;
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
			static EResult Allocate(LogicalDevice::Handle _deviceHandle, const AllocateInfo& _allocateInfo, CommandBuffer::Handle* _commandBuffers)
			{
				return EResult(vkAllocateCommandBuffers(_deviceHandle, _allocateInfo, _commandBuffers));
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
				return EResult(vkCreateCommandPool(_deviceHandle, _createInfo, *_allocator, &_commandPool));
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
				vkDestroyCommandPool(_deviceHandle, _commandPool, *_allocator);
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
				      LogicalDevice::Handle  _deviceHandle   ,
				      Handle                 _commandPool   ,
				      ui32                   _bufferCount   ,
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
			 * @param _deviceHandle
			 * @param _commandPool
			 * @param _flags
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

			/**
			@brief Uses the VulkanAPI's default allocator.
			*/
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, Handle& _commandPool)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _commandPool);
			}

			using Parent::Create;

			/**
			@brief Uses the VulkanAPI's default allocator.
			*/
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _commandPool)
			{
				Parent::Destroy(_deviceHandle, _commandPool, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			@brief Allows for the passing of the allocate info to specify the pool and buffer count alternatively.
			*/
			static void Free(LogicalDevice::Handle _device, const AllocateInfo& _info, const V1::CommandBuffer::Handle* _commandBuffers)
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
			static V1::CommandBuffer::Handle BeginSingleTimeCommands(LogicalDevice::Handle _device, CommandPool::Handle _commandPool)
			{
				AllocateInfo allocationInfo{};

				allocationInfo.Pool = _commandPool;

				V1::CommandBuffer::Handle commandBuffer;

				Allocate(_device, allocationInfo, &commandBuffer);

				V1::CommandBuffer::BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				V1::CommandBuffer::BeginRecord(commandBuffer, beginInfo);

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
				V1::CommandBuffer   ::Handle _commandBuffer,
				CommandPool         ::Handle _commandPool  ,
				LogicalDevice       ::Handle _device       ,
				LogicalDevice::Queue::Handle _queue
			)
			{
				V1::CommandBuffer::EndRecord(_commandBuffer);

				V1::CommandBuffer::SubmitInfo submitInfo{};

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

			/** @brief Set scissor rectangles dynamically. (Single scissor) */
			static void SetScissor(Handle _commandBuffer, const Rect2D& _scissors)
			{
				Parent::SetScissor(_commandBuffer, 0, 1, &_scissors);
			}

			using Parent::SetScissor;

			/** @brief Set viewport transformation parameters dynamically. (Single viewport) */
			static void SetViewport(Handle _commandBuffer, const Viewport& _viewport)
			{
				Parent::SetViewport(_commandBuffer, 0, 1, &_viewport);
			}

			using Parent::SetViewport;

			/**
			@brief A version of SubmitPipelineBarrier where only a set of regular memory barriers are submitted.
			*/
			static void SubmitPipelineBarrier
			(
				      Handle               _commandBuffer       ,
				      Pipeline::StageFlags _sourceStageMask     ,
				      Pipeline::StageFlags _destinationStageMask,
				      DependencyFlags      _dependencyFlags     ,
				      ui32                 _memoryBarrierCount  ,
				const Memory::Barrier*     _memoryBarriers
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer       ,
					_sourceStageMask     ,
					_destinationStageMask,
					_dependencyFlags     ,
					_memoryBarrierCount  ,
					_memoryBarriers      ,
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
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer       ,
					_sourceStageMask     ,
					_destinationStageMask,
					_dependencyFlags     ,
					0, nullptr,
					_bufferMemoryBarrierCount,
					_bufferMemoryBarriers    ,
					0, nullptr
				);
			}

			/**
			@brief A version of SubmitPipelineBarrier where only a set of image memory barriers are submitted.
			*/
			static void SubmitPipelineBarrier
			(
				      Handle                 _commandBuffer           ,
				      Pipeline::StageFlags   _sourceStageMask         ,
				      Pipeline::StageFlags   _destinationStageMask    ,
				      DependencyFlags        _dependencyFlags         ,
				      ui32                   _imageMemoryBarrierCount ,
				const Image::Memory_Barrier* _imageMemoryBarriers
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer       ,
					_sourceStageMask     ,
					_destinationStageMask,
					_dependencyFlags     ,
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
				      Handle               _commandBuffer     ,
				      ui32                 _eventCount        ,
				const Event::Handle*       _events            ,
				      Pipeline::StageFlags _srcStageMask      ,
				      Pipeline::StageFlags _dstStageMask      ,
				      ui32                 _memoryBarrierCount,
				const Memory::Barrier*     _memoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer     ,
					_eventCount        , 
					_events            ,
					_srcStageMask      , 
					_dstStageMask      ,
					_memoryBarrierCount, 
					_memoryBarriers    ,
					0, nullptr, 
					0, nullptr
				);
			}

			/**
			@brief A version of WaitForEvents where only a set of buffer memory barriers are waited on.
			*/
			static void WaitForEvents
			(
				      Handle                  _commandBuffer           ,
				      ui32                    _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount   , 
					_events       ,
					_srcStageMask ,
					_dstStageMask ,
					0, nullptr,
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers    ,
					0, nullptr
				);
			}

			/**
			@brief A version of WaitForEvents where only a set of image memory barriers are waited on.
			*/
			static void WaitForEvents
			(
				      Handle                 _commandBuffer          ,
				      ui32                   _eventCount             ,
				const Event::Handle*         _events                 ,
				      Pipeline::StageFlags   _srcStageMask           ,
				      Pipeline::StageFlags   _dstStageMask           ,
				      ui32                   _imageMemoryBarrierCount,
				const Image::Memory_Barrier* _imageMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount   , 
					_events       ,
					_srcStageMask , 
					_dstStageMask ,
					0, nullptr,
					0, nullptr,
					_imageMemoryBarrierCount, 
					_imageMemoryBarriers
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
		@brief Command buffers are objects used to record commands which can be subsequently submitted to a device queue for execution.

		@details This object only acts as a host interface to a given device object's handle. Since command pools handle the lifetime
		of a command buffer, The command buffer can only clear its references to the device object.
		*/
		class CommandBuffer : public V2::CommandBuffer
		{
		public:

			using Parent = V2::CommandBuffer;

			using AllocateInfo = V2::CommandPool::AllocateInfo;

			/**
			@brief Default constructor.
			*/
			CommandBuffer() : handle(Null<Handle>), device(nullptr)
			{}

			/**
			@brief Constructor with logical device, allocate info, and handle specified (acts as an Assign() call)
			*/
			CommandBuffer(const LogicalDevice& _device, Handle& _handle) :
				handle(_handle), device(&_device)
			{}

			/**
			@brief Assign a device and handle.
			*/
			void Assign(const LogicalDevice& _device, Handle& _handle)
			{
				device = &_device;
				handle = _handle ;
			}

			/**
			@brief Clear references to related device objects.
			*/
			void Clear()
			{
				device = nullptr     ;
				handle = Null<Handle>;
			}

			/**
			@brief Begin recording commands to the buffer.

			@details Command buffer recording follows an immediate design. Calls done related to this buffer will be recorded by the buffer.
			*/
			EResult BeginRecord(const BeginInfo& _info) const
			{
				return Parent::BeginRecord(handle, _info);
			}

			/**
			@brief Begin recording a render pass set of commands into the buffer.
			*/
			void BeginRenderPass(const RenderPass::BeginInfo& _info, ESubpassContents _contents) const
			{
				Parent::BeginRenderPass(handle, _info, _contents);
			}

			/**
			@brief Bind one or more descriptor sets to a command buffer. (No dynamic offsets)
			*/
			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint         ,
				      Pipeline::Layout&      _layout            ,
				      ui32                   _firstSet          ,
				      ui32                   _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets
			) const
			{
				Parent::BindDescriptorSets(handle, _bindPoint, _layout, _firstSet, _descritporSetCount, _descriptorSets, 0, nullptr);
			}

			/**
			@brief Bind one or more descriptor sets to a command buffer. 
			*/
			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint         ,
				      Pipeline::Layout&      _layout            ,
				      ui32                   _firstSet          ,
				      ui32                   _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets    ,
				      ui32                   _dynamicOffsetCount,
				const ui32*                  _dynamicOffsets
			) const
			{
				Parent::BindDescriptorSets(handle, _bindPoint, _layout, _firstSet, _descritporSetCount, _descriptorSets, _dynamicOffsetCount, _dynamicOffsets);
			}

			/**
			@brief Bind an index buffer to a command buffer.
			*/
			void BindIndexBuffer(Buffer& _buffer, DeviceSize _offset, EIndexType _type) const
			{
				Parent::BindIndexBuffer(handle, _buffer, _offset, _type);
			}

			/**
			@brief Bind vertex buffers to a command buffer for use in subsequent draw commands. (No offsets)
			*/
			void BindVertexBuffers(ui32 _firstBinding, ui32 _bindingCount, const Buffer::Handle* _buffers) const
			{
				unbound DeviceSize offsets[] = {0};

				Parent::BindVertexBuffers(handle, _firstBinding, _bindingCount, _buffers, offsets);
			}

			/**
			@brief Bind vertex buffers to a command buffer for use in subsequent draw commands. 
			*/
			void BindVertexBuffers(ui32 _firstBinding, ui32 _bindingCount, const Buffer::Handle* _buffers, const DeviceSize* _offsets) const
			{
				Parent::BindVertexBuffers(handle, _firstBinding, _bindingCount, _buffers, _offsets);
			}

			/**
			@brief Bind a pipeline to a command buffer for use in subsequent commands. (Until another pipeline is bound)
			*/
			void BindPipeline(EPipelineBindPoint _bindPoint, Pipeline& _pipeline) const
			{
				Parent::BindPipeline(handle, _bindPoint, _pipeline);
			}

			/**
			@brief Copy regions of a source image into a destination image, potentially performing format conversion, arbitrary scaling, and filtering.
			*/
			void BlitImage(Image& _src, EImageLayout _srcLayout, Image& _dst, EImageLayout _dstLayout, ui32 _regionCount, const Image::Blit* _regions, EFilter _filter) const
			{
				Parent::BlitImage(handle, _src, _srcLayout, _dst, _dstLayout, _regionCount, _regions, _filter);
			}

			/**
			@brief Copy data between buffer objects.
			*/
			void CopyBuffer(Buffer& _sourceBuffer, Buffer& _destinationBuffer, ui32 _regionCount, const Buffer::CopyInfo* _regions) const
			{
				Parent::Parent::CopyBuffer(handle, _sourceBuffer, _destinationBuffer, _regionCount, _regions);
			}

			/**
			@brief Copy data from a buffer object to an image object.
			*/
			void CopyBufferToImage
			(
				      Buffer&            _srcBuffer     ,
				      Image&             _dstImage      ,
				      EImageLayout       _dstImageLayout,
				      ui32		         _regionCount   ,
				const BufferImageRegion* _regions
			) const
			{
				Parent::CopyBufferToImage(handle, _srcBuffer, _dstImage, _dstImageLayout, _regionCount, _regions);
			}

			/**
			@brief Record a non-indexed draw.
			*/
			void Draw(ui32 _firstVertex, ui32 _vertexCount, ui32 _firstInstance, ui32 _instanceCount) const
			{
				Parent::Draw(handle, _firstVertex, _vertexCount, _firstInstance, _instanceCount);
			}

			/**
			@brief Record an indexed draw.
			*/
			void DrawIndexed
			(
				ui32 _indexCount   ,
				ui32 _instanceCount,
				ui32 _firstIndex   ,
				si32 _vertexOffset ,
				ui32 _firstInstance
			) const
			{
				Parent::DrawIndexed(handle, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			/**
			@brief complete recording of a command buffer.
			*/
			EResult EndRecord() const
			{
				return Parent::EndRecord(handle);
			}

			/**
			@brief record a command to end a render pass instance after recording the commands for the last subpass.
			*/
			void EndRenderPass() const
			{
				Parent::EndRenderPass(handle);
			}

			/**
			@brief A secondary command buffer must not be directly submitted to a queue. 
			Instead, secondary command buffers are recorded to execute as part of a primary command buffer..
			*/
			void Execute(ui32 _secondaryBufferCount, const Handle* _secondaryBuffers) const
			{
				Parent::Execute(handle, _secondaryBufferCount, _secondaryBuffers);
			}

			/**
			@brief Set the state of an event to unsignaled from a device.
			*/
			void ResetEvent(Event& _event, Pipeline::StageFlags _stageMask) const
			{
				Parent::ResetEvent(handle, _event, _stageMask);
			}

			/**
			@brief Update the current device bitfield of a command buffer.
			*/
			void SetDeviceMask(ui32 _deviceMask) const
			{
				Parent::SetDeviceMask(handle, _deviceMask);
			}

			/**
			@brief Set the state of an event to signaled from a device.
			*/
			void SetEvent(Event& _event, Pipeline::StageFlags _stageMask) const
			{
				Parent::SetEvent(handle, _event, _stageMask);
			}

			/** @brief Set scissor rectangles dynamically. */
			void SetScissor(ui32 _firstScissor, ui32 _scissorCount, const Rect2D* _scissors) const
			{
				Parent::SetScissor(handle, _firstScissor, _scissorCount, _scissors);
			}

			/** @brief Set scissor rectangles dynamically. */
			void SetScissor(const DynamicArray<Rect2D>& _scissors) const
			{
				Parent::SetScissor(handle, 0, static_cast<ui32>(_scissors.size()), _scissors.data());
			}

			/** @brief Set scissor rectangles dynamically. (Single scissor) */
			void SetScissor(const Rect2D& _scissor) const
			{
				Parent::SetScissor(handle, _scissor);
			}

			/** @brief Set viewport transformation parameters dynamically. */
			void SetViewport(ui32 _firstViewport, ui32 _viewportCount, const Viewport* _viewports) const
			{
				Parent::SetViewport(handle, _firstViewport, _viewportCount, _viewports);
			}

			/** 
			@brief Set viewport transformation parameters dynamically. 
			*/
			void SetViewport(const DynamicArray<Viewport>& _viewports) const
			{
				Parent::SetViewport(handle, 0, static_cast<ui32>(_viewports.size()), _viewports.data());
			}

			/** 
			@brief Set viewport transformation parameters dynamically. (Single viewport) 
			*/
			void SetViewport(const Viewport& _viewport) const
			{
				Parent::SetViewport(handle, _viewport);
			}

		#pragma region SubmitPipelineBarrier_OO

			/**
			@brief A version of SubmitPipelineBarrier where only a set of regular memory barriers are submitted.
			*/
			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags _sourceStageMask         ,
				      Pipeline::StageFlags _destinationStageMask    ,
				      DependencyFlags      _dependencyFlags         ,
				      ui32                 _memoryBarrierCount      ,
				const Memory::Barrier*     _memoryBarriers          
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle               , 
					_sourceStageMask     , 
					_destinationStageMask, 
					_dependencyFlags     , 
					_memoryBarrierCount  , 
					_memoryBarriers
				);
			}

			/**
			@brief A version where only a set of buffer memory barriers are submitted.
			*/
			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask         , 
					_destinationStageMask    , 
					_dependencyFlags         , 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers
				);
			}

			/**
			@brief A version of SubmitPipelineBarrier where only a set of image memory barriers are submitted.
			*/
			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags   _sourceStageMask         ,
				      Pipeline::StageFlags   _destinationStageMask    ,
				      DependencyFlags        _dependencyFlags         ,
				      ui32                   _imageMemoryBarrierCount ,
				const Image::Memory_Barrier* _imageMemoryBarriers
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask        , 
					_destinationStageMask   , 
					_dependencyFlags        , 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			/**
			@brief Record a pipeline barrier.
			*/
			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      ui32                    _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      ui32                    _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle                   , 
					_sourceStageMask         , 
					_destinationStageMask    , 
					_dependencyFlags         , 
					_memoryBarrierCount      , 
					_memoryBarriers          , 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers    , 
					_imageMemoryBarrierCount ,
					_imageMemoryBarriers
				);
			}

		#pragma endregion SubmitPipelineBarrier_OO

		#pragma region WaitForEvents_OO

			/**
			@brief A version of WaitForEvents where only a set of memory barriers are waited on.
			*/
			void WaitForEvents
			(
				      ui32                 _eventCount              ,
				const Event::Handle*       _events                  ,
				      Pipeline::StageFlags _srcStageMask            ,
				      Pipeline::StageFlags _dstStageMask            ,
				      ui32                 _memoryBarrierCount      ,
				const Memory::Barrier*     _memoryBarriers          
			) const
			{
				Parent::WaitForEvents
				(
					handle             , 
					_eventCount        , 
					_events            , 
					_srcStageMask      , 
					_dstStageMask      , 
					_memoryBarrierCount, 
					_memoryBarriers
				);
			}

			/**
			@brief A version of WaitForEvents where only a set of buffer memory barriers are waited on.
			*/
			void WaitForEvents
			(
				      ui32                    _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			) const
			{
				Parent::WaitForEvents
				(
					handle                   , 
					_eventCount              , 
					_events                  , 
					_srcStageMask            , 
					_dstStageMask            , 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers
				);
			}

			/**
			@brief A version of WaitForEvents where only a set of image memory barriers are waited on.
			*/
			void WaitForEvents
			(
				      ui32                   _eventCount              ,
				const Event::Handle*         _events                  ,
				      Pipeline::StageFlags   _srcStageMask            ,
				      Pipeline::StageFlags   _dstStageMask            ,
				      ui32                   _imageMemoryBarrierCount ,
				const Image::Memory_Barrier* _imageMemoryBarriers
			) const
			{
				Parent::WaitForEvents
				(
					handle                  , 
					_eventCount             , 
					_events                 , 
					_srcStageMask           , 
					_dstStageMask           , 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			/**
			@brief Wait for one or more events to enter the signaled state on a device.
			*/
			void WaitForEvents
			(
				      ui32                    _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      ui32                    _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      ui32                    _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      ui32                    _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::WaitForEvents
				(
					handle                   , 
					_eventCount              , 
					_events                  ,  
					_srcStageMask            , 
					_dstStageMask            , 
					_memoryBarrierCount      , 
					_memoryBarriers          , 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers    ,
					_imageMemoryBarrierCount ,
					_imageMemoryBarriers
				);
			}

		#pragma endregion WaitForEvents_OO

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
			@brief Implicit conversion to give a pointers to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const CommandBuffer& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const LogicalDevice* device;
		};

		/**
		@ingroup APISpec_Command_Buffers
		@brief Command pools are opaque objects that command buffer memory is allocated from,
		and which allow the implementation to amortize the cost of resource creation across multiple command buffers.

		@details
		Command pools are externally synchronized, meaning that a command pool must not be used concurrently in multiple threads.
		That includes use via recording commands on any command buffers allocated from the pool, as well as operations that allocate,
		free, and reset command buffers or the pool itself.

		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class CommandPool : public V2::CommandPool
		{
		public:
			using Parent = V2::CommandPool;

			/**
			@brief Default constructor.
			*/
			CommandPool() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Default constructor, logical device defined.
			*/
			CommandPool(const LogicalDevice& _device) : handle(Null<Handle>),  allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Default constructor, logical device and allocator defined.
			*/
			CommandPool(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : 
				handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			CommandPool(CommandPool&& _poolToMove) noexcept : 
				handle(std::move(_poolToMove.handle)), allocator(std::move(_poolToMove.allocator)), device(std::move(_poolToMove.device))
			{
				_poolToMove.handle    = Null<Handle>            ;
				_poolToMove.allocator = Memory::DefaultAllocator;
				_poolToMove.device    = nullptr                 ;
			}

			/**
			@brief Call the destroy for the device object if the host object's handle is not null.
			*/
			~CommandPool()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Allocate a command buffer.
			*/
			EResult Allocate(CommandBuffer& _buffer)
			{
				CommandBuffer::Handle bufferHandle;

				AllocateInfo info; info.Pool = handle;

				EResult returnCode = Parent::Allocate(*device, info, &bufferHandle);

				if (returnCode != EResult::Success) return returnCode;

				_buffer.Assign(*device, bufferHandle);

				return returnCode;
			}

			/**
			@brief Allocate a command buffer with the specified allocation info.
			*/
			EResult Allocate(AllocateInfo& _info, CommandBuffer& _buffer)
			{
				CommandBuffer::Handle bufferHandle;

				EResult returnCode = Parent::Allocate(*device, _info, &bufferHandle);

				if (returnCode != EResult::Success) return returnCode;

				_buffer.Assign(*device, bufferHandle);

				return returnCode;
			}

			/**
			@brief Allocate command buffers based on the allocate info.
			*/
			EResult Allocate(AllocateInfo& _info, CommandBuffer::Handle* _buffers)
			{
				EResult returnCode = Parent::Allocate(*device, _info, _buffers);

				return returnCode;
			}

			/**
			@brief Allocate command buffers with the specified count and level.
			*/
			EResult Allocate(ECommandBufferLevel _level, ui32 _count, CommandBuffer::Handle* _buffers)
			{
				AllocateInfo allocInfo; 

				allocInfo.Level       = _level;
				allocInfo.Pool        = handle;
				allocInfo.BufferCount = _count;

				EResult returnCode = Parent::Allocate(*device, allocInfo, _buffers);

				return returnCode;
			}

/**
			@brief Allocate command buffers and their handles into dynamic arrays. based on the count provided and the level desired.
			*/
			EResult Allocate
			(
				ECommandBufferLevel          _level         ,
				ui32                         _count         ,
				DynamicArray<CommandBuffer>& _commandBuffers
			)
			{
				AllocateInfo allocInfo; 
				
				allocInfo.Level       = _level;
				allocInfo.Pool        = handle;
				allocInfo.BufferCount = _count;

				DynamicArray<CommandBuffer::Handle> handles(_count);

				_commandBuffers.resize(_count);

				EResult returnCode = Parent::Allocate(*device, allocInfo, handles.data());

				if (returnCode != EResult::Success) return returnCode;

				for (DeviceSize index = 0; index < _count; index++)
				{
					_commandBuffers[index].Assign(*device, handles[index]);
				}

				return returnCode;
			}

			/**
			@brief Allocate command buffers and their handles into dynamic arrays. based on the count provided and the level desired.
			*/
			EResult Allocate
			(
				ECommandBufferLevel                  _level         ,
				ui32                                 _count         ,
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
					_commandBuffers[index].Assign(*device, _handles[index]);
				}

				return returnCode;
			}

			/**
			@brief Create a command pool.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Create a command pool (device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);	
			}

			/**
			@brief Create a command pool (device and allocator specified).
			*/
			EResult Create(const LogicalDevice& _device, CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);	
			}

			/**
			@brief Destroy a command pool.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle    = Null<Handle>;
				allocator = nullptr     ;
				device    = nullptr     ;
			}

			/**
			@brief Free the command buffers based on the count and handle container provided.
			*/
			void Free(ui32 _bufferCount, const CommandBuffer::Handle* _commandBuffers)
			{
				Parent::Free(*device, handle, _bufferCount, _commandBuffers);
			}

			/**
			@brief Free the command buffers based on the allocate info and handle container provided.
			*/
			void Free(const AllocateInfo& _info, const CommandBuffer::Handle* _commandBuffers)
			{
				Parent::Free(*device, handle, _info.BufferCount, _commandBuffers);	
			}

			/**
			@brief Free a command buffer.
			*/
			void Free(CommandBuffer& _commandBuffer)
			{
				Parent::Free(*device, handle, 1, _commandBuffer);
			}

			/**
			@brief Resetting a command pool recycles all of the resources from all of the command buffers allocated from the command pool back to the command pool. 
			All command buffers that have been allocated from the command pool are put in the initial state.
			*/
			EResult Reset(ResetFlags _flags)
			{
				return Parent::Reset(*device, handle, _flags);
			}

			/**
			@brief Trimming a command pool recycles unused memory from the command pool back to the system. 
			Command buffers allocated from the pool are not affected by the command.
			*/
			void Trim(TrimFlags _flags)
			{
				Parent::Trim(*device, handle, _flags);
			}

		#pragma region SingleTimeCommands

			/**
			* @brief Will auto-allocate a command buffer on the specified pool and begin recording commands on the buffer. 
			* 
			* @details
			* The handle to the command buffer will be returned.
			* 
			* Expected to be used with the EndSingleTimeCommands function (defined below it).
			*/
			CommandBuffer BeginSingleTimeCommands(EResult& _result)
			{
				AllocateInfo allocationInfo;

				allocationInfo.Pool = handle;

				CommandBuffer::Handle bufferHandle;

				_result = Allocate(allocationInfo, &bufferHandle);

				if (_result != EResult::Success) return CommandBuffer();

				CommandBuffer::BeginInfo beginInfo;

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				_result = CommandBuffer::Parent::BeginRecord(bufferHandle, beginInfo);

				return CommandBuffer(*device, bufferHandle);
			}

			/**
			* @brief Will end the recording and submit the command buffer created with the BeginSingleTimeCommands function.
			* 
			* @details
			* Will wait until the queue is idle that the commands were submitted to. Will also free the command buffer after completion.
			* 
			* Expected to be used with the BeginSingleTimeCommands function (defined above it).
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

				CommandBuffer::SubmitInfo submitInfo;

				submitInfo.CommandBufferCount = 1             ;
				submitInfo.CommandBuffers     = _commandBuffer;

				result = _queue.SubmitToQueue(1, submitInfo, Null<Fence::Handle>);

				if (result != EResult::Success) return result;

				result = _queue.WaitUntilIdle();

				if (result != EResult::Success) return result;

				Free(_commandBuffer);

				return result;
			}

			/**
			@brief Uses a single time command buffer to copy a buffer with the provided queue and copy info.
			*/
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
			bool operator== (const CommandPool& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			CommandPool& operator= (CommandPool&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/** @} */	// Vault_3
	}
}
