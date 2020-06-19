/*
Vaulted Thermals: Platform Specification

The Vulkan C-API header is included here and platform detection implementation is defined.
*/

#pragma once



#pragma region Includes

#include "_foreign/Foreign_ConventionEnforcer.hpp"


#ifdef _WIN32

	#ifndef VK_USE_PLATFORM_WIN32_KHR
	#define VK_USE_PLATFORM_WIN32_KHR 
	#endif

#endif


/*
This guard is necessary to prevent redefinition errors. I am not entirely sure with pragma once
specified, why this is required.
*/
#ifndef VULKAN_INCLUDEGUARD
#define VULKAN_INCLUDEGUARD

	#include <vulkan/vulkan.h>

#endif

#pragma endregion Includes



namespace Vulkan
{
	namespace Vault_00
	{
		/*
		Enum specifies operating system platform.
		*/
		enum class EOS_Platform
		{
			Windows, Mac, Linux
		};

		#ifdef _WIN32

			// OS Platform constant.
			constexpr EOS_Platform OS_Platform = EOS_Platform::Windows;

		#endif

		template<EOS_Platform>
		/*
		Defines maker of platform struct that defines operating system types.
		*/
		struct PlatformTypes_Maker;

		template<>
		/*
		Defines Windows specific types.
		*/
		struct PlatformTypes_Maker<EOS_Platform::Windows>
		{
			using OS_AppHandle    = HINSTANCE;
			using OS_WindowHandle = HWND;
		};

		using PlatformTypes = PlatformTypes_Maker<OS_Platform>;
	}


	// Calling Conventions

	MakeConventionEnforcer(Vulkan, VKAPI_ATTR, VKAPI_CALL);
}
