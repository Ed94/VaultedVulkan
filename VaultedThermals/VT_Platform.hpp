/*****************************************************************//**
 * @file   VT_Platform.hpp
 * @brief  Vaulted Thermals: Platform Specification
 * 
 * @details The Vulkan C-API header is included here and platform detection implementation is defined.
 *********************************************************************/



#pragma once



#pragma region Includes


#ifdef _WIN32

	#ifndef VK_USE_PLATFORM_WIN32_KHR
	#define VK_USE_PLATFORM_WIN32_KHR 
	#endif

#endif


/** 
This guard is necessary to prevent redefinition errors. I am not entirely sure with pragma once
specified, why this is required.
*/
#ifndef VULKAN_INCLUDEGUARD
#define VULKAN_INCLUDEGUARD

	#include <vulkan/vulkan.h>

#endif


// C++
#include <stdexcept>
#include <typeinfo>

// VT
#include "_foreign/Foreign_Bitmask.hpp"
#include "_foreign/Foreign_ConventionEnforcer.hpp"

#include "VT_Vaults.hpp"


#pragma endregion Includes



namespace VaultedThermals
{
	namespace Vault_00
	{
		/** @enum EOS_Platform
			@brief Enum specifies operating system platform.
		*/
		enum class EOS_Platform
		{
			Windows, Mac, Linux
		};

		#ifdef _WIN32

			/** 
				@var OS_Platform

				@brief Contains the definition of the OS_Platform. (Set to windows)
			 */
			constexpr EOS_Platform OS_Platform = EOS_Platform::Windows;

		#endif

		/**  
		@struct PlatformTypes_Maker

		@brief Defines maker of platform struct that defines operating system types.
		*/
		template<EOS_Platform>
		struct PlatformTypes_Maker;

		/** 
		@struct PlatformTypes_Maker_WindowsImplementation

		@brief Defines Windows specific types.
		*/	
		template<>
		struct PlatformTypes_Maker<EOS_Platform::Windows>
		{
			using OS_AppHandle    = HINSTANCE;
			using OS_WindowHandle = HWND     ;
		};

		/** 
		 * @struct PlatformTypes
		 * 
		 * @brief A structure containing the types for the detected platform.
		 */
		using PlatformTypes = PlatformTypes_Maker<OS_Platform>;
	}


	/**
		@def Vulkan Convention Enforcement.

		@brief Generates the convention enforcer set for the vulkan API.
	 */
	MakeConventionEnforcer(Vulkan, VKAPI_ATTR, VKAPI_CALL);
}
