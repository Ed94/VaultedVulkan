/*


*/



#pragma once


#include "VT_Enums.hpp"
#include "VT_Types.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{

	}

	/**
	 * @brief An object that represents an image subresource range of a specific image, 
	 * and state that controls how the contents are interpreted.
	 */
	struct ImageView
	{
		using AspectFlags = Bitmask<EImageAspect, Flags>;

		using Handle = VkImageView;

		struct SubresourceRange
		{
			AspectFlags AspectMask    ;
			uint32      BaseMipLevel  ;
			uint32      LevelCount    ;
			uint32      BaseArrayLayer;
			uint32      LayerCount    ;
		};

		struct CreateInfo
		{
			using CreateFlags = Bitmask<EImageViewCreateFlag, Flags>;

			      EStructureType            SType           ;			
			const void*                     Extensions      ;
			      CreateFlags               Flags           ;
			      Image::Handle             Image           ;
			      EImageViewType            ViewType        ;
			      EImageFormat              Format          ;
			      ComponentMapping          Components      ;
				  SubresourceRange          SubresourceRange;


			operator VkImageViewCreateInfo()
			{
				return *(VkImageViewCreateInfo*)(this);
			}
		};
	};


	inline EResult CreateImageView
	(
		      LogicalDevice::Handle  _deviceHandle,
		const ImageView::CreateInfo& _creationSpec,
		const AllocationCallbacks*   _allocator   ,
		      ImageView::Handle*     _imageView
	)
	{
		return EResult(vkCreateImageView(_deviceHandle, (VkImageViewCreateInfo*)(&_creationSpec), _allocator, (VkImageView*)(_imageView)));
	}

	inline void DestroyImageView
	(
		      LogicalDevice::Handle _deviceHandle,
		      ImageView::Handle     _imageView   ,
		const AllocationCallbacks*  _allocator
	)
	{
		vkDestroyImageView(_deviceHandle, _imageView, _allocator);
	}
}
