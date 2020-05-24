#pragma once


#include "VT_Platform.hpp"
#include "VT.hpp"
#include "VT_Enums.hpp"
#include "VT_Types.hpp"
#include "VT_AppInstance.hpp"




namespace Vulkan
{
	namespace Debug
	{
		constexpr 
		const char* Extension_DebugUtility = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;

		struct Label
		{
			      EStructureType SType    ;
			const void*          Extension;
			const char*          Name     ;
			      float32        Color[4] ;

			operator VkDebugUtilsLabelEXT()
			{
				return *(VkDebugUtilsLabelEXT*)(this);
			}
		};

		struct ObjectInfo
		{
			      EStructureType SType    ;
			const void*          Extension;
			      EObjectType    Type     ;
			      uInt64         Handle   ;
			const char*          Name     ;

			operator VkDebugUtilsObjectNameInfoEXT()
			{
				return *(VkDebugUtilsObjectNameInfoEXT*)(this);
			}
		};

		using MessageServerityFlags = Bitmask<EDebugUtilities_MessageSeverity, Flags>;
		using MessageTypeFlags      = Bitmask<EDebugUtilities_MessageType    , Flags>;

		class Messenger
		{
		public:
			using Handle = VkDebugUtilsMessengerEXT;

			struct CallbackData
			{
				using FlagsMask = Bitmask<EUndefined, Flags>;

				      EStructureType SType               ;
				const void*          Extension           ;
				      FlagsMask      Flags               ;
				const char*          MesssageIDName      ;
				      sint32         MessageIDNumber     ;
				const char*          Message             ;
				      uint32         QueueLabelCount     ;
				const Label*         QueueLabels         ;
				      uint32         CMDBufferLabel_Count;
				const Label*         CMDBufferLabels     ;
				      uint32         ObjectCount         ;
				const ObjectInfo*    Objects             ;

				operator VkDebugUtilsMessengerCallbackDataEXT()
				{
					return *(VkDebugUtilsMessengerCallbackDataEXT*)(this);
				}
			};

			using CallbackDelegate = VK_FPtr<Bool,
				MessageServerityFlags, MessageTypeFlags, const CallbackData, void* >;

			struct CreateInfo
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				      EStructureType        SType       ;
				const void*                 Extension   ;
				      CreateFlags           Flags       ;
				      MessageServerityFlags Serverity   ;
				      MessageTypeFlags      Type        ;
				      CallbackDelegate      UserCallback;
				      void*                 UserData    ;

				operator VkDebugUtilsMessengerCreateInfoEXT()
				{
					return *(VkDebugUtilsMessengerCreateInfoEXT*)(this);
				}
			};
		}; 


		// Functions

		EResult CreateMessenger
		(
			      AppInstance::Handle    _appInstance,
			const Messenger::CreateInfo& _createSpec ,
			const AllocationCallbacks*   _allocator  ,
			      Messenger::Handle&     _messenger
		)
		{
			FPtr_CreateMessenger delegate = GetProcedureAddress<FPtr_CreateMessenger>(_appInstance, "vkCreateDebugUtilsMessengerEXT");

			if (delegate != nullptr)
			{
				return EResult
				(
					delegate
					(
						_appInstance,
						(const VkDebugUtilsMessengerCreateInfoEXT*)(&_createSpec),
						(const VkAllocationCallbacks*             )( _allocator ),
						(      VkDebugUtilsMessengerEXT*          )(&_messenger )
					)
				);
			}
			else
			{
				return EResult::Error_ExtensionNotPresent;
			}
		}

		void DestroyMessenger
		(
			      AppInstance::Handle  _appInstance,
			      Messenger::Handle    _messenger  ,
			const AllocationCallbacks* _allocator
		)
		{
			using FPtr_DestroyMessenger = PFN_vkDestroyDebugUtilsMessengerEXT;

			FPtr_DestroyMessenger delegate = GetProcedureAddress<FPtr_DestroyMessenger>(_appInstance, "vkDestroyDebugUtilsMessengerEXT");

			if (delegate != nullptr)
			{
				delegate(_appInstance, _messenger, _allocator);
			}
		}
	}
}
