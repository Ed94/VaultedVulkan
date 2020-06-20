/** @file VT_SwapChain.hpp

@brief Vaulted Thermals: Swap Chain

@details
<a href="https://vulkan-tutorial.com/Drawing_a_triangle/Presentation/Swap_chain">Guide (No Specification...)</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Enums.hpp"
#include "VT_Constants.hpp"
#include "VT_Initialization.hpp"
#include "VT_Queues.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Resource.hpp"
#include "VT_Surface.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		/**
		 * @brief A queue of images that can be presented to a surface.
		 */
		struct SwapChain
		{
			using Handle = VkSwapchainKHR;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSwapchainCreateInfoKHR.html">Specification</a> .
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkSwapchainCreateInfoKHR>
			{
				using ECreateFlag = ESwapchainCreateFlag;

				using CreateFlags = Bitmask<ECreateFlag, VkSwapchainCreateFlagsKHR >;

				      EType             SType                ;
				const void*             Next                 ;
				      CreateFlags       Flags                ;
				      Surface::Handle   Surface              ; 
				      uint32            MinImageCount        ;
				      EFormat           ImageFormat          ;
				      EColorSpace       ImageColorSpace      ;
				      Extent2D          ImageExtent          ;
				      uint32            ImageArrayLayers     ;
				      ImageUsageFlags	ImageUsage           ;
				      ESharingMode      ImageSharingMode     ;
				      uint32            QueueFamilyIndexCount;
				const uint32*           QueueFamilyIndices   ;
				      ESurfaceTransform PreTransform         ;
				      ECompositeAlpha   CompositeAlpha       ;
				      EPresentationMode PresentationMode     ;
				      Bool              Clipped              ;
				      Handle            OldSwapchain         ;
			};

			static constexpr Handle NullHandle = Handle(EHandle::Null);

			/**
			 * @brief Create a swapchain.
			 * 
			 * @details
			 * If the oldSwapchain parameter of pCreateInfo is a valid swapchain, which has exclusive full-screen access, that access is released from oldSwapchain. 
			 * If the command succeeds in this case, the newly created swapchain will automatically acquire exclusive full-screen access from oldSwapchain.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateSwapchainKHR.html">link text</a> 
			 * 
			 * \param _deviceHandle
			 * \param _creationSpecification
			 * \param _allocator
			 * \param _swapChain
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle  _deviceHandle         ,
				const SwapChain::CreateInfo& _creationSpecification,
				const AllocationCallbacks*   _allocator            ,
				      SwapChain::Handle&     _swapChain
			)
			{
				return EResult(vkCreateSwapchainKHR(_deviceHandle, (VkSwapchainCreateInfoKHR*)(&_creationSpecification), _allocator, (VkSwapchainKHR*)(&_swapChain)));
			};

			/**
			 * @brief Destroy a swapchain object.
			 * 
			 * @details
			 * The application must not destroy a swapchain until after completion of all outstanding operations on images that were acquired from the swapchain. 
			 * swapchain and all associated VkImage handles are destroyed, and must not be acquired or used any more by the application.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroySwapchainKHR.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _swapChainToDestroy
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, SwapChain::Handle _swapChainToDestroy, const AllocationCallbacks* _allocator)
			{
				vkDestroySwapchainKHR(_deviceHandle, _swapChainToDestroy, _allocator);
			}

			/**
			 * @brief Obtain the array of presentable images associated with a swapchain.
			 * 
			 * @details
			 * If pSwapchainImages is NULL, then the number of presentable images for swapchain is returned in pSwapchainImageCount. 
			 * Otherwise, pSwapchainImageCount must point to a variable set by the user to the number of elements in the pSwapchainImages array, 
			 * and on return the variable is overwritten with the number of structures actually written to pSwapchainImages.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetSwapchainImagesKHR.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _swapChain
			 * \param _numImages
			 * \param _images
			 * \return 
			 */
			static EResult QueryImages(LogicalDevice::Handle _deviceHandle, SwapChain::Handle _swapChain, uint32& _numImages, Image::Handle* _imagesContainer)
			{
				return EResult(vkGetSwapchainImagesKHR(_deviceHandle, _swapChain, &_numImages, _imagesContainer));
			}
		};
	}

	namespace Vault_02
	{
		using Vault_01::Image;

		struct SwapChain : Vault_01::SwapChain
		{
			/**
			 * @brief Provides the number of presentable images with the swapchain.
			 * 
			 * \param _deviceHandle
			 * \param _swapChain
			 * \return 
			 */
			static uint32 GetImageCount(LogicalDevice::Handle _deviceHandle, SwapChain::Handle _swapChain)
			{
				uint32 numImages;

				EResult&& result = QueryImages(_deviceHandle, _swapChain, numImages, nullptr);

				if (result != EResult::Success) std::runtime_error("Failed to get number of presentable images...");

				return numImages;
			}

			/**
			 * @brief Provides all presentable images with the swapchain.
			 * 
			 * \param _deviceHandle
			 * \param _swapChain
			 * \param _images
			 * \return 
			 */
			static EResult GetImages
			(
				LogicalDevice::Handle _deviceHandle,
				SwapChain::Handle     _swapChain   ,
				Image::Handle*        _images
			)
			{
				uint32 numImages = GetImageCount(_deviceHandle, _swapChain);

				EResult&& result = QueryImages(_deviceHandle, _swapChain, numImages, _images);

				if (result != EResult::Success) std::runtime_error("Failed to get number of presentable images...");

				return result;
			}
		};
	}
}
