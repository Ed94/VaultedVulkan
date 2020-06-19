/*
VaultedThermals: Physical Device

A physical device usually represents a single complete implementation of Vulkan 
(excluding instance-level functionality) available to the host, of which there are a finite number. 

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration
*/



#pragma once




#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Enums.hpp"
#include "VT_Constants.hpp"
#include "VT_Initalization.hpp"



namespace Vulkan
{
	namespace Vault_01
	{
		struct PhysicalDevice
		{
			static constexpr 
			sint32 MaxNameSize = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;

			using NameStr = char[MaxNameSize];
			using Handle  = VkPhysicalDevice ;
			using Size    = VkDeviceSize     ;   // Device memory size and offsets.

			struct Features : Vault_00::VKStruct_Base<VkPhysicalDeviceFeatures>
			{
				Bool RobustBufferAccess                     ;   // Out of bounds buffer accesses are well defined.
				Bool FullDrawIndexUint32                    ;   // full 32-bit range of indices are supported for indexed draw calls using VK_INDEX_TYPE_UINT32.
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
				Bool NonSolidFillModes                      ;   // Point and wireframe fill modes are supported.
				Bool DepthBounds                            ;   // Depth bounds test supported.
				Bool WideLines                              ;
				Bool LargePoints                            ;
				Bool AlphaToOne                             ;   // The implementation can replace the alpha value of the color fragment output to the maximum representable alpha value for fixed - point colors or 1.0 for floating - point colors.
				Bool MultiViewport                          ;   // Multiple viewports are supported. (VR)
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

			struct Limits : Vault_00::VKStruct_Base<VkPhysicalDeviceLimits>
			{
				uint32           MaxImageDimension1D;
				uint32           MaxImageDimension2D;
				uint32           MaxImageDimension3D;
				uint32           MaxImageDimensionCube;
				uint32           MaxImageArrayLayers;
				uint32           MaxTexelBufferElements;
				uint32           MaxUniformBufferRange;
				uint32           MaxStorageBufferRange;
				uint32           MaxPushConstantsSize;
				uint32           MaxMemoryAllocationCount;
				uint32           MaxSamplerAllocationCount;
				Size             BufferImageGranularity;
				Size             SparseAddressSpaceSize;
				uint32           MaxBoundDescriptorSets;
				uint32           MaxPerStageDescriptorSamplers;
				uint32           MaxPerStageDescriptorUniformBuffers;
				uint32           MaxPerStageDescriptorStorageBuffers;
				uint32           MaxPerStageDescriptorSampledImages;
				uint32           MaxPerStageDescriptorStorageImages;
				uint32           MaxPerStageDescriptorInputAttachments;
				uint32           MaxPerStageResources;
				uint32           MaxDescriptorSetSamplers;
				uint32           MaxDescriptorSetUniformBuffers;
				uint32           MaxDescriptorSetUniformBuffersDynamic;
				uint32           MaxDescriptorSetStorageBuffers;
				uint32           MaxDescriptorSetStorageBuffersDynamic;
				uint32           MaxDescriptorSetSampledImages;
				uint32           MaxDescriptorSetStorageImages;
				uint32           MaxDescriptorSetInputAttachments;
				uint32           MaxVertexInputAttributes;
				uint32           MaxVertexInputBindings;
				uint32           MaxVertexInputAttributeOffset;
				uint32           MaxVertexInputBindingStride;
				uint32           MaxVertexOutputComponents;
				uint32           MaxTessellationGenerationLevel;
				uint32           MaxTessellationPatchSize;
				uint32           MaxTessellationControlPerVertexInputComponents;
				uint32           MaxTessellationControlPerVertexOutputComponents;
				uint32           MaxTessellationControlPerPatchOutputComponents;
				uint32           MaxTessellationControlTotalOutputComponents;
				uint32           MaxTessellationEvaluationInputComponents;
				uint32           MaxTessellationEvaluationOutputComponents;
				uint32           MaxGeometryShaderInvocations;
				uint32           MaxGeometryInputComponents;
				uint32           MaxGeometryOutputComponents;
				uint32           MaxGeometryOutputVertices;
				uint32           MaxGeometryTotalOutputComponents;
				uint32           MaxFragmentInputComponents;
				uint32           MaxFragmentOutputAttachments;
				uint32           MaxFragmentDualSrcAttachments;
				uint32           MaxFragmentCombinedOutputResources;
				uint32           MaxComputeSharedMemorySize;
				uint32           MaxComputeWorkGroupCount[3];
				uint32           MaxComputeWorkGroupInvocations;
				uint32           MaxComputeWorkGroupSize[3];
				uint32           SubPixelPrecisionBits;
				uint32           SubTexelPrecisionBits;
				uint32           MipmapPrecisionBits;
				uint32           MaxDrawIndexedIndexValue;
				uint32           MaxDrawIndirectCount;
				float32          MaxSamplerLodBias;
				float32          MaxSamplerAnisotropy;
				uint32           MaxViewports;
				uint32           MaxViewportDimensions[2];
				float32          ViewportBoundsRange[2];
				uint32           ViewportSubPixelBits;
				size_t           MinMemoryMapAlignment;
				Size             MinTexelBufferOffsetAlignment;
				Size             MinUniformBufferOffsetAlignment;
				Size             MinStorageBufferOffsetAlignment;
				sint32           MinTexelOffset;
				uint32           MaxTexelOffset;
				sint32           MinTexelGatherOffset;
				uint32           MaxTexelGatherOffset;
				float32          MinInterpolationOffset;
				float32          MaxInterpolationOffset;
				uint32           SubPixelInterpolationOffsetBits;
				uint32           MaxFramebufferWidth;
				uint32           MaxFramebufferHeight;
				uint32           MaxFramebufferLayers;
				SampleCountFlags FramebufferColorSampleCounts;
				SampleCountFlags FramebufferDepthSampleCounts;
				SampleCountFlags FramebufferStencilSampleCounts;
				SampleCountFlags FramebufferNoAttachmentsSampleCounts;
				uint32           MaxColorAttachments;
				SampleCountFlags SampledImageColorSampleCounts;
				SampleCountFlags SampledImageIntegerSampleCounts;
				SampleCountFlags SampledImageDepthSampleCounts;
				SampleCountFlags SampledImageStencilSampleCounts;
				SampleCountFlags StorageImageSampleCounts;
				uint32           MaxSampleMaskWords;
				Bool             TimestampComputeAndGraphics;
				float32          TimestampPeriod;
				uint32           MaxClipDistances;
				uint32           MaxCullDistances;
				uint32           MaxCombinedClipAndCullDistances;
				uint32           DiscreteQueuePriorities;
				float32          PointSizeRange[2];
				float32          LineWidthRange[2];
				float32          PointSizeGranularity;
				float32          LineWidthGranularity;
				Bool             StrictLines;
				Bool             StandardSampleLocations;
				Size             OptimalBufferCopyOffsetAlignment;
				Size             OptimalBufferCopyRowPitchAlignment;
				Size             NonCoherentAtomSize;
			};

			struct SparseMemoryProperties
			{
				Bool ResidencyStandard2DBlockShape;
				Bool ResidencyStandard2DMultisampleBlockShape;
				Bool ResidencyStandard3DBlockShape;
				Bool ResidencyAlignedMipSize;
				Bool ResidencyNonResidentStrict;

				operator VkPhysicalDeviceSparseProperties()
				{
					return *(VkPhysicalDeviceSparseProperties*)(this);
				}
			};

			struct QueueFamilyProperties
			{
				QueueFlags QueueFlags                 ;
				uint32     QueueCount                 ;
				uint32     TimestampValidBits         ;
				Extent3D   MinImageTransferGranularity;

				operator VkQueueFamilyProperties()
				{
					return *(VkQueueFamilyProperties*)(this);
				}
			};

			struct Properties
			{
				uint32 API_Version;
				uint32 DriverVersion;
				uint32 VenderID;
				uint32 ID;
				EPhysicalDeviceType Type;
				NameStr Name;
				UUID PipelineCacheUUID;
				Limits LimitsSpec;
				SparseMemoryProperties SpareProperties;

				operator VkPhysicalDeviceProperties()
				{
					return *(VkPhysicalDeviceProperties*)(this);
				}
			};

			static constexpr 
			Handle NullHandle()
			{
				return Handle(VK_NULL_HANDLE);
			}


			static EResult Generate(AppInstance::Handle _instance, uint32& _numDevices, PhysicalDevice::Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_instance, &_numDevices, _deviceListing));
			}

			static uint32 GetNumOfDevices(AppInstance::Handle _instance)
			{
				uint32 deviceCount;

				vkEnumeratePhysicalDevices(_instance, &deviceCount, nullptr);

				return deviceCount;
			}

			static EResult GetAvailableDevices(AppInstance::Handle _instance, PhysicalDevice::Handle* _deviceListing)
			{
				uint32 deviceCount;

				vkEnumeratePhysicalDevices(_instance, &deviceCount, nullptr);

				return EResult(vkEnumeratePhysicalDevices(_instance, &deviceCount, _deviceListing));
			}

			static void GetProperties(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::Properties& _propertiesContainer)
			{
				vkGetPhysicalDeviceProperties(_deviceHandle, (VkPhysicalDeviceProperties*)(&_propertiesContainer));
			}

			static void GetFeatures(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::Features& _featuresContainer)
			{
				vkGetPhysicalDeviceFeatures(_deviceHandle, (VkPhysicalDeviceFeatures*)&_featuresContainer);
			}

			static void ReportQueueFamilyProperties(Handle _deviceHandle )
			{

			}

			/*
			Device extensions add new device-level functionality to the API, outside of the core specification.

			Query the extensions available to a given physical device.

			When pLayerName parameter is NULL, only extensions provided by the Vulkan implementation or by implicitly enabled layers are returned. 
			When pLayerName is the name of a layer, the device extensions provided by that layer are returned.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_device_extensions
			*/
			static EResult EnumerateExtensionProperties(Handle _deviceHandle, RoCStr _layerName, uint32* _numOfExtensions, ExtensionProperties* _extensionPropertiesContainer)
			{
				return EResult(vkEnumerateDeviceExtensionProperties(_deviceHandle, nullptr, _numOfExtensions, nullptr));
			}
		};
	}

	namespace Vault_02
	{
		struct PhysicalDevice : Vault_01::PhysicalDevice
		{
			/*
			
			*/
			static uint32 GetNumOfQueueFamilyProperties(PhysicalDevice::Handle _deviceHandle)
			{
				uint32 result;

				vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, &result, nullptr);

				return result;
			}

			static void GetQueueFamilyProperties(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::QueueFamilyProperties* _familyContainer)
			{
				uint32 numQueueFamilies;

				vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, &numQueueFamilies, nullptr);

				VkQueueFamilyProperties test;

				//vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, &numQueueFamilies, &test);
				vkGetPhysicalDeviceQueueFamilyProperties(_deviceHandle, &numQueueFamilies, (VkQueueFamilyProperties*)_familyContainer);

				//PhysicalDevice::QueueFamilyProperties conversionTest = *(PhysicalDevice::QueueFamilyProperties*)(&test);

				//*_familyContainer = conversionTest;
			}

			static uint32 GetNumOfAvailableExtensions(Handle _deviceHandle)
			{
				uint32 numExtensions;

				EnumerateExtensionProperties(_deviceHandle, nullptr, &numExtensions, nullptr);

				return numExtensions;
			}

			static void GetAvailableExtensions(Handle _deviceHandle, Vault_01::ExtensionProperties* _extensionPropertiesContainer)
			{
				uint32 numExtensions;

				EnumerateExtensionProperties(_deviceHandle, nullptr, &numExtensions, nullptr);

				EnumerateExtensionProperties(_deviceHandle, nullptr, &numExtensions, (VkExtensionProperties*)(_extensionPropertiesContainer));
			}
		};
	}
}
