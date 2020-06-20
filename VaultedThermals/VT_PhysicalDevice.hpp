/** @file VT_PhysicalDevice.hpp

@brief VaultedThermals: Physical Device

@details
A physical device usually represents a single complete implementation of Vulkan 
(excluding instance-level functionality) available to the host, of which there are a finite number. 


<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
*/



#pragma once



#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Enums.hpp"
#include "VT_Constants.hpp"
#include "VT_Initialization.hpp"
#include "VT_Queues.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		/**
		@brief
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
				Bool AnisotropySampler                      ;
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
			};


			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
			*/
			static EResult GenerateDevices(AppInstance::Handle _instance, uint32* _numDevices, PhysicalDevice::Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_instance, _numDevices, _deviceListing));
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
			@brief Query supported features. Reports capabilities of a physical device.
			
			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetPhysicalDeviceFeatures.html">Specification</a> 
			*/
			static void GetFeatures(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::Features& _featuresContainer)
			{
				vkGetPhysicalDeviceFeatures(_deviceHandle, _featuresContainer.operator VkPhysicalDeviceFeatures*());
			}

			/**
			@brief Query properties of queues available on a physical device. Reports properties of the queues of the specified physical device.

			@details
			If pQueueFamilyProperties is NULL, then the number of queue families available is returned in pQueueFamilyPropertyCount. 
			Implementations must support at least one queue family. Otherwise, pQueueFamilyPropertyCount must point to a variable set 
			by the user to the number of elements in the pQueueFamilyProperties array, and on return the variable is overwritten 
			with the number of structures actually written to pQueueFamilyProperties.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetPhysicalDeviceQueueFamilyProperties.html">Specification</a> 
			*/
			static void ReportQueueFamilyProperties(Handle _deviceHandle, uint32* _numQueueFamilies, QueueFamilyProperties* _queuefamilyContainer)
			{
				vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, _numQueueFamilies, _queuefamilyContainer->operator VkQueueFamilyProperties*());
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
		using Vault_01::QueueFamilyProperties;
		using Vault_01::ExtensionProperties  ;

		struct PhysicalDevice : Vault_01::PhysicalDevice
		{
			/**
			@brief Provides the number of available physical devices.
			*/
			static uint32 GetNumOfDevices(AppInstance::Handle _instance)
			{
				uint32 deviceCount;

				EResult result = GenerateDevices(_instance, &deviceCount, nullptr);

				if (result != EResult::Success) throw std::runtime_error("Failed to get number of extensions for a physical device.");

				return deviceCount;
			}

			/** 
			@brief Provides the handles of all available physical devices.
			*/
			static EResult GetAvailableDevices(AppInstance::Handle _instance, PhysicalDevice::Handle* _deviceListing)
			{
				uint32 deviceCount;

				EResult&& result = GenerateDevices(_instance, &deviceCount, nullptr);

				result = GenerateDevices(_instance, &deviceCount, _deviceListing);

				return result;
			}

			/**
			@brief Provides the number of available queue family  properties.
			*/
			static uint32 GetNumOfQueueFamilyProperties(PhysicalDevice::Handle _deviceHandle)
			{
				uint32 result;

				ReportQueueFamilyProperties(_deviceHandle, &result, nullptr);

				return result;
			}

			/**
			@brief Provides the queue families for the respective device.
			*/
			static void GetQueueFamilyProperties(PhysicalDevice::Handle _deviceHandle, QueueFamilyProperties* _familyContainer)
			{
				uint32 numQueueFamilies;

				ReportQueueFamilyProperties(_deviceHandle, &numQueueFamilies, nullptr);

				ReportQueueFamilyProperties(_deviceHandle, &numQueueFamilies, _familyContainer);
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
}
