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
 * Files that do not follow specification are labeled with an NS-#.
 * Files that are for platform extended functionality are labeled with EX-#.
 * 
 * Note: Files are in order of include, so specification modules may be slightly out of order.
 * 
 * 
 * Features that would be nice to have:
 * @todo Have support for object model enforcement.
 * 
 * @subsection OutlineSec Outline
 * 
 * ## NS-1: VT_Vaults.hpp
 * Defines the vaulting scope used for the various levels of implementation within the library.
 * 
 * 
 * ## NS-2: VT_Platform.hpp
 * Platform detection and includes the C-API vulkan header.
 * 
 * ## NS-3: VT_Backend.hpp
 * NS-1: Backend related definitions for use in implementing the library.
 * 
 * ## 2: Fundamentals
 * ### VT_Types.hpp
 * Fundamental Typedefs, Common Object Types, Non-Specification Types.
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals">Fundamentals Specification</a>
 * 
 * ## NS-4: VT_Enums.hpp
 * Unsorted global enum definitions.
 * 
 * ## NS-5: VT_Constants.hpp
 * Unsorted constants.
 * 
 * ## 3: Initialization
 * ### VT_Initialization.hpp
 * Command function pointers, application instancing.
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">Initialization Specification</a>
 * 
 * ## 4: Devices and Queues
 * 
 * ### 4.3: VT_Queues.hpp
 * Queues
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues">Queues Specification</a>
 * 
 * ### 4.1: VT_PhysicalDevice.hpp
 * Physical Device
 *
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Physical Device Specification</a>
 * 
 * ### 4.2 : VT_LogicalDevice.hpp
 * Logical Device
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#devsandqueues-devices">Logical Device Specification</a> 
 * 
 * ## 11: Resource Creation
 * 
 * ### 11.1-5: VT_Resource.hpp
 * Buffers, Buffer Views, Images, Image Layouts, Image Views
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#resources">Resource Specification</a> 
 *
 * ## 7 Render Pass
 * ### VT_RenderPass.hpp
 * Render Pass Creation, Compatibility, FrameBuffers
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#renderpass">Specification</a> 
 * 
 * ## 5 Command Buffers
 * ### VT_CommandBuffers.hpp
 * Command Buffer Lifecycle, 
 * Pools, 
 * Buffer Allocation and Management, 
 * Recording, 
 * Submission, 
 * Queue Forward Progress, 
 * Secondary Command Buffer Execution, 
 * RenderPass Commands
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#commandbuffers">Specification</a> 
 * 
 * ## EX-1: Window Surface 
 * ### VT_Surface.hpp
 * 
 * <a href="https://vulkan-tutorial.com/Drawing_a_triangle/Presentation/Window_surface">Surface Guide (From tutorial due to lack of specification)</a> 
 * 
 * ## EX-2: Swap Chain
 * ###VT_SwapChain.hpp
 * 
 * <a href="https://vulkan-tutorial.com/Drawing_a_triangle/Presentation/Swap_chain">Guide (No Specification...)</a>  
 */



#include "VaultedThermals/VT_Vaults.hpp"
#include "VaultedThermals/VT_Backend.hpp"
#include "VaultedThermals/VT_Platform.hpp"
#include "VaultedThermals/VT_Types.hpp"
#include "VaultedThermals/VT_Enums.hpp"
#include "VaultedThermals/VT_Constants.hpp"
#include "VaultedThermals/VT_Initialization.hpp"
#include "VaultedThermals/VT_Queues.hpp"
#include "VaultedThermals/VT_PhysicalDevice.hpp"
#include "VaultedThermals/VT_LogicalDevice.hpp"
#include "VaultedThermals/VT_Resource.hpp"
#include "VaultedThermals/VT_Surface.hpp"
#include "VaultedThermals/VT_SwapChain.hpp"
