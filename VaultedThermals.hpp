/** 
@file VaultedThermals.hpp

@brief 
VaultedThermals Include Interface
    
The library single include header.
*/



#pragma once



/**
 * @page LibraryOutline 
 * 
 * @section GuideSec Guide
 * The libraries files are organized based on the Khronos Vulkan Specification manual:
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html">Vulkan Specification</a>
 *
 * Each file Starting from the number 2 represents a chapter/category of the manual.
 * Files may have non-specification within them.
 * 
 * Content related directly to the Vulkan API will have a link to its respective specification.
 * 
 * Files that do not follow specification are labeled with an NS-# in their comment below.
 * 
 * Note: Files are in order of include, so specification modules may be slightly out of order.
 * 
 * 
 * Features that would be nice to have:
 * @todo Have support for object model enforcement.
 * 
 * @subsection OutlineSec Outline
 * 
 * ## NS-0: VT_Vaults.hpp
 * Defines the vaulting scope used for the various levels of implementation within the library.
 * 
 * ## NS-1: VT_Backend.hpp
 * NS-1: Backend related definitions for use in implementing the library. 
 * 
 * ## NS-2 VT_Platform.hpp
 * Platform detection and includes the C-API vulkan header.
 * 
 * ## 2: VT_Types.hpp
 * Fundamental Typedefs, Common Object Types, Non-Specification Types.
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals">Fundamentals Specification</a>
 * 
 * ## NS-3 VT_Enums.hpp
 * Unsorted global enum definitions.
 * 
 * ## NS-4 VT_Constants.hpp
 * Unsorted constants.
 * 
 * ## 3: VT_Initialization
 * Command function pointers, application instancing.
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">Initialization Specification</a>
 * 
 * ## 4: Devices and Queues
 * 
 * ## 4.3: 
 * Queues
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues">Queues Specification</a>
 * 
 * ## 4.1:
 * Physical Devices
 *
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Physical Device Specification</a>
 */



#include "VaultedThermals/VT_Vaults.hpp"
#include "VaultedThermals/VT_Backend.hpp"
#include "VaultedThermals/VT_Platform.hpp"
#include "VaultedThermals/VT_Types.hpp"
#include "VaultedThermals/VT_Enums.hpp"
#include "VaultedThermals/VT_Constants.hpp"
#include "VaultedThermals/VT_Initalization.hpp"
#include "VaultedThermals/VT_Queues.hpp"
#include "VaultedThermals/VT_PhysicalDevice.hpp"



#include "VaultedThermals/VT_Layer.hpp"
#include "VaultedThermals/VT_Debug.hpp"
#include "VaultedThermals/VT_PhysicalDevice.hpp"
#include "VaultedThermals/VT_LogicalDevice.hpp"
#include "VaultedThermals/VT_Surface.hpp"
#include "VaultedThermals/VT_SwapChain.hpp"
#include "VaultedThermals/VT_ImageView.hpp"
#include "VaultedThermals/VT_ShaderModule.hpp"
#include "VaultedThermals/VT_Pipeline.hpp"
