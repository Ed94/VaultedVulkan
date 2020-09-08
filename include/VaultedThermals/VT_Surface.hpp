/*!
@file VT_Surface.hpp

@brief Vaulted Thermals: Surface

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_surface">Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
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



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V0
	{
		using V1::Extent2D   ;
		using V1::InstanceExt;

		/**
		@addtogroup Vault_0
		@{
		*/

		/**
		 * @brief Cross-Platform set of definitions for a Surface.
		 */
		struct Surface_PlatformAgnostic
		{
			using Image = V1::Image;

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceKHR">Specification</a> 
			
			@ingroup APISpec_Window_System_Integration_WSI 
			*/
			using Handle = VkSurfaceKHR;

			using ETransform = ESurfaceTransformFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceTransformFlagsKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
			using ETransformFlags     = Bitmask<ESurfaceTransformFlag, VkSurfaceTransformFlagsKHR>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompositeAlphaFlagsKHR">Specification</a> @ingroup APISpec_Window_System_Integration_WSI */
			using CompositeAlphaFlags = Bitmask<ECompositeAlpha      , VkCompositeAlphaFlagsKHR  >;

			/**
			 * @brief Structure describing capabilities of a surface.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceCapabilitiesKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 */
			struct Capabilities : V0::VKStruct_Base<VkSurfaceCapabilitiesKHR>
			{
				uint32              MinImageCount          ;
				uint32              MaxImageCount          ;
				Extent2D            CurrentExtent          ;
				Extent2D            MinImageExtent         ;
				Extent2D            MaxImageExtent         ;
				uint32              MaxImageArrayLayers    ;
				ETransformFlags     SupportedTransforms    ;
				ETransform          CurrentTransform       ;
				CompositeAlphaFlags SupportedCompositeAlpha;
				Image::UsageFlags   SupportedUsageFlags    ;

				bool operator== (const Capabilities& _other)
				{
					return
						MinImageCount           == _other.MinImageCount           &&
						MaxImageCount           == _other.MaxImageCount           &&
						CurrentExtent           == _other.CurrentExtent           &&
						MinImageExtent          == _other.MinImageExtent          &&
						MaxImageExtent          == _other.MaxImageExtent          &&
						MaxImageArrayLayers     == _other.MaxImageArrayLayers     &&
						SupportedTransforms     == _other.SupportedTransforms     &&
						SupportedCompositeAlpha == _other.SupportedCompositeAlpha &&
						SupportedUsageFlags     == _other.SupportedUsageFlags 
						? true : false;
				}

				bool operator!= (const Capabilities& _other)
				{
					return
						MinImageCount           != _other.MinImageCount           &&
						MaxImageCount           != _other.MaxImageCount           &&
						CurrentExtent           != _other.CurrentExtent           &&
						MinImageExtent          != _other.MinImageExtent          &&
						MaxImageExtent          != _other.MaxImageExtent          &&
						MaxImageArrayLayers     != _other.MaxImageArrayLayers     &&
						SupportedTransforms     != _other.SupportedTransforms     &&
						SupportedCompositeAlpha != _other.SupportedCompositeAlpha &&
						SupportedUsageFlags     != _other.SupportedUsageFlags 
						? true : false;
				}
			};

			/**
			 * @brief Structure describing a supported swapchain format-color space pair.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceFormatKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 */
			struct Format : V0::VKStruct_Base<VkSurfaceFormatKHR>
			{
				EFormat     Format    ;
				EColorSpace ColorSpace;
			};
		};

		/** @brief Used to create an OS platform's surface type. */
		template<EOS> struct Surface_Maker;

		/** @brief Defines a Surface's extended definitions for Windows. */
		template<> struct Surface_Maker<EOS::Windows> : public Surface_PlatformAgnostic
		{
			using OS_AppHandle    = PlatformTypes::OS_AppHandle   ;
			using OS_WindowHandle = PlatformTypes::OS_WindowHandle;

			static constexpr RoCStr OSSurface = InstanceExt::Win32Surface;

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32SurfaceCreateInfoKHR">Specification</a> 

			@ingroup APISpec_Window_System_Integration_WSI
			*/
			struct CreateInfo : V0::VKStruct_Base<VkWin32SurfaceCreateInfoKHR, EStructureType::Win32_Surface_CreateInfo_KHR>
			{
				using CreateFlags = Bitmask<EUndefined, VkWin32SurfaceCreateFlagsKHR>;   ///< Reserved for future use.

				      EType           SType      ;
				const void*           Next       ;
				      CreateFlags     Flags      ;
				      OS_AppHandle    OSAppHandle;
				      OS_WindowHandle OSWinHandle;
			};

			/**
			 * @brief Returns the handle for the current process.
			 * 
			 * @details
			 * <a href="https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea">Specification</a> 
			 * 
			 * \return 
			 */
			static OS_AppHandle GetOS_AppHandle()
			{
				return GetModuleHandle(nullptr);
			}

			/**
			 * @brief Create a slink:VkSurfaceKHR object for an Win32 native window.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateWin32SurfaceKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * \param _appHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _surfaceHandle
			 * \return 
			 */
			static EResult Create
			(
				      V1::AppInstance::Handle      _appHandle    ,
				const CreateInfo&                  _info         ,
				const Memory::AllocationCallbacks* _allocator    ,
				      Handle&                      _surfaceHandle
			)
			{
				return EResult(vkCreateWin32SurfaceKHR(_appHandle, _info, _allocator->operator const VkAllocationCallbacks*(), &_surfaceHandle));
			}
		};

		/** @brief Surface definition for the currently detected OS platform. */
		//using Surface = Surface_Maker<OS_Platform>;

		/** @} */
	}

	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/** 
		@brief Native platform surface or window objects are abstracted by surface objects.

		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_surface">Specification</a> 

		@ingroup APISpec_Window_System_Integration_WSI
		*/
		struct Surface : public V0::Surface_Maker<V0::OS_Platform>
		{
			/**
			 * @brief Destroy a VkSurfaceKHR object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySurfaceKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * \param _appHandle
			 * \param _surfaceHandle
			 * \param _allocator
			 */
			static void Destroy(AppInstance::Handle _appHandle, Surface::Handle _surfaceHandle, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroySurfaceKHR(_appHandle, _surfaceHandle, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief Query if presentation is supported.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfaceSupportKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * \param _physDeviceHandle
			 * \param _queueFamilyIndex
			 * \param _surfaceHandle
			 * \param _checkResult
			 * \return 
			 */
			static EResult CheckPhysicalDeviceSupport
			(
				PhysicalDevice::Handle _physDeviceHandle,
				uint32                 _queueFamilyIndex,
				Surface::Handle        _surfaceHandle   ,
				Bool&                  _checkResult
			)
			{
				return EResult(vkGetPhysicalDeviceSurfaceSupportKHR(_physDeviceHandle, _queueFamilyIndex, _surfaceHandle, &_checkResult));
			}

			/**
			 * @brief Query surface capabilities.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfaceCapabilitiesKHR">Specification</a>  
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * \param _deviceHandle
			 * \param _surface
			 * \param _capabilitiesResult
			 * \return 
			 */
			static EResult GetPhysicalDeviceCapabilities(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surface, Surface::Capabilities& _capabilitiesResult)
			{
				return EResult(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_deviceHandle, _surface, (VkSurfaceCapabilitiesKHR*)(&_capabilitiesResult)));
			}

			/**
			 * @brief Query color formats supported by surface.
			 * 
			 * @details 
			 * If pSurfaceFormats is NULL, then the number of format pairs supported for the given surface is returned in pSurfaceFormatCount. 
			 * Otherwise, pSurfaceFormatCount must point to a variable set by the user to the number of elements in the pSurfaceFormats array, 
			 * and on return the variable is overwritten with the number of structures actually written to pSurfaceFormats.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfaceFormatsKHR">Specification</a> 
			 *
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _numFormats
			 * \param _formatsContainer
			 * \return 
			 */
			static EResult GetFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, uint32& _numFormats, Surface::Format* _formatsContainer)
			{
				return EResult(vkGetPhysicalDeviceSurfaceFormatsKHR(_deviceHandle, _surfaceHandle, &_numFormats, _formatsContainer->operator VkSurfaceFormatKHR*()));
			}

			/**
			 * @brief Query supported presentation modes.
			 * 
			 * @details
			 * If pPresentModes is NULL, then the number of presentation modes supported for the given surface is returned in pPresentModeCount. 
			 * Otherwise, pPresentModeCount must point to a variable set by the user to the number of elements in the pPresentModes array, 
			 * and on return the variable is overwritten with the number of values actually written to pPresentModes.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfacePresentModesKHR">Specification</a>  
			 * 
			 * @ingroup APISpec_Window_System_Integration_WSI
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _numPresentationModes
			 * \param _presentationModesContainer
			 * \return 
			 */
			static EResult QuerySupportedPresentationModes
			(
				PhysicalDevice::Handle _deviceHandle              , 
				Surface::Handle        _surfaceHandle             , 
				uint32&                _numPresentationModes      , 
				EPresentationMode*     _presentationModesContainer
			)
			{
				return EResult(vkGetPhysicalDeviceSurfacePresentModesKHR(_deviceHandle, _surfaceHandle, &_numPresentationModes, (VkPresentModeKHR*)(_presentationModesContainer)));
			}
		};

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		*/

		/** @brief Surfaces hook onto a window to use as a rendering target. */
		struct Surface : public  V1::Surface
		{
			using Parent = V1::Surface;

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType       = STypeEnum        ;
					Next        = nullptr          ;
					OSAppHandle = GetOS_AppHandle();
				}
			};

			/**
			@brief Create a surface (Default Allocator).
			*/
			static EResult Create(AppInstance::Handle _appHandle, const CreateInfo& _createInfo, Handle& _surfaceHandle)
			{
				return Parent::Create(_appHandle, _createInfo, Memory::DefaultAllocator, _surfaceHandle);
			}

			using Parent::Create;

			/**
			@brief Destroy a surface (Default Allocator).
			*/
			static void Destroy(AppInstance::Handle _appHandle, Surface::Handle _surfaceHandle)
			{
				Parent::Destroy(_appHandle, _surfaceHandle, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Provides the available surface formats.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _formatsContainer
			 * \return 
			 */
			static EResult GetAvailableFormats
			(
				PhysicalDevice::Handle         _deviceHandle    , 
				Surface::Handle                _surfaceHandle   , 
				DynamicArray<Surface::Format>& _formatsContainer
			)
			{
				uint32 numFormats; 
				
				EResult result = GetFormats(_deviceHandle, _surfaceHandle, numFormats, nullptr);

				if (result != EResult::Success) return result;

				_formatsContainer.resize(numFormats);

				result = GetFormats(_deviceHandle, _surfaceHandle, numFormats, _formatsContainer.data());

				return result;
			}

			/**
			 * @brief Provides the supported presentation modes.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _presentationModesContainer
			 * \return 
			 */
			static EResult GetSupportedPresentationModes
			(
				PhysicalDevice::Handle           _deviceHandle              , 
				Surface::Handle                  _surfaceHandle             , 
				DynamicArray<EPresentationMode>& _presentationModesContainer
			)
			{
				uint32 numPresentationModes; 
				
				EResult result = QuerySupportedPresentationModes(_deviceHandle, _surfaceHandle, numPresentationModes, nullptr);

				if (result != EResult::Success) return result;

				_presentationModesContainer.resize(numPresentationModes);

				result = QuerySupportedPresentationModes(_deviceHandle, _surfaceHandle, numPresentationModes, _presentationModesContainer.data());
				
				return result;
			}
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		*/

		class Surface : public V2::Surface
		{
		public:

			using Parent = V2::Surface;

			void AssignPhysicalDevice(const PhysicalDevice& _physicalDevice)
			{
				physicalDevice = &_physicalDevice;
			}

			EResult Create(const AppInstance& _app, OS_WindowHandle _window)
			{
				CreateInfo geninfo {}; geninfo.OSWinHandle = _window;

				app       = &_app                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*app, geninfo, handle);
			}

			EResult Create(const AppInstance& _appHandle, const CreateInfo&  _info)
			{
				app       = &_appHandle             ;
				allocator = Memory::DefaultAllocator;
				
				return Parent::Create(*app, _info, handle);
			}

			EResult Create(const AppInstance& _appHandle, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				app       = &_appHandle;
				allocator = &_allocator;
				
				return Parent::Create(*app, _info, allocator, handle);
			}

			EResult CheckPhysicalDeviceSupport(uint32 _queueFamilyIndex, Bool& _checkResult)
			{
				return Parent::CheckPhysicalDeviceSupport(*physicalDevice, _queueFamilyIndex, handle, _checkResult);
			}

			void Destroy()
			{
				Parent::Destroy(*app, handle);
			}

			EResult GetAvailableFormats(DynamicArray<Format>& _formatsContainer) const
			{
				return Parent::GetAvailableFormats(*physicalDevice, handle, _formatsContainer);
			}

			EResult GetPhysicalDeviceCapabilities(Capabilities& _result) const
			{
				return Parent::GetPhysicalDeviceCapabilities(*physicalDevice, handle, _result);
			}

			EResult GetSupportedPresentationModes(DynamicArray<EPresentationMode>& _presentationModesContainer) const
			{
				return Parent::GetSupportedPresentationModes(*physicalDevice, handle, _presentationModesContainer);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const Surface& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;
			
			const AppInstance* app;

			const PhysicalDevice* physicalDevice;
		};

		/** @} */
	}
}