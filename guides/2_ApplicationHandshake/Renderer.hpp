#pragma once



// Cross Window + Utils
#include "CrossWindow/CrossWindow.h"
#include "Utils.hpp"

// GLM
#define GLM_FORCE_SSE42 1
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES 1
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// VT
#include "VaultedThermals.hpp"



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

        AppInstance   appVk ;
        LogicalDevice device;    

        struct PhysicalGPU
        {
            PhysicalGPU(PhysicalDevice& _physicalDevice, std::vector<LayerAndExtensionProperties>& _properties):
                PhysicalDevice(_physicalDevice), LayersAndExtensions(_properties)
            {}

            V3::PhysicalDevice                       PhysicalDevice       ;
            std::vector<LayerAndExtensionProperties> LayersAndExtensions  ;
            std::vector<QueueFamilyProperties>       QueueFamilyProperties;
        };

        std::vector<PhysicalGPU> gpus;

        DebugUtils::Messenger messenger;
    };
}