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



namespace VaultedThermals
{
	//TODO: Move constants based on specification to their respective file if possible.
	namespace Corridors
	{
		constexpr RoCStr ValidationLayer_Khronos = "VK_LAYER_KHRONOS_validation"  ;
		constexpr RoCStr Swapchain_ExtensionName = VK_KHR_SWAPCHAIN_EXTENSION_NAME;

		constexpr void* NullHandle = VK_NULL_HANDLE;
	}
}
