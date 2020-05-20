#pragma once


#include <vulkan/vulkan.h>


#include "VT_Enums.hpp"



namespace Vulkan
{
	// TODO: Strict definition of an application in reguards to this api.

	/*
	A handle to an object that manages the application state.

	Other Name: Application State Container

	Vulkan has no global state reference: 
	Every application must keep track of their state using an instance object.

	https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkInstance.html
	*/
	class AppInstance
	{
	public:   // Types
		using Handle = VkInstance;

		using CreateFlags = VkInstanceCreateFlags;

		/*
		A structure that specifies to the vulkan driver information about an
		application that will run an instance.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkApplicationInfo.html
		*/
		//using ApplicationInformation = VkApplicationInfo;
		struct AppInfo
		{
			      EStructureType SType        ;
			const void*          Extension    ;
			const char*          AppName      ;
			      uint32         AppVersion   ;
			const char*          EngineName   ;
			      uint32         EngineVersion;
			      EAPI_Version   API_Version  ;

			operator VkApplicationInfo() const
			{
				return *(VkApplicationInfo*)(this);
			}
		};

		struct CreateInfo
		{
			using CStr      = char*      ;
			using CStrArray = const CStr*;

			      EStructureType SType                ;
			const void*          Extension            ;
			      CreateFlags    Flags                ;
			const AppInfo*       AppInfo              ;
			      uint32         EnabledLayerCount    ;
			      CStrArray      EnabledLayerNames    ;
			      uint32         EnabledExtensionCount;
			     CStrArray       EnabledExtensionNames;

			operator VkInstanceCreateInfo() const
			{
				// The struct data layout is exactly the same, so there should be no issue doing an raw cast...
				return *(VkInstanceCreateInfo*)(this);
			}
		};

	public:

		//ApplicationInstance();
		//ApplicationInstance(CreateInfo CreationSpecToUse, AppInfo AppInfoToUse);

		// EResult Create();

		//AppInfo    appSpec     ;
		//CreateInfo creationSpec;
		//Handle     ID          ;
	};


	EResult CreateAppInstance
	(
		const AppInstance::CreateInfo& _appSpec        ,
		const AllocationCallbacks*     _customAllocator,
		      AppInstance::Handle&     _handleContainer
	)
	{
		return EResult(vkCreateInstance(&(const VkInstanceCreateInfo)(_appSpec), _customAllocator, &_handleContainer));
	}
}
