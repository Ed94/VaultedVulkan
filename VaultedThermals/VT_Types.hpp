/*


*/



#pragma once


// C++ STI
#include <cstddef>
#include <cstdint>

// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_Backend.hpp"



namespace Vulkan
{
	#pragma region Global Typedefs
	// Defines commonly used types.

	using Bool = VkBool32;

	// Integers

	// Flexible

	using uint32 = unsigned int;
	using sint32 = signed   int;


	// Strict

	// Signed
	using sInt8  = signed           char;
	using sInt16 = signed short     int ;
	using sInt32 = signed long      int ;
	using sInt64 = signed long long int ;

	// Unsigned

	using uInt8  = unsigned            char;
	using uInt16 = unsigned short      int ;
	using uInt32 = unsigned long       int ;
	using uInt64 = unsigned long long  int ;

	// Floats

	using float32 =      float ;
	using float64 =      double;

	// Data

	using DataSize = std::size_t   ;
	using sIntPtr  = std::intptr_t ;
	using uIntPtr  = std::uintptr_t;

	// RawStrings

	using CStr                 = char*             ;
	using RoCStr               = const char*       ;
	using CStrArray            = CStr*             ;
	using RoCStrArray          = const char**      ;   // Readonly c-string array.
	using RoSCtr_roArray_Array = const char* const*;   // Array of readonly array of readonly c-string.

	#pragma endregion Global Typedefs

	
	#pragma region Common Object Types
	// https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-common-objects

	namespace Vault_01
	{
		/*
		Structure specifying a two-dimensional offset.

		Offsets are used to describe a pixel location within an image or framebuffer, 
		as an (x,y) location for two-dimensional images, or an (x,y,z) location for three-dimensional images.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_offsets
		*/
		struct Offset2D : Vault_00::VKStruct_Base<VkOffset2D>
		{
			sint32 X;
			sint32 Y;
		};

		/*
		Structure specifying a three-dimensional offset.

		Offsets are used to describe a pixel location within an image or framebuffer, 
		as an (x,y) location for two-dimensional images, or an (x,y,z) location for three-dimensional images.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_offsets
		*/
		struct Offset3D : Vault_00::VKStruct_Base<VkOffset3D>
		{
			sint32 X;
			sint32 Y;
			sint32 Z;
		};

		/*
		Structure specifying a two-dimensional extent.

		Extents are used to describe the size of a rectangular region of pixels within an image or framebuffer, 
		as (width,height) for two-dimensional images, or as (width,height,depth) for three-dimensional images.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkExtent2D.html
		*/
		struct Extent2D : Vault_00::VKStruct_Base<VkExtent2D>
		{
			uint32 Width ;
			uint32 Height;
		};

		/*
		Structure specifying a three-dimensional extent.

		Extents are used to describe the size of a rectangular region of pixels within an image or framebuffer, 
		as (width,height) for two-dimensional images, or as (width,height,depth) for three-dimensional images.

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkExtent3D.html
		*/
		struct Extent3D : Vault_00::VKStruct_Base<VkExtent3D>
		{
			uint32 Width ;
			uint32 Height;
			uint32 Depth ;
		};

		/*
		Structure specifying a two-dimensional subregion.

		Rectangles are used to describe a specified rectangular region of pixels within an image or framebuffer. 
		Rectangles include both an offset and an extent of the same dimensionality, as described above. 

		https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_rectangles
		*/
		struct Rect2D : Vault_00::VKStruct_Base<VkRect2D>
		{
			Offset2D Offset;
			Extent2D Extent;
		};
	}

	#pragma endregion Common Object Types


	// TODO: Needs sorting.

	namespace Vault_Shared
	{
		// These Strings are used throughout the Vulkan API.

		constexpr sint32 Description_MaxSize   = VK_MAX_DESCRIPTION_SIZE   ;   // Used for DescriptionStr definition.
		constexpr sint32 ExtensionName_MaxSize = VK_MAX_EXTENSION_NAME_SIZE;   // Used for ExtensionNameStr definition.

		using ExtensionNameStr = char[ExtensionName_MaxSize];   // Can hold an extension name.
		using DescrptionStr    = char[Description_MaxSize  ];   // Can hold a description string.

		// Flags & Bitmasks

		using Flags = VkFlags;   // Used to represent bitmasks for Vulkan flag types.

		using CallbackDataFlags = Bitmask<EUndefined , Flags>;   // TODO: Add comment on what this is for.
		using QueueFlags        = Bitmask<EQueueFlag , Flags>;   // Bitmask specifying capabilities of queues in a queue family.
		using ImageUsageFlags   = Bitmask<EImageUsage, Flags>;   // Bitmask specifying intended usage of an image.

		// Pointers

		template<typename ReturnType, typename... ParameterTypes>
		// Vulkan Function Pointer
		using VK_FPtr = ReturnType(VKAPI_PTR*)(ParameterTypes...);

		// Equivalent to VK_FPtr<void, void>.
		using FPtr_Void = PFN_vkVoidFunction;


		/*
		Note: Will most likely make a struct wrap, doing this for now...
		*/
		using AllocationCallbacks = VkAllocationCallbacks;

		

		/*
		Structure specifying an extension properties.

		https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#VkExtensionProperties
		*/
		struct ExtensionProperties : Vault_00::VKStruct_Base<VkExtensionProperties>
		{
			ExtensionNameStr ExtensionName;
			uint32           SpecVersion  ;
		};

		/*
		Images represent multidimensional - up to 3 - arrays of data which can be used for various purposes 
		(e.g. attachments, textures), 
		by binding them to a graphics or compute pipeline via descriptor sets, 
		or by directly specifying them as parameters to certain commands.
		*/
		struct Image
		{
			using Handle = VkImage;
		};

		/*
		The VkComponentMapping components member describes a remapping from components of the image to components of the vector 
		returned by shader image instructions. This remapping must be the identity swizzle for storage image descriptors, 
		input attachment descriptors, framebuffer attachments, and any VkImageView used with a combined image sampler that 
		enables sampler Y’CBCR conversion.
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

		using CullModeFlags = Bitmask<ECullModeFlag, Flags>;
		using SampleCountFlags = Bitmask<ESampleCount, Flags>;
		using SampleMask = VkSampleMask;   // TODO: Not sure yet...

		using ColorComponentFlags = Bitmask<EColorComponentFlag, Flags>;

		struct Sampler
		{
			using Handle = VkSampler;
		};	


		constexpr sint32 UUID_Size = VK_UUID_SIZE;

		using UUID = unsigned int[UUID_Size];
	}

	namespace SPIR_V
	{
		using Bytecode = uint32;
	}
}
