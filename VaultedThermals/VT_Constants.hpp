/** 
@file VT_Constants.hpp

@brief Vaulted Thermals: Constants
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_0
	{
	#ifdef VT_Option__Use_STL_Exceptions
		constexpr bool UseSTL_Exceptions = true;
	#else
		constexpr bool UseSTL_exceptions = false;
	#endif
	}

	namespace Corridors
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_NULL_HANDLE">Specification</a> .
		 */
		constexpr void* NullHandle = VK_NULL_HANDLE;

		constexpr DeviceSize MaxMemoryHeaps = VK_MAX_MEMORY_HEAPS;
		constexpr DeviceSize MaxMemoryTypes = VK_MAX_MEMORY_TYPES;

		constexpr RoCStr Swapchain_ExtensionName = VK_KHR_SWAPCHAIN_EXTENSION_NAME;
		constexpr RoCStr ValidationLayer_Khronos = "VK_LAYER_KHRONOS_validation"  ;

		constexpr DeviceSize QueueFamily_Ignored = VK_QUEUE_FAMILY_IGNORED;
	}
}
