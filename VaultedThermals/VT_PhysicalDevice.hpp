/*
VaultedThermals: Physical Device
*/



#pragma once



#include <vulkan/vulkan.h>


#include "_foreign/Bitmask.hpp"


#include "VT_Constants.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_AppInstance.hpp"



namespace Vulkan
{
	class PhysicalDevice
	{
	public:
		using NameStr = char[PhysicalDevice_MaxNameSize];

		using Handle = VkPhysicalDevice;

		using Size = VkDeviceSize;   // Device memory size and offsets.


		struct Limits
		{
			using SampleCountFlags = bitmask<Flags, ESampleCountFlags>;

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

			operator VkPhysicalDeviceLimits()
			{
				return *(VkPhysicalDeviceLimits*)(this);
			}
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
	};


	EResult GeneratePhysicalDevices(AppInstance::Handle _instance, uint32& _numDevices, PhysicalDevice::Handle* _deviceListing)
	{
		return EResult(vkEnumeratePhysicalDevices(_instance, &_numDevices, _deviceListing));
	}

	uint32 GetNumOf_PhysicalDevices(AppInstance::Handle _instance)
	{
		uint32 deviceCount;

		vkEnumeratePhysicalDevices(_instance, &deviceCount, nullptr);

		return deviceCount;
	}

	EResult GetAvailablePhysicalDevices(AppInstance::Handle _instance, PhysicalDevice::Handle* _deviceListing)
	{
		uint32 deviceCount = GetNumOf_PhysicalDevices(_instance);

		return EResult(vkEnumeratePhysicalDevices(_instance, &deviceCount, _deviceListing));
	}

	void GetPhysicalDeviceProperties(PhysicalDevice::Handle _deviceHandle, PhysicalDevice::Properties& _propertiesContainer)
	{
		vkGetPhysicalDeviceProperties(_deviceHandle, (VkPhysicalDeviceProperties*)(&_propertiesContainer));
	}
}
