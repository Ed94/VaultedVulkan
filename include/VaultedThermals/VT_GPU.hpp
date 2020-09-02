/*!
@file VT_GPU.hpp

@brief Vaulted Thermals: GPU Backend (Bootstrap)

@details
*/



#pragma once



#include "VT_GPU_Comms.hpp"



/**
@brief Implementation for V4 (must be dumped into a cpp file...)
*/
#ifdef VT_V4_Setup_Implementation



#  ifndef VT_Option__Use_Long_Namespace
namespace VT
#  else
namespace VaultedThermals
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
		
		V3::DebugMessenger GPU_Comms::messenger;

		PhysicalDeviceList GPU_Comms::physicalGPUs;
		LogicalDeviceList  GPU_Comms::logicalGPUs ;

		LogicalDevice* GPU_Comms::engagedDevice;

	#pragma endregion GPU_Comms

		/** @} */
	}
}



#endif
