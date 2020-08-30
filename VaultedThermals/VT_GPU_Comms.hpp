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
	/**
	 * While this option has been defined here, currently this bootstrapped backend only supports
	 * engaging a single GPU...
	 */
	#ifndef VT_Option_AllowMultiGPUEngagement
		constexpr bool EngageSingleGPU = true;
	#else
		constexpr bool EngageSingleGPU = false;
	#endif

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

		
		namespace Backend
		{
			template<bool>
			class GPU_Comms_Maker;

			template<>
			class GPU_Comms_Maker<true /* Engage Single GPU */>
			{
			public:

				AppInstance::Handle GetAppHandle()
				{
					return app.GetHandle();
				}

				const LogicalDevice& GetEngagedDevice()
				{
					return *engagedDevice;
				}

			private:

				static AppInstance app;

				static LayerAndExtensionList layersAndExtensions;
				static Deque<RoCStr>         desiredLayers;
				static Deque<RoCStr>         desiredExtensions;
				static Deque<RoCStr>         desriedDeviceExts;

				static V3::DebugMessenger messenger;

				static PhysicalDeviceList physicalGPUs;
				static LogicalDeviceList  logicalGPUs;

				static LogicalDevice* engagedDevice;
			};
		}

		using GPU_Comms = Backend::GPU_Comms_Maker<EngageSingleGPU>;
	}
}
