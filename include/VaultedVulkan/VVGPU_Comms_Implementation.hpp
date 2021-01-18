/*!
@file VV_GPU.hpp

@brief Vaulted Vulkan: GPU Backend (Bootstrap)

@details
*/



#pragma once



#include "VVGPU_Comms.hpp"



/**
@brief Implementation for V4 (must be dumped into a cpp file...)
*/
#ifdef VV_V4_Setup_Implementation



#  ifndef VV_Option__Use_Long_Namespace
namespace VV
#  else
namespace VaultedVulkan
#  endif
{
	namespace V4
	{
		/**
		@addtogroup Vault_4
		@{
		*/
	#pragma region GPU_Comms

		AppInstance GPU_Comms::app;

		LayerAndExtensionList GPU_Comms::layersAndExtensions;
		Deque<RoCStr>         GPU_Comms::desiredLayers      ;
		Deque<RoCStr>         GPU_Comms::desiredExtensions  ;
		Deque<RoCStr>         GPU_Comms::desriedDeviceExts  ;
		
		V3::DebugUtils::Messenger GPU_Comms::messenger;

		PhysicalDeviceList GPU_Comms::physicalGPUs;
		LogicalDeviceList  GPU_Comms::logicalGPUs ;

		LogicalDevice* GPU_Comms::engagedDevice;

	#pragma endregion GPU_Comms

		/** @} */
	}
}



#endif
