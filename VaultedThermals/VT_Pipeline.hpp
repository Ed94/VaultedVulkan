#pragma once



#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_ShaderModule.hpp"



namespace Vulkan
{
	struct Pipeline
	{
		struct ShaderStage
		{
			using CreateFlags = Bitmask<EPipelineShaderStageCreateFlag, Flags>;


			struct CreateInfo
			{
				      EStructureType       SType         ;
				const void*                Extenions     ;
				      CreateFlags          Flags         ;
				      EShaderStageFlag     Stage         ;
					  ShaderModule::Handle Module        ;
				      RoCStr               Name          ;
				const SpecializationInfo*  Specialization;

				operator VkShaderModuleCreateInfo()
				{
					return *reinterpret_cast<VkShaderModuleCreateInfo*>(this);
				}
			};
		};
	};
}
