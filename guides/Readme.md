# These are a set of walk-through guides for getting started with the library.

## Current Guides:

**Hello Triangle Seed:** Get VT setup with a barebones renderer with Vault 3, showing a the classic rainbow triangle.

## UserSpace

This is a workspace area that has been setup for the library user to work on the guides with.

## Setup

### Installation CMake / Visual Studio Code

[Windows](https://github.com/Ed94/VaultedThermals/wiki/VT-Guides:-WIndows-Setup)

Linux 

Mac

## Thirdparty libraries used:

[CrossWindow](https://github.com/alaingalvan/CrossWindow/tree/master): A basic cross platform system abstraction library for managing windows and performing OS tasks.

[GLM](https://github.com/g-truc/glm/tree/master): Math library popular for use with OpenGL, using at the math library for the guides.
    
## Important Note:

If you stumbled upon this library while looking for vulkan resources on github, I would recommend completing at least a few guides on the regular Vulkan C/C++ API before using this library. While this library aims to be a replacement for those, its not offical and should not be taken as a tool a user can get away with not learning the offical library.

### Recommended Vulkan C/C++ API Tutorials

C++ :   

[Raw Vulkan](https://alain.xyz/blog/raw-vulkan)   
This is what the Tri_Seeed guide is based off of and will kick start you well with the Vulkan-Hpp library.

C :   

[Vulkan Tutorial](https://vulkan-tutorial.com/Introduction)
This was the first tutorial I engaged with and got the job done. It goes quite in depth, I kinda wish there was a C++ equivalent for Vulkan-Hpp.   

[Intel's API without Secrets: Introduction to Vulkan](https://software.intel.com/content/www/us/en/develop/articles/api-without-secrets-introduction-to-vulkan-part-1.html)   
This one has the most depth of the ones described here. If you want details, this is the place.