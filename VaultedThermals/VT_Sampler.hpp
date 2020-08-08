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
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
        /**
         * @brief.
         */
		struct Sampler
		{
            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampler">Specification</a>  */
			using Handle = VkSampler;

            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateFlags">Specification</a>  */
            using CreateFlags = Bitmask<ESamplerCreateFlag, VkSamplerCreateFlags>;

            using EMipmapMode = ESamplerMipmapMode ; 
            using AddressMode = ESamplerAddressMode;

            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkSamplerCreateInfo, EStructureType::Sampler_CreateInfo>
			{
                      EType             SType                  ;
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

            /**
             * @brief.
             * 
             * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSampler">Specification</a> 
             * 
             * \param _device
             * \param _createInfo
             * \param _allocator
             * \param _sampler
             * \return 
             */
            static EResult Create
            (
				      LogicalDevice::Handle        _device    ,
				const CreateInfo&                  _createInfo,
				const Memory::AllocationCallbacks* _allocator ,
				      Handle&                      _sampler
            )
            {
                return EResult(vkCreateSampler(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_sampler));
            }

            /**
             * @brief.
             * 
             * @details
             * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySampler">Specification</a> 
             * 
             * \param _device
             * \param _sampler
             * \param _allocator
             */
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

    namespace V2
    {
        struct Sampler : public V1::Sampler
        {
            using Parent = V1::Sampler;

            struct CreateInfo : public Parent::CreateInfo
            {
                CreateInfo()
                {
                    SType = STypeEnum;
                    Next  = nullptr  ;
                }
            };

            /**
             * @brief.

             * \param _device
             * \param _createInfo
             * \param _allocator
             * \param _sampler
             * \return 
             */
            static EResult Create
            (
				      LogicalDevice::Handle _device    ,
				const CreateInfo&           _createInfo,
				      Handle&               _sampler
            )
            {
                return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _sampler);
            }

            using Parent::Create;

            /**
             * @brief.
             * 
             * @details
             * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySampler">Specification</a> 
             * 
             * \param _device
             * \param _sampler
             * \param _allocator
             */
            static void Destroy(LogicalDevice::Handle _device , Handle _sampler)
            {
                Parent::Destroy(_device, _sampler, Memory::DefaultAllocator);
            }

            using Parent::Destroy;
        };
    }

    namespace V4
    {
        class Sampler : public V2::Sampler
        {
        public:

            using Parent = V2::Sampler;

            EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
            {
                device    = _device;
                info      = _info                   ;
                allocator = Memory::DefaultAllocator;

                return Parent::Create(device, info, allocator, handle);
            }

            EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
            {
                device    = _device;
                info      = _info  ;
                allocator = _allocator;

                return Parent::Create(device, info, allocator, handle);
            }

            void Destroy()
            {
                Parent::Destroy(device, handle, allocator);
            }

            const Handle& GetHandle() const
            {
                return handle;
            }

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

        protected:

            Handle handle;

            CreateInfo info;

            const Memory::AllocationCallbacks* allocator;

            LogicalDevice::Handle device;
        };
    }
}
