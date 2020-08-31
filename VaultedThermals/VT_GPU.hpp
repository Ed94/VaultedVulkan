#pragma once



#include "VT_GPU_Comms.hpp"



#ifdef VT_V4_Setup_Implementation

namespace VT
{
	namespace V4
	{
	#pragma region GPU_Comms

		AppInstance GPU_Comms::app;

		LayerAndExtensionList GPU_Comms::layersAndExtensions;
		Deque<RoCStr>         GPU_Comms::desiredLayers      ;
		Deque<RoCStr>         GPU_Comms::desiredExtensions  ;
		Deque<RoCStr>         GPU_Comms::desriedDeviceExts  ;
		
		V3::DebugMessenger GPU_Comms::messenger;

		PhysicalDeviceList GPU_Comms::physicalGPUs;
		LogicalDeviceList  GPU_Comms::logicalGPUs ;

		LogicalDevice* GPU_Comms::engagedDevice;

	#pragma endregion GPU_Comms
	}
}

#endif

