/** 
@file VaultedThermals.hpp

VaultedThermals Include Interface



@brief
{
	This header acts as a table of contents for the library.

	The libraries files are organized based on the Khronos Vulkan Specification manual:
	https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html
}

@details
{
	Each file Starting from the number 2 represents a chapter/category of the manual.
	Files may have non-specification within them.

	Content related directly to the Vulkan API will have a link to its respective specification.

	Files that do not follow specification are labeled with an NS-# in their comment below.

	Features that would be nice to have:
	Have support for object model enforcement. 
}
*/



#pragma once




/**
 * @addtogroup LibraryOutline
 * @{
 * 
 */



/** NS-0: Defines the vaulting scope used for the various levels of implementation within the library.
*/ 
#include "VaultedThermals/VT_Vaults.hpp"

/** NS-1: Backend related definitions for use in implementing the library.
*/
#include "VaultedThermals/VT_Backend.hpp"

// NS-2: Platform detection and includes the C-API vulkan header.
#include "VaultedThermals/VT_Platform.hpp"

/* 2: Fundamental Typedefs, Common Object Types, Non-Specification Types.

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals
*/
#include "VaultedThermals/VT_Types.hpp"

// NS-3: Unsorted global enum definitions.
#include "VaultedThermals/VT_Enums.hpp"

// NS-4: Unsorted constants.
#include "VaultedThermals/VT_Constants.hpp"

/* 3: Command function pointers, application instancing.

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization
*/
#include "VaultedThermals/VT_Initalization.hpp"

// 4: Devices and Queues https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues

/* 4.3. Queues 

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues
*/
#include "VaultedThermals/VT_Queues.hpp"

/* 4.1. Physical Devices 

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration
*/
#include "VaultedThermals/VT_PhysicalDevice.hpp"



/**
 * @}
 * .
 */



#include "VaultedThermals/VT_Layer.hpp"
#include "VaultedThermals/VT_Debug.hpp"
#include "VaultedThermals/VT_PhysicalDevice.hpp"
#include "VaultedThermals/VT_LogicalDevice.hpp"
#include "VaultedThermals/VT_Surface.hpp"
#include "VaultedThermals/VT_SwapChain.hpp"
#include "VaultedThermals/VT_ImageView.hpp"
#include "VaultedThermals/VT_ShaderModule.hpp"
#include "VaultedThermals/VT_Pipeline.hpp"
