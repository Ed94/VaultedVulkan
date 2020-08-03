/**
@file VT_Memory.hpp

@brief Vaulted Thermals: Memory

@details
Contains the full definition of the intended memory structure.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a>
*/



#pragma once


// VT#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Corridors.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"




#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		struct Memory : public Vault_00::Memory
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemory">Specification</a>  */
			using Handle = VkDeviceMemory;

			/**
			* @brief.
			* 
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateMemory">Specification</a> 
			* 
			* \param _device
			* \param _allocateInfo
			* \param _allocator
			* \param _memory
			* \return 
			*/
			static EResult Allocate
			(
				      LogicalDevice::Handle _device      ,
				const AllocateInfo&         _allocateInfo,
				const AllocationCallbacks*  _allocator   ,
				      Handle&               _memory
			)
			{
				return EResult(vkAllocateMemory(_device, _allocateInfo, _allocator->operator const VkAllocationCallbacks*(), &_memory) );
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeMemory">Specification</a> 
			* 
			* \param _device
			* \param _memory
			* \param _allocator
			* \return 
			*/
			static void Free
			(
				      LogicalDevice::Handle _device,
				      Memory::Handle _memory,
				const AllocationCallbacks* _allocator
			)
			{
				vkFreeMemory(_device, _memory, _allocator->operator const VkAllocationCallbacks*());
			}

			/** 
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkMapMemory">Specification</a>
			* 
			* \param _device
			* \param _memory
			* \param _offset
			* \param _size
			* \param _flags
			* \param _data
			* \return 
			*/
			static EResult Map
			(
				LogicalDevice::Handle _device,
				Handle                _memory,
				DeviceSize            _offset,
				DeviceSize            _size  ,
				MapFlags              _flags ,
				VoidPtr&              _data
			)
			{
				return EResult(vkMapMemory(_device, _memory, _offset, _size, _flags, &_data));
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkUnmapMemory">Specification</a>
			* 
			* \param _device
			* \param _memory
			*/
			static void Unmap(LogicalDevice::Handle _device, Handle _memory)
			{
				vkUnmapMemory(_device, _memory);
			}
		};
	}

	namespace Vault_02
	{
		struct Memory : public Vault_01::Memory
		{
			using Parent = Vault_01::Memory;

			struct AllocateInfo : public Vault_01::Memory::AllocateInfo
			{
				using Parent = Vault_01::Memory::AllocateInfo;

				AllocateInfo() { SType = STypeEnum; }
			};

			struct Barrier : public Vault_01::Memory::Barrier
			{
				using Parent = Vault_01::Memory::Barrier;

				Barrier() { SType = STypeEnum; }
			};
		};
	}

	namespace Vault_05
	{
		class Memory : public Vault_01::Memory
		{
		public:


		protected:

			Handle handle;

			LogicalDevice& assignedDevice;
		};
	}
}
