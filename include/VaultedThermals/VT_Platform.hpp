/*!
@file VT_Platform.hpp

@brief Vaulted Thermals: Platform Specification

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
#ifndef VT_VULKAN_INCLUDEGUARD
#define VT_VULKAN_INCLUDEGUARD

	#include <vulkan/vulkan.h>

#endif


// VT
#include "VT_Vaults.hpp"


#pragma endregion Includes



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V0
	{
		/**
		@addtogroup Vault_0
		@{
		*/

		/** @enum EOS_Platform
			@brief Enum specifies operating system platform.
		*/
		enum class EOS
		{
			Windows, Mac, Linux
		};

		#ifdef _WIN32

			/** @var OS_Platform

				@brief Contains the definition of the OS_Platform. (Set to windows)
			 */
			constexpr EOS OS_Platform = EOS::Windows;

		#endif

		#ifdef __MACH__

			/** @var OS_Platform

			@brief Contains the definition of the OS_Platform. (Set to Mac)
			*/
			constexpr EOS OS = EOS::Mac;

		#endif

		#ifdef __linux__

			/** @var OS_Platform

			@brief Contains the definition of the OS_Platform. (Set to Linux)
			*/
			constexpr EOS OS = EOS::Linux;

		#endif 

		/**  
		@struct PlatformTypes_Maker

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
		@struct PlatformTypes_Maker_WindowsImplementation

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
		 * @struct PlatformTypes
		 * 
		 * @brief A structure containing the types for the detected platform.
		 */
		using PlatformTypes = PlatformTypes_Maker<OS_Platform>;

		/** @} */
	}

	namespace Corridors
	{
		using V0::OS_Platform;
	}


/**
@addtogroup Vault_0
@{
*/

#ifndef CALLING_CONVENTION_ENFORCER_H
#define CALLING_CONVENTION_ENFORCER_H


	template <class ID>
	struct CallEnforcementSet;

	#define MakeCallEnforcer_ConventionID(__API_NAME) \
	class CallEnforcerID_##__API_NAME;

	#define MakeCallEnforcer_EnforcementSet(__API_NAME, __ATTRIBUTE, __CALL)         \
	template<>                                                                       \
	struct CallEnforcementSet<CallEnforcerID_##__API_NAME>                           \
	{                                                                                \
		template<typename FunctionType, FunctionType*>                               \
		struct CallEnforcer_CallMaker;                                               \
		                                                                             \
		template                                                                     \
		<                                                                            \
			typename    ReturnType    ,                                              \
			typename... ParameterTypes,                                              \
			ReturnType(*FunctionType)(ParameterTypes...)                             \
		>                                                                            \
		struct CallEnforcer_CallMaker<ReturnType(ParameterTypes...), FunctionType>   \
		{                                                                            \
			static __ATTRIBUTE ReturnType __CALL Call(ParameterTypes... _parameters) \
			{                                                                        \
				return FunctionType(std::forward<ParameterTypes>(_parameters)...);   \
			}                                                                        \
		};                                                                           \
	};

	#define MakeCallEnforcer(__API_NAME, __ATTRIBUTE, __CALL)        \
	MakeCallEnforcer_ConventionID(__API_NAME);                       \
	MakeCallEnforcer_EnforcementSet(__API_NAME, __ATTRIBUTE, __CALL);

	template
	<
		class    ID          ,
		typename FunctionType,

		FunctionType& _functionRef
	>
	auto Enforced_Call()
	{
		return &(CallEnforcementSet<ID>::template CallEnforcer_CallMaker<FunctionType, &_functionRef>::Call);
	};

	/*
	Ease of use macro to call the Enforcer_Caller for the defined API convention.
	*/
	#define EnforceCallingConvention(__API_NAME, __FUNCTION)      \
	Enforced_Call<__API_NAME, decltype(__FUNCTION), __FUNCTION>()

#endif

	/**
	@def Vulkan Convention Enforcement.

	@brief Generates the convention enforcer set for the vulkan API.

	@details
	EnforceConvention(EnforcerID_Vulkan, _functionName) will wrap a function call with the proper calling conventions for the Vulkan API.
	*/
	MakeCallEnforcer(Vulkan, VKAPI_ATTR, VKAPI_CALL)

	/**
	@brief Used to wrap a function with the vulkan calling convention specifiers.
	Used for vulkan messaging callbacks.

	@details
	This is the only intended macro to be used by the user of this library.
	If the user wishes to avoid using this ease of use macro, the actual function call can be made:

	Enforced_Call<CallEnforcerID_Vulkan, decltype(Function), Function>()
	*/
	#define EnforceVulkanCallingConvention(_FUNCTION) \
	EnforceCallingConvention(CallEnforcerID_Vulkan, _FUNCTION)

	/** @} */
}
