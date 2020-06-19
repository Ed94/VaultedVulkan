/*
Vaulted Thermals: Backend

Contains implementation related to library backend.
*/



#pragma once



// VT
#include "VT_Platform.hpp"



namespace Vulkan
{
	namespace Vault_00
	{
		/*
		Base struct for wrapping Vulkan native C API Structs.
		*/
		template<typename VulkanType>
		struct VKStruct_Base
		{
			using VkType = VulkanType;

			operator VulkanType*()
			{
				return reinterpret_cast<VulkanType*>(this);
			}

			operator const VulkanType*() const
			{
				return reinterpret_cast<VulkanType*>(this);
			}
		};
	}
}
