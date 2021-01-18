/*!
@file VV_Platform.hpp

@brief Vaulted Vulkan: Platform Specification

@details The Vulkan C-API header is included here and platform detection implementation is defined.
*/


#pragma once



#pragma region Includes


#ifdef _WIN32

	#ifndef VK_USE_PLATFORM_WIN32_KHR
	#define VK_USE_PLATFORM_WIN32_KHR 
	#endif

#endif

#ifdef __MACH__

	#ifdef  VK_USE_PLATFORM_MACOS_MVK
	#define VK_USE_PLATFORM_MACOS_MVK
	#endif

#endif

#ifdef __linux__
	
	#ifdef  VK_USE_PLATFORM_WAYLAND_KHR
    #define VK_USE_PLATFORM_WAYLAND_KHR
	#endif

#endif



/** 
@todo
This guard is necessary to prevent redefinition errors. I am not entirely sure with pragma once
specified, why this is required.
*/
#ifndef VV_VULKAN_INCLUDEGUARD
#define VV_VULKAN_INCLUDEGUARD

	#include <vulkan/vulkan.h>

#endif


// VT
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"


#pragma endregion Includes



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
	namespace V0
	{
		/**
		@addtogroup Vault_0
		@{
		*/

		/**
		@brief Enum specifies operating system platform.
		*/
		enum class EOS
		{
			Windows, Mac, Linux
		};

		#ifdef _WIN32

			/**
			@brief Contains the definition of the OS_Platform. (Set to windows)
			 */
			constexpr EOS OS_Platform = EOS::Windows;

		#endif

		#ifdef __MACH__

			/**
			@brief Contains the definition of the OS_Platform. (Set to Mac)
			*/
			constexpr EOS OS = EOS::Mac;

		#endif

		#ifdef __linux__

			/**
			@brief Contains the definition of the OS_Platform. (Set to Linux)
			*/
			constexpr EOS OS = EOS::Linux;

		#endif 

		/**  
		@brief Defines maker of platform struct that defines operating system types.
		*/
		template<EOS>
		struct PlatformTypes_Maker;

		template<>
		struct PlatformTypes_Maker<EOS::Linux>
		{
			using OS_Handle = int;
		};


		/** 
		@brief Defines Windows specific types.
		*/	
		template<>
		struct PlatformTypes_Maker<EOS::Windows>
		{
			using OS_AppHandle    = HINSTANCE;
			using OS_WindowHandle = HWND     ;
			using OS_Handle       = HANDLE   ;
		};

		/** 
		 * @brief A structure containing the types for the detected platform.
		 */
		using PlatformTypes = PlatformTypes_Maker<OS_Platform>;

		/** @} */

		template<typename FunctionType, FunctionType*>
		struct CallEnforcer_CallMaker;

		/**
		@brief Generates a wrapped call to the function passed to it.
		*/
		template
			<
			typename    ReturnType    ,
			typename... ParameterTypes,

			ReturnType(*FunctionPtr)(ParameterTypes...)
			>
			struct CallEnforcer_CallMaker<ReturnType(ParameterTypes...), FunctionPtr>
		{
			static VKAPI_ATTR ReturnType VKAPI_CALL Call(ParameterTypes... _parameters)
			{
				return FunctionPtr(std::forward<ParameterTypes>(_parameters)...);
			}
		};

		template<typename FunctionType, FunctionType& _functionRef>
		auto GetVulkanAPI_Call()
		{
			return &(CallEnforcer_CallMaker<FunctionType, &_functionRef>::Call);
		}

		/**
		@brief Used to wrap a function with the vulkan calling convention specifiers.
		Used for vulkan messaging callbacks.

		@details
		This is the only intended macro to be used by the user of this library.
		If the user wishes to avoid using this ease of use macro, the actual function call can be made:

		Enforced_Call<decltype(Function), Function>()
		*/
		#define GetVTAPI_Call(_FUNCTION) \
		GetVulkanAPI_Call<decltype(_FUNCTION), _FUNCTION>()
	}

	namespace Corridors
	{
		using V0::GetVulkanAPI_Call;
		using V0::OS_Platform      ;
	}
}
