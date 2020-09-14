# VaultedThermals
A vulkan wrapper.

Documentation can be found here: http://edsdigitalabode.com/VaultedThermals/index.html
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
WIP. See milestones in issues.

Currently the library can be used to bootstrap a vulkan backend, however a good amount of the C-API has not been wrapped.

My current intentions is to get this going as far as I like in conjunction with following various vulkan guides, and making my engine mvp. 
After that is done, this will be publicly released with some sort of open source license.

## Guides

Head on over to ![guides](https://github.com/Ed94/VaultedThermals/tree/master/guides) to get started.
