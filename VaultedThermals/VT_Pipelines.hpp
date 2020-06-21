/**
@file VT_Pipelines.hpp

@brief Vaulted Thermals: Pipelines

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Enums.hpp"
#include "VT_Constants.hpp"
#include "VT_Initialization.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Resource.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Shaders.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		/**
		 * @brief A monolithic object describing the entire graphics, raytracing, or compute pipeline.
		 */
		struct Pipeline
		{
			using Handle = VkPipeline;

			using ShaderStageFlags = Bitmask<EShaderStageFlag, Flags>;

			/**
			 * @brief Pipeline cache objects allow the result of pipeline construction to be reused between pipelines and between runs of an application. 
			 * 
			 * @details
			 * Reuse between pipelines is achieved by passing the same pipeline cache object when creating multiple related pipelines. 
			 * Reuse across runs of an application is achieved by retrieving pipeline cache contents in one run of an application, saving the contents, 
			 * and using them to preinitialize a pipeline cache on a subsequent run. The contents of the pipeline cache objects are managed by the implementation. 
			 * Applications can manage the host memory consumed by a pipeline cache object and control the amount of data retrieved from a pipeline cache object.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-cache">Specification</a> 
			 */
			struct Cache
			{
				using Handle = VkPipelineCache;

				using CreateFlags = Bitmask<EPipelineCacheCreateFlag, VkPipelineCacheCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineCacheCreateInfo>
				{
					      EType       SType          ;
					const void*       Next           ;
					      CreateFlags Flags          ;
					      DataSize    InitialDataSize;
					const void*       InitialData    ;
				};

				/**
				 * @brief Create a pipeline cache.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreatePipelineCache.html">Specification</a>
				 * 
				 * \param _deviceHandle
				 * \param _createInfo
				 * \param _allocator
				 * \param _pipelineCache
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle  _deviceHandle ,
					const CreateInfo&            _createInfo   ,
					const VkAllocationCallbacks* _allocator    ,
					      Cache::Handle&         _pipelineCache
				)
				{
					return EResult(vkCreatePipelineCache(_deviceHandle, _createInfo.operator const VkPipelineCacheCreateInfo*(), _allocator, &_pipelineCache));
				}

				/**
				 * @brief Destroy a pipeline cache.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyPipelineCache.html">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _allocator
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Cache::Handle _cache, const AllocationCallbacks* _allocator)
				{
					vkDestroyPipelineCache(_deviceHandle, _cache, _allocator);
				}
			};

			/** @brief  */
			struct ColorBlendState
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineColorBlendAttachmentState">Specification</a>  */
				struct AttachmentState : Vault_00::VKStruct_Base<VkPipelineColorBlendAttachmentState>
				{
					Bool                EnableBlend                 ;
					EBlendFactor        Source_ColorBlendFactor     ;
					EBlendFactor        Destination_ColorBlendFactor;
					EBlendOperation     ColorOperation              ;
					EBlendFactor        Source_AlphaBlendFactor     ;
					EBlendFactor        Destination_AlphaBlendFactor;
					EBlendOperation     AlphaOperation              ;
					ColorComponentFlags ColorWriteMask              ;
				};

				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineColorBlendStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineColorBlendStateCreateInfo >
				{
					      EType            SType                ;
					const void*            Next                 ;
					      CreateFlags      Flags                ;
					      Bool             EnableLogicOperations;
					      ELogicOperation  LogicOperation       ;
					      uint32           AttachmentCount      ;
					const AttachmentState* Attachments          ;
					      float32          BlendConstants[4]    ;
				};
			};

			/** @brief */
			struct DepthStencilState
			{
				using CreateFlags = Bitmask<EUndefined, VkPipelineDepthStencilStateCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDepthStencilStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineDepthStencilStateCreateInfo>
				{
					      EType             SType                ;			   
					const void*             Next                 ;
					      CreateFlags       Flags                ;
					      Bool              DepthTestEnable      ;
					      Bool              DepthWriteEnable     ;
					      ECompareOperation DepthCompareOp       ;
 					      Bool              DepthBoundsTestEnable;
					      Bool              StencilTestEnable    ;   
					      EStencilOperation Front                ;
					      EStencilOperation Back                 ;
					      float32           MinDepthBounds       ;
					      float32           MaxDepthBounds       ;
				};
			};

			/** @brief */
			struct DynamicState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDynamicStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineDynamicStateCreateInfo>
				{
					      EType          SType     ;
					const void*          Next      ;
					      CreateFlags    Flags     ;
					      uint32         StateCount;
					const EDynamicState* States    ;
				};
			};

			/** @brief */
			struct InputAssemblyState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineInputAssemblyStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineInputAssemblyStateCreateInfo>
				{
						  EType              SType                 ;
					const void*              Next                  ;
						  CreateFlags        Flags                 ;
						  EPrimitiveTopology Topology              ;
						  Bool               PrimitiveRestartEnable;
				};
			};

			/**
			 * @brief Access to descriptor sets from a pipeline is accomplished through a pipeline layout.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-pipelinelayout">Specification</a> 
			 */
			struct Layout
			{
				using Handle = VkPipelineLayout;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPushConstantRange.html">Specification</a>  */
				struct PushConstantRange : Vault_00::VKStruct_Base<VkPushConstantRange>
				{
					ShaderStageFlags StageFlags;
					uint32           Offset    ;
					uint32           Size      ;
				};

				/**
				 * @brief Descriptors are grouped together into descriptor set objects. 
				 * 
				 * @details
				 * A descriptor set object is an opaque object containing storage for a set of descriptors, 
				 * where the types and number of descriptors is defined by a descriptor set layout. 
				 * 
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-setlayout">Specification</a> 
				 * @todo See if this should be outside of the layout structure.
				 */
				struct DescriptorSet
				{
					using Handle = VkDescriptorSetLayout;

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBinding">Specification</a>  */
					struct Binding : Vault_00::VKStruct_Base<VkDescriptorSetLayoutBinding>
					{
						/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBindingFlagsCreateInfo">Specification</a>  */
						struct Flags
						{
							using Mask = Bitmask<EDescriptorBindingFlag ,VkDescriptorBindingFlags>;

							/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBindingFlagsCreateInfo">Specification</a>  */
							struct CreateInfo : Vault_00::VKStruct_Base<VkDescriptorSetLayoutBindingFlagsCreateInfo >
							{
								       EType SType       ;
								const void*  Next        ;
								      uint32 BindingCount;
								const Mask*  BindingFlags;
							};
						};

						      uint32           Binding          ;
						      EDescriptorType  Type             ;
						      uint32           Count            ;
						      ShaderStageFlags StageFlags       ;
						const Sampler::Handle* ImmutableSamplers;
					};

					using CreateFlags = Bitmask<EDescriptorSetLayoutCreateFlag, Flags>;

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutCreateInfo">Specification</a>  */
					struct CreateInfo : Vault_00::VKStruct_Base<VkDescriptorSetLayoutCreateInfo>
					{
						      EType       SType       ;
						const void*       Extension   ;
						      CreateFlags Flags       ;
						      uint32      BindingCount;
						const Binding*    Bindings    ;
					};

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutSupport">Specification</a>  */
					struct Support : Vault_00::VKStruct_Base<VkDescriptorSetLayoutSupport>
					{
						/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetVariableDescriptorCountLayoutSupport">Specification</a>  */
						struct SetVariableCount : Vault_00::VKStruct_Base<VkDescriptorSetVariableDescriptorCountLayoutSupport>
						{
							EType  sType           ;
							void*  Next            ;
							uint32 MaxVariableCount;
						};

						EType SType    ;
						void* Next     ;
						Bool  Supported;
					};

					/**
					 * @brief Create a descriptor set layout.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateDescriptorSetLayout.html">Specification</a> 
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _allocator
					 * \param _setLayout
					 * \return 
					 */
					static EResult Create
					(
						      LogicalDevice::Handle  _deviceHandle,
						const CreateInfo*            _createInfo  ,
						const AllocationCallbacks*   _allocator   ,
						      Handle&                _setLayout
					)
					{
						return EResult(vkCreateDescriptorSetLayout(_deviceHandle, _createInfo->operator const VkDescriptorSetLayoutCreateInfo*(), _allocator, &_setLayout));
					}

					/**
					 * @brief Destroy a descriptor set layout.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyDescriptorSetLayout.html">Specification</a> 
					 * 
					 * \param _deviceHandle
					 * \param _descriptorSet
					 * \param _allocator
					 */
					static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _descriptorSet, const AllocationCallbacks* _allocator)
					{
						vkDestroyDescriptorSetLayout(_deviceHandle, _descriptorSet, _allocator);
					}

					/**
					 * @brief Query whether a descriptor set layout can be created.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetDescriptorSetLayoutSupport.html">Specification</a> 
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _support
					 */
					static void GetSupport(LogicalDevice::Handle _deviceHandle, CreateInfo& _createInfo, Support& _support)
					{
						vkGetDescriptorSetLayoutSupport(_deviceHandle, _createInfo, _support);
					}
				};

				using CreateFlags = Bitmask<EUndefined, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineLayoutCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineLayoutCreateInfo>
				{
					      EType                  SType                 ;
					const void*                  Next                  ;
					      CreateFlags            Flags                 ;
					      uint32                 SetLayoutCount        ;
					const DescriptorSet::Handle* SetLayouts            ;
					      uint32                 PushConstantRangeCount;
					const PushConstantRange*     PushConstantRanges    ;
				};

				/**
				 * @brief Create a pipeline layout.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreatePipelineLayout.html">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _creationSpec
				 * \param _allocator
				 * \param _pipelineLayout
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle         _deviceHandle  ,
					const Pipeline::Layout::CreateInfo& _creationSpec  ,
					const AllocationCallbacks*          _allocator     ,
					      Pipeline::Layout::Handle&     _pipelineLayout
				)
				{
					return EResult(vkCreatePipelineLayout(_deviceHandle, (VkPipelineLayoutCreateInfo*)(&_creationSpec), _allocator, &_pipelineLayout));
				}

				/**
				 * @brief Destroy a pipeline layout.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyPipelineLayout.html">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _pipelineLayout
				 * \param _allocator
				 */
				static void Destroy
				(
					      LogicalDevice::Handle    _deviceHandle  ,
					      Pipeline::Layout::Handle _pipelineLayout,
					const AllocationCallbacks*     _allocator
				)
				{
					vkDestroyPipelineLayout(_deviceHandle, _pipelineLayout, _allocator);
				}
			};

			/** @brief */
			struct MultisampleState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineMultisampleStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineMultisampleStateCreateInfo >
				{
					      EType        SType                ;
					const void*        Next                 ;
					      CreateFlags  Flags                ;
					      ESampleCount RasterizationSamples ;
					      Bool         EnableSampleShading  ;
					      float32      MinSampleShading     ;
					const SampleMask*  SampleMask           ;
					      Bool         EnableAlphaToCoverage;
					      Bool         EnableAlphaToOne     ;
				};
			};

			/** @brief  */
			struct RasterizationState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineRasterizationStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineRasterizationStateCreateInfo>
				{
						  EType         SType                  ;
					const void*         Next                   ;
						  CreateFlags   Flags                  ;
						  Bool          EnableDepthClamp       ;
						  Bool          EnableRasterizerDiscard;
						  EPolygonMode  PolygonMode            ;
						  CullModeFlags CullMode               ;
						  EFrontFace    FrontFace              ;
						  Bool          EnableDepthBias        ;
						  float32       DepthBiasConstantFactor;
						  float32       DepthBiasClamp         ;
						  float32       DepthBiasSlopeFactor   ;
						  float32       LineWidth              ;
				};
			};

			/** 
			@brief
			Specialization constants are a mechanism whereby constants in a SPIR-V module can have their constant value specified 
			at the time the VkPipeline is created. This allows a SPIR-V module to have constants that can be modified 
			while executing an application that uses the Vulkan API.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationMapEntry">Specification</a> 
			*/
			struct Specialization
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationMapEntry">Specification</a>  */
				struct MapEntry : Vault_00::VKStruct_Base<VkSpecializationMapEntry>
				{
					uint32   ConstantID;
					uint32   Offset    ;
					DataSize Size      ;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationInfo">Specification</a>  */
				struct Info : Vault_00::VKStruct_Base<VkSpecializationInfo>
				{
					      uint32    MapEntryCount;
					const MapEntry* MapEntires   ;
					      DataSize  SizeOfData   ;
					const void*     Data         ;
				};
			};


			/**
			 * @brief Used to handle shader staging within a pipeline, more than one shader can be staged in a pipeline.
			 */
			struct ShaderStage
			{
				using CreateFlags = Bitmask<EPipelineShaderStageCreateFlag, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineShaderStageCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkShaderModuleCreateInfo>
				{
						  EType                 SType         ;
					const void*                 Next          ;
						  CreateFlags           Flags         ;
						  EShaderStageFlag      Stage         ;
						  ShaderModule::Handle  Module        ;
						  RoCStr                Name          ;
					const Specialization::Info* Specialization;
				};
			};
			
			/** @brief */
			struct TessellationState
			{
				using CreateFlags = Bitmask<EUndefined, VkPipelineTessellationStateCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineTessellationStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineTessellationStateCreateInfo>
				{
					      EType       SType             ;
					const void*       Next              ;
					      CreateFlags Flags             ;
					      uint32      PatchControlPoints;
				};
			};

			/**
			 * @brief.
			 */
			struct VertexInputState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkVertexInputAttributeDescription.html">Specification</a>  */
				struct AttributeDescription : Vault_00::VKStruct_Base<VkVertexInputAttributeDescription>
				{
					uint32  Location;
					uint32  Binding ;
					EFormat Format  ;
					uint32  Offset  ;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkVertexInputBindingDescription.html">Specification</a>  */
				struct BindingDescription : Vault_00::VKStruct_Base<VkVertexInputBindingDescription>
				{
					uint32           Binding  ;
					uint32           Stride   ;
					EVertexInputRate InputRate;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineVertexInputStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineVertexInputStateCreateInfo>
				{
						  EType                 SType                        ;
					const void*                 Next                         ;
						  CreateFlags           Flags                        ;
						  uint32                VertexBindingDescriptionCount;
					const BindingDescription*   BindingDescriptions          ;
						  uint32                AttributeDescriptionCount    ;
					const AttributeDescription* AttributeDescription         ;
				};
			};

			/** @brief */
			struct ViewportState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineViewportStateCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkPipelineViewportStateCreateInfo>
				{
						  EType     SType        ;
					const void*     Extension    ;
						  uint32    ViewportCount;
					const Viewport* Viewports    ;
						  uint32    ScissorCount ;
					const Rect2D*   Scissors     ;
				};
			};

			/**
			 * @brief The compute pipeline represents a compute shader.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-compute">Specification</a> 
			 */
			struct Compute
			{
				using CreateFlags = Bitmask<EPipelineCreateFlag, VkPipelineCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkComputePipelineCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkComputePipelineCreateInfo>
				{
					      EType                   SType             ;
					const void*                   Next              ;
					      CreateFlags             Flags             ;
					      ShaderStage::CreateInfo ShaderStage       ;
					      Layout::Handle          Layout            ;
					      Pipeline::Handle        BasePipelineHandle;
					      sint32                  BasePipelineIndex ;
				};

				/**
				 * @brief Create a compute pipeline.
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _allocator
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle _deviceHandle   ,
					      Cache::Handle         _cache          ,
					      uint32                _createInfoCount,
					const CreateInfo&           _createInfos    ,
					const AllocationCallbacks*  _allocator      ,
					      Handle&               _pipelines
				)
				{
					return EResult(vkCreateComputePipelines(_deviceHandle, _cache, _createInfoCount, _createInfos.operator const VkComputePipelineCreateInfo*(), _allocator, &_pipelines));
				}
			};

			/**
			 * @brief Graphics pipelines consist of multiple shader stages, multiple fixed-function pipeline stages, and a pipeline layout.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-graphics">Specification</a> 
			 */
			struct Graphics
			{
				using CreateFlags = Bitmask<EPipelineCreateFlag, VkPipelineCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsPipelineCreateInfo">Specification</a>  */
				struct CreateInfo : Vault_00::VKStruct_Base<VkGraphicsPipelineCreateInfo>
				{
					      EType                           SType             ;
					const void*                           Next              ;
					      CreateFlags                     Flags             ;
					      uint32                          StageCount        ;
					const ShaderStage::CreateInfo*        Stages            ;
					const VertexInputState::CreateInfo*   VertexInputState  ;
					const InputAssemblyState::CreateInfo* InputAssemblyState;
					const TessellationState::CreateInfo*  TessellationState ;
					const ViewportState::CreateInfo*      ViewportState     ;
					const RasterizationState::CreateInfo* RasterizationState;
					const MultisampleState::CreateInfo*   MultisampleState  ;
					const DepthStencilState::CreateInfo*  DepthStencilState ;
					const ColorBlendState::CreateInfo*    ColorBlendState   ;
					const DynamicState::CreateInfo*       DynamicState      ;
					      Pipeline::Layout                Layout            ;
					      RenderPass                      RenderPass        ;
					      uint32                          Subpass           ;
					      Pipeline::Handle                BasePipelineHandle;
					      sint32                          BasePipelineIndex ;
				};

				/**
				 * @brief Graphics pipelines can contain multiple shader groups that can be bound individually. \
				 * Each shader group behaves as if it was a pipeline using the shader group’s state.
				 * 
				 * @details
				 *  When the pipeline is bound by regular means, it behaves as if the state of group 0 is active, 
				 * use vkCmdBindPipelineShaderGroupNV to bind an individual shader group. The primary purpose 
				 * of shader groups is allowing the device to bind different pipeline state using Device-Generated Commands.
				 * 
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
				 * 
				 * @todo Implement.
				 */
				struct ShaderGroup
				{
						
				};

				/**
				 * @brief Create a graphics pipeline.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateGraphicsPipelines.html">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _pipelineCache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _allocator
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle  _deviceHandle   ,
					      Cache::Handle          _pipelineCache  ,
					      uint32                 _createInfoCount,
					const CreateInfo&            _createInfos    ,
					const VkAllocationCallbacks* _allocator      ,
					      Handle&                _pipelines
				)
				{
					return EResult(vkCreateGraphicsPipelines(_deviceHandle, _pipelineCache, _createInfoCount, _createInfos, _allocator, &_pipelines));
				}
			};

			/**
			 * @brief Destroy a pipeline object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyPipeline.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _pipeline
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipeline, const AllocationCallbacks* _allocator)
			{
				vkDestroyPipeline(_deviceHandle, _pipeline, _allocator);
			}
		};
	}
}
