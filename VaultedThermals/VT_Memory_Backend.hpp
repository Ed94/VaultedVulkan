/**
@file VT_Memory_Corridors.hpp

@brief Vaulted Thermals: Memory: Preliminary Definitions

@details
Had to make this as there are definitions used by both application instance and physical device before full definitions done with the logical device.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a> 
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



VT_Namespace
{
	namespace V0
	{
		/**
		* @brief General memory definitions.
		*/
		struct Memory
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeapFlags">Specification</a>
			 */
			using HeapFlags = Bitmask<EMemoryHeapFlag, VkMemoryHeapFlags>;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryMapFlags">Specification</a>
			*/
			using MapFlags = Bitmask<EUndefined, VkMemoryMapFlags>;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryPropertyFlags">Specification</a> 
			*/
			using PropertyFlags = Bitmask<EMemoryPropertyFlag, VkMemoryPropertyFlags>;

			using FPtr_Allocation                     = PFN_vkAllocationFunction            ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkAllocationFunction">Specification</a> 
			using FPtr_Reallocation                   = PFN_vkReallocationFunction          ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkReallocationFunction">Specification</a> 
			using FPtr_Free                           = PFN_vkFreeFunction                  ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkFreeFunction">Specification</a> 
			using FPtr_InternalAllocationNotification = PFN_vkInternalAllocationNotification;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkInternalAllocationNotification">Specification</a> 
			using FPtr_InternalFreeNotification       = PFN_vkInternalFreeNotification      ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkInternalFreeNotification">Specification</a> 


			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryAllocateInfo">Specification</a>  */
			struct AllocateInfo : V0::VKStruct_Base<VkMemoryAllocateInfo, EStructureType::MemoryAllocateInfo>
			{
				      EType      SType          ;
				const void*      Next           ;
				      DeviceSize AllocationSize ;
				      uint32     MemoryTypeIndex;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAllocationCallbacks">Specification</a> */
			struct AllocationCallbacks : V0::VKStruct_Base<VkAllocationCallbacks>
			{
				void*                               UserData          ;
				FPtr_Allocation                     Allocation        ;
				FPtr_Reallocation                   Reallocation      ;
				FPtr_Free                           Free              ;
				FPtr_InternalAllocationNotification InternalAllocation;
				FPtr_InternalFreeNotification       InternalFree      ;
			};

			static constexpr AllocationCallbacks* DefaultAllocator = nullptr;

			/**
			 * @brief Global memory barriers apply to memory accesses involving all memory objects that exist at the time of its execution..
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryBarrier">Specification</a> 
			 */
			struct Barrier : V0::VKStruct_Base<VkMemoryBarrier, EStructureType::Memory_Barrier>
			{
				      EType       SType        ;
				const void*       Next         ;
				      AccessFlags SrcAccessMask;
				      AccessFlags DstAccessMask;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeap">Specification</a> 
			 */
			struct Heap : V0::VKStruct_Base<VkMemoryHeap>
			{
				DeviceSize Size ;
				HeapFlags  Flags;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryRequirements">Specification</a> 
			 */
			struct Requirements : V0::VKStruct_Base<VkMemoryRequirements>
			{
				DeviceSize Size          ;
				DeviceSize Alignment     ;
				uint32     MemoryTypeBits;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryType ">Specification</a> 
			 */
			struct Type : V0::VKStruct_Base<VkMemoryType>
			{
				PropertyFlags PropertyFlags;
				uint32        HeapIndex    ;
			};
		};
	}
}
