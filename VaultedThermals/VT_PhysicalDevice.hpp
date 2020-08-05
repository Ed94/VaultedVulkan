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
#include "VT_Memory_Corridors.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_1
	{
		/**
		@brief Represents a physical device.
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
		 */
		struct PhysicalDevice
		{
			using Memory = Vault_0::Memory;

			static constexpr DeviceSize MaxNameSize        = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;
			static constexpr DeviceSize MaxDeviceGroupSize = VK_MAX_DEVICE_GROUP_SIZE;

			using Handle       = VkPhysicalDevice          ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevice">Specification</a> 
			

			using NameStr = char[MaxNameSize];

			static constexpr DeviceSize MaxDriverNameSize = VK_MAX_DRIVER_NAME_SIZE;
			static constexpr DeviceSize MaxDriverInfoSize = VK_MAX_DRIVER_INFO_SIZE;

			using DriverNameStr = char[MaxDriverNameSize];
			using DriverInfoStr = char[MaxDriverInfoSize];

			static constexpr Handle NullHandle = Handle(EHandle::Null);

		    using EDeviceType = EPhysicalDeviceType;	

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a> 
			*/
			struct ConformanceVersion : Vault_0::VKStruct_Base<VkConformanceVersion>
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
			struct Features : Vault_0::VKStruct_Base<VkPhysicalDeviceFeatures>
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
			struct Group : Vault_0::VKStruct_Base<VkPhysicalDeviceGroupProperties, EStructureType::PhysicalDevice_GroupProperties>
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
			struct Limits : Vault_0::VKStruct_Base<VkPhysicalDeviceLimits>
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
			struct MemoryProperties : Vault_0::VKStruct_Base<VkPhysicalDeviceMemoryProperties>
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
			struct PerformanceCounter : Vault_0::VKStruct_Base<VkPerformanceCounterKHR, EStructureType::PerformacneCounter_KHR>
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
				struct Description : Vault_0::VKStruct_Base<VkPerformanceCounterDescriptionKHR>
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
			struct SparseMemoryProperties : Vault_0::VKStruct_Base<VkPhysicalDeviceSparseProperties>
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
			struct Properties : Vault_0::VKStruct_Base<VkPhysicalDeviceProperties>
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
				struct DeviceID : Vault_0::VKStruct_Base<VkPhysicalDeviceIDProperties >
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
				struct PCIBusInfo : Vault_0::VKStruct_Base
					<VkPhysicalDevicePCIBusInfoPropertiesEXT, EStructureType::PhysicalDevice_PCI_BUS_Info_Properties_EXT>
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
				struct Vulkan11 : Vault_0::VKStruct_Base<VkPhysicalDeviceVulkan11Properties, EStructureType::PhysicalDevice_Vulkan_1_1_Properties>
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
				struct Vulkan12 : Vault_0::VKStruct_Base<VkPhysicalDeviceVulkan12Properties, EStructureType::PhysicalDevice_Vulkan_1_2_Properties>
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
			struct Properties2 : Vault_0::VKStruct_Base<VkPhysicalDeviceProperties2, EStructureType::PhysicalDevice_Properties_2>
			{
				EType      SType     ;
				void*      Next      ;
				Properties Properties;
			};

			/**
			@brief A set of queues that have common properties and support the same functionality.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties">Specification</a> 
			*/
			struct QueueFamilyProperties : Vault_0::VKStruct_Base<VkQueueFamilyProperties>
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
			struct QueueFamilyProperties2 : Vault_0::VKStruct_Base<VkQueueFamilyProperties2, EStructureType::QueueFamily_Properties_2>
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
				struct Checkpoint : Vault_0::VKStruct_Base<VkQueueFamilyCheckpointPropertiesNV, EStructureType::QueueFamilyCheckpoint_Properties_NV>
				{
					using Pipeline_StageFlags = Bitmask<EPipelineStageFlag, VkPipelineStageFlags>;   // Not defined yet...

					EType               SType                       ;
					void*               Next                        ;
					Pipeline_StageFlags CheckpointExecutionStageMask;
				};
			};

			/**
			@brief Device extensions add new device-level functionality to the API, outside of the core specification.

			@details
			Query the extensions available to a given physical device.

			When pLayerName parameter is NULL, only extensions provided by the Vulkan implementation or by implicitly enabled layers are returned. 
			When pLayerName is the name of a layer, the device extensions provided by that layer are returned.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_device_extensions">Specification</a> 
			*/
			static EResult EnumerateExtensionProperties(Handle _deviceHandle, RoCStr _layerName, uint32* _numOfExtensions, ExtensionProperties* _extensionPropertiesContainer)
			{
				return EResult(vkEnumerateDeviceExtensionProperties(_deviceHandle, _layerName, _numOfExtensions, _extensionPropertiesContainer->operator VkExtensionProperties*()));
			}

			/**
			@brief Query supported features. Reports capabilities of a physical device.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFeatures">Specification</a> 
			*/
			static void GetFeatures(Handle _deviceHandle, Features& _featuresContainer)
			{
				vkGetPhysicalDeviceFeatures(_deviceHandle, _featuresContainer.operator VkPhysicalDeviceFeatures*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFormatProperties">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _format
			 * \param _properties
			 */
			static void GetFormatProperties(Handle _physicalDevice, EFormat _format, FormatProperties& _properties)
			{
				vkGetPhysicalDeviceFormatProperties(_physicalDevice, VkFormat(_format), _properties);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceMemoryProperties">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _properties
			 */
			static void GetMemoryProperties(Handle _physicalDevice, MemoryProperties& _properties)
			{
				vkGetPhysicalDeviceMemoryProperties(_physicalDevice, _properties);
			}

			/**
			@brief Query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties">Specification</a> 
			*/
			static void GetProperties(Handle _deviceHandle, Properties& _propertiesContainer)
			{
				vkGetPhysicalDeviceProperties(_deviceHandle, _propertiesContainer.operator VkPhysicalDeviceProperties*());
			}

			/**
			 * @brief Query general properties of physical devices once enumerated (Second Ver).
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties2">Specification</a> 
			 */
			static void GetProperties2
			(
				Handle       _physicalDevice,
				Properties2& _properties
			)
			{
				vkGetPhysicalDeviceProperties2(_physicalDevice, _properties);
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
			static void QueryQueueFamilyProperties(Handle _deviceHandle, uint32* _numQueueFamilies, QueueFamilyProperties* _queuefamilyContainer)
			{
				vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, _numQueueFamilies, _queuefamilyContainer->operator VkQueueFamilyProperties*());
			}	

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties2">Specification</a> 
			*/
			static void QueryQueueFamilyProperties2
			(
				Handle                  _physicalDevice,
				uint32*                 _propertyCount ,
				QueueFamilyProperties2* _properties
			)
			{
				vkGetPhysicalDeviceQueueFamilyProperties2(_physicalDevice, _propertyCount, _properties->operator VkQueueFamilyProperties2*());
			}

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">Specification</a> 
			*/
			static EResult QueryPerfomranceQueryCounters
			(
				Handle                           _physicalDevice     ,
				uint32                           _queueFamilyIndex   ,
				uint32*                          _counterCount       ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			)
			{
				vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
				(
					_physicalDevice,
					_queueFamilyIndex,
					_counterCount,
					_counters->operator VkPerformanceCounterKHR*(),
					_counterDescriptions->operator VkPerformanceCounterDescriptionKHR*()
				);
			}
		};
	}

	namespace Vault_2
	{
		using Vault_1::ExtensionProperties;

		/**
		@brief Represents a physical device.
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
		*/
		struct PhysicalDevice : Vault_1::PhysicalDevice
		{
			using Parent = Vault_1::PhysicalDevice;

			using List      = std::vector<PhysicalDevice::Handle>;
			using GroupList = std::vector<PhysicalDevice::Group>;

			struct Group : Parent::Group
			{
				Group()
				{
					SType               = STypeEnum;
					Next                = nullptr  ;
				}
			};

			struct PerformanceCounter : Parent::PerformanceCounter
			{
				PerformanceCounter()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct Description : Parent::PerformanceCounter::Description
				{
					Description()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct Properties : Parent::Properties
				{
					struct DeviceID : Parent::Properties::DeviceID
					{
						DeviceID()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					struct PCIBusInfo : Parent::Properties::PCIBusInfo
					{
						PCIBusInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					struct Vulkan11 : Parent::Properties::Vulkan11
					{
						Vulkan11()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					struct Vulkan12 : Parent::Properties::Vulkan12
					{
						Vulkan12()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};
				};

				struct Properties2 : Parent::Properties2
				{
					Properties2()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct QueueFamilyProperties2 : Parent::QueueFamilyProperties2
				{
					QueueFamilyProperties2()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}

					struct Checkpoint : Parent::QueueFamilyProperties2::Checkpoint
					{
						Checkpoint()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};
				};
			};

			struct QueueFamilyProperties : Parent::QueueFamilyProperties
			{
				using List = std::vector<QueueFamilyProperties>;
			};

			static uint32 FindMemoryType(PhysicalDevice::Handle _device, uint32 _typeFilter, Memory::PropertyFlags _properties)
			{
				MemoryProperties memProperties;

				GetMemoryProperties(_device, memProperties);

				for (DeviceSize index = 0; index < memProperties.TypeCount; index++)
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

			#ifdef VT_Option__USE_STL_EXCEPTIONS
				throw std::runtime_error("Failed to find suitable memory type!");
			#endif
			}

			static ESampleCount GetMaxSampleCount_ColorAndDepth(PhysicalDevice::Handle _physicalDevice)
			{
				PhysicalDevice::Properties properties;

				PhysicalDevice::GetProperties(_physicalDevice, properties);

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

			/**
			* @brief Provides the queue families for the respective device.
			* 
			* \param _device
			* \return 
			*/
			static QueueFamilyProperties::List GetAvailableQueueFamilies(Handle _device)
			{
				QueueFamilyProperties::List queryResult; uint32 count;

				QueryQueueFamilyProperties(_device, &count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(_device, &count, queryResult.data());

				return queryResult;
			}

			using ExtensionList = std::vector<ExtensionProperties>;

			static EResult GetAvailableExtensions(Handle _device, RoCStr _layerName, ExtensionList& _extensionListing)
			{
				uint32 count;

				EResult&& returnCode = EnumerateExtensionProperties(_device, _layerName, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_extensionListing.resize(count);

				returnCode = EnumerateExtensionProperties(_device, _layerName, &count, _extensionListing.data());

				return returnCode;
			}
		};
	}

	namespace Vault_5
	{
		class PhysicalDevice : public Vault_2::PhysicalDevice
		{
		public:

			using Parent = Vault_2::PhysicalDevice;
			
			using List = std::vector<PhysicalDevice>;

			PhysicalDevice()
			{
				handle = NullHandle;

				properties2 = Vault_2::PhysicalDevice::Properties2();
			}

			void AssignHandle(Handle _handle) 
			{ 
				handle = _handle; 

				Parent::GetFeatures        (handle, features        );
				Parent::GetMemoryProperties(handle, memoryProperties);
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties2     (handle, properties2     );

				queueFamilies = Parent::GetAvailableQueueFamilies(handle);
			}

			uint32 FindMemoryType(uint32 _typeFilter, Memory::PropertyFlags _properties) const
			{
				for (DeviceSize index = 0; index < memoryProperties.TypeCount; index++)
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

			#ifdef VT_Option__USE_STL_EXCEPTIONS
				throw std::runtime_error("Failed to find suitable memory type!");
			#endif
			}

			EResult GetAvailableExtensions(RoCStr _layerName, ExtensionList& _extensionListing) const
			{
				return EResult(Parent::GetAvailableExtensions(handle, _layerName, _extensionListing));
			}

			const Features& GetFeatures() const
			{
				return features;
			}

			FormatProperties GetFormatProperties(EFormat _format) const
			{
				FormatProperties properties;

				Parent::GetFormatProperties(handle, _format, properties);

				return properties;
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

			const QueueFamilyProperties::List& GetAvailableQueueFamilies() const
			{
				return queueFamilies;
			}

		protected:

			Handle handle;

			EDeviceType type    ;
			EDriverID   driverID;
			EVendorID   vendorID;

			Features features; 
			Limits   limits  ; 

			MemoryProperties memoryProperties; 

			

			Vault_2::PhysicalDevice::Properties  properties ;
			Properties2 properties2;

			QueueFamilyProperties::List queueFamilies;
		};
	}
}
