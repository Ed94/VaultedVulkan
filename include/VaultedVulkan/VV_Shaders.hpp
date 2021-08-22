/*!
@file VV_Shaders.hpp

@brief Vaulted Vulkan: Shaders

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shaders">Specification</a> 
*/



#pragma once



// VT
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"
#include "VV_Backend.hpp"
#include "VV_Types.hpp"
#include "VV_Constants.hpp"
#include "VV_Memory_Backend.hpp"
#include "VV_PhysicalDevice.hpp"
#include "VV_Initialization.hpp"
#include "VV_LogicalDevice.hpp"
#include "VV_Memory.hpp"
#include "VV_Sampler.hpp"
#include "VV_Resource.hpp"
#include "VV_SyncAndCacheControl.hpp"


#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
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
			using CreateFlags = Bitfield<EUndefined, Flags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a> @ingroup APISpec_Shaders */
			struct CreateInfo : V0::VKStruct_Base<VkShaderModuleCreateInfo, EStructureType::ShaderModule_CreateInfo>
			{
				      EType             SType     = STypeEnum;
				const void*             Next      = nullptr  ;
				      CreateFlags       Flags    ;
				      std::size_t       CodeSize  = 0        ;
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

		/**

		@brief Shader modules contain shader code and one or more entry points. 
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

				CreateInfo(RoCStr _code, std::size_t _codeSize)
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

		/**
		@brief Shader modules contain shader code and one or more entry points. 

		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class ShaderModule : public V2::ShaderModule
		{
		public:
			
			using Parent = V2::ShaderModule;

			/**
			@brief Default constructor.
			*/
			ShaderModule() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Specifies the logical device.
			*/
			ShaderModule(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Specifies the logical device and allocator.
			*/
			ShaderModule(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			ShaderModule(ShaderModule&& _other) noexcept : 
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy the shader module if the handle is not null.
			*/
			~ShaderModule()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Create a shader module.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a shader module (logical device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a shader module (logical device and allocator specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy a shader module.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ; 
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const ShaderModule& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
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
