/*

*/



#pragma once



#include <cstddef>
#include <cstdint>

#include "VT_Platform.hpp"
#include "VT_Constants.hpp"



namespace Vulkan
{
	// Integers

	// Flexible

	using uint32 = unsigned int;
	using sint32 = signed   int;


	// Strict

	// Signed
	using sInt8  = signed           char;
	using sInt16 = signed short     int ;
	using sInt32 = signed long      int ;
	using sInt64 = signed long long int ;

	// Unsigned

	using uInt8  = unsigned            char;
	using uInt16 = unsigned short      int ;
	using uInt32 = unsigned long       int ;
	using uInt64 = unsigned long long  int ;

	// Floats

	using float32 =      float ;
	using float64 =      double;

	// Data

	using DataSize = std::size_t   ;
	using sIntPtr  = std::intptr_t ;
	using uIntPtr  = std::uintptr_t;

	using CStr = char*;

	using RoCStr = const char*;

	using CStrArray = CStr*;

	using RoCStrArray = const char**;   // Readonly c-string array.

	using RoSCtr_roArray_Array = const char* const*;   // Array of readonly array of readonly c-string.

	using Bool = VkBool32;

	using Flags         = VkFlags     ;
	using RawQueueFlags = VkQueueFlags;

	using QueueFlags = bitmask<EQueueFlags, RawQueueFlags>;

	using CallbackDataFlags = bitmask<EUndefined, Flags>;

	using ExtensionNameStr = char[ExtensionName_MaxSize];
	using DescrptionStr    = char[Description_MaxSize  ];	
	
	template<typename ReturnType, typename... ParameterTypes>
	// Vulkan Function Pointer
	using VK_FPtr = ReturnType(VKAPI_PTR*)(ParameterTypes...);

	// Equivalent to VK_FPtr<void, void>.
	using FPtr_Void = PFN_vkVoidFunction;

	// Will most likely make a class wrap, doing this for now...
	using AllocationCallbacks = VkAllocationCallbacks;

	using FPtr_CreateMessenger = PFN_vkCreateDebugUtilsMessengerEXT;

	struct Extent3D
	{
		uint32_t    Width;
		uint32_t    Height;
		uint32_t    Depth;

		operator VkExtent3D()
		{
			return *(VkExtent3D*)(this);
		}
	};


	namespace Vault_00
	{
		template<EOS_Platform>
		struct PlatformTypes_Maker;

		template<>
		struct PlatformTypes_Maker<EOS_Platform::Windows>
		{
			using OS_AppHandle    = HINSTANCE;
			using OS_WindowHandle = HWND     ;
		};

		using PlatformTypes = PlatformTypes_Maker<OS_Platform>;
	}

	using PlatformTypes = Vault_00::PlatformTypes;
}
