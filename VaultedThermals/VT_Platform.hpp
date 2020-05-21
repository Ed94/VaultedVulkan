#pragma once


#include "_foreign/ConventionEnforcer.hpp"



#ifdef _WIN32
	#ifndef VK_USE_PLATFORM_WIN32_KHR

		#define VK_USE_PLATFORM_WIN32_KHR 

		// I had to do it manually the vulkan header was not seeing the macro definition for some reason...
		#include <windows.h>
		#include <vulkan/vulkan_win32.h>
		
	#endif
#endif



#include <vulkan/vulkan.h>



namespace Vulkan
{
	namespace Vault__00
	{
	}

	enum class EOS_Platform
	{
		Windows, Mac, Linux
	};

	#ifdef _WIN32
		constexpr
		EOS_Platform OS_Platform = EOS_Platform::Windows;
	#endif


	// Calling Conventions

	MakeConventionEnforcer(Vulkan, VKAPI_ATTR, VKAPI_CALL);
}
