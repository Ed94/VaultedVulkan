/** 
@file VaultedThermals.hpp

@brief 
VaultedThermals Include Interface
    
The library single include header.

If you want to use the short namespace: #define VT_Option__Use_Short_Namespace
Short Namespace: VT
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
 * Files that do not follow specification are labeled with an NS-#.
 * Files that are for platform extended functionality are labeled with EX-#.
 * 
 * Note: Files are in order of include, so specification modules may be slightly out of order. 
 * Files may also contain more than one specification module as the modules have concepts bleed to 
 * different modules based on the desired context of their description.
 * (If a submodule is within a different module file, it will be noted, 
 * [right now due to state of progress it may not be, please use the class hierarchy's to help find them] )
 * 
 * Features that would be nice to have:
 * @todo Have support for object model enforcement.
 * 
 * @subsection OutlineSec Outline
 * 
 * ## NS-1: VT_Vaults.hpp
 * Defines the vaulting scope used for the various levels of implementation within the library.
 * 
 * ## NS-2: VT_Platform.hpp
 * Platform detection and includes the C-API vulkan header.
 * 
 * * ## NS-3: Unsorted global enum definitions. 
 * ### VT_Enums.hpp
 * 
 * ## NS-4: VT_Backend.hpp
 * NS-1: Backend related definitions for use in implementing the library.
 * 
 * ## 2: Fundamentals
 * ### VT_Types.hpp
 * Fundamental Typedefs, Common Object Types, Non-Specification Types.
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals">Fundamentals Specification</a>
  
 * ## NS-5: Unsorted global enum definitions.
 * ### VT_Constants.hpp
 * 
 * ## 3: Initialization
 * ### VT_Initialization.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">Initialization Specification</a>
 * 
 * ## 4: Devices and Queues
 * 
 * ### 4.1: Physical Device 
 * #### VT_PhysicalDevice.hpp
 * Contains: 4.3 QueueFamilies
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues">Queues Specification</a>
 *
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Physical Device Specification</a>
 * 
 * ### 4.2 : Logical Device
 * #### VT_LogicalDevice.hpp
 * Contains: 4.3 Queues
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues">Queues Specification</a>
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Logical Device Specification</a> 
 * 
 * ## 11: Resource Creation
 * ### 11.1-5: VT_Resource.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources">Resource Specification</a> 
 *
 * ## 7 Render Pass
 * ### VT_RenderPass.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
 * 
 * ## 8 Shaders
 * ### VT_Shaders.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shaders">Specification</a>  
 * 
 * ## 9 Pipelines
 * ### VT_Pipelines.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
 * 
 * ## 5 Command Buffers
 * ### VT_Command.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
 * 
 * ## EX-1: Window Surface 
 * ### VT_Surface.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_surface">Specification</a> 
 * 
 * ## EX-2: Swap Chain
 * ###VT_SwapChain.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_swapchain">Specification</a>  
 */



#include "VaultedThermals/VT_Vaults.hpp"
#include "VaultedThermals/VT_Platform.hpp"
#include "VaultedThermals/VT_CPP_STL.hpp"
#include "VaultedThermals/VT_Enums.hpp"
#include "VaultedThermals/VT_Backend.hpp"
#include "VaultedThermals/VT_Types.hpp"
#include "VaultedThermals/VT_Constants.hpp"
#include "VaultedThermals/VT_Memory_Backend.hpp"
#include "VaultedThermals/VT_PhysicalDevice.hpp"
#include "VaultedThermals/VT_Initialization.hpp"
#include "VaultedThermals/VT_LogicalDevice.hpp"
#include "VaultedThermals/VT_Memory.hpp"
#include "VaultedThermals/VT_Sampler.hpp"
#include "VaultedThermals/VT_Resource.hpp"
#include "VaultedThermals/VT_RenderPass.hpp"
#include "VaultedThermals/VT_Shaders.hpp"
#include "VaultedThermals/VT_Pipelines.hpp"
#include "VaultedThermals/VT_Surface.hpp"
#include "VaultedThermals/VT_SwapChain.hpp"
#include "VaultedThermals/VT_Debug.hpp"