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