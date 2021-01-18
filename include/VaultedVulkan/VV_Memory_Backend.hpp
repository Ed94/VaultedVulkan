/*!
@file VV_Memory_Backend.hpp

@brief Vaulted Vulkan: Memory: Preliminary Definitions

@details
Had to make this as there are definitions used by both application instance and physical device before full definitions done with the logical device.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a> 
*/



#pragma once



// VT
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"
#include "VV_Backend.hpp"
#include "VV_Types.hpp"
#include "VV_Constants.hpp"



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
	namespace V0
	{
		using V1::AccessFlags;
		using V1::DeviceSize ;

		/**
		@addtogroup Vault_0
		@{
		*/

		/**
		* @brief General memory definitions.
		* 
		* @details 
		* 
		* @ingroup APISpec_Memory_Allocation
		*/
		struct Memory
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeapFlags">Specification</a>
			 */
			using HeapFlags = Bitfield<EMemoryHeapFlag, VkMemoryHeapFlags>;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryMapFlags">Specification</a>
			*/
			using MapFlags = Bitfield<EUndefined, VkMemoryMapFlags>;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryPropertyFlags">Specification</a> 
			*/
			using PropertyFlags = Bitfield<EMemoryPropertyFlag, VkMemoryPropertyFlags>;

			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkAllocationFunction">Specification</a>  
			@ingroup APISpec_Memory_Allocation
			*/
			using FPtr_Allocation                     = PFN_vkAllocationFunction            ;
			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkReallocationFunction">Specification</a>
			@ingroup APISpec_Memory_Allocation
			*/
			using FPtr_Reallocation                   = PFN_vkReallocationFunction          ;
			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkFreeFunction">Specification</a> 
			@ingroup APISpec_Memory_Allocation
			*/
			using FPtr_Free                           = PFN_vkFreeFunction                  ;
			/**
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkInternalAllocationNotification">Specification</a> 	
			@ingroup APISpec_Memory_Allocation
			*/
			using FPtr_InternalAllocationNotification = PFN_vkInternalAllocationNotification;
			/**
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkInternalFreeNotification">Specification</a> 
			@ingroup APISpec_Memory_Allocation
			*/
			using FPtr_InternalFreeNotification       = PFN_vkInternalFreeNotification      ;


			/** 
			@brief Structure describing parameters of the allocation.
			
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryAllocateInfo">Specification</a>  

			@ingroup APISpec_Memory_Allocation
			*/
			struct AllocateInfo : V0::VKStruct_Base<VkMemoryAllocateInfo, EStructureType::MemoryAllocateInfo>
			{
				      EType      SType           = STypeEnum;
				const void*      Next            = nullptr  ;
				      DeviceSize AllocationSize ;
				      ui32     MemoryTypeIndex;
			};

			/** 
			@brief 
			Vulkan provides applications the opportunity to perform host memory allocations on behalf of the Vulkan implementation. 
			If this feature is not used, the implementation will perform its own memory allocations.
			
			@details 
			Since most memory allocations are off the critical path, this is not meant as a performance feature. Rather, 
			this can be useful for certain embedded systems, for debugging purposes (e.g. putting a guard page after all host allocations), 
			or for memory allocation logging.
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAllocationCallbacks">Specification</a> 

			@ingroup APISpec_Memory_Allocation
			*/
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
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			struct Barrier : V0::VKStruct_Base<VkMemoryBarrier, EStructureType::Memory_Barrier>
			{
				      EType       SType         = STypeEnum;
				const void*       Next          = nullptr  ;
				      AccessFlags SrcAccessMask;
				      AccessFlags DstAccessMask;
			};

			/**
			* @biref Structure describing the memory heap from which memory can be allocated.
			* 
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeap">Specification</a> 
			* 
			* @ingroup APISpec_Memory_Allocation
			*/
			struct Heap : V0::VKStruct_Base<VkMemoryHeap>
			{
				DeviceSize Size ;
				HeapFlags  Flags;
			};

			/**
			* @brief Structure describing the memory requirements for a buffer or an image.
			* 
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryRequirements">Specification</a> 
			* 
			* @ingroup APISpec_Resource_Creation
			*/
			struct Requirements : V0::VKStruct_Base<VkMemoryRequirements>
			{
				DeviceSize Size          ;
				DeviceSize Alignment     ;
				ui32       MemoryTypeBits;
			};

			/**
			* @brief Structures describing the memory types that can be used to access memory allocated from the heaps specified by memoryHeaps.
			* 
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryType ">Specification</a> 
			* 
			* @ingroup APISpec_Memory_Allocation
			*/
			struct Type : V0::VKStruct_Base<VkMemoryType>
			{
				PropertyFlags PropertyFlags;
				ui32          HeapIndex    ;
			};
		};

		/** @} */
	}
}
