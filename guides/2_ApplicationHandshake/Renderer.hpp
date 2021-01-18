#pragma once



// Utils
#include "Utils.hpp"

// VV
#include "VaultedThermals.hpp"



namespace Backend
{
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