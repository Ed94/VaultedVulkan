/*!
@file VT_Constants.hpp

@brief Vaulted Thermals: Constants
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace Corridors
	{
		/**
		@addtogroup Corridors
		@{
		*/

		template<typename HandleType>
		/**
		@brief A template version of the VK_NULL_Handle specifier.
		(The handle type must be provided)
		
		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_NULL_HANDLE">Specification</a> 
		 
		@ingroup APISpec__Appendix-F__API_Boilerplate
		*/
		constexpr HandleType Null = VK_NULL_HANDLE;

		/**
		@brief Maximum number of heap elements in a physical device's memory properties.
		*/
		constexpr DeviceSize MaxMemoryHeaps = VK_MAX_MEMORY_HEAPS;

		/**
		@brief Maximum number of memory type elements in a physical device's memory properties.
		*/
		constexpr DeviceSize MaxMemoryTypes = VK_MAX_MEMORY_TYPES;

		/**
		@brief Used in resource synchronization and render pass commands. 

		@todo #TODO: Make a better brief/detailed elaboration.
		*/
		constexpr DeviceSize QueueFamily_Ignored = VK_QUEUE_FAMILY_IGNORED;

		/**
		@brief Used in render pass subpass related functionality.

		@todo #TODO : Make a better brief/detailed elaboration.
		*/
		constexpr ui32 Subpass_External = VK_SUBPASS_EXTERNAL;

		

		struct InstanceExt
		{
			/**
			@brief  
			This extension provides the following capabilities:
			The ability to create a debug messenger which will pass along debug messages to an application supplied callback.
			The ability to identify specific Vulkan objects using a name or tag to improve tracking.
			The ability to identify specific sections within a VkQueue or VkCommandBuffer using labels to aid organization and offline analysis in external tools.
			
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_EXT_debug_utils">Specification</a> 

			@ingroup APISpec__Appendix-E__Layers_and_Extensions_Informative
			*/
			static constexpr RoCStr DebugUtility = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;

			/**
			@brief It introduces VkSurfaceKHR objects, which abstract native platform surface or window objects for use with Vulkan. 
			It also provides a way to determine whether a queue family in a physical device supports presenting to particular surface. 
			
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_KHR_surface">Specification</a> 

			@ingroup APISpec__Appendix-E__Layers_and_Extensions_Informative
			*/
			static constexpr RoCStr Surface      = VK_KHR_SURFACE_EXTENSION_NAME;

			/**
			@brief It provides a mechanism to create a VkSurfaceKHR object (defined by the VK_KHR_surface extension) that refers to a Win32 HWND, 
			as well as a query to determine support for rendering to the windows desktop.

			@details https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_KHR_win32_surface

			@ingroup APISpec__Appendix-E__Layers_and_Extensions_Informative
			*/
			static constexpr RoCStr Win32Surface = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
		};

		struct DeviceExt
		{
			/**
			@brief Introduces VkSwapchainKHR objects, which provide the ability to present rendering results to a surface.
			
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_KHR_swapchain">Specification</a> 

			@ingroup  APISpec__Appendix-E__Layers_and_Extensions_Informative
			*/
			static constexpr RoCStr Swapchain = VK_KHR_SWAPCHAIN_EXTENSION_NAME;	
		};

		struct Layer
		{
			// Utility

			/**
			@brief Prints API calls, parameters, and values to the identified output stream. 
			It has several settings that can be adjusted by either environment variables or by using the vk_layer_settings.txt file.

			@details <a href="https://vulkan.lunarg.com/doc/view/1.1.114.0/windows/api_dump_layer.html">Specification</a> 
			*/
			static constexpr RoCStr LunarG_API_Dump   = "VK_LAYER_LUNARG_api_dump";

			/**
			@brief Prints the real-time frames-per-second value to the application's title bar. (Only works on the most recently opened window)

			@details <a href="https://vulkan.lunarg.com/doc/view/1.2.131.1/windows/monitor_layer.html">Specification</a> 
			*/
			static constexpr RoCStr LunarG_Monitor    = "VK_LAYER_LUNARG_monitor";   // Shows FPS on the most recently created window.

			/**
			@brief Records frames to image files.

			@details <a href="https://vulkan.lunarg.com/doc/view/latest/linux/screenshot_layer.html">Specification</a> 
			*/
			static constexpr RoCStr LunarG_Screenshot = "VK_LAYER_LUNARG_screenshot";

			// Validation

			// Deprecated (Fallback 3)

			/**
			@brief 
			The VK_LAYER_LUNARG_core_validation layer validates the status of descriptor sets, command buffers, shader modules, pipeline states, renderpass usage, synchronization, 
			dynamic states and is the workhorse layer for many other types of valid usage.

			@details https://vulkan.lunarg.com/doc/view/1.1.85.0/linux/core_validation_layer.html
			*/
			static constexpr RoCStr LunarG_CoreValidation = "VK_LAYER_LUNARG_core_validation";

			// Deprecated (Fallback 2)

			/**
			@brief Checks the input parameters to API calls for validity.

			@details <a href="https://chromium.googlesource.com/external/github.com/KhronosGroup/Vulkan-ValidationLayers/+/refs/tags/v1.1.97/docs/parameter_validation_layer.md">Specification</a> 
			*/
			static constexpr RoCStr LunarG_ParameterValidation = "VK_LAYER_LUNARG_parameter_validation";
			/**
			@brief Tracks all Vulkan objects. Object lifetimes are validated along with issues related to unknown objects and object destruction and cleanup.

			@details <a href="https://vulkan.lunarg.com/doc/view/1.1.85.0/linux/object_tracker_layer.html">Specification</a> 
			*/
			static constexpr RoCStr LunarG_ObjectTracker       = "VK_LAYER_LUNARG_object_tracker";
			/**
			@brief Checks multi-threading of API calls for validity. 
			Checks performed by this layer include ensuring that only one thread at a time uses an object in free-threaded API calls.

			@details <a href="https://vulkan.lunarg.com/doc/view/1.1.108.0/mac/threading_layer.html">Specification</a> 
			*/
			static constexpr RoCStr Google_Threading           = "VK_LAYER_GOOGLE_threading";
			/**
			@brief Wrap all Vulkan objects in a unique pointer at create time and unwrap them at use time

			@details <a href="https://vulkan.lunarg.com/doc/view/1.1.85.0/linux/unique_objects_layer.html">Specification</a> 
			*/
			static constexpr RoCStr Google_UniqueObjedcts      = "VK_LAYER_GOOGLE_unique_objects";

			// Meta Validation - Deprecated (Fallback 1)

			/**
			@brief This is a meta-layer managed by the loader. 
			On desktop systems, specifying this layer name will cause the loader to load the all of the standard validation layers.
			
			@details <a href="https://chromium.googlesource.com/android_ndk/+/refs/heads/unmodified/sources/third_party/vulkan/src/layers/vk_validation_layer_details.md#VK_LAYER_LUNARG_standard_validation">Specification</a> 
			*/
			static constexpr RoCStr LunarG_StandardValidation = "VK_LAYER_LUNARG_standard_validation";
			
			// Default

			/**
			@brief Encompasses the complete functionality that had previously been provided.

			@details <a href="https://vulkan.lunarg.com/doc/view/1.1.114.0/windows/khronos_validation_layer.html">Specification</a> 
			*/
			static constexpr RoCStr Khronos_Validation = "VK_LAYER_KHRONOS_validation";

			/** @} */
		};
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief Ease of identification masks for identifying a type of queue family.
		*/
		struct QueueMask
		{
			/**
			@brief Ease of identification mask for identifying a asynchronous compute queue family.
			*/
			static constexpr ui32 ComputeAsync = 
				ui32(EQueueFlag::Compute      ) |
				ui32(EQueueFlag::Transfer     ) |
				ui32(EQueueFlag::SparseBinding)  ;

			/**
			@brief Ease of identification mask for identifying a transfer only queue family.
			*/
			static constexpr ui32 TransferOnly = ui32(EQueueFlag::Transfer) | ui32(EQueueFlag::SparseBinding);
		};

		/** @} */
	}

	namespace V3
	{
		using V2::QueueMask;
	}
}
