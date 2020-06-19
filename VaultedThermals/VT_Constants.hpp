/*
Vaulted Thermals: Constants
*/



#pragma once



#include "VT_Platform.hpp"
#include "VT_Types.hpp"



namespace Vulkan
{
	//TODO: Move constants based on specification to their respective file if possible.
	namespace Vault_01
	{
		constexpr RoCStr ValidationLayer_Khronos = "VK_LAYER_KHRONOS_validation"  ;
		constexpr RoCStr Swapchain_ExtensionName = VK_KHR_SWAPCHAIN_EXTENSION_NAME;

		constexpr sint32 Description_MaxSize   = VK_MAX_DESCRIPTION_SIZE   ;
		constexpr sint32 ExtensionName_MaxSize = VK_MAX_EXTENSION_NAME_SIZE;

		constexpr void* NullHandle = VK_NULL_HANDLE;

		constexpr sint32 PhysicalDevice_MaxNameSize = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;

		constexpr sint32 UUID_Size = VK_UUID_SIZE;
	}
}
