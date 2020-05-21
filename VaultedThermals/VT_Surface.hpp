/*


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
		};

		template<EOS_Platform>
		struct Surface_Maker;

		template<>
		struct Surface_Maker<EOS_Platform::Windows> : Surface_PlatformAgnostic
		{
			struct CreateInfo
			{
				using CreateFlags = bitmask<EUndefined, Flags>;

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

	typename std::enable_if< OS_Platform == EOS_Platform::Windows, Surface::CreateInfo::
	OS_AppHandle>::type GetOS_AppHandle() 
	{ 
		return GetModuleHandle(nullptr); 
	}

	typename std::enable_if< OS_Platform == EOS_Platform::Windows, 
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

	void DestroySurface(AppInstance::Handle _appHandle, Surface::Handle _surfaceHandle, const AllocationCallbacks* _allocator)
	{
		vkDestroySurfaceKHR(_appHandle, _surfaceHandle, _allocator);
	}
}
