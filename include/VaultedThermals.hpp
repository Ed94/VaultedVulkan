/*!
@file VaultedThermals.hpp

@brief VaultedThermals Include Interface

// Optional Features:

The library single include header.

Long namespace: #define VT_Option__Use_Long_Namespace

Inlining:
VT_Option__Use_Inline_Hinting
VT_Option__Use_Forced_Inlining

STL Exceptions (Note: right now the library does not STL exceptions but may in the future...):
VT_Option__Use_STL_Exceptions

Defining your own containers:

#define VT_Option__Use_Custom_Containers

using Deque        = YourContainerHere
using DynamicArray = YourCOntainerHere

Vault 4 Use:

In a cpp file, include VaultedThermals.hpp with the following way:

#define VT_V4_Setup_Implementation
#include "VaultedThermals.hpp

This will drop into your project the necessary implementation for the instantiated
*/



#pragma once

/**
@mainpage VaultedThermals

# VaultedThermals

A vulkan wrapper.

Documentation can be found here : http://edsdigitalabode.com/VaultedThermals/index.html
(Documentation is updated ussually with implementation or if not during refactoring periods)

## Benefits:
-Features a 1 : 1 wrap implementation of the Vulkan C - API (See Vault_01 implementation).
- Full in source and doxygen documentation.
- Ease of use functionality for boostrapping (See Vaults_02 / 3 / 4), but without the extra non - gpu API related clutter (Asset Loading, Camera, Entity, etc)
- Leveled abstraction namspacing and optional implementation wrapped in macros to allow easy discretion of features desired.

## State

This is currently a WIP, I am fleshing this out while making my engine project :
[Abstract Realm] (https ://github.com/Ed94/AbstractRealm)

The scope of this library is sort of outlined in the VT_Vaults.hppand VaultedThermals.hpp

Motivations for doing so is I like clean librariesand while Vulkan - Hpp looked well designed, I cannot find a proper specification or documentation related to it, only the C - API.There is only their "samples".

This library aims to have full documentation / specificaton within its comments and have clean organization.

(Its also to help me learn Vulkan as I wanted to learn a low - level GPU API)

My current intentions is to get this going as far as I like in conjunction with following various vulkan guides, and making my engine mvp.
After that is done, this will be publicly released with some sort of open source license.
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
#include "VaultedThermals/VT_SyncAndCacheControl.hpp"
#include "VaultedThermals/VT_Shaders.hpp"
#include "VaultedThermals/VT_Pipelines.hpp"
#include "VaultedThermals/VT_RenderPass.hpp"
#include "VaultedThermals/VT_Command.hpp"
#include "VaultedThermals/VT_Surface.hpp"
#include "VaultedThermals/VT_SwapChain.hpp"
#include "VaultedThermals/VT_Debug.hpp"
#include "VaultedThermals/VT_GPU_Comms.hpp"
#include "VaultedThermals/VT_GPU.hpp"
