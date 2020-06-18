#pragma once


#include "_foreign/ConventionEnforcer.hpp"



#ifdef _WIN32
	#ifndef VK_USE_PLATFORM_WIN32_KHR
	#define VK_USE_PLATFORM_WIN32_KHR 
	#endif
#endif

#ifndef VULKAN_BSGUARD
#define VULKAN_BSGUARD
#include <vulkan/vulkan.h>
#endif



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
