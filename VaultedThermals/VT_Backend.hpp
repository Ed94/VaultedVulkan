/** @file VT_Backend.hpp

@brief Vaulted Thermals: Backend

@details Contains implementation related to library backend.
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"


#ifdef VT_Option__Use_Long_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V0
	{
		#ifdef VT_Option__Use_STL_Exceptions
			constexpr bool UseSTL_Exceptions = true;
		#else
			constexpr bool UseSTL_exceptions = false;
		#endif

		#ifdef VT_Option__Use_Inline_Hinting
			#define VT_InlineSpecifier inline
		#elif VT_Option__Use_Forced_Inlining
			#ifdef _WIN32
				#define VT_InlineSpecifier __forceinline
			#else
				#define VT_InlineSpecifier 
			#endif
		#else
			#define VT_InlineSpecifier 
		#endif

		/** @brief Determines whether to return an result code for a function based on if STL exceptions are enabled. */
		using ShouldUse_EResult = typename std::conditional<V0::UseSTL_Exceptions, void, EResult>::type;

		template<typename Type>
		/**
		 * @brief A custom dynamic container from the default can be used with specific functionality in the library.
		 * 
		 * @details Have a container that supports the following functions (They are equivalent to those used in std::vector)
		 * 
		 * @todo Add support?
		 */
		class IDynamicArray
		{
		public:
			~IDynamicArray() {};

			virtual Type at(DataSize _index) = NULL;

			virtual Type data() = NULL;

			virtual void push_back() = NULL;

			virtual void resize(DataSize _size) = NULL;

			virtual DataSize size() = NULL;
		};

	
		/** @struct VKStruct_Base

			@brief Base struct for wrapping Vulkan native C API Structs.

			@details 
		*/
		template<typename VulkanType, EStructureType TemplateSpecifiedStype = EStructureType::Max_Enum>
		struct VKStruct_Base
		{
			/**
			 * @typedef EType
			 * 
			 * @brief Defines the EType enum to the default vkStructureType enum for now.
			 * 
			 * @todo Finish the proper enum...
			 */
			using EType = EStructureType;

			/** @brief Keeps track of the structure type enum for a native vulkan struct (If an enum does not exist Max_Enum is used instead) */
			static constexpr EType STypeEnum = TemplateSpecifiedStype;
			
			/** 
			@typdef VkType 
			
			@brief Keeps record of the struct's inherent vulkan equivalent.
			*/
			using VkType = VulkanType;   

			/*operator VulkanType()
			{
				return *reinterpret_cast<VulkanType*>(this);
			}*/

			/*operator const VulkanType&()
			{
				return *reinterpret_cast<VulkanType*>(this);
			}*/

			operator VulkanType*()
			{
				return reinterpret_cast<VulkanType*>(this);
			}

			operator const VulkanType*() const
			{
				return reinterpret_cast<const VulkanType*>(this);
			}
		};
	}
}
