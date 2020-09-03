# VaultedThermals
A vulkan wrapper.

Documentation can be found here: http://edsdigitalabode.com/VaultedThermals/index.html
(Documentation is updated ussually with implementation or if not during refactoring periods)

## Benefits:
- Features a 1:1 wrap implementation of the Vulkan C-API. (See Vault_01 implementation) [Note: Work in progress, the entire API has not be wrapped as of yet]
- Full in source and doxygen documentation.
- Ease of use functionality for boostrapping (See Vaults_02/3/4), but without the extra non-gpu API related clutter (Asset Loading, Camera, Entity, etc)
- Leveled abstraction namspacing and optional implementation wrapped in macros to allow easy discretion of features desired.

## State

This is currently a WIP, I am fleshing this out while making my engine project:
[Abstract Realm](https://github.com/Ed94/AbstractRealm)

Currently the API can be used to boostrap a vulkan backend, however a good amount of the API has not been wrapped.

My current intentions is to get this going as far as I like in conjunction with following various vulkan guides, and making my engine mvp. 
After that is done, this will be publicly released with some sort of open source license.