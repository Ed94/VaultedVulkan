/**
@file VT_Memory.hpp

@brief Vaulted Thermals: Memory

@details

<a href="linkURL">Specification</a> 
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



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		/**
		* @brief.
		*/
		struct Memory
		{
			using PropertyFlags = Bitmask<EMemoryPropertyFlag, VkMemoryPropertyFlags>;
			using MapFlags = Bitmask<EUndefined, Flags>;

			using Handle = VkDeviceMemory;	

			using FPtr_Allocation                     = PFN_vkAllocationFunction            ;   // VK_FPtr<void*,	void*, size_t, size_t , VkSystemAllocationScope>;
			using FPtr_Reallocation                   = PFN_vkReallocationFunction          ;   
			using FPtr_Free                           = PFN_vkFreeFunction                  ;
			using FPtr_InternalAllocationNotification = PFN_vkInternalAllocationNotification;
			using FPtr_InternalFreeNotification       = PFN_vkInternalFreeNotification      ;


			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryAllocateInfo">Specification</a>  */
			struct AllocateInfo : Vault_00::VKStruct_Base<VkMemoryAllocateInfo, EStructureType::MemoryAllocateInfo>
			{
				      EType      SType          ;
				const void*      Next           ;
				      DeviceSize AllocationSize ;
				      uint32     MemoryTypeIndex;
			};

			struct AllocationCallbacks : Vault_00::VKStruct_Base<VkAllocationCallbacks>
			{
				void*                               UserData          ;
				FPtr_Allocation                     Allocation        ;
				FPtr_Reallocation                   Reallocation      ;
				FPtr_Free                           Free              ;
				FPtr_InternalAllocationNotification InternalAllocation;
				FPtr_InternalFreeNotification       InternalFree      ;
			};

			/**


			 * @todo Implement.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeap">Specification</a> 
			 */
			struct Heap : Vault_00::VKStruct_Base<VkMemoryHeap>
			{
				DeviceSize        size;
				VkMemoryHeapFlags flags;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryRequirements">Specification</a> 
			 */
			struct Requirements : Vault_00::VKStruct_Base<VkMemoryRequirements>
			{
				DeviceSize Size          ;
				DeviceSize Alignment     ;
				uint32     MemoryTypeBits;
			};

			/**
			 * @todo Implement.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryType ">Specification</a> 
			 */
			struct Type : Vault_00::VKStruct_Base<VkMemoryType>
			{
				PropertyFlags propertyFlags;
				uint32        heapIndex;
			};
		};
	}
}
