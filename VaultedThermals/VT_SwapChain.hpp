/*

*/



#pragma once



#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_Surface.hpp"



namespace Vulkan
{
	struct SwapChain
	{
		using Handle = VkSwapchainKHR;

		struct CreateInfo
		{
			using ECreateFlag = ESwapchainCreateFlag;
			using CreateFlags = bitmask<ECreateFlag, Flags>;


			EStructureType    SType;
			const void*       Extension;
			CreateFlags       Flags;
			Surface::Handle   Surface;
			uint32            MinImageCount;
			EImageFormat      ImageFormat;
			EColorSpace       ImageColorSpace;
			Extent2D          ImageExtent;
			uint32            ImageArrayLayers;
			ImageUsageFlags	ImageUsage;
			ESharingMode      ImageSharingMode;
			uint32            QueueFamilyIndexCount;
			const uint32*     QueueFamilyIndices;
			ESurfaceTransform PreTransform;
			ECompositeAlpha   CompositeAlpha;
			EPresentationMode PresentationMode;
			Bool              Clipped;
			Handle            OldSwapchain;

			operator VkSwapchainCreateInfoKHR()
			{
				return *(VkSwapchainCreateInfoKHR*)(this);
			}
		};

		static constexpr Handle NullHandle()
		{
			return Handle(VK_NULL_HANDLE);
		}
	};

	EResult CreateSwapChain
	(
		LogicalDevice::Handle _deviceHandle,
		const SwapChain::CreateInfo& _creationSpecification,
		const AllocationCallbacks* _allocator,
		SwapChain::Handle& _swapChain
	)
	{
		return EResult(vkCreateSwapchainKHR(_deviceHandle, (VkSwapchainCreateInfoKHR*)(&_creationSpecification), _allocator, (VkSwapchainKHR*)(&_swapChain)));
	};

	void DestroySwapChain(LogicalDevice::Handle _deviceHandle, SwapChain::Handle _swapChainToDestroy, const AllocationCallbacks* _allocator)
	{
		vkDestroySwapchainKHR(_deviceHandle, _swapChainToDestroy, _allocator);
	}

	EResult SwapChain_GetImages
	(
		LogicalDevice::Handle _deviceHandle,
		SwapChain::Handle _swapChain,
		Image::Handle* _images
	)
	{
		uint32 numImages;

		vkGetSwapchainImagesKHR(_deviceHandle, _swapChain, &numImages, nullptr);

		return EResult( vkGetSwapchainImagesKHR(_deviceHandle, _swapChain, &numImages, _images));
	}
}
