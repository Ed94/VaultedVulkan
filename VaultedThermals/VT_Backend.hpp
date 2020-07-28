/** @file VT_Backend.hpp

@brief Vaulted Thermals: Backend

@details Contains implementation related to library backend.
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"



namespace VaultedThermals
{
	namespace Vault_00
	{
		/** @struct VKStruct_Base

			@brief Base struct for wrapping Vulkan native C API Structs.

			@details 
		*/
		template<typename VulkanType, EStructureType TemplateSpecifiedStype = EStructureType::Max_Enum>
		struct VKStruct_Base
		{
			/**
			 * @typedef EType
			 * 
			 * @brief Defines the EType enum to the default vkStructureType enum for now.
			 * 
			 * @todo Finish the proper enum...
			 */
			using EType= EStructureType;

			//constexpr EType STypeSpecifier() { return TemplateSpecifiedStype; }

			static constexpr EType STypeEnum = TemplateSpecifiedStype;
			
			/** 
			@typdef VkType 
			
			@brief Keeps record of the struct's inherent vulkan equivalent.
			*/
			using VkType = VulkanType;   

			operator VulkanType*()
			{
				return reinterpret_cast<VulkanType*>(this);
			}

			operator const VulkanType*() const
			{
				return reinterpret_cast<const VulkanType*>(this);
			}
		};
	}
}
