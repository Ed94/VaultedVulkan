/*
@file VT_CPP_STL.hpp

@brief C++ STL related definitions
*/



#pragma once



// C++
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <typeinfo>

// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"



VT_Namespace
{
	namespace Corridors
	{
		/**
		 * @brief Vulkan's boolean type.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBool32">Specification</a> 
		 */
		using Bool = VkBool32;

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

		using uInt8  = unsigned           char;
		using uInt16 = unsigned short     int ;
		using uInt32 = unsigned long      int ;
		using uInt64 = unsigned long long int ;

		// Floats

		using float32 =      float ;
		using float64 =      double;

		// Data

		using VoidPtr  = void*  ;
		using PtrArray = void*[];

		using DataSize = std::size_t   ;
		using sIntPtr  = std::intptr_t ;
		using uIntPtr  = std::uintptr_t;

		// RawStrings

		using CStr                 = char*             ;
		using RoCStr               = const char*       ;
		using CStrArray            = CStr*             ;
		using RoCStrArray          = const char**      ;   ///< Readonly c-string array.
		using RoSCtr_roArray_Array = const char* const*;   ///< Array of readonly array of readonly c-string.
	}
}
