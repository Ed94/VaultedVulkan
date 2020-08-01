# VaultedThermals
A vulkan wrapper.

## Benefits:
- Features a 1:1 wrap implementation of the Vulkan C-API (See Vault_01 implementation).
- Full in source and doxygen documentation.
- Ease of use functionality for boostrapping (See Vaults_02/3/4/6/7/8), but without the extra non-gpu API related clutter (Asset Loading, Camera, Entity, etc)
- Leveled abstraction namspacing and optional implementation wrapped in macros to allow easy discretion of features desired.

This is currently a WIP, I am fleshing this out while making my engine project:
[Abstract Realm](https://github.com/Ed94/AbstractRealm)

Motivations for doing so is I like clean libraries and while Vulkan-Hpp looked well designed, I cannot find a proper specification or documentation related to it, only the C-API. There is only their "samples". 

This library aims to have full documentation/specificaton within its comments and have clean organization. 

(Its also to help me learn Vulkan as I wanted to learn a low-level GPU API)

Documentation can be found here: http://edsdigitalabode.com/VaultedThermals/index.html
(Documentation is updated ussually with implementation or if not during refactoring periods)

The scope of this library is sort of outlined in the VT_Vaults.hpp and VaultedThermals.hpp

My current intentions is to get this going as far as I like in conjunction with following various vulkan guides, and making my engine mvp. After that is done, this will be publicly released with some sort of open source license.

## Why not just use something like Bgfx, Cauldron, other libraries and framewokrs out there?

When I started to look into getting to learn Vulkan, I was already convinced that learning with the bare C-API was not the most ideal scenario and looked for alternatives. The first found was Anvil from GPU-Open. I quickly learned that was shelved for a more robust framework (Cauldron). 

Looking further I found Bgfx which looked promising, but seemed to have abstracted away the low level interface Vulkan provides and essentially made it the same level of abstraction of OpenGL defeating the purpose of learing a low level graphics API.

Going back to Khronos I found Vulkan-HPP the C++ wrapper provided by Khronos. Unfortunately, it is generated, with no proper documentation. Looking online for one leads you to a few power point slides used at conference presentations of the changes completed. This isn't professional nor adequate for someone who is learning.

Attemping to find ANYTHING else leads to a framework or library that was more liberal with the implementation, with a bunch of bells and whistles that is not related to a low-level gpu library api.

This is a Vulkan API only library, there is no other concepts here, no added features. Its just a straight up proper wrap of the C-API with easy to read source and docs, no nonsense. It was made by someone wanting to learn Vulkan, hopefully it can help others with the same goal but with less hair pulling.

### P.S. Vulkan should have been mainly a C++ library with a generated C library, not the other way around.
