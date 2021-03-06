/*!
@file VV_PhysicalDevice.hpp

@brief Vaulted Vulkan: Physical Device

@details
A physical device usually represents a single complete implementation of Vulkan 
(excluding instance-level functionality) available to the host, of which there are a finite number. 


<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
*/



#pragma once



// VT
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"
#include "VV_Backend.hpp"
#include "VV_Types.hpp"
#include "VV_Constants.hpp"
#include "VV_Memory_Backend.hpp"



#ifndef VT_Option__Use_Long_Namespace
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
		@brief Represents a physical device.
		@details
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a>
		@ingroup APISpec_Devices_and_Queues
		 */
		struct PhysicalDevice
		{
			using Memory = V0::Memory;

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevice">Specification</a>
			@ingroup APISpec_Devices_and_Queues
			*/
			using Handle = VkPhysicalDevice;

			static constexpr DeviceSize MaxNameSize        = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;   ///< @brief Maximum size of a name string.
			static constexpr DeviceSize MaxDeviceGroupSize = VK_MAX_DEVICE_GROUP_SIZE        ;   ///< @brief Maximum size of a device group.
			static constexpr DeviceSize MaxDriverNameSize  = VK_MAX_DRIVER_NAME_SIZE         ;   ///< @brief maximum size of a driver name string.
			static constexpr DeviceSize MaxDriverInfoSize  = VK_MAX_DRIVER_INFO_SIZE         ;   ///< @brief Maximum size of a driver info string.

			using NameStr = char[MaxNameSize];   ///< @brief Used in various structures to define a name.

			using DriverNameStr = char[MaxDriverNameSize];   ///< @brief Driver name string.
			using DriverInfoStr = char[MaxDriverInfoSize];   ///< @brief Driver info string.

			using EDeviceType = EPhysicalDeviceType;

			/**
			* @brief Conformance test suite version an implementation is compliant with is described with this.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct ConformanceVersion : V0::VKStruct_Base<VkConformanceVersion>
			{
				u8 Major   ;
				u8 Minor   ;
				u8 Subminor;
				u8 Patch   ;

				bool operator==(const ConformanceVersion _other) 
				{ return Major == _other.Major && Minor == _other.Minor && Subminor == _other.Subminor && Patch == _other.Patch ? true : false; }
				bool operator!=(const ConformanceVersion _other) 
				{ return Major != _other.Major && Minor != _other.Minor && Subminor != _other.Subminor && Patch != _other.Patch ? true : false; }
			};

			/**
			@brief Structure describing the fine-grained features that can be supported by an implementation.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceFeatures">Specification</a>

			@ingroup APISpec_Features
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
			* @brief
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceGroupProperties ">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct Group : V0::VKStruct_Base<VkPhysicalDeviceGroupProperties, EStructureType::PhysicalDevice_GroupProperties>
			{
				using DeviceListing = Handle[MaxDeviceGroupSize];

				EType         SType               = STypeEnum;
				void*         Next                = nullptr  ;
				ui32          PhysicalDeviceCount;
				DeviceListing PhysicalDevices    ;
				Bool          SubsetAllocation   ;
			};

			/**
			@brief Structure reporting implementation-dependent physical device limits.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceLimits">Specification</a> 

			@ingroup APISpec_Limits
			*/
			struct Limits : V0::VKStruct_Base<VkPhysicalDeviceLimits>
			{
				ui32             MaxImageDimension1D                            ;
				ui32             MaxImageDimension2D                            ;
				ui32             MaxImageDimension3D                            ;
				ui32             MaxImageDimensionCube                          ;
				ui32             MaxImageArrayLayers                            ;
				ui32             MaxTexelBufferElements                         ;
				ui32             MaxUniformBufferRange                          ;
				ui32             MaxStorageBufferRange                          ;
				ui32             MaxPushConstantsSize                           ;
				ui32             MaxMemoryAllocationCount                       ;
				ui32             MaxSamplerAllocationCount                      ;
				DeviceSize       BufferImageGranularity                         ;
				DeviceSize       SparseAddressSpaceSize                         ;
				ui32             MaxBoundDescriptorSets                         ;
				ui32             MaxPerStageDescriptorSamplers                  ;
				ui32             MaxPerStageDescriptorUniformBuffers            ;
				ui32             MaxPerStageDescriptorStorageBuffers            ;
				ui32             MaxPerStageDescriptorSampledImages             ;
				ui32             MaxPerStageDescriptorStorageImages             ;
				ui32             MaxPerStageDescriptorInputAttachments          ;
				ui32             MaxPerStageResources                           ;
				ui32             MaxDescriptorSetSamplers                       ;
				ui32             MaxDescriptorSetUniformBuffers                 ;
				ui32             MaxDescriptorSetUniformBuffersDynamic          ;
				ui32             MaxDescriptorSetStorageBuffers                 ;
				ui32             MaxDescriptorSetStorageBuffersDynamic          ;
				ui32             MaxDescriptorSetSampledImages                  ;
				ui32             MaxDescriptorSetStorageImages                  ;
				ui32             MaxDescriptorSetInputAttachments               ;
				ui32             MaxVertexInputAttributes                       ;
				ui32             MaxVertexInputBindings                         ;
				ui32             MaxVertexInputAttributeOffset                  ;
				ui32             MaxVertexInputBindingStride                    ;
				ui32             MaxVertexOutputComponents                      ;
				ui32             MaxTessellationGenerationLevel                 ;
				ui32             MaxTessellationPatchSize                       ;
				ui32             MaxTessellationControlPerVertexInputComponents ;
				ui32             MaxTessellationControlPerVertexOutputComponents;
				ui32             MaxTessellationControlPerPatchOutputComponents ;
				ui32             MaxTessellationControlTotalOutputComponents    ;
				ui32             MaxTessellationEvaluationInputComponents       ;
				ui32             MaxTessellationEvaluationOutputComponents      ;
				ui32             MaxGeometryShaderInvocations                   ;
				ui32             MaxGeometryInputComponents                     ;
				ui32             MaxGeometryOutputComponents                    ;
				ui32             MaxGeometryOutputVertices                      ;
				ui32             MaxGeometryTotalOutputComponents               ;
				ui32             MaxFragmentInputComponents                     ;
				ui32             MaxFragmentOutputAttachments                   ;
				ui32             MaxFragmentDualSrcAttachments                  ;
				ui32             MaxFragmentCombinedOutputResources             ;
				ui32             MaxComputeSharedMemorySize                     ;
				ui32             MaxComputeWorkGroupCount[3]                    ;
				ui32             MaxComputeWorkGroupInvocations                 ;
				ui32             MaxComputeWorkGroupSize[3]                     ;
				ui32             SubPixelPrecisionBits                          ;
				ui32             SubTexelPrecisionBits                          ;
				ui32             MipmapPrecisionBits                            ;
				ui32             MaxDrawIndexedIndexValue                       ;
				ui32             MaxDrawIndirectCount                           ;
				f32              MaxSamplerLodBias                              ;
				f32              MaxSamplerAnisotropy                           ;
				ui32             MaxViewports                                   ;
				ui32             MaxViewportDimensions[2]                       ;
				f32              ViewportBoundsRange[2]                         ;
				ui32             ViewportSubPixelBits                           ;
				size_t           MinMemoryMapAlignment                          ;
				DeviceSize       MinTexelBufferOffsetAlignment                  ;
				DeviceSize       MinUniformBufferOffsetAlignment                ;
				DeviceSize       MinStorageBufferOffsetAlignment                ;
				si32             MinTexelOffset                                 ;
				ui32             MaxTexelOffset                                 ;
				si32             MinTexelGatherOffset                           ;
				ui32             MaxTexelGatherOffset                           ;
				f32              MinInterpolationOffset                         ;
				f32              MaxInterpolationOffset                         ;
				ui32             SubPixelInterpolationOffsetBits                ;
				ui32             MaxFramebufferWidth                            ;
				ui32             MaxFramebufferHeight                           ;
				ui32             MaxFramebufferLayers                           ;
				SampleCountFlags FramebufferColorSampleCounts                   ;
				SampleCountFlags FramebufferDepthSampleCounts                   ;
				SampleCountFlags FramebufferStencilSampleCounts                 ;
				SampleCountFlags FramebufferNoAttachmentsSampleCounts           ;
				ui32             MaxColorAttachments                            ;
				SampleCountFlags SampledImageColorSampleCounts                  ;
				SampleCountFlags SampledImageIntegerSampleCounts                ;
				SampleCountFlags SampledImageDepthSampleCounts                  ;
				SampleCountFlags SampledImageStencilSampleCounts                ;
				SampleCountFlags StorageImageSampleCounts                       ;
				ui32             MaxSampleMaskWords                             ;
				Bool             TimestampComputeAndGraphics                    ;
				f32              TimestampPeriod                                ;
				ui32             MaxClipDistances                               ;
				ui32             MaxCullDistances                               ;
				ui32             MaxCombinedClipAndCullDistances                ;
				ui32             DiscreteQueuePriorities                        ;
				f32              PointSizeRange[2]                              ;
				f32              LineWidthRange[2]                              ;
				f32              PointSizeGranularity                           ;
				f32              LineWidthGranularity                           ;
				Bool             StrictLines                                    ;
				Bool             StandardSampleLocations                        ;
				DeviceSize       OptimalBufferCopyOffsetAlignment               ;
				DeviceSize       OptimalBufferCopyRowPitchAlignment             ;
				DeviceSize       NonCoherentAtomSize                            ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceMemoryProperties">Specification</
			 * 
			 * @ingroup APISpec_Devices_and_Queues
			 */
			struct MemoryProperties : V0::VKStruct_Base<VkPhysicalDeviceMemoryProperties>
			{
				ui32         TypeCount            ;
				Memory::Type Types[MaxMemoryTypes];
				ui32         HeapCount            ;
				Memory::Heap Heaps[MaxMemoryHeaps];
			};

			/**
			* @brief
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterKHR">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct PerformanceCounter : V0::VKStruct_Base<VkPerformanceCounterKHR, EStructureType::PerformacneCounter_KHR>
			{
				      EType                      SType       = STypeEnum;
				const void*                      Next        = nullptr  ;
				      EPerformanceCounterUnit    Unit       ;
				      EPerformanceCounterScope   Scope      ;
				      EPerformanceCounterStorage Storage    ;
				      UUID                       CounterUUID;


				using DescriptionFlags = Bitfield<EPerformanceCounterDescriptionFlag, VkPerformanceCounterDescriptionFlagsKHR>;

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterDescriptionKHR">Specification</a> 
				* 
				* @ingroup APISpec_Devices_and_Queues
				*/
				struct Description : V0::VKStruct_Base<VkPerformanceCounterDescriptionKHR>
				{
					      EType            SType       = STypeEnum;
					const void*            Next        = nullptr  ;
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

			@ingroup APISpec_Sparse_Resources
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

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties">Specification</a> 

			@ingroup APISpec_Devices_and_Queues
			*/
			struct Properties : V0::VKStruct_Base<VkPhysicalDeviceProperties>
			{
				ui32                   API_Version      ;
				ui32                   DriverVersion    ;
				ui32                   VenderID         ;
				ui32                   ID               ;
				EDeviceType            Type             ;
				NameStr                Name             ;
				UUID                   PipelineCacheUUID;
				Limits                 LimitsSpec       ;
				SparseMemoryProperties SpareProperties  ;

				/**
				* @brief To query the UUID and LUID of a device, add a VkPhysicalDeviceIDProperties structure to the pNext chain of the VkPhysicalDeviceProperties2 structure.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties">Specification</a>
				* 
				* @ingroup APISpec_Devices_and_Queues
				*/
				struct DeviceID : V0::VKStruct_Base<VkPhysicalDeviceIDProperties >
				{
					EType  SType           = STypeEnum;
					void*  Next            = nullptr  ;
					UUID   DeviceUUID     ;
					UUID   DriverUUID     ;
					UUID   DeviceLUID     ;
					ui32   DeviceNodeMask ;
					Bool   DeviceLUIDValid;
				};	

				/**
				* @brief To query the PCI bus information of a physical device, add a VkPhysicalDevicePCIBusInfoPropertiesEXT 
				* structure to the pNext chain of the VkPhysicalDeviceProperties2 structure.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevicePCIBusInfoPropertiesEXT">Specification</a> 
				* 
				* @ingroup APISpec_Devices_and_Queues
				*/
				struct PCIBusInfo : V0::VKStruct_Base<VkPhysicalDevicePCIBusInfoPropertiesEXT, EStructureType::PhysicalDevice_PCI_BUS_Info_Properties_EXT>
				{
					EType  SType    = STypeEnum;
					void*  Next     = nullptr  ;
					ui32   Domain  ;
					ui32   Bus     ;
					ui32   Device  ;
					ui32   Function;
				};

				/**
				* @brief To query the properties of the driver corresponding to Vulkan 1.1 functionality, 
				* add VkPhysicalDeviceVulkan11Properties to the pNext chain of the VkPhysicalDeviceProperties2 structure.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceVulkan11Properties">Specification</a> 
				* 
				* @ingroup APISpec_Devices_and_Queues
				*/
				struct Vulkan11 : V0::VKStruct_Base<VkPhysicalDeviceVulkan11Properties, EStructureType::PhysicalDevice_Vulkan_1_1_Properties>
				{
					using ShaderStageFlags = Bitfield<EShaderStageFlag, VkShaderStageFlags>;

					EType                  SType                             = STypeEnum;
					void*                  Next                              = nullptr  ;
					UUID                   DeviceUUID                       ;
					UUID                   DriverUUID                       ;
					UUID                   DeviceLUID                       ;
					ui32                   DeviceNodeMask                   ;
					Bool                   DeviceLUIDValid                  ;
					ui32                   SubgroupSize                     ;
					ShaderStageFlags       SubgroupSupportedStages          ;
					ESubgroupFeaturesFlag  SubgroupSupportedOperations      ;
					Bool                   SubgroupQuadOperationsInAllStages;
					EPointClippingBehavior PointClippingBehavior            ;
					ui32                   MaxMultiviewViewCount            ;
					ui32                   MaxMultiviewInstanceIndex        ;
					Bool                   ProtectedNoFault                 ;
					ui32                   MaxPerSetDescriptors             ;
					DeviceSize             MaxMemoryAllocationSize          ;
				};

				/**
				* @brief To query the properties of the driver corresponding to Vulkan 1.2 functionality, 
				* add VkPhysicalDeviceVulkan12Properties to the pNext chain of the VkPhysicalDeviceProperties2 structure.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceVulkan12Properties">Specification</a> 
				*  
				* @ingroup APISpec_Devices_and_Queues
				*/
				struct Vulkan12 : V0::VKStruct_Base<VkPhysicalDeviceVulkan12Properties, EStructureType::PhysicalDevice_Vulkan_1_2_Properties>
				{
					EType                           SType                                               = STypeEnum;
					void*                           Next                                                = nullptr  ;
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
					ui32                            MaxUpdateAfterBindDescriptorsInAllPools             ;
					Bool                            ShaderUniformBufferArrayNonUniformIndexingNative    ;
					Bool                            ShaderSampledImageArrayNonUniformIndexingNative     ;
					Bool                            ShaderStorageBufferArrayNonUniformIndexingNative    ;
					Bool                            ShaderStorageImageArrayNonUniformIndexingNative     ;
					Bool                            ShaderInputAttachmentArrayNonUniformIndexingNative  ;
					Bool                            RobustBufferAccessUpdateAfterBind                   ;
					Bool                            QuadDivergentImplicitLod                            ;
					ui32                            MaxPerStageDescriptorUpdateAfterBindSamplers        ;
					ui32                            MaxPerStageDescriptorUpdateAfterBindUniformBuffers  ;
					ui32                            MaxPerStageDescriptorUpdateAfterBindStorageBuffers  ;
					ui32                            MaxPerStageDescriptorUpdateAfterBindSampledImages   ;
					ui32                            MaxPerStageDescriptorUpdateAfterBindStorageImages   ;
					ui32                            MaxPerStageDescriptorUpdateAfterBindInputAttachments;
					ui32                            MaxPerStageUpdateAfterBindResources                 ;
					ui32                            MaxDescriptorSetUpdateAfterBindSamplers             ;
					ui32                            MaxDescriptorSetUpdateAfterBindUniformBuffers       ;
					ui32                            MaxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
					ui32                            MaxDescriptorSetUpdateAfterBindStorageBuffers       ;
					ui32                            MaxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
					ui32                            MaxDescriptorSetUpdateAfterBindSampledImages        ;
					ui32                            MaxDescriptorSetUpdateAfterBindStorageImages        ;
					ui32                            MaxDescriptorSetUpdateAfterBindInputAttachments     ;
					ResolveModeFlags                SupportedDepthResolveModes                          ;
					ResolveModeFlags                SupportedStencilResolveModes                        ;
					Bool                            IndependentResolveNone                              ;
					Bool                            IndependentResolve                                  ;
					Bool                            FilterMinmaxSingleComponentFormats                  ;
					Bool                            FilterMinmaxImageComponentMapping                   ;
					u64                            MaxTimelineSemaphoreValueDifference                 ;
					SampleCountFlags                FramebufferIntegerColorSampleCounts                 ;
				};
			};

			/**
			 * @brief Each structure in Properties and its pNext chain contain members corresponding to properties or implementation-dependent limits. 
			 *  
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties2">Specification</a>
			 * 
			 * @ingroup APISpec_Devices_and_Queues
			 */
			struct Properties2 : V0::VKStruct_Base<VkPhysicalDeviceProperties2, EStructureType::PhysicalDevice_Properties_2>
			{
				EType      SType      = STypeEnum;
				void*      Next       = nullptr  ;
				Properties Properties;
			};

			/**
			@brief A set of queues that have common properties and support the same functionality.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties">Specification</a> 

			@ingroup APISpec_Devices_and_Queues
			*/
			struct QueueFamilyProperties : V0::VKStruct_Base<VkQueueFamilyProperties>
			{
				/**
				* @brief Bitfield specifying capabilities of queues in a queue family.     
				* 
				* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFlags">Specification</a> 
				*/
				using Flags = Bitfield<EQueueFlag , VkQueueFlags>;

				Flags    QueueFlags                 ;
				ui32     QueueCount                 ;
				ui32     TimestampValidBits         ;
				Extent3D MinImageTransferGranularity;
			};

			/**
			* @brief Return extended information in a pNext chain of output structures.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties2">Specification</a>
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			struct QueueFamilyProperties2 : V0::VKStruct_Base<VkQueueFamilyProperties2, EStructureType::QueueFamily_Properties_2>
			{
				EType                 SType      = STypeEnum;
				void*                 Next       = nullptr  ;
				QueueFamilyProperties Properties;

				/**
				* @brief Additional queue family information can be queried by setting QueueFamilyProperties2::Next to 
				* point to a Checkpoint structure.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyCheckpointPropertiesNV">Specification</a>
				* 
				* @ingroup APISpec_Devices_and_Queues
				*/
				struct Checkpoint : V0::VKStruct_Base<VkQueueFamilyCheckpointPropertiesNV, EStructureType::QueueFamilyCheckpoint_Properties_NV>
				{
					using Pipeline_StageFlags = Bitfield<EPipelineStageFlag, VkPipelineStageFlags>;   ///< Not defined yet. (See VT_Pipelines.hpp)

					EType               SType                        = STypeEnum;
					void*               Next                         = nullptr  ;
					Pipeline_StageFlags CheckpointExecutionStageMask;
				};
			};

			/**
			@brief Query supported features. Reports capabilities of a physical device.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFeatures">Specification</a>

			@ingroup APISpec_Features
			*/
			static void GetFeatures(Handle _handle, Features& _features)
			{
				vkGetPhysicalDeviceFeatures(_handle, _features);
			}

			/**
			 * @brief Query supported format features which are properties of the physical device.
			 *
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFormatProperties">Specification</a>
			 * 
			 * @ingroup APISpec_Formats
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
			 * @brief Query memory properties.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceMemoryProperties">Specification</a>
			 * 
			 * @ingroup APISpec_Memory_Allocation
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

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties">Specification</a>

			@ingroup APISpec_Devices_and_Queues
			*/
			static void GetProperties(Handle _handle, Properties& _properties)
			{
				vkGetPhysicalDeviceProperties(_handle, _properties);
			}

			/**
			 * @brief Query general properties of physical devices once enumerated (Second Ver).
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties2">Specification</a> 
			 * 
			 * @ingroup APISpec_Devices_and_Queues
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

			@ingroup APISpec_Extending_Vulkan
			*/
			static EResult QueryExtensionProperties(Handle _handle, RoCStr _layerName, ui32* _numExtensions, ExtensionProperties* _extensionPropertiesContainer)
			{
				return EResult(vkEnumerateDeviceExtensionProperties(_handle, _layerName, _numExtensions, *_extensionPropertiesContainer));
			}

			/**
			@brief Query properties of queues available on a physical device. Reports properties of the queues of the specified physical device.

			@details
			If pQueueFamilyProperties is NULL, then the number of queue families available is returned in pQueueFamilyPropertyCount. 
			Implementations must support at least one queue family. Otherwise, pQueueFamilyPropertyCount must point to a variable set 
			by the user to the number of elements in the pQueueFamilyProperties array, and on return the variable is overwritten 
			with the number of structures actually written to pQueueFamilyProperties.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties">Specification</a> 

			@ingroup APISpec_Devices_and_Queues
			*/
			static void QueryQueueFamilyProperties(Handle _handle, ui32* _numQueueFamilies, QueueFamilyProperties* _queueFamilies)
			{
				vkGetPhysicalDeviceQueueFamilyProperties(_handle, _numQueueFamilies, *_queueFamilies);
			}	

			/**
			* @brief Query properties of queues available on a physical device.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties2">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			static void QueryQueueFamilyProperties2
			(
				Handle                  _handle       ,
				ui32*                   _numProperties,
				QueueFamilyProperties2* _properties
			)
			{
				vkGetPhysicalDeviceQueueFamilyProperties2(_handle, _numProperties, *_properties);
			}

			/**
			* @brief Enumerate the performance query counters available on a queue family of a physical device.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">Specification</a> 
			* 
			* @ingroup APISpec_Devices_and_Queues
			*/
			static EResult QueryPerfomranceQueryCounters
			(
				Handle                           _handle             ,
				ui32                             _queueFamilyIndex   ,
				ui32*                            _numCounters        ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			)
			{
				return EResult(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
				(
					_handle              ,
					_queueFamilyIndex    ,
					_numCounters         ,
					*_counters           ,
					*_counterDescriptions
				));
			}
		};

		using QueueFamilyProperties = PhysicalDevice::QueueFamilyProperties;

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		using V1::ExtensionProperties;

		/**
		@brief Represents a physical device.

		@ingroup
		*/
		struct PhysicalDevice : V1::PhysicalDevice
		{
			using Parent = V1::PhysicalDevice;

			/**
			* @brief Checks to see if the specified extensions are supported by the physical device.
			*/
			static bool CheckExtensionSupport(Handle _handle, RoCStr _extensionSpecified)
			{
				DynamicArray<ExtensionProperties> availableExtensions;

				GetAvailableLayerExtensions(_handle, nullptr, availableExtensions);

				bool isSupported = false;

				for (const auto& extension : availableExtensions)
				{
					if (strcmp(extension.Name, _extensionSpecified) == 0)
					{
						isSupported = true;
					}
				}

				return isSupported;
			}

			/**
			 * @brief Checks to see if the specified extensions are supported by the physical device.
			 */
			static bool CheckExtensionSupport(Handle _handle, DynamicArray<RoCStr> _extensionsSpecified)
			{
				DynamicArray<ExtensionProperties> availableExtensions;

				GetAvailableLayerExtensions(_handle, nullptr, availableExtensions);

				using ExtensionNameSet = std::set<std::string>;

				ExtensionNameSet requiredExtensions(_extensionsSpecified.begin(), _extensionsSpecified.end());

				for (const auto& extension : availableExtensions)
				{
					requiredExtensions.erase(extension.Name);
				}

				bool isSupported = requiredExtensions.empty();

				return isSupported;
			}

			/**
			@brief Checks to see if the formats in _canidates are available for the specified physical device, if the format is found, 
			it will be returned with the format container reference.	
			*/
			static EResult FindSupportedFormat(Handle _handle, const DynamicArray<EFormat>& _canidates, EImageTiling _tiling, FormatFeatureFlags _features, EFormat& _format)
			{
				for (EFormat possibleFormat : _canidates)
				{
					FormatProperties formatProperties;

					Parent::GetFormatProperties(_handle, possibleFormat, formatProperties);

					switch (_tiling)
					{
						case EImageTiling::Linear:
						{
							if (formatProperties.LinearTilingFeatures.CheckForEither(_features))
							{
								_format = possibleFormat;

								return EResult::Success;
							}

							break;
						}
						case EImageTiling::Optimal:
						{
							if (formatProperties.OptimalTilingFeatures.CheckForEither(_features))
							{
								_format = possibleFormat;

								return EResult::Success;
							}

							break;
						}
						case EImageTiling::DRM_FormatModifier_Extension:
						{
							return EResult::Error_FormatNotSupported;   // Not implemented yet.
						}
					}
				}

				return EResult::Error_FormatNotSupported;
			}

			/**
			@brief Finds the memory type index based on the type filter and properties desired. (Returns the max value of uint32 otherwise)
			*/
			static ui32 FindMemoryType(Handle _handle, ui32 _typeFilter, Memory::PropertyFlags _properties)
			{
				MemoryProperties memProperties;

				GetMemoryProperties(_handle, memProperties);

				for (ui32 index = 0; index < memProperties.TypeCount; index++)
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
			#else
				return 4294967295;
			#endif
			}

			/**
			@brief Provides the available layer extensions for the specified layer name into the _extensionListing container.
			*/
			static EResult GetAvailableLayerExtensions(Handle _handle, RoCStr _layerName, DynamicArray<ExtensionProperties>& _extensionListing)
			{
				ui32 count;

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
			static EResult GetAvailableLayersAndExtensions(Handle _handle, DynamicArray<LayerAndExtensionProperties>& _layersAndExtensions)
			{
				EResult result;

				for (ui32 index = 0; index < _layersAndExtensions.size(); index++)
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
			static DynamicArray<QueueFamilyProperties> GetAvailableQueueFamilies(Handle _handle)
			{
				DynamicArray<QueueFamilyProperties> queryResult; ui32 count;

				QueryQueueFamilyProperties(_handle, &count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(_handle, &count, queryResult.data());

				return queryResult;
			}

			/**
			@brief Gets the maximum sample count allowed for color and depth.
			*/
			static ESampleCount GetMaxSampleCount_ColorAndDepth(Handle _handle)
			{
				Properties properties;

				GetProperties(_handle, properties);

				SampleCountFlags counts
				(
					properties.LimitsSpec.FramebufferColorSampleCounts, 
					properties.LimitsSpec.FramebufferDepthSampleCounts
				);

				if (counts.HasFlag(ESampleCount::_64)) return ESampleCount::_64;
				if (counts.HasFlag(ESampleCount::_32)) return ESampleCount::_32;
				if (counts.HasFlag(ESampleCount::_16)) return ESampleCount::_16;
				if (counts.HasFlag(ESampleCount::_8 )) return ESampleCount::_8 ;
				if (counts.HasFlag(ESampleCount::_4 )) return ESampleCount::_4 ;
				if (counts.HasFlag(ESampleCount::_2 )) return ESampleCount::_2 ;

				return ESampleCount::_1;
			}
		};

		using QueueFamilyProperties = PhysicalDevice::QueueFamilyProperties;

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@brief Represents a physical device.

		@details This object only acts as a host interface to a given device object's handle. 
		*/
		class PhysicalDevice : public V2::PhysicalDevice
		{
		public:

			using Parent = V2::PhysicalDevice;
			
			/**
			@brief Default constructor.
			*/
			PhysicalDevice() : handle(Null<Handle>)
			{}

			/**
			@brief Default constructor with handle specified.
			*/
			PhysicalDevice(Handle _handle) : handle(_handle)
			{
				Parent::GetFeatures        (handle, features        );
				Parent::GetMemoryProperties(handle, memoryProperties);
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties2     (handle, properties2     );
			}

			/**
			@brief Assigns the handle.
			*/
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
			bool CheckExtensionSupport(RoCStr _extensionSpecified) const
			{
				DynamicArray<ExtensionProperties> availableExtensions;

				GetAvailableExtensions(nullptr, availableExtensions);

				bool isSupported = false;

				for (const auto& extension : availableExtensions)
				{
					if (strcmp(extension.Name, _extensionSpecified) == 0)
					{
						isSupported = true;
					}
				}

				return isSupported;
			}

			/**
			@brief Checks to see if the extensions specified are supported.
			*/
			bool CheckExtensionSupport(DynamicArray<RoCStr> _extensionsSpecified) const
			{
				DynamicArray<ExtensionProperties> availableExtensions;

				GetAvailableExtensions(nullptr, availableExtensions);

				using ExtensionNameSet = std::set<std::string>;

				ExtensionNameSet requiredExtensions(_extensionsSpecified.begin(), _extensionsSpecified.end());

				for (const auto& extension : availableExtensions)
				{
					requiredExtensions.erase(extension.Name);
				}

				bool isSupported = requiredExtensions.empty();

				return isSupported;
			}

			/**
			@brief Find the suitable memory type for the type filter and properties specified.
			*/
			ui32 FindMemoryType(ui32 _typeFilter, Memory::PropertyFlags _properties) const
			{
				for (ui32 index = 0; index < memoryProperties.TypeCount; index++)
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

				return 4294967295;
			}

			/**
			@brief Provides the queue families for the respective device.
			*/
			EResult FindSupportedFormat(const DynamicArray<EFormat>& _canidates, EImageTiling _tiling, FormatFeatureFlags _features, EFormat& _format) const
			{
				return Parent::FindSupportedFormat(handle, _canidates, _tiling, _features, _format);
			}

			/**
			@brief Assigns the handle.
			*/
			EResult GetAvailableExtensions(RoCStr _layerName, DynamicArray<ExtensionProperties>& _extensionListing) const
			{
				return EResult(Parent::GetAvailableLayerExtensions(handle, _layerName, _extensionListing));
			}

			/**
			@brief Provides the available queue families in a dynamic array.
			*/
			DynamicArray<QueueFamilyProperties> GetAvailableQueueFamilies() const
			{
				DynamicArray<QueueFamilyProperties> queryResult; ui32 count;

				QueryQueueFamilyProperties(&count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(&count, queryResult.data());

				return queryResult;
			}

			/**
			@brief Provides features.
			*/
			const Features& GetFeatures() const
			{
				return features;
			}

			/**
			@brief Query supported format features which are properties of the physical device.
			*/
			FormatProperties GetFormatProperties(EFormat _format) const
			{
				FormatProperties formatProperties;

				Parent::GetFormatProperties(handle, _format, formatProperties);

				return formatProperties;
			}

			/**
			@brief Gets the max sample count between color and depth.
			*/
			ESampleCount GetMaxSampleCount_ColorAndDepth() const
			{
				SampleCountFlags counts
				(
					properties.LimitsSpec.FramebufferColorSampleCounts,
					properties.LimitsSpec.FramebufferDepthSampleCounts
				);

				if (counts.HasFlag(ESampleCount::_64)) return ESampleCount::_64;
				if (counts.HasFlag(ESampleCount::_32)) return ESampleCount::_32;
				if (counts.HasFlag(ESampleCount::_16)) return ESampleCount::_16;
				if (counts.HasFlag(ESampleCount::_8 )) return ESampleCount::_8 ;
				if (counts.HasFlag(ESampleCount::_4 )) return ESampleCount::_4 ;
				if (counts.HasFlag(ESampleCount::_2 )) return ESampleCount::_2 ;

				return ESampleCount::_1;
			}

			/**
			@brief Provides the memory properties
			*/
			const MemoryProperties& GetMemoryProperties() const
			{
				return memoryProperties;
			}

			/**
			@brief Provides the properties.
			*/
			const Properties& GetProperties() const
			{
				return properties;
			}

			/**
			@brief Provides the properties 2.
			*/
			const Properties2& GetProperties2() const
			{
				return properties2;
			}

			/**
			@brief Query properties of queues available on a physical device. Reports properties of the queues of the specified physical device.
			*/
			EResult QueryExtensionProperties(RoCStr _layerName, ui32* _numExtensions, ExtensionProperties* _extensionPropertiesContainer) const
			{
				return Parent::QueryExtensionProperties(handle, _layerName, _numExtensions, _extensionPropertiesContainer);
			}

			/**
			@brief Query properties of queues available on a physical device.
			*/
			void QueryQueueFamilyProperties(ui32* _numQueueFamilies, QueueFamilyProperties* _queueFamilies) const
			{
				return Parent::QueryQueueFamilyProperties(handle, _numQueueFamilies, _queueFamilies);
			}

			/**
			@brief Query properties of queues available on a physical device.
			*/
			void QueryQueueFamilyProperties2(ui32* _numProperties, QueueFamilyProperties2* _properties) const
			{
				return Parent::QueryQueueFamilyProperties2(handle, _numProperties, _properties);
			}

			/**
			@brief Enumerate the performance query counters available on a queue family of a physical device.
			*/
			EResult QueryPerfomranceQueryCounters
			(
				ui32                             _queueFamilyIndex   ,
				ui32*                            _numCounters        ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			) const
			{
				return Parent::QueryPerfomranceQueryCounters(handle, _queueFamilyIndex, _numCounters, _counters, _counterDescriptions);
			}

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
			bool operator== (const PhysicalDevice& _other) const
			{
				return handle == _other.handle;
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

		using QueueFamilyProperties = PhysicalDevice::QueueFamilyProperties;

		/** @} */
	}
}
