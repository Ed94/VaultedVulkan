/** @file VT_PhysicalDevice.hpp

@brief VaultedThermals: Physical Device

@details
A physical device usually represents a single complete implementation of Vulkan 
(excluding instance-level functionality) available to the host, of which there are a finite number. 


<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
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



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		@brief Represents a physical device.
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
		 */
		struct PhysicalDevice
		{
			using Memory = V0::Memory;

			using Handle = VkPhysicalDevice;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevice">Specification</a> 

			static constexpr DeviceSize MaxNameSize        = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;
			static constexpr DeviceSize MaxDeviceGroupSize = VK_MAX_DEVICE_GROUP_SIZE        ;

			static constexpr DeviceSize MaxDriverNameSize = VK_MAX_DRIVER_NAME_SIZE;
			static constexpr DeviceSize MaxDriverInfoSize = VK_MAX_DRIVER_INFO_SIZE;

			using NameStr = char[MaxNameSize];

			using DriverNameStr = char[MaxDriverNameSize];
			using DriverInfoStr = char[MaxDriverInfoSize];

		    using EDeviceType = EPhysicalDeviceType;	

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a> 
			*/
			struct ConformanceVersion : V0::VKStruct_Base<VkConformanceVersion>
			{
				uInt8 Major   ;
				uInt8 Minor   ;
				uInt8 Subminor;
				uInt8 Patch   ;
			};

			/**
			@brief Structure describing the fine-grained features that can be supported by an implementation.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceFeatures">Specification</a> 
			*/
			struct Features : V0::VKStruct_Base<VkPhysicalDeviceFeatures>
			{
				Bool RobustBufferAccess                     ;   ///< Out of bounds buffer accesses are well defined.
				Bool FullDrawIndexUint32                    ;   ///< full 32-bit range of indices are supported for indexed draw calls using VK_INDEX_TYPE_UINT32.
				Bool ImageCubeArray                         ;
				Bool IndependentBlend                       ;
				Bool GeometryShader                         ;
				Bool TessellationShader                     ;
				Bool SampleRateShading                      ;
				Bool DualSrcBlend                           ;
				Bool LogicOperations                        ;
				Bool MultiDrawIndirect                      ;
				Bool drawIndirectFirstInstance              ;
				Bool DepthClamping                          ;
				Bool DepthBiasClamping                      ;
				Bool NonSolidFillModes                      ;   ///< Point and wireframe fill modes are supported.
				Bool DepthBounds                            ;   ///< Depth bounds test supported.
				Bool WideLines                              ;
				Bool LargePoints                            ;
				Bool AlphaToOne                             ;   ///< The implementation can replace the alpha value of the color fragment output to the maximum representable alpha value for fixed - point colors or 1.0 for floating - point colors.
				Bool MultiViewport                          ;   ///< Multiple viewports are supported. (VR)
				Bool SamplerAnisotropy                      ;
				Bool TextureCompressionETC2                 ;
				Bool TextureCompressionASTC_LDR             ;
				Bool TextureCompressionBC                   ;
				Bool OcclusionQueryPrecise                  ;
				Bool PipelineStatisticsQuery                ;
				Bool VertexPipelineStoresAndAtomics         ;
				Bool FragmentStoresAndAtomics               ;
				Bool ShaderTessellationAndGeometryPointSize ;
				Bool ShaderImageGatherExtended              ;
				Bool ShaderStorageImageExtendedFormats      ;
				Bool ShaderStorageImageMultisample          ;
				Bool ShaderStorageImageReadWithoutFormat    ;
				Bool ShaderStorageImageWriteWithoutFormat   ;
				Bool ShaderUniformBufferArrayDynamicIndexing;
				Bool ShaderSampledImageArrayDynamicIndexing ;
				Bool ShaderStorageBufferArrayDynamicIndexing;
				Bool ShaderStorageImageArrayDynamicIndexing ;
				Bool ShaderClipDistance                     ;
				Bool ShaderCullDistance                     ;
				Bool ShaderFloat64                          ;
				Bool ShaderInt64                            ;
				Bool ShaderInt16                            ;
				Bool ShaderResourceResidency                ;
				Bool ShaderResourceMinLod                   ;
				Bool SparseBinding                          ;
				Bool SparseResidencyBuffer                  ;
				Bool SparseResidencyImage2D                 ;
				Bool SparseResidencyImage3D                 ;
				Bool SparseResidency2Samples                ;
				Bool SparseResidency4Samples                ;
				Bool SparseResidency8Samples                ;
				Bool SparseResidency16Samples               ;
				Bool SparseResidencyAliased                 ;
				Bool VariableMultisampleRate                ;
				Bool InheritedQueries                       ;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceGroupProperties ">Specification</a> 
			*/
			struct Group : V0::VKStruct_Base<VkPhysicalDeviceGroupProperties, EStructureType::PhysicalDevice_GroupProperties>
			{
				using DeviceListing = Handle[MaxDeviceGroupSize];

				EType         SType              ;
				void*         Next               ;
				uint32        PhysicalDeviceCount;
				DeviceListing PhysicalDevices    ;
				Bool          SubsetAllocation   ;
			};

			/**
			@brief Structure reporting implementation-dependent physical device limits.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceLimits">Specification</a> 
			*/
			struct Limits : V0::VKStruct_Base<VkPhysicalDeviceLimits>
			{
				uint32           MaxImageDimension1D                            ;
				uint32           MaxImageDimension2D                            ;
				uint32           MaxImageDimension3D                            ;
				uint32           MaxImageDimensionCube                          ;
				uint32           MaxImageArrayLayers                            ;
				uint32           MaxTexelBufferElements                         ;
				uint32           MaxUniformBufferRange                          ;
				uint32           MaxStorageBufferRange                          ;
				uint32           MaxPushConstantsSize                           ;
				uint32           MaxMemoryAllocationCount                       ;
				uint32           MaxSamplerAllocationCount                      ;
				DeviceSize       BufferImageGranularity                         ;
				DeviceSize       SparseAddressSpaceSize                         ;
				uint32           MaxBoundDescriptorSets                         ;
				uint32           MaxPerStageDescriptorSamplers                  ;
				uint32           MaxPerStageDescriptorUniformBuffers            ;
				uint32           MaxPerStageDescriptorStorageBuffers            ;
				uint32           MaxPerStageDescriptorSampledImages             ;
				uint32           MaxPerStageDescriptorStorageImages             ;
				uint32           MaxPerStageDescriptorInputAttachments          ;
				uint32           MaxPerStageResources                           ;
				uint32           MaxDescriptorSetSamplers                       ;
				uint32           MaxDescriptorSetUniformBuffers                 ;
				uint32           MaxDescriptorSetUniformBuffersDynamic          ;
				uint32           MaxDescriptorSetStorageBuffers                 ;
				uint32           MaxDescriptorSetStorageBuffersDynamic          ;
				uint32           MaxDescriptorSetSampledImages                  ;
				uint32           MaxDescriptorSetStorageImages                  ;
				uint32           MaxDescriptorSetInputAttachments               ;
				uint32           MaxVertexInputAttributes                       ;
				uint32           MaxVertexInputBindings                         ;
				uint32           MaxVertexInputAttributeOffset                  ;
				uint32           MaxVertexInputBindingStride                    ;
				uint32           MaxVertexOutputComponents                      ;
				uint32           MaxTessellationGenerationLevel                 ;
				uint32           MaxTessellationPatchSize                       ;
				uint32           MaxTessellationControlPerVertexInputComponents ;
				uint32           MaxTessellationControlPerVertexOutputComponents;
				uint32           MaxTessellationControlPerPatchOutputComponents ;
				uint32           MaxTessellationControlTotalOutputComponents    ;
				uint32           MaxTessellationEvaluationInputComponents       ;
				uint32           MaxTessellationEvaluationOutputComponents      ;
				uint32           MaxGeometryShaderInvocations                   ;
				uint32           MaxGeometryInputComponents                     ;
				uint32           MaxGeometryOutputComponents                    ;
				uint32           MaxGeometryOutputVertices                      ;
				uint32           MaxGeometryTotalOutputComponents               ;
				uint32           MaxFragmentInputComponents                     ;
				uint32           MaxFragmentOutputAttachments                   ;
				uint32           MaxFragmentDualSrcAttachments                  ;
				uint32           MaxFragmentCombinedOutputResources             ;
				uint32           MaxComputeSharedMemorySize                     ;
				uint32           MaxComputeWorkGroupCount[3]                    ;
				uint32           MaxComputeWorkGroupInvocations                 ;
				uint32           MaxComputeWorkGroupSize[3]                     ;
				uint32           SubPixelPrecisionBits                          ;
				uint32           SubTexelPrecisionBits                          ;
				uint32           MipmapPrecisionBits                            ;
				uint32           MaxDrawIndexedIndexValue                       ;
				uint32           MaxDrawIndirectCount                           ;
				float32          MaxSamplerLodBias                              ;
				float32          MaxSamplerAnisotropy                           ;
				uint32           MaxViewports                                   ;
				uint32           MaxViewportDimensions[2]                       ;
				float32          ViewportBoundsRange[2]                         ;
				uint32           ViewportSubPixelBits                           ;
				size_t           MinMemoryMapAlignment                          ;
				DeviceSize       MinTexelBufferOffsetAlignment                  ;
				DeviceSize       MinUniformBufferOffsetAlignment                ;
				DeviceSize       MinStorageBufferOffsetAlignment                ;
				sint32           MinTexelOffset                                 ;
				uint32           MaxTexelOffset                                 ;
				sint32           MinTexelGatherOffset                           ;
				uint32           MaxTexelGatherOffset                           ;
				float32          MinInterpolationOffset                         ;
				float32          MaxInterpolationOffset                         ;
				uint32           SubPixelInterpolationOffsetBits                ;
				uint32           MaxFramebufferWidth                            ;
				uint32           MaxFramebufferHeight                           ;
				uint32           MaxFramebufferLayers                           ;
				SampleCountFlags FramebufferColorSampleCounts                   ;
				SampleCountFlags FramebufferDepthSampleCounts                   ;
				SampleCountFlags FramebufferStencilSampleCounts                 ;			    
				SampleCountFlags FramebufferNoAttachmentsSampleCounts           ;
				uint32           MaxColorAttachments                            ;
				SampleCountFlags SampledImageColorSampleCounts                  ;
				SampleCountFlags SampledImageIntegerSampleCounts                ;
				SampleCountFlags SampledImageDepthSampleCounts                  ;
				SampleCountFlags SampledImageStencilSampleCounts                ;
				SampleCountFlags StorageImageSampleCounts                       ;
				uint32           MaxSampleMaskWords                             ;
				Bool             TimestampComputeAndGraphics                    ;
				float32          TimestampPeriod                                ;
				uint32           MaxClipDistances                               ;
				uint32           MaxCullDistances                               ;
				uint32           MaxCombinedClipAndCullDistances                ;
				uint32           DiscreteQueuePriorities                        ;
				float32          PointSizeRange[2]                              ;
				float32          LineWidthRange[2]                              ;
				float32          PointSizeGranularity                           ;
				float32          LineWidthGranularity                           ;
				Bool             StrictLines                                    ;
				Bool             StandardSampleLocations                        ;
				DeviceSize       OptimalBufferCopyOffsetAlignment               ;
				DeviceSize       OptimalBufferCopyRowPitchAlignment             ;
				DeviceSize       NonCoherentAtomSize                            ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceMemoryProperties">Specification</a> 
			 */
			struct MemoryProperties : V0::VKStruct_Base<VkPhysicalDeviceMemoryProperties>
			{
				uint32       TypeCount            ;
				Memory::Type Types[MaxMemoryTypes];
				uint32       HeapCount            ;
				Memory::Heap Heaps[MaxMemoryHeaps];
			};

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterKHR">Specification</a> 
			*/
			struct PerformanceCounter : V0::VKStruct_Base<VkPerformanceCounterKHR, EStructureType::PerformacneCounter_KHR>
			{
				      EType                      SType      ;
				const void*                      Next       ;
				      EPerformanceCounterUnit    Unit       ;
				      EPerformanceCounterScope   Scope      ;
				      EPerformanceCounterStorage Storage    ;
				      UUID                       CounterUUID;


				using DescriptionFlags = Bitmask<EPerformanceCounterDescriptionFlag, VkPerformanceCounterDescriptionFlagsKHR>;

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterDescriptionKHR">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Description : V0::VKStruct_Base<VkPerformanceCounterDescriptionKHR>
				{
					      EType            SType      ;
					const void*            Next       ;
					      DescriptionFlags Flags      ;
					      DescrptionStr    Name       ;
					      DescrptionStr    Category   ;
					      DescrptionStr    Description;
				};
			};

			/**
			@brief Structure specifying various sparse related properties of the physical device.

			@details
			Some features of the implementation are not possible to disable, and are reported to allow applications 
			to alter their sparse resource usage accordingly. These read-only capabilities are reported in the 
			VkPhysicalDeviceProperties::sparseProperties member, which is a structure of type VkPhysicalDeviceSparseProperties.
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#sparsememory-physicalprops">Specification</a> 
			*/
			struct SparseMemoryProperties : V0::VKStruct_Base<VkPhysicalDeviceSparseProperties>
			{
				Bool ResidencyStandard2DBlockShape           ;
				Bool ResidencyStandard2DMultisampleBlockShape;
				Bool ResidencyStandard3DBlockShape           ;
				Bool ResidencyAlignedMipSize                 ;
				Bool ResidencyNonResidentStrict              ;
			};

			/**
			@brief Container of query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties">Specification</a> 
			*/
			struct Properties : V0::VKStruct_Base<VkPhysicalDeviceProperties>
			{
				uint32                 API_Version      ;
				uint32                 DriverVersion    ;
				uint32                 VenderID         ;
				uint32                 ID               ;
				EDeviceType            Type             ;
				NameStr                Name             ;
				UUID                   PipelineCacheUUID;
				Limits                 LimitsSpec       ;
				SparseMemoryProperties SpareProperties  ;

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties">Specification</a> 
				*/
				struct DeviceID : V0::VKStruct_Base<VkPhysicalDeviceIDProperties >
				{
					EType  SType          ;
					void*  Next           ;
					UUID   DeviceUUID     ;
					UUID   DriverUUID     ;
					UUID   DeviceLUID     ;
					uint32 DeviceNodeMask ;
					Bool   DeviceLUIDValid;
				};	

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevicePCIBusInfoPropertiesEXT">Specification</a> 
				*/
				struct PCIBusInfo : V0::VKStruct_Base<VkPhysicalDevicePCIBusInfoPropertiesEXT, EStructureType::PhysicalDevice_PCI_BUS_Info_Properties_EXT>
				{
					EType  SType   ;
					void*  Next    ;
					uint32 Domain  ;
					uint32 Bus     ;
					uint32 Device  ;
					uint32 Function;
				};

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceVulkan11Properties">Specification</a> 
				*/
				struct Vulkan11 : V0::VKStruct_Base<VkPhysicalDeviceVulkan11Properties, EStructureType::PhysicalDevice_Vulkan_1_1_Properties>
				{
					using ShaderStageFlags = Bitmask<EShaderStageFlag, VkShaderStageFlags>;

					EType                  SType                            ;
					void*                  Next                             ;
					UUID                   DeviceUUID                       ;
					UUID                   DriverUUID                       ;
					UUID                   DeviceLUID                       ;
					uint32                 DeviceNodeMask                   ;
					Bool                   DeviceLUIDValid                  ;
					uint32                 SubgroupSize                     ;
					ShaderStageFlags       SubgroupSupportedStages          ;
					ESubgroupFeaturesFlag  SubgroupSupportedOperations      ;
					Bool                   SubgroupQuadOperationsInAllStages;
					EPointClippingBehavior PointClippingBehavior            ;
					uint32                 MaxMultiviewViewCount            ;
					uint32                 MaxMultiviewInstanceIndex        ;
					Bool                   ProtectedNoFault                 ;
					uint32                 MaxPerSetDescriptors             ;
					DeviceSize             MaxMemoryAllocationSize          ;
				};

				/**
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceVulkan12Properties">Specification</a> 
				*  
				* @todo Implement.
				*/
				struct Vulkan12 : V0::VKStruct_Base<VkPhysicalDeviceVulkan12Properties, EStructureType::PhysicalDevice_Vulkan_1_2_Properties>
				{
					EType                           SType                                               ;
					void*                           Next                                                ;
					EDriverID                       DriverID                                            ;
					DriverNameStr                   DriverName                                          ;
					DriverInfoStr                   DriverInfo                                          ;
					ConformanceVersion              ConformanceVersion                                  ;
					EShaderFloatControlIndependence DenormBehaviorIndependence                          ;
					EShaderFloatControlIndependence RoundingModeIndependence                            ;
					Bool                            ShaderSignedZeroInfNanPreserveFloat16               ;
					Bool                            ShaderSignedZeroInfNanPreserveFloat32               ;
					Bool                            ShaderSignedZeroInfNanPreserveFloat64               ;
					Bool                            ShaderDenormPreserveFloat16                         ;
					Bool                            ShaderDenormPreserveFloat32                         ;
					Bool                            ShaderDenormPreserveFloat64                         ;
					Bool                            ShaderDenormFlushToZeroFloat16                      ;
					Bool                            ShaderDenormFlushToZeroFloat32                      ;
					Bool                            ShaderDenormFlushToZeroFloat64                      ;
					Bool                            ShaderRoundingModeRTEFloat16                        ;
					Bool                            ShaderRoundingModeRTEFloat32                        ;
					Bool                            ShaderRoundingModeRTEFloat64                        ;
					Bool                            ShaderRoundingModeRTZFloat16                        ;
					Bool                            ShaderRoundingModeRTZFloat32                        ;
					Bool                            ShaderRoundingModeRTZFloat64                        ;
					uint32                          MaxUpdateAfterBindDescriptorsInAllPools             ;
					Bool                            ShaderUniformBufferArrayNonUniformIndexingNative    ;
					Bool                            ShaderSampledImageArrayNonUniformIndexingNative     ;
					Bool                            ShaderStorageBufferArrayNonUniformIndexingNative    ;
					Bool                            ShaderStorageImageArrayNonUniformIndexingNative     ;
					Bool                            ShaderInputAttachmentArrayNonUniformIndexingNative  ;
					Bool                            RobustBufferAccessUpdateAfterBind                   ;
					Bool                            QuadDivergentImplicitLod                            ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindSamplers        ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindUniformBuffers  ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindStorageBuffers  ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindSampledImages   ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindStorageImages   ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindInputAttachments;
					uint32                          MaxPerStageUpdateAfterBindResources                 ;
					uint32                          MaxDescriptorSetUpdateAfterBindSamplers             ;
					uint32                          MaxDescriptorSetUpdateAfterBindUniformBuffers       ;
					uint32                          MaxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
					uint32                          MaxDescriptorSetUpdateAfterBindStorageBuffers       ;
					uint32                          MaxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
					uint32                          MaxDescriptorSetUpdateAfterBindSampledImages        ;
					uint32                          MaxDescriptorSetUpdateAfterBindStorageImages        ;
					uint32                          MaxDescriptorSetUpdateAfterBindInputAttachments     ;
					ResolveModeFlags                SupportedDepthResolveModes                          ;
					ResolveModeFlags                SupportedStencilResolveModes                        ;
					Bool                            IndependentResolveNone                              ;
					Bool                            IndependentResolve                                  ;
					Bool                            FilterMinmaxSingleComponentFormats                  ;
					Bool                            FilterMinmaxImageComponentMapping                   ;
					uInt64                          MaxTimelineSemaphoreValueDifference                 ;
					SampleCountFlags                FramebufferIntegerColorSampleCounts                 ;
				};
			};

			/**
			 * @brief.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties2">Specification</a> 
			 */
			struct Properties2 : V0::VKStruct_Base<VkPhysicalDeviceProperties2, EStructureType::PhysicalDevice_Properties_2>
			{
				EType      SType     ;
				void*      Next      ;
				Properties Properties;
			};

			/**
			@brief A set of queues that have common properties and support the same functionality.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties">Specification</a> 
			*/
			struct QueueFamilyProperties : V0::VKStruct_Base<VkQueueFamilyProperties>
			{
				/**
				* @brief Bitmask specifying capabilities of queues in a queue family.     
				* 
				* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFlags">Specification</a> 
				*/
				using Flags = Bitmask<EQueueFlag , VkQueueFlags>;

				Flags    QueueFlags                 ;
				uint32   QueueCount                 ;
				uint32   TimestampValidBits         ;
				Extent3D MinImageTransferGranularity;				
			};

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties2">Specification</a> 
			*/
			struct QueueFamilyProperties2 : V0::VKStruct_Base<VkQueueFamilyProperties2, EStructureType::QueueFamily_Properties_2>
			{
				EType                 SType     ;
				void*                 Next      ;
				QueueFamilyProperties Properties;

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyCheckpointPropertiesNV">Specification</a> 
				*/
				struct Checkpoint : V0::VKStruct_Base<VkQueueFamilyCheckpointPropertiesNV, EStructureType::QueueFamilyCheckpoint_Properties_NV>
				{
					using Pipeline_StageFlags = Bitmask<EPipelineStageFlag, VkPipelineStageFlags>;   ///< Not defined yet. (See VT_Pipelines.hpp)

					EType               SType                       ;
					void*               Next                        ;
					Pipeline_StageFlags CheckpointExecutionStageMask;
				};
			};

			/**
			@brief Query supported features. Reports capabilities of a physical device.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFeatures">Specification</a> 
			*/
			static void GetFeatures(Handle _handle, Features& _features)
			{
				vkGetPhysicalDeviceFeatures(_handle, _features.operator VkPhysicalDeviceFeatures*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFormatProperties">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _format
			 * \param _properties
			 */
			static void GetFormatProperties(Handle _handle, EFormat _format, FormatProperties& _properties)
			{
				vkGetPhysicalDeviceFormatProperties(_handle, VkFormat(_format), _properties);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceMemoryProperties">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _properties
			 */
			static void GetMemoryProperties(Handle _handle, MemoryProperties& _properties)
			{
				vkGetPhysicalDeviceMemoryProperties(_handle, _properties);
			}

			/**
			@brief Query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties">Specification</a> 
			*/
			static void GetProperties(Handle _handle, Properties& _properties)
			{
				vkGetPhysicalDeviceProperties(_handle, _properties.operator VkPhysicalDeviceProperties*());
			}

			/**
			 * @brief Query general properties of physical devices once enumerated (Second Ver).
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties2">Specification</a> 
			 */
			static void GetProperties2
			(
				Handle       _handle    ,
				Properties2& _properties
			)
			{
				vkGetPhysicalDeviceProperties2(_handle, _properties);
			}

			/**
			@brief Device extensions add new device-level functionality to the API, outside of the core specification.

			@details
			Query the extensions available to a given physical device.

			When pLayerName parameter is NULL, only extensions provided by the Vulkan implementation or by implicitly enabled layers are returned. 
			When pLayerName is the name of a layer, the device extensions provided by that layer are returned.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_device_extensions">Specification</a> 
			*/
			static EResult QueryExtensionProperties(Handle _handle, RoCStr _layerName, uint32* _numExtensions, ExtensionProperties* _extensionPropertiesContainer)
			{
				return EResult(vkEnumerateDeviceExtensionProperties(_handle, _layerName, _numExtensions, _extensionPropertiesContainer->operator VkExtensionProperties*()));
			}

			/**
			@brief Query properties of queues available on a physical device. Reports properties of the queues of the specified physical device.

			@details
			If pQueueFamilyProperties is NULL, then the number of queue families available is returned in pQueueFamilyPropertyCount. 
			Implementations must support at least one queue family. Otherwise, pQueueFamilyPropertyCount must point to a variable set 
			by the user to the number of elements in the pQueueFamilyProperties array, and on return the variable is overwritten 
			with the number of structures actually written to pQueueFamilyProperties.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties">Specification</a> 
			*/
			static void QueryQueueFamilyProperties(Handle _handle, uint32* _numQueueFamilies, QueueFamilyProperties* _queueFamilies)
			{
				vkGetPhysicalDeviceQueueFamilyProperties(_handle, _numQueueFamilies, _queueFamilies->operator VkQueueFamilyProperties*());
			}	

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties2">Specification</a> 
			*/
			static void QueryQueueFamilyProperties2
			(
				Handle                  _handle       ,
				uint32*                 _numProperties,
				QueueFamilyProperties2* _properties
			)
			{
				vkGetPhysicalDeviceQueueFamilyProperties2(_handle, _numProperties, _properties->operator VkQueueFamilyProperties2*());
			}

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">Specification</a> 
			*/
			static EResult QueryPerfomranceQueryCounters
			(
				Handle                           _handle             ,
				uint32                           _queueFamilyIndex   ,
				uint32*                          _numCounters        ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			)
			{
				return EResult(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
				(
					_handle,
					_queueFamilyIndex,
					_numCounters,
					_counters->operator VkPerformanceCounterKHR*(),
					_counterDescriptions->operator VkPerformanceCounterDescriptionKHR*()
				));
			}
		};
	}

	namespace V2
	{
		using V1::ExtensionProperties;

		/**
		@brief Represents a physical device.
		*/
		struct PhysicalDevice : V1::PhysicalDevice
		{
			using Parent = V1::PhysicalDevice;

			struct Group : public Parent::Group
			{
				Group()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct PerformanceCounter : public Parent::PerformanceCounter
			{
				PerformanceCounter()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct Description : public Parent::PerformanceCounter::Description
				{
					Description()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Properties : public Parent::Properties
			{
				struct DeviceID : public Parent::Properties::DeviceID
				{
					DeviceID()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct PCIBusInfo : public Parent::Properties::PCIBusInfo
				{
					PCIBusInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct Vulkan11 : public Parent::Properties::Vulkan11
				{
					Vulkan11()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct Vulkan12 : public Parent::Properties::Vulkan12
				{
					Vulkan12()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Properties2 : public Parent::Properties2
			{
				Properties2()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct QueueFamilyProperties2 : public Parent::QueueFamilyProperties2
			{
				QueueFamilyProperties2()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct Checkpoint : public Parent::QueueFamilyProperties2::Checkpoint
				{
					Checkpoint()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			/**
			* @brief Checks to see if the specified extensions are supported by the physical device.
			* 
			* @todo make the extensions specified container generic using an interface.
			*/
			static bool CheckExtensionSupport(Handle _handle, RoCStr _extensionSpecified)
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableLayerExtensions(_handle, nullptr, availableExtensions);

				bool isSupported = false;

				for (const auto& extension : availableExtensions)
				{
					if (strcmp(extension.ExtensionName, _extensionSpecified) == 0)
					{
						isSupported = true;
					}
				}

				return isSupported;
			}

			/**
			 * @brief Checks to see if the specified extensions are supported by the physical device.
			 * 
			 * @todo make the extensions specified container generic using an interface.
			 */
			static bool CheckExtensionSupport(Handle _handle, std::vector<RoCStr> _extensionsSpecified)
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableLayerExtensions(_handle, nullptr, availableExtensions);

				using ExtensionNameSet = std::set<std::string>;

				ExtensionNameSet requiredExtensions(_extensionsSpecified.begin(), _extensionsSpecified.end());

				for (const auto& extension : availableExtensions)
				{
					requiredExtensions.erase(extension.ExtensionName);
				}

				bool isSupported = requiredExtensions.empty();

				return isSupported;
			}

			static uint32 FindMemoryType(Handle _handle, uint32 _typeFilter, Memory::PropertyFlags _properties)
			{
				MemoryProperties memProperties;

				GetMemoryProperties(_handle, memProperties);

				for (uint32 index = 0; index < memProperties.TypeCount; index++)
				{
					if
						(
						_typeFilter & (1 << index) &&
						(memProperties.Types[index].PropertyFlags & _properties) == _properties
						)
					{
						return index;
					}
				}

			#ifdef VT_Option__Use_STL_Exceptions
				throw std::runtime_error("Failed to find suitable memory type!");
			#endif
			}

			static EResult GetAvailableLayerExtensions(Handle _handle, RoCStr _layerName, std::vector<ExtensionProperties>& _extensionListing)
			{
				uint32 count;

				EResult returnCode = QueryExtensionProperties(_handle, _layerName, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_extensionListing.resize(count);

				returnCode = QueryExtensionProperties(_handle, _layerName, &count, _extensionListing.data());

				return returnCode;
			}

			/**
			 * @brief Gets all extensions for the known layers that the physical device supports.
			 * 
			 * @details 
			 * Note: The layers and extensions container must have the layer properties member of each element populated
			 * by the application instance.
			 * 
			 * \param _layersAndExtensions
			 * \return 
			 */
			static EResult GetAvailableLayersAndExtensions(Handle _handle, std::vector<LayerAndExtensionProperties>& _layersAndExtensions)
			{
				EResult result;

				for (uint32 index = 0; index < _layersAndExtensions.size(); index++)
				{
					result = GetAvailableLayerExtensions(_handle, _layersAndExtensions[index].Layer.Name, _layersAndExtensions[index].Extensions);

					if (result != EResult::Success) return result;
				}

				return result;
			}

			/**
			* @brief Provides the queue families for the respective device.
			* 
			* \param _device
			* \return 
			*/
			static std::vector<QueueFamilyProperties> GetAvailableQueueFamilies(Handle _handle)
			{
				std::vector<QueueFamilyProperties> queryResult; uint32 count;

				QueryQueueFamilyProperties(_handle, &count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(_handle, &count, queryResult.data());

				return queryResult;
			}

			static ESampleCount GetMaxSampleCount_ColorAndDepth(Handle _handle)
			{
				Properties properties;

				GetProperties(_handle, properties);

				SampleCountFlags counts
				(
					properties.LimitsSpec.FramebufferColorSampleCounts, 
					properties.LimitsSpec.FramebufferDepthSampleCounts
				);

				if (counts.Has(ESampleCount::_64)) return ESampleCount::_64;
				if (counts.Has(ESampleCount::_32)) return ESampleCount::_32;
				if (counts.Has(ESampleCount::_16)) return ESampleCount::_16;
				if (counts.Has(ESampleCount::_8 )) return ESampleCount::_8 ;
				if (counts.Has(ESampleCount::_4 )) return ESampleCount::_4 ;
				if (counts.Has(ESampleCount::_2 )) return ESampleCount::_2 ;

				return ESampleCount::_1;
			}
		};
	}

	namespace V4
	{
		class PhysicalDevice : public V2::PhysicalDevice
		{
		public:

			using Parent = V2::PhysicalDevice;
			
			PhysicalDevice()
			{
				handle = Null<Handle>;
			}

			void AssignHandle(Handle _handle) 
			{ 
				handle = _handle; 

				Parent::GetFeatures        (handle, features        );
				Parent::GetMemoryProperties(handle, memoryProperties);
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties2     (handle, properties2     );
			}

			/**
			* @brief Checks to see if the specified extensions are supported by the physical device.
			* 
			* @todo make the extensions specified container generic using an interface.
			*/
			bool CheckExtensionSupport(RoCStr _extensionSpecified)
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableExtensions(nullptr, availableExtensions);

				bool isSupported = false;

				for (const auto& extension : availableExtensions)
				{
					if (strcmp(extension.ExtensionName, _extensionSpecified) == 0)
					{
						isSupported = true;
					}
				}

				return isSupported;
			}

			/**
			 * @todo make the extensions specified container generic using an interface.
			 * 
			 * \param _handle
			 */
			bool CheckExtensionSupport(std::vector<RoCStr> _extensionsSpecified) const
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableExtensions(nullptr, availableExtensions);

				using ExtensionNameSet = std::set<std::string>;

				ExtensionNameSet requiredExtensions(_extensionsSpecified.begin(), _extensionsSpecified.end());

				for (const auto& extension : availableExtensions)
				{
					requiredExtensions.erase(extension.ExtensionName);
				}

				bool isSupported = requiredExtensions.empty();

				return isSupported;
			}

			uint32 FindMemoryType(uint32 _typeFilter, Memory::PropertyFlags _properties) const
			{
				for (uint32 index = 0; index < memoryProperties.TypeCount; index++)
				{
					auto flags = memoryProperties.Types[index].PropertyFlags;

					if
					(
						_typeFilter & (1 << index) &&
						(flags & _properties) == _properties
					)
					{
						return index;
					}
				}

			#ifdef VT_Option__Use_STL_Exceptions
				throw std::runtime_error("Failed to find suitable memory type!");
			#endif
			}

			EResult GetAvailableExtensions(RoCStr _layerName, std::vector<ExtensionProperties>& _extensionListing) const
			{
				return EResult(Parent::GetAvailableLayerExtensions(handle, _layerName, _extensionListing));
			}

			std::vector<QueueFamilyProperties> GetAvailableQueueFamilies()
			{
				std::vector<QueueFamilyProperties> queryResult; uint32 count;

				QueryQueueFamilyProperties(&count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(&count, queryResult.data());

				return queryResult;
			}

			const Features& GetFeatures() const
			{
				return features;
			}

			FormatProperties GetFormatProperties(EFormat _format) const
			{
				FormatProperties formatProperties;

				Parent::GetFormatProperties(handle, _format, formatProperties);

				return formatProperties;
			}

			Handle GetHandle() const
			{
				return handle;
			}

			ESampleCount GetMaxSampleCount_ColorAndDepth() const
			{
				SampleCountFlags counts
				(
					properties.LimitsSpec.FramebufferColorSampleCounts,
					properties.LimitsSpec.FramebufferDepthSampleCounts
				);

				if (counts.Has(ESampleCount::_64)) return ESampleCount::_64;
				if (counts.Has(ESampleCount::_32)) return ESampleCount::_32;
				if (counts.Has(ESampleCount::_16)) return ESampleCount::_16;
				if (counts.Has(ESampleCount::_8 )) return ESampleCount::_8 ;
				if (counts.Has(ESampleCount::_4 )) return ESampleCount::_4 ;
				if (counts.Has(ESampleCount::_2 )) return ESampleCount::_2 ;

				return ESampleCount::_1;
			}

			const MemoryProperties& GetMemoryProperties() const
			{
				return memoryProperties;
			}

			const Properties& GetProperties() const
			{
				return properties;
			}

			const Properties2& GetProperties2() const
			{
				return properties2;
			}

			EResult QueryExtensionProperties(RoCStr _layerName, uint32* _numExtensions, ExtensionProperties* _extensionPropertiesContainer)
			{
				return Parent::QueryExtensionProperties(handle, _layerName, _numExtensions, _extensionPropertiesContainer);
			}

			void QueryQueueFamilyProperties(uint32* _numQueueFamilies, QueueFamilyProperties* _queueFamilies)
			{
				return Parent::QueryQueueFamilyProperties(handle, _numQueueFamilies, _queueFamilies);
			}

			void QueryQueueFamilyProperties2(uint32* _numProperties, QueueFamilyProperties2* _properties) const
			{
				return Parent::QueryQueueFamilyProperties2(handle, _numProperties, _properties);
			}

			EResult QueryPerfomranceQueryCounters
			(
				uint32                           _queueFamilyIndex   ,
				uint32*                          _numCounters        ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			) const
			{
				return Parent::QueryPerfomranceQueryCounters(handle, _queueFamilyIndex, _numCounters, _counters, _counterDescriptions);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle&() const
			{
				return handle;
			}

		protected:

			Handle handle;

			EDeviceType type    ;
			EDriverID   driverID;
			EVendorID   vendorID;

			Features features; 

			MemoryProperties memoryProperties; 

			Properties  properties ;
			Properties2 properties2;
		};
	}
}
