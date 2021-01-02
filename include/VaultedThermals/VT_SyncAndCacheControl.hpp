/*!
@file VT_SyncAndCacheControl.hpp

@brief Vaulted Thermals: Synchronization and Cache Control

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization">Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Backend.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
#endif
{
	namespace V0
	{
		struct Fence_PlatformAgnostic
		{
			using EExternalHandleTypeFlag = EExternalFenceHandleTypeFlag;

			/** 
			@ingroup APISpec_Synchronization_and_Cache_Control 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFence">Specification</a> 
			*/
			using Handle = VkFence;
		};

		struct Semaphore_PlatformAgnostic
		{
			/**
			@ingroup APISpec_Synchronization_and_Cache_Control
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphore">Specification</a> 
			*/
			using Handle = VkSemaphore;	

			using EExternalHandleType = EExternalSemaphoreHandleTypeFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalSemaphoreHandleTypeFlags">Specification</a> @ingroup APISpec_Additional_Capabilities */
			using ExternalHandleTypeFlags = Bitmask<EExternalHandleType, VkExternalSemaphoreHandleTypeFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreImportFlags">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			using ImportFlags = Bitmask<ESemaphoreImportFlag, VkSemaphoreImportFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitFlags">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			using WaitFlags = Bitmask<ESemaphoreWaitFlag, VkSemaphoreWaitFlags>;
		};

		template<EOS> struct Fence_Maker    ;
		template<EOS> struct Semaphore_Maker;

		template<> struct Fence_Maker<EOS::Linux> : Fence_PlatformAgnostic
		{
			using OS_Handle = PlatformTypes_Maker<EOS::Linux>::OS_Handle;

			/** 
			@brief Do not use, dummy structure.
			*/
			struct ExportableHandleInfo : V0::VKStruct_Base<DummyBase, EStructureType::Max_Enum>
			{
				      EType SType;
				const void* Next ;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceGetFdInfoKHR">Specification</a> 
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct GetOS_HandleInfo : V0::VKStruct_Base<VkFenceGetFdInfoKHR, EStructureType::Fence_Get_FD_Info_KHR>
			{
				      EType                   SType      = STypeEnum;
				const void*                   Next       = nullptr  ;
				      Handle                  Fence     ;
				      EExternalHandleTypeFlag HandleType;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportFenceFdInfoKHR">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			struct ImportOS_HandleInfo : V0::VKStruct_Base<VkImportFenceFdInfoKHR, EStructureType::ImportFence_FD_Info_KHR>
			{
				      EType                   SType          = STypeEnum;
				const void*                   Next           = nullptr  ;
				      Handle                  Fence         ;
				      FenceImportFlags        Flags         ;
				      EExternalHandleTypeFlag HandleType    ;
				      OS_Handle               FileDescriptor;
			};

			/**
			* @brief 
			* 
			* @details<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceFdKHR">Specification</a>  
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			* 
			* \param device
			* \param pGetFdInfo
			* \param pFd
			* \return 
			*/
			static EResult GetOS_Handle
			(
				      V1::LogicalDevice::Handle _device        ,
				const GetOS_HandleInfo&         _fdInfo        ,
				      OS_Handle*                _fileDescriptor
			)
			{
				return EResult(vkGetFenceFdKHR(_device, _fdInfo, _fileDescriptor));
			}

			/**
			 * @brief  
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportFenceFdKHR">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _importInfo
			 * \return 
			 */
			static EResult ImportOS_Handle
			(
				      V1::LogicalDevice::Handle _device    ,
				const ImportOS_HandleInfo&      _importInfo
			)
			{
				return EResult(vkImportFenceFdKHR(_device, _importInfo));
			}
		};

		template<> struct Fence_Maker<EOS::Windows> : Fence_PlatformAgnostic
		{
			using OS_Handle = PlatformTypes_Maker<EOS::Windows>::OS_Handle;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportFenceWin32HandleInfoKHR">Specification</a> 
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct ExportableOS_HandleInfo : V0::VKStruct_Base<VkExportFenceWin32HandleInfoKHR, EStructureType::ExportFence_Win32Handle_Info_KHR>
			{
				      EType                SType        = STypeEnum;
				const void*                Next         = nullptr  ;
				const SECURITY_ATTRIBUTES* Attributes  ;
				      DWORD                AccessRights;
				      LPCWSTR              Name        ;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceGetWin32HandleInfoKHR">Specification</a> 
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct GetOS_HandleInfo : V0::VKStruct_Base<VkFenceGetWin32HandleInfoKHR, EStructureType::Fence_GetWin32Handle_Info_KHR>
			{
				      EType                   SType      = STypeEnum;
				const void*                   Next       = nullptr  ;
				      Handle                  Fence     ;
				      EExternalHandleTypeFlag HandleType;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportFenceWin32HandleInfoKHR">Specification</a> 
			 * 
			 * @details
			 * Note: Windows provides an extra member for the handle name.
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			struct ImportOS_HandleInfo : V0::VKStruct_Base<VkImportFenceWin32HandleInfoKHR, EStructureType::ImportFence_Win32Handle_Info_KHR>
			{
				      EType                   SType      = STypeEnum;
				const void*                   Next       = nullptr  ;
				      Handle                  Fence     ;
				      FenceImportFlags        Flags     ;
				      EExternalHandleTypeFlag HandleType;
				      OS_Handle               Handle    ;
				      LPCWSTR                 Name      ;
			};

			/**
			* @brief Export a Windows handle representing the state of a fence.
			
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceWin32HandleKHR">Specification</a>  
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			* 
			* \return 
			*/
			static EResult GetOS_Handle
			(
				      V1::LogicalDevice::Handle _device            ,
				const GetOS_HandleInfo&         _getWin32HandleInfo,
				      OS_Handle&                _winHandle
			)
			{
				return EResult(vkGetFenceWin32HandleKHR(_device, _getWin32HandleInfo, &_winHandle));
			}

			/**
			 * @brief Import a fence payload from a Windows handle.
			 *
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportFenceWin32HandleKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pImportFenceWin32HandleInfo
			 * \return 
			 */
			static EResult ImportOS_Handle
			(
				      V1::LogicalDevice::Handle _device    ,
				const ImportOS_HandleInfo&      _importInfo
			)
			{
				return EResult(vkImportFenceWin32HandleKHR(_device, _importInfo));
			}
		};

		template<> struct Semaphore_Maker<EOS::Linux> : Semaphore_PlatformAgnostic
		{
			using OS_Handle = PlatformTypes_Maker<EOS::Linux>::OS_Handle;

			/** 
			@brief Do not use, dummy structure. 
			*/
			struct ExportableOS_HandleInfo : V0::VKStruct_Base<DummyBase, EStructureType::Max_Enum>
			{
				      EType SType = STypeEnum;
				const void* Next  = nullptr  ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreGetFdInfoKHR">Specification</a>  

			@ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct GetOS_HandleInfo : V0::VKStruct_Base<VkSemaphoreGetFdInfoKHR, EStructureType::Semaphore_Get_FD_Info_KHR>
			{
				      EType               SType      = STypeEnum;
				const void*               Next       = nullptr  ;
				      Handle              Semaphore ;
				      EExternalHandleType HandleType;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportSemaphoreFdInfoKHR">Specification</a>  

			@ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct ImportOS_HandleInfo : V0::VKStruct_Base<VkImportSemaphoreFdInfoKHR, EStructureType::ImportSemaphore_FD_Info_KHR>
			{
				      EType               SType      = STypeEnum;
				const void*               Next       = nullptr  ;
				      Handle              Semaphore ;
				      ImportFlags         Flags     ;
				      EExternalHandleType HandleType;
				      OS_Handle           OSHandle  ;
			};


			/**
			 * @brief Export a POSIX file descriptor representing the payload of a semaphore.
			 *  
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreFdKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pGetFdInfo
			 * \param pFd
			 * \return 
			 */
			static EResult GetOS_Handle
			(
				      V1::LogicalDevice::Handle _device        ,
				const GetOS_HandleInfo&         _getInfo       ,
				      OS_Handle*                _fileDescriptor
			)
			{
				return EResult(vkGetSemaphoreFdKHR(_device, _getInfo, _fileDescriptor));
			}

			/**
			 * @brief Import a semaphore payload from a POSIX file descriptor.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportSemaphoreFdKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pImportSemaphoreFdInfo
			 * \return 
			 */
			static EResult ImportOS_Handle(V1::LogicalDevice::Handle _device, const ImportOS_HandleInfo& _importPOSIX_Info)
			{
				return EResult(vkImportSemaphoreFdKHR(_device, _importPOSIX_Info));
			}
		};

		template<> struct Semaphore_Maker<EOS::Windows> : Semaphore_PlatformAgnostic
		{
			using OS_Handle = PlatformTypes_Maker<EOS::Windows>::OS_Handle;

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportSemaphoreWin32HandleInfoKHR">Specification</a>  

			@ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct ExportableOS_HandleInfo : V0::VKStruct_Base<VkExportSemaphoreWin32HandleInfoKHR, EStructureType::ExportSemaphore_Win32Handle_Info_KHR>
			{
				      EType                SType        = STypeEnum;
				const void*                Next         = nullptr  ;
				const SECURITY_ATTRIBUTES* Attributes   = nullptr  ;
				      DWORD                AccessRights;
				      LPCWSTR              Name        ;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreGetWin32HandleInfoKHR">Specification</a>  

			@ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct GetOS_HandleInfo : V0::VKStruct_Base<VkSemaphoreGetWin32HandleInfoKHR, EStructureType::Semaphore_GetWin32Handle_Info_KHR>
			{
				      EType               SType      = STypeEnum;
				const void*               Next       = nullptr  ;
				      Handle              Semaphore ;
				      EExternalHandleType HandleType;
			};

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportSemaphoreWin32HandleInfoKHR">Specification</a>  

			@ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct ImportOS_HandleInfo : V0::VKStruct_Base<VkImportSemaphoreWin32HandleInfoKHR, EStructureType::ImportSemaphore_Win32Handle_Info_KHR>
			{
				      EType               SType      = STypeEnum;
				const void*               Next       = nullptr  ;
				      Handle              Semaphore ;
				      ImportFlags         Flags     ;
				      EExternalHandleType HandleType;
				      OS_Handle           OSHandle  ;
				      LPCWSTR             Name      ;
			};


			/**
			 * @brief Export a Windows handle representing the payload of a semaphore.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreWin32HandleKHR">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pGetWin32HandleInfo
			 * \param pHandle
			 * \return 
			 */
			static EResult GetOS_Handle
			(
				      V1::LogicalDevice::Handle _device ,
				const GetOS_HandleInfo&         _getInfo,
				      OS_Handle&                _handle
			)
			{
				return EResult(vkGetSemaphoreWin32HandleKHR(_device, _getInfo, &_handle));
			}

			/**
			* @brief Import a semaphore payload from a Windows handle.
			* 
			* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportSemaphoreWin32HandleKHR">Specification</a> 
			* 
			* @ingroup APISpec_Synchronization_and_Cache_Control
			* 
			* \param device
			* \param pImportSemaphoreWin32HandleInfo
			* \return 
			*/
			static EResult ImportOS_Handle(V1::LogicalDevice::Handle _device, const ImportOS_HandleInfo& _importHandleInfo)
			{
				return EResult(vkImportSemaphoreWin32HandleKHR(_device, _importHandleInfo));
			}
		};
	}

	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		 * @brief 
		 * Events are a synchronization primitive that can be used to insert a fine-grained dependency between commands submitted to the same queue, 
		 * or between the host and a queue. Events must not be used to insert a dependency between commands submitted to different queues. 
		 * Events have two states - signaled and unsignaled. 
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-events">Specification</a> 
		 * 
		 * @ingroup APISpec_Synchronization_and_Cache_Control
		 */
		struct Event
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkEvent">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			using Handle = VkEvent;

			using CreateFlags = Bitmask<EUndefined, VkEventCreateFlags>;   ///< @brief Reserved for future use.

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkEventCreateInfo">Specification</a> @ingroup  APISpec_Synchronization_and_Cache_Control */
			struct CreateInfo : V0::VKStruct_Base<VkEventCreateInfo, EStructureType::Event_CreateInfo>
			{
				      EType       SType = STypeEnum;
				const void*       Next  = nullptr  ;
				      CreateFlags Flags;
			};

			/**
			 * @brief Create an Event.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateEvent">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _event
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _device    ,
				const Event::CreateInfo&           _createInfo,
				const Memory::AllocationCallbacks* _allocator ,
				      Handle&                      _event
			)
			{
				return EResult(vkCreateEvent(_device, _createInfo, *_allocator, &_event));
			}

			/**
			 * @brief Destroy an event.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyEvent">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _event
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _device   ,
				      Handle                       _event    ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyEvent(_device, _event, *_allocator);
			}

			/**
			 * @brief Query the state of an event from the host.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetEventStatus">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param event
			 * \return 
			 */
			static EResult GetStatus(LogicalDevice::Handle _device, Handle _event)
			{
				return EResult(vkGetEventStatus(_device, _event));
			}

			/**
			 * @brief Set the state of an event to unsignaled from the host.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetEvent">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _event
			 * \return 
			 */
			static EResult Reset(LogicalDevice::Handle _device, Handle _event)
			{
				return EResult(vkResetEvent(_device, _event));
			}

			/**
			 * @brief 
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkSetEvent">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _event
			 * \return 
			 */
			static EResult Set(LogicalDevice::Handle _device, Handle _event)
			{
				return EResult(vkSetEvent(_device, _event));
			}
		};

		/**
		@brief Fences are a synchronization primitive that can be used to insert a dependency from a queue to the host. Fences have two states - signaled and unsignaled.

		@details
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-fences">Specification</a> 

		@ingroup APISpec_Synchronization_and_Cache_Control
		*/
		struct Fence : V0::Fence_Maker<V0::OS_Platform>
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateFlags">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			using CreateFlags = Bitmask<EFenceCreateFlag, VkFenceCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalFenceHandleTypeFlags">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			using ExternalHandleFlags = Bitmask<EExternalFenceHandleTypeFlag, VkExternalFenceHandleTypeFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateInfo">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			struct CreateInfo : V0::VKStruct_Base<VkFenceCreateInfo, EStructureType::Fence_CreateInfo>
			{
				      EType       SType = STypeEnum;
				const void*       Next  = nullptr  ;
				      CreateFlags Flags;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceEventInfoEXT">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct DeviceEventInfo : V0::VKStruct_Base<VkDeviceEventInfoEXT, EStructureType::Device_EventInfo_EXT>
			{
				      EType            SType       = STypeEnum;
				const void*            Next        = nullptr  ;
				      EDeviceEventType DeviceEvent;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDisplayEventInfoEXT">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control
			*/
			struct DisplayEventInfo : V0::VKStruct_Base<VkDisplayEventInfoEXT, EStructureType::Display_EventInfo_EXT>
			{
				      EType             SType        = STypeEnum;
				const void*             Next         = nullptr  ;
				      EDisplayEventType DisplayEvent;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportFenceCreateInfo">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control
			 */
			struct ExportCreateInfo : V0::VKStruct_Base<VkExportFenceCreateInfo, EStructureType::ExportFence_CreateInfo>
			{
				      EType               SType       = STypeEnum;
				const void*               Next        = nullptr  ;
				      ExternalHandleFlags HandleTypes;
			};

			/**
			 * @brief Create a fence.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateFence">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _logicalDevice
			 * \param _createInfo
			 * \param _allocator
			 * \param _fence
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _logicalDevice,
				const CreateInfo&                  _createInfo   ,
				const Memory::AllocationCallbacks* _allocator    ,
				      Handle&                      _fence
			)
			{
				return EResult(vkCreateFence(_logicalDevice, _createInfo, *_allocator, &_fence));
			}

			/**
			 * @brief Destroy a fence.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyFence">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _logicalDevice,
				      Handle                       _fence        ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyFence(_logicalDevice, _fence, *_allocator);
			}

			/**
			 * @brief Export a Windows handle representing the state of a fence.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceStatus">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \return 
			 */
			static EResult GetStatus(LogicalDevice::Handle _logicalDevice, Handle _fence)
			{
				return EResult(vkGetFenceStatus(_logicalDevice, _fence));
			}			

			/**
			 * @brief Create a fence that will be signaled when an event occurs on a device.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkRegisterDeviceEventEXT">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pDeviceEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			static EResult RegisterDeviceEvent
			(
				      LogicalDevice::Handle        _device         ,
				const DeviceEventInfo&             _deviceEventInfo,
				const Memory::AllocationCallbacks* _allocator      ,
				      Handle&                      _fence
			)
			{
				return EResult(vkRegisterDeviceEventEXT(_device, _deviceEventInfo, *_allocator, &_fence));
			}

			/**
			 * @brief Create a fence that will be signaled when an event occurs on a Display object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkRegisterDisplayEventEXT">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param display
			 * \param pDisplayEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			static EResult RegisterDisplayEvent
			(
				      LogicalDevice::Handle        _device          ,
				      Display::Handle              _display         ,
				const DisplayEventInfo&            _displayEventInfo,
				const Memory::AllocationCallbacks* _allocator       ,
				      Handle&                      _fence
			)
			{
				return EResult(vkRegisterDisplayEventEXT(_device, _display, _displayEventInfo, *_allocator, &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetFences">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _logicalDevice
			 * \param _fences
			 * \param _fenceCount
			 * \return 
			 */
			static EResult Reset(LogicalDevice::Handle _logicalDevice, Handle* _fences, ui32 _fenceCount)
			{
				return EResult(vkResetFences(_logicalDevice, _fenceCount, _fences));
			}

			/**
			 * 
			 * @brief Wait for one or more fences to enter the signaled state on the host.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkWaitForFences">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param fenceCount
			 * \param pFences
			 * \param waitAll
			 * \param timeout
			 * \return 
			 */
			static EResult WaitForFences
			(
				      LogicalDevice::Handle _device    ,
				      ui32                  _fenceCount,
				const Handle*               _fences    ,
				      Bool                  _waitAll   ,
				      uI64                  _timeout
			)
			{
				return EResult(vkWaitForFences(_device, _fenceCount, _fences, _waitAll, _timeout));
			}
		};

		/**
		@brief Semaphores are a synchronization primitive that can be used to insert a dependency between queue operations or between a queue operation and the host. 
		Binary semaphores have two states - signaled and unsignaled.
		
		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-semaphores">Specification</a> 

		@ingroup APISpec_Synchronization_and_Cache_Controls
		*/
		struct Semaphore : V0::Semaphore_Maker<V0::OS_Platform>
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreCreateInfo">Specification</a> APISpec_Synchronization_and_Cache_Control
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Controls
			 */
			struct CreateInfo : V0::VKStruct_Base<VkSemaphoreCreateInfo, EStructureType::Semaphore_CreateInfo>
			{
				using CreateFlags = Bitmask<EUndefined, VkSemaphoreCreateFlags>;

				      EType       SType = STypeEnum;
				const void*       Next  = nullptr  ;
				      CreateFlags Flags;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportSemaphoreCreateInfo">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Controls
			 */
			struct ExportCreateInfo : V0::VKStruct_Base<VkExportSemaphoreCreateInfo, EStructureType::Export_Semaphore_CreateInfo_KHR>
			{
				      EType                   SType       = STypeEnum;
				const void*                   Next        = nullptr  ;
				      ExternalHandleTypeFlags HandleTypes;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreSignalInfo">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			struct SignalInfo : V0::VKStruct_Base<VkSemaphoreSignalInfo, EStructureType::Semaphore_SignalInfo>
			{
				      EType  SType     = STypeEnum;
				const void*  Next      = nullptr  ;
				      Handle Semaphore;
				      uI64   Value    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreTypeCreateInfo">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			struct TypeSpecifiedCreateInfo : V0::VKStruct_Base<VkSemaphoreTypeCreateInfo, EStructureType::SemaphoreType_CreateInfo>
			{
				      EType  SType         = STypeEnum;
				const void*  Next          = nullptr  ;
				      Handle SemaphoreType;
				      uI64   InitialValue ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitInfo">Specification</a> @ingroup APISpec_Synchronization_and_Cache_Control */
			struct WaitInfo : V0::VKStruct_Base<VkSemaphoreWaitInfo, EStructureType::Semaphore_WaitInfo>
			{
				      EType     SType          = STypeEnum;
				const void*     Next           = nullptr  ;
				      WaitFlags Flags         ;
				      ui32      SemaphoreCount;
				const Handle*   Semaphores     = nullptr  ;
				const uI64*     Values         = nullptr  ;
			};

			/**
			 * @brief Create a semaphore.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSemaphore">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pCreateInfo
			 * \param pAllocator
			 * \param pSemaphore
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _device    ,
				const CreateInfo&                  _createInfo,
				const Memory::AllocationCallbacks* _allocator ,
				      Handle&                      _semaphore
			)
			{
				return EResult(vkCreateSemaphore(_device, _createInfo, *_allocator, &_semaphore));
			}

			/**
			 * @brief Destroy a semaphore.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySemaphore">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _semaphore
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _device   ,
				      Handle                       _semaphore,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroySemaphore(_device, _semaphore, *_allocator);
			}

			/**
			 * @brief Query the current counter value of a semaphore created with a SemaphoreType of Timeline from the host.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreCounterValue">Specification</a> 
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param semaphore
			 * \param pValue
			 * \return 
			 */
			static EResult GetCounterValue
			(
				LogicalDevice::Handle _device   ,
				Handle                _semaphore,
				uI64&                 _value
			)
			{
				return EResult(vkGetSemaphoreCounterValue(_device, _semaphore, &_value));
			}

			/**
			 * @brief Signal a semaphore created with a SemaphoreType of Timeline with a particular counter value, on the host.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkSignalSemaphore">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param device
			 * \param pSignalInfo
			 * \return 
			 */
			static EResult Signal(LogicalDevice::Handle _device, const SignalInfo& _signalInfo)
			{
				return EResult(vkSignalSemaphore(_device, _signalInfo));
			}

			/**
			 * @brief Wait for a set of semaphores created with a VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE to reach particular counter values on the host.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkWaitSemaphores">Specification</a>
			 * 
			 * @ingroup APISpec_Synchronization_and_Cache_Control
			 * 
			 * \param _device
			 * \param _waitInfo
			 * \param timeout
			 * \return 
			 */
			static EResult WaitFor
			(
				      LogicalDevice::Handle _device  ,
				const WaitInfo&             _waitInfo,
				      uI64                  _timeout
			)
			{
				return EResult(vkWaitSemaphores(_device, _waitInfo, _timeout));
			}
		};

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief
		Events are a synchronization primitive that can be used to insert a fine-grained dependency between commands submitted to the same queue,
		or between the host and a queue. Events must not be used to insert a dependency between commands submitted to different queues.
		Events have two states - signaled and unsignaled.
		*/
		struct Event : public V1::Event
		{
			using Parent = V1::Event;

			/**
			 * @brief Create an event (Default Allocator).
			 * 
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _event
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _device    ,
				const Event::CreateInfo&    _createInfo,
				      Handle&               _event
			)
			{
				return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _event);
			}

			using Parent::Create;

			/**
			 * @brief Destroy an event (Default Allocator).

			 * \param _device
			 * \param _event
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _event)
			{
				Parent::Destroy(_device, _event, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		/**
		@brief Fences are a synchronization primitive that can be used to insert a dependency from a queue to the host. Fences have two states - signaled and unsignaled.
		*/
		struct Fence : public V1::Fence
		{
			using Parent = V1::Fence;
			
			/**
			 * @brief Create a fence (Default Allocator).
			 * 
			 * \param _logicalDevice
			 * \param _createInfo
			 * \param _allocator
			 * \param _fence
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _logicalDevice,
				const CreateInfo&                  _createInfo   ,
				      Handle&                      _fence
			)
			{
				return Parent::Create(_logicalDevice, _createInfo, Memory::DefaultAllocator, _fence);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a fence (Default Allocator).
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _logicalDevice, Handle _fence)
			{
				Parent::Destroy(_logicalDevice, _fence, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			* 
			* @brief
			* 
			* @details
			 * 
			 * \param device
			 * \param pDeviceEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			static EResult RegisterDeviceEvent
			(
				      LogicalDevice::Handle        _device         ,
				const DeviceEventInfo&             _deviceEventInfo,
				      Handle&                      _fence
			)
			{
				return Parent::RegisterDeviceEvent(_device, _deviceEventInfo, Memory::DefaultAllocator, _fence);
			}

			using Parent::RegisterDeviceEvent;

			/**
			* @brief 
			* 
			* @details
			* 
			 * \param device
			 * \param display
			 * \param pDisplayEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			static EResult RegisterDisplayEvent
			(
				      LogicalDevice::Handle        _device          ,
				      Display::Handle              _display         ,
				const DisplayEventInfo&            _displayEventInfo,
				      Handle&                      _fence
			)
			{
				return Parent::RegisterDisplayEvent(_device, _display, _displayEventInfo, Memory::DefaultAllocator, _fence);
			}

			using Parent::RegisterDisplayEvent;
		};

		/**
		@brief Semaphores are a synchronization primitive that can be used to insert a dependency between queue operations or between a queue operation and the host.
		Binary semaphores have two states - signaled and unsignaled.
		*/
		struct Semaphore : public V1::Semaphore
		{
			using Parent = V1::Semaphore;

			/**
			@brief Create a semaphore (Default Allocator).
			*/
			static EResult Create
			(
				      LogicalDevice::Handle _device    ,
				const CreateInfo&           _createInfo,
				      Handle&               _semaphore
			)
			{
				return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _semaphore);
			}

			using Parent::Create;

			/**
			@brief Destroy a semaphore (Default Allocator).
			*/
			static void Destroy
			(
				LogicalDevice::Handle _device   ,
				Handle                _semaphore
			)
			{
				Parent::Destroy(_device, _semaphore, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@brief
		Events are a synchronization primitive that can be used to insert a fine-grained dependency between commands submitted to the same queue,
		or between the host and a queue. Events must not be used to insert a dependency between commands submitted to different queues.
		Events have two states - signaled and unsignaled.
		 
		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class Event : public V2::Event
		{
		public:
			using Parent = V2::Event;

			/**
			@brief Default constructor.
			*/
			Event() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Logical device specified.
			*/
			Event(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Logical device and allocator specified.
			*/
			Event(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			Event(Event&& _other) noexcept : 
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy the event if the handle is not null.
			*/
			~Event()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Create an event.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create an event (logical device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create an event (logical device and allocator specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy an event.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Query the state of an event from the host.
			*/
			EResult GetStatus()
			{
				return Parent::GetStatus(*device, handle);
			}

			/**
			@brief Set the state of an event to unsignaled from the host.
			*/
			EResult Reset()
			{
				return Parent::Reset(*device, handle);
			}

			/**
			@brief Set the state of an event to signaled from the host.
			*/
			EResult Set()
			{
				return Parent::Set(*device, handle);
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const Event& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			Event& operator= (Event&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/**
		@brief Fences are a synchronization primitive that can be used to insert a dependency from a queue to the host. Fences have two states - signaled and unsignaled.
		
		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class Fence : public V2::Fence
		{
		public:
			using Parent = V2::Fence;

			/**
			@brief Default constructor.
			*/
			Fence() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Logical device specified.
			*/
			Fence(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Logical device and allocator specified.
			*/
			Fence(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			Fence(Fence&& _other) noexcept :
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy a fence if handle is not null.
			*/
			~Fence()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Create a fence.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a fence (logical device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a fence (logical device and allocator specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy a fence.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Provides the logical device handle.
			*/
			LogicalDevice::Handle GetDeviceHandle() const
			{
				return *device;
			}

			/**
			@brief Query the status of a fence from the host
			*/
			EResult GetStatus()
			{
				return Parent::GetStatus(*device, handle);
			}

			/**
			@brief Platform agnostic way to export the os handle of the fence.
			*/
			EResult GetOS_Handle(const GetOS_HandleInfo& _win32Info, OS_Handle & _winHandle)
			{
				return Parent::GetOS_Handle(*device, _win32Info, _winHandle);
			}

			/**
			@brief Import a fence payload from a os handle.
			*/
			EResult ImportOS_Handle(const ImportOS_HandleInfo& _importInfo)
			{
				return Parent::ImportOS_Handle(*device, _importInfo);
			}

			/**
			@brief Create a fence that will be signaled when an event occurs on a device.
			*/
			EResult RegisterDeviceEvent(const DeviceEventInfo _eventInfo)
			{
				return Parent::RegisterDeviceEvent(*device, _eventInfo, allocator, handle);
			}

			/**
			@brief Create a fence that will be signaled when an event occurs on a Display object.
			*/
			EResult RegisterDisplayEvent(Display::Handle _display, const DisplayEventInfo& _eventInfo)
			{
				return Parent::RegisterDisplayEvent(*device, _display, _eventInfo, allocator, handle);
			}

			/**
			@brief Set the state of fences to unsignaled from the host.
			*/
			EResult Reset()
			{
				return Parent::Reset(*device, &handle, 1);
			}

			/**
			@brief Reset the fences in the provided container.
			*/
			static EResult Reset(DynamicArray<Fence> _fences)
			{
				auto device = _fences[0].GetDeviceHandle();

				DynamicArray<Fence::Handle> handles;

				for (auto& fence : _fences) handles.push_back(fence);

				return Parent::Reset(device, handles.data(), static_cast<ui32>(_fences.size()));
			}

			/**
			@brief Wait for the fence to enter the signaled state on the host.
			*/
			EResult WaitFor(uI64 _timeout)
			{
				return Parent::WaitForFences(*device, 1, &handle, false, _timeout);
			}

			/**
			@brief Wait for one or more fences to enter the signaled state on the host.
			*/
			static EResult WaitForFence(DynamicArray<Fence> _fences, bool _waitForAll, uI64 _timeout)
			{
				auto device = _fences[0].GetDeviceHandle();

				DynamicArray<Fence::Handle> handles;

				for (auto& fence : _fences) handles.push_back(fence);

				return Parent::WaitForFences(device, static_cast<ui32>(_fences.size()), handles.data(), _waitForAll, _timeout);
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const Fence& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			Fence& operator= (Fence&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/**
		@brief Semaphores are a synchronization primitive that can be used to insert a dependency between queue operations or between a queue operation and the host.
		Binary semaphores have two states - signaled and unsignaled.

		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class Semaphore : public V2::Semaphore
		{
		public:
			using Parent = V2::Semaphore;

			/**
			@brief Default constructor.
			*/
			Semaphore() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Logical device specified.
			*/
			Semaphore(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Logical device and allocator specified.
			*/
			Semaphore(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			Semaphore(Semaphore&& _other) noexcept :
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy the semaphore if the handle is not null.
			*/
			~Semaphore()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Create a semaphore.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a semaphore (logical device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a semaphore (logical device and allocator specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy a semaphore.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Query the current counter value of a semaphore created with a SemaphoreType of Timeline from the host.
			*/
			EResult GetCounterValue(uI64& _value)
			{
				return Parent::GetCounterValue(*device, handle, _value);
			}

			/**
			@brief Export an os handle representing the payload of a semaphore.
			*/
			EResult GetOS_Handle(const GetOS_HandleInfo& _getInfo, OS_Handle& _osHandle)
			{
				return Parent::GetOS_Handle(*device, _getInfo, _osHandle);
			}

			/**
			@brief Import a semaphore payload from an os handle.
			*/
			EResult ImportOS_Handle(const ImportOS_HandleInfo& _importPOSIX_Info)
			{
				return Parent::ImportOS_Handle(*device, _importPOSIX_Info);
			}

			/**
			@brief Signal a semaphore created with a SemaphoreType of Timeline with a particular counter value, on the host.
			*/
			EResult Signal(const SignalInfo& _info)
			{
				return Parent::Signal(*device, _info);
			}

			/**
			@brief Wait for a set of semaphores created with a VkSemaphoreType of VK_SEMAPHORE_TYPE_TIMELINE to reach particular counter values on the host.
			*/
			EResult WaitFor(const WaitInfo& _info, uI64 _timeout)
			{
				return Parent::WaitFor(*device, _info, _timeout);
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const Semaphore& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			Semaphore& operator= (Semaphore&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/** @} */
	}
}
