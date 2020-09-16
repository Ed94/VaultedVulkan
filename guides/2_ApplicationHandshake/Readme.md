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

        void Render();        

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