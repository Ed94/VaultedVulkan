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
	namespace Corridors
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_NULL_HANDLE">Specification</a> .
		 */
		template<typename HandleType>
		constexpr HandleType Null = VK_NULL_HANDLE;

		constexpr DeviceSize MaxMemoryHeaps = VK_MAX_MEMORY_HEAPS;
		constexpr DeviceSize MaxMemoryTypes = VK_MAX_MEMORY_TYPES;

		constexpr DeviceSize QueueFamily_Ignored = VK_QUEUE_FAMILY_IGNORED;

		constexpr uint32 Subpass_External = VK_SUBPASS_EXTERNAL;

		struct QueueMask
		{
			static constexpr uint32 ComputeAsync = 
				uint32(EQueueFlag::Compute ) | 
				uint32(EQueueFlag::Transfer) |
				uint32(EQueueFlag::SparseBinding);

			static constexpr uint32 TransferOnly = uint32(EQueueFlag::Transfer) | uint32(EQueueFlag::SparseBinding);
		};

		struct InstanceExt
		{
			static constexpr RoCStr DebugUtility = VK_EXT_DEBUG_UTILS_EXTENSION_NAME  ;
			static constexpr RoCStr Surface      = VK_KHR_SURFACE_EXTENSION_NAME      ;
			static constexpr RoCStr Win32Surface = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
		};

		struct DeviceExt
		{
			static constexpr RoCStr Swapchain = VK_KHR_SWAPCHAIN_EXTENSION_NAME;	
		};

		struct Layer
		{
			static constexpr RoCStr LunarG_API_Dump         = "VK_LAYER_LUNARG_api_dump";
			static constexpr RoCStr ValidationLayer_Khronos = "VK_LAYER_KHRONOS_validation";
		};
	}
}
