#pragma once



#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_ShaderModule.hpp"



namespace Vulkan
{
	namespace Vault_01
	{
		struct Pipeline
		{
			using ShaderStageFlags = Bitmask<EShaderStageFlag, Flags>;

			/*
			Specialization constants are a mechanism whereby constants in a SPIR-V module can have their constant value specified 
			at the time the VkPipeline is created. This allows a SPIR-V module to have constants that can be modified 
			while executing an application that uses the Vulkan API.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationMapEntry
			*/
			struct Specialization
			{
				struct MapEntry : Vault_00::VKStruct_Base<VkSpecializationMapEntry>
				{
					uint32   ConstantID;
					uint32   Offset    ;
					DataSize Size      ;
				};

				struct Info : Vault_00::VKStruct_Base<VkSpecializationInfo>
				{
					      uint32    MapEntryCount;
					const MapEntry* MapEntires   ;
					      DataSize  SizeOfData   ;
					const void*     Data         ;
				};
			};

			struct ColorBlend
			{
				struct AttachmentState
				{
					Bool                EnableBlend;
					EBlendFactor        Source_ColorBlendFactor;
					EBlendFactor        Destination_ColorBlendFactor;
					EBlendOperation     ColorOperation;
					EBlendFactor        Source_AlphaBlendFactor;
					EBlendFactor        Destination_AlphaBlendFactor;
					EBlendOperation     AlphaOperation;
					ColorComponentFlags ColorWriteMask;
				};

				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				struct CreateInfo
				{
					EStructureType SType;
					const void* Extension;
					CreateFlags Flags;
					Bool EnableLogicOperations;
					ELogicOperation LogicOperation;
					uint32 AttachmentCount;
					const AttachmentState* Attachments;
					float BlendConstants[4];
				};
			};

			struct DynamicState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				struct CreateInfo
				{
					EStructureType SType;
					const void* Extension;
					CreateFlags Flags;
					uint32 StateCount;
					const EDynamicState* States;
				};
			};

			struct InputAssembly
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				struct CreateInfo
				{
						  EStructureType     SType                 ;
					const void*              Extension             ;
						  CreateFlags        Flags                 ;
						  EPrimitiveTopology Topology              ;
						  Bool               PrimitiveRestartEnable;
				};
			};

			struct Layout
			{
				using Handle = VkPipelineLayout;

				struct PushConstantRange
				{
					ShaderStageFlags StageFlags;
					uint32 Offset;
					uint32 Size;
				};

				struct DescriptorSet
				{
					using Handle = VkDescriptorSetLayout;

					struct Binding
					{
						uint32 Binding;
						EDescriptorType Type;
						uint32 Count;
						ShaderStageFlags StageFlags;
						const Sampler::Handle* ImmutableSamplers;
					};

					using CreateFlags = Bitmask<EDescriptorSetLayoutCreateFlag, Flags>;

					struct CreateInfo
					{
						EStructureType SType;
						const void* Extension;
						CreateFlags Flags;
						uint32 BindingCount;
						const Binding* Bindings;
					};
				};

				using CreateFlags = Bitmask<EUndefined, Flags>;

				struct CreateInfo
				{
					EStructureType SType;
					const void* Extension;
					CreateFlags Flags;
					uint32 SetLayoutCount;
					const DescriptorSet::Handle* SetLayouts;
					uint32 PushConstantRangeCount;
					const PushConstantRange* PushConstantRanges;
				};
			};

			struct MultisampleState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				struct CreateInfo
				{
					EStructureType SType;
					const void* Extension;
					CreateFlags Flags;
					ESampleCount RasterizationSamples;
					Bool EnableSampleShading;
					float MinSampleShading;
					const VkSampleMask* SampleMask;
					Bool EnableAlphaToCoverage;
					Bool EnableAlphaToOne;
				};
			};

			struct RasterizationState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				struct CreateInfo
				{
						  EStructureType SType                  ;
					const void*          Extension              ;
						  CreateFlags    Flags                  ;
						  Bool           EnableDepthClamp       ;
						  Bool           EnableRasterizerDiscard;
						  EPolygonMode   PolygonMode            ;
						  CullModeFlags  CullMode               ;
						  EFrontFace     FrontFace              ;
						  Bool           EnableDepthBias        ;
						  float          DepthBiasConstantFactor;
						  float          DepthBiasClamp         ;
						  float          DepthBiasSlopeFactor   ;
						  float          LineWidth              ;
				};
			};

			struct ShaderStage
			{
				using CreateFlags = Bitmask<EPipelineShaderStageCreateFlag, Flags>;

				struct CreateInfo
				{
						  EStructureType       SType         ;
					const void*                Extenions     ;
						  CreateFlags          Flags         ;
						  EShaderStageFlag     Stage         ;
						  ShaderModule::Handle Module        ;
						  RoCStr               Name          ;
					const Specialization::Info*  Specialization;

					operator VkShaderModuleCreateInfo()
					{
						return *reinterpret_cast<VkShaderModuleCreateInfo*>(this);
					}
				};
			};

			struct VertexInputState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				struct AttributeDescription
				{
					uint32       Location;
					uint32       Binding ;
					EImageFormat Format  ;
					uint32       Offset  ;
				};

				struct BindingDescription
				{
					uint32           Binding  ;
					uint32           Stride   ;
					EVertexInputRate InputRate;
				};

				struct CreateInfo
				{
						  EStructureType        SType                        ;
					const void*                 Extension                    ;
						  CreateFlags           Flags                        ;
						  uint32                VertexBindingDescriptionCount;
					const BindingDescription*   BindingDescriptions          ;
						  uint32                AttributeDescriptionCount    ;
					const AttributeDescription* AttributeDescription         ;
				};
			};

			struct ViewportState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				struct CreateInfo
				{
						  EStructureType SType        ;
					const void*          Extension    ;
						  uint32         ViewportCount;
					const Viewport*      Viewports    ;
						  uint32         ScissorCount ;
					const Rect2D*        Scissors     ;
				};
			};


			static EResult CreateLayout
			(
					  LogicalDevice::Handle         _device        ,
				const Pipeline::Layout::CreateInfo& _creationSpec  ,
				const AllocationCallbacks*          _allocator     ,
					  Pipeline::Layout::Handle&     _pipelineLayout
			)
			{
				return EResult(vkCreatePipelineLayout(_device, (VkPipelineLayoutCreateInfo*)(&_creationSpec), _allocator, &_pipelineLayout) );
			}

			static void DestroyLayout
			( 
				      LogicalDevice::Handle    _device,
				      Pipeline::Layout::Handle _pipelineLayout,
				const AllocationCallbacks*     _allocator
			)
			{
				vkDestroyPipelineLayout(_device, _pipelineLayout, _allocator);
			}
		};

		
	}
}



