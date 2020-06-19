#pragma once


#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Types.hpp"


namespace Vulkan
{
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
