/*


*/



#pragma once


#include <vulkan/vulkan.h>



#include "VT_Constants.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_AppInstance.hpp"



namespace Vulkan
{
	struct LayerProperties
	{
		ExtensionNameStr LayerName            ;
		uint32           SpecVersion          ;
		uint32           ImplementationVersion;
		DescrptionStr    Descrption           ;

		operator VkLayerProperties() const
		{
			return *(VkLayerProperties*)(this);
		}
	};
	
	// Functions

	EResult GenerateGlobalLayerProperties(uint32* _numContainer, LayerProperties* _propertiesContainer)
	{
		return EResult(vkEnumerateInstanceLayerProperties(_numContainer, (VkLayerProperties*)(_propertiesContainer)));
	}

	uint32 GetNumOf_AvailableGlobalLayerProperties()
	{
		uint32 layerCount;

		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		return layerCount;
	}

	EResult GetAvailableGlobalLayerProperties(LayerProperties* _container)
	{
		uint32 layerCount = GetNumOf_AvailableGlobalLayerProperties();

		return EResult(vkEnumerateInstanceLayerProperties(&layerCount, (VkLayerProperties*)(_container)));
	}
}
