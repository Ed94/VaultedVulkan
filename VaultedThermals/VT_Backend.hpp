/** @file VT_Backend.hpp

@brief Vaulted Thermals: Backend

@details Contains implementation related to library backend.
*/



#pragma once



// VT
#include "VT_Platform.hpp"



namespace VaultedThermals
{
	namespace Vault_00
	{
		/** @struct VKStruct_Base

			@brief Base struct for wrapping Vulkan native C API Structs.

			@details 
		*/
		template<typename VulkanType>
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
				return reinterpret_cast<VulkanType*>(this);
			}
		};
	}
}
