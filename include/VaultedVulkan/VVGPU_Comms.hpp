/*!
@file VV_GPU_Comms.hpp

@brief Vaulted Vulkan: GPU Communication

@details
*/



#pragma once



// VT

#include "VV_Vaults.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"
#include "VV_Backend.hpp"
#include "VV_Types.hpp"
#include "VV_Constants.hpp"
#include "VV_Memory_Backend.hpp"
#include "VV_PhysicalDevice.hpp"
#include "VV_Initialization.hpp"
#include "VV_LogicalDevice.hpp"
#include "VV_Memory.hpp"
#include "VV_Sampler.hpp"
#include "VV_Resource.hpp"
#include "VV_RenderPass.hpp"
#include "VV_Shaders.hpp"
#include "VV_Pipelines.hpp"
#include "VV_Surface.hpp"
#include "VV_SwapChain.hpp"
#include "VV_Debug.hpp"
#include <type_traits>



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
	namespace V4
	{
		/**
		@addtogroup Vault_4
		@{
		*/

		enum class EGPU_Engage
		{
			Single,
			Multi
		};

	/**
	 * While this option has been defined here, currently this bootstrapped backend only supports
	 * engaging a single GPU...
	 */
	#ifndef VT_Option_AllowMultiGPUEngagement
		constexpr EGPU_Engage GPU_Engagement = EGPU_Engage::Single;
	#else
		constexpr EGPU_Engage GPU_Engagement = EGPU_Engage::Multi;
	#endif

		using V3::DebugUtils;
		using V3::LayerAndExtensionProperties;

		using LayerAndExtensionList = DynamicArray<LayerAndExtensionProperties>;

		class PhysicalDevice : public V3::PhysicalDevice
		{
		public:

			

		protected:

		};

		using PhysicalDeviceList = DynamicArray<PhysicalDevice>;

		struct DebugUtils : public V3::DebugUtils
		{
			using Parent = V3::DebugUtils;

			class Messenger : public Parent::Messenger
			{
			public:
				using Parent = V3::DebugUtils::Messenger;

			protected:
			};
		};

		class AppInstance : public V3::AppInstance
		{
		public:


		};

		class LogicalDevice : public V3::LogicalDevice
		{
		public:

			const PhysicalDevice& GetPhysicalDevice() const
			{
				return *static_cast<const PhysicalDevice*>(physicalDevice);
			}

		protected:


		};

		using LogicalDeviceList = DynamicArray<LogicalDevice>;

		
		namespace Backend
		{
			template<EGPU_Engage>
			class GPU_Comms_Maker;

			template<>
			class GPU_Comms_Maker<EGPU_Engage::Single>
			{
			public:

				// Initialization and Cease (Startup/Shutdown)

				static void Initalize();

				static void Cease();



				static AppInstance::Handle GetAppHandle()
				{
					return app.GetHandle();
				}

				static const LogicalDevice& GetEngagedDevice()
				{
					return *engagedDevice;
				}

				static const PhysicalDevice& GetEngagedPhysicalGPU()
				{
					return engagedDevice->GetPhysicalDevice();
				}

			private:

				static void AcquirePhysicalDevices();

				static void EngageMostSuitableDevice();

				static void GenerateLogicalDevices();

				static AppInstance app;

				static LayerAndExtensionList layersAndExtensions;
				static Deque<RoCStr>         desiredLayers;
				static Deque<RoCStr>         desiredExtensions;
				static Deque<RoCStr>         desriedDeviceExts;

				static V3::DebugUtils::Messenger messenger;

				static PhysicalDeviceList physicalGPUs;
				static LogicalDeviceList  logicalGPUs;

				static LogicalDevice* engagedDevice;
			};
		}

		using GPU_Comms = Backend::GPU_Comms_Maker<GPU_Engagement>;

		/** @} */
	}
}
