/**
@file VT_Shaders.hpp

@brief 

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shaders">Specification</a> 
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
#include "VT_Memory_Corridors.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_SyncAndCacheControl.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		/**
		 * @brief 
		 * Shader modules contain shader code and one or more entry points. 
		 * 
		 * @details
		 * Shaders are selected from a shader module by specifying an entry point as part of pipeline creation. 
		 * The stages of a pipeline can use shaders that come from different modules.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shader-modules">Specification</a> 
		 */
		struct ShaderModule
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModule">Specification</a>  */
			using Handle = VkShaderModule;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a>  */
			using CreateFlags = Bitmask<EUndefined, Flags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkShaderModuleCreateInfo, EStructureType::ShaderModule_CreateInfo>
			{
				      EType             SType    ;
				const void*             Extension;
				      CreateFlags       Flags    ;
				      DataSize          CodeSize ;
				const SPIR_V::Bytecode* Code     ;
			};

			/**
			 * @brief Create a sher module.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateShaderModule">Specification</a> 
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
				      ShaderModule::Handle&        _shaderModule
			)
			{
				return EResult(vkCreateShaderModule(_deviceHandle, _creationSpec.operator const VkShaderModuleCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_shaderModule));
			}

			/**
			 * @brief Destroy a shader module.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyShaderModule">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _moduleHandle
			 * \param _allocator
			 */
			static void Destory(LogicalDevice::Handle _deviceHandle, ShaderModule::Handle _moduleHandle, const Memory::AllocationCallbacks* _allocator)
			{
				return vkDestroyShaderModule(_deviceHandle, _moduleHandle, _allocator->operator const VkAllocationCallbacks*());
			}
		};
	}
}
