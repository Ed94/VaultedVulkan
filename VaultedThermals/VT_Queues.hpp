/**
@file VT_Queues.hpp

@brief Vaulted Thermals: Queues
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Enums.hpp"
#include "VT_Constants.hpp"
#include "VT_Initialization.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		/**
		 * @brief Queues handle different types of batched commands for the GPU to complete.
		 * 
		 * @details 
		 * Vulkan queues provide an interface to the execution engines of a device. 
		 * Commands for these execution engines are recorded into command buffers ahead of execution time.
		 * These command buffers are then submitted to queues with a queue submission command for execution in a number of batches. 
		 * Once submitted to a queue, these commands will begin and complete execution without further application intervention,
		 * though the order of this execution is dependent on a number of implicit and explicit ordering constraints.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#fundamentals-queueoperation">Specification</a> 
		 */
		struct Queue
		{
			using Handle = VkQueue;   ///< Opaque handle to a queue object

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceQueueCreateInfo.html">Specification</a> 
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkDeviceQueueCreateInfo>
			{
				using ECreateFlag = ELogicalDeviceQueueCreateFlag                 ;
				using CreateFlags = Bitmask<ECreateFlag, VkDeviceQueueCreateFlags>;

				      EType       SType           ;
				const void*       Extension       ;
				      CreateFlags Flags           ;
				      uint32      QueueFamilyIndex;
				      uint32      QueueCount      ;
				const float*      QueuePriorities ;
			};
		};

		/**
		@brief A set of queues that have common properties and support the same functionality.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkQueueFamilyProperties.html">Specification</a> 
		*/
		struct QueueFamilyProperties : Vault_00::VKStruct_Base<VkQueueFamilyProperties>
		{
			using EFlag = EQueueFlag            ;
			using Flags = Bitmask<EFlag , Flags>;   // Bitmask specifying capabilities of queues in a queue family.    

			Flags      QueueFlags                 ;
			uint32     QueueCount                 ;
			uint32     TimestampValidBits         ;
			Extent3D   MinImageTransferGranularity;
		};
	}
}
