/*
@file VT_Samples.hpp
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
#include "VT_Initialization.hpp"



namespace VaultedThermals
{
	namespace Vault_01
	{
		using SampleCountFlags = Bitmask<ESampleCount, Flags>;

		struct Sampler
		{
			using Handle = VkSampler;
		};
	}
}
