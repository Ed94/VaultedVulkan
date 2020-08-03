/*
@file VT_SyncAndCacheControl

@brief Vaulted Thermals: Synchronization and Cache Control

@details
<a href="linkURL">Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		/**
		 * @brief.
		 */
		struct Event
		{
			using Handle = VkEvent;

			struct CreateInfo : Vault_00::VKStruct_Base<VkEventCreateInfo, EStructureType::Event_CreateInfo>
			{
				VkStructureType       sType;
				const void*           pNext;
				VkEventCreateFlags    flags;
			};

			/**
			 * @brief.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateEvent">Specification</a> 
			 * 
			 * \param device
			 * \param pCreateInfo
			 * \param pAllocator
			 * \param pEvent
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _device    ,
				const Event::CreateInfo&    _createInfo,
				const AllocationCallbacks*  _allocator ,
				      Handle*               _event
			)
			{
				return EResult(vkCreateEvent(_device, _createInfo, _allocator, _event));
			}

			/*static void Destroy
			(
				VkDevice                                    device,
				VkEvent                                     event,
				const VkAllocationCallbacks* pAllocator
			)
			{

			}

			static EResult GetStatus(VkDevice device, VkEvent event)
			{

			}

			static EResult Reset(VkDevice device, VkEvent event)
			{

			}

			static EResult Set(VkDevice device, VkEvent event)
			{

			}*/
		};

		/**
		 * @brief .
		 */
		struct Fence
		{
			using Handle = VkFence;

			static constexpr
				Handle NullHandle = Handle(EHandle::Null);

			/**
			 * @brief Specification: .
			 */
			using CreateFlags = Bitmask<EFenceCreateFlag, VkFenceCreateFlags>;

			/** @brief Specification: <a href="linkURL">Specification</a>  */
			using ExternalHandleFlags = Bitmask<EExternalFenceHandleTypeFlag, VkExternalFenceHandleTypeFlagBits>;

			/**
			 * @brief.
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkFenceCreateInfo, EStructureType::Fence_CreateInfo>
			{
				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			* @todo Implement.
			* 
			* VkDeviceEventInfoEXT 
			*/
			struct DeviceEventInfo : Vault_00::VKStruct_Base<VkDeviceEventInfoEXT, EStructureType::Device_EventInfo_EXT>
			{
				VkStructureType         sType;
				const void*             pNext;
				VkDeviceEventTypeEXT    deviceEvent;
			};

			/**
			* @todo Implement.
			*/
			struct DisplayEventInfo : Vault_00::VKStruct_Base<VkDisplayEventInfoEXT, EStructureType::Display_EventInfo_EXT>
			{
				VkStructureType          sType;
				const void* pNext;
				VkDisplayEventTypeEXT    displayEvent;
			};

			/**
			* @todo Implement.
			*/
			struct ExportableWin32 : Vault_00::VKStruct_Base<VkExportFenceWin32HandleInfoKHR, EStructureType::ExportFence_Win32Handle_Info_KHR>
			{
				VkStructureType               sType;
				const void* pNext;
				const SECURITY_ATTRIBUTES* pAttributes;
				DWORD                         dwAccess;
				LPCWSTR                       name;
			};

			/**
			* @todo Implement.
			*/
			struct GetPOSIX_FileDescriptorInfo : Vault_00::VKStruct_Base<VkFenceGetFdInfoKHR, EStructureType::Fence_Get_FD_Info_KHR>
			{
				VkStructureType                      sType;
				const void*                          pNext;
				VkFence                              fence;
				VkExternalFenceHandleTypeFlagBits    handleType;
			};

			/**
			* @todo Implement.
			* 
			* VkFenceGetWin32HandleInfoKHR 
			*/
			struct GetWin32HandleInfo : Vault_00::VKStruct_Base<VkFenceGetWin32HandleInfoKHR, EStructureType::Fence_GetWin32Handle_Info_KHR>
			{
				VkStructureType                      sType;
				const void* pNext;
				VkFence                              fence;
				VkExternalFenceHandleTypeFlagBits    handleType;
			};

			/**
			 * @todo Implement.
			 * 
			 */
			struct ImportFencePOSIX_FileDescriptorInfo : Vault_00::VKStruct_Base<VkImportFenceFdInfoKHR, EStructureType::ImportFence_FD_Info_KHR>
			{
				VkStructureType                      sType;
				const void*                          pNext;
				VkFence                              fence;
				VkFenceImportFlags                   flags;
				VkExternalFenceHandleTypeFlagBits    handleType;
				int                                  fd;
			};

			/**
			 * @todo Implement..
			 * 
			 * 
			 */
			struct ImportFenceWin32HandleInfo : Vault_00::VKStruct_Base<VkImportFenceWin32HandleInfoKHR, EStructureType::ImportFence_Win32Handle_Info_KHR>
			{
				VkStructureType                      sType;
				const void*                          pNext;
				VkFence                              fence;
				VkFenceImportFlags                   flags;
				VkExternalFenceHandleTypeFlagBits    handleType;
				HANDLE                               handle;
				LPCWSTR                              name;
			};

			/**
			 * @brief.
			 */
			struct ExportCreateInfo : Vault_00::VKStruct_Base<VkExportFenceCreateInfo, EStructureType::ExportFence_CreateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      ExternalHandleFlags HandleTypes;
			};


			/**
			 * @brief.
			 * 
			 * \param _logicalDevice
			 * \param _createInfo
			 * \param _allocator
			 * \param _fence
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _logicalDevice,
				const CreateInfo&           _createInfo   ,
				const AllocationCallbacks*  _allocator    ,
				      Handle&               _fence
			)
			{
				return EResult(vkCreateFence(_logicalDevice, _createInfo, _allocator, &_fence));
			}

			/**
			 * @brief.
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \param _allocator
			 */
			static void Destroy
			(
				LogicalDevice::Handle      _logicalDevice,
				      Fence::Handle        _fence        ,
				const AllocationCallbacks* _allocator
			)
			{
				vkDestroyFence(_logicalDevice, _fence, _allocator);
			}

			/**
			 * @brief.
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \return 
			 */
			static EResult GetStatus(LogicalDevice::Handle _logicalDevice, Fence::Handle _fence)
			{
				return EResult(vkGetFenceStatus(_logicalDevice, _fence));
			}

			/**
			* @todo Implement.
			* 
			* vkGetFenceWin32HandleKHR
			* 
			* \return 
			*/
			/*static EResult GetWin32Handle()
			{

			}*/

			/**
			* @todo Implement.
			* 
			* vkGetFenceFdKHR
			* 
			* \param device
			* \param pGetFdInfo
			* \param pFd
			* \return 
			*/
			/*static EResult GetPOSIX_FileDescriptor
			(
				VkDevice                                    device,
				const VkFenceGetFdInfoKHR*                  pGetFdInfo,
				int*                                        pFd
			)
			{
			}

			static EResult ImportFence_POSIX_FileDescriptor
			(
				VkDevice                                    device,
				const VkImportFenceFdInfoKHR*               pImportFenceFdInfo
			)
			{

			}*/

			/**
			 * @todo Implement..
			 * 
			 * vkImportFenceWin32HandleKHR
			 * 
			 * \param device
			 * \param pImportFenceWin32HandleInfo
			 * \return 
			 */
			/*static EResult ImportFenceWin32Handle
			(
				VkDevice                                    device,
				const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo
			)
			{

			}*/

			/**
			 * @brief..
			 * 
			 * @todo Implement.
			 * 
			 * vkRegisterDeviceEventEXT
			 * 
			 * \param device
			 * \param pDeviceEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			/*static EResult RegisterDeviceEvent
			(
				VkDevice                                    device,
				const VkDeviceEventInfoEXT* pDeviceEventInfo,
				const VkAllocationCallbacks* pAllocator,
				VkFence* pFence
			)
			{

			}*/

			/**
			 * @todo Implement..
			 * 
			 * vkRegisterDisplayEventEXT
			 * 
			 * \param device
			 * \param display
			 * \param pDisplayEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			/*static EResult RegisterDisplayEvent
			(
				VkDevice                                    device,
				VkDisplayKHR                                display,
				const VkDisplayEventInfoEXT*                pDisplayEventInfo,
				const VkAllocationCallbacks*                pAllocator,
				VkFence*                                    pFence
			)
			{

			}*/

			/**
			 * @brief.
			 * 
			 * \param _logicalDevice
			 * \param _fences
			 * \param _fenceCount
			 * \return 
			 */
			static EResult Reset(LogicalDevice::Handle _logicalDevice, Fence::Handle& _fences, uint32 _fenceCount)
			{
				return EResult(vkResetFences(_logicalDevice, _fenceCount, &_fences));
			}

			/**
			 * 
			 * @brief .
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkWaitForFences">Specification</a> 
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
				uint32                _fenceCount,
				const Fence::Handle*  _fences    ,
				Bool                  _waitAll   ,
				uInt64                _timeout
			)
			{
				return EResult(vkWaitForFences(_device, _fenceCount, _fences, _waitAll, _timeout));
			}
		};


		/**
		 * @brief.
		 */
		struct Semaphore
		{
			using Handle = VkSemaphore;

			/**
			 * @brief.
			 */
			struct CreateInfo : Vault_00::VKStruct_Base<VkSemaphoreCreateInfo, EStructureType::Semaphore_CreateInfo>
			{
				using CreateFlags = Bitmask<EUndefined, VkSemaphoreCreateFlags>;

				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			struct ExportCreateInfo : Vault_00::VKStruct_Base<VkExportSemaphoreCreateInfo, EStructureType::Export_Semaphore_CreateInfo_KHR>
			{
				VkStructureType                       sType;
				const void* pNext;
				VkExternalSemaphoreHandleTypeFlags    handleTypes;

				struct Win32HandleInfo : Vault_00::VKStruct_Base<VkExportSemaphoreWin32HandleInfoKHR, EStructureType::ExportSemaphore_Win32Handle_Info_KHR>
				{
					VkStructureType               sType;
					const void*                   pNext;
					const SECURITY_ATTRIBUTES*    pAttributes;
					DWORD                         dwAccess;
					LPCWSTR                       name;
				};
			};

			struct GetPOSIX_FileDescriptorInfo : Vault_00::VKStruct_Base<VkSemaphoreGetFdInfoKHR, EStructureType::Semaphore_Get_FD_Info_KHR>
			{
				VkStructureType                          sType;
				const void*                              pNext;
				VkSemaphore                              semaphore;
				VkExternalSemaphoreHandleTypeFlagBits    handleType;
			};

			struct GetWin32HandleInfo : Vault_00::VKStruct_Base<VkSemaphoreGetWin32HandleInfoKHR, EStructureType::Semaphore_GetWin32Handle_Info_KHR>
			{
				VkStructureType                          sType;
				const void*                              pNext;
				VkSemaphore                              semaphore;
				VkExternalSemaphoreHandleTypeFlagBits    handleType;
			};

			struct ImportPOSIX_FileDescriptorInfo : Vault_00::VKStruct_Base<VkImportSemaphoreFdInfoKHR, EStructureType::ImportSemaphore_FD_Info_KHR>
			{
				VkStructureType                          sType;
				const void*                              pNext;
				VkSemaphore                              semaphore;
				VkSemaphoreImportFlags                   flags;
				VkExternalSemaphoreHandleTypeFlagBits    handleType;
				int                                      fd;
			};

			struct ImportWin32HandleInfo : Vault_00::VKStruct_Base<VkImportSemaphoreWin32HandleInfoKHR, EStructureType::ImportSemaphore_Win32Handle_Info_KHR>
			{
				VkStructureType                          sType;
				const void*                              pNext;
				VkSemaphore                              semaphore;
				VkSemaphoreImportFlags                   flags;
				VkExternalSemaphoreHandleTypeFlagBits    handleType;
				HANDLE                                   handle;
				LPCWSTR                                  name;
			};

			struct SignalInfo : Vault_00::VKStruct_Base<VkSemaphoreSignalInfo, EStructureType::Semaphore_SignalInfo>
			{
				VkStructureType    sType;
				const void*        pNext;
				VkSemaphore        semaphore;
				uint64_t           value;
			};

			struct TypeSpecifiedCreateInfo : Vault_00::VKStruct_Base<VkSemaphoreTypeCreateInfo, EStructureType::SemaphoreType_CreateInfo>
			{
				VkStructureType    sType;
				const void*        pNext;
				VkSemaphoreType    semaphoreType;
				uint64_t           initialValue;
			};

			struct WaitInfo : Vault_00::VKStruct_Base<VkSemaphoreWaitInfo, EStructureType::Semaphore_WaitInfo>
			{
				VkStructureType         sType;
				const void*             pNext;
				VkSemaphoreWaitFlags    flags;
				uint32_t                semaphoreCount;
				const VkSemaphore*      pSemaphores;
				const uint64_t*         pValues;
			};


			/**
			 * @brief.
			 * 
			 * \param device
			 * \param pCreateInfo
			 * \param pAllocator
			 * \param pSemaphore
			 * \return 
			 */
			static EResult Create
			(
				LogicalDevice::Handle      _device    ,
				const CreateInfo&          _createInfo,
				const AllocationCallbacks* _allocator ,
				Semaphore::Handle&         _semaphore
			)
			{
				return EResult(vkCreateSemaphore(_device, _createInfo.operator const VkSemaphoreCreateInfo*(), _allocator, &_semaphore));
			}

			static void Destroy
			(
				LogicalDevice::Handle      _device   ,
				Semaphore::Handle          _semaphore,
				const AllocationCallbacks* _allocator
			)
			{
				vkDestroySemaphore(_device, _semaphore, _allocator);
			}

			/*static EResult GetCounterValue
			(
				VkDevice                                    device,
				VkSemaphore                                 semaphore,
				uint64_t*                                   pValue
			)
			{

			}

			static EResult GetPOSIX_FileDescriptor
			(
				VkDevice                                    device,
				const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
				int*                                        pFd
			)
			{

			}

			static EResult GetWin32Handle
			(
				VkDevice                                    device,
				const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
				HANDLE*                                     pHandle
			)
			{

			}

			static EResult ImportPOSIX_FileDescriptor(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo)
			{

			}

			static EResult ImportWin32Handle(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo)
			{

			}

			static EResult Signal(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo)
			{

			}

			static EResult WaitFor
			(
				VkDevice                                    device,
				const VkSemaphoreWaitInfo* pWaitInfo,
				uint64_t                                    timeout
			)
			{

			}*/
		};
	}
}
