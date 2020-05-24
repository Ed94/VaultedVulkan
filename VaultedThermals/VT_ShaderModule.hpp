/*

*/



#pragma once



#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_LogicalDevice.hpp"


namespace Vulkan
{
	struct ShaderModule
	{
		using Handle = VkShaderModule;

		using CreateFlags = Bitmask<EUndefined, Flags>;

		struct CreateInfo
		{
			      EStructureType    SType    ;
			const void*             Extension;
			      CreateFlags       Flags    ;
			      DataSize          CodeSize ;
			const SPIR_V::Bytecode* Code     ;

			operator VkShaderModuleCreateInfo()
			{
				return *reinterpret_cast<VkShaderModuleCreateInfo*>(this);
			}
		};
	};


	EResult ShaderModule_Create
	(
		LogicalDevice::Handle _deviceHandle, 
		const ShaderModule::CreateInfo& _creationSpec, 
		const AllocationCallbacks* _allocator, 
		ShaderModule::Handle& _shaderModule
	)
	{
		return EResult(vkCreateShaderModule(_deviceHandle, (VkShaderModuleCreateInfo*)(&_creationSpec), _allocator, &_shaderModule));
	}

	void ShaderModule_Destory(LogicalDevice::Handle _deviceHandle, ShaderModule::Handle _moduleHandle, const AllocationCallbacks* _allocator)
	{
		return vkDestroyShaderModule(_deviceHandle, _moduleHandle, _allocator);
	}
}	
