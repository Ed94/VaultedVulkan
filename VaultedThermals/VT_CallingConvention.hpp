#pragma once


#include <vulkan/vulkan.h>



#include "_foreign/ConventionEnforcer.hpp"



namespace Vulkan
{
	// Calling Conventions

	// Experimental
	// Reference: https://stackoverflow.com/questions/40326733/changing-calling-convention
	MakeConventionEnforcementSet(Vulkan, VKAPI_ATTR, VKAPI_CALL);
}
