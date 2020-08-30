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
@todo
This guard is necessary to prevent redefinition errors. I am not entirely sure with pragma once
specified, why this is required.
*/
#ifndef VT_VULKAN_INCLUDEGUARD
#define VT_VULKAN_INCLUDEGUARD

	#include <vulkan/vulkan.h>

#endif

// Foreign Objects: These are helper functionality I defined but are not directly related to the Vaulted Thermals Library.
// They are however needed by the Library in order to function.
#include "_foreign/Foreign_Bitmask.hpp"
#include "_foreign/Foreign_ConventionEnforcer.hpp"

// VT
#include "VT_Vaults.hpp"


#pragma endregion Includes



#ifdef VT_Option__Use_Long_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V0
	{
		/** @enum EOS_Platform
			@brief Enum specifies operating system platform.
		*/
		enum class EOS_Platform
		{
			Windows, Mac, Linux
		};

		#ifdef _WIN32

			/** @var OS_Platform

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

		@details
		EnforceConvention(EnforcerID_Vulkan, _functionName) will wrap a function call with the proper calling conventions for the vulkan api.
	 */
	MakeConventionEnforcer(Vulkan, VKAPI_ATTR, VKAPI_CALL)
}
