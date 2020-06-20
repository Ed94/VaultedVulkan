/**
@file VT_Enums.hpp

@brief Vaulted Thermals: Enumerations
*/

#pragma once



// VT
#include "_foreign/Foreign_Bitmask.hpp"

#include "VT_Platform.hpp"



//TODO: Move enums fork based on specification to their respective file if possible.
namespace VaultedThermals
{
    namespace Corridors
    {
		/** 
		@enum Undefined Enum
		@brief Necessary for Bitmasks in the Vulkan specification that are not defined but reserved for future use.
		*/
		enum class EUndefined {};

		SpecifyBitmaskable(EUndefined);

		/**
		 * @enum Handle Enum
		 */
		enum class EHandle
		{
			Null = VK_NULL_HANDLE
		};

		/**
		 * @enum API_Version
		 * 
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#extendingvulkan-coreversions-versionnumbers">Specification</a> 
		 * 
		 */
		enum class EAPI_Version
		{
			_1_0 = VK_API_VERSION_1_0,
			_1_1 = VK_API_VERSION_1_1,
			_1_2 = VK_API_VERSION_1_2
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#fundamentals-commandsyntax">Specification</a> .
		 */
		enum EBool
		{
			True  = VK_TRUE ,
			False = VK_FALSE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkObjectType.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkResult.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkStructureType.html">Specification</a>  */
		enum class EStructureType : uint32
		{
			ApplicationInformation                                      = VK_STRUCTURE_TYPE_APPLICATION_INFO                                               ,
			Instance_CreateInfo                                         = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO                                           ,
			DeviceQueue_CreateInfo                                      = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO                                       ,
			Device_CreateInfo                                           = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO                                       ,
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
			Pipeline_ShaderState_CreateInfo                             = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO                              ,
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
			ImageMMemory_Barrier                                        = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER                                           ,
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
			PhysicalDevice_Porperties                                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2                                   ,
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
			PhysicalDevice_ShaderDrawParameter_Features                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES                ,   		     
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
			PhysicalDevice_VariablePointer_Features_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR                 ,
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
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDebugUtilsMessageSeverityFlagBitsEXT.html">Specification</a>  */
		enum class EDebugUtilities_MessageSeverity : uint32
		{
			Verbose = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
			Info    = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT   ,
			Warning = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT,
			Error   = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT
		};

		SpecifyBitmaskable(EDebugUtilities_MessageSeverity);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDebugUtilsMessageTypeFlagBitsEXT.html">Specification</a> de */
		enum class EDebugUtilities_MessageType : uint32
		{
			General     = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT    ,
			Validation  = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT ,
			Performance = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT
		};

		SpecifyBitmaskable(EDebugUtilities_MessageType);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSampleCountFlagBits.html">Specification</a>  */
		enum class ESampleCount : uint32
		{
			_1  = VK_SAMPLE_COUNT_1_BIT ,
			_2  = VK_SAMPLE_COUNT_2_BIT ,
			_4  = VK_SAMPLE_COUNT_4_BIT ,
			_8  = VK_SAMPLE_COUNT_8_BIT ,
			_16 = VK_SAMPLE_COUNT_16_BIT,
			_32 = VK_SAMPLE_COUNT_32_BIT,
			_64 = VK_SAMPLE_COUNT_64_BIT
		};

		SpecifyBitmaskable(ESampleCount);

		/**
		@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkQueueFlagBits.html">Specification</a> 
		*/
		enum class EQueueFlag : uint32
		{
			Graphics               = VK_QUEUE_GRAPHICS_BIT      ,
			Compute                = VK_QUEUE_COMPUTE_BIT       ,
			Transfer               = VK_QUEUE_TRANSFER_BIT      ,
			SquareMemoryManagement = VK_QUEUE_SPARSE_BINDING_BIT,
			Protected              = VK_QUEUE_PROTECTED_BIT
		};

		SpecifyBitmaskable(EQueueFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceQueueCreateFlagBits.html">Specification</a>  */
		enum class ELogicalDeviceQueueCreateFlag : uint32
		{
			CreateProtected = VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT
		};

		SpecifyBitmaskable(ELogicalDeviceQueueCreateFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSurfaceTransformFlagBitsKHR.html">Specification</a>  */
		enum class ESurfaceTransform : uint32
		{
			Identity                     = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR                    ,
			Rotate_90                    = VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR                   ,
			Rotate_180                   = VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR                  ,
			Rotate_270                   = VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR                  ,
			Horizontal_Mirror            = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR           ,
			Horizontal_Mirror_Rotate_90  = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR ,
			Horizontal_Mirror_Rotate_180 = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR,
			Horizontal_Mirror_Rotate_270 = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR,
			Inherit                      = VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR 
		};

		SpecifyBitmaskable(ESurfaceTransform);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkCompositeAlphaFlagBitsKHR.html">Specification</a>  */
		enum class ECompositeAlpha : uint32
		{
			Opaque         = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR          ,
			PreMultiplied  = VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR  ,
			PostMultiplied = VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR ,
			Inherit        = VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR 
		};

		SpecifyBitmaskable(ECompositeAlpha);

		/** @brief <a href"https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageUsageFlagBits.html">Specification</a> */
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
			DensityMap              = VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT
		};

		SpecifyBitmaskable(EImageUsage);

		/**
		 * @brief Supported buffer and image formats.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#formats">Specification</a> 
		 */
		enum class EFormat : uint32
		{
			Undefined                       = VK_FORMAT_UNDEFINED            ,
			UNormalized_R4_G4_8Pack         = VK_FORMAT_R4G4_UNORM_PACK8     ,
			UNormalized_R4_G4_B4_A4_16Pack  = VK_FORMAT_R4G4B4A4_UNORM_PACK16,
			UNormalized_B4_G4_R4_A4_16Pack  = VK_FORMAT_B4G4R4A4_UNORM_PACK16,
			UNormalized_R5_G6_B5_16Pack     = VK_FORMAT_R5G6B5_UNORM_PACK16  ,
			UNormalized_B5_G6_R5_16Pack     = VK_FORMAT_B5G6R5_UNORM_PACK16  ,
			UNormalized_R5_G5_B5_1A_16Pack  = VK_FORMAT_R5G5B5A1_UNORM_PACK16,
			UNormalized_B5_G5_R5_A1_16Pack  = VK_FORMAT_B5G5R5A1_UNORM_PACK16,
			UNormalized_A1_R5_G5_B5_16Pack  = VK_FORMAT_A1R5G5B5_UNORM_PACK16,
			UNormalized_R8                  = VK_FORMAT_R8_UNORM             ,
			SNormalized_R8                  = VK_FORMAT_R8_SNORM             ,
			VK_FORMAT_R8_USCALED = 11,
			VK_FORMAT_R8_SSCALED = 12,
			VK_FORMAT_R8_UINT = 13,
			VK_FORMAT_R8_SINT = 14,
			VK_FORMAT_R8_SRGB = 15,
			VK_FORMAT_R8G8_UNORM = 16,
			VK_FORMAT_R8G8_SNORM = 17,
			VK_FORMAT_R8G8_USCALED = 18,
			VK_FORMAT_R8G8_SSCALED = 19,
			VK_FORMAT_R8G8_UINT = 20,
			VK_FORMAT_R8G8_SINT = 21,
			VK_FORMAT_R8G8_SRGB = 22,
			VK_FORMAT_R8G8B8_UNORM = 23,
			VK_FORMAT_R8G8B8_SNORM = 24,
			VK_FORMAT_R8G8B8_USCALED = 25,
			VK_FORMAT_R8G8B8_SSCALED = 26,
			VK_FORMAT_R8G8B8_UINT = 27,
			VK_FORMAT_R8G8B8_SINT = 28,
			VK_FORMAT_R8G8B8_SRGB = 29,
			VK_FORMAT_B8G8R8_UNORM = 30,
			VK_FORMAT_B8G8R8_SNORM = 31,
			VK_FORMAT_B8G8R8_USCALED = 32,
			VK_FORMAT_B8G8R8_SSCALED = 33,
			VK_FORMAT_B8G8R8_UINT = 34,
			VK_FORMAT_B8G8R8_SINT = 35,
			VK_FORMAT_B8G8R8_SRGB = 36,
			VK_FORMAT_R8G8B8A8_UNORM = 37,
			VK_FORMAT_R8G8B8A8_SNORM = 38,
			VK_FORMAT_R8G8B8A8_USCALED = 39,
			VK_FORMAT_R8G8B8A8_SSCALED = 40,
			VK_FORMAT_R8G8B8A8_UINT = 41,
			VK_FORMAT_R8G8B8A8_SINT = 42,
			VK_FORMAT_R8G8B8A8_SRGB = 43,
			VK_FORMAT_B8G8R8A8_UNORM = 44,
			VK_FORMAT_B8G8R8A8_SNORM = 45,
			VK_FORMAT_B8G8R8A8_USCALED = 46,
			VK_FORMAT_B8G8R8A8_SSCALED = 47,
			VK_FORMAT_B8G8R8A8_UINT = 48,
			VK_FORMAT_B8G8R8A8_SINT = 49,
			VK_FORMAT_B8G8R8A8_SRGB = 50,
			VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
			VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
			VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
			VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
			VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
			VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
			VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
			VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
			VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
			VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
			VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
			VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
			VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
			VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
			VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
			VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
			VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
			VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
			VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
			VK_FORMAT_R16_UNORM = 70,
			VK_FORMAT_R16_SNORM = 71,
			VK_FORMAT_R16_USCALED = 72,
			VK_FORMAT_R16_SSCALED = 73,
			VK_FORMAT_R16_UINT = 74,
			VK_FORMAT_R16_SINT = 75,
			VK_FORMAT_R16_SFLOAT = 76,
			VK_FORMAT_R16G16_UNORM = 77,
			VK_FORMAT_R16G16_SNORM = 78,
			VK_FORMAT_R16G16_USCALED = 79,
			VK_FORMAT_R16G16_SSCALED = 80,
			VK_FORMAT_R16G16_UINT = 81,
			VK_FORMAT_R16G16_SINT = 82,
			VK_FORMAT_R16G16_SFLOAT = 83,
			VK_FORMAT_R16G16B16_UNORM = 84,
			VK_FORMAT_R16G16B16_SNORM = 85,
			VK_FORMAT_R16G16B16_USCALED = 86,
			VK_FORMAT_R16G16B16_SSCALED = 87,
			VK_FORMAT_R16G16B16_UINT = 88,
			VK_FORMAT_R16G16B16_SINT = 89,
			VK_FORMAT_R16G16B16_SFLOAT = 90,
			VK_FORMAT_R16G16B16A16_UNORM = 91,
			VK_FORMAT_R16G16B16A16_SNORM = 92,
			VK_FORMAT_R16G16B16A16_USCALED = 93,
			VK_FORMAT_R16G16B16A16_SSCALED = 94,
			VK_FORMAT_R16G16B16A16_UINT = 95,
			VK_FORMAT_R16G16B16A16_SINT = 96,
			VK_FORMAT_R16G16B16A16_SFLOAT = 97,
			VK_FORMAT_R32_UINT = 98,
			VK_FORMAT_R32_SINT = 99,
			VK_FORMAT_R32_SFLOAT = 100,
			VK_FORMAT_R32G32_UINT = 101,
			VK_FORMAT_R32G32_SINT = 102,
			VK_FORMAT_R32G32_SFLOAT = 103,
			VK_FORMAT_R32G32B32_UINT = 104,
			VK_FORMAT_R32G32B32_SINT = 105,
			VK_FORMAT_R32G32B32_SFLOAT = 106,
			VK_FORMAT_R32G32B32A32_UINT = 107,
			VK_FORMAT_R32G32B32A32_SINT = 108,
			VK_FORMAT_R32G32B32A32_SFLOAT = 109,
			VK_FORMAT_R64_UINT = 110,
			VK_FORMAT_R64_SINT = 111,
			VK_FORMAT_R64_SFLOAT = 112,
			VK_FORMAT_R64G64_UINT = 113,
			VK_FORMAT_R64G64_SINT = 114,
			VK_FORMAT_R64G64_SFLOAT = 115,
			VK_FORMAT_R64G64B64_UINT = 116,
			VK_FORMAT_R64G64B64_SINT = 117,
			VK_FORMAT_R64G64B64_SFLOAT = 118,
			VK_FORMAT_R64G64B64A64_UINT = 119,
			VK_FORMAT_R64G64B64A64_SINT = 120,
			VK_FORMAT_R64G64B64A64_SFLOAT = 121,
			VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
			VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
			VK_FORMAT_D16_UNORM = 124,
			VK_FORMAT_X8_D24_UNORM_PACK32 = 125,
			VK_FORMAT_D32_SFLOAT = 126,
			VK_FORMAT_S8_UINT = 127,
			VK_FORMAT_D16_UNORM_S8_UINT = 128,
			VK_FORMAT_D24_UNORM_S8_UINT = 129,
			VK_FORMAT_D32_SFLOAT_S8_UINT = 130,
			VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
			VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
			VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
			VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
			VK_FORMAT_BC2_UNORM_BLOCK = 135,
			VK_FORMAT_BC2_SRGB_BLOCK = 136,
			VK_FORMAT_BC3_UNORM_BLOCK = 137,
			VK_FORMAT_BC3_SRGB_BLOCK = 138,
			VK_FORMAT_BC4_UNORM_BLOCK = 139,
			VK_FORMAT_BC4_SNORM_BLOCK = 140,
			VK_FORMAT_BC5_UNORM_BLOCK = 141,
			VK_FORMAT_BC5_SNORM_BLOCK = 142,
			VK_FORMAT_BC6H_UFLOAT_BLOCK = 143,
			VK_FORMAT_BC6H_SFLOAT_BLOCK = 144,
			VK_FORMAT_BC7_UNORM_BLOCK = 145,
			VK_FORMAT_BC7_SRGB_BLOCK = 146,
			VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
			VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
			VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
			VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
			VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
			VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
			VK_FORMAT_EAC_R11_UNORM_BLOCK = 153,
			VK_FORMAT_EAC_R11_SNORM_BLOCK = 154,
			VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
			VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
			VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
			VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
			VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
			VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
			VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
			VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
			VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
			VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
			VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
			VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
			VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
			VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
			VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
			VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
			VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
			VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
			VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
			VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
			VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
			VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
			VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
			VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
			VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
			VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
			VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
			VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
			VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
			VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184,
			VK_FORMAT_G8B8G8R8_422_UNORM = 1000156000,
			VK_FORMAT_B8G8R8G8_422_UNORM = 1000156001,
			VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM = 1000156002,
			VK_FORMAT_G8_B8R8_2PLANE_420_UNORM = 1000156003,
			VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM = 1000156004,
			VK_FORMAT_G8_B8R8_2PLANE_422_UNORM = 1000156005,
			VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM = 1000156006,
			VK_FORMAT_R10X6_UNORM_PACK16 = 1000156007,
			VK_FORMAT_R10X6G10X6_UNORM_2PACK16 = 1000156008,
			VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 1000156009,
			VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 1000156010,
			VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 1000156011,
			VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 1000156012,
			VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 1000156013,
			VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 1000156014,
			VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 1000156015,
			VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 1000156016,
			VK_FORMAT_R12X4_UNORM_PACK16 = 1000156017,
			VK_FORMAT_R12X4G12X4_UNORM_2PACK16 = 1000156018,
			VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 1000156019,
			VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 1000156020,
			VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 1000156021,
			VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 1000156022,
			VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 1000156023,
			VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 1000156024,
			VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 1000156025,
			VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 1000156026,
			VK_FORMAT_G16B16G16R16_422_UNORM = 1000156027,
			VK_FORMAT_B16G16R16G16_422_UNORM = 1000156028,
			VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM = 1000156029,
			VK_FORMAT_G16_B16R16_2PLANE_420_UNORM = 1000156030,
			VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM = 1000156031,
			VK_FORMAT_G16_B16R16_2PLANE_422_UNORM = 1000156032,
			VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM = 1000156033,
			VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
			VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
			VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
			VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
			VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
			VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
			VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
			VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007,
			VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT = 1000066000,
			VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT = 1000066001,
			VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT = 1000066002,
			VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT = 1000066003,
			VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT = 1000066004,
			VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT = 1000066005,
			VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT = 1000066006,
			VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT = 1000066007,
			VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT = 1000066008,
			VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT = 1000066009,
			VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT = 1000066010,
			VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT = 1000066011,
			VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT = 1000066012,
			VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT = 1000066013,
			VK_FORMAT_G8B8G8R8_422_UNORM_KHR = VK_FORMAT_G8B8G8R8_422_UNORM,
			VK_FORMAT_B8G8R8G8_422_UNORM_KHR = VK_FORMAT_B8G8R8G8_422_UNORM,
			VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM,
			VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM,
			VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM,
			VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM,
			VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM,
			VK_FORMAT_R10X6_UNORM_PACK16_KHR = VK_FORMAT_R10X6_UNORM_PACK16,
			VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR = VK_FORMAT_R10X6G10X6_UNORM_2PACK16,
			VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16,
			VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16,
			VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16,
			VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16,
			VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16,
			VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16,
			VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16,
			VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16,
			VK_FORMAT_R12X4_UNORM_PACK16_KHR = VK_FORMAT_R12X4_UNORM_PACK16,
			VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR = VK_FORMAT_R12X4G12X4_UNORM_2PACK16,
			VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16,
			VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16,
			VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16,
			VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16,
			VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16,
			VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16,
			VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16,
			VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16,
			VK_FORMAT_G16B16G16R16_422_UNORM_KHR = VK_FORMAT_G16B16G16R16_422_UNORM,
			VK_FORMAT_B16G16R16G16_422_UNORM_KHR = VK_FORMAT_B16G16R16G16_422_UNORM,
			VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM,
			VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM,
			VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM,
			UNormalized_G16_B16_R16_2Plane_422_KHR     = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR,
			UNormalized_3Plane_G16_B16_R16_444_KHR     = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR   // Specifies an unsigned normalized multi-planar format that has a 16-bit G component in each 16-bit word of plane 0, a 16-bit B component in each 16-bit word of plane 1, and a 16-bit R component in each 16-bit word of plane 2. Each plane has the same dimensions and each R, G and B component contributes to a single texel. The location of each plane when this image is in linear layout can be determined via vkGetImageSubresourceLayout, using VK_IMAGE_ASPECT_PLANE_0_BIT for the G plane, VK_IMAGE_ASPECT_PLANE_1_BIT for the B plane, and VK_IMAGE_ASPECT_PLANE_2_BIT for the R plane.
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkColorSpaceKHR.html">Specification</a>  */
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

		/** @brief <a href="VkPresentModeKHR">Specification</a>  */
		enum class EPresentationMode : uint32
		{
			Immediate               = VK_PRESENT_MODE_IMMEDIATE_KHR                ,
			Mailbox                 = VK_PRESENT_MODE_MAILBOX_KHR                  ,
			FIFO                    = VK_PRESENT_MODE_FIFO_KHR                     ,
			FIFO_Relaxed            = VK_PRESENT_MODE_FIFO_RELAXED_KHR             ,
			SharedDemandRefresh     = VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR    ,
			SharedContinuousRefresh = VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSwapchainCreateFlagBitsKHR.html">Specification</a>  */
		enum class ESwapchainCreateFlag : uint32
		{
			SplitInstanceBindRegions = VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR ,
			CreateProtected          = VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR                   ,
			CreateMutableFormat      = VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR
		};

		SpecifyBitmaskable(ESwapchainCreateFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSharingMode.html">Specification</a>  */
		enum class ESharingMode : uint32
		{
			Excusive   = VK_SHARING_MODE_EXCLUSIVE ,
			Concurrent = VK_SHARING_MODE_CONCURRENT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageViewCreateFlagBits.html">Specification</a>  */
		enum class EImageViewCreateFlag : uint32
		{
			Fragment_DensityMapDynamiic = VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT,
		};

		SpecifyBitmaskable(EImageViewCreateFlag)

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageView.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkComponentSwizzle.html">Specification</a>  */
		enum class EComponentSwizzle : uint32
		{
			Identitity = VK_COMPONENT_SWIZZLE_IDENTITY,
			Zero       = VK_COMPONENT_SWIZZLE_ZERO    ,
			One        = VK_COMPONENT_SWIZZLE_ONE     ,
			R          = VK_COMPONENT_SWIZZLE_R       ,
			G          = VK_COMPONENT_SWIZZLE_G       ,
			B          = VK_COMPONENT_SWIZZLE_B       ,
			A          = VK_COMPONENT_SWIZZLE_A
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageAspectFlagBits.html">Specification</a>  */
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
			KHR_Plane_2   = VK_IMAGE_ASPECT_PLANE_2_BIT_KHR
		};

		SpecifyBitmaskable(EImageAspect);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPipelineShaderStageCreateFlagBits.html">Specification</a>  */
		enum class EPipelineShaderStageCreateFlag : uint32
		{
			AllowVaryingSubgroupSize = VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT,
			RequireFullSubgroups     = VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT
		};

		SpecifyBitmaskable(EPipelineShaderStageCreateFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkShaderStageFlagBits.html">Specification</a>  */
		enum class EShaderStageFlag : uint32_t
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
			Callable_NV            = VK_SHADER_STAGE_CALLABLE_BIT_NV            
		};

		SpecifyBitmaskable(EShaderStageFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkVertexInputRate.html">Specification</a>  */
		enum class EVertexInputRate : uint32
		{
			Vertex   = VK_VERTEX_INPUT_RATE_VERTEX,
			Instance = VK_VERTEX_INPUT_RATE_INSTANCE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPrimitiveTopology.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#primsrast-polygonmode">Specification</a>  */
		enum class EPolygonMode : uint32
		{
			Fill              = VK_POLYGON_MODE_FILL             ,
			Line              = VK_POLYGON_MODE_LINE             ,
			Point             = VK_POLYGON_MODE_POINT            ,
			NV_Fill_Rectangle = VK_POLYGON_MODE_FILL_RECTANGLE_NV
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkCullModeFlagBits.html">Specification</a>  */
		enum class ECullModeFlag : uint32
		{
			None           = VK_CULL_MODE_NONE          ,
			Front          = VK_CULL_MODE_FRONT_BIT     ,
			Back           = VK_CULL_MODE_BACK_BIT      ,
			Front_And_Back = VK_CULL_MODE_FRONT_AND_BACK 
		};

		SpecifyBitmaskable(ECullModeFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkFrontFace.html">Specification</a>  */
		enum class EFrontFace : uint32
		{
			CounterClockwise = VK_FRONT_FACE_COUNTER_CLOCKWISE,
			Clockwise        = VK_FRONT_FACE_CLOCKWISE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBlendFactor.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBlendOp.html">Specification</a>  */
		enum class EBlendOperation : uint32
		{
			Add                        = VK_BLEND_OP_ADD                   ,
			Subtract                   = VK_BLEND_OP_SUBTRACT              ,
			ReverseSubtract            = VK_BLEND_OP_REVERSE_SUBTRACT      ,
			Mininum                    = VK_BLEND_OP_MIN                   ,
			Maximum                    = VK_BLEND_OP_MAX                   ,
			Zero_Extension             = VK_BLEND_OP_ZERO_EXT              ,
			Source_Extension           = VK_BLEND_OP_SRC_EXT               ,
			Destination_Extension      = VK_BLEND_OP_DST_EXT               ,
			SourceOver_Extension       = VK_BLEND_OP_SRC_OVER_EXT          ,
			DestinationOver_Extension  = VK_BLEND_OP_DST_OVER_EXT          ,
			SourceIn_Extension         = VK_BLEND_OP_SRC_IN_EXT            ,
			DestinationIN_Extension    = VK_BLEND_OP_DST_IN_EXT            ,
			SourceOut_Extension        = VK_BLEND_OP_SRC_OUT_EXT           ,
			DestinationOut_Extension   = VK_BLEND_OP_DST_OUT_EXT           ,
			SourceAtop_Extension       = VK_BLEND_OP_SRC_ATOP_EXT          ,
			DestinationATop_Extension  = VK_BLEND_OP_DST_ATOP_EXT          ,
			XOR_Extension              = VK_BLEND_OP_XOR_EXT               ,
			Multiply_Extension         = VK_BLEND_OP_MULTIPLY_EXT          ,
			Screen_Extension           = VK_BLEND_OP_SCREEN_EXT            ,
			Overlay_Extension          = VK_BLEND_OP_OVERLAY_EXT           ,
			Darken_Extension           = VK_BLEND_OP_DARKEN_EXT            ,
			Lighten_Extension          = VK_BLEND_OP_LIGHTEN_EXT           ,
			ColorDodge_Extension       = VK_BLEND_OP_COLORDODGE_EXT        ,
			ColorBurn_Extension        = VK_BLEND_OP_COLORBURN_EXT         ,
			HardLight_Extension        = VK_BLEND_OP_HARDLIGHT_EXT         ,
			SoftLight_Extension        = VK_BLEND_OP_SOFTLIGHT_EXT         ,
			Difference_Extension       = VK_BLEND_OP_DIFFERENCE_EXT        ,
			Exclusion_Extention        = VK_BLEND_OP_EXCLUSION_EXT         ,
			Invert_Extension           = VK_BLEND_OP_INVERT_EXT            ,
			Invert_RGB_Extension       = VK_BLEND_OP_INVERT_RGB_EXT        ,
			LinearDodge_Extension      = VK_BLEND_OP_LINEARDODGE_EXT       ,
			LinearBurn_Extension       = VK_BLEND_OP_LINEARBURN_EXT        ,
			VividLight_Extension       = VK_BLEND_OP_VIVIDLIGHT_EXT        ,
			LinearLight_Extension      = VK_BLEND_OP_LINEARLIGHT_EXT       ,
			PinLight_Extension         = VK_BLEND_OP_PINLIGHT_EXT          ,
			Hardmix_Extension          = VK_BLEND_OP_HARDMIX_EXT           ,
			HSL_Hue_Extension          = VK_BLEND_OP_HSL_HUE_EXT           ,
			HSL_Saturation_Extension   = VK_BLEND_OP_HSL_SATURATION_EXT    ,
			HSL_Color_Extension        = VK_BLEND_OP_HSL_COLOR_EXT         ,
			HSL_Luminosity_Extension   = VK_BLEND_OP_HSL_LUMINOSITY_EXT    ,
			Plus_Extension             = VK_BLEND_OP_PLUS_EXT              ,
			PlusClamped_Extension      = VK_BLEND_OP_PLUS_CLAMPED_EXT      ,
			PlusClampedAlpha_Extension = VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT,
			PlusDarker_Extension       = VK_BLEND_OP_PLUS_DARKER_EXT       ,
			Minus_Extension            = VK_BLEND_OP_MINUS_EXT             ,
			MinusClamped_Extension     = VK_BLEND_OP_MINUS_CLAMPED_EXT     ,
			Constrast_Extension        = VK_BLEND_OP_CONTRAST_EXT          ,
			InvertOVG_Extension        = VK_BLEND_OP_INVERT_OVG_EXT        ,
			Red_Extension              = VK_BLEND_OP_RED_EXT               ,
			Green_Extension            = VK_BLEND_OP_GREEN_EXT             ,
			Blue_Extension             = VK_BLEND_OP_BLUE_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkColorComponentFlagBits.html">Specification</a>  */
		enum class EColorComponentFlag : uint32
		{
			R = VK_COLOR_COMPONENT_R_BIT,
			G = VK_COLOR_COMPONENT_G_BIT,
			B = VK_COLOR_COMPONENT_B_BIT,
			A = VK_COLOR_COMPONENT_A_BIT
		};

		SpecifyBitmaskable(EColorComponentFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkLogicOp.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDynamicState.html">Specification</a>  */
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

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDescriptorSetLayoutCreateFlagBits.html">Specification</a>  */
		enum class EDescriptorSetLayoutCreateFlag : uint32
		{
			UpdateAfterBindPool           = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT    ,
			PushDescriptor                = VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR       ,
			UpdateAfterBindPool_Extension = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT
		};

		SpecifyBitmaskable(EDescriptorSetLayoutCreateFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDescriptorType.html">Specification</a>  */
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

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBufferCreateFlagBits.html">Specification</a> 
		 * 
		 * @details
		 * 
		 */
		enum class EBufferCreateFlag : uint32
		{
			SparseBinding                       = VK_BUFFER_CREATE_SPARSE_BINDING_BIT                   ,
			SparseResidency                     = VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT                 ,
			SparseAliased                       = VK_BUFFER_CREATE_SPARSE_ALIASED_BIT                   ,
			Protected                           = VK_BUFFER_CREATE_PROTECTED_BIT                        ,
			DeviceAddressCaptureReplay          = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT    ,
			DeviceAddressCaptureReplayExtension = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT,
			DeviceAddressCaptureReplayKHR       = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR
		};

		SpecifyBitmaskable(EBufferCreateFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBufferUsageFlagBits.html">Specification</a>  */
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
			IndirectBuffer      = VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT     
		};

		SpecifyBitmaskable(EBufferUsage);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageCreateFlagBits.html">Specification</a> */
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
			Alias_KHR                          = VK_IMAGE_CREATE_ALIAS_BIT_KHR                            
		};

		SpecifyBitmaskable(EImageCreateFlag);

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageType.html">Specification</a>  */
		enum class EImageType : uint32
		{
			_1D = VK_IMAGE_TYPE_1D,
			_2D = VK_IMAGE_TYPE_2D,
			_3D = VK_IMAGE_TYPE_3D
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageTiling.html">Specification</a>  */
		enum class EImageTiling : uint32
		{
			Optional                     = VK_IMAGE_TILING_OPTIMAL                ,
			Linear                       = VK_IMAGE_TILING_LINEAR                 ,
			DRM_FormatModifier_Extension = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageLayout.html">Specification</a>  */
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
    }
}
