/** @file VT_Surface.hpp

@brief Vaulted Thermals: Surface

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_surface">Specification</a> 
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
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_0
	{
		using Vault_1::Image;

		/**
		 * @brief Cross-Platform set of definitions for a Surface.
		 */
		struct Surface_PlatformAgnostic
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceKHR">Specification</a>  */
			using Handle = VkSurfaceKHR;   ///< Opaque handle to a surface object.

			using ETransform = ESurfaceTransformFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceTransformFlagsKHR">Specification</a>  */
			using ETransformFlags     = Bitmask<ESurfaceTransformFlag, VkSurfaceTransformFlagsKHR>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompositeAlphaFlagsKHR">Specification</a>  */
			using CompositeAlphaFlags = Bitmask<ECompositeAlpha      , VkCompositeAlphaFlagsKHR  >;

			/**
			 * @brief Structure describing capabilities of a surface.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceCapabilitiesKHR">Specification</a> 
			 */
			struct Capabilities : VKStruct_Base<VkSurfaceCapabilitiesKHR>
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
			};

			/**
			 * @brief Structure describing a supported swapchain format-color space pair.
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceFormatKHR">Specification</a> 
			 */
			struct Format : VKStruct_Base<VkSurfaceFormatKHR>
			{
				EFormat     Format    ;
				EColorSpace ColorSpace;
			};
		};

		/** @brief Used to create an OS platform's surface type. */
		template<EOS_Platform>
		struct Surface_Maker;

		/** @brief Defines a Surface's extended definitions for Windows. */
		template<>
		struct Surface_Maker<EOS_Platform::Windows> : Surface_PlatformAgnostic
		{
			//static constexpr EStructureType CreateInfoType = EStructureType::Win32_Surface_CreateInfo_KHR;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32SurfaceCreateInfoKHR">Specification</a> */
			struct CreateInfo : VKStruct_Base<VkWin32SurfaceCreateInfoKHR, EStructureType::Win32_Surface_CreateInfo_KHR>
			{
				using CreateFlags = Bitmask<EUndefined, VkWin32SurfaceCreateFlagsKHR>;   ///< Reserved for future use.

				using OS_AppHandle    = PlatformTypes::OS_AppHandle   ;
				using OS_WindowHandle = PlatformTypes::OS_WindowHandle;

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
			static CreateInfo::OS_AppHandle GetOS_AppHandle()
			{
				return GetModuleHandle(nullptr);
			}

			/**
			 * @brief Create a slink:VkSurfaceKHR object for an Win32 native window.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateWin32SurfaceKHR">Specification</a> 
			 * 
			 * \param _appHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _surfaceHandle
			 * \return 
			 */
			static EResult Create
			(
				      Vault_1::AppInstance::Handle _appHandle    ,
				      CreateInfo&                  _createInfo   ,
				const Memory::AllocationCallbacks* _allocator    ,
				      Handle&                      _surfaceHandle
			)
			{
				return EResult(vkCreateWin32SurfaceKHR(_appHandle, _createInfo.operator const VkWin32SurfaceCreateInfoKHR*(), _allocator->operator const VkAllocationCallbacks*(), &_surfaceHandle));
			}
		};

		/** @brief Surface definition for the currently detected OS platform. */
		using Surface = Surface_Maker<OS_Platform>;
	}

	namespace Vault_1
	{
		/** @brief Surfaces hook onto a window to use as a rendering target. */
		struct Surface : Vault_0::Surface
		{
			/**
			 * @brief Destroy a VkSurfaceKHR object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySurfaceKHR">Specification</a> 
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
			 * \param _physDeviceHandle
			 * \param _queueFamilyIndex
			 * \param _surfaceHandle
			 * \param _checkResult
			 * \return 
			 */
			static EResult CheckPhysicalDeviceSupport
			(
				Vault_1::PhysicalDevice::Handle _physDeviceHandle,
				uint32                          _queueFamilyIndex,
				Surface::Handle                 _surfaceHandle   ,
				Bool& _checkResult
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
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _numPresentationModes
			 * \param _presentationModesContainer
			 * \return 
			 */
			static EResult QuerySupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, uint32& _numPresentationModes, EPresentationMode* _presentationModesContainer)
			{
				return EResult(vkGetPhysicalDeviceSurfacePresentModesKHR(_deviceHandle, _surfaceHandle, &_numPresentationModes, (VkPresentModeKHR*)(_presentationModesContainer)));
			}
		};
	}

	namespace Vault_2
	{
		/** @brief Surfaces hook onto a window to use as a rendering target. */
		struct Surface : Vault_1::Surface
		{
			static bool CheckForPresentationSupport
			(
				PhysicalDevice::Handle _physicalDevice,
				Surface::Handle _surface,
				uint32 _queueIndex
			)
			{
				Bool presentationSupport = EBool::False;

				Surface::CheckPhysicalDeviceSupport(_physicalDevice, _queueIndex, _surface, presentationSupport);

				return presentationSupport;
			}

			/**
			 * @brief Provides the number of available surface formats.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \return 
			 */
			static uint32 GetNumOf_AvailableFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle)
			{
				uint32 numFormats;

				EResult&& result = GetFormats(_deviceHandle, _surfaceHandle, numFormats, nullptr);

				if (result != EResult::Success) throw std::runtime_error("Failed to get number of available formats...");

				return numFormats;
			}

			/**
			 * @brief Provides the available surface formats.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _formatsContainer
			 * \return 
			 */
			static EResult GetAvailableFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, Surface::Format* _formatsContainer)
			{
				uint32 numFormats = GetNumOf_AvailableFormats(_deviceHandle, _surfaceHandle);

				EResult&& result = GetFormats(_deviceHandle, _surfaceHandle, numFormats, _formatsContainer);

				if (result != EResult::Success) throw std::runtime_error("Failed to get available formats...");

				return result;
			}

			/**
			 * @brief Provides the number of supported presentation modes.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \return 
			 */
			static uint32 GetNumOf_SupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle)
			{
				uint32 numPresentationModes;

				EResult result =  QuerySupportedPresentationModes(_deviceHandle, _surfaceHandle, numPresentationModes, nullptr);

				if (result != EResult::Success) throw std::runtime_error("Failed to get number of supported presentation modes...");

				return numPresentationModes;
			}

			/**
			 * @brief Provides the supported presentation modes.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _presentationModesContainer
			 * \return 
			 */
			static EResult GetSupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, EPresentationMode* _presentationModesContainer)
			{
				uint32 numPresentationModes = GetNumOf_SupportedPresentationModes(_deviceHandle, _surfaceHandle);

				EResult result = QuerySupportedPresentationModes(_deviceHandle, _surfaceHandle, numPresentationModes, _presentationModesContainer);
				
				if (result != EResult::Success) throw std::runtime_error("Failed to get supported presentation modes...");

				return result;
			}
		};
	}
}
