/*!
@file VaultedVulkan.hpp

@brief VaultedVulkan Include Interface

// Optional Features:

The library single include header.

Long namespace: #define VV_Option__Use_Long_Namespace

Inlining:
VV_Option__Use_Inline_Hinting
VV_Option__Use_Forced_Inlining

STL Exceptions (Note: right now the library does not STL exceptions but may in the future...):
VV_Option__Use_STL_Exceptions

Defining your own containers:

#define VV_Option__Use_Custom_Containers

using Deque        = YourContainerHere
using DynamicArray = YourContainerHere

Vault 4 Use:

In a hpp file, include VaultedVulkan.hpp with this macro definition defined:
#define VT_Open_Vault_4

This will include all V4 header implementation.

In a cpp file, include VaultedVulkan.hpp with this macro definition defined:
#define VT_V4_Setup_Implementation

This will include all V4 object implementation.
*/



#pragma once



/**
@mainpage VaultedVulkan

# VaultedVulkan
A vulkan wrapper. 

https://github.com/Ed94/VaultedThermals

Documentation can be found here: http://edsdigitalabode.com/VaultedVulkan/index.html
(Documentation is updated usually with implementation or if not during refactoring periods)

## Benefits:
- Features a 1:1 wrap implementation of the Vulkan C-API. (See Vault_01 implementation) [Note: Work in progress, the entire API has not be wrapped as of yet.
- Vulkan API Structures auto set thier VkStructureType and have other default member initalization + operators for equality comparison.
- Typesafe bitmasks inspired by Jonathan's typesafe library.
- Ease of use functionality for bootstrapping (See Vaults_02/3/4), but without the extra non-gpu API related clutter (Asset Loading, Camera, Entity, etc)
- Leveled abstraction namespacing and optional implementation wrapped in macros to allow easy discretion of features desired.
- Full doxygen documentation presented nicely in a nice web format thanks to ModernC++Starter.
- Handwritten.

## State
WIP. See milestones / projects tab.

Currently the library can be used to bootstrap a vulkan backend, however a good amount of the C-API has not been wrapped.

My current intentions is to get this going as far as I like in conjunction with following various vulkan guides, and making my engine mvp. 
After that is done, this will be publicly released with some sort of open source license.

## Guides

Head on over to https://github.com/Ed94/VaultedVulkan/tree/master/guides to get started.
*/



/**
@page LibraryOutline 

@section GuideSec Guide

The libraries files are organized based on the Khronos Vulkan Specification manual:
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html">Vulkan Specification</a>

While files are organized based on specification they do not strictly follow it entirely.

If its desired to view the content of the library in adherence to the organization of the official specification,
see the module: VulkanAPI_Specification.

Implementation directly related (1:1) to the Vulkan API will have a link to its respective specification.
 
Features that would be nice to have:
@todo Have support for object model enforcement.
*/



#include "VaultedVulkan/VV_Vaults.hpp"
#include "VaultedVulkan/VV_APISpecGroups.hpp"
#include "VaultedVulkan/VV_Platform.hpp"
#include "VaultedVulkan/VV_CPP_STL.hpp"
#include "VaultedVulkan/VV_Enums.hpp"
#include "VaultedVulkan/VV_Backend.hpp"
#include "VaultedVulkan/VV_Types.hpp"
#include "VaultedVulkan/VV_Constants.hpp"
#include "VaultedVulkan/VV_Memory_Backend.hpp"
#include "VaultedVulkan/VV_PhysicalDevice.hpp"
#include "VaultedVulkan/VV_Initialization.hpp"
#include "VaultedVulkan/VV_LogicalDevice.hpp"
#include "VaultedVulkan/VV_Memory.hpp"
#include "VaultedVulkan/VV_Sampler.hpp"
#include "VaultedVulkan/VV_Resource.hpp"
#include "VaultedVulkan/VV_SyncAndCacheControl.hpp"
#include "VaultedVulkan/VV_Shaders.hpp"
#include "VaultedVulkan/VV_Pipelines.hpp"
#include "VaultedVulkan/VV_RenderPass.hpp"
#include "VaultedVulkan/VV_Command.hpp"
#include "VaultedVulkan/VV_Surface.hpp"
#include "VaultedVulkan/VV_SwapChain.hpp"
#include "VaultedVulkan/VV_Debug.hpp"



#ifdef VV_Open_Vault_4

	#include "VaultedVulkan/VVGPU_Comms.hpp"
	#include "VaultedVulkan/VVGPU_Comms_Implementation.hpp"

	#include "VaultedVulkan/VVGPU_Renderer.hpp"

#endif
