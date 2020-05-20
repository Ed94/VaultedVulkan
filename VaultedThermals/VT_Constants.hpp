/*

*/



#pragma once



namespace Vulkan
{
	constexpr
	const char* ValidationLayer_Khronos = "VK_LAYER_KHRONOS_validation";

	constexpr int ExtensionName_MaxSize = VK_MAX_EXTENSION_NAME_SIZE;
	constexpr int Description_MaxSize   = VK_MAX_DESCRIPTION_SIZE   ;

	constexpr int PhysicalDevice_MaxNameSize = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;

	constexpr int UUID_Size = VK_UUID_SIZE;

	using UUID = uInt8[UUID_Size];
}
