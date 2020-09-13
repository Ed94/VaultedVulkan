/*
@file VT_SwapChain.hpp

@brief Vaulted Thermals: Swap Chain

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_swapchain">Specification</a>
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_SyncAndCacheControl.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Command.hpp"
#include "VT_Surface.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		@ingroup APISpec_Window_System_Integration_WSI
		
		@brief A queue of images that can be presented to a surface.
		
		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_swapchain">Specification</a>
		*/
		struct Swapchain
		{
			/**
			@ingroup APISpec_Window_System_Integration_WSI

			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSwapchainKHR">Specification</a> 
			*/
			using Handle = VkSwapchainKHR;

			using ECreateFlag = ESwapchainCreateFlag;

			/**
			@ingroup APISpec_Window_System_Integration_WSI

			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSwapchainCreateFlagsKHR">Specification</a> 
			*/
			using CreateFlags = Bitmask<ESwapchainCreateFlag, VkSwapchainCreateFlagsKHR >;

			/**
			@ingroup APISpec_Window_System_Integration_WSI

			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSwapchainCreateInfoKHR.html">Specification</a> 
			*/
			struct CreateInfo : V0::VKStruct_Base<VkSwapchainCreateInfoKHR, EStructureType::SwapChain_CreateInfo_KHR>
			{
				      EType                 SType                 = STypeEnum;
				const void*                 Next                  = nullptr  ;
				      CreateFlags           Flags                ;
				      Surface::Handle       Surface              ;
				      uint32                MinImageCount        ;
				      EFormat               ImageFormat          ;
				      EColorSpace           ImageColorSpace      ;
				      Extent2D              ImageExtent          ;
				      uint32                ImageArrayLayers     ;
				      Image::UsageFlags	    ImageUsage           ;
				      ESharingMode          ImageSharingMode     ;
				      uint32                QueueFamilyIndexCount = 0        ;
				const uint32*               QueueFamilyIndices    = nullptr  ;
				      ESurfaceTransformFlag PreTransform         ;
				      ECompositeAlpha       CompositeAlpha       ;
				      EPresentationMode     PresentationMode     ;
				      Bool                  Clipped              ;
				      Handle                OldSwapchain         ;
			};

			/**
			@ingroup APISpec_Window_System_Integration_WSI

			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPresentInfoKHR">Specification</a>
			*/
			struct PresentationInfo : V0::VKStruct_Base<VkPresentInfoKHR, EStructureType::PresentInfo_KHR>
			{
				      EType              SType              = STypeEnum;
				const void*              Next               = nullptr  ;
				      uint32             WaitSemaphoreCount = 0        ;
				const Semaphore::Handle* WaitSemaphores     = nullptr  ;
				      uint32             SwapchainCount     = 0        ;
				const Handle*            Swapchains         = nullptr  ;
				const uint32*            ImageIndices       = nullptr  ;
				      EResult*           Results            = nullptr  ;
			};

			/**
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * @brief Acquire an available presentable image to use, and retrieve the index of that image.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAcquireNextImageKHR">Specification</a>
			 */
			static EResult AcquireNextImage
			(
				LogicalDevice::Handle _device    ,
				Handle                _swapchain ,
				uInt64                _timeout   ,
				Semaphore::Handle     _semaphore ,
				Fence::Handle         _fence     ,
				uint32&               _imageIndex
			)
			{
				return EResult(vkAcquireNextImageKHR(_device, _swapchain, _timeout, _semaphore, _fence, &_imageIndex));
			}

			/**
			@ingroup APISpec_Window_System_Integration_WSI
			
			@brief Create a swapchain.
			* 
			@details If the oldSwapchain parameter of pCreateInfo is a valid swapchain, which has exclusive full-screen access, that access is released from oldSwapchain.
			If the command succeeds in this case, the newly created swapchain will automatically acquire exclusive full-screen access from oldSwapchain.
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSwapchainKHR">Specification</a> 
			*/
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _info        ,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _swapChain
			)
			{
				return EResult(vkCreateSwapchainKHR(_deviceHandle, _info, *_allocator, &_swapChain));
			};

			/**
			@ingroup APISpec_Window_System_Integration_WSI
			
			@brief Destroy a swapchain object.
			
			@details
			The application must not destroy a swapchain until after completion of all outstanding operations on images that were acquired from the swapchain. 
			swapchain and all associated VkImage handles are destroyed, and must not be acquired or used any more by the application.
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySwapchainKHR">Specification</a> 
			*/
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _swapChainToDestroy, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroySwapchainKHR(_deviceHandle, _swapChainToDestroy, *_allocator);
			}

			/**
			@ingroup APISpec_Window_System_Integration_WSI

			@brief Query a swapchains status when rendering to a shared presentable image.

			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSwapchainStatusKHR">Specification</a> 
			*/
			static EResult GetStatus(LogicalDevice::Handle _device, Handle _swapchain)
			{
				return EResult(vkGetSwapchainStatusKHR(_device, _swapchain));
			}

			/**
			@ingroup APISpec_Window_System_Integration_WSI
			
			@brief Obtain the array of presentable images associated with a swapchain.
			
			@details
			If pSwapchainImages is NULL, then the number of presentable images for swapchain is returned in pSwapchainImageCount. 
			Otherwise, pSwapchainImageCount must point to a variable set by the user to the number of elements in the pSwapchainImages array, 
			and on return the variable is overwritten with the number of structures actually written to pSwapchainImages.
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSwapchainImagesKHR">Specification</a>
			*/
			static EResult QueryImages(LogicalDevice::Handle _deviceHandle, Handle _swapChain, uint32& _numImages, Image::Handle* _imagesContainer)
			{
				return EResult(vkGetSwapchainImagesKHR(_deviceHandle, _swapChain, &_numImages, _imagesContainer));
			}
		};

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief A queue of images that can be presented to a surface.
		*/
		struct Swapchain : V1::Swapchain
		{
			using Parent = V1::Swapchain;

			/**
			@brief Create a swapchain (Default Allocator).
			*/
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _info        ,
				      Handle&               _swapChain
			)
			{
				return Parent::Create(_deviceHandle, _info, Memory::DefaultAllocator, _swapChain);
			}

			using Parent::Create;

			/**
			@brief Destroy a swapchain (Default Allocator).
			*/
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _swapChainToDestroy)
			{
				Parent::Destroy(_deviceHandle, _swapChainToDestroy, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			@brief Provides all presentable images with the swapchain.
			*/
			static EResult GetImages
			(
				LogicalDevice::Handle        _deviceHandle,
				Handle                       _swapChain   ,
				DynamicArray<Image::Handle>* _images
			)
			{
				uint32 numImages;

				EResult result = QueryImages(_deviceHandle, _swapChain, numImages, nullptr);

				if (result != EResult::Success) return result;

				_images->resize(numImages);
					
				result = QueryImages(_deviceHandle, _swapChain, numImages, _images->data());

				return result;
			}
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@brief A queue of images that can be presented to a surface.

		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class Swapchain : public V2::Swapchain
		{
		public:

			using Parent = V2::Swapchain;

			/**
			@brief Default constructor.
			*/
			Swapchain() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Specifies the logical device.
			*/
			Swapchain(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Specifies the logical device and allocator.
			*/
			Swapchain(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			Swapchain(Swapchain&& _other) noexcept :
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy a swapchain if the handle is null.
			*/
			~Swapchain()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Acquire an available presentable image to use, and retrieve the index of that image.
			*/
			EResult AcquireNextImage
			(
				uInt64                _timeout   ,
				Semaphore::Handle     _semaphore ,
				Fence::Handle         _fence     ,
				uint32&               _imageIndex
			)
			{
				return Parent::AcquireNextImage(*device, handle, _timeout, _semaphore, _fence, _imageIndex);
			}

			/**
			@brief Create a swapchain with the specified create info.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a swapchain with the specified logical device and create info.
			*/
			EResult Create(const LogicalDevice& _deviceHandle, const CreateInfo& _info)
			{
				device = &_deviceHandle;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a swapchain with the specified logical device, create info, and allocator.
			*/
			EResult Create(const LogicalDevice& _deviceHandle, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_deviceHandle;
				allocator = &_allocator   ;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy a swapchain.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Gets the available swapchain images and stores them in the provided dynamic array container.
			*/
			EResult GetImages(DynamicArray<Image>& _images)
			{
				uint32 numImages;

				EResult result = QueryImages(numImages, nullptr);

				if (result != EResult::Success) return result;

				_images.resize(numImages);	DynamicArray<Image::Handle> handles(numImages);

				result = QueryImages(numImages, handles.data());

				for (DeviceSize index = 0; index < numImages; index++)
				{
					_images[index].Assign(*device, handles[index]);
				}

				return result;
			}

			/**
			@brief Obtain the array of presentable images associated with a swapchain.
			*/
			EResult QueryImages(uint32& _numImages, Image::Handle* _imagesContainer)
			{
				return Parent::QueryImages(*device, handle, _numImages, _imagesContainer);
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
			bool operator== (const Swapchain& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			Swapchain& operator= (Swapchain&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/** @} */
	}
}
