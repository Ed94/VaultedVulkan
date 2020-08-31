/*
@file VT_CPP_STL.hpp

@brief C++ STL related definitions
*/



#pragma once



// C++
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>

// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"



#ifndef VT_Option__Use_Long_Namespace
/**
@namespace VaultedThermals

@brief Main library namespace for Vaulted Thermals (Vulkan Wrapper)

@details For long namespace: #define VT_Option__Use_Long_Namespace
*/
namespace VT
#else
/**
@namespace VaultedThermals

@brief Main library namespace for Vaulted Thermals (Vulkan Wrapper)

@details VT_Option__Use_Long_Namespace in use.
*/
namespace VaultedThermals
#endif
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



		/** 
		* @brief Containers used for the library are defined here.
		* 
		* @details
		* 
		* If library user decides to implement their own containers they must define containers
		* that function the same as the STL containers used here with the same names.
		*/
		#ifndef VT_Option__Use_Custom_Containers

			#include <deque>
			#include <vector>

			template<class Type>
			/**
			 * @brief Typdef of std::deque.
			 */
			using Deque = std::deque<Type>;

			template<class Type>
			/**
			 * @brief Typedef of std::vector.
			 */
			using DynamicArray = std::vector<Type>;

		#endif
	}
}
