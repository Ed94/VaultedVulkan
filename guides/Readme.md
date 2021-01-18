# These are a set of walk-through guides for getting started with the library.

My rule of thumb with guides is to be as explict as possible, and try to guide through with some redundancy. For experienced programmers, this may feel too verbose, but if thats the case your most likely better off just looking at the guides source. You'll be happy to find that its just as clean as the library and filled with comments.

## Setup

### Installation CMake / Visual Studio Code

[Windows](https://github.com/Ed94/VaultedThermals/wiki/VV-Guides:-Windows-Setup)

Linux 

Mac

## Current Guides:

**[1_Intro:](https://github.com/Ed94/VaultedVulkan/tree/master/guides/1_Intro)** Learn about the guide's workspace.

**[2_ApplicationHandshake](https://github.com/Ed94/VaultedVulkan/tree/master/guides/2_ApplicationHandshake)** Setup vulkan <-> application communiction. Gather information about your machine's GPU capabilities, and learn how to setup validation the layer/s for debugging.

**TriSeed:** Get VT setup with a barebones renderer with Vault 3, showing a the classic rainbow triangle.

## UserSpace

This is a workspace area that has been setup for the library user to work on the guides with.

## Thirdparty libraries used:

[CrossWindow](https://github.com/alaingalvan/CrossWindow/tree/master): A basic cross platform system abstraction library for managing windows and performing OS tasks.

[GLM](https://github.com/g-truc/glm/tree/master): Math library popular for use with OpenGL, using at the math library for the guides.
    
## Important Note:

If you stumbled upon this library while looking for vulkan resources on github, I would recommend completing at least a few guides on the regular Vulkan C/C++ API before/after using this library. While this library aims to be a replacement for those, its not offical and should not be taken as a tool a user can get away with not learning the offical library.

### Recommended Vulkan C/C++ API Tutorials

C++ :   

[Raw Vulkan](https://alain.xyz/blog/raw-vulkan)   
This will kick start you well with the Vulkan-Hpp library. It also has some of the nicest explanations of many vulkan concepts.

C :   

[Vulkan Tutorial](https://vulkan-tutorial.com/Introduction)
This was the first tutorial I engaged with and got the job done. It goes quite in depth, I kinda wish there was a C++ equivalent for Vulkan-Hpp.   

[Intel's API without Secrets: Introduction to Vulkan](https://software.intel.com/content/www/us/en/develop/articles/api-without-secrets-introduction-to-vulkan-part-1.html)   
This one has the most depth of the ones described here. If you want details, this is the place.