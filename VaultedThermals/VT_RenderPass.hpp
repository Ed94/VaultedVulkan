/**
@file VT_RenderPass.hpp

@brief Vaulted Thermals: Render Pass

@details

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
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
#include "VT_Initialization.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"
#include "VT_Pipelines.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_01
	{
		/**
		 * @brief Render passes operate in conjunction with framebuffers. Framebuffers represent a collection of specific memory attachments that a render pass instance uses.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_framebuffers">Specification</a> 
		 */
		struct Framebuffer
		{
			using Handle = VkFramebuffer;
			
			using CreateFlags = Bitmask<EFrameBufferCreateFlag, VkFramebufferCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkFramebufferCreateInfo, EStructureType::Framebuffer_CreateInfo>
			{
				using RenderPass_Handle = VkRenderPass;   // RenderPass::Handle not defined yet. (Defined later in the file)

				      EType              SType          ;
				const void*              Next           ;
				      CreateFlags        Flags          ;
					  RenderPass_Handle  RenderPass     ;
				      uint32             AttachmentCount;
				const ImageView::Handle* Attachments    ;
				      uint32             Width          ;
				      uint32             Height         ;
				      uint32             Layers         ;
			};

			/**
			 * @brief Creates a framebuffer.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkCreateFramebuffer.html">Specification</a> 
			 * 
			 * \param _deviceHanle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _framebuffer
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHanle ,
				const CreateInfo&           _creationSpec,
				const AllocationCallbacks*  _allocator   ,
				      Framebuffer::Handle&  _framebuffer
			)
			{
				return EResult(vkCreateFramebuffer(_deviceHanle, _creationSpec.operator const VkFramebufferCreateInfo*(), _allocator, &_framebuffer));
			}

			/**
			 * @brief Destroy a framebuffer.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyFramebuffer.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _framebuffer
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Framebuffer::Handle _framebuffer, const AllocationCallbacks* _allocator)
			{
				vkDestroyFramebuffer(_deviceHandle, _framebuffer, _allocator);
			}
		};


		/**
		 * @brief A render pass represents a collection of attachments, subpasses, and dependencies between the subpasses, and describes how the attachments are used over the course of the subpasses.
		 */
		struct RenderPass
		{
			using Handle = VkRenderPass;

			using AttachmentDescriptionFlags = Bitmask<EAttachmentDescriptionFlag, VkAttachmentDescriptionFlags>;
			using SubpassDesriptionFlags     = Bitmask<ESubpassDescriptionFlag   , VkSubpassDescriptionFlags   >;
			using CreateFlags                = Bitmask<EUndefined                , VkRenderPassCreateFlags     >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescription">Specification</a>  */
			struct AttachmentDescription : Vault_00::VKStruct_Base<VkAttachmentDescription>
			{
				AttachmentDescriptionFlags Flags         ;
				EFormat                    Format        ;
				ESampleCount               Samples       ;
				EAttachmentLoadOperation   LoadOp        ;
				EAttachmentStoreOperation  StoreOp       ;
				EAttachmentLoadOperation   StencilLoadOp ;
				EAttachmentStoreOperation  StencilStoreOp;
				EImageLayout               InitialLayout ;
				EImageLayout               FinalLayout   ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentReference">Specification</a>  */
			struct AttachmentReference : Vault_00::VKStruct_Base<VkAttachmentReference >
			{
				uint32       Attachment;
				EImageLayout Layout    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassBeginInfo">Specification</a>  */
			struct BeginInfo : Vault_00::VKStruct_Base<VkRenderPassBeginInfo, EStructureType::RenderPass_BeginInfo>
			{
				      EType               SType          ;
				const void*               Next           ;
				      RenderPass::Handle  RenderPass     ;
				      Framebuffer::Handle Framebuffer    ;
				      Rect2D              RenderArea     ;
				      uint32              ClearValueCount;
				const ClearValue*         ClearValues    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDescription">Specification</a>  */
			struct SubpassDescription : Vault_00::VKStruct_Base<VkSubpassDescription>
			{
				      SubpassDesriptionFlags Flags                  ;
				      EPipelineBindPoint     PipelineBindPoint      ;
				      uint32                 InputAttachmentCount   ;
				const AttachmentReference*   InputAttachments       ;
				      uint32                 ColorAttachmentCount   ;
				const AttachmentReference*   ColorAttachments       ;
				const AttachmentReference*   ResolveAttachments     ;
				const AttachmentReference*   DepthStencilAttachment ;
				      uint32                 PreserveAttachmentCount;
				const uint32*                PreserveAttachments    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDependency">Specification</a>  */
			struct SubpassDependency : Vault_00::VKStruct_Base<VkSubpassDependency>
			{
				uint32               SourceSubpass        ;
				uint32               DestinationSubpass   ;
				Pipeline::StageFlags SourceStageMask      ;
				Pipeline::StageFlags DestinationStageMask ;
				AccessFlags          SourceAccessMask     ;
				AccessFlags          DestinationAccessMask;
				DependencyFlags      DependencyFlags      ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_00::VKStruct_Base<VkRenderPassCreateInfo, EStructureType::RenderPass_CreateInfo>
			{
				      EType                  SType          ;
				const void*                  Next           ;
				      CreateFlags            Flags          ;
				      uint32                 AttachmentCount;
				const AttachmentDescription* Attachments    ;
				      uint32                 SubpassCount   ;
				const SubpassDescription*     Subpasses     ;
				      uint32                 DependencyCount;
				const SubpassDependency*     Dependencies   ;
			};

			/**
			 * @brief Create a render pass.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass-creation">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _renderPass
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _createInfo  ,
				const AllocationCallbacks*  _allocator   ,
				      RenderPass::Handle&   _renderPass
			)
			{
				return EResult(vkCreateRenderPass(_deviceHandle, _createInfo.operator const VkRenderPassCreateInfo*(), _allocator, &_renderPass));
			}

			/**
			 * @brief Destroy a render pass.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyRenderPass.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _renderPass
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, RenderPass::Handle _renderPass, const AllocationCallbacks* _allocator)
			{
				vkDestroyRenderPass(_deviceHandle, _renderPass, _allocator);
			}
		};

	}
}
