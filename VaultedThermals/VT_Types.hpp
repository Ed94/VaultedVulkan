/*

*/



#pragma once



#include <vulkan/vulkan.h>


#include <cstdint>


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



	using Bool = VkBool32;

	using Flags = VkFlags;


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
}
