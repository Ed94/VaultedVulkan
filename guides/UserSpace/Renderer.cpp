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

        std::vector<const char*> desiredLayers = 
        {
            Layer::Khronos_Validation
        }
    }

    void VKGPU::CeaseCommunication()
    {

    }
}