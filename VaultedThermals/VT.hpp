/*
Vulkan Hardware Abstraction Layer

Last Modified: 5/19/2020
*/



#pragma once

// C++
#include <typeinfo>

// VT
#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"



namespace Vulkan
{
	namespace Vault_00
	{
		/*
		TODO: Document here what this is for.
		*/
		template<typename HandleType>
		struct HandledAddressed
		{
			using Handle = HandleType;

			static constexpr Handle NullHandle()
			{
				return Handle(VK_NULL_HANDLE);
			}
		};

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

	namespace Vault_01
	{
		/*
		Construct an API version number.
		*/
		inline uInt32 MakeVersion(uInt32 _major, uInt32 _minor, uInt32 _patch)
		{
			return VK_MAKE_VERSION(_major, _minor, _patch);
		}
	}
}
