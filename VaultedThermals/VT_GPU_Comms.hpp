/*
Vaulted Thermals: GPU Communication

*/



#pragma once



// VT

#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_RenderPass.hpp"
#include "VT_Shaders.hpp"
#include "VT_Pipelines.hpp"
#include "VT_Surface.hpp"
#include "VT_SwapChain.hpp"
#include "VT_Debug.hpp"
#include <type_traits>



#ifdef VT_Option__Use_Long_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V4
	{
		using V3::DebugMessenger             ;
		using V3::LayerAndExtensionProperties;

		using LayerAndExtensionList = DynamicArray<LayerAndExtensionProperties>;

		class PhysicalDevice : public V3::PhysicalDevice
		{
		public:

		protected:

		};

		using PhysicalDeviceList = DynamicArray<PhysicalDevice>;

		class AppInstance : public V3::AppInstance
		{
		public:


		};

		class LogicalDevice : public V3::LogicalDevice
		{
		public:

		protected:


		};

		using LogicalDeviceList = DynamicArray<LogicalDevice>;

		

		class GPU_Comms
		{
		public:


		private:

			static constexpr bool engageSingleGPU = true;

			static AppInstance app;
			
			static LayerAndExtensionList layersAndExtensions;
			static std::deque<RoCStr>    desiredLayers      ;
			static std::deque<RoCStr>    desiredExtensions  ;
			static std::deque<RoCStr>    desriedDeviceExts  ;

			static V3::DebugMessenger messenger;

			static PhysicalDeviceList physicalGPUs;
			static LogicalDeviceList  logicalGPUs ;
		};
	}
}
