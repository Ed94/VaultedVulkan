/*!
@file VT_Types.hpp

@brief Vaulted Thermals: Types

@details
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"



#ifndef VT_Option__Use_Long_Namespace
/**
@namespace VaultedThermals

@brief Main library namespace for Vaulted Thermals (Vulkan Wrapper)

@details For long namespace: #define VT_Option__Use_Long_Namespace
*/
namespace VT
#else
/**
@namespace VaultedThermals

@brief Main library namespace for Vaulted Thermals (Vulkan Wrapper)

@details VT_Option__Use_Long_Namespace in use.
*/
namespace VaultedThermals
#endif
{
#pragma region Common Object Types

	/** 
	@defgroup Common_Object_Types

	<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-common-objects">Common Object Types Specification</a>
	*/

	/** @namespace Corridors

	@brief Contains shared definitions between the vaults.

	@ingroup Corridors
	*/
	namespace Corridors
	{
		/** 
		@addtogroup Common_Object_Types
		@ingroup Corridors
		@{
		*/

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-commandsyntax">Specification</a>  */
		using DeviceAddress = VkDeviceAddress;

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkDeviceSize.html">Specification</a>  */
		using DeviceSize = VkDeviceSize;

		/**
		* @brief Can be used to facilitate iterating through a read-only structure pointer chain.
		* 
		* @details
		* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBaseInStructure.html">Specification</a> 
		*/
		struct Base_InStructure : V0::VKStruct_Base<VkBaseInStructure>
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
		struct Base_OutStructure : V0::VKStruct_Base<VkBaseOutStructure>
		{
			      EType              SType;
			const Base_OutStructure* Next ;
		};

		/** 
		@struct Offset2D

		@brief Structure specifying a two-dimensional offset.

		@details
		Offsets are used to describe a pixel location within an image or framebuffer, 
		as an (x,y) location for two-dimensional images, or an (x,y,z) location for three-dimensional images.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_offsets">Offsets Specification</a>
		@link 
		*/
		struct Offset2D : V0::VKStruct_Base<VkOffset2D>
		{
			sint32 X, Y;

			bool operator==(const Offset2D _other) {  return X == _other.X && Y == _other.Y ? true : false; }
			bool operator!=(const Offset2D _other) {  return X != _other.X && Y != _other.Y ? true : false; }
		};

		/** 
		@struct Offset3D

		@brief Structure specifying a three-dimensional offset.

		@details
		Offsets are used to describe a pixel location within an image or framebuffer, 
		as an (x,y) location for two-dimensional images, or an (x,y,z) location for three-dimensional images.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_offsets">Offsets Specification</a>
		*/
		struct Offset3D : V0::VKStruct_Base<VkOffset3D>
		{
			sint32 X, Y, Z;

			bool operator==(const Offset3D& _other) { return X == _other.X && Y == _other.Y && Z == _other.Z ? true : false; }
			bool operator!=(const Offset3D& _other) { return X != _other.X && Y != _other.Y && Z != _other.Z ? true : false; }
		};

		/** 
		@struct Extent2D

		@brief Structure specifying a two-dimensional extent.

		@details
		Extents are used to describe the size of a rectangular region of pixels within an image or framebuffer, 
		as (width,height) for two-dimensional images, or as (width,height,depth) for three-dimensional images.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkExtent2D.html">Extent-2D Specification</a>
		*/
		struct Extent2D : V0::VKStruct_Base<VkExtent2D>
		{
			uint32 Width, Height;

			bool operator==(const Extent2D _other) { return Width == _other.Width && Height == _other.Height ? true : false; }
			bool operator!=(const Extent2D _other) { return Width != _other.Width && Height != _other.Height ? true : false; }
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
		struct Extent3D : V0::VKStruct_Base<VkExtent3D>
		{
			uint32 Width, Height, Depth;

			bool operator==(const Extent3D& _other) { return Width == _other.Width && Height == _other.Height && Depth == _other.Depth ? true : false; }
			bool operator!=(const Extent3D& _other) { return Width != _other.Width && Height != _other.Height && Depth == _other.Depth ? true : false; }
		};

		/** 
		@brief Structure specifying a two-dimensional subregion.

		@details
		Rectangles are used to describe a specified rectangular region of pixels within an image or framebuffer. 
		Rectangles include both an offset and an extent of the same dimensionality, as described above. 

		@link https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_rectangles
		*/
		struct Rect2D : V0::VKStruct_Base<VkRect2D>
		{
			Offset2D Offset;
			Extent2D Extent;

			bool operator==(const Rect2D& _other) { Offset == _other.Offset && Extent == _other.Extent ? true : false; }
			bool operator!=(const Rect2D& _other) { Offset != _other.Offset && Extent != _other.Extent ? true : false; }
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

		constexpr DeviceSize Description_MaxSize   = VK_MAX_DESCRIPTION_SIZE   ;   ///< Used for DescriptionStr definition.
		constexpr DeviceSize ExtensionName_MaxSize = VK_MAX_EXTENSION_NAME_SIZE;   ///< Used for ExtensionNameStr definition.

		using ExtensionNameStr = char[ExtensionName_MaxSize];   ///< Can hold an extension name.
		using DescrptionStr    = char[Description_MaxSize  ];   ///< Can hold a description string.

		/**
		@}
		 */


		/**
		@defgroup Flags and Bitmasks
		*/

		/**
		@addtogroup Flags and Bitmasks
		@{
		*/

		/**
		 * @brief Used to represent bitmasks for Vulkan flag types.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFlags">Specification</a> 
		 */
		using Flags = VkFlags;

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAccessFlags">Specification</a> 
		 */
		using AccessFlags = Bitmask<EAccessFlag, VkAccessFlags>;

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkColorComponentFlags">Specification</a>
		 */
		using ColorComponentFlags = Bitmask<EColorComponentFlag, VkColorComponentFlags>;

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAccessFlags">Specification</a> 
		 */
		using DependencyFlags = Bitmask<EDependencyFlag, VkDependencyFlags>;

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceImportFlags">Specification</a> 
		 */
		using FenceImportFlags = Bitmask<EFenceImportFlag, VkFenceImportFlags>;

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFormatFeatureFlags">Specification</a> 
		 */
		using FormatFeatureFlags = Bitmask<EFormatFeatureFlag, VkFormatFeatureFlags>;

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkResolveModeFlags">Specification</a>
		 */
		using ResolveModeFlags = Bitmask<EResolveModeFlags, VkResolveModeFlags>;

		/**
		* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampleCountFlags">Specification</a> 
		*/
		using SampleCountFlags = Bitmask<ESampleCount, VkSampleCountFlags>;

		/**
		@}
		*/

		/**
		@defgroup Pointers
		*/

		/**
		@addtogroup Pointers
		@{
		*/

		/** 
		@brief Vulkan Function Pointer
		*/
		template<typename ReturnType, typename... ParameterTypes>
		using VK_FPtr = ReturnType(VKAPI_PTR*)(ParameterTypes...);

		/** 
		@brief Equivalent to VK_FPtr<void, void>.

		@details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkVoidFunction">Specification</a> 
		*/
		using FPtr_Void = PFN_vkVoidFunction;

		/**
		@}
		*/

		// Misc

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkClearValue">Specification</a>  */
		struct ClearValue
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkClearColorValue">Specification</a>  */
			union UColor
			{
				float32 InFloat[4];
				sint32  InSInt [4];
				uint32  InUInt [4];
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkClearDepthStencilValue">Specification</a>  */
			struct UDepthStencil
			{
				float32 Depth  ;
				uint32  Stencil;
			};

			union
			{
				UColor        Color       ;
				UDepthStencil DepthStencil;
			};
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
		struct ComponentMapping : V0::VKStruct_Base<VkComponentMapping>
		{
			EComponentSwizzle R;
			EComponentSwizzle G;
			EComponentSwizzle B;
			EComponentSwizzle A;

			bool operator==(const ComponentMapping& _other) { return R == _other.R && G == _other.G && B == _other.B && A == _other.A ? true : false; }
			bool operator!=(const ComponentMapping& _other) { return R != _other.R && G != _other.G && B != _other.B && A != _other.A ? true : false; }
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a>  */
		struct ConformanceVersion : V0::VKStruct_Base<VkConformanceVersion>
		{
			uInt8 Major, Minor, Subminor, Patch;

			bool operator==(const ConformanceVersion _other) 
			{ return Major == _other.Major && Minor == _other.Minor && Subminor == _other.Subminor && Patch == _other.Patch ? true : false; }
			bool operator!=(const ConformanceVersion _other) 
			{ return Major != _other.Major && Minor != _other.Minor && Subminor != _other.Subminor && Patch != _other.Patch ? true : false; }
		};

		/** 
		@brief
		Structure specifying an extension properties.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExtensionProperties">Extension Properties Specification</a> 
		*/
		struct ExtensionProperties : V0::VKStruct_Base<VkExtensionProperties>
		{
			ExtensionNameStr ExtensionName;
			uint32           SpecVersion  ;

			// #TODO: Should offer default operator== ? (With strcmp?)
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFormatProperties">Specification</a>  */
		struct FormatProperties : V0::VKStruct_Base<VkFormatProperties>
		{
			FormatFeatureFlags    LinearTilingFeatures ;
			FormatFeatureFlags    OptimalTilingFeatures;
			FormatFeatureFlags    BufferFeatures       ;
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkLayerProperties">Specification</a>  */
		struct LayerProperties : V0::VKStruct_Base<VkLayerProperties>
		{
			ExtensionNameStr Name                 ;
			uint32           SpecVersion          ;
			uint32           ImplementationVersion;
			DescrptionStr    Descrption           ;
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkStencilOpState">Specification</a>  */
		struct StencilOperationState : V0::VKStruct_Base<VkStencilOpState>
		{
			EStencilOperation FailOp     ;
			EStencilOperation PassOp     ;
			EStencilOperation DepthFailOp;
			ECompareOperation CompareOp  ;
			uint32            CompareMask;
			uint32            WriteMask  ;
			uint32            Reference  ;
		};
		
		/**
		 * @brief Surface viewing region.

		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkViewport">Specification</a> 
		 */
		struct Viewport : V0::VKStruct_Base<VkViewport>
		{
			float32 X       , Y       ;
			float32 Width   , Height  ;
			float32 MinDepth, MaxDepth;

			bool operator== (const Viewport& _other) 
			{
				return
				X        == _other.X        && Y        == _other.Y        &&
				Width    == _other.Width    && Height   == _other.Height   &&
				MinDepth == _other.MinDepth && MaxDepth == _other.MaxDepth
				? true : false;
			}

			bool operator!= (const Viewport& _other) 
			{
				return
					X        != _other.X        && Y        != _other.Y        &&
					Width    != _other.Width    && Height   != _other.Height   &&
					MinDepth != _other.MinDepth && MaxDepth != _other.MaxDepth
					? true : false;
			}
		};

		constexpr DeviceSize UUID_Size = VK_UUID_SIZE;

		using UUID = unsigned int[UUID_Size];   ///< Universally unique identifier.


		// TODO: Move these later...

		struct Display
		{
			using Handle = VkDisplayKHR;
		};
	}

	/** @namespace Vault_2

	@brief Repetitive functionality wrapping.
	*/
	namespace V2
	{
		/**
		* @brief Currently hard coded to use STL vector for extensions.
		* 
		* @todo Make the extensions container a template type with enforcement for IDynamicArray.
		*/
		struct LayerAndExtensionProperties
		{
			LayerProperties                   Layer     ;
			DynamicArray<ExtensionProperties> Extensions;
		};
	}

	namespace V3
	{
		using V2::LayerAndExtensionProperties;
	}

	namespace SPIR_V
	{
		using Bytecode = Corridors::uint32;   ///< Word size of a SPIR-V instruction.
	}

}
