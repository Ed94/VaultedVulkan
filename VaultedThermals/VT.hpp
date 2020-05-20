/*
Vulkan Hardware Abstraction Layer

Last Modified: 5/19/2020


*/



#pragma once


#include <typeinfo>


#include "VT_CallingConvention.hpp"
#include "VT_Constants.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_AppInstance.hpp"



namespace Vulkan
{
	uInt32 MakeVersion(uInt32 _major, uInt32 _minor, uInt32 _patch)
	{
		return VK_MAKE_VERSION(_major, _minor, _patch);
	}

	template<typename ReturnType> 
	typename std::enable_if
	<
		std::bool_constant
		< 
			std::is_pointer <                             ReturnType       >::value &&
			std::is_function<typename std::remove_pointer<ReturnType>::type>::value
		>::value,

	ReturnType>::type GetProcedureAddress(AppInstance::Handle& _appInstance, const char* _procedureName)
	{
		return ReturnType(vkGetInstanceProcAddr(_appInstance, _procedureName));
	}
}
