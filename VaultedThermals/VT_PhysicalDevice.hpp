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
#include "VT_Memory.hpp"
#include "VT_Initialization.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		/**
		@brief Represents a physical device.
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
		 */
		struct PhysicalDevice
		{
			static constexpr 
			sint32 MaxNameSize = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;

			using Handle  = VkPhysicalDevice ;   //< https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDevice.html
			using NameStr = char[MaxNameSize];
			using Size    = VkDeviceSize     ;   //< https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceSize.html

			static constexpr
			Handle NullHandle = Handle(EHandle::Null);

			/**
			@brief Supported physical device types.

			@details
			The physical device type is advertised for informational purposes only, and does not directly affect the operation of the system. 
			However, the device type may correlate with other advertised properties or capabilities of the system, such as how many memory heaps there are.
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceType.html">Specification</a> 
			*/
			enum class EDeviceType : uint32
			{
				Other          = VK_PHYSICAL_DEVICE_TYPE_OTHER         ,
				IntergratedGPU = VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU,
				DiscreteGPU    = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU  ,
				VirtualGPU     = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU   ,
				CPU            = VK_PHYSICAL_DEVICE_TYPE_CPU
			};

			/**
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDriverId">Specification</a> 
			 * 
			 * @todo Implement.
			 */
			enum class EDriverID;

			/**
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkVendorId.html">Specification</a> 
			 * 
			 * @todo Implement.
			 */
			enum class EVendorID : uint32
			{
				VK_VENDOR_ID_VIV = 0x10001,
				VK_VENDOR_ID_VSI = 0x10002,
				VK_VENDOR_ID_KAZAN = 0x10003,
				VK_VENDOR_ID_CODEPLAY = 0x10004,
				VK_VENDOR_ID_MESA = 0x10005,
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a> 
			* 
			* @todo Implement.
			*/
			struct ConformanceVersion : Vault_00::VKStruct_Base<VkConformanceVersion>
			{};

			/**
			@brief Structure describing the fine-grained features that can be supported by an implementation.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceFeatures.html">Specification</a> 
			*/
			struct Features : Vault_00::VKStruct_Base<VkPhysicalDeviceFeatures>
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
			@brief Structure reporting implementation-dependent physical device limits.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceLimits.html">Specification</a> 
			*/
			struct Limits : Vault_00::VKStruct_Base<VkPhysicalDeviceLimits>
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
				Size             BufferImageGranularity                         ;
				Size             SparseAddressSpaceSize                         ;
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
				Size             MinTexelBufferOffsetAlignment                  ;
				Size             MinUniformBufferOffsetAlignment                ;
				Size             MinStorageBufferOffsetAlignment                ;
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
				Size             OptimalBufferCopyOffsetAlignment               ;
				Size             OptimalBufferCopyRowPitchAlignment             ;
				Size             NonCoherentAtomSize                            ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceMemoryProperties">Specification</a> 
			 */
			struct MemoryProperties : Vault_00::VKStruct_Base<VkPhysicalDeviceMemoryProperties >
			{
				uint32       TypeCount            ;
				Memory::Type Types[MaxMemoryTypes];
				uint32       HeapCount            ;
				Memory::Heap Heaps[MaxMemoryHeaps];
			};

			/**
			@brief Structure specifying various sparse related properties of the physical device.

			@details
			Some features of the implementation are not possible to disable, and are reported to allow applications 
			to alter their sparse resource usage accordingly. These read-only capabilities are reported in the 
			VkPhysicalDeviceProperties::sparseProperties member, which is a structure of type VkPhysicalDeviceSparseProperties.
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#sparsememory-physicalprops">Specification</a> 
			*/
			struct SparseMemoryProperties : Vault_00::VKStruct_Base<VkPhysicalDeviceSparseProperties>
			{
				Bool ResidencyStandard2DBlockShape           ;
				Bool ResidencyStandard2DMultisampleBlockShape;
				Bool ResidencyStandard3DBlockShape           ;
				Bool ResidencyAlignedMipSize                 ;
				Bool ResidencyNonResidentStrict              ;
			};

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterKHR">Specification</a> 
			* 
			* @todo Implement.
			*/
			struct PerformanceCounter
			{
				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterDescriptionKHR">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Description
				{

				};

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterScopeKHR">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Scope
				{

				};
			};

			/**
			@brief Container of query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceProperties.html">Specification</a> 
			*/
			struct Properties : Vault_00::VKStruct_Base<VkPhysicalDeviceProperties>
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
				@brief A set of queues that have common properties and support the same functionality.

				<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkQueueFamilyProperties.html">Specification</a> 
				*/
				struct QueueFamily: Vault_00::VKStruct_Base<VkQueueFamilyProperties>
				{
					using EFlag = EQueueFlag            ;
					using Flags = Bitmask<EFlag , Flags>;   // Bitmask specifying capabilities of queues in a queue family.    

					Flags      QueueFlags                 ;
					uint32     QueueCount                 ;
					uint32     TimestampValidBits         ;
					Extent3D   MinImageTransferGranularity;

					/**
					@brief Query properties of queues available on a physical device. Reports properties of the queues of the specified physical device.

					@details
					If pQueueFamilyProperties is NULL, then the number of queue families available is returned in pQueueFamilyPropertyCount. 
					Implementations must support at least one queue family. Otherwise, pQueueFamilyPropertyCount must point to a variable set 
					by the user to the number of elements in the pQueueFamilyProperties array, and on return the variable is overwritten 
					with the number of structures actually written to pQueueFamilyProperties.

					<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetPhysicalDeviceQueueFamilyProperties.html">Specification</a> 
					*/
					static void Report(Handle _deviceHandle, uint32* _numQueueFamilies, QueueFamily* _queuefamilyContainer)
					{
						vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, _numQueueFamilies, _queuefamilyContainer->operator VkQueueFamilyProperties*());
					}

					/**
					* @brief.
					* 
					* @details
					* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">Specification</a> 
					* 
					* @todo Implement.
					*/
					static EResult GetPerfomranceQueryCounters();
				};

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties2">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct QueueFamily2
				{
					/**
					* @brief.
					* 
					* @details
					* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyCheckpointPropertiesNV">Specification</a> 
					* 
					* @todo Implement.
					*/
					struct Checkpoint
					{

					};


					/**
					* @brief.
					* 
					* @details
					* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties2">Specification</a> 
					* 
					* @todo Implement.
					*/
					static void Report();
				};

				/**
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceVulkan11Properties.html">Specification</a> 
				*  
				* @todo Implement.
				*/
				struct Vulkan11
				{
					VkStructureType            sType;
					void*                      pNext;
					uint8_t                    deviceUUID[VK_UUID_SIZE];
					uint8_t                    driverUUID[VK_UUID_SIZE];
					uint8_t                    deviceLUID[VK_LUID_SIZE];
					uint32_t                   deviceNodeMask;
					VkBool32                   deviceLUIDValid;
					uint32_t                   subgroupSize;
					VkShaderStageFlags         subgroupSupportedStages;
					VkSubgroupFeatureFlags     subgroupSupportedOperations;
					VkBool32                   subgroupQuadOperationsInAllStages;
					VkPointClippingBehavior    pointClippingBehavior;
					uint32_t                   maxMultiviewViewCount;
					uint32_t                   maxMultiviewInstanceIndex;
					VkBool32                   protectedNoFault;
					uint32_t                   maxPerSetDescriptors;
					VkDeviceSize               maxMemoryAllocationSize;
				};

				/**
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceVulkan12Properties.html">Specification</a> 
				*  
				* @todo Implement.
				*/
				struct Vulkan12
				{
					VkStructureType                      sType;
					void*                                pNext;
					VkDriverId                           driverID;
					char                                 driverName[VK_MAX_DRIVER_NAME_SIZE];
					char                                 driverInfo[VK_MAX_DRIVER_INFO_SIZE];
					VkConformanceVersion                 conformanceVersion;
					VkShaderFloatControlsIndependence    denormBehaviorIndependence;
					VkShaderFloatControlsIndependence    roundingModeIndependence;
					VkBool32                             shaderSignedZeroInfNanPreserveFloat16;
					VkBool32                             shaderSignedZeroInfNanPreserveFloat32;
					VkBool32                             shaderSignedZeroInfNanPreserveFloat64;
					VkBool32                             shaderDenormPreserveFloat16;
					VkBool32                             shaderDenormPreserveFloat32;
					VkBool32                             shaderDenormPreserveFloat64;
					VkBool32                             shaderDenormFlushToZeroFloat16;
					VkBool32                             shaderDenormFlushToZeroFloat32;
					VkBool32                             shaderDenormFlushToZeroFloat64;
					VkBool32                             shaderRoundingModeRTEFloat16;
					VkBool32                             shaderRoundingModeRTEFloat32;
					VkBool32                             shaderRoundingModeRTEFloat64;
					VkBool32                             shaderRoundingModeRTZFloat16;
					VkBool32                             shaderRoundingModeRTZFloat32;
					VkBool32                             shaderRoundingModeRTZFloat64;
					uint32_t                             maxUpdateAfterBindDescriptorsInAllPools;
					VkBool32                             shaderUniformBufferArrayNonUniformIndexingNative;
					VkBool32                             shaderSampledImageArrayNonUniformIndexingNative;
					VkBool32                             shaderStorageBufferArrayNonUniformIndexingNative;
					VkBool32                             shaderStorageImageArrayNonUniformIndexingNative;
					VkBool32                             shaderInputAttachmentArrayNonUniformIndexingNative;
					VkBool32                             robustBufferAccessUpdateAfterBind;
					VkBool32                             quadDivergentImplicitLod;
					uint32_t                             maxPerStageDescriptorUpdateAfterBindSamplers;
					uint32_t                             maxPerStageDescriptorUpdateAfterBindUniformBuffers;
					uint32_t                             maxPerStageDescriptorUpdateAfterBindStorageBuffers;
					uint32_t                             maxPerStageDescriptorUpdateAfterBindSampledImages;
					uint32_t                             maxPerStageDescriptorUpdateAfterBindStorageImages;
					uint32_t                             maxPerStageDescriptorUpdateAfterBindInputAttachments;
					uint32_t                             maxPerStageUpdateAfterBindResources;
					uint32_t                             maxDescriptorSetUpdateAfterBindSamplers;
					uint32_t                             maxDescriptorSetUpdateAfterBindUniformBuffers;
					uint32_t                             maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
					uint32_t                             maxDescriptorSetUpdateAfterBindStorageBuffers;
					uint32_t                             maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
					uint32_t                             maxDescriptorSetUpdateAfterBindSampledImages;
					uint32_t                             maxDescriptorSetUpdateAfterBindStorageImages;
					uint32_t                             maxDescriptorSetUpdateAfterBindInputAttachments;
					VkResolveModeFlags                   supportedDepthResolveModes;
					VkResolveModeFlags                   supportedStencilResolveModes;
					VkBool32                             independentResolveNone;
					VkBool32                             independentResolve;
					VkBool32                             filterMinmaxSingleComponentFormats;
					VkBool32                             filterMinmaxImageComponentMapping;
					uint64_t                             maxTimelineSemaphoreValueDifference;
					VkSampleCountFlags                   framebufferIntegerColorSampleCounts;
				};

				/**
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceProperties.html">Specification</a> 
				*  
				* @todo Implement.
				*/
				struct DeviceID
				{
					uint32_t                            apiVersion;
					uint32_t                            driverVersion;
					uint32_t                            vendorID;
					uint32_t                            deviceID;
					VkPhysicalDeviceType                deviceType;
					char                                deviceName[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
					uint8_t                             pipelineCacheUUID[VK_UUID_SIZE];
					VkPhysicalDeviceLimits              limits;
					VkPhysicalDeviceSparseProperties    sparseProperties;
				};

				/**
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevicePCIBusInfoPropertiesEXT">Specification</a> 
				*  
				* @todo Implement.
				*/
				struct PCIBusInfo : Vault_00::VKStruct_Base
					<VkPhysicalDevicePCIBusInfoPropertiesEXT, EStructureType::PhysicalDevice_PCI_BUS_Info_Properties_EXT>
				{
					VkStructureType    sType;
					void* pNext;
					uint32_t           pciDomain;
					uint32_t           pciBus;
					uint32_t           pciDevice;
					uint32_t           pciFunction;
				};

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceGroupProperties ">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Group
				{
					/**
					* @brief 
					* 
					* @details
					* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceGroups">Specification</a> 
					* 
					* @todo Implement.
					*/
					static EResult GetListing();
				};
			};

			/**
			 * @brief.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceProperties2.html">Specification</a> 
			 * 
			 * @todo Implement.
			 */
			struct Properties2
			{
				VkStructureType               sType;
				void*                         pNext;
				VkPhysicalDeviceProperties    properties;
			};

			
			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
			*/
			static EResult QueryDeviceListing(AppInstance::Handle _instance, uint32* _numDevices, Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_instance, _numDevices, _deviceListing));
			}

			static void GetMemoryProperties(PhysicalDevice::Handle _physicalDevice, MemoryProperties& _properties)
			{
				vkGetPhysicalDeviceMemoryProperties(_physicalDevice, _properties);
			}

			/**
			@brief Query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetPhysicalDeviceProperties.html">Specification</a> 
			*/
			static void GetProperties(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::Properties& _propertiesContainer)
			{
				vkGetPhysicalDeviceProperties(_deviceHandle, _propertiesContainer.operator VkPhysicalDeviceProperties*());
			}

			/**
			 * @brief Query general properties of physical devices once enumerated (Second Ver).
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetPhysicalDeviceProperties2.html">Specification</a> 
			 * 
			 * @todo Implement.
			 */
			static void GetProperties2()
			{

			}

			/**
			@brief Query supported features. Reports capabilities of a physical device.
			
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetPhysicalDeviceFeatures.html">Specification</a> 
			*/
			static void GetFeatures(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::Features& _featuresContainer)
			{
				vkGetPhysicalDeviceFeatures(_deviceHandle, _featuresContainer.operator VkPhysicalDeviceFeatures*());
			}

			

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
		};
	}

	namespace Vault_02
	{
		using Vault_01::ExtensionProperties;

		/**
		@brief Represents a physical device.
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
		*/
		struct PhysicalDevice : Vault_01::PhysicalDevice
		{
			struct Properties : Vault_01::PhysicalDevice::Properties
			{
				struct QueueFamily : Vault_01::PhysicalDevice::Properties::QueueFamily
				{
					/**
					@brief Provides the number of available queue family  properties.
					*/
					static uint32 GetCount(Handle _deviceHandle)
					{
						uint32 result;

						Properties::QueueFamily::Report(_deviceHandle, &result, nullptr);

						return result;
					}

					/**
					@brief Provides the queue families for the respective device.
					*/
					static void Get(Handle _deviceHandle, QueueFamily* _familyContainer)
					{
						uint32 numQueueFamilies;

						Report(_deviceHandle, &numQueueFamilies, nullptr);

						Report(_deviceHandle, &numQueueFamilies, _familyContainer);
					}
				};
			};

			/**
			@brief Provides the number of available physical devices.
			*/
			static uint32 GetNumOfDevices(AppInstance::Handle _instance)
			{
				uint32 deviceCount;

				EResult result = QueryDeviceListing(_instance, &deviceCount, nullptr);

				if (result != EResult::Success) throw std::runtime_error("Failed to get number of extensions for a physical device.");

				return deviceCount;
			}

			/** 
			@brief Provides the handles of all available physical devices.
			*/
			static EResult GetAvailableDevices(AppInstance::Handle _instance, PhysicalDevice::Handle* _deviceListing)
			{
				uint32 deviceCount;

				EResult&& result = QueryDeviceListing(_instance, &deviceCount, nullptr);

				result = QueryDeviceListing(_instance, &deviceCount, _deviceListing);

				return result;
			}

			/** 
			@brief Provides the number of available extensions.
			*/
			static uint32 GetNumOfAvailableExtensions(Handle _deviceHandle)
			{
				uint32 numExtensions;

				EResult&& result = EnumerateExtensionProperties(_deviceHandle, nullptr, &numExtensions, nullptr);

				if (result != EResult::Success) throw std::runtime_error("Failed to get number of extensions for a physical device.");

				return numExtensions;
			}

			/** 
			@brief Provides the available extensions.
			*/
			static EResult GetAvailableExtensions(Handle _deviceHandle, ExtensionProperties* _extensionPropertiesContainer)
			{
				uint32 numExtensions;

				EResult&& result = EnumerateExtensionProperties(_deviceHandle, nullptr, &numExtensions, nullptr);

				result = EnumerateExtensionProperties(_deviceHandle, nullptr, &numExtensions, _extensionPropertiesContainer);

				return result;
			}
		};
	}

	namespace Vault_05
	{
		struct PhysicalDevice : Vault_02::PhysicalDevice
		{
		private:
			Handle handle;

			EDeviceType type    ;
			EDriverID   driverID;
			EVendorID   vendorID;

			//ConformanceVersion conformance;


			Features features;
			Limits   limits  ;

			PerformanceCounter perfCounter;


			Properties               properties      ;
			Properties2              properties2     ;
			Properties::DeviceID     deviceID        ;
			Properties::QueueFamily  queueFamily     ;
			Properties::QueueFamily2 queueFamily2    ;
			Properties::Group        group           ;
			Properties::PCIBusInfo   pciBusInfo      ;
			Properties::Vulkan11     vulk11Properties;
			Properties::Vulkan12     vulk12Properites;

			SparseMemoryProperties sparseMemProps;

		};
	}
}
