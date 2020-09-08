/*!
@file VT_Enums.hpp

@brief Vaulted Thermals: Enumerations
*/

#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
    namespace Corridors
    {
		/**
		@addtogroup Corridors
		@{
		*/

	#pragma region VT_Enums

		/** 
		@enum Undefined Enum
		@brief Necessary for Bitmasks in the Vulkan specification that are not defined but reserved for future use.
		*/
		enum class EUndefined : uint32 { VT_SpecifyBitmaskable = sizeof(uint32) };

		/**
		 * @enum Handle Enum
		 */
		enum class EHandle
		{
			Null = VK_NULL_HANDLE
		};

	#pragma endregion VT_Enums

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAccessFlagBits">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class EAccessFlag : uint32
		{
			IndirectCommandRead                 = VK_ACCESS_INDIRECT_COMMAND_READ_BIT                ,
			IndexRead                           = VK_ACCESS_INDEX_READ_BIT                           ,
			VertexAttributeRead                 = VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT                ,
			UniformRead                         = VK_ACCESS_UNIFORM_READ_BIT                         ,
			InputAttachmentRead                 = VK_ACCESS_INPUT_ATTACHMENT_READ_BIT                ,
			ShaderRead                          = VK_ACCESS_SHADER_READ_BIT                          ,
			ShaderWrite                         = VK_ACCESS_SHADER_WRITE_BIT                         ,
			ColorAttachmentRead                 = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT                ,
			ColorAttachmentWrite                = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT               ,
			DepthStencilAttachmentRead          = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT        ,
			DepthStencilAttachmentWrite         = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT       ,
			TransferRead                        = VK_ACCESS_TRANSFER_READ_BIT                        ,
			TransferWrite                       = VK_ACCESS_TRANSFER_WRITE_BIT                       ,
			HostRead                            = VK_ACCESS_HOST_READ_BIT                            ,
			HostWrite                           = VK_ACCESS_HOST_WRITE_BIT                           ,
			MemoryRead                          = VK_ACCESS_MEMORY_READ_BIT                          ,
			MemoryWrite                         = VK_ACCESS_MEMORY_WRITE_BIT                         ,
			TransformFeedback_Write_EXT         = VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT         ,   // Provided by VK_EXT_transform_feedback
			TransformFeedback_CounterRead_EXT   = VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT  ,   // Provided by VK_EXT_transform_feedback
			TransformFeedback_CounterWrite_EXT  = VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT ,   // Provided by VK_EXT_transform_feedback
			ConditionalRendering_Read_EXT       = VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT       ,   // Provided by VK_EXT_conditional_rendering
			ColorAttachment_ReadNoncoherent_EXT = VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT,   // Provided by VK_EXT_blend_operation_advanced
			AccelerationStructure_Read_KHR      = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR      ,   // Provided by VK_KHR_ray_tracing
			AccelerationStructure_Write_KHR     = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR     ,   // Provided by VK_KHR_ray_tracing
			ShadingRateImage_Read_NV            = VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV           ,   // Provided by VK_NV_shading_rate_image
			FragmentDensityMap_Read_EXT         = VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT        ,   // Provided by VK_EXT_fragment_density_map
			CommandPreprocess_Read_NV           = VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV           ,   // Provided by VK_NV_device_generated_commands
			CommandPreprocess_Write_NV          = VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV          ,   // Provided by VK_NV_device_generated_commands
			AccelerationStructure_Read_NV       = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_NV       ,   // Provided by VK_NV_ray_tracing
			AccelerationStructure_Write_NV      = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_NV      ,   // Provided by VK_NV_ray_tracing

			VT_SpecifyBitmaskable = VK_ACCESS_FLAG_BITS_MAX_ENUM
		};

		/**
		 * @enum API_Version
		 * 
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#extendingvulkan-coreversions-versionnumbers">Specification</a> 
		 * 
		 * @ingroup APISpec_Extending_Vulkan
		 */
		enum class EAPI_Version
		{
			_1_0 = VK_API_VERSION_1_0,
			_1_1 = VK_API_VERSION_1_1,
			_1_2 = VK_API_VERSION_1_2
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescriptionFlagBits">Specification</a> @ingroup APISpec_Render_Pass */
		enum class EAttachmentDescriptionFlag : uint32
		{
			AttachmentDescription_MAY_ALIAS = VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT,

			VT_SpecifyBitmaskable = VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentLoadOp">Specification</a> @ingroup APISpec_Render_Pass */
		enum class EAttachmentLoadOperation : uint32
		{
			Load     = VK_ATTACHMENT_LOAD_OP_LOAD     , 
			Clear    = VK_ATTACHMENT_LOAD_OP_CLEAR    ,
			DontCare = VK_ATTACHMENT_LOAD_OP_DONT_CARE 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentStoreOp">Specification</a> @ingroup APISpec_Render_Pass */
		enum class EAttachmentStoreOperation : uint32
		{
			Store    = VK_ATTACHMENT_STORE_OP_STORE    ,
			DontCare = VK_ATTACHMENT_STORE_OP_DONT_CARE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBlendFactor">Specification</a> @ingroup APISpec_The_Framebuffer */
		enum class EBlendFactor : uint32
		{
			Zero                      = VK_BLEND_FACTOR_ZERO                    ,
			One                       = VK_BLEND_FACTOR_ONE                     ,
			SourceColor               = VK_BLEND_FACTOR_SRC_COLOR               ,
			OneMinusOne_SourceColor   = VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR     ,
			DesinationColor           = VK_BLEND_FACTOR_DST_COLOR               ,
			OneMinus_DestinationColor = VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR     ,
			AlphaSource               = VK_BLEND_FACTOR_SRC_ALPHA               ,
			OneMinus_AlphaSource      = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA     ,
			AlphaDestination          = VK_BLEND_FACTOR_DST_ALPHA               ,
			OneMinus_AlphaDestination = VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA     ,
			ConstantColor             = VK_BLEND_FACTOR_CONSTANT_COLOR          ,
			OneMinus_ConstantColor    = VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR,
			ConstantAlpha             = VK_BLEND_FACTOR_CONSTANT_ALPHA          ,
			OneMinus_ConstantAlpha    = VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA,
			SourceAlphaSaturate       = VK_BLEND_FACTOR_SRC_ALPHA_SATURATE      ,
			SourceOne_Color           = VK_BLEND_FACTOR_SRC1_COLOR              ,
			OneMinus_SourceOneColor   = VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR    ,
			SourceOneAlpha            = VK_BLEND_FACTOR_SRC1_ALPHA              ,
			OneMinus_SourceOneAlpha   = VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA    
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBlendOp">Specification</a> @ingroup APISpec_The_Framebuffer */
		enum class EBlendOperation : uint32
		{
			Add                  = VK_BLEND_OP_ADD                   ,
			Subtract             = VK_BLEND_OP_SUBTRACT              ,
			ReverseSubtract      = VK_BLEND_OP_REVERSE_SUBTRACT      ,
			Mininum              = VK_BLEND_OP_MIN                   ,
			Maximum              = VK_BLEND_OP_MAX                   ,
			Zero_EXT             = VK_BLEND_OP_ZERO_EXT              ,
			Source_EXT           = VK_BLEND_OP_SRC_EXT               ,
			Destination_EXT      = VK_BLEND_OP_DST_EXT               ,
			SourceOver_EXT       = VK_BLEND_OP_SRC_OVER_EXT          ,
			DestinationOver_EXT  = VK_BLEND_OP_DST_OVER_EXT          ,
			SourceIn_EXT         = VK_BLEND_OP_SRC_IN_EXT            ,
			DestinationIN_ET     = VK_BLEND_OP_DST_IN_EXT            ,
			SourceOut_EXT        = VK_BLEND_OP_SRC_OUT_EXT           ,
			DestinationOut_EXT   = VK_BLEND_OP_DST_OUT_EXT           ,
			SourceAtop_EXT       = VK_BLEND_OP_SRC_ATOP_EXT          ,
			DestinationATop_EXT  = VK_BLEND_OP_DST_ATOP_EXT          ,
			XOR_EXT              = VK_BLEND_OP_XOR_EXT               ,
			Multiply_EXT         = VK_BLEND_OP_MULTIPLY_EXT          ,
			Screen_EXT           = VK_BLEND_OP_SCREEN_EXT            ,
			Overlay_EXT          = VK_BLEND_OP_OVERLAY_EXT           ,
			Darken_EXT           = VK_BLEND_OP_DARKEN_EXT            ,
			Lighten_EXT          = VK_BLEND_OP_LIGHTEN_EXT           ,
			ColorDodge_EXT       = VK_BLEND_OP_COLORDODGE_EXT        ,
			ColorBurn_EXT        = VK_BLEND_OP_COLORBURN_EXT         ,
			HardLight_EXT        = VK_BLEND_OP_HARDLIGHT_EXT         ,
			SoftLight_Ext        = VK_BLEND_OP_SOFTLIGHT_EXT         ,
			Difference_Ext       = VK_BLEND_OP_DIFFERENCE_EXT        ,
			Exclusion_Ext        = VK_BLEND_OP_EXCLUSION_EXT         ,
			Invert_Ext           = VK_BLEND_OP_INVERT_EXT            ,
			Invert_RGB_Ext       = VK_BLEND_OP_INVERT_RGB_EXT        ,
			LinearDodge_Ext      = VK_BLEND_OP_LINEARDODGE_EXT       ,
			LinearBurn_Ext       = VK_BLEND_OP_LINEARBURN_EXT        ,
			VividLight_Ext       = VK_BLEND_OP_VIVIDLIGHT_EXT        ,
			LinearLight_Ext      = VK_BLEND_OP_LINEARLIGHT_EXT       ,
			PinLight_Ext         = VK_BLEND_OP_PINLIGHT_EXT          ,
			Hardmix_Ext          = VK_BLEND_OP_HARDMIX_EXT           ,
			HSL_Hue_Ext          = VK_BLEND_OP_HSL_HUE_EXT           ,
			HSL_Saturation_Ext   = VK_BLEND_OP_HSL_SATURATION_EXT    ,
			HSL_Color_Ext        = VK_BLEND_OP_HSL_COLOR_EXT         ,
			HSL_Luminosity_Ext   = VK_BLEND_OP_HSL_LUMINOSITY_EXT    ,
			Plus_Ext             = VK_BLEND_OP_PLUS_EXT              ,
			PlusClamped_Ext      = VK_BLEND_OP_PLUS_CLAMPED_EXT      ,
			PlusClampedAlpha_Ext = VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT,
			PlusDarker_EXT       = VK_BLEND_OP_PLUS_DARKER_EXT       ,
			Minus_EXT            = VK_BLEND_OP_MINUS_EXT             ,
			MinusClamped_EXT     = VK_BLEND_OP_MINUS_CLAMPED_EXT     ,
			Constrast_EXT        = VK_BLEND_OP_CONTRAST_EXT          ,
			InvertOVG_EXT        = VK_BLEND_OP_INVERT_OVG_EXT        ,
			Red_EXT              = VK_BLEND_OP_RED_EXT               ,
			Green_EXT            = VK_BLEND_OP_GREEN_EXT             ,
			Blue_EXT             = VK_BLEND_OP_BLUE_EXT
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-commandsyntax">Specification</a> 
		 * 
		 * @ingroup APISpec_Fundamentals
		 */
		enum EBool
		{
			True  = VK_TRUE ,
			False = VK_FALSE
		};

		/** 
		@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBorderColor">Specification</a>  

		@ingroup APISpec_Samplers
		*/
		enum EBorderColor : uint32
		{
			Float_TransparentBlack = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK,
			Int_TransparentBlack   = VK_BORDER_COLOR_INT_TRANSPARENT_BLACK  ,
			Float_OpaqueBlack      = VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK     , 
			Int_OpaqueBlack        = VK_BORDER_COLOR_INT_OPAQUE_BLACK       , 
			Float_OpaqueWhite      = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE     , 
			Int_OpaqueWhite        = VK_BORDER_COLOR_INT_OPAQUE_WHITE       , 

			// Provided by VK_EXT_custom_border_color
			Float_Custom_EXT = VK_BORDER_COLOR_FLOAT_CUSTOM_EXT,

			// Provided by VK_EXT_custom_border_color
			Int_Custom_EXT = VK_BORDER_COLOR_INT_CUSTOM_EXT,
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateFlagBits">Specification</a> 
		 * 
		 * @ingroup APISpec_Resource_Creation
		 */
		enum class EBufferCreateFlag : uint32
		{
			SparseBinding                       = VK_BUFFER_CREATE_SPARSE_BINDING_BIT                   ,
			SparseResidency                     = VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT                 ,
			SparseAliased                       = VK_BUFFER_CREATE_SPARSE_ALIASED_BIT                   ,
			Protected                           = VK_BUFFER_CREATE_PROTECTED_BIT                        ,
			DeviceAddressCaptureReplay          = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT    ,
			DeviceAddressCaptureReplayExtension = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT,
			DeviceAddressCaptureReplayKHR       = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR,

			VT_SpecifyBitmaskable = VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferUsageFlagBits">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EBufferUsage : uint32
		{
			TransferSource      = VK_BUFFER_USAGE_TRANSFER_SRC_BIT        ,
			TransferDestination = VK_BUFFER_USAGE_TRANSFER_DST_BIT        ,
			UniformTexelBuffer  = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT,
			StorageTexelBuffer  = VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT,
			UniformBuffer       = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT      ,
			StorageBuffer       = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT      ,
			IndexBuffer         = VK_BUFFER_USAGE_INDEX_BUFFER_BIT        ,
			VertexBuffer        = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT       ,
			IndirectBuffer      = VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT     ,

			VT_SpecifyBitmaskable = VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkColorComponentFlagBits">Specification</a> @ingroup APISpec_The_Framebuffer */
		enum class EColorComponentFlag : uint32
		{
			R = VK_COLOR_COMPONENT_R_BIT,
			G = VK_COLOR_COMPONENT_G_BIT,
			B = VK_COLOR_COMPONENT_B_BIT,
			A = VK_COLOR_COMPONENT_A_BIT,

			VT_SpecifyBitmaskable = VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkColorSpaceKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
		enum class EColorSpace : uint32
		{
			SRGB_NonLinear                   = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR         ,
			NonLinear_Display_P3             = VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT   ,
			ExtendedSRGB_Linear              = VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT   ,
			Display_P3_LInear                = VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT      ,
			DCI_P3_NonLinear                 = VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT       ,
			BT709_Linear                     = VK_COLOR_SPACE_BT709_LINEAR_EXT           ,
			BT709_NonLinear                  = VK_COLOR_SPACE_BT709_NONLINEAR_EXT        ,
			BT2020_Linear                    = VK_COLOR_SPACE_BT2020_LINEAR_EXT          ,
			Extensions_HDR_ST2084            = VK_COLOR_SPACE_HDR10_ST2084_EXT           ,
			Extension_DoblyVision            = VK_COLOR_SPACE_DOLBYVISION_EXT            ,
			HDR10_HLG                        = VK_COLOR_SPACE_HDR10_HLG_EXT              ,
			AdobeRGB_Linear                  = VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT        ,
			AdobeRGB_NonLinear               = VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT     ,
			Extension_PassThrough            = VK_COLOR_SPACE_PASS_THROUGH_EXT           ,
			Extension_ExtendedSRGB_NonLinear = VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT,
			AMD_Native                       = VK_COLOR_SPACE_DISPLAY_NATIVE_AMD         ,
			KHR_SRGB_NonLinear               = VK_COLORSPACE_SRGB_NONLINEAR_KHR          ,
			Extension_DCI_P3_Linear          = VK_COLOR_SPACE_DCI_P3_LINEAR_EXT          ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferLevel">Specification</a> @ingroup APISpec_Command_Buffers */
		enum class ECommandBufferLevel
		{
			Primary   = VK_COMMAND_BUFFER_LEVEL_PRIMARY  ,
			Secondary = VK_COMMAND_BUFFER_LEVEL_SECONDARY 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlagBits ">Specification</a> @ingroup APISpec_Command_Buffers */
		enum class ECommandBufferResetFlag : uInt32
		{
			ReleaseResources = VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT,

			VT_SpecifyBitmaskable = VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlagBits">Specification</a> @ingroup APISpec_Command_Buffers */
		enum class ECommandBufferUsageFlag : uint32
		{
			OneTimeSubmit      = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT     ,
			RenderPassContinue = VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT,
			SimultaneousUse    = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT    ,

			VT_SpecifyBitmaskable = VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateFlagBits">Specification</a> @ingroup APISpec_Command_Buffers */
		enum class ECommandPoolCreateFlag : uint32
		{
			Transient          = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT           ,
			ResetCommandBuffer = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			Protected          = VK_COMMAND_POOL_CREATE_PROTECTED_BIT           ,

			VT_SpecifyBitmaskable = VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolResetFlagBits">Specification</a> @ingroup APISpec_Command_Buffers */
		enum class ECommandPoolResetFlags : uInt32
		{
			ReleaseResources = VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT,

			VT_SpecifyBitmaskable = VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkComponentSwizzle">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EComponentSwizzle : uint32
		{
			Identitity = VK_COMPONENT_SWIZZLE_IDENTITY,
			Zero       = VK_COMPONENT_SWIZZLE_ZERO    ,
			One        = VK_COMPONENT_SWIZZLE_ONE     ,
			R          = VK_COMPONENT_SWIZZLE_R       ,
			G          = VK_COMPONENT_SWIZZLE_G       ,
			B          = VK_COMPONENT_SWIZZLE_B       ,
			A          = VK_COMPONENT_SWIZZLE_A       ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompositeAlphaFlagBitsKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
		enum class ECompositeAlpha : uint32
		{
			Opaque         = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR          ,
			PreMultiplied  = VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR  ,
			PostMultiplied = VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR ,
			Inherit        = VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR         ,

			VT_SpecifyBitmaskable = VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompareOp">Specification</a> @ingroup APISpec_Fragment_Operations */
		enum class ECompareOperation : uint32
		{
			Never          = VK_COMPARE_OP_NEVER           ,
			Less           = VK_COMPARE_OP_LESS            ,
			Equal          = VK_COMPARE_OP_EQUAL           ,
			LessOrEqual    = VK_COMPARE_OP_LESS_OR_EQUAL   ,
			Greater        = VK_COMPARE_OP_GREATER         ,
			NotEqual       = VK_COMPARE_OP_NOT_EQUAL       ,
			GreaterOrEqual = VK_COMPARE_OP_GREATER_OR_EQUAL,
			Always         = VK_COMPARE_OP_ALWAYS
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCullModeFlagBits">Specification</a> @ingroup APISpec_Rasterization */
		enum class ECullModeFlag : uint32
		{
			None           = VK_CULL_MODE_NONE          ,
			Front          = VK_CULL_MODE_FRONT_BIT     ,
			Back           = VK_CULL_MODE_BACK_BIT      ,
			Front_And_Back = VK_CULL_MODE_FRONT_AND_BACK,

			VT_SpecifyBitmaskable = VK_CULL_MODE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageSeverityFlagBitsEXT">Specification</a> @ingroup APISpec_Debugging */
		enum class EDebugUtils_MessageSeverity : uint32
		{
			Verbose = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
			Info    = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT   ,
			Warning = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT,
			Error   = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT  ,

			VT_SpecifyBitmaskable = VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageTypeFlagBitsEXT">Specification</a> @ingroup APISpec_Debugging */
		enum class EDebugUtils_MessageType : uint32
		{
			General     = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT    ,
			Validation  = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT ,
			Performance = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,

			VT_SpecifyBitmaskable = VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDependencyFlagBits">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class EDependencyFlag : uint32
		{
			ByRegion = VK_DEPENDENCY_BY_REGION_BIT,

			VT_SpecifyBitmaskable = VK_DEPENDENCY_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBindingFlagBits">Specification</a> @ingroup APISpec_Resource_Descriptors */
		enum class EDescriptorBindingFlag : uint32
		{
			UpdateAfterBind              = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT              ,
			UpdateUnusedWhilePending     = VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT    ,
			PartiallyBound               = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT                ,
			VariableDescriptorCount      = VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT      ,
			UpdateAfterBind_EXT          = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT_EXT          ,
			UpdateUnusedWhilePending_EXT = VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT_EXT,
			PartiallyBound_EXT           = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT_EXT            ,
			VariableDescriptorCount_EXT  = VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT_EXT  ,

			VT_SpecifyBitmaskable = VK_DESCRIPTOR_BINDING_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateFlagBits">Specification</a> @ingroup APISpec_Resource_Descriptors */
		enum class EDescriptorPoolCreateFlag : uint32
		{
			FreeDescriptorSet   = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT  ,
			UpdateAfterBind     = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT    ,
			UpdateAfterBind_EXT = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT,

			VT_SpecifyBitmaskable = VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutCreateFlagBits">Specification</a> @ingroup APISpec_Resource_Descriptors */
		enum class EDescriptorSetLayoutCreateFlag : uint32
		{
			UpdateAfterBindPool           = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT    ,
			PushDescriptor                = VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR       ,
			UpdateAfterBindPool_Extension = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT,

			VT_SpecifyBitmaskable = VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorType">Specification</a> @ingroup APISpec_Resource_Descriptors */
		enum class EDescriptorType : uint32
		{
			Sampler                      = VK_DESCRIPTOR_TYPE_SAMPLER                   ,
			CombinedImageSampler         = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER    ,
			SampledImage                 = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE             ,
			StorageImage                 = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE             ,
			UniformTexelBuffer           = VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER      ,
			StorageTexelBuffer           = VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER      ,
			UniformBuffer                = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER            ,
			StorageBuffer                = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER            ,
			UniformBufferDynamic         = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC    ,
			StorageBufferDynamic         = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC    ,
			InputAttachment              = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT          ,
			InlineUniformBlock_Extension = VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT  ,
			AccelerationStructure_KHR    = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR,
			AccelerationStructure_NV     = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigFlagBitsNV">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EDeviceDiagnosticConfigFlag : uint32
		{
			EnableShaderDebugInfo      = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV    , 
			EnableResourceTracking     = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV    , 
			EnableAutomaticCheckpoints = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV,

			VT_SpecifyBitmaskable = VK_DEVICE_DIAGNOSTICS_CONFIG_FLAG_BITS_MAX_ENUM_NV
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlagBits">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EDeviceQueueCreateFlag : uint32
		{
			// Provided by VK_VERSION_1_1
			Protected = VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT,

			VT_SpecifyBitmaskable = VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceEventTypeEXT">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EDeviceEventType : uint32
		{
			DisplayHotPlug_ = VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDisplayEventTypeEXT">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class EDisplayEventType : uint32
		{
			FirstPixelOut_EXT = VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT
		};

		/**
		* @details
		* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDriverId">Specification</a> 
		* 
		* @ingroup APISpec_Devices_and_Queues
		*/
		enum class EDriverID
		{
			Proprietary             = VK_DRIVER_ID_AMD_PROPRIETARY          ,
			OpenSource              = VK_DRIVER_ID_AMD_OPEN_SOURCE          ,
			Mesa_RADV               = VK_DRIVER_ID_MESA_RADV                ,
			NvidiaProprietary       = VK_DRIVER_ID_NVIDIA_PROPRIETARY       ,
			IntelProprietaryWindows = VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS,
			IntelOpenSourceMesa     = VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA   ,
			ImaginationProprietary  = VK_DRIVER_ID_IMAGINATION_PROPRIETARY  ,
			QualcommProprietary     = VK_DRIVER_ID_QUALCOMM_PROPRIETARY     ,
			ARM_Proprietary         = VK_DRIVER_ID_ARM_PROPRIETARY          ,
			GoogleSwiftShader       = VK_DRIVER_ID_GOOGLE_SWIFTSHADER       ,
			GGP_Proprietary         = VK_DRIVER_ID_GGP_PROPRIETARY          ,
			BroadcomProprietary     = VK_DRIVER_ID_BROADCOM_PROPRIETARY     ,
			MESA_LLLVM_Pipe         = VK_DRIVER_ID_MESA_LLVMPIPE            ,
			//MoltenVK                = VK_DRIVER_ID_MOLTENVK                 ,

			// Provided by VK_KHR_driver_properties
			AMD_Proprietary_KHR         = VK_DRIVER_ID_AMD_PROPRIETARY_KHR          ,
			AMD_OpenSource_KHR          = VK_DRIVER_ID_AMD_OPEN_SOURCE_KHR          ,
			Mesa_RADV_KHR               = VK_DRIVER_ID_MESA_RADV_KHR                ,
			NvidiaProprietary_KHR       = VK_DRIVER_ID_NVIDIA_PROPRIETARY_KHR       ,
			IntelProprietaryWindows_KHR = VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS_KHR,
			IntelOpenSourceMesa_KHR     = VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA_KHR   ,
			Imagination_Proprietary_KHR = VK_DRIVER_ID_IMAGINATION_PROPRIETARY_KHR  ,
			QualCommProprietary_KHR     = VK_DRIVER_ID_QUALCOMM_PROPRIETARY_KHR     ,
			ARM_Proprietary_KHR         = VK_DRIVER_ID_ARM_PROPRIETARY_KHR          ,
			GoogleSwiftShader_KHR       = VK_DRIVER_ID_GOOGLE_SWIFTSHADER_KHR       ,
			GGP_Proprietary_KHR         = VK_DRIVER_ID_GGP_PROPRIETARY_KHR          ,
			BroadcomProprietary_KHR     = VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR     ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDynamicState">Specification</a> @ingroup APISpec_Pipelines */
		enum class EDynamicState : uint32
		{
			Viewport                      = VK_DYNAMIC_STATE_VIEWPORT                        ,
			Scissor                       = VK_DYNAMIC_STATE_SCISSOR                         ,
			LineWidth                     = VK_DYNAMIC_STATE_LINE_WIDTH                      ,
			DepthBias                     = VK_DYNAMIC_STATE_DEPTH_BIAS                      ,
			BlendConstants                = VK_DYNAMIC_STATE_BLEND_CONSTANTS                 ,
			DepthBounds                   = VK_DYNAMIC_STATE_DEPTH_BOUNDS                    ,
			StencilCompareMask            = VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK            ,
			StencilWriteMask              = VK_DYNAMIC_STATE_STENCIL_WRITE_MASK              ,
			StencilReference              = VK_DYNAMIC_STATE_STENCIL_REFERENCE               ,
			Viewport_W_Scaling_NV         = VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV           ,
			DiscardRectangle_Extension    = VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT           ,
			SampleLocations_Extension     = VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT            ,
			ViewportShadingRatePalette_NV = VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV,
			ViewportCoarseSampleOrder_NV  = VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV ,
			ExclusiveScissor_NV           = VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV            ,
			LineStipple_Extension         = VK_DYNAMIC_STATE_LINE_STIPPLE_EXT                
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalFenceHandleTypeFlagBits">Specification</a> @ingroup APISpec_Additional_Capabilities */
		enum class EExternalFenceHandleTypeFlag : uint32
		{
			OpaqueFD             = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT           ,
			Opaque_Win32         = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT        ,
			Opaque_Win32_KMT     = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT    ,
			SyncFD               = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT             ,
			OpaqueFD_KHR         = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR       ,   // Provided by VK_KHR_external_fence_capabilities
			Opaque_Win32_KHR     = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR    ,   // Provided by VK_KHR_external_fence_capabilities
			Opaque_Win32_KMT_KHR = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR,   // Provided by VK_KHR_external_fence_capabilities
			SyncFD_KHR           = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR         ,   // Provided by VK_KHR_external_fence_capabilities

			VT_SpecifyBitmaskable = VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalSemaphoreHandleTypeFlagBits">Specification</a> @ingroup APISpec_Additional_Capabilities */
		enum class EExternalSemaphoreHandleTypeFlag : uint32
		{
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT = 0x00000001,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT = 0x00000002,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT = 0x00000004,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT = 0x00000008,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT = 0x00000010,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT,

			VT_SpecifyBitmaskable = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateFlagBits">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class EFenceCreateFlag : uint32
		{
			Signaled = VK_FENCE_CREATE_SIGNALED_BIT,

			VT_SpecifyBitmaskable = VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceImportFlagBits">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class EFenceImportFlag
		{
			Temporary     = VK_FENCE_IMPORT_TEMPORARY_BIT    ,   // Provided by VK_KHR_external_fence
			Temporary_KHR = VK_FENCE_IMPORT_TEMPORARY_BIT_KHR,

			VT_SpecifyBitmaskable = VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFilter">Specification</a> @ingroup APISpec_Samplers */
		enum class EFilter : uint32
		{
			Nearest   = VK_FILTER_NEAREST  ,
			Linear    = VK_FILTER_LINEAR   ,
			Cubic     = VK_FILTER_CUBIC_IMG,
			Cubic_EXT = VK_FILTER_CUBIC_EXT 
		};

		/**
		 * @brief Supported buffer and image formats.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#formats">Specification</a> 
		 * 
		 * @ingroup APISpec_Formats
		 */
		enum class EFormat : uint32
		{
			Undefined                                            = VK_FORMAT_UNDEFINED                                     ,
			R4_G4_UNormalized_8Pack                              = VK_FORMAT_R4G4_UNORM_PACK8                              ,
			R4_G4_B4_A4_UNormalized_16Pack                       = VK_FORMAT_R4G4B4A4_UNORM_PACK16                         ,
			B4_G4_R4_A4_UNormalized_16Pack                       = VK_FORMAT_B4G4R4A4_UNORM_PACK16                         ,
			R5_G6_B5_UNormalized_16Pack                          = VK_FORMAT_R5G6B5_UNORM_PACK16                           ,
			B5_G6_R5_UNormalized_16Pack                          = VK_FORMAT_B5G6R5_UNORM_PACK16                           ,
			R5_G5_B5_1A_UNormalized_16Pack                       = VK_FORMAT_R5G5B5A1_UNORM_PACK16                         ,
			B5_G5_R5_A1_UNormalized_16Pack                       = VK_FORMAT_B5G5R5A1_UNORM_PACK16                         ,
			A1_R5_G5_B5_UNormalized_16Pack                       = VK_FORMAT_A1R5G5B5_UNORM_PACK16                         ,
			R8_UNormalized                                       = VK_FORMAT_R8_UNORM                                      ,
			R8_SNormalized                                       = VK_FORMAT_R8_SNORM                                      ,
			R8_UScaled                                           = VK_FORMAT_R8_USCALED                                    ,
			R8_SScaled                                           = VK_FORMAT_R8_SSCALED                                    ,
			R8_UInt                                              = VK_FORMAT_R8_UINT                                       ,
			R8_SInt                                              = VK_FORMAT_R8_SINT                                       ,
			R8_SRGB                                              = VK_FORMAT_R8_SRGB                                       ,
			R8_G8_UNormalized                                    = VK_FORMAT_R8G8_UNORM                                    ,
			R8_G8_SNormalized                                    = VK_FORMAT_R8G8_SNORM                                    ,
			R8_G8_UScaled                                        = VK_FORMAT_R8G8_USCALED                                  ,
			R8_G8_SScaled                                        = VK_FORMAT_R8G8_SSCALED                                  ,
			R8_G8_UInt                                           = VK_FORMAT_R8G8_UINT                                     ,
			R8_G8_SInt                                           = VK_FORMAT_R8G8_SINT                                     ,
			R8_G8_SRGB                                           = VK_FORMAT_R8G8_SRGB                                     ,
			R8_G8_B8_UNormalized                                 = VK_FORMAT_R8G8B8_UNORM                                  ,
			R8_G8_B8_SNormalized                                 = VK_FORMAT_R8G8B8_SNORM                                  ,
			R8_G8_B8_UScaled                                     = VK_FORMAT_R8G8B8_USCALED                                ,
			R8_G8_B8_SScaled                                     = VK_FORMAT_R8G8B8_SSCALED                                ,
			R8_G8_B8_UInt                                        = VK_FORMAT_R8G8B8_UINT                                   ,
			R8_G8_B8_SInt                                        = VK_FORMAT_R8G8B8_SINT                                   ,
			R8_G8_B8_SRGB                                        = VK_FORMAT_R8G8B8_SRGB                                   ,
			B8_G8_R8_UNormalized                                 = VK_FORMAT_B8G8R8_UNORM                                  ,
			B8_G8_R8_SNormalized                                 = VK_FORMAT_B8G8R8_SNORM                                  ,
			B8_G8_R8_UScaled                                     = VK_FORMAT_B8G8R8_USCALED                                ,
			B8_G8_R8_SScaled                                     = VK_FORMAT_B8G8R8_SSCALED                                ,
			B8_G8_R8_UInt                                        = VK_FORMAT_B8G8R8_UINT                                   ,
			B8_G8_R8_SInt                                        = VK_FORMAT_B8G8R8_SINT                                   ,
			B8_G8_R8_SRGB                                        = VK_FORMAT_B8G8R8_SRGB                                   ,
			R8_G8_B8_A8_UNormalized                              = VK_FORMAT_R8G8B8A8_UNORM                                ,
			R8_G8_B8_A8_SNormalized                              = VK_FORMAT_R8G8B8A8_SNORM                                ,
			R8_G8_B8_A8_UScaled                                  = VK_FORMAT_R8G8B8A8_USCALED                              ,
			R8_G8_B8_A8_SScaled                                  = VK_FORMAT_R8G8B8A8_SSCALED                              ,
			R8_G8_B8_A8_UInt                                     = VK_FORMAT_R8G8B8A8_UINT                                 ,
			R8_G8_B8_A8_SInt                                     = VK_FORMAT_R8G8B8A8_SINT                                 ,
			R8_G8_B8_A8_SRGB                                     = VK_FORMAT_R8G8B8A8_SRGB                                 ,
			B8_G8_R8_A8_UNormalized                              = VK_FORMAT_B8G8R8A8_UNORM                                ,
			B8_G8_R8_A8_SNormalized                              = VK_FORMAT_B8G8R8A8_SNORM                                ,
			B8_G8_R8_A8_UScaled                                  = VK_FORMAT_B8G8R8A8_USCALED                              ,
			B8_G8_R8_A8_SScaled                                  = VK_FORMAT_B8G8R8A8_SSCALED                              ,
			B8_G8_R8_A8_Uint                                     = VK_FORMAT_B8G8R8A8_UINT                                 ,
			B8_G8_R8_A8_SInt                                     = VK_FORMAT_B8G8R8A8_SINT                                 ,
			B8_G8_R8_A8_SRGB                                     = VK_FORMAT_B8G8R8A8_SRGB                                 ,
			A8_B8_G8_R8_UNormalized_Pack32                       = VK_FORMAT_A8B8G8R8_UNORM_PACK32                         ,
			A8_B8_G8_R8_SNormalized_Pack32                       = VK_FORMAT_A8B8G8R8_SNORM_PACK32                         ,
			A8_B8_G8_R8_UScaled_Pack32                           = VK_FORMAT_A8B8G8R8_USCALED_PACK32                       ,
			A8_B8_G8_R8_SScaled_Pack32                           = VK_FORMAT_A8B8G8R8_SSCALED_PACK32                       ,
			A8_B8_G8_R8_UInt_Pack32                              = VK_FORMAT_A8B8G8R8_UINT_PACK32                          ,
			A8_B8_G8_R8_SInt_Pack32                              = VK_FORMAT_A8B8G8R8_SINT_PACK32                          ,
			A8_B8_G8_R8_SRGB_Pack32                              = VK_FORMAT_A8B8G8R8_SRGB_PACK32                          ,
			A2_R10_G10_B10_UNormalized_Pack32                    = VK_FORMAT_A2R10G10B10_UNORM_PACK32                      ,
			A2_R10_G10_B10_SNormalized_Pack32                    = VK_FORMAT_A2R10G10B10_SNORM_PACK32                      ,
			A2_R10_G10_B10_UScaled_Pack32                        = VK_FORMAT_A2R10G10B10_USCALED_PACK32                    ,
			A2_R10_G10_B10_SScaled_Pack32                        = VK_FORMAT_A2R10G10B10_SSCALED_PACK32                    ,
			A2_R10_G10_B10_UInt_Pack32                           = VK_FORMAT_A2R10G10B10_UINT_PACK32                       ,
			A2_R10_G10_B10_SInt_Pack32                           = VK_FORMAT_A2R10G10B10_SINT_PACK32                       ,
			A2_B10_G10_R10_UNormalized_Pack32                    = VK_FORMAT_A2B10G10R10_UNORM_PACK32                      ,
			A2_B10_G10_R10_SNormalized_Pack32                    = VK_FORMAT_A2B10G10R10_SNORM_PACK32                      ,
			A2_B10_G10_R10_UScaled_Pack32                        = VK_FORMAT_A2B10G10R10_USCALED_PACK32                    ,
			A2_B10_G10_R10_SScaled_Pack32                        = VK_FORMAT_A2B10G10R10_SSCALED_PACK32                    ,
			A2_B10_G10_R10_UInt_Pack32                           = VK_FORMAT_A2B10G10R10_UINT_PACK32                       ,
			A2_B10_G10_R10_SInt_Pack32                           = VK_FORMAT_A2B10G10R10_SINT_PACK32                       ,
			R16_UNormalized                                      = VK_FORMAT_R16_UNORM                                     ,
			R16_SNormalized                                      = VK_FORMAT_R16_SNORM                                     ,
			R16_UScaled                                          = VK_FORMAT_R16_USCALED                                   ,
			R16_SScaled                                          = VK_FORMAT_R16_SSCALED                                   ,
			R16_UInt                                             = VK_FORMAT_R16_UINT                                      ,
			R16_SInt                                             = VK_FORMAT_R16_SINT                                      ,
			R16_SFloat                                           = VK_FORMAT_R16_SFLOAT                                    ,
			R16_G16_UNormalized                                  = VK_FORMAT_R16G16_UNORM                                  ,
			R16_G16_SNormalized                                  = VK_FORMAT_R16G16_SNORM                                  ,
			R16_G16_UScaled                                      = VK_FORMAT_R16G16_USCALED                                ,
			R16_G16_SScaled                                      = VK_FORMAT_R16G16_SSCALED                                ,
			R16_G16_UInt                                         = VK_FORMAT_R16G16_UINT                                   ,
			R16_G16_SInt                                         = VK_FORMAT_R16G16_SINT                                   ,
			R16_G16_SFloat                                       = VK_FORMAT_R16G16_SFLOAT                                 ,
			R16_G16_B16_UNormalized                              = VK_FORMAT_R16G16B16_UNORM                               ,
			R16_G16_B16_SNormalized                              = VK_FORMAT_R16G16B16_SNORM                               ,
			R16_G16_B16_UScaled                                  = VK_FORMAT_R16G16B16_USCALED                             ,
			R16_G16_B16_SScaled                                  = VK_FORMAT_R16G16B16_SSCALED                             ,
			R16_G16_B16_UInt                                     = VK_FORMAT_R16G16B16_UINT                                ,
			R16_G16_B16_SInt                                     = VK_FORMAT_R16G16B16_SINT                                ,
			R16_G16_B16_SFloat                                   = VK_FORMAT_R16G16B16_SFLOAT                              ,
			R16_G16_B16_A16_UNormalized                          = VK_FORMAT_R16G16B16A16_UNORM                            ,
			R16_G16_B16_A16_SNormalized                          = VK_FORMAT_R16G16B16A16_SNORM                            ,
			R16_G16_B16_A16_UScaled                              = VK_FORMAT_R16G16B16A16_USCALED                          ,
			R16_G16_B16_A16_SScaled                              = VK_FORMAT_R16G16B16A16_SSCALED                          ,
			R16_G16_B16_A16_UInt                                 = VK_FORMAT_R16G16B16A16_UINT                             ,
			R16_G16_B16_A16_SInt                                 = VK_FORMAT_R16G16B16A16_SINT                             ,
			R16_G16_B16_A16_SFloat                               = VK_FORMAT_R16G16B16A16_SFLOAT                           ,
			R32_UInt                                             = VK_FORMAT_R32_UINT                                      ,
			R32_SInt                                             = VK_FORMAT_R32_SINT                                      ,
			R32_SFloat                                           = VK_FORMAT_R32_SFLOAT                                    ,
			R32_G32_UInt                                         = VK_FORMAT_R32G32_UINT                                   ,
			R32_G32_SInt                                         = VK_FORMAT_R32G32_SINT                                   ,
			R32_G32_SFloat                                       = VK_FORMAT_R32G32_SFLOAT                                 ,
			R32_G32_B32_UInt                                     = VK_FORMAT_R32G32B32_UINT                                ,
			R32_G32_B32_Sint                                     = VK_FORMAT_R32G32B32_SINT                                ,
			R32_G32_B32_SFloat                                   = VK_FORMAT_R32G32B32_SFLOAT                              ,
			R32_G32_B32_A32_UInt                                 = VK_FORMAT_R32G32B32A32_UINT                             ,
			R32_G32_B32_A32_SInt                                 = VK_FORMAT_R32G32B32A32_SINT                             ,
			R32_G32_B32_A32_SFloat                               = VK_FORMAT_R32G32B32A32_SFLOAT                           ,
			R64_Uint                                             = VK_FORMAT_R64_UINT                                      ,
			R64_SInt                                             = VK_FORMAT_R64_SINT                                      ,
			R64_SFloat                                           = VK_FORMAT_R64_SFLOAT                                    ,
			R64_G64_UInt                                         = VK_FORMAT_R64G64_UINT                                   ,
			R64_G64_SInt                                         = VK_FORMAT_R64G64_SINT                                   ,
			R64_G64_SFloat                                       = VK_FORMAT_R64G64_SFLOAT                                 ,
			R64_G64_B64_UInt                                     = VK_FORMAT_R64G64B64_UINT                                ,
			R64_G64_B64_SInt                                     = VK_FORMAT_R64G64B64_SINT                                ,
			R64_G64_B64_SFloat                                   = VK_FORMAT_R64G64B64_SFLOAT                              ,
			R64_G64_B64_A64_UInt                                 = VK_FORMAT_R64G64B64A64_UINT                             ,
			R64_G64_B64_A64_SInt                                 = VK_FORMAT_R64G64B64A64_SINT                             ,
			R64_G64_B64_A64_SFloat                               = VK_FORMAT_R64G64B64A64_SFLOAT                           ,
			B10_G11_R11_UFloat_Pack32                            = VK_FORMAT_B10G11R11_UFLOAT_PACK32                       ,
			E5_B9_G9_R9_UFloat_Pack32                            = VK_FORMAT_E5B9G9R9_UFLOAT_PACK32                        ,
			D16_UNormalized                                      = VK_FORMAT_D16_UNORM                                     ,
			X8_D24_UNormalized_Pack32                            = VK_FORMAT_X8_D24_UNORM_PACK32                           ,
			D32_SFloat                                           = VK_FORMAT_D32_SFLOAT                                    ,
			S8_UInt                                              = VK_FORMAT_S8_UINT                                       ,
			D16_UNormalized_S8_UInt                              = VK_FORMAT_D16_UNORM_S8_UINT                             ,
			D24_UNormalized_S8_UInt                              = VK_FORMAT_D24_UNORM_S8_UINT                             ,
			D32_SFloat_S8_UInt                                   = VK_FORMAT_D32_SFLOAT_S8_UINT                            ,
			BC1_RGB_UNormalized_Block                            = VK_FORMAT_BC1_RGB_UNORM_BLOCK                           ,
			BC1_RGB_SRGB_Block                                   = VK_FORMAT_BC1_RGB_SRGB_BLOCK                            ,
			BC1_RGBA_Unormalized_Block                           = VK_FORMAT_BC1_RGBA_UNORM_BLOCK                          ,
			BC1_RGBA_SRGB_Block                                  = VK_FORMAT_BC1_RGBA_SRGB_BLOCK                           ,
			BC2_UNormalized_Block                                = VK_FORMAT_BC2_UNORM_BLOCK                               ,
			BC2_SRGB_Block                                       = VK_FORMAT_BC2_SRGB_BLOCK                                ,
			BC3_UNormalized_Block                                = VK_FORMAT_BC3_UNORM_BLOCK                               ,
			BC3_SRGB_Block                                       = VK_FORMAT_BC3_SRGB_BLOCK                                ,
			BC4_UNormalized_Block                                = VK_FORMAT_BC4_UNORM_BLOCK                               ,
			BC4_SNormalized_Block                                = VK_FORMAT_BC4_SNORM_BLOCK                               ,
			BC5_UNormalized_Block                                = VK_FORMAT_BC5_UNORM_BLOCK                               ,
			BC5_SNormalized_Block                                = VK_FORMAT_BC5_SNORM_BLOCK                               ,
			BC6H_UFloat_Block                                    = VK_FORMAT_BC6H_UFLOAT_BLOCK                             ,
			BC6H_SFloat_Block                                    = VK_FORMAT_BC6H_SFLOAT_BLOCK                             ,
			BC7_UNormalized_Block                                = VK_FORMAT_BC7_UNORM_BLOCK                               ,
			BC7_SRGB_Block                                       = VK_FORMAT_BC7_SRGB_BLOCK                                ,
			ETC2_R8_G8_B8_UNormalized_Block                      = VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK                       ,
			ETC2_R8_G8_B8_SRGB_Block                             = VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK                        ,
			ETC2_R8_G8_B8_A1_UNormalized_Block                   = VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK                     ,
			ETC2_R8_G8_B8_A1_Block                               = VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK                      ,
			ETC_2_R8_G8_B8_A8_UNormalized_Block                  = VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK                     ,
			ETC2_R8_G8_B8_A8_SRGB_Block                          = VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK                      ,
			EAC_R11_UNormalized_Block                            = VK_FORMAT_EAC_R11_UNORM_BLOCK                           ,
			EAC_R11_SNormalized_Block                            = VK_FORMAT_EAC_R11_SNORM_BLOCK                           ,
			EAC_R11_G11_UNormalized_Block                        = VK_FORMAT_EAC_R11G11_UNORM_BLOCK                        ,
			EAC_R11_G11_SNormalized_Block                        = VK_FORMAT_EAC_R11G11_SNORM_BLOCK                        ,
			ASTC_4x4_UNormalized_Block                           = VK_FORMAT_ASTC_4x4_UNORM_BLOCK                          ,
			ASTC_4x4_SRGB_Block                                  = VK_FORMAT_ASTC_4x4_SRGB_BLOCK                           ,
			ASTC_5x4_UNormalized_Block                           = VK_FORMAT_ASTC_5x4_UNORM_BLOCK                          ,
			ASTC_5x4_SRGB_Block                                  = VK_FORMAT_ASTC_5x4_SRGB_BLOCK                           ,
			ASTC_5x5_UNormalized_Block                           = VK_FORMAT_ASTC_5x5_UNORM_BLOCK                          ,
			ASTC_5x5_SRGB_Block                                  = VK_FORMAT_ASTC_5x5_SRGB_BLOCK                           ,
			ASTC_6x5_UNormalized_Block                           = VK_FORMAT_ASTC_6x5_UNORM_BLOCK                          ,
			ASTC_6x5_SRGB_Block                                  = VK_FORMAT_ASTC_6x5_SRGB_BLOCK                           ,
			ASTC_6x6_UNormalized_Block                           = VK_FORMAT_ASTC_6x6_UNORM_BLOCK                          ,
			ASTC_6x6_SRGB_Block                                  = VK_FORMAT_ASTC_6x6_SRGB_BLOCK                           ,
			ASTC_8x5_UNormalized_Block                           = VK_FORMAT_ASTC_8x5_UNORM_BLOCK                          ,
			ASTC_8x5_SRGB_Block                                  = VK_FORMAT_ASTC_8x5_SRGB_BLOCK                           ,
			ASTC_8x6_UNormalized_Block                           = VK_FORMAT_ASTC_8x6_UNORM_BLOCK                          ,
			ASTC_8x6_SRGB_Block                                  = VK_FORMAT_ASTC_8x6_SRGB_BLOCK                           ,
			ASTC_8x8_UNormalized_Block                           = VK_FORMAT_ASTC_8x8_UNORM_BLOCK                          ,
			ASTC_8x8_SRGB_Block                                  = VK_FORMAT_ASTC_8x8_SRGB_BLOCK                           ,
			ASTC_10x5_UNormalized_Block                          = VK_FORMAT_ASTC_10x5_UNORM_BLOCK                         ,
			ASTC_10x5_SRGB_Block                                 = VK_FORMAT_ASTC_10x5_SRGB_BLOCK                          ,
			ASTC_10x6_UNormalized_Block                          = VK_FORMAT_ASTC_10x6_UNORM_BLOCK                         ,
			ASTC_10x6_SRGB_Block                                 = VK_FORMAT_ASTC_10x6_SRGB_BLOCK                          ,
			ASTC_10x8_UNormalized_Block                          = VK_FORMAT_ASTC_10x8_UNORM_BLOCK                         ,
			ASTC_10x8_SRGB_Block                                 = VK_FORMAT_ASTC_10x8_SRGB_BLOCK                          ,
			ASTC_10x10_UNormalized_Block                         = VK_FORMAT_ASTC_10x10_UNORM_BLOCK                        ,
			ASTC_10x10_SRGB_Block                                = VK_FORMAT_ASTC_10x10_SRGB_BLOCK                         ,
			ASTC_12x10_UNormalized_Block                         = VK_FORMAT_ASTC_12x10_UNORM_BLOCK                        ,
			ASTC_12x10_SRGB_Block                                = VK_FORMAT_ASTC_12x10_SRGB_BLOCK                         ,
			ASTC_12x12_UNormalize_Block                          = VK_FORMAT_ASTC_12x12_UNORM_BLOCK                        ,
			ASTC_12x12_SRGB_Block                                = VK_FORMAT_ASTC_12x12_SRGB_BLOCK                         ,
			G8_B8_G8_R8_422_UNormalized                          = VK_FORMAT_G8B8G8R8_422_UNORM                            ,
			B8_G8_R8_G8_422_UNormalized                          = VK_FORMAT_B8G8R8G8_422_UNORM                            ,
			G8_B8_R8_3Plane_420_UNormalized                      = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM                     ,
			G8_B8_R8_2Plane_420_UNormalized                      = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM                      ,
			G8_B8_R8_3Plane_422_UNormalized                      = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM                     ,
			G8_B8_R8_2Plane_422_UNormalized                      = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM                      ,
			G8_B8_R8_3Plane_444_UNormalized                      = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM                     ,
			R10x6_UNormalized_Pack16                             = VK_FORMAT_R10X6_UNORM_PACK16                            ,
			R10x6_G10x6_UNormalized_2Pack16                      = VK_FORMAT_R10X6G10X6_UNORM_2PACK16                      ,
			R10x6_G10x6_B10x6_A10x6_UNormalized_4Pack16          = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16            ,
			G10x6_B10x6_G10x6_R10x6_422_UNormalized_4Pack16      = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16        ,
			B10x6_G10x6_R10x6_G10x6_422_UNormalized_4Pack16      = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16        ,
			G10x6_B10x6_R10x6_3Plane_420_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16    ,
			G10x6_B10x6_R10x6_2Plane_420_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16     ,
			G10x6_B10x6_R10x6_3Plane_422_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16    ,
			G10x6_B10x6_R10x6_2Plane_422_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16     ,
			G10x6_B10x6_R10x6_3Plane_444_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16    ,
			R12x4_UNormalized_Pack16                             = VK_FORMAT_R12X4_UNORM_PACK16                            ,
			R12x4_G12x4_UNormalized_2Pack16                      = VK_FORMAT_R12X4G12X4_UNORM_2PACK16                      ,
			R12x4_G12x4_B12x4_A12x4_UNormalized_4Pack16          = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16            ,
			G12x4_B12x4_G12x4_R12x4_422_UNormalized_4Pack16      = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16        ,
			B12x4_G12x4_R12x4_G12x4_422_UNormalized_4Pack16      = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16        ,
			G12x4_B12x4_R12x4_3Plane_420_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16    ,
			G12x4_B12x4_R12x4_2Plane_420_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16     ,
			G12x4_B12x4_R12x4_3Plane_422_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16    ,
			G12x4_B12x4_R12x4_2Plane_422_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16     ,
			G12x4_B12x4_R12x4_3Plane_444_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16    ,
			G16_B16_G16_R16_422_UNormalized                      = VK_FORMAT_G16B16G16R16_422_UNORM                        ,
			B16_G16_R16_G16_422_UNormalized                      = VK_FORMAT_B16G16R16G16_422_UNORM                        ,
			G16_B16_R16_3Plane_420_UNormalized                   = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM                  ,
			G16_B16_R16_2Plane_420_UNormalized                   = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM                   ,
			G16_B16_3Plane_422_UNormalized                       = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM                  ,
			G16_B16_R16_2Plane_422_UNormalized                   = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM                   ,
			G16_B16_R16_3Plane_444_UNormalized                   = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM                  ,
			PVRTC1_2BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG                   ,
			PVRTC1_4BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG                   ,
			PVRTC2_2BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG                   ,
			PVRTC2_4BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG                   ,
			PVRTC1_2BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG                    ,
			PVRTC1_4BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG                    ,
			PVRTC2_2BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG                    ,
			PVRTC2_4BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG                    ,
			ASTC_4x4_SFloat_Block_EXT                            = VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT                     ,
			ASTC_5x4_SFloat_Block_EXT                            = VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT                     ,
			ASTC_5x5_SFloat_Block_EXT                            = VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT                     ,
			ASTC_6x5_SFloat_Block_EXT                            = VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT                     ,
			ASTC_6x6_SFloat_Block_EXT                            = VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT                     ,
			ASTC_8x5_SFloat_Block_EXT                            = VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT                     ,
			ASTC_8x6_SFloat_Block_EXT                            = VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT                     ,
			ASTC_8x8_SFloat_Block_EXT                            = VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT                     ,
			ASTC_10x5_SFloat_Block_EXT                           = VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT                    ,
			ASTC_10x6_SFloat_Block_EXT                           = VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT                    ,
			ASTC_10x8_SFloat_Block_EXT                           = VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT                    ,
			ASTC_10x10_SFloat_Block_EXT                          = VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT                   ,
			ASTC_12x10_SFloat_Block_EXT                          = VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT                   ,
			ASTC_12x12_SFloat_Block_EXT                          = VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT                   ,
			G8_B8_G8_R8_422_UNormalized_KHR                      = VK_FORMAT_G8B8G8R8_422_UNORM_KHR                        ,
			B8_G8_R8_G8_422_UNormalized_KHR                      = VK_FORMAT_B8G8R8G8_422_UNORM_KHR                        ,
			G8_B8_R8_3Plane_420_UNormalized_KHR                  = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR                 ,
			G8_B8_R8_2Plane_420_UNormalized_KHR                  = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR                  ,
			G8_B8_R8_3Plane_422_UNormalized_KHR                  = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR                 ,
			G8_B8_R8_2Plane_422_Unormalized_KHR                  = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR                  ,
			G8_B8_R8_3Plane_444_UNormalized_KHR                  = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR                 ,
			R10x6_UNormalized_Pack16_KHR                         = VK_FORMAT_R10X6_UNORM_PACK16_KHR                        ,
			R10x6_G10x6_UNormalized_2Pack16_KHR                  = VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR                  ,
			R10x6_G10x6_B10x6_A10x6_UNormalized_4Pack16_KHR      = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR        ,
			G10x6_B10x6_G10x6_R10x6_422_UNormalized_4Pack16_KHR  = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR    ,
			B10x6_G10x6_R10x6_G10x6_422_UNormalized_4Pack16_KHR  = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR    ,
			G10x6_B10x6_3Plane_420_UNormalized_3Pac16_KHR        = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR,
			G10x6_B10x6_R10x6_2PLane_420_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR ,
			G10x6_B10x6_R10x6_3Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR,
			G10x6_B10x6_R10x6_2Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR ,
			G10x6_B10x6_R10x6_3Plane_444_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR,
			R12X4_UNormalized_Pack16_KHR                         = VK_FORMAT_R12X4_UNORM_PACK16_KHR                        ,
			R12x4_G12x4_UNormalized_2Pack16_KHR                  = VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR                  ,
			R12x4_G12x4_B12x4_A12x4_UNormalized_4Pack16_KHR      = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR        ,
			G12x4_B12x4_G12x4_R12x4_422_UNormalized_4Pack16_KHR  = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR    ,
			B12x4_G12x4_R12x4_G12x4_422_UNormalized_4Pack16_KHR  = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR    ,
			G12x4_B12x4_R12x4_3Plane_410_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR,
			G12x4_B12x4_R12x4_2Plane_420_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR ,
			G12x4_B12x4_R12x4_3Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR,
			G12x4_B12x4_R12x4_2Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR ,
			G12x4_B12x4_R12x4_3Plane_444_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR,
			G16_B16_G16_R16_422_UNormalized_KHR                  = VK_FORMAT_G16B16G16R16_422_UNORM_KHR                    ,
			B16_G16_R16_G16_422_UNormalized_KHR                  = VK_FORMAT_B16G16R16G16_422_UNORM_KHR                    ,
			G16_B16_R16_3Plane_420_UNormalized_KHR               = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR              ,
			G16_B16_R16_2Plane_420_UNormalized_KHR               = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR               ,
			G16_B16_R16_3Plane_422_UNormalized_KHR               = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR              ,
			G16_B16_R16_2Plane_422_UNormalized_KHR               = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR               ,
			G16_B16_R16_3Plane_444_UNormalized_KHR               = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR                  // Specifies an unsigned normalized multi-planar format that has a 16-bit G component in each 16-bit word of plane 0, a 16-bit B component in each 16-bit word of plane 1, and a 16-bit R component in each 16-bit word of plane 2. Each plane has the same dimensions and each R, G and B component contributes to a single texel. The location of each plane when this image is in linear layout can be determined via vkGetImageSubresourceLayout, using VK_IMAGE_ASPECT_PLANE_0_BIT for the G plane, VK_IMAGE_ASPECT_PLANE_1_BIT for the B plane, and VK_IMAGE_ASPECT_PLANE_2_BIT for the R plane.
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFormatFeatureFlagBits">Specification</a> @ingroup APISpec_Formats */
		enum class EFormatFeatureFlag : uint32
		{
			SampledImage             = VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT              ,
			StorageImage             = VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT              ,
			ImageAtomic              = VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT       ,
			UniformTexelBuffer       = VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT       ,
			StroageTexelBuffer       = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT       ,
			StorageTexelBufferAtomic = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT,
			VertexBuffer             = VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT              ,
			ColorAttachment          = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT           ,
			ColorAttachmentBlend     = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT     ,
			DepthStencilAttachment   = VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT   ,
			BlitSource               = VK_FORMAT_FEATURE_BLIT_SRC_BIT                   ,
			BlitDestination          = VK_FORMAT_FEATURE_BLIT_DST_BIT                   ,
			SampledImageFilterLinear = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT,

			// Provided by VK_VERSION_1_1
			TransferSource                                                 = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT                                                           ,
			TransferDestination                                            = VK_FORMAT_FEATURE_TRANSFER_DST_BIT                                                           ,
			MidpointChromaSamples                                          = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT                                                ,
			SampledImageYCBCR_ConversionLinearFilter                        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT                           ,
			SampledImageYCBCR_ConversionSeparateReconstructionFilter        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplicit        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplictForcable = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT,
			Disjoint                                                       = VK_FORMAT_FEATURE_DISJOINT_BIT                                                               ,
			CositedChromaSamples                                           = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT                                                 ,

			SampledImageFilterMinMax              = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT             ,   // Provided by VK_VERSION_1_2
			SampledImageFilterCubic_IMG           = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG          ,   // Provided by VK_IMG_filter_cubic
			AccelerationStructureVertexBuffer_KHR = VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR,   // Provided by VK_KHR_ray_tracing
			FragmentDensityMap_EXT                = VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT                ,   // Provided by VK_EXT_fragment_density_map
			TransferSource_KHR                    = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR                        ,   // Provided by VK_KHR_maintenance1
			TransferDestination_KHR               = VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR                        ,   // Provided by VK_KHR_maintenance1
			SampledImageFilterMinMax_EXT          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT         ,   // Provided by VK_EXT_sampler_filter_minmax

			// Provided by VK_KHR_sampler_ycbcr_conversion
			MidpointChromaSamples_KHR                                             = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT_KHR                                                ,
			SampledImageYCBCR_ConversionLinearFilter_KHR                          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR                           ,
			SampledImageYCBCR_ConversionSeparateReconstructionFilter_KHR          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplicit_KHR          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplicit_Forcable_KHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR,
			Disjoint_KHR                                                          = VK_FORMAT_FEATURE_DISJOINT_BIT_KHR                                                               ,
			CositedChromaSamples_KHR                                              = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT_KHR                                                 ,
			SampledImageFilterCubic_EXT                                           = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT                                             ,   // Provided by VK_EXT_filter_cubic

			VT_SpecifyBitmaskable = VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateFlagBits">Specification</a> @ingroup APISpec_Render_Pass */
		enum class EFrameBufferCreateFlag : uint32 { VT_SpecifyBitmaskable = sizeof(uint32) };

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFrontFace">Specification</a> @ingroup APISpec_Rasterization */
		enum class EFrontFace : uint32
		{
			CounterClockwise = VK_FRONT_FACE_COUNTER_CLOCKWISE,
			Clockwise        = VK_FRONT_FACE_CLOCKWISE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageAspectFlagBits">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageAspect : uint32
		{
			Color         = VK_IMAGE_ASPECT_COLOR_BIT             ,
			Depth         = VK_IMAGE_ASPECT_DEPTH_BIT             ,
			Stencil       = VK_IMAGE_ASPECT_STENCIL_BIT           ,
			MetaData      = VK_IMAGE_ASPECT_METADATA_BIT          ,
			Plane_0       = VK_IMAGE_ASPECT_PLANE_0_BIT           ,
			Plane_1       = VK_IMAGE_ASPECT_PLANE_1_BIT           ,
			Plane_2       = VK_IMAGE_ASPECT_PLANE_2_BIT           ,
			MemoryPlane_0 = VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT,
			MemoryPlane_1 = VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT,
			MemroyPlane_2 = VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT,
			MemoryPlane_3 = VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT,
			KHR_Plane_0   = VK_IMAGE_ASPECT_PLANE_0_BIT_KHR       ,
			KHR_Plane_1   = VK_IMAGE_ASPECT_PLANE_1_BIT_KHR       ,
			KHR_Plane_2   = VK_IMAGE_ASPECT_PLANE_2_BIT_KHR       ,

			VT_SpecifyBitmaskable = VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateFlagBits">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageCreateFlag : uint32
		{
			SparseBinding                      = VK_IMAGE_CREATE_SPARSE_BINDING_BIT                       ,
			SparseResidency                    = VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT                     ,
			SparseAliased                      = VK_IMAGE_CREATE_SPARSE_ALIASED_BIT                       ,
			MutableFormat                      = VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT                       ,
			CubeCompatible                     = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT                      ,
			Alias                              = VK_IMAGE_CREATE_ALIAS_BIT                                ,
			SplitInstanceBindRegions           = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT          ,
			_2DArrayCompatible                 = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT                  ,
			BlockTexelViewCompatible           = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT          ,
			ExtendedUsage                      = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT                       ,
			Protected                          = VK_IMAGE_CREATE_PROTECTED_BIT                            ,
			Disjoint                           = VK_IMAGE_CREATE_DISJOINT_BIT                             ,
			CornerSampled                      = VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV                    ,
			SampleLocationsCompatibleDepth_Ext = VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT,
			Subsampled_Ext                     = VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT                       ,
			SplitInstanceBindRegions_KHR       = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR      ,
			_2DArrayCompatible_KHR             = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR              ,
			BlockTexelViewCompatible_KHR       = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR      ,
			ExtendedUsage_KHR                  = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR                   ,
			Disjoint_KHR                       = VK_IMAGE_CREATE_DISJOINT_BIT_KHR                         ,
			Alias_KHR                          = VK_IMAGE_CREATE_ALIAS_BIT_KHR                            ,

			VT_SpecifyBitmaskable = VK_IMAGE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageLayout">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageLayout : uint32
		{
			Undefined                                    = VK_IMAGE_LAYOUT_UNDEFINED                                     ,
			General                                      = VK_IMAGE_LAYOUT_GENERAL                                       ,
			Color_AttachmentOptimal                      = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL                      ,
			DepthStencil_AttachmentOptimal               = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL              ,
			DepthStencil_ReadonlyOptimal                 = VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL               ,
			Shader_ReadonlyOptimal                       = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL                      ,
			TransferSource_Optimal                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL                          ,
			TransferDestination_Optimal                  = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL                          ,
			Preinitalized                                = VK_IMAGE_LAYOUT_PREINITIALIZED                                ,
			Depth_Readonly_Stencil_AttachemntOptimal     = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL    ,
			Depth_Attachment_Stencil_ReadonlyOptimal     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL    ,
			Depth_AttachmentOptimal                      = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL                      ,
			Depth_ReadonlyOptimal                        = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL                       ,
			Stencil_AttachmentOptimal                    = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL                    ,
			Stencil_ReadonlyOptimal                      = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL                     ,
			PresentSource_KHR                            = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR                               ,
			SharedPresent_KHR                            = VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR                            ,
			ShadingRate_Optimal                          = VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV                       ,
			Fragment_DensityMapOptimal_EXT               = VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT              ,
			Depth_Readonly_Stencil_AttachmentOptimal_KHR = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR,
			Depth_Atteachment_StencilReadonlyOptimal_KHR = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR,
			Depth_AttachmentOptimal_KHR                  = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR                  ,
			Depth_ReadonlyOptimal_KHR                    = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR                   ,
			Stencil_AttachmentOptimal_KHR                = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR                ,
			Stencil_ReadonlyOptimal_KHR                  = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR                 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageTiling">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageTiling : uint32
		{
			Optimal                      = VK_IMAGE_TILING_OPTIMAL                ,
			Linear                       = VK_IMAGE_TILING_LINEAR                 ,
			DRM_FormatModifier_Extension = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageType">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageType : uint32
		{
			_1D = VK_IMAGE_TYPE_1D,
			_2D = VK_IMAGE_TYPE_2D,
			_3D = VK_IMAGE_TYPE_3D
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageUsageFlagBits">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageUsage : uint32
		{
			TransferSource          = VK_IMAGE_USAGE_TRANSFER_SRC_BIT            ,
			TransferDestination     = VK_IMAGE_USAGE_TRANSFER_DST_BIT            ,
			Sampled                 = VK_IMAGE_USAGE_SAMPLED_BIT                 ,
			Storage                 = VK_IMAGE_USAGE_STORAGE_BIT                 ,
			Color_Attachment        = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT        ,
			DepthStencil_Attachment = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
			Transient_Attachment    = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT    ,
			Input_Attachemnt        = VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT        ,
			Image_ShadingRate       = VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV   ,
			DensityMap              = VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT,

			VT_SpecifyBitmaskable = VK_IMAGE_USAGE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateFlagBits">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageViewCreateFlag : uint32
		{
			Fragment_DensityMapDynamiic = VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT,

			VT_SpecifyBitmaskable = VK_IMAGE_VIEW_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageView">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class EImageViewType : uint32
		{
			_1D       = VK_IMAGE_VIEW_TYPE_1D        ,
			_2D       = VK_IMAGE_VIEW_TYPE_2D        ,
			_3D       = VK_IMAGE_VIEW_TYPE_3D        ,
			_Cube     = VK_IMAGE_VIEW_TYPE_CUBE      ,
			_1D_Array = VK_IMAGE_VIEW_TYPE_1D_ARRAY  ,
			_2D_Array = VK_IMAGE_VIEW_TYPE_2D_ARRAY  ,
			CubeArray = VK_IMAGE_VIEW_TYPE_CUBE_ARRAY
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkIndexType">Specification</a> @ingroup APISpec_Drawing_Commands */
		enum class EIndexType : uint32
		{
			uInt16   = VK_INDEX_TYPE_UINT16   ,
			uInt32   = VK_INDEX_TYPE_UINT32   ,
			None_KHR = VK_INDEX_TYPE_NONE_KHR ,
			uInt8    = VK_INDEX_TYPE_UINT8_EXT,
			None_NV  = VK_INDEX_TYPE_NONE_NV 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInternalAllocationType">Specification</a> @ingroup APISpec_Memory_Allocation */
		enum class EInternalAllocationType
		{
			Executable = VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlagBits">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class ELogicalDeviceQueueCreateFlag : uint32
		{
			CreateProtected = VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT,

			VT_SpecifyBitmaskable = VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkLogicOp">Specification</a> @ingroup APISpec_The_Framebuffer */
		enum class ELogicOperation : uint32
		{
			Clear         = VK_LOGIC_OP_CLEAR        ,
			And           = VK_LOGIC_OP_AND          ,
			And_Reverse   = VK_LOGIC_OP_AND_REVERSE  ,
			Copy          = VK_LOGIC_OP_COPY         ,
			And_Inverted  = VK_LOGIC_OP_AND_INVERTED ,
			No            = VK_LOGIC_OP_NO_OP        ,
			XOR           = VK_LOGIC_OP_XOR          ,
			Or            = VK_LOGIC_OP_OR           ,
			NOR           = VK_LOGIC_OP_NOR          ,
			Equivalent    = VK_LOGIC_OP_EQUIVALENT   ,
			Int           = VK_LOGIC_OP_INVERT       ,
			OR_Reverse    = VK_LOGIC_OP_OR_REVERSE   ,
			Copy_Inverted = VK_LOGIC_OP_COPY_INVERTED,
			Or_Inverted   = VK_LOGIC_OP_OR_INVERTED  ,
			NAND          = VK_LOGIC_OP_NAND         ,
			Set           = VK_LOGIC_OP_SET          
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeapFlagBits">Specification</a> @ingroup APISpec_Memory_Allocation */
		enum class EMemoryHeapFlag : uint32
		{
			DeviceLocal       = VK_MEMORY_HEAP_DEVICE_LOCAL_BIT      ,
			MultiInstance     = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT    ,
			MultiInstance_KHR = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR,

			VT_SpecifyBitmaskable = VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM
		};

		/**
		@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryOverallocationBehaviorAMD">Specification</a> @ingroup APISpec_Devices_and_Queues
		*/
		enum class EMemoryOverallocationBehaviorAMD : uint32
		{
			Default    = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD   , 
			Allowed    = VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD   , 
			Disallowed = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryPropertyFlagBits">Specification</a> @ingroup APISpec_Memory_Allocation */
		enum class EMemoryPropertyFlag : uint32
		{
			DeviceLocal        = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT       ,
			HostVisible        = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT       ,
			HostCoherent       = VK_MEMORY_PROPERTY_HOST_COHERENT_BIT      , 
			HostCached         = VK_MEMORY_PROPERTY_HOST_CACHED_BIT        ,
			LazilyAllocated    = VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT   ,
			Protected          = VK_MEMORY_PROPERTY_PROTECTED_BIT          ,
			DeviceCoherent_AMD = VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD,
			DeviceUncached_AMD = VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD,

			VT_SpecifyBitmaskable = VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkObjectType">Specification</a> @ingroup APISpec_Debugging */
		enum class EObjectType : uint32
		{
			Unknown                        = VK_OBJECT_TYPE_UNKNOWN                        ,
			Instance                       = VK_OBJECT_TYPE_INSTANCE                       ,
			PhysicalDevice                 = VK_OBJECT_TYPE_PHYSICAL_DEVICE                ,
			Device                         = VK_OBJECT_TYPE_DEVICE                         ,
			Queue                          = VK_OBJECT_TYPE_QUEUE                          ,
			Semaphore                      = VK_OBJECT_TYPE_SEMAPHORE                      ,
			CommandBuffer                  = VK_OBJECT_TYPE_COMMAND_BUFFER                 ,
			Fence                          = VK_OBJECT_TYPE_FENCE                          ,
			DeviceMemory                   = VK_OBJECT_TYPE_DEVICE_MEMORY                  ,
			Buffer                         = VK_OBJECT_TYPE_BUFFER                         ,
			Image                          = VK_OBJECT_TYPE_IMAGE                          ,
			Event                          = VK_OBJECT_TYPE_EVENT                          ,
			QueryPool                      = VK_OBJECT_TYPE_QUERY_POOL                     ,
			BufferView                     = VK_OBJECT_TYPE_BUFFER_VIEW                    ,
			ImageView                      = VK_OBJECT_TYPE_IMAGE_VIEW                     ,
			ShaderModule                   = VK_OBJECT_TYPE_SHADER_MODULE                  ,
			PipelineCache                  = VK_OBJECT_TYPE_PIPELINE_CACHE                 ,
			PipelineLayout                 = VK_OBJECT_TYPE_PIPELINE_LAYOUT                ,
			RenderPass                     = VK_OBJECT_TYPE_RENDER_PASS                    ,
			Pipeline                       = VK_OBJECT_TYPE_PIPELINE                       ,
			DescriptorSetLayout            = VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT          ,
			Sampler                        = VK_OBJECT_TYPE_SAMPLER                        ,
			DescriptorPool                 = VK_OBJECT_TYPE_DESCRIPTOR_POOL                ,
			DescriptorSet                  = VK_OBJECT_TYPE_DESCRIPTOR_SET                 ,
			FrameBuffer                    = VK_OBJECT_TYPE_FRAMEBUFFER                    ,
			CommandPool                    = VK_OBJECT_TYPE_COMMAND_POOL                   ,
			Sampler_YCBCR_Conversion       = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION       ,
			DescriptorUpdateTemplate       = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE     ,
			Surface_KHR                    = VK_OBJECT_TYPE_SURFACE_KHR                    ,
			SwapChain_KHR                  = VK_OBJECT_TYPE_SWAPCHAIN_KHR                  ,
			Display_KHR                    = VK_OBJECT_TYPE_DISPLAY_KHR                    ,
			DisplayMode_KHR                = VK_OBJECT_TYPE_DISPLAY_MODE_KHR               ,
			DebugReportCallback_EXT        = VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT      ,
			DebugUtilsMessenger_EXT        = VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT      ,
			AccelerationStructure_KHR      = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR     ,
			ValidationCache_EXT            = VK_OBJECT_TYPE_VALIDATION_CACHE_EXT           ,
			Intel_PerformanceConfiguration = VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL,
			DeferredOperation_KHR          = VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR         ,
			IndirectCommandsLayout         = VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV    ,
			//Extension_PrivateDataSlot = VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT,   // TODO: is this ok?
			PrivateDataSlot_EXT            = 1000295000,
			DescriptorUpdateTemplate_KHR   = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR ,
			Sampler_YCBCR_Conversion_KHR   = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR   ,
			AccelerationStructure          = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterDescriptionFlagBitsKHR">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EPerformanceCounterDescriptionFlag : uint32
		{
			PerformanceImpacting = VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR,
			ConcurrentlyImpacted = VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR,

			VT_SpecifyBitmaskable = VK_PERFORMANCE_COUNTER_DESCRIPTION_FLAG_BITS_MAX_ENUM_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterScopeKHR">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EPerformanceCounterScope : uint32
		{
			Performance_CommandBuffer = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR,
			Performance_RenderPass    = VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR   ,
			Performance_Command       = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR       ,
			Query_Buffer              = VK_QUERY_SCOPE_COMMAND_BUFFER_KHR              ,
			Query_RenderPass          = VK_QUERY_SCOPE_RENDER_PASS_KHR                 ,
			Query_Command             = VK_QUERY_SCOPE_COMMAND_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterStorageKHR">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EPerformanceCounterStorage : uint32
		{
			VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR = 0,
			VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR = 1,
			VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR = 2,
			VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR = 3,
			VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR = 4,
			VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR = 5,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterUnitKHR">Specification</a> @ingroup APISpec_Devices_and_Queues */
		enum class EPerformanceCounterUnit : uint32
		{
			Generic        = VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR         ,
			Percentage     = VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR      ,
			Nanoseconds    = VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR     ,
			Bytes          = VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR           ,
			BytesPerSecond = VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR,
			Kelvin         = VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR          ,
			Watts          = VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR           ,
			Volts          = VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR           ,
			Amps           = VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR            ,
			Hertz          = VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR           ,
			Cycles         = VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR          
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineBindPoint">Specification</a> @ingroup APISpec_Pipelines */
		enum class EPipelineBindPoint : uint32
		{
			Graphics = VK_PIPELINE_BIND_POINT_GRAPHICS,
			Compute  = VK_PIPELINE_BIND_POINT_COMPUTE 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateFlagBits">Specification</a> @ingroup APISpec_Pipelines */
		enum class EPipelineCacheCreateFlag : uint32
		{
			Externally_Synchronized = VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT,

			VT_SpecifyBitmaskable = VK_PIPELINE_CACHE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCreateFlagBits">Specification</a> @ingroup APISpec_Pipelines */
		enum class EPipelineCreateFlag : uint32
		{
			DisableOptimization                    = VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT                        ,
			AllowDerivatives                       = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT                           ,
			Derivative                             = VK_PIPELINE_CREATE_DERIVATIVE_BIT                                  ,
			ViewIndexFromDeviceIndex               = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT                ,
			DispatchBase                           = VK_PIPELINE_CREATE_DISPATCH_BASE_BIT                               ,
			Raytracing_NoNull_AnyHit_Shaders       = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR     ,
			Raytracing_NoNull_ClosestHit_Shaders   = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR ,
			Raytracing_NoNull_Miss_Shaders         = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR        ,
			Raytracing_NoNull_Intersection_Shaders = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR,
			Raytracing_SkipTriangles               = VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR              ,
			Raytracing_Skip_AABBS                  = VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR                  ,
			DeferCompile                           = VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV                            ,
			CaptureStatistics                      = VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR                      ,
			CaptureInternalRepresentations         = VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR        ,
			IndirectBindable                       = VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV                        ,
			Library                                = VK_PIPELINE_CREATE_LIBRARY_BIT_KHR                                 ,
			FailOn_PipelineCompileRequired         = VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT       ,
			EarlyReturnOn_Failure                  = VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT                 ,
			DispatchBase2                          = VK_PIPELINE_CREATE_DISPATCH_BASE                                   ,
			ViewIndexFromDeviceInex                = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR            ,
			DispatchBase_KHR                       = VK_PIPELINE_CREATE_DISPATCH_BASE_KHR                               ,

			VT_SpecifyBitmaskable = VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineShaderStageCreateFlagBits">Specification</a> @ingroup APISpec_Pipelines */
		enum class EPipelineShaderStageCreateFlag : uint32
		{
			AllowVaryingSubgroupSize = VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT,
			RequireFullSubgroups     = VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT     ,

			VT_SpecifyBitmaskable = VK_PIPELINE_SHADER_STAGE_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineStageFlagBits">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class EPipelineStageFlag : uint32
		{
			TopOfPipe                    = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT                   ,
			DrawIndirect                 = VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT                 ,
			VertexInput                  = VK_PIPELINE_STAGE_VERTEX_INPUT_BIT                  ,
			VertexShader                 = VK_PIPELINE_STAGE_VERTEX_SHADER_BIT                 ,
			TessellationControlShader    = VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT   ,
			TessellationEvaluationShader = VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT,
			GeometryShader               = VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT               ,
			FragementShader              = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT               ,
			EarlyFragmentTests           = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT          ,
			LateFragmentTests            = VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT           ,
			ColorAttachmentOutput        = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT       ,
			ComputeShader                = VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT                ,
			Transfer                     = VK_PIPELINE_STAGE_TRANSFER_BIT                      ,
			BottomOfPipe                 = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT                ,
			Host                         = VK_PIPELINE_STAGE_HOST_BIT                          ,
			AllGraphics                  = VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT                  ,
			AllCommands                  = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT                  ,

			VT_SpecifyBitmaskable = VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#primsrast-polygonmode">Specification</a> @ingroup APISpec_Rasterization */
		enum class EPolygonMode : uint32
		{
			Fill              = VK_POLYGON_MODE_FILL             ,
			Line              = VK_POLYGON_MODE_LINE             ,
			Point             = VK_POLYGON_MODE_POINT            ,
			NV_Fill_Rectangle = VK_POLYGON_MODE_FILL_RECTANGLE_NV
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPresentModeKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
		enum class EPresentationMode : uint32
		{
			Immediate               = VK_PRESENT_MODE_IMMEDIATE_KHR                ,
			Mailbox                 = VK_PRESENT_MODE_MAILBOX_KHR                  ,
			FIFO                    = VK_PRESENT_MODE_FIFO_KHR                     ,
			FIFO_Relaxed            = VK_PRESENT_MODE_FIFO_RELAXED_KHR             ,
			SharedDemandRefresh     = VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR    ,
			SharedContinuousRefresh = VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPrimitiveTopology">Specification</a> @ingroup APISpec_Drawing_Commands */
		enum class EPrimitiveTopology : uint32
		{
			PointList                   = VK_PRIMITIVE_TOPOLOGY_POINT_LIST                   ,
			LineList                    = VK_PRIMITIVE_TOPOLOGY_LINE_LIST                    ,
			LineStrip                   = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP                   ,
			TriangleList                = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST                ,
			TriangleStrip               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP               ,
			TriangleFan                 = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN                 ,
			LineList_WithAdjacency      = VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY     ,
			LineStrip_WithAdjacency     = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY    ,
			TriangleList_WithAdjaceny   = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY ,
			TriangleStrip_WithAdjacency = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY,
			PatchList                   = VK_PRIMITIVE_TOPOLOGY_PATCH_LIST                    
		};

		/**
		@brief Supported physical device types.

		@details
		The physical device type is advertised for informational purposes only, and does not directly affect the operation of the system. 
		However, the device type may correlate with other advertised properties or capabilities of the system, such as how many memory heaps there are.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceType.html">Specification</a> 

		@ingroup APISpec_Devices_and_Queues
		*/
		enum class EPhysicalDeviceType : uint32
		{
			Other          = VK_PHYSICAL_DEVICE_TYPE_OTHER         ,
			IntergratedGPU = VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU,
			DiscreteGPU    = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU  ,
			VirtualGPU     = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU   ,
			CPU            = VK_PHYSICAL_DEVICE_TYPE_CPU
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPointClippingBehavior">Specification</a> @ingroup APISpec_Fixed-Function_Vertex_Post-Processing */
		enum class EPointClippingBehavior : uint32
		{
			AllClipPlanes      = VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES      , 
			UserClipPlanesOnly = VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY, 

			// Provided by VK_KHR_maintenance2
			AllClipPlanes_KHR      = VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR      , 
			UserClipPlanesOnly_KHR = VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryControlFlagBits">Specification</a> @ingroup APISpec_Queries */
		enum class EQueryControlFlags : uint32
		{
			Precise = VK_QUERY_CONTROL_PRECISE_BIT,

			VT_SpecifyBitmaskable = VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM
		};

		/**
		@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFlagBits">Specification</a> @ingroup APISpec_Devices_and_Queues
		*/
		enum class EQueueFlag : uint32
		{
			Graphics      = VK_QUEUE_GRAPHICS_BIT      ,
			Compute       = VK_QUEUE_COMPUTE_BIT       ,
			Transfer      = VK_QUEUE_TRANSFER_BIT      ,
			SparseBinding = VK_QUEUE_SPARSE_BINDING_BIT,
			Protected     = VK_QUEUE_PROTECTED_BIT     ,

			VT_SpecifyBitmaskable = VK_QUEUE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryPipelineStatisticFlagBits">Specification</a> @ingroup APISpec_Queries */
		enum class EQueryPipelineStatisticFlag : uint32
		{
			AssemblyVertices                        = VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT                   ,
			AssemblyPrimitives                      = VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT                 ,
			VertexShaderInovcations                 = VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT                 ,
			GeometryShaderInvocations               = VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT               ,
			GeometryShaderPrimitives                = VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT                ,
			ClippingInocation                       = VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT                      ,
			ClippingPrimitives                      = VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT                       ,
			FragmentShaderInvoations                = VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT               ,
			TessellationControlShaderPatches        = VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT       ,
			TessellationEvaluationShaderInvocations = VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT,
			ComputeShaderInvocations                = VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT                ,

			VT_SpecifyBitmaskable = VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkResolveModeFlagBits">Specification</a> @ingroup APISpec_Render_Pass */
		enum class EResolveModeFlags : uint32
		{
			None       = VK_RESOLVE_MODE_NONE ,
			SampleZero = VK_RESOLVE_MODE_SAMPLE_ZERO_BIT ,
			Average    = VK_RESOLVE_MODE_AVERAGE_BIT ,
			Min        = VK_RESOLVE_MODE_MIN_BIT ,
			Max        = VK_RESOLVE_MODE_MAX_BIT ,

			// Provided by VK_KHR_depth_stencil_resolve
			None_KHR       = VK_RESOLVE_MODE_NONE_KHR           ,
			SampleZero_KHR = VK_RESOLVE_MODE_SAMPLE_ZERO_BIT_KHR,
			Average_KHR    = VK_RESOLVE_MODE_AVERAGE_BIT_KHR    ,
			Min_KHR        = VK_RESOLVE_MODE_MIN_BIT_KHR        ,
			Max_KHR        = VK_RESOLVE_MODE_MAX_BIT_KHR        ,

			VT_SpecifyBitmaskable = VK_RESOLVE_MODE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkResult">Specification</a> @ingroup APISpec_Fundamentals */
		enum class EResult : sint32
		{
			Success                                         = VK_SUCCESS                                           ,
			Not_Ready                                       = VK_NOT_READY                                         ,
			Timeout                                         = VK_TIMEOUT                                           ,
			Event_Set                                       = VK_EVENT_SET                                         ,
			Event_Reset                                     = VK_EVENT_RESET                                       ,
			Incomplete                                      = VK_INCOMPLETE                                        ,
			Error_OutOfHostMemory                           = VK_ERROR_OUT_OF_HOST_MEMORY                          ,
			Error_OutOfDeviceMemory                         = VK_ERROR_OUT_OF_DEVICE_MEMORY                        ,
			Error_InitalizationFailed                       = VK_ERROR_INITIALIZATION_FAILED                       ,
			Error_DeviceLost                                = VK_ERROR_DEVICE_LOST                                 ,
			Error_MemoryMap_Failed                          = VK_ERROR_MEMORY_MAP_FAILED                           ,
			Error_LayerNotPresent                           = VK_ERROR_LAYER_NOT_PRESENT                           ,
			Error_ExtensionNotPresent                       = VK_ERROR_EXTENSION_NOT_PRESENT                       ,
			Error_FeatureNotPresent                         = VK_ERROR_FEATURE_NOT_PRESENT                         ,
			Error_IncompatibleDriver                        = VK_ERROR_INCOMPATIBLE_DRIVER                         ,
			Error_TooManyObjects                            = VK_ERROR_TOO_MANY_OBJECTS                            ,
			Error_FormatNotSupported                        = VK_ERROR_FORMAT_NOT_SUPPORTED                        ,
			Error_FragmentedPool                            = VK_ERROR_FRAGMENTED_POOL                             ,
			Error_Unknown                                   = VK_ERROR_UNKNOWN                                     ,
			Error_OutOfPoolMemory                           = VK_ERROR_OUT_OF_POOL_MEMORY                          ,
			Error_InvalidExternalHandle                     = VK_ERROR_INVALID_EXTERNAL_HANDLE                     ,
			Error_Fragmentation                             = VK_ERROR_FRAGMENTATION                               ,
			Error_InvalidOpaqueCaptureAddress               = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS              ,
			Error_SurfaceLost_KHR                           = VK_ERROR_SURFACE_LOST_KHR                            ,
			Error_NativeWindowInUse_KHR                     = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR                    ,
			Suboptimal_KHR                                  = VK_SUBOPTIMAL_KHR                                    ,
			Error_OutOfDate_KHR                             = VK_ERROR_OUT_OF_DATE_KHR                             ,
			Error_IncompatbileDisplay_KHR                   = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR                    ,
			Error_Extension_ValidationFailed                = VK_ERROR_VALIDATION_FAILED_EXT                       ,
			Error_InvalidShader_NV                          = VK_ERROR_INVALID_SHADER_NV                           ,
			Error_IncompatibleVersion_KHR                   = VK_ERROR_INCOMPATIBLE_VERSION_KHR                    ,
			Error_Invalid_DRMFormat_ModifierPlaneLayout_EXT = VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT,
			Error_NotPermitted_EXT                          = VK_ERROR_NOT_PERMITTED_EXT                           ,
			Error_FullScreenExculsiveMode_Lost_EXT          = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT         ,
			Thread_Idle_KHR                                 = VK_THREAD_IDLE_KHR                                   ,
			Thread_Done_KHR                                 = VK_THREAD_DONE_KHR                                   ,
			OperationDeferred_KHR                           = VK_OPERATION_DEFERRED_KHR                            ,
			OperationNotDeferred_KHR                        = VK_OPERATION_NOT_DEFERRED_KHR                        ,
			PipelineCompileRequired_EXT                     = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT               ,
			Error_OutOfPoolMemory_KHR                       = VK_ERROR_OUT_OF_POOL_MEMORY_KHR                      ,
			Error_InvalidExternalHandle_KHR                 = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR                 ,
			Error_Fragmentation_EXT                         = VK_ERROR_FRAGMENTATION_EXT                           ,
			Error_InvalidDeviceAddress_EXT                  = VK_ERROR_INVALID_DEVICE_ADDRESS_EXT                  ,
			Error_InvalidOpaqueCaptureAddress_KHR           = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR          ,
			Error_PipelineCompileRequired_EXT               = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampleCountFlagBits">Specification</a> @ingroup APISpec_Limits */
		enum class ESampleCount : uint32
		{
			_1  = VK_SAMPLE_COUNT_1_BIT ,
			_2  = VK_SAMPLE_COUNT_2_BIT ,
			_4  = VK_SAMPLE_COUNT_4_BIT ,
			_8  = VK_SAMPLE_COUNT_8_BIT ,
			_16 = VK_SAMPLE_COUNT_16_BIT,
			_32 = VK_SAMPLE_COUNT_32_BIT,
			_64 = VK_SAMPLE_COUNT_64_BIT,

			VT_SpecifyBitmaskable = VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerAddressMode">Specification</a> @ingroup VkSamplerAddressMode */
		enum class ESamplerAddressMode : uint32
		{
			Repeat         = VK_SAMPLER_ADDRESS_MODE_REPEAT         ,
			MirroredRepeat = VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
			ClampToEdge    = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE  ,
			ClampToBorder  = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
			
			// Provided by VK_VERSION_1_2, VK_KHR_sampler_mirror_clamp_to_edge
			MirrorClampToEdge     = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE    ,
			MirrorClampToEdge_KHR = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateFlagBits">Specification</a> @ingroup VkSamplerCreateFlagBits */
		enum class ESamplerCreateFlag : uint32
		{
			Subsampled_EXT                     = VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT                      ,
			SubsampledCoarseReconstruction_EXT = VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT,

			VT_SpecifyBitmaskable = VK_SAMPLER_CREATE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerMipmapMode">Specification</a> @ingroup APISpec_Samplers */
		enum class ESamplerMipmapMode : uint32
		{
			Nearest = VK_SAMPLER_MIPMAP_MODE_NEAREST,
			Linear  = VK_SAMPLER_MIPMAP_MODE_LINEAR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreImportFlagBits">Specification</a> @ingroup VkSemaphoreImportFlagBits */
		enum class ESemaphoreImportFlag
		{
			Temporary     = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT    ,
			Temporary_KHR = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR,

			VT_SpecifyBitmaskable = VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreType">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class ESemaphoreType : uint32
		{
			Binary       = VK_SEMAPHORE_TYPE_BINARY      ,
			Timeline     = VK_SEMAPHORE_TYPE_TIMELINE    ,
			Binary_KHR   = VK_SEMAPHORE_TYPE_BINARY_KHR  ,
			Timeline_KHR = VK_SEMAPHORE_TYPE_TIMELINE_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitFlagBits">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
		enum class ESemaphoreWaitFlag : uint32
		{
			Any     = VK_SEMAPHORE_WAIT_ANY_BIT    ,
			Any_KHR = VK_SEMAPHORE_WAIT_ANY_BIT_KHR,

			VT_SpecifyBitmaskable = VK_SEMAPHORE_WAIT_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderFloatControlsIndependence">Specification</a> @ingroup APISpec_Limits */
		enum class EShaderFloatControlIndependence : uint32
		{
			_32Bit_Only = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY,
			All         = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL        ,
			None        = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE       ,

			// Provided by VK_KHR_shader_float_controls
			_32Bit_Only_KHR = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY_KHR,
			All_KHR         = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL_KHR        ,
			None_KHR        = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE_KHR       ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderStageFlagBits">Specification</a> @ingroup APISpec_Pipelines */
		enum class EShaderStageFlag : uint32
		{
			Vertex                 = VK_SHADER_STAGE_VERTEX_BIT                 ,
			TessellationControl    = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT   ,
			TessellationEvaluation = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT,
			Geometry               = VK_SHADER_STAGE_GEOMETRY_BIT               ,
			Fragment               = VK_SHADER_STAGE_FRAGMENT_BIT               ,
			Compute                = VK_SHADER_STAGE_COMPUTE_BIT                ,
			Graphics               = VK_SHADER_STAGE_ALL_GRAPHICS               ,
			All                    = VK_SHADER_STAGE_ALL                        ,
			Raygen_KHR             = VK_SHADER_STAGE_RAYGEN_BIT_KHR             ,
			AnyHit_KHR             = VK_SHADER_STAGE_ANY_HIT_BIT_KHR            ,
			ClosestHit_KHR         = VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR        ,
			Miss_KHR               = VK_SHADER_STAGE_MISS_BIT_KHR               ,
			Intersection_KHR       = VK_SHADER_STAGE_INTERSECTION_BIT_KHR       ,
			Callable_KHR           = VK_SHADER_STAGE_CALLABLE_BIT_KHR           ,
			Task_NV                = VK_SHADER_STAGE_TASK_BIT_NV                ,
			Mesh_NV                = VK_SHADER_STAGE_MESH_BIT_NV                ,
			Raygen_NV              = VK_SHADER_STAGE_RAYGEN_BIT_NV              ,
			AnyHit_NV              = VK_SHADER_STAGE_ANY_HIT_BIT_NV             ,
			ClosestHit_NV          = VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV         ,
			Miss_NV                = VK_SHADER_STAGE_MISS_BIT_NV                ,
			Intersection_NV        = VK_SHADER_STAGE_INTERSECTION_BIT_NV        ,
			Callable_NV            = VK_SHADER_STAGE_CALLABLE_BIT_NV            ,

			VT_SpecifyBitmaskable = VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSharingMode">Specification</a> @ingroup APISpec_Resource_Creation */
		enum class ESharingMode : uint32
		{
			Exclusive  = VK_SHARING_MODE_EXCLUSIVE ,
			Concurrent = VK_SHARING_MODE_CONCURRENT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkStencilOp">Specification</a> @ingroup APISpec_Fragment_Operations */
		enum class EStencilOperation : uint32
		{
			Keep              = VK_STENCIL_OP_KEEP               ,
			Zero              = VK_STENCIL_OP_ZERO               ,
			Replace           = VK_STENCIL_OP_REPLACE            ,
			IncrementAndClamp = VK_STENCIL_OP_INCREMENT_AND_CLAMP,
			DecrementAndClamp = VK_STENCIL_OP_DECREMENT_AND_CLAMP,
			Invert            = VK_STENCIL_OP_INVERT             ,
			IncrementAndWrap  = VK_STENCIL_OP_INCREMENT_AND_WRAP ,
			DecrementAndWrap  = VK_STENCIL_OP_DECREMENT_AND_WRAP 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkStructureType">Specification</a> @ingroup APISpec_Fundamentals */
		enum class EStructureType : uint32
		{
			ApplicationInformation                                      = VK_STRUCTURE_TYPE_APPLICATION_INFO                                               ,
			Instance_CreateInfo                                         = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO                                           ,
			DeviceQueue_CreateInfo                                      = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO                                       ,
			Device_CreateInfo                                           = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO                                             ,
			SubmitInfo                                                  = VK_STRUCTURE_TYPE_SUBMIT_INFO                                                    ,
			MemoryAllocateInfo                                          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO                                           ,
			MappedMemoryRange                                           = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE                                            ,
			BindSparseInfo                                              = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO                                               ,
			Fence_CreateInfo                                            = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO                                              ,
			Semaphore_CreateInfo                                        = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO                                          ,
			Event_CreateInfo                                            = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO                                              ,
			QueryPool_CreateInfo                                        = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO                                         ,
			Buffer_CreateInfo                                           = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO                                             ,
			BufferView_CreateInfo                                       = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO                                        ,
			Image_CreateInfo                                            = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO                                              ,
			ImageView_CreateInfo                                        = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO                                         ,
			ShaderModule_CreateInfo                                     = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO                                      ,
			Pipeline_Cache_CreateInfo                                   = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO                                     ,
			Pipeline_ShaderStage_CreateInfo                             = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO                              ,
			Pipeline_VertexInputState_CreateInfo                        = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO                        ,
			Pipeline_InputAssemblyState_CreateInfo                      = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO                      ,
			Pipeline_TessellationState_CreateInfo                       = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO                        ,
			Pipeline_ViewportState_CreateInfo                           = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO                            ,
			Pipeline_RasterizationState_CreateInfo                      = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO                       ,
			Pipeline_MultisampleState_CreateInfo                        = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO                         ,
			Pipeline_DepthStencilState_CreateInfo                       = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO                       ,
			Pipeline_ColorBlendState_CreateInfo                         = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO                         ,
			Pipeline_DynamicState_CreateInfo                            = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO                             ,
			GraphicsPipeline_CreateInfo                                 = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO                                  ,
			ComputePipeline_CreateInfo                                  = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO                                   ,
			Pipeline_Layout_CreateInfo                                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO                                    ,
			Sampler_CreateInfo                                          = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO                                            ,
			Descriptor_SetLayout_CreateInfo                             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO                              ,
			Descriptor_Pool_CreateInfo                                  = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO                                    ,
			Descriptor_SetAllocateInfo                                  = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO                                   ,
			WriteDescriptor_Set                                         = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET                                           ,
			CopyDescriptor_Set                                          = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET                                            ,
			Framebuffer_CreateInfo                                      = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO                                        ,
			RenderPass_CreateInfo                                       = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO                                        ,
			CommandPool_CreateInfo                                      = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO                                       ,
			CommandBuffer_AllocateInfo                                  = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO                                   ,
			CommandBuffer_InheritanceInfo                               = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO                                ,
			CommandBuffer_BeginInfo                                     = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO                                      ,
			RenderPass_BeginInfo                                        = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO                                         ,
			BufferMemory_Barrier                                        = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER                                          ,
			ImageMemory_Barrier                                         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER                                           ,
			Memory_Barrier                                              = VK_STRUCTURE_TYPE_MEMORY_BARRIER                                                 ,
			LoaderInstance_CreateInfo                                   = VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO                                    ,
			LoaderDevice_CreateInfo                                     = VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO                                      ,
			PhysicalDevice_SubgroupProperties                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES                            ,
			BindBuffer_MemoryInfo                                       = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO                                        ,
			BindImage_MemoryInfo                                        = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO                                         ,
			PhysicalDevice_16Bit_StorageFeatures                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES                         ,
			MemoryDedicatedRequirements                                 = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS                                  ,
			MemoryDedicated_AllocateInfo                                = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO                                 ,
			Memory_AllocateFlagsInfo                                    = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO                                     ,
			DeviceGroup_RenderPass_BeginInfo                            = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO                            ,
			DeviceGroup_CommandBuffer_BeginInfo                         = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO                         ,
			DeviceGroup_SubmitInfo                                      = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO                                       ,
			DeviceGroup_BindSparseInfo                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO                                  ,
			BindBuffer_MemoryDevice_GroupInfo                           = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO                           ,
			BindImage_MemoryDevice_GroupInfo                            = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO                            ,
			PhysicalDevice_GroupProperties                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES                               ,
			Device_GroupDevice_CreateInfo                               = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO                                ,
			BufferMemory_RequirementsInfo_2                             = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2                              ,
			ImageMemory_RequirementsInfo_2                              = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2                               ,
			ImageSparseMemory_RequirementsInfo_2                        = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2                        ,
			MemoryRequirements_2                                        = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2                                          ,
			SparseImage_MemoryRequirements_2                            = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2                             ,
			PhysicalDevice_Features_2                                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2                                     ,
			PhysicalDevice_Properties_2                                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2                                   ,
			Format_Properties_2                                         = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2                                            ,
			ImageFormat_Properties_2                                    = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2                                      ,
			PhysicalDevice_ImageFormatInfo_2                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2                            ,
			QueueFamily_Properties_2                                    = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2                                      ,
			PhysicalDevice_MemoryProperties_2                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2                            ,
			SpareImageFormat_Properites2                                = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2                               ,
			PhysicalDevice_SparceImageFormatInfo_2                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2                     ,
			PhysicalDevice_PointClippingProperites                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES                      ,
			RenderPass_InputAttachmentAspectCreateInfo                  = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO                ,
			ImageViewUsage_CreateInfo                                   = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO                                   ,
			Pipeline_TessellationDomainOriginState_CreateInfo           = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO          ,
			RenderPassMulitivew_CreateInfo                              = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO                              ,
			PhysicalDevice_MultiviewFeatures                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES                             ,
			PhysicalDevice_MultivewProperties                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES                           ,
			PhysicalDevice_PointersFeatures                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES                     ,
			ProtectedSubmitInfo                                         = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO                                          ,
			PhysicalDevice_ProtectedMemoryFeatures                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES                      ,
			PhysicalDevice_ProtectedMemoryProperties                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES                    ,
			DeviceQueueInfo2                                            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2                                            ,
			SamplerYCBCR_Conversion_CreateInfo                          = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO                           ,
			SamplerYCBCR_Conversion_Info                                = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO                                  ,
			BindImagePlane_MemoryInfo                                   = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO                                   ,
			ImagePlaneMemory_RequirementsInfo                           = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO                           ,
			PhysicalDevice_SamplerYCBCR_ConversionFeatures              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES              ,
			SamplerYCBCR_Conversion_ImageFormatProperties               = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES               ,
			DescriptorUpdateTemplate_CreateInfo                         = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO                         ,
			PhysicalDevice_ExternalImageFormat_Info                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO                     ,
			ExternalImageFormat_Properties                              = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES                               ,
			PhysicalDevice_ExternalBuffer_Info                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO                           ,
			ExternalBuffer_Properites                                   = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES                                     ,
			PhysicalDevice_ID_Properties                                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES                                  ,
			ExternalMemoryBuffer_CreateInfo                             = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO                             ,
			ExtenralMemoryImage_CreateInfo                              = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO                              ,
			ExternalMemoryAllocate_Info                                 = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO                                    ,
			PhysicalDevice_ExternalFence_Info                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO                            ,
			ExternalFence_Properties                                    = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES                                      ,
			ExportFence_CreateInfo                                      = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO                                       ,
			ExportSemaphore_CreateInfo                                  = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO                                   ,
			PhysicalDevice_ExternalSemaphore_Info                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO                        ,
			ExternalSemaphore_Properties                                = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES                                  ,
			PhysicalDevice_Maintence_3_Properties                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES                       ,
			Descriptor_SetLayoutSupport                                 = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT                                  ,
			PhysicalDevice_ShaderDrawParameters_Features                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES                ,
			PhysicalDevice_Vulkan_1_1_Features                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES                            ,
			PhysicalDevice_Vulkan_1_1_Properties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES                          ,
			PhysicalDevice_Vulkan_1_2_Features                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES                            ,
			PhysicalDevice_Vulkan_1_2_Properties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES                          ,
			ImageFormatList_CreateInfo                                  = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO                                  ,
			AttachmentDescription_2                                     = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2                                       ,
			AttachmentReference_2                                       = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2                                         ,
			SubpassDescription_2                                        = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2                                          ,
			SubpassDependency_2                                         = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2                                           ,
			RenderPass_CreateInfo_2                                     = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2                                      ,
			Subpass_BeginInfo                                           = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO                                             ,
			Subpass_EndInfo                                             = VK_STRUCTURE_TYPE_SUBPASS_END_INFO                                               ,
			PhysicalDevice_8BitStorageFeatures                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES                          ,
			PhysicalDevice_DriverProperites                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES                              ,
			Physicaldevice_ShaderAtomic_Int64Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES                   ,
			PhysicalDevice_ShaderFloat16_Int8Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES                   ,
			PhysicalDevice_FloatControlsProperties                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES                      ,
			Descriptor_SetLayoutBindingFlags_CreateInfo                 = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO                ,
			PhysicalDevice_Descriptor_IndexingFeatures                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES                   ,
			PhysicalDevice_Descriptor_IndexingProperties                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES                 ,
			Descriptor_SetVariable_DescriptorCount_AllocateInfo         = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO         ,
			Descriptor_SetVariable_Descriptor_CountLayoutSupport        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT        ,
			PhysicalDevice_DepthStencil_ResolveProperties               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES               ,
			SubpassDescription_DepthStencilResolve                      = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE                      ,
			PhysicalDevice_ScalarBlockLayoutFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES                   ,
			ImageStencilUsage_CreateInfo                                = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO                                ,
			PhysicalDevice_SamplerFilterMinMax_Properties               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES               ,
			Sampler_ReductionMode_CreateInfo                            = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO                             ,
			PhysicalDevice_VulkanMemoryModelFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES                   ,
			PhysicalDevice_ImagelessFramebufferFeatures                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES                 ,
			FramebufferAttachments_CreateInfo                           = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO                            ,
			FramebufferAttachment_ImageInfo                             = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO                              ,
			RenderPassAttachment_BeginInfo                              = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO                              ,
			PhysicalDevice_UniformBuffer_StandardLayoutFeatures         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES        ,
			PhysicalDevice_ShaderSubgroup_ExtendedTypesFeatures         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES        ,
			PhysicalDevice_SeparateDepthStencilLayout_Features          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES        ,
			AttachmentReference_StencilLayout                           = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT                            ,
			AttachmentDescription_StencilLayout                         = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT                          ,
			PhysicalDevice_HostQueryReset_Features                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES                      ,
			PhysicalDevice_TimelineSemaphore_Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES                    ,
			PhysicalDevice_TimelineSemaphore_Properties                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES                  ,
			SemaphoreType_CreateInfo                                    = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO                                     ,
			TimelineSemaphore_SubmitInfo                                = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO                                 ,
			Semaphore_WaitInfo                                          = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO                                            ,
			Semaphore_SignalInfo                                        = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO                                          ,
			PhysicalDevice_BufferDeviceAddress_Features                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES                 ,
			BufferDeviceAddress_Info                                    = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO                                     ,
			Buffer_OpaqueCaptureAddress_CreateInfo                      = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO                      ,
			Memory_OpaqueCaptureAddress_AllocateInfo                    = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO                    ,
			DeviceMemory_OpaqueCaptureAddress_Info                      = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO                      ,
			SwapChain_CreateInfo_KHR                                    = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR                                      ,
			PresentInfo_KHR                                             = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR                                               ,
			DeviceGroup_PrsentCapabilitties_KHR                         = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR                          ,
			ImageSwapChain_CreateInfo_KHR                               = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR                                ,
			BindImageMemory_SwapChain_Info_KHR                          = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR                           ,
			Acquire_NextImage_Info_KHR                                  = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR                                    ,
			DeviceGroup_PrsentInfo_KHR                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR                                  ,
			DeviceGroup_SwapChain_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR                         ,
			DisplayMode_CreateInfo_KHR                                  = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR                                   ,
			DisplaySurface_CreateInfo_KHR                               = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR                                ,
			DispalyPrsent_Info_KHR                                      = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR                                       ,
			XLIB_Surface_CreateInfo_KHR                                 = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR                                   ,
			XCB_Surface_CreateInfo_KHR                                  = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR                                    ,
			Wayland_Surface_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR                                ,
			Andriod_Surface_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR                                ,
			Win32_Surface_CreateInfo_KHR                                = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR                                  ,
			DebugReport_Callback_CreateInfo_EXT                         = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT                          ,
			PipelineRasterizationState_RasterizationOrder_AMD           = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD           ,
			DebugMarkerObject_NameInfo_EXT                              = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT                              ,
			DebugMarkerObject_TagInfo_EXT                               = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT                               ,
			DebugMarker_MarkerInfo_EXT                                  = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT                                   ,
			DedicatedAllocationImage_CreateInfo_NV                      = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV                      ,
			DedicatedAllocationBuffer_CreateInfo_NV                     = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV                     ,
			DedicatedAllocationMemory_AllocateInfo_NV                   = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV                   ,
			PhysicalDevice_TransformFeedback_Features_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT                ,
			PhysicalDevice_TransformFeedback_Properties_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT              ,
			PipelineRasterizationStateStream_CrateInfo_EXT              = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT            ,
			ImageView_HandleInfo_NVX                                    = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX                                     ,
			Texture_LOD_GatherFormat_Properties_AMD                     = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD                       ,
			StreamDescriptorSurface_CreateInfo_GGP                      = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP                      ,
			PhysicalDevice_CornerSampledImage_Features_NV               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV               ,
			ExternalMemoryImage_CreateInfo_NV                           = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV                           ,
			ExportMemory_AllocateInfo_NV                                = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV                                 ,
			ImportMemory_Win32_HandleInfo_NV                            = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV                             ,
			ExportMemory_Win32_HandleInfo_NV                            = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV                             ,
			Win32_KeyedMutex_AquireRelease_Info_NV                      = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV                      ,
			ValidationFlags_EXT                                         = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT                                           ,
			VI_Surface_CreateInfo_NN                                    = VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN                                      ,
			PhysicalDevice_TextureCompression_ASTC_HDR_Features_EXT     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT      ,
			ImageView_ASTC_DecodeMode_EXT                               = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT                                ,
			PhysicalDevice_ASTC_Decode_Features_EXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT                       ,
			ImportMemory_Win32Handle_Info_KHR                           = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR                            ,
			ExportMemory_Win32Handle_Info_KHR                           = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR                            ,
			Memory_Win32Handle_Properties_KHR                           = VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR                             ,
			Memory_Get_Win32Handle_Info_KHR                             = VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR                               ,
			Import_Memory_FD_INFO_KHR                                   = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR                                      ,
			Memory_FD_Properites_KHR                                    = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR                                       ,
			Memory_GET_FD_Info_KHR                                      = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR                                         ,
			Win32_MutexAquireRelease_Info_KHR                           = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR                     ,
			ImportSemaphore_Win32Handle_Info_KHR                        = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR                         ,
			ExportSemaphore_Win32Handle_Info_KHR                        = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR                         ,
			D3D12_Fence_SubmitInfo_KHR                                  = VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR                                    ,
			Semaphore_GetWin32Handle_Info_KHR                           = VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR                            ,
			ImportSemaphore_FD_Info_KHR                                 = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR                                   ,
			Semaphore_Get_FD_Info_KHR                                   = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR                                      ,
			PhysicalDevice_PushDescriptor_Properties_KHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR                 ,
			CommandBuffer_Inheritance_ConditionalRendering_Info_EXT     = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT      ,
			PhysicalDevice_ConditionalRendering_Features_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT             ,
			ConditionalRendering_BeginInfo_EXT                          = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT                           ,
			PresentationRegions_KHR                                     = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR                                            ,
			Pipeline_Viewport_W_ScalingState_CreateInfo_NV              = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV               ,
			SurfaceCapabilitties_2_EXT                                  = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT                                     ,
			DisplayPower_Info_EXT                                       = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT                                         ,
			Device_EventInfo_EXT                                        = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT                                          ,
			Display_EventInfo_EXT                                       = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT                                         ,
			Swapchain_Counter_CreateInfo_EXT                            = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT                              ,
			PresentTimes_Info_Google                                    = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE                                      ,
			PhysicalDevice_MultiviewPerViewAttributes_Properties_NVX    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX   ,
			Pipeline_viewportSwizzleState_CreateInfo_NV                 = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV                 ,
			PhysicalDevice_DiscardRectangle_Properties_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT               ,
			Pipeline_Discard_RectangleState_CreateInfo_EXT              = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT               ,
			PhysicalDevice_ConservativeRasterization_Properties_EXT     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT      ,
			Pipeline_RasterizationConservativeState_CreateInfo_EXT      = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT      ,
			PhysicalDevice_DepthClipEnable_Features_EXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT                 ,
			Pipeline_Rasterization_DepthClipState_CreateInfo_EXT        = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT        ,
			HDR_MetaData_EXT                                            = VK_STRUCTURE_TYPE_HDR_METADATA_EXT                                               ,
			SharedPresentSurfaceCapabilities_KHR                        = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR                        ,
			ImportFence_Win32Handle_Info_KHR                            = VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR                             ,
			ExportFence_Win32Handle_Info_KHR                            = VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR                             ,
			Fence_GetWin32Handle_Info_KHR                               = VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR                                ,
			ImportFence_FD_Info_KHR                                     = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR                                       ,
			Fence_Get_FD_Info_KHR                                       = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR                                          ,
			PhysicalDevice_PerformanceQuery_Features_KHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR                 ,
			PhysicalDevice_PerformanceQuery_Properties_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR               ,
			QueryPool_Performance_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR                         ,
			PerformanceQuery_SubmitInfo_KHR                             = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR                              ,
			AcquireProfilingLock_Info_KHR                               = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR                                ,
			PerformacneCounter_KHR                                      = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR                                        ,
			PerformanceCounter_Description_KHR                          = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR                            ,
			PhysicalDevice_Surface_Info_2_KHR                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR                             ,
			SurfaceCapabilitties_2_KHR                                  = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR                                     ,
			SurfaceFormat_2_KHR                                         = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR                                           ,
			DisplayProperties_2_KHR                                     = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR                                       ,
			DisplayPlaneProperties_2_KHR                                = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR                                 ,
			DisplayModeProperties_2_KHR                                 = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR                                  ,
			DisplayPlane_Info_2_KHR                                     = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR                                       ,
			DisplayPlaneCapabilitties_2_KHR                             = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR                               ,
			Surface_CreateInfo_MVK                                      = VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK                                    ,
			MacOS_Surface_CreateInfo_MVK                                = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK                                  ,
			DebugUtils_ObjectName_Info_EXT                              = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT                               ,
			DebugUtils_ObjectTag_Info_EXT                               = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT                                ,
			DebugUtils_Label_EXT                                        = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT                                          ,
			DebugUtils_MessengerCallback_Data_EXT                       = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT                        ,
			DebugUtils_Messenger_CreateInfo_EXT                         = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT                          ,
			Android_HardwareBufferUsage_Andriod                         = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID                          ,
			Android_HardwareBuffer_Properties_Andrioid                  = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID                     ,
			Android_HardwareBufferFormat_Properties_Android             = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID              ,
			ImportAndroidHardwareBuffer_Info_Android                    = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID                    ,
			Memory_GetAndoridHardwareBuffer_Info_Android                = VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID                ,
			ExternalFormat_Android                                      = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID                                        ,
			PhysicalDevice_InlineUniformBlock_Features_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT              ,
			PhysicalDevice_InlineUniformBlock_Properties_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT            ,
			WriteDescriptor_SetInlineUniformBlock_EXT                   = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT                  ,
			DescriptorPool_InlineUniformBlock_CreateInfo_EXT            = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT           ,
			SampleLocations_Info_EXT                                    = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT                                      ,
			RenderPass_SampleLocations_BeginInfo_EXT                    = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT                    ,
			Pipeline_SampleLocationsState_CreateInfo_EXT                = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT                ,
			PhysicalDevice_SampleLocations_Properties_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT                ,
			Multisample_Properties_EXT                                  = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT                                     ,
			PhyscialDevice_BlendOperation_AdvancedFeatures_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT          ,
			PhysicalDevice_BlendOperationAdvanced_Properties_EXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT        ,
			Pipeline_ColorBlendAdvancedState_CreateInfo_EXT             = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT            ,
			Pipeline_CoverageToColorState_CreateInof_NV                 = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV                ,
			Bind_AccelerationStructureMemory_Info_KHR                   = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_KHR                    ,
			WriteDescriptorSet_AccelerationStruture_KHR                 = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR                ,
			AcclerationStructure_BuildGeometry_Info_KHR                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR                 ,
			AccelerationStructure_CreateGeometryType_Info_KHR           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_GEOMETRY_TYPE_INFO_KHR           ,
			AccelrationStructure_DeviceAddress_Info_KHR                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR                 ,
			AccelerationStructure_GeometryAABBS_Data_KHR                = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR                 ,
			AccelerationStructure_Geometry_Instance_Data_KHR            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR             ,
			AccelerationStructure_GeometryTriangles_Data_KHR            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR             ,
			AccelerationStructure_Geometry_KHR                          = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR                            ,
			//AccelerationStructure_Info_KHR                              = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_KHR                                ,
			AccelerationStructure_MemoryRequirements_Info_KHR           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_KHR            ,
			AccelerationStructure_Version_KHR                           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_KHR                             ,
			Copy_AccelerationStructure_Info_KHR                         = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR                           ,
			CopyAccelerationStructureTOMemory_Info_KHR                  = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR                 ,
			Copy_MemopryToAccelerationStructure_Info_KHR                = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR                 ,
			PhysicalDevice_Raytracing_Features_KHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_FEATURES_KHR                       ,
			PhysicalDevice_Raytracing_Properties_KHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_KHR                     ,
			Raytracing_Pipeline_CreateInfo_KHR                          = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR                           ,
			Raytracing_ShaderGroup_CreateInfo_KHR                       = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR                       ,
			AccelerationStructure_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR                         ,
			Raytracing_PipelineInterface_CreateInfo_KHR                 = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR                 ,
			Pipeline_CoverageModulationState_CreateInfo_NV              = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV              ,
			PhysicalDevice_ShaderSM_Builtins_Features_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV                 ,
			PhyscialDevice_ShaderSM_Builtins_Properties_NV              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV               ,
			DRM_FormatModifier_PropertiesList_EXT                       = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT                        ,
			DRM_FormatModifier_Properties_EXT                           = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT                             ,
			PhysicalDevice_ImageDRM_FormatModifier_Info_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT             ,
			ImageDRM_FomratModifierList_CreateInfo_EXT                  = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT                 ,
			ImageDRM_FormatModifierExplicit_CreateInfo_EXT              = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT             ,
			ImageDRM_FormatModifierProperties_EXT                       = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT                       ,
			ValidationCache_CreateInfo_EXT                              = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT                               ,
			ShaderModule_ValidationCache_CreateInfo_EXT                 = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT                 ,
			Pipeline_viewportShadingRateImageState_CreateInfo_NV        = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV      ,
			PhysicalDevice_ShadingRateImage_Features_NV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV                 ,
			PhysicalDevice_ShaderRateImage_Properties_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV               ,
			Pipeline_ViewportCoarseSampleOrder_State_CreateInfo_NV      = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV     ,
			Raytracing_Pipeline_CreateInfo_NV                           = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV                            ,
			AccelerationStructure_CreateInfo_NV                         = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV                          ,
			Geometry_NV                                                 = VK_STRUCTURE_TYPE_GEOMETRY_NV                                                    ,
			GeometryTriangles_NV                                        = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV                                          ,
			Geometry_AABB_NV                                            = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV                                               ,
			AccelerationStructure_MemoryRequirements_Info_NV            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV             ,
			PhysicalDevice_DeviceRaytracing_Properties_NV               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV                      ,
			Ratracing_ShaderGroup_CreateInfo_NV                         = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV                        ,
			AccelerationStructure_Info_NV                               = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV                                 ,
			PhysicalDevice_RepresentativeFragmentTest_Features_NV       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV       ,
			Pipeline_Representative_FragmentTestState_CreateInfo_NV     = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV     ,
			PhysicalDevice_ImageView_ImgeFormat_Info_EXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT               ,
			FilterCubic_ImageView_ImageFormat_Properties_EXT            = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT            ,
			DeviceQueue_GlobalPriority_CreateInfo_EXT                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT                   ,
			ImportMemory_HostPointer_Info_EXT                           = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT                            ,
			MemoryHost_PointerProperties_EXT                            = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT                             ,
			PhysicalDevice_ExternalMemoryHost_Properites_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT            ,
			PhysicalDevice_ShaderClock_Features_KHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR                      ,
			Pipeline_CompilerControl_CreateInfo_AMD                     = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD                      ,
			Calibrated_Timestamp_Info_EXT                               = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT                                  ,
			PhysicalDevice_ShaderCore_Properties_AMD                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD                     ,
			DeviceMemory_Overallocation_CreateInfo_AMD                  = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD                   ,
			PhysicalDevice_VertexAttributeDivisor_Properties_EXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT        ,
			Pipeline_VertexInput_DivisorState_CreateInfo_EXT            = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT            ,
			PhysicalDevice_VertexAttributeDevisor_Features_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT          ,
			PresentFrameToken_GGP                                       = VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP                                        ,
			Pipeline_CreationFeedback_CreateInfo_EXT                    = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT                     ,
			PhysicalDevice_ComputeShaderDerivatives_Features_NV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV         ,
			PhysicalDevice_MeshShader_Features_NV                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV                        ,
			PhysicalDevice_MeshShader_Properties_NV                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV                      ,
			PhysicalDevice_FragmentShaderBarycentric_Features_NV        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV        ,
			PhysicalDevice_ShaderImageFootprint_Features_NV             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV             ,
			Pipeline_ViewportExclusiveScissorState_CreateInfo_NV        = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV       ,
			PhysicalDevice_ExclusiveScissor_features_NV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV                  ,
			CheckpointData_NV                                           = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV                                             ,
			QueueFamilyCheckpoint_Properties_NV                         = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV                          ,
			PhysicalDevice_ShaderIntegerFunctions_2_Features_Intel      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL      ,
			QueryPool_CreateInfo_Intel                                  = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL                                   ,
			InitializePerformanceAPI_Info_Intel                         = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL                          ,
			PerformanceMarker_Info_Intel                                = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL                                  ,
			PerformanceStreamMarker_info_Intel                          = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL                           ,
			PerformanceOverride_Info_Intel                              = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL                                ,
			PerformanceConfiguration_Aquire_Info_Intel                  = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL                   ,
			PhysicalDevice_PCI_BUS_Info_Properties_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT                    ,
			Display_NativeHDR_SurfaceCapabbilitties_AMD                 = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD                    ,
			SwapChain_DisplayNativeHDR_CreateInfo_AMD                   = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD                   ,
			ImagepipeSurface_CreateInfo_FUCHSIA                         = VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA                          ,
			Metal_Surface_CreateInfo_EXT                                = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT                                  ,
			PhysicalDevice_FragmentDensity_MapFeatures_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT              ,
			PhysicalDevice_FragmentDensityMap_Properties_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT            ,
			RenderPass_FragmentDensityMap_CreateInfo_EXT                = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT               ,
			PhysicalDevice_SubgroupSizeControl_Properties_EXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT           ,
			Pipeline_ShaderStage_RequiredSubgroupSize_CreateInfo_EXT    = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT   ,
			PhysicalDevice_SubgroupSizeControl_Features_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT             ,
			PhysicalDevice_ShaderCore_Properties_2_AMD                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD                   ,
			PhysicalDeice_CoherentMemory_Features_AMD                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD                   ,
			PhysicalDevice_MemoryBudget_Properties_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT                   ,
			PhysicalDevice_MemoryPriority_Features_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT                   ,
			MemoryPriority_AllocateInfo_EXT                             = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT                              ,
			Surface_ProtectedCapabilitties_KHR                          = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR                             ,
			PhysicalDevice_DedicatedAllocationImageAliasing_Features_NV = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV,
			PhysicalDevice_BufferDeviceAddress_Features_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT             ,
			BufferDeviceAddress_CreateInfo_EXT                          = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT                          ,
			PhysicalDevice_ToolProperties_EXT                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT                            ,
			ValidationFeatures_EXT                                      = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT                                        ,
			PhysicalDevice_CooperativeMatrix_Features_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV                 ,
			CooperativeMatrix_Properties_NV                             = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV                               ,
			PhysicalDevice_CooperativeMatrix_Proeprties_NV              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV               ,
			PhysicalDevice_CoverageReductionMode_Features_NV            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV            ,
			Pipeline_CoverageReductionState_CreateInfo_NV               = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV               ,
			Framebufer_MixedSamplesCombination_NV                       = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV                       ,
			PhyscialDevice_FragmentShader_Interlock_Features_EXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT         ,
			PhysicalDevice_YCBCR_ImageArrays_Features_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT                ,
			Surface_FullscreenExclusive_Info_EXT                        = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT                         ,
			Surface_Capabilities_FullscreenExclusive_EXT                = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT                 ,
			Surface_FullscreenExclusive_Win32_Info_EXT                  = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT                   ,
			HeadlessSurface_CreateInfo_EXT                              = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT                               ,
			PhysicalDevice_LineRasterization_Features_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT                ,
			Pipeline_RasterizationLineState_CreateInfo_EXT              = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT              ,
			PhysicalDevice_LineRasterization_Properties_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT              ,
			PhysicalDevice_IndexType_Uint8_Features_EXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT                  ,
			DeferredOperation_Info_KHR                                  = VK_STRUCTURE_TYPE_DEFERRED_OPERATION_INFO_KHR                                    ,
			PhysicalDevice_PipelineExecutableProperties_Features_KHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR    ,
			Pipeline_Info_KHR                                           = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR                                              ,
			Pipeline_ExecutableProperties_KHR                           = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR                             ,
			Pipeline_ExecutableInfo_KHR                                 = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR                                   ,
			Pipeline_ExecutableStatistic_KHR                            = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR                              ,
			Pipeline_Executable_InternalRepresentation_KHR              = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR                ,
			PhysicalDevice_ShaderDemoteToHelperInvocationFeatures_EXT   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT,
			PhysicalDevice_DeviceGeneratedCommand_Properties_NV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV        ,
			GraphicsShaderGroup_CreateInfo_NV                           = VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV                           ,
			GraphicsPipeline_ShaderGroups_CreateInfo_NV                 = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV                 ,
			IndirectCommands_LayoutToken_NV                             = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV                              ,
			IndirectCommands_Layout_CreateInfo_NV                       = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV                        ,
			GeneratedCommands_Info_NV                                   = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV                                     ,
			GeneratedCommands_MemoryRequirements_Info_NV                = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV                 ,
			PhysicalDevice_DeviceGeneratedCommand_Features_NV           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV          ,
			PhysicalDevice_TexelBufferAlignment_Features_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT            ,
			PhysicalDevice_TEXELBuffer_AlignmentProperties_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT          ,
			CommandBufferInheritance_RenderPassTransform_Info_QCOM      = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM     ,
			RenderPass_Transform_BeginInfo_QCOM                         = VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM                          ,
			PipelineLibrary_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR                               ,
			PhysicalDevice_PipelineCreationCacheControl_Features_EXT    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT   ,
			PhysicalDevice_DiagnosticsConfig_Features_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV                 ,
			DeviceDiagnosticsConfig_CreateInfo_NV                       = VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV                       ,
			PhysicalDevice_VariablePointer_Features                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES                      ,
			PhysicalDevice_ShaderDrawParameter_Features                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES                 ,
			DebugReport_CreateInfo_EXT                                  = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT                                   ,
			RenderPass_Multiview_CreateInfo_KHR                         = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR                          ,
			PhysicalDevice_Multiview_Features_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR                         ,
			PhysicalDevice_multiview_Properties_KHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR                       ,
			PhysicalDevice_Features_2_KHR                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR                                 ,
			PhysicalDevice_Properties_2_KHR                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR                               ,
			FormatProperties_2_KHR                                      = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR                                        ,
			ImageFormat_Properties_2_KHR                                = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR                                  ,
			PhysicalDevice_ImageFormat_Info_2_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR                        ,
			QueueFamily_Properties_2_KHR                                = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR                                  ,
			PhysicalDevice_MemoryProperties_2_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR                        ,
			SpraseImageFormat_Properties_2_KHR                          = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR                           ,
			PhysicalDevice_SparseImageFormat_Info_2_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR                 ,
			MemoryAllocateFlags_Info_KHR                                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR                                 ,
			DeviceGroup_RenderPass_BeginInfo_KHR                        = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR                        ,
			DeviceGroup_CommandBuffer_BeginInfo_KHR                     = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR                     ,
			DeviceGroup_SubmitInfo_KHR                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR                                   ,
			DeviceGroup_BindSparse_Info_KHR                             = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR                              ,
			BindBuffer_MemoryDeviceGroup_Info_KHR                       = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR                       ,
			BindImage_MemoryDeviceGroup_Info_KHR                        = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR                        ,
			PhysicalDeviceGroup_Properties_KHR                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR                           ,
			DeviceGroup_Device_CreateInfo_KHR                           = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR                            ,
			PhysicalDevice_ExternalImageFormat_Inf_KHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR                 ,
			ExternalImageFormat_Properties_KHR                          = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR                           ,
			PhysicalDevice_ExternalBuffer_Info_KHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR                       ,
			ExternalBuffer_Propertis_KHR                                = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR                                 ,
			PhysicalDevice_ID_Properties_KHR                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR                              ,
			ExternalMemory_Buffer_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR                         ,
			ExternalMemoryImage_CreateInfo_KHR                          = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR                          ,
			Export_MemoryAllocate_Info_KHR                              = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR                                ,
			PhysicalDevice_ExternalSemaphore_Info_KHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR                    ,
			External_Semaphore_Properties_KHR                           = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR                              ,
			Export_Semaphore_CreateInfo_KHR                             = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR                               ,
			PhysicalDevice_Shader_Float16_Int8_Features_KHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES_KHR               ,
			PhysicalDevice_Float16_Int8_Features_KHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR                      ,
			PhysicalDevice_16BitStorage_Features_KHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR                     ,
			Descriptor_UpdateTemplate_CreateInfo_KHR                    = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR                     ,
			Surface_Capabilities_2_EXT                                  = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES2_EXT                                      ,
			PhysicalDevice_Imageless_Framebuffer_Features_KHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR             ,
			Framebuffer_Attachments_CreateInfo_KHR                      = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR                        ,
			Framebuffer_Attachment_ImageInfo_KHR                        = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR                          ,
			RenderPass_Attachment_BeginInfo_KHR                         = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR                          ,
			Attachment_Description_2_KHR                                = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR                                   ,
			Attachment_Reference_2_KHR                                  = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR                                     ,
			Subpass_Description_2_KHR                                   = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR                                      ,
			Subpass_Dependency_2_KHR                                    = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR                                       ,
			RenderPass_CreateInfo_2_KHR                                 = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR                                  ,
			Subpass_BeginInfo_HR                                        = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR                                         ,
			Subpass_EndInfo_KHR                                         = VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR                                           ,
			PhysicalDevice_ExternalFence_Info_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR                        ,
			ExternalFence_Properties_KHR                                = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR                                  ,
			ExportFence_CreateInfo_KHR                                  = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR                                   ,
			PhysicalDevice_PointClipping_Properties_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR                  ,
			RenderPass_InputAttachmentAspect_CreateInfo_KHR             = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR            ,
			ImageViewUsage_CreateInfo_KHR                               = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR                               ,
			Pipeline_TessellationDomain_OriginState_CreateInfo_KHR      = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR      ,
			PhysicalDevice_VariablePointer_Features_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR                  ,
			PhysicalDevice_VariablePointers_Features_KHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR                 ,
			MemoryDedicated_Requirements_KHR                            = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR                              ,
			MemoryDedicated_AllocateInfo_KHR                            = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR                             ,
			PhysicalDevice_SamplerFilter_MinMax_Properties_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT           ,
			Sampler_ReductionMode_CreateInfo_EXT                        = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT                         ,
			Buffer_MemoryRequirements_Inof_2_KHR                        = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR                          ,
			Image_MemoryRequirements_Info_2_KHR                         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR                           ,
			ImageSparse_MemoryRequirements_Info_2_KHR                   = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR                    ,
			MemoryRequirements_2_KHR                                    = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR                                      ,
			SparseImage_MemoryRequirements_2_KHR                        = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR                         ,
			ImageFormatList_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR                              ,
			SamplerYCBCR_Conversion_CreateInfo_KHR                      = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR                       ,
			Sampler_YCBCR_ConversionInfo_KHR                            = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR                              ,
			BindImagePlane_MemoryInfo_KHR                               = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR                               ,
			ImagePlane_MemoryRequirements_Info_KHR                      = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR                       ,
			PhysicalDevice_Sampler_YCBCR_Conversion_Features_KHR        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR          ,
			SamplerYCBCR_Conversion_ImageFormat_Properties_KHR          = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR           ,
			Buffer_MemoryInfo_KHR                                       = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR                                    ,
			BindImage_MemoryInfo_KHR                                    = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR                                     ,
			Descriptor_SetLayoutBindingFlags_CreateInfo_EXT             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT            ,
			PhysicalDevice_DescriptorIndexing_Features_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT               ,
			PhysicalDevice_Descriptor_IndexingProperties_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT             ,
			DescriptorSet_VariableDescriptorCount_AllocateInfo_EXT      = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT     ,
			DescriptorSet_VaraibleDescriptorCount_LayoutSupport_EXT     = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT    ,
			Bind_AccelerationStructure_MemoryInfo_NV                    = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV                     ,
			WriteDescriptorSet_AccelerationStructure_NV                 = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV                 ,
			PhysicalDevice_Maintenance_3_Properties_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR                   ,
			DescriptorSet_LayoutSupport_KHR                             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR                              ,
			PhysicalDevice_ShaderSubgroup_ExtendedTypes_Features_KHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR    ,
			PhysicalDevice_8BitStorage_Features_KHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR                      ,
			PhysicalDevice_Shader_AtomicInt64_Features_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR               ,
			PhysicalDevice_DriverProperties_KHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR                          ,
			PhysicalDevice_FloatControls_Properties_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR                  ,
			PhysicalDevice_DepthStencilResolve_Properties_KHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR           ,
			Subpass_Description_DepthStencilResolve_KHR                 = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR                  ,
			PhysicalDevice_TimelineSemaphore_Features_KHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR                ,
			PhysicalDevice_TimelineSemaphoreProperties_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR              ,
			SemaphoreType_CreateInfo_KHR                                = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO_KHR                                 ,
			TimelineSemaphore_SubmitInfo_KHR                            = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR                             ,
			Semaphore_WaitInfo_KHR                                      = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO_KHR                                        ,
			Sempaphore_SignalInfo_KHR                                   = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO_KHR                                      ,
			PhysicalDevice_Vulakn_MemoryModel_Features_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR               ,
			PhysicalDevice_ScalarBlock_LayoutFeatures_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT               ,
			PhysicalDevice_SeparateDepth_StencilLayouts_Features_KHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR    ,
			AttachmentReference_StencilLayout_KHR                       = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR                        ,
			AttachmentDescription_StencilLayout_KHR                     = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR                      ,
			PhysicalDevice_BufferAddress_Features_EXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT                    ,
			BufferDevice_AddressInfo_EXT                                = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_EXT                                 ,
			Extesnion_ImageStencilUsage_CreateInfo                      = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT                            ,
			PhysicalDevice_UniformBufferStandardLayout_Features_KHR     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR    ,
			PhysicalDevice_BufferDevice_AddressFeatures_KHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR             ,
			BufferDevice_Address_Info                                   = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_KHR                                 ,
			BufferOpaque_CaptureAddress_Createinfo                      = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR                  ,
			MemoryOpaque_CaptureAddressAllocate_Info_KHR                = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR                ,
			DeviceMemory_OpaqueCaptureAddress_Info_KHR                  = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR                  ,
			PhysicalDevice_HostQuery_ResetFeatures_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT                  ,

			// Not found... (1.2.141)
			Device_PrivateData_CreateInfo_EXT = 1000295001,   // VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT,

			Max_Enum                                                    = VK_STRUCTURE_TYPE_MAX_ENUM
		};
		

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubgroupFeatureFlagBits">Specification</a> @ingroup APISpec_Limits */
		enum class ESubgroupFeaturesFlag : uint32
		{
			Basic           = VK_SUBGROUP_FEATURE_BASIC_BIT           ,
			Vote            = VK_SUBGROUP_FEATURE_VOTE_BIT            ,
			Arithemtic      = VK_SUBGROUP_FEATURE_ARITHMETIC_BIT      ,
			Ballot          = VK_SUBGROUP_FEATURE_BALLOT_BIT          ,
			Shuffle         = VK_SUBGROUP_FEATURE_SHUFFLE_BIT         ,
			ShuffleRealtive = VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT,
			Clustered       = VK_SUBGROUP_FEATURE_CLUSTERED_BIT       ,
			Quad            = VK_SUBGROUP_FEATURE_QUAD_BIT            ,

			// Provided by VK_NV_shader_subgroup_partitioned
			Partitioned_NV  =  VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV ,

			VT_SpecifyBitmaskable = VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassContents">Specification</a> @ingroup APISpec_Render_Pass */
		enum class ESubpassContents : uint32
		{
			Inline                  = VK_SUBPASS_CONTENTS_INLINE                   ,
			SecondaryCommandBuffers = VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDescriptionFlagBits">Specification</a> @ingroup APISpec_Render_Pass */
		enum class ESubpassDescriptionFlag : uint32 { VT_SpecifyBitmaskable = sizeof(uint32) };

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceTransformFlagBitsKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
		enum class ESurfaceTransformFlag : uint32
		{
			Identity                     = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR                    ,
			Rotate_90                    = VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR                   ,
			Rotate_180                   = VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR                  ,
			Rotate_270                   = VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR                  ,
			Horizontal_Mirror            = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR           ,
			Horizontal_Mirror_Rotate_90  = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR ,
			Horizontal_Mirror_Rotate_180 = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR,
			Horizontal_Mirror_Rotate_270 = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR,
			Inherit                      = VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR                     ,

			VT_SpecifyBitmaskable = VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSwapchainCreateFlagBitsKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
		enum class ESwapchainCreateFlag : uint32
		{
			SplitInstanceBindRegions = VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR ,
			CreateProtected          = VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR                   ,
			CreateMutableFormat      = VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR              ,

			VT_SpecifyBitmaskable = VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSystemAllocationScope">Specification</a> @ingroup APISpec_Memory_Allocation */
		enum class ESystemAllocationScope : uint32
		{
			Command  = VK_SYSTEM_ALLOCATION_SCOPE_COMMAND ,
			Object   = VK_SYSTEM_ALLOCATION_SCOPE_OBJECT  ,
			Cache    = VK_SYSTEM_ALLOCATION_SCOPE_CACHE   ,
			Device   = VK_SYSTEM_ALLOCATION_SCOPE_DEVICE  ,
			Instance = VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationCheckEXT">Specification</a> @ingroup VkValidationCheckEXT */
		enum class EValidationCheck : uint32
		{
			All     = VK_VALIDATION_CHECK_ALL_EXT    ,
			Shaders = VK_VALIDATION_CHECK_SHADERS_EXT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFeatureEnableEXT">Specification</a> @ingroup APISpec_Initialization  */
		enum class EValidationFeatureEnable : uint32
		{
			GPU_Assisted                   = VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT                     ,
			GPU_AssistedReserveBindingSlot = VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT,
			BestPractices                  = VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT                   ,
			DebugPrintF                    = VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT 
		};

		/**
		* @details
		* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkVendorId.html">Specification</a> @ingroup APISpec_Devices_and_Queues
		*/
		enum class EVendorID : uint32
		{
			VIV      = VK_VENDOR_ID_VIV     ,
			VSI      = VK_VENDOR_ID_VSI     ,
			KAZAN    = VK_VENDOR_ID_KAZAN   ,
			CODEPLAY = VK_VENDOR_ID_CODEPLAY,
			MESA     = VK_VENDOR_ID_MESA    
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkVertexInputRate">Specification</a> @ingroup APISpec_Fixed-Function_Vertex_Processing */
		enum class EVertexInputRate : uint32
		{
			Vertex   = VK_VERTEX_INPUT_RATE_VERTEX,
			Instance = VK_VERTEX_INPUT_RATE_INSTANCE
		};
    }

	/** @} */
}