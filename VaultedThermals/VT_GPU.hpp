#pragma once



#include "VT_GPU_Comms.hpp"



#ifndef VT_V4_Setup_Implementation
#define VT_V4_Setup_Implementation


namespace VT
{
	namespace V4
	{
	#pragma region GPU_Comms

		AppInstance           GPU_Comms::app                ;
		LayerAndExtensionList GPU_Comms::layersAndExtensions;
		std::deque<RoCStr>    GPU_Comms::desiredLayers      ;
		std::deque<RoCStr>    GPU_Comms::desiredExtensions  ;

	#pragma endregion GPU_Comms
	}
}

#endif

