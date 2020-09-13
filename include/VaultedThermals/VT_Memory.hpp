/*!
@file VT_Memory.hpp

@brief Vaulted Thermals: Memory

@details Contains the full definition of the intended memory structure.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a>
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
#include "VT_Constants.hpp"
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		@brief General memory structures and functionality for device memory.

		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a> 

		@ingroup APISpec_Memory_Allocation
		*/
		struct Memory : public V0::Memory
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemory">Specification</a>  */
			using Handle = VkDeviceMemory;

			/**
			@brief Used to specify no offset when mapping memory.
			*/
			static constexpr DeviceSize ZeroOffset = 0;

			/**
			* @brief Allocate memory objects.
			* 
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateMemory">Specification</a>
			* 
			* @ingroup APISpec_Memory_Allocation
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
				return EResult(vkAllocateMemory(_device, _allocateInfo, *_allocator, &_memory) );
			}

			/**
			* @brief Free a memory object.
			*
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeMemory">Specification</a>
			* 
			* @ingroup APISpec_Memory_Allocation
			* 
			* \param _device
			* \param _memory
			* \param _allocator
			* \return 
			*/
			static void Free(LogicalDevice::Handle _device, Handle _memory, const AllocationCallbacks* _allocator)
			{
				vkFreeMemory(_device, _memory, *_allocator);
			}

			/** 
			* @brief Retrieve a host virtual address pointer to a region of a mappable memory object.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkMapMemory">Specification</a>
			* 
			* @ingroup APISpec_Memory_Allocation
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
			* @brief Unmap a memory object once host access to it is no longer needed by the application.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkUnmapMemory">Specification</a> 
			* 
			* @ingroup APISpec_Memory_Allocation
			* 
			* \param _device
			* \param _memory
			*/
			static void Unmap(LogicalDevice::Handle _device, Handle _memory)
			{
				vkUnmapMemory(_device, _memory);
			}
		};

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief General memory structures and functionality for device memory.

		@ingroup APISpec_Memory_Allocation
		*/
		struct Memory : public V1::Memory
		{
			using Parent = V1::Memory;

			/**
			* @brief Allocate memory objects using the default allocator.
			* 
			* \param _device
			* \param _allocateInfo
			* \param _allocator
			* \param _memory
			* \return 
			*/
			static EResult Allocate(LogicalDevice::Handle _device, const AllocateInfo& _allocateInfo, Handle& _memory)
			{
				return EResult(vkAllocateMemory(_device, _allocateInfo, *Memory::DefaultAllocator, &_memory) );
			}

			using Parent::Allocate;

			/**
			* @brief Free a memory object allocated using the default allocator.
			* 
			* \param _device
			* \param _memory
			* \param _allocator
			* \return 
			*/
			static void Free(LogicalDevice::Handle _device, Handle _memory)
			{
				vkFreeMemory(_device, _memory, *Memory::DefaultAllocator);
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
				const VoidPtr&              _data
			)
			{
				VoidPtr gpuAddressing;

				Map(_device, _memory, _offset, _size, _flags, gpuAddressing);   ///< @todo Add exception handling for this / return code...

					memcpy(gpuAddressing, _data, _size);

				Unmap(_device, _memory);
			}
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@ingroup APISpec_Memory_Allocation
		@brief General memory structures and functionality for device memory.

		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class Memory : public V2::Memory
		{
		public:

			using Parent = V2::Memory;

			/**
			@brief Default constructor.
			*/
			Memory() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Constructor with logical device specified.
			*/
			Memory(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Constructor with logical device and allocator specified.
			*/
			Memory(const LogicalDevice& _device, const Memory::AllocationCallbacks _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			Memory(Memory&& _other) noexcept :
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;	
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destructor will destroy the device object if handle is not null.
			*/
			~Memory()
			{
				if (handle != Null<Handle>) Free();
			}

			/**
			@brief Allocate memory objects.
			*/
			EResult Allocate(const AllocateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Allocate(*device, _info, handle);
			}

			/**
			@brief Allocate memory objects. (Device specified)
			*/
			EResult Allocate(const LogicalDevice& _device, const AllocateInfo& _allocateInfo)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				return Parent::Allocate(*device, _allocateInfo, handle);
			}

			/**
			@brief Allocate memory objects. (Device and allocator specified)
			*/
			EResult Allocate(const LogicalDevice& _device, const AllocateInfo& _allocateInfo, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Allocate(*device, _allocateInfo, allocator, handle);
			}

			/**
			@brief Free a memory object.
			*/
			void Free()
			{
				Parent::Free(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Retrieve a host virtual address pointer to a region of a mappable memory object.
			*/
			EResult Map(DeviceSize _offset, DeviceSize _size, MapFlags _flags, VoidPtr& _data)
			{
				return Parent::Map(*device, handle, _offset, _size, _flags, _data);
			}

			/**
			@brief Unmap a memory object once host access to it is no longer needed by the application.
			*/
			void Unmap()
			{
				Parent::Unmap(*device, handle);
			}

			/**
			@brief Writes to GPU memory by mapping to device memory specified by a
			handle and then using memcpy to copy data specified in _data.
			*/
			void WriteToGPU(DeviceSize _offset, DeviceSize _size, MapFlags _flags, VoidPtr& _data)
			{
				Parent::WriteToGPU(*device, handle, _offset, _size, _flags, _data);
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const Memory& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			Memory& operator= (Memory&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/** @} */
	}
}
