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
#include "VT_Initalization.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		struct Queue
		{
			using Handle = VkQueue;
		};

		/**
		@brief A set of queues that have common properties and support the same functionality.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkQueueFamilyProperties.html">Specification</a> 
		*/
		struct QueueFamilyProperties : Vault_00::VKStruct_Base<VkQueueFamilyProperties>
		{
			using Flags = Bitmask<EQueueFlag , Flags>;   // Bitmask specifying capabilities of queues in a queue family.    

			Flags      QueueFlags                 ;
			uint32     QueueCount                 ;
			uint32     TimestampValidBits         ;
			Extent3D   MinImageTransferGranularity;
		};
	}
}
