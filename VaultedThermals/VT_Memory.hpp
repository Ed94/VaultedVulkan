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
	namespace Vault_1
	{
		struct Memory : public Vault_0::Memory
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemory">Specification</a>  */
			using Handle = VkDeviceMemory;

			static constexpr DeviceSize ZeroOffset = 0;

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
				      LogicalDevice::Handle _device   ,
				      Memory::Handle        _memory   ,
				const AllocationCallbacks*  _allocator
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

	namespace Vault_2
	{
		struct Memory : public Vault_1::Memory
		{
			using Parent = Vault_1::Memory;

			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo() 
				{ 
					SType           = STypeEnum; 
					Next            = nullptr  ;
					AllocationSize  = 0        ;
					MemoryTypeIndex = 0        ;
				}
			};

			struct Barrier : public Parent::Barrier
			{
				Barrier() 
				{ 
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			/**
			 * @brief Writes to GPU memory by mapping to device memory specified by a 
			 * handle and then using memcpy to copy data specified in _data.
			 * 
			 * \param _device
			 * \param _memory
			 * \param _offset
			 * \param _size
			 * \param _flags
			 * \param _data
			 */
			static void WriteToGPU
			(
				LogicalDevice::Handle _device,
				Handle                _memory,
				DeviceSize            _offset,
				DeviceSize            _size  ,
				MapFlags              _flags ,
				VoidPtr&              _data
			)
			{
				VoidPtr gpuAddressing;

				Map(_device, _memory, _offset, _size, _flags, gpuAddressing);   ///< @todo Add exception handling for this / return code...

					memcpy(gpuAddressing, _data, _size);

				Unmap(_device, _memory);
			}
		};
	}

	namespace Vault_4
	{
		class Memory : public Vault_2::Memory
		{
			using Parent = Vault_2::Memory;

		public:

			EResult Allocate(LogicalDevice& _devce, AllocateInfo& _allocateInfo, Memory::AllocationCallbacks* _allocator)
			{
				device       = &_devce      ;
				allocateInfo = _allocateInfo;
				allocator    = _allocator   ;

				return Parent::Allocate(device->GetHandle(), allocateInfo, allocator, handle);
			}

			void Free()
			{
				Parent::Free(device->GetHandle(), handle, allocator);
			}

			Handle GetHandle() const
			{
				return handle;
			}

			EResult Map
			(
				DeviceSize _offset, DeviceSize _size, MapFlags _flags, VoidPtr& _data
			)
			{
				return Parent::Map(device->GetHandle(), handle, _offset, _size, _flags, _data);
			}

			void Unmap()
			{
				Parent::Unmap(device->GetHandle(), handle);
			}

			void WriteToGPU(DeviceSize _offset, DeviceSize _size, MapFlags _flags, VoidPtr& _data)
			{
				Parent::WriteToGPU(device->GetHandle(), handle, _offset, _size, _flags, _data);
			}

			operator Handle() const
			{
				return handle;
			}

		protected:

			Handle handle;

			AllocateInfo allocateInfo;

			AllocationCallbacks* allocator;

			LogicalDevice* device;
		};
	}
}
