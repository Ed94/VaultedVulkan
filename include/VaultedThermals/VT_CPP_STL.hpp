/*!
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
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace Corridors
	{
		/**
		@addtogroup Corridors
		@{
		*/

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

		using float32 = float ;
		using float64 = double;

		// Data

		using VoidPtr  = void*  ;
		using PtrArray = void*[];

		using WordSize = std::size_t   ;
		using sIntPtr  = std::intptr_t ;
		using uIntPtr  = std::uintptr_t;

		// RawStrings

		using CStr              =       char*       ;
		using RoCStr            = const char*       ;
		using CStrArray         =       char*      *;
		using RoCStrArray       = const char*      *;   ///< Readonly c-string array.
		using RoArray_of_RoCStr = const char* const*;   ///< Array of readonly array of readonly c-string.



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

		/** @} */
	}
}
