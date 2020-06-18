/*

Note: Review this... seems like some of it at least needs to be moved to physical device.
*/


#pragma once




#include "VT_Platform.hpp"
#include "VT_Constants.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"



namespace Vulkan
{
	namespace Vault_00
	{
		struct Surface_PlatformAgnostic
		{
			using Handle = VkSurfaceKHR;

			using ESurfacTransformFlags = Bitmask<ESurfaceTransform, Flags>;
			using CompositeAlphaFlags   = Bitmask<ECompositeAlpha  , Flags>;

			struct Capabilities
			{
				uint32                MinImageCount          ;
				uint32                MaxImageCount          ;
				Extent2D              CurrentExtent          ;
				Extent2D              MinImageExtent         ;
				Extent2D              MaxImageExtent         ;
				uint32                MaxImageArrayLayers    ;
				ESurfacTransformFlags SupportedTransforms    ;
				ESurfaceTransform     CurrentTransform       ;
				CompositeAlphaFlags   SupportedCompositeAlpha;
				ImageUsageFlags       SupportedUsageFlags    ;

				operator VkSurfaceCapabilitiesKHR()
				{
					return *(VkSurfaceCapabilitiesKHR*)(this);
				}
			};

			struct Format
			{
				EImageFormat Format    ;
				EColorSpace  ColorSpace;

				operator VkSurfaceFormatKHR()
				{
					return *(VkSurfaceFormatKHR*)(this);
				}
			};
		};

		template<EOS_Platform>
		struct Surface_Maker;

		template<>
		struct Surface_Maker<EOS_Platform::Windows> : Surface_PlatformAgnostic
		{
			struct CreateInfo
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				using OS_AppHandle    = PlatformTypes::OS_AppHandle   ;
				using OS_WindowHandle = PlatformTypes::OS_WindowHandle;

				EStructureType                  SType      ;
				const void*                     Extension  ;
				VkWin32SurfaceCreateFlagsKHR    Flags      ;
				OS_AppHandle                    OSAppHandle;
				OS_WindowHandle                 OSWinHandle;
			};
		};

		using Surface = Surface_Maker<OS_Platform>;
	}

	using Surface = Vault_00::Surface_Maker<OS_Platform>;

	constexpr typename std::enable_if< OS_Platform == EOS_Platform::Windows, 
	EStructureType>::type OS_SurfaceCreateInfoEnum = EStructureType::VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;

	inline typename std::enable_if< OS_Platform == EOS_Platform::Windows, Surface::CreateInfo::
	OS_AppHandle>::type GetOS_AppHandle() 
	{ 
		return GetModuleHandle(nullptr); 
	}

	inline typename std::enable_if< OS_Platform == EOS_Platform::Windows, 
	EResult>::type  CreateSurface
	(
		AppInstance::Handle        _appHandle, 
		Surface::CreateInfo&       _createInfo, 
		const AllocationCallbacks* _allocator,
		Surface::Handle&           _surfaceHandle
	)
	{
		return EResult(vkCreateWin32SurfaceKHR(_appHandle, (VkWin32SurfaceCreateInfoKHR*)(&_createInfo), _allocator, &_surfaceHandle));
	}

	inline void DestroySurface(AppInstance::Handle _appHandle, Surface::Handle _surfaceHandle, const AllocationCallbacks* _allocator)
	{
		vkDestroySurfaceKHR(_appHandle, _surfaceHandle, _allocator);
	}

	inline EResult Surface_CheckPhysicalDeviceSupport
	(
		PhysicalDevice::Handle _physDeviceHandle,
		uint32 _queueFamilyIndex,
		Surface::Handle _surfaceHandle,
		Bool& _checkResult
	)
	{
		return EResult(vkGetPhysicalDeviceSurfaceSupportKHR(_physDeviceHandle, _queueFamilyIndex, _surfaceHandle, &_checkResult));
	}

	inline EResult Surface_GetPhysicalDeviceCapabilities(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surface, Surface::Capabilities& _capabilitiesResult)
	{
		return EResult( vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_deviceHandle, _surface, (VkSurfaceCapabilitiesKHR*)(&_capabilitiesResult) ));
	}

	inline uint32 Surface_GetNumOf_AvailableFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle)
	{
		uint32 numFormats;

		vkGetPhysicalDeviceSurfaceFormatsKHR(_deviceHandle, _surfaceHandle, &numFormats, nullptr);

		return numFormats;
	}

	inline EResult Surface_GetAvailableFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, Surface::Format* _formatsContainer)
	{
		uint32 numFormats;

		vkGetPhysicalDeviceSurfaceFormatsKHR(_deviceHandle, _surfaceHandle, &numFormats, nullptr);

		return EResult( vkGetPhysicalDeviceSurfaceFormatsKHR(_deviceHandle, _surfaceHandle, &numFormats, (VkSurfaceFormatKHR*)(_formatsContainer)) );
	}

	inline uint32 Surface_GetNumOf_SupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle)
	{
		uint32 numPresentationModes;

		vkGetPhysicalDeviceSurfacePresentModesKHR(_deviceHandle, _surfaceHandle, &numPresentationModes, nullptr);

		return numPresentationModes;
	}

	inline EResult Surface_GetSupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, EPresentationMode* _presentationModesContainer)
	{
		uint32 numPresentationModes;

		vkGetPhysicalDeviceSurfacePresentModesKHR(_deviceHandle, _surfaceHandle, &numPresentationModes, nullptr);

		return EResult( vkGetPhysicalDeviceSurfacePresentModesKHR(_deviceHandle, _surfaceHandle, &numPresentationModes, (VkPresentModeKHR*)_presentationModesContainer) );
	}
}
