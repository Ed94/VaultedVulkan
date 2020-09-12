/*!
@file VT_Sampler.hpp

@brief Vaulted Thermals: Sampler

@details
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
		@{
		*/

        /**
         * @brief Represent the state of an image sampler which is used by the implementation to read image data and apply filtering and other transformations for the shader.
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampler">Specification</a> 
		 * @ingroup APISpec_Samplers
         */
		struct Sampler
		{
            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampler">Specification</a> @ingroup APISpec_Samplers */
			using Handle = VkSampler;

            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateFlags">Specification</a> @ingroup APISpec_Samplers */
            using CreateFlags = Bitmask<ESamplerCreateFlag, VkSamplerCreateFlags>;

            using EMipmapMode = ESamplerMipmapMode ; 
            using AddressMode = ESamplerAddressMode;

            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateInfo">Specification</a> @ingroup APISpec_Samplers */
			struct CreateInfo : V0::VKStruct_Base<VkSamplerCreateInfo, EStructureType::Sampler_CreateInfo>
			{
                      EType             SType                   = STypeEnum;
                const void*             Next                    = nullptr  ;
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
             * @brief Create a sampler object.
             * 
             * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSampler">Specification</a> 
			 * 
			 * @ingroup APISpec_Samplers
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
             * @brief Destroy a sampler.
             * 
             * @details
             * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySampler">Specification</a> 
			 * 
			 * @ingroup APISpec_Samplers
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

		/** @} */
	}

    namespace V2
    {
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief Represent the state of an image sampler which is used by the implementation to read image data and apply filtering and other transformations for the shader.
		*/
        struct Sampler : public V1::Sampler
        {
            using Parent = V1::Sampler;

            /**
             * @brief Create a sampler object (Default Allocator).

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
             * @brief Destroy a sampler (Default Allocator).
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

		/** @} */
    }

    namespace V3
    {
		/**
		@addtogroup Vault_3
		@{
		*/

        class Sampler : public V2::Sampler
        {
        public:

            using Parent = V2::Sampler;


			Sampler() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			Sampler(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			Sampler(const LogicalDevice& _device, const Memory::AllocationCallbacks _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			Sampler(Sampler&& _other) noexcept :
				handle(_other.handle), allocator(_other.allocator), device(_other.device)
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			~Sampler()
			{
				if (handle != Null<Handle>) Destroy();
			}

			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, allocator, handle);
			}

            EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
            {
                device = &_device;

				allocator = Memory::DefaultAllocator;   // #TODO: Delete this.

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

				handle = Null<Handle>;
				device = nullptr     ;
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

			bool operator== (const Sampler& _other) const
			{
				return handle == _other.handle;
			}

			Sampler& operator= (Sampler&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

        protected:

            Handle handle;

            const Memory::AllocationCallbacks* allocator;

            const LogicalDevice* device;
        };

		/** @} */
    }
}
