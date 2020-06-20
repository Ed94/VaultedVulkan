/** 
@file VT_Resource.hpp

@brief Vaulted Thermals: Resources

@details
Vulkan supports two primary resource types: buffers and images. 
Resources are views of memory with associated formatting and dimensionality. 
Buffers are essentially unformatted arrays of bytes whereas images contain format information, 
can be multidimensional and may have associated metadata.

<a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#resources">Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Enums.hpp"
#include "VT_Constants.hpp"
#include "VT_Initialization.hpp"
#include "VT_Queues.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_LogicalDevice.hpp"



namespace VaultedThermals
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
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#resources-buffers">Specification</a> 
		 */
		struct Buffer
		{
			using Handle = VkBuffer;

			using ECreateFlag = EBufferCreateFlag;

			using CreateFlag = Bitmask<EBufferCreateFlag, VkBufferCreateFlags>;

			using EUsage = EBufferUsage;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSharingMode.html">Specification</a>
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkBufferCreateInfo>
			{
				      EType        SType                ;
				const void*        Next                 ;
				      CreateFlag   Flags                ;
					  DeviceSize   Size                 ;
					  EUsage       Usuage               ;
				      ESharingMode SharingMode          ;
					  uint32       QueueFamilyIndexCount;
			};

			/**
			 * @brief Create a new buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateBuffer.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _buffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, const AllocationCallbacks* _allocator, Buffer::Handle& _buffer)
			{
				return EResult(vkCreateBuffer(_deviceHandle, _createInfo.operator const VkBufferCreateInfo*(), _allocator, &_buffer));
			}

			/**
			 * @brief Destroy a buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyBuffer.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _buffer
			 * \param _allocator
			 * \return 
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Buffer::Handle _buffer, const AllocationCallbacks* _allocator)
			{
				vkDestroyBuffer(_deviceHandle, _buffer, _allocator);
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
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#resources-buffer-views">Specification</a> 
		 */
		struct BufferView
		{
			using Handle = VkBufferView;

			using CreateFlags = Bitmask<EUndefined, VkBufferViewCreateFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBufferViewCreateInfo.html">Specification</a> .
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkBufferViewCreateInfo >
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
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateBufferView.html">Specification</a> .
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _bufferView
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _creationSpec, const AllocationCallbacks* _allocator, BufferView::Handle& _bufferView)
			{
				return EResult(vkCreateBufferView(_deviceHandle, _creationSpec.operator const VkBufferViewCreateInfo*(), _allocator, &_bufferView));
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
			static void Destroy(LogicalDevice::Handle _deviceHandle, BufferView::Handle _bufferView, const AllocationCallbacks* _allocator)
			{
				vkDestroyBufferView(_deviceHandle, _bufferView, _allocator);
			}
		};

		/** 
		@brief
		Images represent multidimensional - up to 3 - arrays of data which can be used for various purposes 
		(e.g. attachments, textures), by binding them to a graphics or compute pipeline via descriptor sets, 
		or by directly specifying them as parameters to certain commands.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#resources-images">Specification</a> 
		*/
		struct Image
		{
			using Handle = VkImage;

			using ECreateFlag = EImageCreateFlag;

			using CreateFlags = Bitmask<EImageCreateFlag, VkImageCreateFlags>;

			using ETiling = EImageTiling;
			using EUsage = EImageUsage ;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkImageCreateInfo.html">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkImageCreateInfo>
			{
				      EType        SType             ;
				const void*        Next              ;
				      CreateFlags  Flags             ;
				      EImageType   ImageType         ;
				      EFormat      Format            ;
				      Extent3D     Extent            ;
				      uint32       MipmapLevels      ;
				      uint32       ArrayLayers       ;
				      ESampleCount Samples           ;
				      ETiling      Tiling            ;
				      EUsage       Usage             ;
				      ESharingMode SharingMode       ;
				      uint32       QueueFamilyIndices;
				const uint32*      QueueFamilyIndices;
					  EImageLayout InitalLayout      ;
			};

			/**  
			 * @brief  Create an image object.
			 * 
			 * @details <a href="https:www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateImage.html">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _imageHandle
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, const AllocationCallbacks* _allocator, Image::Handle& _imageHandle)
			{
				return EResult(vkCreateImage(_deviceHandle, _createInfo.operator const VkImageCreateInfo*(), _allocator, &_imageHandle));
			}

			/** 
			 * @brief Destroy an image object.
			 * 
			 * @details <a href="https:www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyImage.html">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _image
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _image, const AllocationCallbacks* _allocator)
			{
				vkDestroyImage(_deviceHandle, _image, _allocator);
			}
		};

		/**
		* @brief An object that represents an image subresource range of a specific image, 
		* and state that controls how the contents are interpreted.
		*/
		struct ImageView
		{
			using AspectFlags = Bitmask<EImageAspect, VkImageAspectFlags>;

			using Handle = VkImageView;

			using EViewType = EImageViewType;

			/** @brief <a href="linkURL">Specification</a>  */
			struct SubresourceRange : Vault_00::VKStruct_Base<VkImageSubresourceRange>
			{
				AspectFlags AspectMask    ;
				uint32      BaseMipLevel  ;
				uint32      LevelCount    ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** @brief <a href="linkURL">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkImageViewCreateInfo>
			{
				using CreateFlags = Bitmask<EImageViewCreateFlag, VkImageViewCreateFlags>;

				EStructureType   SType           ;			
				const void*      Next            ;
				CreateFlags      Flags           ;
				Image::Handle    Image           ;
				EViewType        ViewType        ;
				EFormat          Format          ;
				ComponentMapping Components      ;
				SubresourceRange SubresourceRange;
			};

			/**
			 * @brief Create an image view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateImageView.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _imageView
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _creationSpec,
				const AllocationCallbacks*  _allocator   ,
				      Handle*               _imageView
			)
			{
				return EResult(vkCreateImageView(_deviceHandle, _creationSpec, _allocator, (VkImageView*)(_imageView)));
			}

			/**
			 * @brief Destroy an image view.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyImageView.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _imageView
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle _deviceHandle,
				      Handle                _imageView   ,
				const AllocationCallbacks*  _allocator
			)
			{
				vkDestroyImageView(_deviceHandle, _imageView, _allocator);
			}
		};
	}
}
