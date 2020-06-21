/*****************************************************************//**
 * \file   VT_Types.hpp
 * \brief  Vaulted Thermals: Types
 *********************************************************************/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"



namespace VaultedThermals
{
	#pragma region Common Object Types

	/** 
	@defgroup Common_Object_Types

	<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-common-objects">Common Object Types Specification</a>
	*/

	namespace Corridors
	{
		/** 
		@addtogroup Common_Object_Types
		@{
		*/

		/** 
		@struct Offset2D

		@brief Structure specifying a two-dimensional offset.

		@details
		Offsets are used to describe a pixel location within an image or framebuffer, 
		as an (x,y) location for two-dimensional images, or an (x,y,z) location for three-dimensional images.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_offsets">Offsets Specification</a>
		@link 
		*/
		struct Offset2D : Vault_00::VKStruct_Base<VkOffset2D>
		{
			sint32 X;
			sint32 Y;
		};

		/** 
		@struct Offset3D

		@brief Structure specifying a three-dimensional offset.

		@details
		Offsets are used to describe a pixel location within an image or framebuffer, 
		as an (x,y) location for two-dimensional images, or an (x,y,z) location for three-dimensional images.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_offsets">Offsets Specification</a>
		*/
		struct Offset3D : Vault_00::VKStruct_Base<VkOffset3D>
		{
			sint32 X;
			sint32 Y;
			sint32 Z;
		};

		/** 
		@struct Extent2D

		@brief Structure specifying a two-dimensional extent.

		@details
		Extents are used to describe the size of a rectangular region of pixels within an image or framebuffer, 
		as (width,height) for two-dimensional images, or as (width,height,depth) for three-dimensional images.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkExtent2D.html">Extent-2D Specification</a>
		*/
		struct Extent2D : Vault_00::VKStruct_Base<VkExtent2D>
		{
			uint32 Width ;
			uint32 Height;
		};

		/** 
		@struct Extent3D

		@brief Structure specifying a three-dimensional extent.

		@details
		Extents are used to describe the size of a rectangular region of pixels within an image or framebuffer, 
		as (width,height) for two-dimensional images, or as (width,height,depth) for three-dimensional images.

		@link 
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkExtent3D.html">Extent-3D Specification</a>
		*/
		struct Extent3D : Vault_00::VKStruct_Base<VkExtent3D>
		{
			uint32 Width ;
			uint32 Height;
			uint32 Depth ;
		};

		/** 
		@brief Structure specifying a two-dimensional subregion.

		@details
		Rectangles are used to describe a specified rectangular region of pixels within an image or framebuffer. 
		Rectangles include both an offset and an extent of the same dimensionality, as described above. 

		@link https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_rectangles
		*/
		struct Rect2D : Vault_00::VKStruct_Base<VkRect2D>
		{
			Offset2D Offset;
			Extent2D Extent;
		};

		/**
		* @}
		*/
	}

	#pragma endregion Common Object Types


	// TODO: Needs sorting.

	namespace Corridors
	{
		/**
		@defgroup CommonStrings
		 */

		/**
		@addtogroup CommonStrings
		@{
		 */

		constexpr sint32 Description_MaxSize   = VK_MAX_DESCRIPTION_SIZE   ;   ///< Used for DescriptionStr definition.
		constexpr sint32 ExtensionName_MaxSize = VK_MAX_EXTENSION_NAME_SIZE;   ///< Used for ExtensionNameStr definition.

		using ExtensionNameStr = char[ExtensionName_MaxSize];   ///< Can hold an extension name.
		using DescrptionStr    = char[Description_MaxSize  ];   ///< Can hold a description string.

		/**
		@}
		 */

		// Flags & Bitmasks

		using Flags = VkFlags;   ///< Used to represent bitmasks for Vulkan flag types.

		// Pointers

		/** 
		@brief Vulkan Function Pointer
		*/
		template<typename ReturnType, typename... ParameterTypes>
		using VK_FPtr = ReturnType(VKAPI_PTR*)(ParameterTypes...);

		/** @brief Equivalent to VK_FPtr<void, void>.
		*/
		using FPtr_Void = PFN_vkVoidFunction;

		// Misc

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceSize.html">Specification</a>  */
		using DeviceSize = VkDeviceSize;

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-commandsyntax">Specification</a>  */
		using DeviceAddress = VkDeviceAddress;

		/**
		 * @brief Can be used to facilitate iterating through a read-only structure pointer chain.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBaseInStructure.html">Specification</a> 
		 */
		struct Base_InStructure : Vault_00::VKStruct_Base<VkBaseInStructure>
		{
			      EType             SType;
			const Base_InStructure* Next ;
		};

		/**
		 * @brief Can be used to facilitate iterating through a structure pointer chain that returns data back to the application.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBaseOutStructure.html">Specification</a> 
		 */
		struct Base_OutStructure : Vault_00::VKStruct_Base<VkBaseOutStructure>
		{
			      EType              SType;
			const Base_OutStructure* Next ;
		};

		/** 
		@todo Make proper structure.
		*/
		using AllocationCallbacks = VkAllocationCallbacks;

		/** 
		@brief
		Structure specifying an extension properties.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExtensionProperties">Extension Properties Specification</a> 
		*/
		struct ExtensionProperties : Vault_00::VKStruct_Base<VkExtensionProperties>
		{
			ExtensionNameStr ExtensionName;
			uint32           SpecVersion  ;
		};

		/** 
		@brief Structure specifying a color component mapping.

		@details
		The VkComponentMapping components member describes a remapping from components of the image to components of the vector 
		returned by shader image instructions. This remapping must be the identity swizzle for storage image descriptors, 
		input attachment descriptors, framebuffer attachments, and any VkImageView used with a combined image sampler that 
		enables sampler Y’CBCR conversion.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkComponentMapping.html">Component Mapping Specification</a> 
		*/
		struct ComponentMapping : Vault_00::VKStruct_Base<VkComponentMapping>
		{
			EComponentSwizzle R;
			EComponentSwizzle G;
			EComponentSwizzle B;
			EComponentSwizzle A;
		};

		struct Viewport
		{
			float X       , Y       ;
			float Width   , Height  ;
			float MinDepth, MaxDepth;
		};

		using ColorComponentFlags = Bitmask<EColorComponentFlag, Flags>;

		constexpr sint32 UUID_Size = VK_UUID_SIZE;

		using UUID = unsigned int[UUID_Size];
	}

	namespace SPIR_V
	{
		using Bytecode = Corridors::uint32;
	}
}
