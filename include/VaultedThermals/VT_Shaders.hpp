/*!
@file VT_Shaders.hpp

@brief Vaulted Thermals: Shaders

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shaders">Specification</a> 
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
#include "VT_Resource.hpp"
#include "VT_SyncAndCacheControl.hpp"



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
		 * @brief 
		 * Shader modules contain shader code and one or more entry points. 
		 * 
		 * @details
		 * Shaders are selected from a shader module by specifying an entry point as part of pipeline creation. 
		 * The stages of a pipeline can use shaders that come from different modules.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shader-modules">Specification</a> 
		 * 
		 * @ingroup APISpec_Shaders
		 */
		struct ShaderModule
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModule">Specification</a> @ingroup APISpec_Shaders */
			using Handle = VkShaderModule;

			/** 
			@brief Reserved for future use.
			
			@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a> 
			@ingroup APISpec_Shaders 
			*/
			using CreateFlags = Bitmask<EUndefined, Flags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a> @ingroup APISpec_Shaders */
			struct CreateInfo : V0::VKStruct_Base<VkShaderModuleCreateInfo, EStructureType::ShaderModule_CreateInfo>
			{
				      EType             SType     = STypeEnum;
				const void*             Next      = nullptr  ;
				      CreateFlags       Flags    ;
				      WordSize          CodeSize  = 0        ;
				const SPIR_V::Bytecode* Code      = nullptr  ;
			};

			/**
			 * @brief Create a sher module.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateShaderModule">Specification</a> 
			 * 
			 * @ingroup APISpec_Shaders
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _shaderModule
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _creationSpec,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _shaderModule
			)
			{
				return EResult(vkCreateShaderModule(_deviceHandle, _creationSpec, *_allocator, &_shaderModule));
			}

			/**
			 * @brief Destroy a shader module.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyShaderModule">Specification</a> 
			 * 
			 * @ingroup APISpec_Shaders
			 * 
			 * \param _deviceHandle
			 * \param _moduleHandle
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _moduleHandle, const Memory::AllocationCallbacks* _allocator)
			{
				return vkDestroyShaderModule(_deviceHandle, _moduleHandle, *_allocator);
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

		struct ShaderModule : public V1::ShaderModule
		{
			using Parent = V1::ShaderModule;

			/**
			@brief Offers a default constructor and one code/code size parameters.
			*/
			struct CreateInfo : public Parent::CreateInfo
			{
				using Parent = Parent::CreateInfo;

				CreateInfo() : Parent::CreateInfo()
				{}

				CreateInfo(RoCStr _code, WordSize _codeSize)
				{
					using SPIR_V::Bytecode;

					SType    = STypeEnum;
					Next     = nullptr  ;
					CodeSize = _codeSize;
					Code     = reinterpret_cast<const Bytecode*>(_code);
				}
			};

			/**
			 * @brief Create a sher module.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _shaderModule
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _creationSpec,
				      Handle&               _shaderModule
			)
			{
				return Parent::Create(_deviceHandle, _creationSpec, Memory::DefaultAllocator, _shaderModule);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a shader module.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _moduleHandle
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _moduleHandle)
			{
				Parent::Destroy(_deviceHandle, _moduleHandle, Memory::DefaultAllocator);
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

		class ShaderModule : public V2::ShaderModule
		{
		public:
			
			using Parent = V2::ShaderModule;


			ShaderModule() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			ShaderModule(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			ShaderModule(const LogicalDevice& _device, const Memory::AllocationCallbacks _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			ShaderModule(ShaderModule&& _other) noexcept : 
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			~ShaderModule()
			{
				if (handle != Null<Handle>) Destroy();
			}

			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device    =  &_device               ;
				allocator = Memory::DefaultAllocator;   // #TODO: Delete this.

				return Parent::Create(*device, _info, handle);
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

			bool operator== (const ShaderModule& _other) const
			{
				return handle == _other.handle;
			}

			ShaderModule& operator= (ShaderModule&& _other) noexcept
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
