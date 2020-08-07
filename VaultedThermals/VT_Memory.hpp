/**
@file VT_Memory.hpp

@brief Vaulted Thermals: Memory

@details
Contains the full definition of the intended memory structure.

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
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"




VT_Namespace
{
	namespace V1
	{
		struct Memory : public V0::Memory
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
				      Handle                _memory   ,
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

	namespace V2
	{
		struct Memory : public V1::Memory
		{
			using Parent = V1::Memory;

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
			* @brief.
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
				      Handle&               _memory
			)
			{
				return EResult(vkAllocateMemory(_device, _allocateInfo, Memory::DefaultAllocator->operator const VkAllocationCallbacks*(), &_memory) );
			}

			using Parent::Allocate;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeMemory">Specification</a> 
			* 
			* \param _device
			* \param _memory
			* \param _allocator
			* \return 
			*/
			static void Free(LogicalDevice::Handle _device, Handle _memory)
			{
				vkFreeMemory(_device, _memory, Memory::DefaultAllocator->operator const VkAllocationCallbacks*());
			}

			using Parent::Free;

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

	namespace V4
	{
		class Memory : public V2::Memory
		{
		public:

			using Parent = V2::Memory;

			EResult Allocate(LogicalDevice& _device, AllocateInfo& _allocateInfo)
			{
				device    = &_device                ;
				info      = _allocateInfo           ;
				allocator = Memory::DefaultAllocator;

				return Parent::Allocate(device->GetHandle(), info, handle);
			}

			EResult Allocate(LogicalDevice& _device, AllocateInfo& _allocateInfo, const Memory::AllocationCallbacks* _allocator)
			{
				device    = &_device     ;
				info      = _allocateInfo;
				allocator = _allocator   ;

				return Parent::Allocate(device->GetHandle(), info, allocator, handle);
			}

			void Free()
			{
				Parent::Free(device->GetHandle(), handle, allocator);
			}

			const Handle& GetHandle() const
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

		protected:

			Handle handle;

			AllocateInfo info;

			const AllocationCallbacks* allocator;

			LogicalDevice* device;
		};
	}
}
