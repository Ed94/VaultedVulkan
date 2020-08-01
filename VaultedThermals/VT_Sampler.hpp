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
#include "VT_Memory.hpp"
#include "VT_Initialization.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_LogicalDevice.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		

		struct Sampler
		{
			using Handle = VkSampler;

            using CreateFlags = Bitmask<ESamplerCreateFlag, VkSamplerCreateFlags>;

            using EMipmapMode = ESamplerMipmapMode;
            using AddressMode = ESamplerAddressMode;

			struct CreateInfo : Vault_00::VKStruct_Base<VkSamplerCreateInfo, EStructureType::Sampler_CreateInfo>
			{
                      EType             SType                   ;
                const void*             Next                   ;
                      CreateFlags       Flags                  ;
                      EFilter           MagnificationFilter    ;
                      EFilter           MinimumFilter          ;
                      EMipmapMode       MipmapMode             ;
                      AddressMode       AddressModeU           ;
                      AddressMode       AddressModeV           ;
                      AddressMode       AddressModeW           ;
                      float32           MipLodBias             ;
                      Bool              AnisotropyEnable       ;
                      float32           MaxAnisotropy          ;
                      Bool              CompareEnable          ;
                      ECompareOperation CompareOperation       ;
                      float32           MinimumLod             ;
                      float32           MaxLod                 ;
                      EBorderColor      BorderColor            ;
                      Bool              UnnormalizedCoordinates;
			};

            static EResult Create
            (
				      LogicalDevice::Handle        _device,
				const CreateInfo&                  _createInfo,
				const Memory::AllocationCallbacks* _allocator,
				      Handle&                      _sampler
            )
            {
                return EResult(vkCreateSampler(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_sampler));
            }

            static void Destroy
            (
                      LogicalDevice::Handle        _device   ,
                      Handle                       _sampler  ,
                const Memory::AllocationCallbacks* _allocator
            )
            {
                vkDestroySampler(_device, _sampler, _allocator->operator const VkAllocationCallbacks*());
            }
		};
	}
}
