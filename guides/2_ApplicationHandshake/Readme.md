# Guide 2: Vulkan Application Handshake

Goes over setting up our skeleton for a rendering backend with Vulkan using a class we'll make called `VKGPU`. We'll setup a VKGPU to begin communication with the graphics api by creating an application instance, and starting to find out information about whats available on the machine graphics wise. Vulkan layers, and debug for vulkan will also be explained and setup.

## Our Implementation Canvas: Renderer Hpp/Cpp and the VKGPU

In your UserSpace, create two new files: Renderer.hpp, and Renderer.cpp. We'll be setting up our skeleton for the bulk of the code the rest of the guides will use.
![gif](https://i.imgur.com/UF0km45.gif)

Add the Utils and VV header to the top of Renderer.hpp
```cpp
#pragma once

// Utils
#include "Utils.hpp"

// VV
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

But... there are occasions that some machines will not have the latest vulkan so its safer to have a more robust sweep of fallback cases just in case:   
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

With those set, the Vulkan object infos need to be setup for creating the application instance and debug messenger.

The first is the application info for the application instance, it provides general information for the Vulkan API and what version of Vulkan to use.
```cpp
AppInstance::AppInfo appInfo;

appInfo.AppName       = "VV Seed GPU"       ;
appInfo.AppVersion    = MakeVersion(0, 1, 0);
appInfo.EngineName    = "VV Seed Engine"    ;
appInfo.EngineVersion = MakeVersion(0, 1, 0);
appInfo.API_Version   = EAPI_Version::_1_0  
```
Next is the application instance's create info. This struct has the parameters for the object creation. There are create info's for all Vulkan objects that are not allocated in Pools.
```cpp
AppInstance::CreateInfo info;

info.AppInfo = &appInfo;

info.EnabledExtensionCount = static_cast<uint32>(desiredExtensions.size());
info.EnabledExtensionNames = desiredExtensions.data();

info.EnabledLayerCount = static_cast<uint32>(desiredLayers.size());
info.EnabledLayerNames = desiredLayers.data();
```

For the debug messenger's create info:
```cpp
// Were going to add a debug call back for vulkan related validation logs.
Messenger::CreateInfo messengerInfo;

using EServerity   = Messenger::EServerity  ;
using EMessageType = Messenger::EMessageType;

messengerInfo.Serverity.Set(EServerity  ::Verbose, EServerity  ::Warning   , EServerity  ::Error      );
messengerInfo.Type     .Set(EMessageType::General, EMessageType::Validation, EMessageType::Performance);

messengerInfo.UserCallback = GetVTAPI_Call(DebugCallback);
		             // A debug callback must follow the vulkan calling convention.
```

Now for that DebugCallback, this is a user defined function for the Vulkan API and gets called by the validation layers.

Here is the one I'm providing:
```cpp
using Messenger = DebugUtils::Messenger;

Bool DebugCallback
(
          Messenger::ServerityFlags  _messageServerity, 
          Messenger::TypeFlags       /*_messageType*/ ,
    const Messenger::CallbackData    _callbackData    , 
          void*                      /*_userData*/
)
{
    using EServerity = Messenger::EServerity;

    LOG(_callbackData.Message);

    return EBool::True;
}
```

With the all that setup, we can now create the application instance and debug messenger:
```cpp
EResult 
returnCode = appVk.Create(info);   // Create the application instance.

if (returnCode != EResult::Success) throw std::runtime_error("Failed to create the vulkan application instance.");

LOG("Vulkan application instance created!");

returnCode = messenger.Create(messengerInfo);   // Create the messenger object.

if (returnCode != EResult::Success) throw std::runtime_error("Failed to create the debug messenger.");	

LOG("Debug messenger created!");
```

Now with our application instance created, lets populate information regarding the physical graphical devices on the machine.
```cpp
// Populating physical devices...

std::vector<PhysicalDevice> physicalDevices;

returnCode = appVk.GetAvailablePhysicalDevices(physicalDevices);

if (returnCode != EResult::Success) throw std::runtime_error("Failed to get any physical devices.");

LOG("\nSupported physical devices aquired:");
```

Last lets use those physical devices to populate our gpu listing information.
```cpp
std::stringstream gpuHandle;

// Cycle through the gpu listing and populate/print out some information.
for (auto& physicalDevice : physicalDevices)
{
    gpus.push_back( PhysicalGPU(physicalDevice, installedLayerAndExtensions) );

    // Populate information

    auto& gpu = gpus.back();

    returnCode = EResult::Incomplete;

    for (auto& layerAndExtensions : gpu.LayersAndExtensions)
    {
        physicalDevice.GetAvailableExtensions(layerAndExtensions.Layer.Name, layerAndExtensions.Extensions);
    }

    gpu.QueueFamilyProperties = physicalDevice.GetAvailableQueueFamilies();

    // Log info

    gpuHandle.str(std::string());

    gpuHandle << physicalDevice;

    LOG(physicalDevice.GetProperties().Name + std::string(" Handle: ") + gpuHandle.str() + std::string("\n"));
}

LOG("Vulkan application handshake complete!");
```
Now we just need to make sure the objects are properly destroyed:
```cpp
void VKGPU::CeaseCommunication()
{
    messenger.Destroy();

    appVk.Destroy();
}
```
Running the program now will yield physical device information with the proper created objects.