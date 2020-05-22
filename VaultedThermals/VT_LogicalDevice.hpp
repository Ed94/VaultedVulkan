/*

*/


#pragma once



#include "_foreign/Bitmask.hpp"

#include "VT_Platform.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_PhysicalDevice.hpp"


#include <typeinfo>



namespace Vulkan
{
	struct LogicalDevice
	{
		using Handle = VkDevice;

		using CreateFlags = bitmask<EUndefined, Flags>;

		struct Queue
		{
			using Handle = VkQueue;

			struct CreateInfo
			{
				using CreateFlags = bitmask<ELogicalDeviceQueueCreateFlag, Flags>;

				EStructureType              SType;
				const void*                 Extension;
				CreateFlags                 Flags;
				uint32                      QueueFamilyIndex;
				uint32                      QueueCount;
				const float*                QueuePriorities;

				operator VkDeviceQueueCreateInfo()
				{
					return *(VkDeviceQueueCreateInfo*)(this);
				}
			};
		};

		struct CreateInfo
		{
				  EStructureType            SType                ;
			const void*                     Extension            ;
			      CreateFlags               Flags                ;
				  uint32                    QueueCreateInfoCount ;
			const Queue::CreateInfo*        QueueCreateInfos     ;
				  uint32                    EnabledLayerCount    ;
			RoSCtr_roArray_Array            EnabledLayerNames    ;
				  uint32                    EnabledExtensionCount;
			RoSCtr_roArray_Array            EnabledExtensionNames;
			const PhysicalDevice::Features* EnabledFeatures      ;

			operator VkDeviceCreateInfo() const
			{
				return *(VkDeviceCreateInfo*)(this);
			}
		};
	};
		

	EResult LogicalDevice_CreateDevice
	(
		      PhysicalDevice::Handle     _physicalDevice,
		const LogicalDevice::CreateInfo& _createSpec    ,
		const AllocationCallbacks*       _allocator     ,
		      LogicalDevice::Handle&     _device
	)
	{
		return EResult(vkCreateDevice(_physicalDevice, (VkDeviceCreateInfo*)(&_createSpec), _allocator, &_device));
	}

	void LogicalDevice_Destory(LogicalDevice::Handle _handle, const AllocationCallbacks* _allocator)
	{
		vkDestroyDevice(_handle, _allocator);
	}

	void LogicalDevice_GetQueue(LogicalDevice::Handle _handle, uint32 _queueFamilyIndex, uint32 _queueIndex, LogicalDevice::Queue::Handle& _queueReturn)
	{
		vkGetDeviceQueue(_handle, _queueFamilyIndex, _queueIndex, &_queueReturn);
	}
}
