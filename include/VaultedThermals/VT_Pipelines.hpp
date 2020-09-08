/*!
@file VT_Pipelines.hpp

@brief Vaulted Thermals: Pipelines

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
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
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_SyncAndCacheControl.hpp"
#include "VT_Shaders.hpp"



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
		 * @brief A monolithic object describing the entire graphics, raytracing, or compute pipeline.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
		 * 
		 * @ingroup APISpec_Pipelines
		 */
		struct Pipeline
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipeline">Specification</a> @ingroup APISpec_Pipelines */
			using Handle = VkPipeline;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderStageFlags">Specification</a> @ingroup APISpec_Pipelines */
			using ShaderStageFlags = Bitmask<EShaderStageFlag, VkShaderStageFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineStageFlags">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			using StageFlags = Bitmask<EPipelineStageFlag, VkPipelineStageFlags>;

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
			 * 
			 * @ingroup APISpec_Pipelines
			 */
			struct Cache
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.htmal#VkPipelineCache">Specification</a> @ingroup APISpec_Pipelines */
				using Handle = VkPipelineCache;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateFlags">Specification</a> @ingroup APISpec_Pipelines  */
				using CreateFlags = Bitmask<EPipelineCacheCreateFlag, VkPipelineCacheCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateInfo">Specification</a> @ingroup APISpec_Pipelines */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineCacheCreateInfo, EStructureType::Pipeline_Cache_CreateInfo>
				{
					      EType       SType          ;
					const void*       Next           ;
					      CreateFlags Flags          ;
					      WordSize    InitialDataSize;
					const void*       InitialData    ;
				};

				/**
				 * @brief Create a pipeline cache.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreatePipelineCache">Specification</a>
				 * 
				 * @ingroup APISpec_Pipelines
				 * 
				 * \param _deviceHandle
				 * \param _createInfo
				 * \param _allocator
				 * \param _pipelineCache
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle ,
					const CreateInfo&                  _createInfo   ,
					const Memory::AllocationCallbacks* _allocator    ,
					      Cache::Handle&               _pipelineCache
				)
				{
					return EResult(vkCreatePipelineCache(_deviceHandle, _createInfo, *_allocator, &_pipelineCache));
				}

				/**
				 * @brief Destroy a pipeline cache.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyPipelineCache">Specification</a> 
				 * 
				 * @ingroup APISpec_Pipelines
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _allocator
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Cache::Handle _cache, const Memory::AllocationCallbacks* _allocator)
				{
					vkDestroyPipelineCache(_deviceHandle, _cache, *_allocator);
				}

				/** 
				@todo 
				#TODO: MakeMergCacheFunction vkMergePipelineCaches 
				*/

				/** 
				@todo 
				#TODO:  vkGetPipelineCacheData 
				*/
			};

			/**
			@ingroup APISpec_The_Framebuffer

			@brief Blending combines the incoming source fragment’s R, G, B, and A values with the destination R, G, B, and A values of each sample stored in the framebuffer 
			at the fragment’s (xf,yf) location. Blending is performed for each color sample covered by the fragment, rather than just once for each fragment.

			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#framebuffer-blending">Specification</a> 
			*/
			struct ColorBlendState
			{
				/**
				@ingroup APISpec_The_Framebuffer

				@brief Specifies per-target blending state for each individual color attachment.
				
				@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineColorBlendAttachmentState">Specification</a> 
				*/
				struct AttachmentState : V0::VKStruct_Base<VkPipelineColorBlendAttachmentState, EStructureType::Pipeline_ColorBlendAdvancedState_CreateInfo_EXT>
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

				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< @brief Reserved for future use.

				/**
				@ingroup APISpec_The_Framebuffer

				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineColorBlendStateCreateInfo">Specification</a>

				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineColorBlendStateCreateInfo, EStructureType::Pipeline_ColorBlendState_CreateInfo>
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

			/**
			@brief Pipeline state controlling the depth bounds tests, stencil test, and depth test.

			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fragops-ds-state">Specification</a> 

			@ingroup APISpec_Fragment_Operations
			*/
			struct DepthStencilState
			{
				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDepthStencilStateCreateFlags">Specification</a> 
				@ingroup APISpec_Fragment_Operations
				*/
				using CreateFlags = Bitmask<EUndefined, VkPipelineDepthStencilStateCreateFlags>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDepthStencilStateCreateInfo">Specification</a>  
				@ingroup APISpec_Fragment_Operations
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineDepthStencilStateCreateInfo, EStructureType::Pipeline_DepthStencilState_CreateInfo>
				{
					      EType                 SType                ;
					const void*                 Next                 ;
					      CreateFlags           Flags                ;
					      Bool                  DepthTestEnable      ;
					      Bool                  DepthWriteEnable     ;
					      ECompareOperation     DepthCompareOp       ;
 					      Bool                  DepthBoundsTestEnable;
					      Bool                  StencilTestEnable    ;
					      StencilOperationState Front                ;
					      StencilOperationState Back                 ;
					      float32               MinDepthBounds       ;
					      float32               MaxDepthBounds       ;
				};
			};

			/** 
			@brief Used to indicate which properties of the pipeline state object are dynamic and can be changed independently of the pipeline state. 

			@details This can be NULL, which means no state in the pipeline is considered dynamic.

			@ingroup APISpec_Pipelines
			*/
			struct DynamicState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< @brief Reserved for future use.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDynamicStateCreateInfo">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineDynamicStateCreateInfo, EStructureType::Pipeline_DynamicState_CreateInfo>
				{
					      EType          SType     ;
					const void*          Next      ;
					      CreateFlags    Flags     ;
					      uint32         StateCount;
					const EDynamicState* States    ;
				};
			};

			/** 
			@brief Each draw is made up of zero or more vertices and zero or more instances, which are processed by the device and result in the assembly of primitives.
			Primitives are assembled according to the InputAssemblyState member.

			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#drawing">Specification</a> 

			@ingroup APISpec_Drawing_Commands
			*/
			struct InputAssemblyState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< @brief Reserved for future use.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineInputAssemblyStateCreateInfo">Specification</a>  
				@ingroup APISpec_Drawing_Commands
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineInputAssemblyStateCreateInfo, EStructureType::Pipeline_InputAssemblyState_CreateInfo>
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
			 * @ingroup APISpec_Resource_Descriptors
			 */
			struct Layout
			{
				/**
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineLayout">Specification</a> 
				@ingroup APISpec_Resource_Descriptors 
				*/
				using Handle = VkPipelineLayout;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPushConstantRange">Specification</a>  
				@ingroup APISpec_Resource_Descriptors
				*/
				struct PushConstantRange : V0::VKStruct_Base<VkPushConstantRange>
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
				 * 
				 * @ingroup APISpec_Resource_Descriptors
				 */
				struct DescriptorSet
				{
					/** 
					@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayout">Specification</a> 
					@ingroup APISpec_Resource_Descriptors
					*/
					using Handle = VkDescriptorSetLayout;

					/** 
					@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBinding">Specification</a> 
					@ingroup APISpec_Resource_Descriptors
					*/
					struct Binding : V0::VKStruct_Base<VkDescriptorSetLayoutBinding>
					{
						      uint32           BindingID        ;
						      EDescriptorType  Type             ;
						      uint32           Count            ;
						      ShaderStageFlags StageFlags       ;
						const Sampler::Handle* ImmutableSamplers;

						/** 
						@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBindingFlags">Specification</a> 
						@ingroup APISpec_Resource_Descriptors 
						*/
						using CreateFlags = Bitmask<EDescriptorBindingFlag ,VkDescriptorBindingFlags>;

						/** 
						@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBindingFlagsCreateInfo">Specification</a> 
						@ingroup APISpec_Resource_Descriptors 
						*/
						struct FlagsCreateInfo : V0::VKStruct_Base<VkDescriptorSetLayoutBindingFlagsCreateInfo, EStructureType::Descriptor_SetLayoutBindingFlags_CreateInfo>
						{
							      EType       SType        ;
							const void*        Next        ;
							      uint32       BindingCount;
							const CreateFlags* BindingFlags;
						};
					};

					/** 
					@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutCreateFlags">Specification</a>  
					@ingroup APISpec_Resource_Descriptors
					*/
					using CreateFlags = Bitmask<EDescriptorSetLayoutCreateFlag, VkDescriptorSetLayoutCreateFlags>;

					/** 
					@brief Information about the descriptor set layout.
					@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutCreateInfo">Specification</a>  
					@ingroup APISpec_Resource_Descriptors
					*/
					struct CreateInfo : V0::VKStruct_Base<VkDescriptorSetLayoutCreateInfo, EStructureType::Descriptor_SetLayout_CreateInfo>
					{
						      EType       SType       ;
						const void*       Next        ;
						      CreateFlags Flags       ;
						      uint32      BindingCount;
						const Binding*    Bindings    ;
					};

					/** 
					@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutSupport">Specification</a>

					@ingroup APISpec_Resource_Descriptors	
					*/
					struct Support : V0::VKStruct_Base<VkDescriptorSetLayoutSupport, EStructureType::Descriptor_SetLayoutSupport>
					{
						EType SType    ;
						void* Next     ;
						Bool  Supported;

						/** 
						@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetVariableDescriptorCountLayoutSupport">Specification</a>  

						@ingroup APISpec_Resource_Descriptors
						*/
						struct SetVariableCount : V0::VKStruct_Base<VkDescriptorSetVariableDescriptorCountLayoutSupport, EStructureType::Descriptor_SetVariable_Descriptor_CountLayoutSupport>
						{
							EType  SType           ;
							void*  Next            ;
							uint32 MaxVariableCount;
						};
					};

					/**
					 * @brief Create a descriptor set layout.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDescriptorSetLayout">Specification</a> 
					 * 
					 * @ingroup APISpec_Resource_Descriptors
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _allocator
					 * \param _setLayout
					 * \return 
					 */
					static EResult Create
					(
						      LogicalDevice::Handle        _deviceHandle,
						const CreateInfo&                  _createInfo  ,
						const Memory::AllocationCallbacks* _allocator   ,
						      Handle&                      _setLayout
					)
					{
						return EResult(vkCreateDescriptorSetLayout(_deviceHandle, _createInfo, *_allocator, &_setLayout));
					}

					/**
					 * @brief Destroy a descriptor set layout.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDescriptorSetLayout">Specification</a> 
					 * 
					 * @ingroup APISpec_Resource_Descriptors
					 * 
					 * \param _deviceHandle
					 * \param _descriptorSet
					 * \param _allocator
					 */
					static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _descriptorSet, const Memory::AllocationCallbacks* _allocator)
					{
						vkDestroyDescriptorSetLayout(_deviceHandle, _descriptorSet, *_allocator);
					}

					/**
					 * @brief Query whether a descriptor set layout can be created.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDescriptorSetLayoutSupport">Specification</a> 
					 * 
					 * @ingroup APISpec_Resource_Descriptors
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


				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< @brief Reserved for future use.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineLayoutCreateInfo">Specification</a>  
				@ingroup APISpec_Resource_Descriptors
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineLayoutCreateInfo, EStructureType::Pipeline_Layout_CreateInfo>
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
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreatePipelineLayout">Specification</a> 
				 * 
				 * @ingroup APISpec_Resource_Descriptors
				 * 
				 * \param _deviceHandle
				 * \param _creationSpec
				 * \param _allocator
				 * \param _pipelineLayout
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle  ,
					const CreateInfo&                  _creationSpec  ,
					const Memory::AllocationCallbacks* _allocator     ,
					      Handle&                      _pipelineLayout
				)
				{
					return EResult(vkCreatePipelineLayout(_deviceHandle, _creationSpec, *_allocator, &_pipelineLayout));
				}

				/**
				 * @brief Destroy a pipeline layout.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyPipelineLayout">Specification</a> 
				 * 
				 * @ingroup APISpec_Resource_Descriptors
				 * 
				 * \param _deviceHandle
				 * \param _pipelineLayout
				 * \param _allocator
				 */
				static void Destroy
				(
					      LogicalDevice::Handle        _deviceHandle  ,
					      Handle                       _pipelineLayout,
					const Memory::AllocationCallbacks* _allocator
				)
				{
					vkDestroyPipelineLayout(_deviceHandle, _pipelineLayout, *_allocator);
				}
			};

			/** 
			@brief Structure specifying parameters of a newly created pipeline multisample state.
			@ingroup APISpec_Rasterization
			*/
			struct MultiSampleState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampleMask">Specification</a>  
				@ingroup APISpec_Rasterization
				*/
				using SampleMask = VkSampleMask;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineMultisampleStateCreateInfo">Specification</a>  
				@ingroup APISpec_Rasterization
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineMultisampleStateCreateInfo, EStructureType::Pipeline_MultisampleState_CreateInfo>
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

			/** 
			@brief Rasterization is the process by which a primitive is converted to a two-dimensional image. 
			Each point of this image contains associated data such as depth, color, or other attributes.
			@ingroup APISpec_Rasterization
			*/
			struct RasterizationState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCullModeFlags">Specification</a>  
				@ingroup APISpec_Rasterization
				*/
				using CullModeFlags = Bitmask<ECullModeFlag, VkCullModeFlags>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineRasterizationStateCreateInfo">Specification</a>  
				@ingroup APISpec_Rasterization
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineRasterizationStateCreateInfo, EStructureType::Pipeline_RasterizationState_CreateInfo>
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

			@ingroup APISpec_Pipelines
			*/
			struct Specialization
			{
				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationMapEntry">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				struct MapEntry : V0::VKStruct_Base<VkSpecializationMapEntry>
				{
					uint32   ConstantID;
					uint32   Offset    ;
					WordSize Size      ;
				};

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationInfo">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				struct Info : V0::VKStruct_Base<VkSpecializationInfo>
				{
					      uint32    MapEntryCount;
					const MapEntry* MapEntires   ;
					      WordSize  SizeOfData   ;
					const void*     Data         ;
				};
			};

			/**
			 * @brief Used to handle shader staging within a pipeline, more than one shader can be staged in a pipeline.
			 * 
			 * @ingroup APISpec_Pipelines
			 */
			struct ShaderStage
			{
				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderStageFlags">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				using CreateFlags = Bitmask<EPipelineShaderStageCreateFlag, VkShaderStageFlags>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineShaderStageCreateInfo">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineShaderStageCreateInfo , EStructureType::Pipeline_ShaderStage_CreateInfo>
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
			
			/** 
			@brief Tessellation involves three pipeline stages. 
			
			@details 
			First, a tessellation control shader transforms control points of a patch and can produce per-patch data.
			Second, a fixed-function tessellator generates multiple primitives corresponding to a tessellation of the patch in (u,v) or (u,v,w) parameter space. 
			Third, a tessellation evaluation shader transforms the vertices of the tessellated patch, for example to compute their positions and attributes as part of the 
			tessellated surface. The tessellator is enabled when the pipeline contains both a tessellation control shader and a tessellation evaluation shader.

			@ingroup APISpec_Tessellation
			*/
			struct TessellationState
			{
				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineTessellationStateCreateFlags">Specification</a>  
				@ingroup APISpec_Tessellation
				*/
				using CreateFlags = Bitmask<EUndefined, VkPipelineTessellationStateCreateFlags>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineTessellationStateCreateInfo">Specification</a>  
				@ingroup APISpec_Tessellation
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineTessellationStateCreateInfo, EStructureType::Pipeline_TessellationState_CreateInfo>
				{
					      EType       SType             ;
					const void*       Next              ;
					      CreateFlags Flags             ;
					      uint32      PatchControlPoints;
				};
			};

			/**
			 * @brief .
			 * @ingroup APISpec_Fixed-Function_Vertex_Processing
			 */
			struct VertexInputState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkVertexInputAttributeDescription">Specification</a>  
				@ingroup APISpec_Fixed-Function_Vertex_Processing
				*/
				struct AttributeDescription : V0::VKStruct_Base<VkVertexInputAttributeDescription>
				{
					uint32  Location;
					uint32  Binding ;
					EFormat Format  ;
					uint32  Offset  ;
				};

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkVertexInputBindingDescription">Specification</a>
				@ingroup APISpec_Fixed-Function_Vertex_Processing
				*/
				struct BindingDescription : V0::VKStruct_Base<VkVertexInputBindingDescription>
				{
					uint32           Binding  ;
					uint32           Stride   ;
					EVertexInputRate InputRate;
				};

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineVertexInputStateCreateInfo">Specification</a>  
				@ingroup APISpec_Fixed-Function_Vertex_Processing
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineVertexInputStateCreateInfo, EStructureType::Pipeline_VertexInputState_CreateInfo>
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

			/** 
			@brief The viewport transformation is determined by the selected viewport’s width and height in pixels, px and py, respectively, 
			and its center (ox, oy) (also in pixels), as well as its depth range min and max determining a depth range scale value pz and 
			a depth range bias value oz (defined below). 

			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vertexpostproc-viewport">Specification</a> 

			@ingroup APISpec_Fixed-Function_Vertex_Post-Processing
			*/
			struct ViewportState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineViewportStateCreateInfo">Specification</a>  
				@ingroup APISpec_Fixed-Function_Vertex_Post-Processing
				*/
				struct CreateInfo : V0::VKStruct_Base<VkPipelineViewportStateCreateInfo, EStructureType::Pipeline_ViewportState_CreateInfo>
				{
					      EType       SType        ;
					const void*       Next         ;
					      CreateFlags Flags        ;
					      uint32      ViewportCount;
					const Viewport*   Viewports    ;
					      uint32      ScissorCount ;
					const Rect2D*     Scissors     ;
				};
			};

			/**
			 * @brief The compute pipeline represents a compute shader.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-compute">Specification</a> 
			 * 
			 * @ingroup APISpec_Pipelines
			 */
			struct Compute
			{
				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCreateFlags">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				using CreateFlags = Bitmask<EPipelineCreateFlag, VkPipelineCreateFlags>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkComputePipelineCreateInfo">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				struct CreateInfo : V0::VKStruct_Base<VkComputePipelineCreateInfo, EStructureType::ComputePipeline_CreateInfo>
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
				 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateComputePipelines">Specification</a> 
				 * 
				 * @ingroup APISpec_Pipelines
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
					      LogicalDevice::Handle        _deviceHandle   ,
					      Cache::Handle                _cache          ,
					      uint32                       _createInfoCount,
					const CreateInfo*                  _createInfos    ,
					const Memory::AllocationCallbacks* _allocator      ,
					      Handle*                      _pipelines
				)
				{
					return EResult(vkCreateComputePipelines(_deviceHandle, _cache, _createInfoCount, *_createInfos, *_allocator, _pipelines));
				}
			};

			/**
			 * @brief Graphics pipelines consist of multiple shader stages, multiple fixed-function pipeline stages, and a pipeline layout.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-graphics">Specification</a> 
			 * 
			 * @ingroup APISpec_Pipelines
			 */
			struct Graphics
			{
				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCreateFlags">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				using CreateFlags = Bitmask<EPipelineCreateFlag, VkPipelineCreateFlags>;

				/** 
				@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsPipelineCreateInfo">Specification</a>  
				@ingroup APISpec_Pipelines
				*/
				struct CreateInfo : V0::VKStruct_Base<VkGraphicsPipelineCreateInfo, EStructureType::GraphicsPipeline_CreateInfo>
				{
					using RenderPass_Handle = VkRenderPass;   // RenderPass::Handle not defined yet. (Defined in VT_RenderPass.hpp)

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
					const MultiSampleState::CreateInfo*   MultisampleState  ;
					const DepthStencilState::CreateInfo*  DepthStencilState ;
					const ColorBlendState::CreateInfo*    ColorBlendState   ;
					const DynamicState::CreateInfo*       DynamicState      ;
					      Pipeline::Layout::Handle        Layout            ;
					      RenderPass_Handle               RenderPass        ;
					      uint32                          Subpass           ;
					      Pipeline::Handle                BasePipelineHandle;
					      sint32                          BasePipelineIndex ;
				};

				/**
				 * @brief Graphics pipelines can contain multiple shader groups that can be bound individually. \
				 * Each shader group behaves as if it was a pipeline using the shader groups state.
				 * 
				 * @details
				 *  When the pipeline is bound by regular means, it behaves as if the state of group 0 is active, 
				 * use vkCmdBindPipelineShaderGroupNV to bind an individual shader group. The primary purpose 
				 * of shader groups is allowing the device to bind different pipeline state using Device-Generated Commands.
				 * 
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#graphics-shadergroups">Specification</a> 
				 * 
				 * @ingroup APISpec_Pipelines
				 */
				struct ShaderGroup 
				{
					/** 
					@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsShaderGroupCreateInfoNV">Specification</a>  
					@ingroup APISpec_Pipelines
					*/
					struct CreateInfo : V0::VKStruct_Base<VkGraphicsShaderGroupCreateInfoNV, EStructureType::GraphicsShaderGroup_CreateInfo_NV>
					{
						      EType                          SType            ;
						const void*                          Next             ;
						      uint32                         StageCount       ;
						const ShaderStage::CreateInfo*       Stages           ;
						const VertexInputState::CreateInfo*  VertexInputState ;
						const TessellationState::CreateInfo* TessellationState;
					};

					/** 
					@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsPipelineShaderGroupsCreateInfoNV">Specification</a>  
					@ingroup APISpec_Pipelines
					*/
					struct MultipleCreateInfo : V0::VKStruct_Base<VkGraphicsPipelineShaderGroupsCreateInfoNV, EStructureType::GraphicsPipeline_ShaderGroups_CreateInfo_NV>
					{
						      EType             SType;
						const void*             Next;
						      uint32            GroupCount;
						const CreateInfo*       Groups;
						      uint32            PipelineCount;
						const Pipeline::Handle* Pipelines;
					};
				};

				/**
				 * @brief Create a graphics pipeline.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateGraphicsPipelines">Specification</a> 
				 * 
				 * @ingroup APISpec_Pipelines
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
					      LogicalDevice::Handle        _deviceHandle   ,
					      Cache::Handle                _pipelineCache  ,
					      uint32                       _createInfoCount,
					const CreateInfo*                  _createInfos    ,
					const Memory::AllocationCallbacks* _allocator      ,
					      Handle*                      _pipelines
				)
				{
					return EResult(vkCreateGraphicsPipelines(_deviceHandle, _pipelineCache, _createInfoCount, *_createInfos, *_allocator, _pipelines));
				}
			};

			/**
			 * @brief Destroy a pipeline object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyPipeline">Specification</a> 
			 * 
			 * @ingroup APISpec_Pipelines
			 * 
			 * \param _deviceHandle
			 * \param _pipeline
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipeline, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyPipeline(_deviceHandle, _pipeline, *_allocator);
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

		struct Pipeline : public V1::Pipeline
		{
			using Parent = V1::Pipeline;

			struct Cache : public Parent::Cache
			{
				using Parent = Parent::Cache;

				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::Cache::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				* @brief Create a pipeline cache (Uses the default allocator).
				* 
				* \param _deviceHandle
				* \param _createInfo
				* \param _pipelineCache
				* \return 
				*/
				static EResult Create
				(
					      LogicalDevice::Handle  _deviceHandle ,
					const CreateInfo&            _createInfo   ,
					      Cache::Handle&         _pipelineCache
				)
				{
					return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _pipelineCache);
				}

				using Parent::Create;

				/**
				 * @brief Destroy a pipeline cache.
				 * 
				 * @details

				 * \param _deviceHandle
				 * \param _cache
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Cache::Handle _cache)
				{
					Parent::Destroy(_deviceHandle, _cache, Memory::DefaultAllocator);
				}

				using Parent::Destroy;
			};

			/**
			@brief Blending combines the incoming source fragment’s R, G, B, and A values with the destination R, G, B, and A values of each sample stored in the framebuffer 
			at the fragment’s (xf,yf) location. Blending is performed for each color sample covered by the fragment, rather than just once for each fragment.
			*/
			struct ColorBlendState : public Parent::ColorBlendState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::ColorBlendState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct DepthStencilState : public Parent::DepthStencilState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::DepthStencilState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
						
						MinDepthBounds = 0;
						MaxDepthBounds = 0;
					}
				};
			};
			
			struct DynamicState : public Parent::DynamicState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::DynamicState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct InputAssemblyState : public Parent::InputAssemblyState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::InputAssemblyState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Layout : public Parent::Layout
			{
				using Parent = Parent::Layout;

				struct DescriptorSet : public Parent::DescriptorSet
				{
					using Parent = Parent::DescriptorSet;

					struct Binding : public Parent::Binding
					{
						/**
						@brief Offers a default constructor.
						*/
						struct FlagsCreateInfo : public Parent::Binding::FlagsCreateInfo
						{
							FlagsCreateInfo()
							{
								SType = STypeEnum;
								Next  = nullptr  ;
							}
						};
					};

					/**
					@brief Offers a default constructor.
					*/
					struct CreateInfo : public Parent::CreateInfo
					{
						CreateInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					/**
					@brief Offers a default constructor.
					*/
					struct Support : public Parent::Support
					{
						Support()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}

						/**
						@brief Offers a default constructor.
						*/
						struct SetVariableCount : public Parent::Support::SetVariableCount
						{
							SetVariableCount()
							{
								SType = STypeEnum;
								Next  = nullptr  ;
							}
						};
					};

					/**
					 * @brief Create a descriptor set layout.
					 * 
					 * @details
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _setLayout
					 * \return 
					 */
					static EResult Create
					(
						      LogicalDevice::Handle _deviceHandle,
						const CreateInfo&           _createInfo  ,
						      Handle&               _setLayout
					)
					{
						return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _setLayout);
					}

					using Parent::Create;

					/**
					 * @brief Destroy a descriptor set layout.
					 * 
					 * @details
					 * 
					 * \param _deviceHandle
					 * \param _descriptorSet
					 */
					static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _descriptorSet)
					{
						Parent::Destroy(_deviceHandle, _descriptorSet, Memory::DefaultAllocator);
					}

					using Parent::Destroy;
				};

				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::Layout::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				* @brief Create a pipeline layout.
				* 
				* @details
				* 
				* \param _deviceHandle
				* \param _creationSpec
				* \param _pipelineLayout
				* \return 
				*/
				static EResult Create
				(
						  LogicalDevice::Handle _deviceHandle  ,
					const CreateInfo&           _creationSpec  ,
						  Handle&               _pipelineLayout
				)
				{
					return Parent::Create(_deviceHandle, _creationSpec, Memory::DefaultAllocator, _pipelineLayout);
				}

				using Parent::Create;

				/**
				 * @brief Destroy a pipeline layout.
				 * 
				 * @details
				 * 
				 * \param _deviceHandle
				 * \param _pipelineLayout
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipelineLayout)
				{
					Parent::Destroy(_deviceHandle, _pipelineLayout, Memory::DefaultAllocator);
				}

				using Parent::Destroy;
			};

			struct MultiSampleState : public Parent::MultiSampleState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::MultiSampleState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct RasterizationState : public Parent::RasterizationState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::RasterizationState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct ShaderStage : public Parent::ShaderStage
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::ShaderStage::CreateInfo
				{
					CreateInfo()
					{
						SType          = STypeEnum;
						Next           = nullptr  ;
						Module         = Null<ShaderModule::Handle>;
						Name           = nullptr;
						Specialization = nullptr;
					}
				};
			};

			struct TessellationState : public Parent::TessellationState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::TessellationState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct VertexInputState : public Parent::VertexInputState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::VertexInputState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct ViewportState : public Parent::ViewportState
			{
				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::ViewportState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Compute : public Parent::Compute
			{
				using Parent = Parent::Compute;

				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::Compute::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				 * @brief Create a compute pipeline.
				 * 
				 * @details 
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle   ,
					      Cache::Handle                _cache          ,
					      uint32                       _createInfoCount,
					const CreateInfo*                  _createInfos    ,
					      Handle*                      _pipelines
				)
				{
					return Parent::Create(_deviceHandle, _cache, _createInfoCount, _createInfos, Memory::DefaultAllocator, _pipelines);
				}

				using Parent::Create;
			};

			struct Graphics : public Parent::Graphics
			{
				using Parent = Parent::Graphics;

				/**
				@brief Offers a default constructor.
				*/
				struct CreateInfo : public Parent::Graphics::CreateInfo
				{
					CreateInfo() 
					{
						SType              = STypeEnum;
						Next               = nullptr  ;
						StageCount         = 0;
						Stages             = nullptr;
						VertexInputState   = nullptr;
						InputAssemblyState = nullptr;
						TessellationState  = nullptr;
						ViewportState      = nullptr;
						RasterizationState = nullptr;
						MultisampleState   = nullptr;
						DepthStencilState  = nullptr;
						ColorBlendState    = nullptr;
						DynamicState       = nullptr;
						Layout             = Null<Layout::Handle>   ;
						RenderPass         = Null<RenderPass_Handle>;
						Subpass            = 0                      ;
						BasePipelineHandle = Null<Pipeline::Handle> ;
						BasePipelineIndex  = 0                      ;
					}
				};

				struct ShaderGroup : public Parent::Graphics::ShaderGroup
				{
					/**
					@brief Offers a default constructor.
					*/
					struct CreateInfo : public Parent::Graphics::ShaderGroup::CreateInfo
					{
						CreateInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					/**
					@brief Offers a default constructor.
					*/
					struct MultipleCreateInfo : public Parent::Graphics::ShaderGroup::MultipleCreateInfo
					{
						MultipleCreateInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};
				};

				/**
				 * @brief Create a graphics pipeline.
				 * 
				 * @details
				 * 
				 * \param _deviceHandle
				 * \param _pipelineCache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle _deviceHandle   ,
					      Cache::Handle         _pipelineCache  ,
					      uint32                _createInfoCount,
					const CreateInfo*           _createInfos    ,
					      Handle*               _pipelines
				)
				{
					return Parent::Create(_deviceHandle, _pipelineCache, _createInfoCount, _createInfos, Memory::DefaultAllocator, _pipelines);
				}

				using Parent::Create;
			};

			/**
			 * @brief Destroy a pipeline object.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _pipeline
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipeline)
			{
				Parent::Destroy(_deviceHandle, _pipeline, Memory::DefaultAllocator);
			}
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		class Pipeline : public V2::Pipeline
		{
		public:
			using Parent = V2::Pipeline;

			class Cache : public Parent::Cache
			{
			public:
				using Parent = V2::Pipeline::Cache;

				EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
				{
					device    = &_device                ;
					allocator = Memory::DefaultAllocator;

					return Parent::Create(*device, _info, allocator, handle);
				}

				EResult Create(const LogicalDevice& _device, CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
				{
					device    = &_device   ;
					allocator = &_allocator;

					return Parent::Create(*device, _info, allocator, handle);
				}

				void Destroy()
				{
					Parent::Destroy(*device, handle, allocator);
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

				bool operator== (const Cache& _other) const
				{
					return handle == _other.handle;
				}

			protected:

				Handle handle;

				const Memory::AllocationCallbacks* allocator;
				
				const LogicalDevice* device;
			};

			class Layout : public Parent::Layout
			{
			public:
				using Parent = V2::Pipeline::Layout;

				class DescriptorSet : public Parent::DescriptorSet
				{
				public:
					using Parent = V2::Pipeline::Layout::DescriptorSet;

					void Assign(const LogicalDevice& _device, const CreateInfo& _info)
					{
						device    = &_device                ;
						info      = _info                   ;
						allocator = Memory::DefaultAllocator;

						Parent::GetSupport(*device, info, support);
					}

					void Assign(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
					{
						device    = &_device   ;
						info      = _info      ;
						allocator = &_allocator;

						Parent::GetSupport(*device, info, support);
					}

					EResult Create()
					{
						return Parent::Create(*device, info, allocator, handle);
					}

					void Destroy()
					{
						Parent::Destroy(*device, handle, allocator);
					}

					const Support& GetSupport() const
					{
						return support;
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

					bool operator== (const DescriptorSet& _other) const
					{
						return handle == _other.handle;
					}

				protected:

					Handle handle;

					const Memory::AllocationCallbacks* allocator;

					CreateInfo info;

					const LogicalDevice* device;

					Support support;
				};

				EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
				{
					device    = &_device                ;
					allocator = Memory::DefaultAllocator;

					return Parent::Create(*device, _info, allocator, handle);
				}

				EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
				{
					device    = &_device   ;
					allocator = &_allocator;

					return Parent::Create(*device, _info, allocator, handle);
				}

				void Destroy()
				{
					Parent::Destroy(*device, handle, allocator);
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

				bool operator== (const Layout& _other) const
				{
					return handle == _other.handle;
				}

			protected:

				Handle handle;

				const Memory::AllocationCallbacks* allocator;

				const LogicalDevice* device;
			};

			void Destroy()
			{
				Parent::Destroy(*device, handle);
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

			bool operator== (const Pipeline& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const Cache* cache;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		class ComputePipeline : public Pipeline
		{
		public:

			using CreateInfo = Parent::Compute::CreateInfo;

			void Assign
			(
				const LogicalDevice&               _device   ,
				const Cache&                       _cache    ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle                       _handle
			)
			{
				handle    = _handle   ;
				allocator = _allocator;
				cache     = &_cache   ;
				device    = &_device  ;
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device;
				cache     = nullptr ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Compute::Create
				(
					*device            ,
					Null<Cache::Handle>,
					1                  ,
					&_info             ,
					allocator          ,
					&handle
				);
			}

			EResult Create(const LogicalDevice& _device, const Cache& _cache, const CreateInfo& _info)
			{
				device    = &_device;
				cache     = &_cache ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Compute::Create
				(
					*device  ,
					*cache   ,
					1        ,
					&_info   ,
					allocator,
					&handle
				);
			}

			EResult Create
			(
				const LogicalDevice&               _device   , 
				const Cache&                       _cache    , 
				const CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = &_device  ;
				cache     = &_cache   ;
				allocator = _allocator;

				return Parent::Parent::Compute::Create
				(
					*device  ,
					*cache   ,
					1        ,
					&_info   ,
					allocator,
					&handle
				);
			}

			static EResult Create
			(
				const LogicalDevice&                 _device         ,
				const Cache&                         _cache          ,
				      uint32                         _createInfoCount,
				const CreateInfo*                    _createInfos    ,
				const Memory::AllocationCallbacks*   _allocator      ,
				      DynamicArray<ComputePipeline>& _pipelines
			)
			{
				_pipelines.resize(_createInfoCount);

				Handle* handles;

				EResult returnCode = 
					Parent::Parent::Compute::Create
					(
						_device         ,
						_cache          ,
						_createInfoCount,
						_createInfos    ,
						_allocator      ,
						handles
					);

				if (returnCode != EResult::Success) return returnCode;

				int index = 0;

				for (auto pipeline : _pipelines)
				{
					pipeline.Assign(_device, _cache, _allocator, handles[index]);
				}

				return returnCode;
			}
		};

		class GraphicsPipeline : public Pipeline
		{
		public:
			using CreateInfo = Parent::Graphics::CreateInfo;

			void Assign
			(
				const LogicalDevice&               _device   ,
				const Cache&                       _cache    ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle                       _handle
			)
			{
				handle    = _handle   ;
				allocator = _allocator;
				cache     = &_cache   ;
				device    = &_device  ;
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device;
				cache     = nullptr ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Graphics::Create
				(
					*device            ,
					Null<Cache::Handle>,
					1                  ,
					&_info             ,
					allocator          ,
					&handle
				);
			}

			EResult Create(const LogicalDevice& _device, Cache& _cache, const CreateInfo& _info)
			{
				device    = &_device;
				cache     = &_cache ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Graphics::Create
				(
					*device,
					*cache             ,
					1                  ,
					&_info             ,
					allocator          ,
					&handle
				);
			}

			EResult Create
			(
				const LogicalDevice&               _device   , 
				const Cache&                       _cache    , 
				      CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = &_device  ;
				cache     = &_cache   ;
				allocator = _allocator;

				return Parent::Parent::Graphics::Create
				(
					*device            ,
					*cache             ,
					1                  ,
					&_info             ,
					allocator          ,
					&handle
				);
			}

			static EResult Create
			(
				const LogicalDevice&                  _device         ,
				const Cache&                          _cache          ,
				      uint32                          _createInfoCount,
				const CreateInfo*                     _createInfos    ,
				const Memory::AllocationCallbacks*    _allocator      ,
				      DynamicArray<GraphicsPipeline>& _pipelines
			)
			{
				_pipelines.resize(_createInfoCount);

				Handle* handles;

				EResult returnCode = 
					Parent::Parent::Graphics::Create
					(
						_device         ,
						_cache          ,
						_createInfoCount,
						_createInfos    ,
						_allocator      ,
						handles
					);

				if (returnCode != EResult::Success) return returnCode;

				int index = 0;

				for (auto pipeline : _pipelines)
				{
					pipeline.Assign(_device, _cache, _allocator, handles[index]);
				}

				return returnCode;
			}
		};

		/** @} */
	}
}
