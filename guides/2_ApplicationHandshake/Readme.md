# Guide 2: Vulkan Application Handshake

Goes over setting up our skeleton for a rendering backend with Vulkan using a class we'll make called `VKGPU`. We'll setup a VKGPU to begin communication with the graphics api by creating an application instance, and starting to find out information about whats available on the machine graphics wise. Vulkan layers, and debug for vulkan will also be explained and setup.

## Our Implementation Canvas: Renderer Hpp/Cpp and the VKGPU

In your UserSpace, create two new files: Renderer.hpp, and Renderer.cpp. We'll be setting up our skeleton for the bulk of the code the rest of the guides will use.
![gif](https://i.imgur.com/UF0km45.gif)

Add the Utils and VT header to the top of Renderer.hpp
```cpp
#pragma once

// Utils
#include "Utils.hpp"

// VT
#include "VaultedThermals.hpp"
```

Here is what we'll need to implement for the VKGPU:   
```cpp
namespace Backend
{
    using namespace xwin  ;
    using namespace VT    ;
    using namespace VT::V3;

    class VKGPU
    {
    public:

        VKGPU();

        ~VKGPU();     

    protected:

        // Initialize your Graphics API (Application/Device Handshake)
	void StartCommunication();

	// Destroy the Application instance and debug messenger
	void CeaseCommunication();

        // GPU Communication

        AppInstance appVk;   // Represents the application in the vulkan API.

        // Container for physical gpu information.
        struct PhysicalGPU
        {
            PhysicalGPU(PhysicalDevice& _physicalDevice, std::vector<LayerAndExtensionProperties>& _properties):
                PhysicalDevice(_physicalDevice), LayersAndExtensions(_properties)
            {}

            V3::PhysicalDevice                       PhysicalDevice       ;
            std::vector<LayerAndExtensionProperties> LayersAndExtensions  ;
            std::vector<QueueFamilyProperties>       QueueFamilyProperties;
        };

        std::vector<PhysicalGPU> gpus;   // Listing of all physical gpus.

        DebugUtils::Messenger messenger;   // Debug messenger used for vulkan logging.
    };
}
```

Lets break this down:

`VKGPU()` will call `StartCommunication()` and `~VKGPU()` will call `CeaseCommunication(`) for now.

`appVk : AppInstance` is the equivalent to vkInstance from Vulkan. It acts as a representative of the application for Vulkan.

`PhysicalGPU` and its members contain information regarding the actual physical GPUs on the machine. We'll need one of these (you most likely only have one unless your machine has an intergrated GPU) later to engage one of these with a logical interface later.

`messenger : DebugUtils::Messenger` will be setup using the Vulkan Layers (specifically with validation layers) to be able to get a feed from the Vulkan API on how things are going with our requested execution within its scope.

Now in the Renderer.cpp setup the implementation skeleton:   
```cpp
// Parent Header
#include "Renderer.hpp"



namespace Backend
{
    // Utility Functions (Don't be afraid to take these with you!)

    // VKGPU

    VKGPU::VKGPU() : messenger(appVk)
    {
	StartCommunication();
    }

    VKGPU::~VKGPU()
    {
        CeaseCommunication();
    }

    void VKGPU::StartCommunication()
    {
	LOG("Preparing for GPU app handshake...");


    }

    void VKGPU::CeaseCommunication()
    {

    }
}
```

The first thing we'll do in start communication is find out some information about the available layers and their extensions at the Vulkan application level:   
```cpp
void VKGPU::StartCommunication()
{
    LOG("Preparing for GPU app handshake...");

    std::vector<LayerAndExtensionProperties> installedLayerAndExtensions;

    // Gives us all available layers and extensions for all vulkan compatible devices on this machine.
    AppInstance::GetAvailableLayersAndExtensions(installedLayerAndExtensions);

    LOG("\nLayers Available:");

    for (auto& layerAndExtensions : installedLayerAndExtensions)
    {
        LOG(layerAndExtensions.Layer.Name);
            
        LOG("Extensions:");

        for (auto& extension : layerAndExtensions.Extensions)
        {
            LOG(extension.Name);
        }
        
        LOG("");
    }
}
```
Now had over to main.cpp and add VKGPU to the execution:   
![img](https://i.imgur.com/tPFAarS.png)

The output of your program should now look like this:   
![img](https://i.imgur.com/SV0DXPm.png)

So I've been talking about these things called layers but without much explanation. Essentially layers are an API entrypoint interception framework. Under these different layers, extensions to the baseline API (the vulkan API itself) can be extended. We'll be using a couple of these later but the ones we need right now are those related to validation layers. These add functionality for debugging that we'll need for our messenger.

If you are on a modern version of vulkan, adding a the validation layer could be as easy as adding a vector with the Khronos validation layer specified:

```cpp
std::vector<const char*> desiredLayers = 
{
    Layer::Khronos_Validation
}
```

But... there are occasions that some machine will not have the latest vulkan so its safer to have a more robust sweep of fallback cases just in case:   
[pastebin](https://pastebin.com/xM82kZhU) (100 lines so I just put it here for you)

Simply use it in the following way now to populate desiredLayers a validation layer:   
![img](https://i.imgur.com/D7SDUKC.png)

Next we'll need to setup the desiredExtensions to have DebugUtility specified:   
```cpp
std::vector<const char*> desiredExtensions =
{
    InstanceExt::DebugUtility   // Enables debugging features.
};
```
This provides the necessary extension to setup our debug messenger.

