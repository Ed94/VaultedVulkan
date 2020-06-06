#pragma once



#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_ShaderModule.hpp"



namespace Vulkan
{
	struct Pipeline
	{
		using ShaderStageFlags = Bitmask<EShaderStageFlag, Flags>;

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
				const SpecializationInfo*  Specialization;

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
	};

	EResult Pipeline_CreateLayout
	(
		      LogicalDevice::Handle         _device        ,
		const Pipeline::Layout::CreateInfo& _creationSpec  ,
		const AllocationCallbacks*          _allocator     ,
		      Pipeline::Layout::Handle&     _pipelineLayout
	)
	{
		return EResult(vkCreatePipelineLayout(_device, (VkPipelineLayoutCreateInfo*)(&_creationSpec), _allocator, &_pipelineLayout) );
	}

	void Pipeline_DestroyLayout
	( 
		LogicalDevice::Handle _device,
		Pipeline::Layout::Handle _pipelineLayout,
		const AllocationCallbacks* _allocator
	)
	{
		vkDestroyPipelineLayout(_device, _pipelineLayout, _allocator);
	}
}



