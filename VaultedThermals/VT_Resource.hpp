/** 
@file VT_Resource.hpp

@brief Vaulted Thermals: Resources

@details
Vulkan supports two primary resource types: buffers and images. 
Resources are views of memory with associated formatting and dimensionality. 
Buffers are essentially unformatted arrays of bytes whereas images contain format information, 
can be multidimensional and may have associated metadata.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources">Specification</a> 
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
#include "VT_Memory_Corridors.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		/**
		 * @brief A linear array of data.
		 * 
		 * @details
		 * Buffers represent linear arrays of data which are used for various purposes by binding them
		 * to a graphics or compute pipeline via descriptor sets or via certain commands, or by
		 * directly specifying them as parameters to certain commands.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-buffers">Specification</a> 
		 */
		struct Buffer
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBuffer">Specification</a>  */
			using Handle = VkBuffer;

			using ECreateFlag = EBufferCreateFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EBufferCreateFlag, VkBufferCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferUsageFlags">Specification</a>  */
			using UsageFlags = Bitmask<EBufferUsage, VkBufferUsageFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateInfo">Specification</a>
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkBufferCreateInfo, EStructureType::Buffer_CreateInfo>
			{
				      EType        SType                ;
				const void*        Next                 ;
				      CreateFlags  Flags                ;
					  DeviceSize   Size                 ;
					  UsageFlags   Usuage               ;
				      ESharingMode SharingMode          ;
					  uint32       QueueFamilyIndexCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCopy">Specification</a>  */
			struct CopyInfo : Vault_00::VKStruct_Base<VkBufferCopy>
			{
				DeviceSize SourceOffset;
				DeviceSize DestinationOffset;
				DeviceSize Size;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferMemoryBarrier">Specification</a>
			 */
			struct Memory_Barrier : Vault_00::VKStruct_Base<VkBufferMemoryBarrier, EStructureType::BufferMemory_Barrier>
			{
				      EType          SType              ;
				const void*          Next               ;
				      AccessFlags    SrcAccessMask      ;
				      AccessFlags    DstAccessMask      ;
				      uint32         SrcQueueFamilyIndex;
				      uint32         DstQueueFamilyIndex;
				      Buffer::Handle Buffer             ;
				      DeviceSize     Offset             ;
				      DeviceSize     Size               ;
			};

			/**
			 * @brief.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBindBufferMemory">Specification</a> 
			 * 
			 * \param _device
			 * \param _buffer
			 * \param _memory
			 * \param _memoryOffset
			 * \return 
			 */
			static EResult BindMemory
			(
				LogicalDevice::Handle _device      ,
				Buffer::Handle        _buffer      ,
				Memory::Handle        _memory      ,
				DeviceSize            _memoryOffset
			)
			{
				return EResult(vkBindBufferMemory(_device, _buffer, _memory, _memoryOffset));
			}

			/**
			 * @brief Create a new buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateBuffer">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _buffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator, Buffer::Handle& _buffer)
			{
				return EResult(vkCreateBuffer(_deviceHandle, _createInfo.operator const VkBufferCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_buffer));
			}

			/**
			 * @brief Destroy a buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyBuffer">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _buffer
			 * \param _allocator
			 * \return 
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Buffer::Handle _buffer, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyBuffer(_deviceHandle, _buffer, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetBufferMemoryRequirements">Specification</a>
			 * 
			 * \param _device
			 * \param _buffer
			 * \param _memoryRequirements
			 */
			static void GetMemoryRequirements
			(
				LogicalDevice::Handle _device             ,
				Buffer::Handle        _buffer             ,
				Memory::Requirements& _memoryRequirements
			)
			{
				vkGetBufferMemoryRequirements(_device, _buffer, _memoryRequirements);
			}
		};

		/**
		 * @brief A buffer view represents a contiguous range of a buffer and a specific format to be used to interpret the data.
		 * 
		 * @details
		 * Buffer views are used to enable shaders to access buffer contents interpreted as formatted data. 
		 * In order to create a valid buffer view, the buffer must have been created with at least one of 
		 * the following usage flags: UnformTexelBuffer or StorageTexelBuffer
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-buffer-views">Specification</a> 
		 */
		struct BufferView
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferView">Specification</a>  */
			using Handle = VkBufferView;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferViewCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EUndefined, VkBufferViewCreateFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBufferViewCreateInfo.html">Specification</a> .
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkBufferViewCreateInfo, EStructureType::BufferView_CreateInfo>
			{
				      EType       SType  ;
				const void*       Next   ;
				      CreateFlags Flags  ;
				      Buffer      VBuffer;
				      EFormat     Format ;
				      DeviceSize  Offset ;
				      DeviceSize  Range  ;
			};

			/**
			 * @brief Create a new buffer view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateBufferView">Specification</a> .
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _bufferView
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _creationSpec, const Memory::AllocationCallbacks* _allocator, BufferView::Handle& _bufferView)
			{
				return EResult(vkCreateBufferView(_deviceHandle, _creationSpec.operator const VkBufferViewCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_bufferView));
			}

			/**
			 * @brief Destroy a buffer view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyBufferView.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _bufferView
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, BufferView::Handle _bufferView, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyBufferView(_deviceHandle, _bufferView, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		struct DescriptorPool
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPool">Specification</a>  */
			using Handle = VkDescriptorPool;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EDescriptorPoolCreateFlag, VkDescriptorPoolCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolResetFlags">Specification</a>  */
			using ResetFlags = Bitmask<EUndefined, VkDescriptorPoolResetFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolSize">Specification</a>  */
			struct Size : Vault_00::VKStruct_Base<VkDescriptorPoolSize>
			{
				EDescriptorType Type ;
				uint32          Count;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkDescriptorPoolCreateInfo, EStructureType::Descriptor_Pool_CreateInfo>
			{
					  EType       SType        ;
				const void*       Next         ;
					  CreateFlags Flags        ;
					  uint32      MaxSets      ;
					  uint32      PoolSizeCount;
				const Size*       PoolSizes    ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDescriptorPool">Specification</a>
			 * 
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _descriptorPool
			 * \return 
			 */
			static EResult Create
			(
					  LogicalDevice::Handle         _device        ,
				const CreateInfo&                   _createInfo    ,
				const Memory::AllocationCallbacks*  _allocator     ,
					  Handle&                       _descriptorPool
			)
			{
				return EResult(vkCreateDescriptorPool(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_descriptorPool));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDescriptorPool">Specification</a> 
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _allocator
			 */
			static void Destroy
			(
				LogicalDevice::Handle               _device,
				Handle                              _descriptorPool,
				const Memory::AllocationCallbacks*  _allocator
			)
			{
				vkDestroyDescriptorPool(_device, _descriptorPool, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetDescriptorPool">Specification</a> 
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _flags
			 * \return 
			 */
			static EResult Reset
			(
				LogicalDevice::Handle _device,
				Handle                _descriptorPool,
				ResetFlags            _flags
			)
			{
				return EResult(vkResetDescriptorPool(_device, _descriptorPool, _flags));
			}
		};

		/** 
		@brief
		Images represent multidimensional - up to 3 - arrays of data which can be used for various purposes 
		(e.g. attachments, textures), by binding them to a graphics or compute pipeline via descriptor sets, 
		or by directly specifying them as parameters to certain commands.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-images">Specification</a> 
		*/
		struct Image
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImage">Specification</a>  */
			using Handle = VkImage;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageAspectFlags">Specification</a>  */
			using AspectFlags = Bitmask<EImageAspect, VkImageAspectFlags>;

			using ECreateFlag = EImageCreateFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EImageCreateFlag, VkImageCreateFlags>;

			using ETiling = EImageTiling;

			using EUsage = EImageUsage;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageUsageFlags">Specification</a>  */
			using UsageFlags = Bitmask<EImageUsage, VkImageUsageFlags>;   ///< Bitmask specifying intended usage of an image.

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkImageCreateInfo, EStructureType::Image_CreateInfo>
			{
				      EType        SType                ;
				const void*        Next                 ;
				      CreateFlags  Flags                ;
				      EImageType   ImageType            ;
				      EFormat      Format               ;
				      Extent3D     Extent               ;
				      uint32       MipmapLevels         ;
				      uint32       ArrayLayers          ;
				      ESampleCount Samples              ;
				      ETiling      Tiling               ;
					  UsageFlags   Usage                ;
				      ESharingMode SharingMode          ;
				      uint32       QueueFamilyIndexCount;
				const uint32*      QueueFamilyIndices   ;
					  EImageLayout InitalLayout         ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageSubresourceLayers">Specification</a>  */
			struct SubresourceLayers : Vault_00::VKStruct_Base<VkImageSubresourceLayers>
			{
				AspectFlags AspectMask    ;
				uint32      MipLevel      ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageSubresourceRange">Specification</a>  */
			struct SubresourceRange : Vault_00::VKStruct_Base<VkImageSubresourceRange>
			{
				AspectFlags AspectMask    ;
				uint32      BaseMipLevel  ;
				uint32      LevelCount    ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageMemoryBarrier">Specification</a>  */
			struct Memory_Barrier : Vault_00::VKStruct_Base<VkImageMemoryBarrier, EStructureType::ImageMemory_Barrier>
			{
				      EType            SType              ;
				const void*            Next               ;
				      AccessFlags      SrcAccessMask      ;
				      AccessFlags      DstAccessMask      ;
				      EImageLayout     OldLayout          ;
				      EImageLayout     NewLayout          ;
				      uint32           SrcQueueFamilyIndex;
				      uint32           DstQueueFamilyIndex;
				      Image::Handle    Image              ;
				      SubresourceRange SubresourceRange   ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageBlit">Specification</a>  */
			struct Blit : Vault_00::VKStruct_Base<VkImageBlit>
			{
				SubresourceLayers SrcSubresource;
				Offset3D          SrcOffsets[2] ;
				SubresourceLayers DstSubresource;
				Offset3D          DstOffsets[2] ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBindImageMemory">Specification</a> 
			 * 
			 * \param _device
			 * \param _image
			 * \param _memory
			 * \param _memoryOffset
			 * \return 
			 */
			static EResult BindMemory
			(
				LogicalDevice::Handle _device      ,
				Handle                _image       ,
				Memory::Handle        _memory      ,
				DeviceSize            _memoryOffset
			)
			{
				return EResult(vkBindImageMemory(_device, _image, _memory, _memoryOffset));
			}

			/**  
			 * @brief  Create an image object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateImage">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _imageHandle
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator, Image::Handle& _imageHandle)
			{
				return EResult(vkCreateImage(_deviceHandle, _createInfo.operator const VkImageCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_imageHandle));
			}

			/** 
			 * @brief Destroy an image object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyImage">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _image
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _image, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyImage(_deviceHandle, _image, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetImageMemoryRequirements">Specification</a> 
			 * 
			 * \param _device
			 * \param _image
			 * \param _memoryRequirements
			 */
			static void GetMemoryRequirements(LogicalDevice::Handle _device, Handle _image, Memory::Requirements& _memoryRequirements)
			{
				vkGetImageMemoryRequirements(_device, _image, _memoryRequirements);
			}
		};

		/**
		* @brief An object that represents an image subresource range of a specific image, 
		* and state that controls how the contents are interpreted.
		* 
		* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-image-views">Specification</a> 
		*/
		struct ImageView
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageView">Specification</a>  */
			using Handle = VkImageView;

			using EViewType = EImageViewType;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkImageViewCreateInfo, EStructureType::ImageView_CreateInfo>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EImageViewCreateFlag, VkImageViewCreateFlags>;

				      EType                   SType           ;			
				const void*                   Next            ;
				      CreateFlags             Flags           ;
				      Image::Handle           Image           ;
				      EViewType               ViewType        ;
				      EFormat                 Format          ;
				      ComponentMapping        Components      ;
				      Image::SubresourceRange SubresourceRange;
			};

			/**
			 * @brief Create an image view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateImageView">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _imageView
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _creationSpec,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _imageView
			)
			{
				return EResult(vkCreateImageView(_deviceHandle, _creationSpec, _allocator->operator const VkAllocationCallbacks*(), &_imageView));
			}

			/**
			 * @brief Destroy an image view.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyImageView">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _imageView
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle _deviceHandle,
				      Handle                _imageView   ,
				const Memory::AllocationCallbacks*  _allocator
			)
			{
				vkDestroyImageView(_deviceHandle, _imageView, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-sets">Specification</a>
		 */
		struct DescriptorSet
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSet">Specification</a>  */
			using Handle = VkDescriptorSet;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetAllocateInfo">Specification</a>  */
			struct AllocateInfo : Vault_00::VKStruct_Base<VkDescriptorSetAllocateInfo, EStructureType::Descriptor_SetAllocateInfo>
			{
				using PipelineLayoutDescriptorSetHandle = VkDescriptorSetLayout;   // Pipeline definitions not defined yet.

					  EType                              SType             ;
				const void*                              Next              ;
					  DescriptorPool::Handle             DescriptorPool    ;
					  uint32                             DescriptorSetCount;
				const PipelineLayoutDescriptorSetHandle* SetLayouts        ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBufferInfo">Specification</a>  */
			struct BufferInfo : Vault_00::VKStruct_Base<VkDescriptorBufferInfo>
			{
				Buffer::Handle Buffer;
				DeviceSize     Offset;
				DeviceSize     Range ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCopyDescriptorSet">Specification</a>  */
			struct Copy : Vault_00::VKStruct_Base<VkCopyDescriptorSet>
			{
				      EType  SType          ;
				const void*  Next           ;
				      Handle SrcSet         ;
				      uint32 SrcBinding     ;
				      uint32 SrcArrayElement;
				      Handle DstSet         ;
				      uint32 DstBinding     ;
				      uint32 DstArrayElement;
				      uint32 DescriptorCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorImageInfo">Specification</a>  */
			struct ImageInfo : Vault_00::VKStruct_Base<VkDescriptorImageInfo>
			{
				Sampler::Handle   Sampler    ;
				ImageView::Handle ImageView  ;
				EImageLayout      ImageLayout;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWriteDescriptorSet">Specification</a>  */
			struct Write : Vault_00::VKStruct_Base<VkWriteDescriptorSet, EStructureType::WriteDescriptor_Set>
			{
				      EType               SType          ;
				const void*               Next           ;
				      Handle              DstSet         ;
				      uint32              DstBinding     ;
				      uint32              DstArrayElement;
				      uint32              DescriptorCount;
				      EDescriptorType     DescriptorType ;
				const ImageInfo*          ImageInfo      ;
				const BufferInfo*         BufferInfo     ;
				const BufferView::Handle* TexelBufferView;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateDescriptorSets">Specification</a> 
			 * 
			 * \param _device
			 * \param _allocateInfo
			 * \param _descriptorSets
			 * \return 
			 */
			static EResult Allocate
			(
					  LogicalDevice::Handle _device        ,
				const AllocateInfo&         _allocateInfo  ,
					  Handle*               _descriptorSets
			)
			{
				return EResult(vkAllocateDescriptorSets(_device, _allocateInfo, _descriptorSets));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeDescriptorSets">Specification</a> 
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _descriptorSetCount
			 * \param _descriptorSets
			 * \return 
			 */
			static EResult Free
			(
				      LogicalDevice::Handle  _device            ,
				      DescriptorPool::Handle _descriptorPool    ,
				      uint32                 _descriptorSetCount,
				const Handle*                _descriptorSets
			)
			{
				return EResult(vkFreeDescriptorSets(_device, _descriptorPool, _descriptorSetCount, _descriptorSets));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkUpdateDescriptorSets">Specification</a> .
			 * 
			 * \param _device
			 * \param _descriptorWriteCount
			 * \param _descriptorWrites
			 * \param _descriptorCopyCount
			 * \param _descriptorCopies
			 */
			static void Update
			(
				      LogicalDevice::Handle _device              ,
				      uint32                _descriptorWriteCount,
				const Write*                _descriptorWrites    ,
				      uint32                _descriptorCopyCount ,
				const Copy*                 _descriptorCopies
			)
			{
				vkUpdateDescriptorSets(_device, _descriptorWriteCount, _descriptorWrites->operator const VkWriteDescriptorSet*(), _descriptorCopyCount, _descriptorCopies->operator const VkCopyDescriptorSet*());
			}
		};	
	}
}
