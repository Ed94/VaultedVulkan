/*!
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
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"



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
		*/

		/**
		 * @brief A linear array of data.
		 * 
		 * @details
		 * Buffers represent linear arrays of data which are used for various purposes by binding them
		 * to a graphics or compute pipeline via descriptor sets or via certain commands, or by
		 * directly specifying them as parameters to certain commands.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-buffers">Specification</a> 
		 * 
		 * @ingroup	APISpec_Resource_Creation
		 */
		struct Buffer
		{
			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBuffer">Specification</a>  
			@ingroup APISpec_Resource_Creation
			*/
			using Handle = VkBuffer;

			using ECreateFlag = EBufferCreateFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using CreateFlags = Bitmask<EBufferCreateFlag, VkBufferCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferUsageFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using UsageFlags = Bitmask<EBufferUsage, VkBufferUsageFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateInfo">Specification</a>
			 * @ingroup APISpec_Resource_Creation
			 */
			struct CreateInfo : V0::VKStruct_Base<VkBufferCreateInfo, EStructureType::Buffer_CreateInfo>
			{
				      EType        SType                ;
				const void*        Next                 ;
				      CreateFlags  Flags                ;
					  DeviceSize   Size                 ;
					  UsageFlags   Usage                ;
				      ESharingMode SharingMode          ;
					  uint32       QueueFamilyIndexCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCopy">Specification</a> @ingroup APISpec_Copy_Commands */
			struct CopyInfo : V0::VKStruct_Base<VkBufferCopy>
			{
				DeviceSize SourceOffset;
				DeviceSize DestinationOffset;
				DeviceSize Size;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferMemoryBarrier">Specification</a>
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			struct Memory_Barrier : V0::VKStruct_Base<VkBufferMemoryBarrier, EStructureType::BufferMemory_Barrier>
			{
				      EType       SType              ;
				const void*       Next               ;
				      AccessFlags SrcAccessMask      ;
				      AccessFlags DstAccessMask      ;
				      uint32      SrcQueueFamilyIndex;
				      uint32      DstQueueFamilyIndex;
				      Handle      Buffer             ;
				      DeviceSize  Offset             ;
				      DeviceSize  Size               ;
			};

			/**
			 * @brief Attach memory to a buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBindBufferMemory">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Creation
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
				Handle                _buffer      ,
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
			 * @ingroup APISpec_Resource_Creation
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _buffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator, Handle& _buffer)
			{
				return EResult(vkCreateBuffer(_device, _createInfo.operator const VkBufferCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_buffer));
			}

			

			/**
			 * @brief Destroy a buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyBuffer">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Creation
			 * 
			 * \param _deviceHandle
			 * \param _buffer
			 * \param _allocator
			 * \return 
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _buffer, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyBuffer(_device, _buffer, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetBufferMemoryRequirements">Specification</a>
			 * 
			 * @ingroup APISpec_Resource_Creation
			 * 
			 * \param _device
			 * \param _buffer
			 * \param _memoryRequirements
			 */
			static void GetMemoryRequirements
			(
				LogicalDevice::Handle _device             ,
				Handle                _buffer             ,
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
		 * 
		 * @ingroup APISpec_Resource_Creation
		 */
		struct BufferView
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferView">Specification</a> @ingroup APISpec_Resource_Creation */
			using Handle = VkBufferView;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferViewCreateFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using CreateFlags = Bitmask<EUndefined, VkBufferViewCreateFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBufferViewCreateInfo.html">Specification</a> 
			 * @ingroup APISpec_Resource_Creation
			 */
			struct CreateInfo : V0::VKStruct_Base<VkBufferViewCreateInfo, EStructureType::BufferView_CreateInfo>
			{
				      EType          SType  ;
				const void*          Next   ;
				      CreateFlags    Flags  ;
				      Buffer::Handle VBuffer;
				      EFormat        Format ;
				      DeviceSize     Offset ;
				      DeviceSize     Range  ;
			};

			/**
			 * @brief Create a new buffer view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateBufferView">Specification</a>.
			 * 
			 * @ingroup APISpec_Resource_Creation
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _bufferView
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _info, const Memory::AllocationCallbacks* _allocator, Handle& _bufferView)
			{
				return EResult(vkCreateBufferView(_device, _info.operator const VkBufferViewCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_bufferView));
			}

			/**
			 * @brief Destroy a buffer view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyBufferView.html">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Creation
			 * 
			 * \param _deviceHandle
			 * \param _bufferView
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _bufferView, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyBufferView(_device, _bufferView, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/** 
		@brief
		Images represent multidimensional - up to 3 - arrays of data which can be used for various purposes 
		(e.g. attachments, textures), by binding them to a graphics or compute pipeline via descriptor sets, 
		or by directly specifying them as parameters to certain commands.

		@details
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-images">Specification</a> 

		@ingroup APISpec_Resource_Creation
		*/
		struct Image
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImage">Specification</a> @ingroup APISpec_Resource_Creation */
			using Handle = VkImage;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageAspectFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using AspectFlags = Bitmask<EImageAspect, VkImageAspectFlags>;

			using ECreateFlag = EImageCreateFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using CreateFlags = Bitmask<EImageCreateFlag, VkImageCreateFlags>;

			using ETiling = EImageTiling;

			using EUsage = EImageUsage;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageUsageFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using UsageFlags = Bitmask<EImageUsage, VkImageUsageFlags>;   ///< Bitmask specifying intended usage of an image.

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateInfo">Specification</a> @ingroup APISpec_Resource_Creation */
			struct CreateInfo : V0::VKStruct_Base<VkImageCreateInfo, EStructureType::Image_CreateInfo>
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

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageSubresourceLayers">Specification</a>  
			@ingroup APISpec_Copy_Commands
			*/
			struct SubresourceLayers : V0::VKStruct_Base<VkImageSubresourceLayers>
			{
				AspectFlags AspectMask    ;
				uint32      MipLevel      ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageSubresourceRange">Specification</a>  
			@ingroup APISpec_Resource_Creation
			*/
			struct SubresourceRange : V0::VKStruct_Base<VkImageSubresourceRange>
			{
				AspectFlags AspectMask    ;
				uint32      BaseMipLevel  ;
				uint32      LevelCount    ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageMemoryBarrier">Specification</a>  
			@ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct Memory_Barrier : V0::VKStruct_Base<VkImageMemoryBarrier, EStructureType::ImageMemory_Barrier>
			{
				      EType            SType              ;
				const void*            Next               ;
				      AccessFlags      SrcAccessMask      ;
				      AccessFlags      DstAccessMask      ;
				      EImageLayout     OldLayout          ;
				      EImageLayout     NewLayout          ;
				      uint32           SrcQueueFamilyIndex;
				      uint32           DstQueueFamilyIndex;
				      Handle           Image              ;
				      SubresourceRange SubresourceRange   ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageBlit">Specification</a>  
			@ingroup APISpec_Copy_Commands
			*/
			struct Blit : V0::VKStruct_Base<VkImageBlit>
			{
				SubresourceLayers SrcSubresource;
				Offset3D          SrcOffsets[2] ;
				SubresourceLayers DstSubresource;
				Offset3D          DstOffsets[2] ;
			};

			/**
			 * @brief Attach memory to a VkImage object created without the VK_IMAGE_CREATE_DISJOINT_BIT set.
			 *
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBindImageMemory">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Creation
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
			 * @ingroup APISpec_Resource_Creation
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _imageHandle
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator, Handle& _imageHandle)
			{
				return EResult(vkCreateImage(_deviceHandle, _createInfo.operator const VkImageCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_imageHandle));
			}

			/** 
			 * @brief Destroy an image object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyImage">Specification</a>.
			 * @ingroup APISpec_Resource_Creation
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
			 * @ingroup APISpec_Resource_Creation
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
		* 
		* @ingroup APISpec_Resource_Creation
		*/
		struct ImageView
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageView">Specification</a> @ingroup APISpec_Resource_Creation */
			using Handle = VkImageView;

			using EViewType = EImageViewType;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateFlags">Specification</a> @ingroup APISpec_Resource_Creation */
			using CreateFlags = Bitmask<EImageViewCreateFlag, VkImageViewCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateInfo">Specification</a> @ingroup APISpec_Resource_Creation */
			struct CreateInfo : V0::VKStruct_Base<VkImageViewCreateInfo, EStructureType::ImageView_CreateInfo>
			{
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
			 * @ingroup APISpec_Resource_Creation
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
			 * @ingroup APISpec_Resource_Creation
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
		 * @brief Descriptors are grouped together into descriptor set objects. A descriptor set object is an opaque object containing storage for a set of descriptors,
		 * where the types and number of descriptors is defined by a descriptor set layout.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-sets">Specification</a>
		 * 
		 * @ingroup APISpec_Resource_Descriptors
		 */
		struct DescriptorSet
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSet">Specification</a> @ingroup APISpec_Resource_Descriptors */
			using Handle = VkDescriptorSet;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBufferInfo">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct BufferInfo : V0::VKStruct_Base<VkDescriptorBufferInfo>
			{
				Buffer::Handle Buffer;
				DeviceSize     Offset;
				DeviceSize     Range ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCopyDescriptorSet">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct Copy : V0::VKStruct_Base<VkCopyDescriptorSet>
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

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorImageInfo">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct ImageInfo : V0::VKStruct_Base<VkDescriptorImageInfo>
			{
				Sampler::Handle   Sampler    ;
				ImageView::Handle ImageView  ;
				EImageLayout      ImageLayout;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWriteDescriptorSet">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct Write : V0::VKStruct_Base<VkWriteDescriptorSet, EStructureType::WriteDescriptor_Set>
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkUpdateDescriptorSets">Specification</a>.
			 * 
			 * @ingroup APISpec_Resource_Descriptors
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

		/**
		@brief A descriptor pool maintains a pool of descriptors, from which descriptor sets are allocated. Descriptor pools are externally synchronized, 
		meaning that the application must not allocate and/or free descriptor sets from the same pool in multiple threads simultaneously.

		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-allocation">Specification</a> 

		@ingroup APISpec_Resource_Descriptors
		*/
		struct DescriptorPool
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPool">Specification</a> @ingroup APISpec_Resource_Descriptors */
			using Handle = VkDescriptorPool;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateFlags">Specification</a> @ingroup APISpec_Resource_Descriptors */
			using CreateFlags = Bitmask<EDescriptorPoolCreateFlag, VkDescriptorPoolCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolResetFlags">Specification</a> @ingroup APISpec_Resource_Descriptors */
			using ResetFlags = Bitmask<EUndefined, VkDescriptorPoolResetFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetAllocateInfo">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct AllocateInfo : V0::VKStruct_Base<VkDescriptorSetAllocateInfo, EStructureType::Descriptor_SetAllocateInfo>
			{
				using PipelineLayoutDescriptorSetHandle = VkDescriptorSetLayout;   // Pipeline definitions not defined yet.

					  EType                              SType             ;
				const void*                              Next              ;
					  Handle                             DescriptorPool    ;
					  uint32                             DescriptorSetCount;
				const PipelineLayoutDescriptorSetHandle* SetLayouts        ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolSize">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct Size : V0::VKStruct_Base<VkDescriptorPoolSize>
			{
				EDescriptorType Type ;
				uint32          Count;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateInfo">Specification</a> @ingroup APISpec_Resource_Descriptors */
			struct CreateInfo : V0::VKStruct_Base<VkDescriptorPoolCreateInfo, EStructureType::Descriptor_Pool_CreateInfo>
			{
					  EType       SType        ;
				const void*       Next         ;
					  CreateFlags Flags        ;
					  uint32      MaxSets      ;
					  uint32      PoolSizeCount;
				const Size*       PoolSizes    ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateDescriptorSets">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Descriptors
			 * 
			 * \param _device
			 * \param _allocateInfo
			 * \param _descriptorSets
			 * \return 
			 */
			static EResult Allocate
			(
					  LogicalDevice::Handle  _device        ,
				const AllocateInfo&          _allocateInfo  ,
					  DescriptorSet::Handle* _descriptorSets
			)
			{
				return EResult(vkAllocateDescriptorSets(_device, _allocateInfo, _descriptorSets));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDescriptorPool">Specification</a>
			 * 
			 * @ingroup APISpec_Resource_Descriptors
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
			 * @ingroup APISpec_Resource_Descriptors
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _device,
				      Handle                       _descriptorPool,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyDescriptorPool(_device, _descriptorPool, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeDescriptorSets">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Descriptors
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
				      Handle                 _descriptorPool    ,
				      uint32                 _descriptorSetCount,
				const DescriptorSet::Handle* _descriptorSets
			)
			{
				return EResult(vkFreeDescriptorSets(_device, _descriptorPool, _descriptorSetCount, _descriptorSets));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetDescriptorPool">Specification</a> 
			 * 
			 * @ingroup APISpec_Resource_Descriptors
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _flags
			 * \return 
			 */
			static EResult Reset
			(
				LogicalDevice::Handle _device        ,
				Handle                _descriptorPool,
				ResetFlags&           _flags
			)
			{
				return EResult(vkResetDescriptorPool(_device, _descriptorPool, _flags));
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

		struct Buffer : V1::Buffer
		{
			using Parent = V1::Buffer;

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo() 
				{
					SType                 = STypeEnum;
					Next                  = nullptr  ;
					Size                  = 0        ;
					QueueFamilyIndexCount = 0        ;
				}

				CreateInfo(UsageFlags _usage, ESharingMode _sharingMode)
				{
					SType                 = STypeEnum   ;
					Next                  = nullptr     ;
					Size                  = 0           ;
					Usage                 = _usage      ;
					SharingMode           = _sharingMode;
					QueueFamilyIndexCount = 0           ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct Memory_Barrier : Parent::Memory_Barrier
			{
				Memory_Barrier()
				{
					SType = STypeEnum;

					Next = nullptr;
				}
			};

			/**
			 * @brief Create a new buffer object. (Default allocator)
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _buffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _createInfo, Handle& _buffer)
			{
				return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _buffer);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a buffer object. (Default allocator)

			 * \param _deviceHandle
			 * \param _buffer
			 * \param _allocator
			 * \return 
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _buffer)
			{
				Parent::Destroy(_device, _buffer, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Will create a buffer and immediately bind it to allocated memory made just for it.
			 * 
			 * \param _bufferInfo
			 * \param _propertyFlags
			 * \param _buffer
			 * \param _bufferMemory
			 * \param _bufferMemoryOffset
			 * \param _physicalDevice
			 * \param _device
			 * \param _allcator
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle _physicalDevice,
				LogicalDevice::Handle  _device        ,
				CreateInfo             _bufferInfo    ,
				Handle&                _buffer        , 
				Memory::PropertyFlags  _propertyFlags , 
				Memory::Handle&        _bufferMemory      
			)
			{
				EResult returnCode = Buffer::Create(_device, _bufferInfo, Memory::DefaultAllocator, _buffer);

				if (returnCode != EResult::Success)
					return returnCode;

				Memory::Requirements memReq;

				Buffer::GetMemoryRequirements(_device, _buffer, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, Memory::DefaultAllocator, _bufferMemory);

				if (returnCode != EResult::Success)
					return returnCode;

				Buffer::BindMemory(_device, _buffer, _bufferMemory, Memory::ZeroOffset);

				return returnCode;
			}

			/**
			 * @brief Will create a buffer and immediately bind it to allocated memory made just for it.
			 * 
			 * \param _bufferInfo
			 * \param _propertyFlags
			 * \param _buffer
			 * \param _bufferMemory
			 * \param _bufferMemoryOffset
			 * \param _physicalDevice
			 * \param _device
			 * \param _allcator
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle       _physicalDevice,
				LogicalDevice::Handle        _device        ,
				CreateInfo                   _bufferInfo    ,
				Handle&                      _buffer        , 
				Memory::PropertyFlags        _propertyFlags , 
				Memory::Handle&              _bufferMemory  ,
				Memory::AllocationCallbacks* _allcator
			)
			{
				EResult returnCode = Buffer::Create(_device, _bufferInfo, _allcator, _buffer);

				if (returnCode != EResult::Success) return returnCode;

				Memory::Requirements memReq;

				Buffer::GetMemoryRequirements(_device, _buffer, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, _allcator, _bufferMemory);

				if (returnCode != EResult::Success) return returnCode;

				Buffer::BindMemory(_device, _buffer, _bufferMemory, Memory::ZeroOffset);

				return returnCode;
			}
		};

		struct BufferView : public V1::BufferView
		{
			using Parent = V1::BufferView;

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			* @brief Create a new buffer view object.
			* 
			* \param _deviceHandle
			* \param _creationSpec
			* \param _allocator
			* \param _bufferView
			* \return 
			*/
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _info, Handle& _bufferView)
			{
				return Parent::Create(_device, _info, Memory::DefaultAllocator, _bufferView);
			}

			using Parent::Create;

			/**
			* @brief Destroy a buffer view object.
			* 
			* \param _deviceHandle
			* \param _bufferView
			* \param _allocator
			*/
			static void Destroy(LogicalDevice::Handle _device, Handle _bufferView)
			{
				Parent::Destroy(_device, _bufferView, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		struct Image : public V1::Image
		{
			using Parent = V1::Image;

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct Memory_Barrier : public Parent::Memory_Barrier
			{
				Memory_Barrier()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**  
			 * @brief  Create an image object.
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _imageHandle
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, Handle& _imageHandle)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _imageHandle);
			}

			using Parent::Create;

			/** 
			 * @brief Destroy an image object.
			 * 
			 * \param _deviceHandle
			 * \param _image
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _image)
			{
				Parent::Destroy(_deviceHandle, _image, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Will create an image and immediately bind it to memory made just for it.
			 * 
			 * \param _physicalDevice
			 * \param _device
			 * \param _info
			 * \param _image
			 * \param _propertyFlags
			 * \param _imageMemory
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle _physicalDevice,
				LogicalDevice::Handle  _device        ,
				CreateInfo             _info          ,
				Handle&                _image         , 
				Memory::PropertyFlags  _propertyFlags , 
				Memory::Handle&        _imageMemory      
			)
			{
				EResult returnCode = Image::Create(_device, _info, _image);

				if (returnCode != EResult::Success)
					return returnCode;

				Memory::Requirements memReq;

				Image::GetMemoryRequirements(_device, _image, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, _imageMemory);

				if (returnCode != EResult::Success)
					return returnCode;

				Image::BindMemory(_device, _image, _imageMemory, Memory::ZeroOffset);

				return returnCode;
			}

			/**
			 * @brief Will create an image and immediately bind it to memory made just for it..
			 * 
			 * \param _physicalDevice
			 * \param _device
			 * \param _info
			 * \param _image
			 * \param _propertyFlags
			 * \param _imageMemory
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle       _physicalDevice,
				LogicalDevice::Handle        _device        ,
				CreateInfo                   _info          ,
				Handle&                      _image         , 
				Memory::PropertyFlags        _propertyFlags , 
				Memory::Handle&              _imageMemory   ,
				Memory::AllocationCallbacks* _allcator
			)
			{
				EResult returnCode = Image::Create(_device, _info, _allcator, _image);

				if (returnCode != EResult::Success)
					return returnCode;

				Memory::Requirements memReq;

				Image::GetMemoryRequirements(_device, _image, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, _allcator, _imageMemory);

				if (returnCode != EResult::Success)
					return returnCode;

				Image::BindMemory(_device, _image, _imageMemory, Memory::ZeroOffset);

				return returnCode;
			}
		};

		struct ImageView : public V1::ImageView
		{
			using Parent = V1::ImageView;

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;

					Components.R = Corridors::EComponentSwizzle::R;
					Components.G = Corridors::EComponentSwizzle::G;
					Components.B = Corridors::EComponentSwizzle::B;
					Components.A = Corridors::EComponentSwizzle::A;
				}
			};

			/**
			 * @brief Create an image view object.
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
				      Handle&                      _imageView
			)
			{
				return Parent::Create(_deviceHandle, _creationSpec, Memory::DefaultAllocator, _imageView);
			}

			using Parent::Create;

			/**
			 * @brief Destroy an image view.
			 * 
			 * \param _deviceHandle
			 * \param _imageView
			 * \param _allocator
			 */
			static void Destroy
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _imageView   
			)
			{
				return Parent::Destroy(_deviceHandle, _imageView, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		struct DescriptorSet : public V1::DescriptorSet
		{
			using Parent = V1::DescriptorSet;

			/**
			@brief Offers a default constructor.
			*/
			struct Copy : public Parent::Copy
			{
				Copy()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct Write : public Parent::Write
			{
				Write()
				{
					SType = STypeEnum;
					Next  = nullptr;
				}
			};
		};

		struct DescriptorPool : public V1::DescriptorPool
		{
			using Parent = V1::DescriptorPool;

			/**
			@brief Offers a default constructor.
			*/
			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			@brief Offers a default constructor.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _descriptorPool
			 * \return 
			 */
			static EResult Create
			(
					  LogicalDevice::Handle _device        ,
				const CreateInfo&           _createInfo    ,
					  Handle&               _descriptorPool
			)
			{
				return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _descriptorPool);
			}

			using Parent::Create;

			/**
			 * \param _device
			 * \param _descriptorPool
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _descriptorPool)
			{
				Parent::Destroy(_device, _descriptorPool, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			static EResult Free
			(
				      LogicalDevice::Handle  _device,
				const AllocateInfo&          _info,
				const DescriptorSet::Handle* _descriptorSets
			)
			{
				return Parent::Free(_device, _info.DescriptorPool, _info.DescriptorSetCount, _descriptorSets);
			}

			using Parent::Free;
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		class Buffer : public V2::Buffer
		{
		public:

			using Parent = V2::Buffer;

			EResult BindMemory(const Memory& _memory, DeviceSize _memoryOffset)
			{
				memory       = &_memory     ;
				memoryOffset = _memoryOffset;

				return Parent::BindMemory(*device, handle, *memory, memoryOffset);
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Parent::Create(*device, _info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(*device, handle, memoryRequirements);
				
				return returnCode;
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				EResult returnCode = Parent::Parent::Create(*device, _info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(*device, handle, memoryRequirements);
				
				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&        _device        ,  
				const CreateInfo&           _info          ,  
				      Memory::PropertyFlags _memoryFlags   ,
				      Memory&               _memory
			)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Create(*device, _info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(*device, handle, memoryRequirements);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(*device, allocationInfo, *allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory, Memory::ZeroOffset);

				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&               _device        ,  
				const CreateInfo&                  _info          , 
				      Memory::PropertyFlags        _memoryFlags   ,
				      Memory&                      _memory        ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = &_device   ;
				allocator = _allocator ;

				EResult returnCode = Parent::Create(*device, _info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(*device, handle, memoryRequirements);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(*device, allocationInfo, *allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory, Memory::ZeroOffset);

				return returnCode;
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			const Memory::Requirements& GetMemoryRequirements() const
			{
				return memoryRequirements;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle*()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const Buffer& _other) const 
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			//CreateInfo info;

			const LogicalDevice* device;

			const Memory* memory;

			DeviceSize memoryOffset;

			Memory::Requirements memoryRequirements;

			const Memory::AllocationCallbacks* allocator;
		};

		class BufferView : public V2::BufferView
		{
		public:
			using Parent = V2::BufferView;

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const BufferView& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			//CreateInfo info;

			const LogicalDevice* device;

			const Memory::AllocationCallbacks* allocator;
		};

		class Image : public V2::Image
		{
		public:
			using Parent = V2::Image;


			void Assign(const LogicalDevice& _device, Handle _handle)
			{
				device = &_device;
				handle = _handle;
			}

			EResult BindMemory(const Memory& _memory, DeviceSize _memoryOffset)
			{
				memory       = &_memory     ;
				memoryOffset = _memoryOffset;

				return Parent::BindMemory(*device, handle, *memory, memoryOffset);
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Create(*device, _info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(*device, handle, memoryRequirements);

				return returnCode;
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				EResult returnCode = Parent::Create(*device, _info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(*device, handle, memoryRequirements);

				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&        _device     ,  
				const CreateInfo&           _info       ,  
				      Memory::PropertyFlags _memoryFlags,
				      Memory&               _memory
			)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				//EResult returnCode = Parent::Create(*device, _info, allocator, handle);

				//if (returnCode != EResult::Success) return returnCode;

				//Parent::GetMemoryRequirements(*device, handle, memoryRequirements);

				EResult returnCode = Create(_device, _info);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(*device, allocationInfo, *allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory, Memory::ZeroOffset);

				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&               _device        ,  
				const CreateInfo&                  _info          , 
				      Memory::PropertyFlags        _memoryFlags   ,
				      Memory&                      _memory        ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = &_device  ;
				allocator = _allocator;

				/*EResult returnCode = Parent::Create(*device, _info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(*device, handle, memoryRequirements);*/

				EResult returnCode = Create(_device, _info, *allocator);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(*device, allocationInfo, *allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory, Memory::ZeroOffset);

				return returnCode;
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			const Memory::Requirements& GetMemoryRequirements() const
			{
				return memoryRequirements;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const Image& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			//CreateInfo info;

			const Memory* memory;

			DeviceSize memoryOffset;

			Memory::Requirements memoryRequirements;

			const LogicalDevice* device;
		};

		class ImageView : public V2::ImageView
		{
		public:
			using Parent = V2::ImageView;

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const ImageView& _other) const
			{
				return handle == _other.handle;
			}

		protected:	

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			//CreateInfo info;

			const LogicalDevice* device;
		};

		class DescriptorSet : public V2::DescriptorSet
		{
		public:
			using Parent = V2::DescriptorSet;

			void Assign(const LogicalDevice& _device, Handle _handle)
			{
				device = &_device;
				handle = _handle ;
			}
			
			const Handle& GetHandle() const
			{
				return handle;
			}

			void Update
			(
				      uint32                _descriptorWriteCount,
				const Write*                _descriptorWrites    ,
				      uint32                _descriptorCopyCount ,
				const Copy*                 _descriptorCopies
			)
			{
				Parent::Update(*device, _descriptorWriteCount, _descriptorWrites, _descriptorCopyCount, _descriptorCopies);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const DescriptorSet& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const LogicalDevice* device;
		};

		class DescriptorPool : public V2::DescriptorPool
		{
		public:
			using Parent = V2::DescriptorPool;


			EResult Allocate(AllocateInfo& _info, DescriptorSet::Handle* _handlesContainer)
			{
				return Parent::Allocate(*device, _info, _handlesContainer);
			}

			EResult Allocate
			(
				AllocateInfo&                        _info   ,
				DynamicArray<DescriptorSet>&         _sets   ,
				DynamicArray<DescriptorSet::Handle>& _handles
			)
			{
				_sets.resize(_info.DescriptorSetCount); _handles.resize(_info.DescriptorSetCount);

				EResult returnCode = Parent::Allocate(*device, _info, _handles.data());

				if (returnCode != EResult::Success) return returnCode;

				for (DeviceSize index = 0; index < _info.DescriptorSetCount; index++)
				{
					_sets[index].Assign(*device, _handles[index]);
				}

				return returnCode;
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    = &_device                ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			EResult Free(uint32 _count, DescriptorSet::Handle* _handles)
			{
				return Parent::Free(*device, handle, _count, _handles);
			}

			EResult Free(DynamicArray<DescriptorSet::Handle> _handles)
			{
				return Parent::Free(*device, handle, static_cast<uint32>(_handles.size()), _handles.data());
			}

			EResult Reset(ResetFlags& _flags)
			{
				return Parent::Reset(*device, handle, _flags);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle* ()
			{
				return &handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

			operator const Handle* () const
			{
				return &handle;
			}

			bool operator== (const DescriptorPool& _other) const
			{
				return handle == _other.handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/** @} */
	}
}
