/** 
@file VaultedThermals.hpp

@brief 
VaultedThermals Include Interface
    
The library single include header.

If you want to use the short namespace: #define VT_Option__Use_Short_Namespace
Short Namespace: VT
*/



#pragma once



/**
 * @page LibraryOutline 
 * 
 * @section GuideSec Guide

 NOTE: This is very outdated, please do not use this outline.

 * The libraries files are organized based on the Khronos Vulkan Specification manual:
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html">Vulkan Specification</a>
 *
 * Each file Starting from the number 2 represents a chapter/category of the manual.
 * Files may have non-specification within them.
 * 
 * Content related directly to the Vulkan API will have a link to its respective specification.
 * 
 * Files that do not follow specification are labeled with an NS-#.
 * Files that are for platform extended functionality are labeled with EX-#.
 * 
 * Note: Files are in order of include, so specification modules may be slightly out of order. 
 * Files may also contain more than one specification module as the modules have concepts bleed to 
 * different modules based on the desired context of their description.
 * (If a submodule is within a different module file, it will be noted, 
 * [right now due to state of progress it may not be, please use the class hierarchy's to help find them] )
 * 
 * Features that would be nice to have:
 * @todo Have support for object model enforcement.
 * 
 * @subsection OutlineSec Outline
 * 
 * ## NS-1: VT_Vaults.hpp
 * Defines the vaulting scope used for the various levels of implementation within the library.
 * 
 * ## NS-2: VT_Platform.hpp
 * Platform detection and includes the C-API vulkan header.
 * 
 * * ## NS-3: Unsorted global enum definitions. 
 * ### VT_Enums.hpp
 * 
 * ## NS-4: VT_Backend.hpp
 * NS-1: Backend related definitions for use in implementing the library.
 * 
 * ## 2: Fundamentals
 * ### VT_Types.hpp
 * Fundamental Typedefs, Common Object Types, Non-Specification Types.
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals">Fundamentals Specification</a>
  
 * ## NS-5: Unsorted global enum definitions.
 * ### VT_Constants.hpp
 * 
 * ## 3: Initialization
 * ### VT_Initialization.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">Initialization Specification</a>
 * 
 * ## 4: Devices and Queues
 * 
 * ### 4.1: Physical Device 
 * #### VT_PhysicalDevice.hpp
 * Contains: 4.3 QueueFamilies
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues">Queues Specification</a>
 *
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Physical Device Specification</a>
 * 
 * ### 4.2 : Logical Device
 * #### VT_LogicalDevice.hpp
 * Contains: 4.3 Queues
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-queues">Queues Specification</a>
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Logical Device Specification</a> 
 * 
 * ## 11: Resource Creation
 * ### 11.1-5: VT_Resource.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources">Resource Specification</a> 
 *
 * ## 7 Render Pass
 * ### VT_RenderPass.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
 * 
 * ## 8 Shaders
 * ### VT_Shaders.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shaders">Specification</a>  
 * 
 * ## 9 Pipelines
 * ### VT_Pipelines.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
 * 
 * ## 5 Command Buffers
 * ### VT_Command.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
 * 
 * ## EX-1: Window Surface 
 * ### VT_Surface.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_surface">Specification</a> 
 * 
 * ## EX-2: Swap Chain
 * ###VT_SwapChain.hpp
 * 
 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_swapchain">Specification</a>  
 */




/*****************************************************************//**
 * \file   Foreign_Bitmask.hpp
 * \brief  
 * A really bare bones bitmasking wrapping implementation for
 * making bitmasks more intuitive to deal with.
 * 
 *********************************************************************/



#ifndef BITMASK_DEFINED

	#include <type_traits>

	#define BITMASK_DEFINED

	template<typename Enum>
	struct Bitmaskable
	{
		static const bool specified = false;
	};

	#define SpecifyBitmaskable(__ENUM)      \
	template<>                              \
	struct Bitmaskable<__ENUM>              \
	{							            \
		static const bool specified = true; \
	};	

	template
	<
		class    EnumType             , 
		typename BitmaskRepresentation
	>
	struct Bitmask
	{
	private:
		static_assert(Bitmaskable<EnumType>::specified, "EnumType must be a Bitmaskable Type.");

		using _ThisType = Bitmask<EnumType, BitmaskRepresentation>;

	public:

		using Representation = BitmaskRepresentation;
		using Enum           =  EnumType            ;   // Guaranteed to be implemented by a Bitmaskable type (or there will be a compile error..);

		template<typename... BitTypes>
		Bitmask(BitTypes... _bits)
		{
			mask = (Representation(_bits) | ...);
		}

		template<typename... BitType>
		void Add(const BitType... _bits)
		{
			mask |= (Representation(_bits) | ...);
		}

		void Clear()
		{
			mask = 0;
		}

		bool Has(const Enum _bit) const
		{
			return (mask & Representation(_bit)) == Representation(_bit);
		}

		template<typename... BitType>
		bool HasOrEither(const BitType... _bits)
		{
			return (mask & (Representation(_bits) | ...)) != 0;
		}

		template<typename... BitType>
		bool HasExactly(const BitType... _bits)
		{
			return (mask & (Representation(_bits) | ...)) == mask;
		}

		template<typename... BitType>
		template Remove(const BitType... _bits)
		{
			if (mask <= 0) return n;

			Representation

			mask &= ~(Representation(_bits) | ...);
		}

		template<typename... BitType>
		void Set(const BitType... _bits)
		{
			mask = (Representation(_bits) | ...);
		}

		_ThisType& operator = (const BitmaskRepresentation _mask) { mask = _mask; return *this; }

		operator Representation()
		{
			return mask;
		}

	private:
		Representation mask;
	};

#endif								 




/*
Convention Enforcer

A macro tool for defining Enforcers for a template calling convention.

Requires std::forward.

C++17
*/



#pragma once



#ifndef CONVENTION_ENFORCER_H


	#define CONVENTION_ENFORCER_H


	template <class ID>
	struct EnforcementSet;

	#define MakeConventionEnforcer_ConventionID(__API_NAME) \
	class EnforcerID_##__API_NAME;

	#define MakeConventionEnforcer_EnforcementSet(__API_NAME, __ATTRIBUTE, __CALL)   \
	template<>																	     \
	struct EnforcementSet<EnforcerID_##__API_NAME>					                 \
	{																			     \
		template<typename FunctionType, FunctionType*>                               \
		struct Enforcer_CallMaker;                                                   \
																					 \
		template																	 \
		<																			 \
			typename    ReturnType    ,                                              \
			typename... ParameterTypes,                                              \
			ReturnType(*FunctionType)(ParameterTypes...)                             \
		>											                                 \
		struct Enforcer_CallMaker<ReturnType(ParameterTypes...), FunctionType>       \
		{																		     \
			static __ATTRIBUTE ReturnType __CALL Call(ParameterTypes... _parameters) \
			{																		 \
				return FunctionType(std::forward<ParameterTypes>(_parameters)...);	 \
			}																		 \
		};																			 \
	};

	#define MakeConventionEnforcer(__API_NAME, __ATTRIBUTE, __CALL)        \
	MakeConventionEnforcer_ConventionID(__API_NAME);                       \
	MakeConventionEnforcer_EnforcementSet(__API_NAME, __ATTRIBUTE, __CALL);

	template
	<
		class    ID          ,
		typename FunctionType,
		FunctionType& _functionRef
	>
	auto Enforced_Call()
	{
		return &(EnforcementSet<ID>::template Enforcer_CallMaker<FunctionType, &_functionRef>::Call);
	};

	/*
	Ease of use macro to call the Enforcer_Caller for the defined API convention.
	*/
	#define EnforceConvention(__API_NAME, __FUNCTION)               \
	Enforced_Call<__API_NAME, decltype(__FUNCTION), __FUNCTION>();


#endif




 /** 
 @file VT_Vaults.hpp

 @brief Vaulted Thermals: Vault Definitions

 @details

 Vaults (Designator):
 MagmaChamber
 V0
 V1
 V2
 V3
 V4
 V5
 V6


 Important: Higher numbered vaults may require a lower level vault to be opened. 
 If the vault is not open, it will define the open definition itself implicitly.

 Opening the MagmaChamber vault is unique int that it affects all other vaults.
 When opened, the definition will change the loader interfaced with for all the implementation
 in the other vaults to the loader generated by the MagmaChamber vault.
 Define macro: VT_Vault_MagmaChamber_Open if you want this. [Note: Currently not implemented]

 Note: Vaults 3 and 7 must be opened before use (see macro definitions for opening). 
 This is due to their implementation making use of static or dynamic object allocations. 
 If the vaults are not properly opened all that will exist within them is a namespace called: Vault_Closed.

 Vault 3 Open Macro: #define VT_Vault_3_Open
 Vault 6 Open Macro: #define VT_Vault_6_Open

 If VT_Option__Use_Short_Namespace is defined, short vault namespace will be used.
 Short namespace: V#, where # is the vault number. (Exception: Corridors, Vault_MagmaChamber)
 */



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	/** @namespace Corridors

	@brief Contains shared definitions between the vaults.
	*/
	namespace Corridors {}

	/** @namespace Vault_MagmaChamber

	@todo Look into possibly implementing with the Volk library.

	@brief Meta-Loading Setup.

	@details When the heat at the control gate isn't enough. 
	*/
	namespace Vault_MagmaChamber {}

	/** @namespace Vault_0

	@brief Backend vault for VaultedThermals

	@details For now only abstracts away OS Platform details and basic meta-structure definitions.
	*/
	namespace V0 { using namespace Corridors; }

	/** @namespace Vault_1
	*
	*	@brief 1:1 Wrapping of Vulkan API
	*/
	namespace V1 { using namespace Corridors; }

	/** @namespace Vault_2

	@brief Repetitive functionality wrapping.
	*/
	namespace V2 { using namespace Corridors; }

	/** @namespace Vault_3

	@brief Object-Oriented wrapping
	*/
	namespace V3 { using namespace Corridors; }

	/** @namespace Vault_4

	@brief Object-Oriented bootstrapped backend
	*/
	namespace V4 { using namespace Corridors; }
}




/*****************************************************************//**
* @file   VT_Platform.hpp
* @brief  Vaulted Thermals: Platform Specification
* 
* @details The Vulkan C-API header is included here and platform detection implementation is defined.
*********************************************************************/



#pragma region Includes


#ifdef _WIN32

#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR 
#endif

#endif


/** 
@todo
This guard is necessary to prevent redefinition errors. I am not entirely sure with pragma once
specified, why this is required.
*/
#ifndef VT_VULKAN_INCLUDEGUARD
#define VT_VULKAN_INCLUDEGUARD

#include <vulkan/vulkan.h>

#endif



#pragma endregion Includes



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V0
	{
		/** @enum EOS_Platform
		@brief Enum specifies operating system platform.
		*/
		enum class EOS_Platform
		{
			Windows, Mac, Linux
		};

	#ifdef _WIN32

		/** @var OS_Platform

		@brief Contains the definition of the OS_Platform. (Set to windows)
		*/
		constexpr EOS_Platform OS_Platform = EOS_Platform::Windows;

	#endif

		/**  
		@struct PlatformTypes_Maker

		@brief Defines maker of platform struct that defines operating system types.
		*/
		template<EOS_Platform>
		struct PlatformTypes_Maker;

		/** 
		@struct PlatformTypes_Maker_WindowsImplementation

		@brief Defines Windows specific types.
		*/	
		template<>
		struct PlatformTypes_Maker<EOS_Platform::Windows>
		{
			using OS_AppHandle    = HINSTANCE;
			using OS_WindowHandle = HWND     ;
		};

		/** 
		* @struct PlatformTypes
		* 
		* @brief A structure containing the types for the detected platform.
		*/
		using PlatformTypes = PlatformTypes_Maker<OS_Platform>;
	}


	/**
	@def Vulkan Convention Enforcement.

	@brief Generates the convention enforcer set for the vulkan API.

	@details
	EnforceConvention(EnforcerID_Vulkan, _functionName) will wrap a function call with the proper calling conventions for the vulkan api.
	*/
	MakeConventionEnforcer(Vulkan, VKAPI_ATTR, VKAPI_CALL)
}




/*
@file VT_CPP_STL.hpp

@brief C++ STL related definitions
*/



// C++
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <typeinfo>



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace Corridors
	{
		/**
		 * @brief Vulkan's boolean type.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBool32">Specification</a> 
		 */
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

		using uInt8  = unsigned           char;
		using uInt16 = unsigned short     int ;
		using uInt32 = unsigned long      int ;
		using uInt64 = unsigned long long int ;

		// Floats

		using float32 =      float ;
		using float64 =      double;

		// Data

		using VoidPtr  = void*  ;
		using PtrArray = void*[];

		using DataSize = std::size_t   ;
		using sIntPtr  = std::intptr_t ;
		using uIntPtr  = std::uintptr_t;

		// RawStrings

		using CStr                 = char*             ;
		using RoCStr               = const char*       ;
		using CStrArray            = CStr*             ;
		using RoCStrArray          = const char**      ;   ///< Readonly c-string array.
		using RoSCtr_roArray_Array = const char* const*;   ///< Array of readonly array of readonly c-string.
	}
}




/**
@file VT_Enums.hpp

@brief Vaulted Thermals: Enumerations
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
    namespace Corridors
    {
	#pragma region VT_Enums

		/** 
		@enum Undefined Enum
		@brief Necessary for Bitmasks in the Vulkan specification that are not defined but reserved for future use.
		*/
		enum class EUndefined : uint32 {};

		SpecifyBitmaskable(EUndefined);

		/**
		 * @enum Handle Enum
		 */
		enum class EHandle
		{
			Null = VK_NULL_HANDLE
		};

	#pragma endregion VT_Enums

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAccessFlagBits">Specification</a>  */
		enum class EAccessFlag : uint32
		{
			IndirectCommandRead                 = VK_ACCESS_INDIRECT_COMMAND_READ_BIT                ,
			IndexRead                           = VK_ACCESS_INDEX_READ_BIT                           ,
			VertexAttributeRead                 = VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT                ,
			UniformRead                         = VK_ACCESS_UNIFORM_READ_BIT                         ,
			InputAttachmentRead                 = VK_ACCESS_INPUT_ATTACHMENT_READ_BIT                ,
			ShaderRead                          = VK_ACCESS_SHADER_READ_BIT                          ,
			ShaderWrite                         = VK_ACCESS_SHADER_WRITE_BIT                         ,
			ColorAttachmentRead                 = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT                ,
			ColorAttachmentWrite                = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT               ,
			DepthStencilAttachmentRead          = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT        ,
			DepthStencilAttachmentWrite         = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT       ,
			TransferRead                        = VK_ACCESS_TRANSFER_READ_BIT                        ,
			TransferWrite                       = VK_ACCESS_TRANSFER_WRITE_BIT                       ,
			HostRead                            = VK_ACCESS_HOST_READ_BIT                            ,
			HostWrite                           = VK_ACCESS_HOST_WRITE_BIT                           ,
			MemoryRead                          = VK_ACCESS_MEMORY_READ_BIT                          ,
			MemoryWrite                         = VK_ACCESS_MEMORY_WRITE_BIT                         ,
			TransformFeedback_Write_EXT         = VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT         ,   // Provided by VK_EXT_transform_feedback
			TransformFeedback_CounterRead_EXT   = VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT  ,   // Provided by VK_EXT_transform_feedback
			TransformFeedback_CounterWrite_EXT  = VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT ,   // Provided by VK_EXT_transform_feedback
			ConditionalRendering_Read_EXT       = VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT       ,   // Provided by VK_EXT_conditional_rendering
			ColorAttachment_ReadNoncoherent_EXT = VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT,   // Provided by VK_EXT_blend_operation_advanced
			AccelerationStructure_Read_KHR      = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR      ,   // Provided by VK_KHR_ray_tracing
			AccelerationStructure_Write_KHR     = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR     ,   // Provided by VK_KHR_ray_tracing
			ShadingRateImage_Read_NV            = VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV           ,   // Provided by VK_NV_shading_rate_image
			FragmentDensityMap_Read_EXT         = VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT        ,   // Provided by VK_EXT_fragment_density_map
			CommandPreprocess_Read_NV           = VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV           ,   // Provided by VK_NV_device_generated_commands
			CommandPreprocess_Write_NV          = VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV          ,   // Provided by VK_NV_device_generated_commands
			AccelerationStructure_Read_NV       = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_NV       ,   // Provided by VK_NV_ray_tracing
			AccelerationStructure_Write_NV      = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_NV      ,   // Provided by VK_NV_ray_tracing
		};

		/**
		 * @enum API_Version
		 * 
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#extendingvulkan-coreversions-versionnumbers">Specification</a> 
		 * 
		 */
		enum class EAPI_Version
		{
			_1_0 = VK_API_VERSION_1_0,
			_1_1 = VK_API_VERSION_1_1,
			_1_2 = VK_API_VERSION_1_2
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescriptionFlagBits">Specification</a>  */
		enum class EAttachmentDescriptionFlag : uint32
		{
			AttachmentDescription_MAY_ALIAS = VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentLoadOp">Specification</a>  */
		enum class EAttachmentLoadOperation : uint32
		{
			Load     = VK_ATTACHMENT_LOAD_OP_LOAD     , 
			Clear    = VK_ATTACHMENT_LOAD_OP_CLEAR    ,
			DontCare = VK_ATTACHMENT_LOAD_OP_DONT_CARE 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentStoreOp">Specification</a>  */
		enum class EAttachmentStoreOperation : uint32
		{
			Store    = VK_ATTACHMENT_STORE_OP_STORE    ,
			DontCare = VK_ATTACHMENT_STORE_OP_DONT_CARE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBlendFactor">Specification</a>  */
		enum class EBlendFactor : uint32
		{
			Zero                      = VK_BLEND_FACTOR_ZERO                    ,
			One                       = VK_BLEND_FACTOR_ONE                     ,
			SourceColor               = VK_BLEND_FACTOR_SRC_COLOR               ,
			OneMinusOne_SourceColor   = VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR     ,
			DesinationColor           = VK_BLEND_FACTOR_DST_COLOR               ,
			OneMinus_DestinationColor = VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR     ,
			AlphaSource               = VK_BLEND_FACTOR_SRC_ALPHA               ,
			OneMinus_AlphaSource      = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA     ,
			AlphaDestination          = VK_BLEND_FACTOR_DST_ALPHA               ,
			OneMinus_AlphaDestination = VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA     ,
			ConstantColor             = VK_BLEND_FACTOR_CONSTANT_COLOR          ,
			OneMinus_ConstantColor    = VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR,
			ConstantAlpha             = VK_BLEND_FACTOR_CONSTANT_ALPHA          ,
			OneMinus_ConstantAlpha    = VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA,
			SourceAlphaSaturate       = VK_BLEND_FACTOR_SRC_ALPHA_SATURATE      ,
			SourceOne_Color           = VK_BLEND_FACTOR_SRC1_COLOR              ,
			OneMinus_SourceOneColor   = VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR    ,
			SourceOneAlpha            = VK_BLEND_FACTOR_SRC1_ALPHA              ,
			OneMinus_SourceOneAlpha   = VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA    
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBlendOp">Specification</a>  */
		enum class EBlendOperation : uint32
		{
			Add                  = VK_BLEND_OP_ADD                   ,
			Subtract             = VK_BLEND_OP_SUBTRACT              ,
			ReverseSubtract      = VK_BLEND_OP_REVERSE_SUBTRACT      ,
			Mininum              = VK_BLEND_OP_MIN                   ,
			Maximum              = VK_BLEND_OP_MAX                   ,
			Zero_EXT             = VK_BLEND_OP_ZERO_EXT              ,
			Source_EXT           = VK_BLEND_OP_SRC_EXT               ,
			Destination_EXT      = VK_BLEND_OP_DST_EXT               ,
			SourceOver_EXT       = VK_BLEND_OP_SRC_OVER_EXT          ,
			DestinationOver_EXT  = VK_BLEND_OP_DST_OVER_EXT          ,
			SourceIn_EXT         = VK_BLEND_OP_SRC_IN_EXT            ,
			DestinationIN_ET     = VK_BLEND_OP_DST_IN_EXT            ,
			SourceOut_EXT        = VK_BLEND_OP_SRC_OUT_EXT           ,
			DestinationOut_EXT   = VK_BLEND_OP_DST_OUT_EXT           ,
			SourceAtop_EXT       = VK_BLEND_OP_SRC_ATOP_EXT          ,
			DestinationATop_EXT  = VK_BLEND_OP_DST_ATOP_EXT          ,
			XOR_EXT              = VK_BLEND_OP_XOR_EXT               ,
			Multiply_EXT         = VK_BLEND_OP_MULTIPLY_EXT          ,
			Screen_EXT           = VK_BLEND_OP_SCREEN_EXT            ,
			Overlay_EXT          = VK_BLEND_OP_OVERLAY_EXT           ,
			Darken_EXT           = VK_BLEND_OP_DARKEN_EXT            ,
			Lighten_EXT          = VK_BLEND_OP_LIGHTEN_EXT           ,
			ColorDodge_EXT       = VK_BLEND_OP_COLORDODGE_EXT        ,
			ColorBurn_EXT        = VK_BLEND_OP_COLORBURN_EXT         ,
			HardLight_EXT        = VK_BLEND_OP_HARDLIGHT_EXT         ,
			SoftLight_Ext        = VK_BLEND_OP_SOFTLIGHT_EXT         ,
			Difference_Ext       = VK_BLEND_OP_DIFFERENCE_EXT        ,
			Exclusion_Ext        = VK_BLEND_OP_EXCLUSION_EXT         ,
			Invert_Ext           = VK_BLEND_OP_INVERT_EXT            ,
			Invert_RGB_Ext       = VK_BLEND_OP_INVERT_RGB_EXT        ,
			LinearDodge_Ext      = VK_BLEND_OP_LINEARDODGE_EXT       ,
			LinearBurn_Ext       = VK_BLEND_OP_LINEARBURN_EXT        ,
			VividLight_Ext       = VK_BLEND_OP_VIVIDLIGHT_EXT        ,
			LinearLight_Ext      = VK_BLEND_OP_LINEARLIGHT_EXT       ,
			PinLight_Ext         = VK_BLEND_OP_PINLIGHT_EXT          ,
			Hardmix_Ext          = VK_BLEND_OP_HARDMIX_EXT           ,
			HSL_Hue_Ext          = VK_BLEND_OP_HSL_HUE_EXT           ,
			HSL_Saturation_Ext   = VK_BLEND_OP_HSL_SATURATION_EXT    ,
			HSL_Color_Ext        = VK_BLEND_OP_HSL_COLOR_EXT         ,
			HSL_Luminosity_Ext   = VK_BLEND_OP_HSL_LUMINOSITY_EXT    ,
			Plus_Ext             = VK_BLEND_OP_PLUS_EXT              ,
			PlusClamped_Ext      = VK_BLEND_OP_PLUS_CLAMPED_EXT      ,
			PlusClampedAlpha_Ext = VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT,
			PlusDarker_EXT       = VK_BLEND_OP_PLUS_DARKER_EXT       ,
			Minus_EXT            = VK_BLEND_OP_MINUS_EXT             ,
			MinusClamped_EXT     = VK_BLEND_OP_MINUS_CLAMPED_EXT     ,
			Constrast_EXT        = VK_BLEND_OP_CONTRAST_EXT          ,
			InvertOVG_EXT        = VK_BLEND_OP_INVERT_OVG_EXT        ,
			Red_EXT              = VK_BLEND_OP_RED_EXT               ,
			Green_EXT            = VK_BLEND_OP_GREEN_EXT             ,
			Blue_EXT             = VK_BLEND_OP_BLUE_EXT
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-commandsyntax">Specification</a> .
		 */
		enum EBool
		{
			True  = VK_TRUE ,
			False = VK_FALSE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBorderColor">Specification</a>  */
		enum EBorderColor : uint32
		{
			Float_TransparentBlack = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK,
			Int_TransparentBlack   = VK_BORDER_COLOR_INT_TRANSPARENT_BLACK  ,
			Float_OpaqueBlack      = VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK     , 
			Int_OpaqueBlack        = VK_BORDER_COLOR_INT_OPAQUE_BLACK       , 
			Float_OpaqueWhite      = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE     , 
			Int_OpaqueWhite        = VK_BORDER_COLOR_INT_OPAQUE_WHITE       , 

			// Provided by VK_EXT_custom_border_color
			Float_Custom_EXT = VK_BORDER_COLOR_FLOAT_CUSTOM_EXT,

			// Provided by VK_EXT_custom_border_color
			Int_Custom_EXT = VK_BORDER_COLOR_INT_CUSTOM_EXT,
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateFlagBits">Specification</a> 
		 */
		enum class EBufferCreateFlag : uint32
		{
			SparseBinding                       = VK_BUFFER_CREATE_SPARSE_BINDING_BIT                   ,
			SparseResidency                     = VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT                 ,
			SparseAliased                       = VK_BUFFER_CREATE_SPARSE_ALIASED_BIT                   ,
			Protected                           = VK_BUFFER_CREATE_PROTECTED_BIT                        ,
			DeviceAddressCaptureReplay          = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT    ,
			DeviceAddressCaptureReplayExtension = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT,
			DeviceAddressCaptureReplayKHR       = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferUsageFlagBits">Specification</a>  */
		enum class EBufferUsage : uint32
		{
			TransferSource      = VK_BUFFER_USAGE_TRANSFER_SRC_BIT        ,
			TransferDestination = VK_BUFFER_USAGE_TRANSFER_DST_BIT        ,
			UniformTexelBuffer  = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT,
			StorageTexelBuffer  = VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT,
			UniformBuffer       = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT      ,
			StorageBuffer       = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT      ,
			IndexBuffer         = VK_BUFFER_USAGE_INDEX_BUFFER_BIT        ,
			VertexBuffer        = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT       ,
			IndirectBuffer      = VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT     
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkColorComponentFlagBits">Specification</a>  */
		enum class EColorComponentFlag : uint32
		{
			R = VK_COLOR_COMPONENT_R_BIT,
			G = VK_COLOR_COMPONENT_G_BIT,
			B = VK_COLOR_COMPONENT_B_BIT,
			A = VK_COLOR_COMPONENT_A_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkColorSpaceKHR">Specification</a>  */
		enum class EColorSpace : uint32
		{
			SRGB_NonLinear                   = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR         ,
			NonLinear_Display_P3             = VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT   ,
			ExtendedSRGB_Linear              = VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT   ,
			Display_P3_LInear                = VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT      ,
			DCI_P3_NonLinear                 = VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT       ,
			BT709_Linear                     = VK_COLOR_SPACE_BT709_LINEAR_EXT           ,
			BT709_NonLinear                  = VK_COLOR_SPACE_BT709_NONLINEAR_EXT        ,
			BT2020_Linear                    = VK_COLOR_SPACE_BT2020_LINEAR_EXT          ,
			Extensions_HDR_ST2084            = VK_COLOR_SPACE_HDR10_ST2084_EXT           ,
			Extension_DoblyVision            = VK_COLOR_SPACE_DOLBYVISION_EXT            ,
			HDR10_HLG                        = VK_COLOR_SPACE_HDR10_HLG_EXT              ,
			AdobeRGB_Linear                  = VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT        ,
			AdobeRGB_NonLinear               = VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT     ,
			Extension_PassThrough            = VK_COLOR_SPACE_PASS_THROUGH_EXT           ,
			Extension_ExtendedSRGB_NonLinear = VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT,
			AMD_Native                       = VK_COLOR_SPACE_DISPLAY_NATIVE_AMD         ,
			KHR_SRGB_NonLinear               = VK_COLORSPACE_SRGB_NONLINEAR_KHR          ,
			Extension_DCI_P3_Linear          = VK_COLOR_SPACE_DCI_P3_LINEAR_EXT          ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferLevel">Specification</a>  */
		enum class ECommandBufferLevel
		{
			Primary   = VK_COMMAND_BUFFER_LEVEL_PRIMARY  ,
			Secondary = VK_COMMAND_BUFFER_LEVEL_SECONDARY 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlagBits ">Specification</a>  */
		enum class ECommandBufferResetFlag : uInt32
		{
			ReleaseResources = VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlagBits">Specification</a>  */
		enum class ECommandBufferUsageFlag : uint32
		{
			OneTimeSubmit      = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT     ,
			RenderPassContinue = VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT,
			SimultaneousUse    = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT  
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateFlagBits">Specification</a>  */
		enum class ECommandPoolCreateFlag : uint32
		{
			Transient          = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT           ,
			ResetCommandBuffer = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			Protected          = VK_COMMAND_POOL_CREATE_PROTECTED_BIT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolResetFlagBits">Specification</a>  */
		enum class ECommandPoolResetFlags : uInt32
		{
			ReleaseResources = VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkComponentSwizzle">Specification</a>  */
		enum class EComponentSwizzle : uint32
		{
			Identitity = VK_COMPONENT_SWIZZLE_IDENTITY,
			Zero       = VK_COMPONENT_SWIZZLE_ZERO    ,
			One        = VK_COMPONENT_SWIZZLE_ONE     ,
			R          = VK_COMPONENT_SWIZZLE_R       ,
			G          = VK_COMPONENT_SWIZZLE_G       ,
			B          = VK_COMPONENT_SWIZZLE_B       ,
			A          = VK_COMPONENT_SWIZZLE_A
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompositeAlphaFlagBitsKHR">Specification</a>  */
		enum class ECompositeAlpha : uint32
		{
			Opaque         = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR          ,
			PreMultiplied  = VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR  ,
			PostMultiplied = VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR ,
			Inherit        = VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompareOp">Specification</a>  */
		enum class ECompareOperation : uint32
		{
			Never          = VK_COMPARE_OP_NEVER           ,
			Less           = VK_COMPARE_OP_LESS            ,
			Equal          = VK_COMPARE_OP_EQUAL           ,
			LessOrEqual    = VK_COMPARE_OP_LESS_OR_EQUAL   ,
			Greater        = VK_COMPARE_OP_GREATER         ,
			NotEqual       = VK_COMPARE_OP_NOT_EQUAL       ,
			GreaterOrEqual = VK_COMPARE_OP_GREATER_OR_EQUAL,
			Always         = VK_COMPARE_OP_ALWAYS
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCullModeFlagBits">Specification</a>  */
		enum class ECullModeFlag : uint32
		{
			None           = VK_CULL_MODE_NONE          ,
			Front          = VK_CULL_MODE_FRONT_BIT     ,
			Back           = VK_CULL_MODE_BACK_BIT      ,
			Front_And_Back = VK_CULL_MODE_FRONT_AND_BACK 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageSeverityFlagBitsEXT">Specification</a>  */
		enum class EDebugUtilities_MessageSeverity : uint32
		{
			Verbose = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
			Info    = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT   ,
			Warning = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT,
			Error   = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageTypeFlagBitsEXT">Specification</a> */
		enum class EDebugUtilities_MessageType : uint32
		{
			General     = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT    ,
			Validation  = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT ,
			Performance = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDependencyFlagBits">Specification</a>  */
		enum class EDependencyFlag : uint32
		{
			ByRegion = VK_DEPENDENCY_BY_REGION_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBindingFlagBits">Specification</a>  */
		enum class EDescriptorBindingFlag : uint32
		{
			UpdateAfterBind              = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT              ,
			UpdateUnusedWhilePending     = VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT    ,
			PartiallyBound               = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT                ,
			VariableDescriptorCount      = VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT      ,
			UpdateAfterBind_EXT          = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT_EXT          ,
			UpdateUnusedWhilePending_EXT = VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT_EXT,
			PartiallyBound_EXT           = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT_EXT            ,
			VariableDescriptorCount_EXT  = VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateFlagBits">Specification</a>  */
		enum class EDescriptorPoolCreateFlag : uint32
		{
			FreeDescriptorSet   = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT  ,
			UpdateAfterBind     = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT    ,
			UpdateAfterBind_EXT = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutCreateFlagBits">Specification</a>  */
		enum class EDescriptorSetLayoutCreateFlag : uint32
		{
			UpdateAfterBindPool           = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT    ,
			PushDescriptor                = VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR       ,
			UpdateAfterBindPool_Extension = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorType">Specification</a>  */
		enum class EDescriptorType : uint32
		{
			Sampler                      = VK_DESCRIPTOR_TYPE_SAMPLER                   ,
			CombinedImageSampler         = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER    ,
			SampledImage                 = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE             ,
			StorageImage                 = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE             ,
			UniformTexelBuffer           = VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER      ,
			StorageTexelBuffer           = VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER      ,
			UniformBuffer                = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER            ,
			StorageBuffer                = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER            ,
			UniformBufferDynamic         = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC    ,
			StorageBufferDynamic         = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC    ,
			InputAttachment              = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT          ,
			InlineUniformBlock_Extension = VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT  ,
			AccelerationStructure_KHR    = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR,
			AccelerationStructure_NV     = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigFlagBitsNV">Specification</a>  */
		enum class EDeviceDiagnosticConfigFlag : uint32
		{
			EnableShaderDebugInfo      = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV    , 
			EnableResourceTracking     = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV    , 
			EnableAutomaticCheckpoints = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlagBits">Specification</a>  */
		enum class EDeviceQueueCreateFlag : uint32
		{
			// Provided by VK_VERSION_1_1
			Protected = VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceEventTypeEXT">Specification</a>  */
		enum class EDeviceEventType : uint32
		{
			DisplayHotPlug_ = VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDisplayEventTypeEXT">Specification</a>  */
		enum class EDisplayEventType : uint32
		{
			FirstPixelOut_EXT = VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT
		};

		/**
		* @details
		* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDriverId">Specification</a> 
		*/
		enum class EDriverID
		{
			Proprietary             = VK_DRIVER_ID_AMD_PROPRIETARY          ,
			OpenSource              = VK_DRIVER_ID_AMD_OPEN_SOURCE          ,
			Mesa_RADV               = VK_DRIVER_ID_MESA_RADV                ,
			NvidiaProprietary       = VK_DRIVER_ID_NVIDIA_PROPRIETARY       ,
			IntelProprietaryWindows = VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS,
			IntelOpenSourceMesa     = VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA   ,
			ImaginationProprietary  = VK_DRIVER_ID_IMAGINATION_PROPRIETARY  ,
			QualcommProprietary     = VK_DRIVER_ID_QUALCOMM_PROPRIETARY     ,
			ARM_Proprietary         = VK_DRIVER_ID_ARM_PROPRIETARY          ,
			GoogleSwiftShader       = VK_DRIVER_ID_GOOGLE_SWIFTSHADER       ,
			GGP_Proprietary         = VK_DRIVER_ID_GGP_PROPRIETARY          ,
			BroadcomProprietary     = VK_DRIVER_ID_BROADCOM_PROPRIETARY     ,
			MESA_LLLVM_Pipe         = VK_DRIVER_ID_MESA_LLVMPIPE            ,
			//MoltenVK                = VK_DRIVER_ID_MOLTENVK                 ,

			// Provided by VK_KHR_driver_properties
			AMD_Proprietary_KHR         = VK_DRIVER_ID_AMD_PROPRIETARY_KHR          ,
			AMD_OpenSource_KHR          = VK_DRIVER_ID_AMD_OPEN_SOURCE_KHR          ,
			Mesa_RADV_KHR               = VK_DRIVER_ID_MESA_RADV_KHR                ,
			NvidiaProprietary_KHR       = VK_DRIVER_ID_NVIDIA_PROPRIETARY_KHR       ,
			IntelProprietaryWindows_KHR = VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS_KHR,
			IntelOpenSourceMesa_KHR     = VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA_KHR   ,
			Imagination_Proprietary_KHR = VK_DRIVER_ID_IMAGINATION_PROPRIETARY_KHR  ,
			QualCommProprietary_KHR     = VK_DRIVER_ID_QUALCOMM_PROPRIETARY_KHR     ,
			ARM_Proprietary_KHR         = VK_DRIVER_ID_ARM_PROPRIETARY_KHR          ,
			GoogleSwiftShader_KHR       = VK_DRIVER_ID_GOOGLE_SWIFTSHADER_KHR       ,
			GGP_Proprietary_KHR         = VK_DRIVER_ID_GGP_PROPRIETARY_KHR          ,
			BroadcomProprietary_KHR     = VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR     ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDynamicState">Specification</a>  */
		enum class EDynamicState : uint32
		{
			Viewport                      = VK_DYNAMIC_STATE_VIEWPORT                        ,
			Scissor                       = VK_DYNAMIC_STATE_SCISSOR                         ,
			LineWidth                     = VK_DYNAMIC_STATE_LINE_WIDTH                      ,
			DepthBias                     = VK_DYNAMIC_STATE_DEPTH_BIAS                      ,
			BlendConstants                = VK_DYNAMIC_STATE_BLEND_CONSTANTS                 ,
			DepthBounds                   = VK_DYNAMIC_STATE_DEPTH_BOUNDS                    ,
			StencilCompareMask            = VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK            ,
			StencilWriteMask              = VK_DYNAMIC_STATE_STENCIL_WRITE_MASK              ,
			StencilReference              = VK_DYNAMIC_STATE_STENCIL_REFERENCE               ,
			Viewport_W_Scaling_NV         = VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV           ,
			DiscardRectangle_Extension    = VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT           ,
			SampleLocations_Extension     = VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT            ,
			ViewportShadingRatePalette_NV = VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV,
			ViewportCoarseSampleOrder_NV  = VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV ,
			ExclusiveScissor_NV           = VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV            ,
			LineStipple_Extension         = VK_DYNAMIC_STATE_LINE_STIPPLE_EXT                
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalFenceHandleTypeFlagBits">Specification</a>  */
		enum class EExternalFenceHandleTypeFlag : uint32
		{
			OpaqueFD             = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT           ,
			Opaque_Win32         = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT        ,
			Opaque_Win32_KMT     = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT    ,
			SyncFD               = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT             ,
			OpaqueFD_KHR         = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR       ,   // Provided by VK_KHR_external_fence_capabilities
			Opaque_Win32_KHR     = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR    ,   // Provided by VK_KHR_external_fence_capabilities
			Opaque_Win32_KMT_KHR = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR,   // Provided by VK_KHR_external_fence_capabilities
			SyncFD_KHR           = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR         ,   // Provided by VK_KHR_external_fence_capabilities
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalSemaphoreHandleTypeFlagBits">Specification</a>  */
		enum class EExternalSemaphoreHandleTypeFlag : uint32
		{
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT = 0x00000001,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT = 0x00000002,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT = 0x00000004,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT = 0x00000008,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT = 0x00000010,
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT,
			// Provided by VK_KHR_external_semaphore_capabilities
			VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateFlagBits">Specification</a>  */
		enum class EFenceCreateFlag : uint32
		{
			Signaled = VK_FENCE_CREATE_SIGNALED_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceImportFlagBits">Specification</a>  */
		enum class EFenceImportFlag
		{
			Temporary     = VK_FENCE_IMPORT_TEMPORARY_BIT    ,   // Provided by VK_KHR_external_fence
			Temporary_KHR = VK_FENCE_IMPORT_TEMPORARY_BIT_KHR,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFilter">Specification</a>  */
		enum class EFilter : uint32
		{
			Nearest   = VK_FILTER_NEAREST  ,
			Linear    = VK_FILTER_LINEAR   ,
			Cubic     = VK_FILTER_CUBIC_IMG,
			Cubic_EXT = VK_FILTER_CUBIC_EXT 
		};

		/**
		 * @brief Supported buffer and image formats.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html#formats">Specification</a> 
		 */
		enum class EFormat : uint32
		{
			Undefined                                            = VK_FORMAT_UNDEFINED                                     ,
			R4_G4_UNormalized_8Pack                              = VK_FORMAT_R4G4_UNORM_PACK8                              ,
			R4_G4_B4_A4_UNormalized_16Pack                       = VK_FORMAT_R4G4B4A4_UNORM_PACK16                         ,
			B4_G4_R4_A4_UNormalized_16Pack                       = VK_FORMAT_B4G4R4A4_UNORM_PACK16                         ,
			R5_G6_B5_UNormalized_16Pack                          = VK_FORMAT_R5G6B5_UNORM_PACK16                           ,
			B5_G6_R5_UNormalized_16Pack                          = VK_FORMAT_B5G6R5_UNORM_PACK16                           ,
			R5_G5_B5_1A_UNormalized_16Pack                       = VK_FORMAT_R5G5B5A1_UNORM_PACK16                         ,
			B5_G5_R5_A1_UNormalized_16Pack                       = VK_FORMAT_B5G5R5A1_UNORM_PACK16                         ,
			A1_R5_G5_B5_UNormalized_16Pack                       = VK_FORMAT_A1R5G5B5_UNORM_PACK16                         ,
			R8_UNormalized                                       = VK_FORMAT_R8_UNORM                                      ,
			R8_SNormalized                                       = VK_FORMAT_R8_SNORM                                      ,
			R8_UScaled                                           = VK_FORMAT_R8_USCALED                                    ,
			R8_SScaled                                           = VK_FORMAT_R8_SSCALED                                    ,
			R8_UInt                                              = VK_FORMAT_R8_UINT                                       ,
			R8_SInt                                              = VK_FORMAT_R8_SINT                                       ,
			R8_SRGB                                              = VK_FORMAT_R8_SRGB                                       ,
			R8_G8_UNormalized                                    = VK_FORMAT_R8G8_UNORM                                    ,
			R8_G8_SNormalized                                    = VK_FORMAT_R8G8_SNORM                                    ,
			R8_G8_UScaled                                        = VK_FORMAT_R8G8_USCALED                                  ,
			R8_G8_SScaled                                        = VK_FORMAT_R8G8_SSCALED                                  ,
			R8_G8_UInt                                           = VK_FORMAT_R8G8_UINT                                     ,
			R8_G8_SInt                                           = VK_FORMAT_R8G8_SINT                                     ,
			R8_G8_SRGB                                           = VK_FORMAT_R8G8_SRGB                                     ,
			R8_G8_B8_UNormalized                                 = VK_FORMAT_R8G8B8_UNORM                                  ,
			R8_G8_B8_SNormalized                                 = VK_FORMAT_R8G8B8_SNORM                                  ,
			R8_G8_B8_UScaled                                     = VK_FORMAT_R8G8B8_USCALED                                ,
			R8_G8_B8_SScaled                                     = VK_FORMAT_R8G8B8_SSCALED                                ,
			R8_G8_B8_UInt                                        = VK_FORMAT_R8G8B8_UINT                                   ,
			R8_G8_B8_SInt                                        = VK_FORMAT_R8G8B8_SINT                                   ,
			R8_G8_B8_SRGB                                        = VK_FORMAT_R8G8B8_SRGB                                   ,
			B8_G8_R8_UNormalized                                 = VK_FORMAT_B8G8R8_UNORM                                  ,
			B8_G8_R8_SNormalized                                 = VK_FORMAT_B8G8R8_SNORM                                  ,
			B8_G8_R8_UScaled                                     = VK_FORMAT_B8G8R8_USCALED                                ,
			B8_G8_R8_SScaled                                     = VK_FORMAT_B8G8R8_SSCALED                                ,
			B8_G8_R8_UInt                                        = VK_FORMAT_B8G8R8_UINT                                   ,
			B8_G8_R8_SInt                                        = VK_FORMAT_B8G8R8_SINT                                   ,
			B8_G8_R8_SRGB                                        = VK_FORMAT_B8G8R8_SRGB                                   ,
			R8_G8_B8_A8_UNormalized                              = VK_FORMAT_R8G8B8A8_UNORM                                ,
			R8_G8_B8_A8_SNormalized                              = VK_FORMAT_R8G8B8A8_SNORM                                ,
			R8_G8_B8_A8_UScaled                                  = VK_FORMAT_R8G8B8A8_USCALED                              ,
			R8_G8_B8_A8_SScaled                                  = VK_FORMAT_R8G8B8A8_SSCALED                              ,
			R8_G8_B8_A8_UInt                                     = VK_FORMAT_R8G8B8A8_UINT                                 ,
			R8_G8_B8_A8_SInt                                     = VK_FORMAT_R8G8B8A8_SINT                                 ,
			R8_G8_B8_A8_SRGB                                     = VK_FORMAT_R8G8B8A8_SRGB                                 ,
			B8_G8_R8_A8_UNormalized                              = VK_FORMAT_B8G8R8A8_UNORM                                ,
			B8_G8_R8_A8_SNormalized                              = VK_FORMAT_B8G8R8A8_SNORM                                ,
			B8_G8_R8_A8_UScaled                                  = VK_FORMAT_B8G8R8A8_USCALED                              ,
			B8_G8_R8_A8_SScaled                                  = VK_FORMAT_B8G8R8A8_SSCALED                              ,
			B8_G8_R8_A8_Uint                                     = VK_FORMAT_B8G8R8A8_UINT                                 ,
			B8_G8_R8_A8_SInt                                     = VK_FORMAT_B8G8R8A8_SINT                                 ,
			B8_G8_R8_A8_SRGB                                     = VK_FORMAT_B8G8R8A8_SRGB                                 ,
			A8_B8_G8_R8_UNormalized_Pack32                       = VK_FORMAT_A8B8G8R8_UNORM_PACK32                         ,
			A8_B8_G8_R8_SNormalized_Pack32                       = VK_FORMAT_A8B8G8R8_SNORM_PACK32                         ,
			A8_B8_G8_R8_UScaled_Pack32                           = VK_FORMAT_A8B8G8R8_USCALED_PACK32                       ,
			A8_B8_G8_R8_SScaled_Pack32                           = VK_FORMAT_A8B8G8R8_SSCALED_PACK32                       ,
			A8_B8_G8_R8_UInt_Pack32                              = VK_FORMAT_A8B8G8R8_UINT_PACK32                          ,
			A8_B8_G8_R8_SInt_Pack32                              = VK_FORMAT_A8B8G8R8_SINT_PACK32                          ,
			A8_B8_G8_R8_SRGB_Pack32                              = VK_FORMAT_A8B8G8R8_SRGB_PACK32                          ,
			A2_R10_G10_B10_UNormalized_Pack32                    = VK_FORMAT_A2R10G10B10_UNORM_PACK32                      ,
			A2_R10_G10_B10_SNormalized_Pack32                    = VK_FORMAT_A2R10G10B10_SNORM_PACK32                      ,
			A2_R10_G10_B10_UScaled_Pack32                        = VK_FORMAT_A2R10G10B10_USCALED_PACK32                    ,
			A2_R10_G10_B10_SScaled_Pack32                        = VK_FORMAT_A2R10G10B10_SSCALED_PACK32                    ,
			A2_R10_G10_B10_UInt_Pack32                           = VK_FORMAT_A2R10G10B10_UINT_PACK32                       ,
			A2_R10_G10_B10_SInt_Pack32                           = VK_FORMAT_A2R10G10B10_SINT_PACK32                       ,
			A2_B10_G10_R10_UNormalized_Pack32                    = VK_FORMAT_A2B10G10R10_UNORM_PACK32                      ,
			A2_B10_G10_R10_SNormalized_Pack32                    = VK_FORMAT_A2B10G10R10_SNORM_PACK32                      ,
			A2_B10_G10_R10_UScaled_Pack32                        = VK_FORMAT_A2B10G10R10_USCALED_PACK32                    ,
			A2_B10_G10_R10_SScaled_Pack32                        = VK_FORMAT_A2B10G10R10_SSCALED_PACK32                    ,
			A2_B10_G10_R10_UInt_Pack32                           = VK_FORMAT_A2B10G10R10_UINT_PACK32                       ,
			A2_B10_G10_R10_SInt_Pack32                           = VK_FORMAT_A2B10G10R10_SINT_PACK32                       ,
			R16_UNormalized                                      = VK_FORMAT_R16_UNORM                                     ,
			R16_SNormalized                                      = VK_FORMAT_R16_SNORM                                     ,
			R16_UScaled                                          = VK_FORMAT_R16_USCALED                                   ,
			R16_SScaled                                          = VK_FORMAT_R16_SSCALED                                   ,
			R16_UInt                                             = VK_FORMAT_R16_UINT                                      ,
			R16_SInt                                             = VK_FORMAT_R16_SINT                                      ,
			R16_SFloat                                           = VK_FORMAT_R16_SFLOAT                                    ,
			R16_G16_UNormalized                                  = VK_FORMAT_R16G16_UNORM                                  ,
			R16_G16_SNormalized                                  = VK_FORMAT_R16G16_SNORM                                  ,
			R16_G16_UScaled                                      = VK_FORMAT_R16G16_USCALED                                ,
			R16_G16_SScaled                                      = VK_FORMAT_R16G16_SSCALED                                ,
			R16_G16_UInt                                         = VK_FORMAT_R16G16_UINT                                   ,
			R16_G16_SInt                                         = VK_FORMAT_R16G16_SINT                                   ,
			R16_G16_SFloat                                       = VK_FORMAT_R16G16_SFLOAT                                 ,
			R16_G16_B16_UNormalized                              = VK_FORMAT_R16G16B16_UNORM                               ,
			R16_G16_B16_SNormalized                              = VK_FORMAT_R16G16B16_SNORM                               ,
			R16_G16_B16_UScaled                                  = VK_FORMAT_R16G16B16_USCALED                             ,
			R16_G16_B16_SScaled                                  = VK_FORMAT_R16G16B16_SSCALED                             ,
			R16_G16_B16_UInt                                     = VK_FORMAT_R16G16B16_UINT                                ,
			R16_G16_B16_SInt                                     = VK_FORMAT_R16G16B16_SINT                                ,
			R16_G16_B16_SFloat                                   = VK_FORMAT_R16G16B16_SFLOAT                              ,
			R16_G16_B16_A16_UNormalized                          = VK_FORMAT_R16G16B16A16_UNORM                            ,
			R16_G16_B16_A16_SNormalized                          = VK_FORMAT_R16G16B16A16_SNORM                            ,
			R16_G16_B16_A16_UScaled                              = VK_FORMAT_R16G16B16A16_USCALED                          ,
			R16_G16_B16_A16_SScaled                              = VK_FORMAT_R16G16B16A16_SSCALED                          ,
			R16_G16_B16_A16_UInt                                 = VK_FORMAT_R16G16B16A16_UINT                             ,
			R16_G16_B16_A16_SInt                                 = VK_FORMAT_R16G16B16A16_SINT                             ,
			R16_G16_B16_A16_SFloat                               = VK_FORMAT_R16G16B16A16_SFLOAT                           ,
			R32_UInt                                             = VK_FORMAT_R32_UINT                                      ,
			R32_SInt                                             = VK_FORMAT_R32_SINT                                      ,
			R32_SFloat                                           = VK_FORMAT_R32_SFLOAT                                    ,
			R32_G32_UInt                                         = VK_FORMAT_R32G32_UINT                                   ,
			R32_G32_SInt                                         = VK_FORMAT_R32G32_SINT                                   ,
			R32_G32_SFloat                                       = VK_FORMAT_R32G32_SFLOAT                                 ,
			R32_G32_B32_UInt                                     = VK_FORMAT_R32G32B32_UINT                                ,
			R32_G32_B32_Sint                                     = VK_FORMAT_R32G32B32_SINT                                ,
			R32_G32_B32_SFloat                                   = VK_FORMAT_R32G32B32_SFLOAT                              ,
			R32_G32_B32_A32_UInt                                 = VK_FORMAT_R32G32B32A32_UINT                             ,
			R32_G32_B32_A32_SInt                                 = VK_FORMAT_R32G32B32A32_SINT                             ,
			R32_G32_B32_A32_SFloat                               = VK_FORMAT_R32G32B32A32_SFLOAT                           ,
			R64_Uint                                             = VK_FORMAT_R64_UINT                                      ,
			R64_SInt                                             = VK_FORMAT_R64_SINT                                      ,
			R64_SFloat                                           = VK_FORMAT_R64_SFLOAT                                    ,
			R64_G64_UInt                                         = VK_FORMAT_R64G64_UINT                                   ,
			R64_G64_SInt                                         = VK_FORMAT_R64G64_SINT                                   ,
			R64_G64_SFloat                                       = VK_FORMAT_R64G64_SFLOAT                                 ,
			R64_G64_B64_UInt                                     = VK_FORMAT_R64G64B64_UINT                                ,
			R64_G64_B64_SInt                                     = VK_FORMAT_R64G64B64_SINT                                ,
			R64_G64_B64_SFloat                                   = VK_FORMAT_R64G64B64_SFLOAT                              ,
			R64_G64_B64_A64_UInt                                 = VK_FORMAT_R64G64B64A64_UINT                             ,
			R64_G64_B64_A64_SInt                                 = VK_FORMAT_R64G64B64A64_SINT                             ,
			R64_G64_B64_A64_SFloat                               = VK_FORMAT_R64G64B64A64_SFLOAT                           ,
			B10_G11_R11_UFloat_Pack32                            = VK_FORMAT_B10G11R11_UFLOAT_PACK32                       ,
			E5_B9_G9_R9_UFloat_Pack32                            = VK_FORMAT_E5B9G9R9_UFLOAT_PACK32                        ,
			D16_UNormalized                                      = VK_FORMAT_D16_UNORM                                     ,
			X8_D24_UNormalized_Pack32                            = VK_FORMAT_X8_D24_UNORM_PACK32                           ,
			D32_SFloat                                           = VK_FORMAT_D32_SFLOAT                                    ,
			S8_UInt                                              = VK_FORMAT_S8_UINT                                       ,
			D16_UNormalized_S8_UInt                              = VK_FORMAT_D16_UNORM_S8_UINT                             ,
			D24_UNormalized_S8_UInt                              = VK_FORMAT_D24_UNORM_S8_UINT                             ,
			D32_SFloat_S8_UInt                                   = VK_FORMAT_D32_SFLOAT_S8_UINT                            ,
			BC1_RGB_UNormalized_Block                            = VK_FORMAT_BC1_RGB_UNORM_BLOCK                           ,
			BC1_RGB_SRGB_Block                                   = VK_FORMAT_BC1_RGB_SRGB_BLOCK                            ,
			BC1_RGBA_Unormalized_Block                           = VK_FORMAT_BC1_RGBA_UNORM_BLOCK                          ,
			BC1_RGBA_SRGB_Block                                  = VK_FORMAT_BC1_RGBA_SRGB_BLOCK                           ,
			BC2_UNormalized_Block                                = VK_FORMAT_BC2_UNORM_BLOCK                               ,
			BC2_SRGB_Block                                       = VK_FORMAT_BC2_SRGB_BLOCK                                ,
			BC3_UNormalized_Block                                = VK_FORMAT_BC3_UNORM_BLOCK                               ,
			BC3_SRGB_Block                                       = VK_FORMAT_BC3_SRGB_BLOCK                                ,
			BC4_UNormalized_Block                                = VK_FORMAT_BC4_UNORM_BLOCK                               ,
			BC4_SNormalized_Block                                = VK_FORMAT_BC4_SNORM_BLOCK                               ,
			BC5_UNormalized_Block                                = VK_FORMAT_BC5_UNORM_BLOCK                               ,
			BC5_SNormalized_Block                                = VK_FORMAT_BC5_SNORM_BLOCK                               ,
			BC6H_UFloat_Block                                    = VK_FORMAT_BC6H_UFLOAT_BLOCK                             ,
			BC6H_SFloat_Block                                    = VK_FORMAT_BC6H_SFLOAT_BLOCK                             ,
			BC7_UNormalized_Block                                = VK_FORMAT_BC7_UNORM_BLOCK                               ,
			BC7_SRGB_Block                                       = VK_FORMAT_BC7_SRGB_BLOCK                                ,
			ETC2_R8_G8_B8_UNormalized_Block                      = VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK                       ,
			ETC2_R8_G8_B8_SRGB_Block                             = VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK                        ,
			ETC2_R8_G8_B8_A1_UNormalized_Block                   = VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK                     ,
			ETC2_R8_G8_B8_A1_Block                               = VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK                      ,
			ETC_2_R8_G8_B8_A8_UNormalized_Block                  = VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK                     ,
			ETC2_R8_G8_B8_A8_SRGB_Block                          = VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK                      ,
			EAC_R11_UNormalized_Block                            = VK_FORMAT_EAC_R11_UNORM_BLOCK                           ,
			EAC_R11_SNormalized_Block                            = VK_FORMAT_EAC_R11_SNORM_BLOCK                           ,
			EAC_R11_G11_UNormalized_Block                        = VK_FORMAT_EAC_R11G11_UNORM_BLOCK                        ,
			EAC_R11_G11_SNormalized_Block                        = VK_FORMAT_EAC_R11G11_SNORM_BLOCK                        ,
			ASTC_4x4_UNormalized_Block                           = VK_FORMAT_ASTC_4x4_UNORM_BLOCK                          ,
			ASTC_4x4_SRGB_Block                                  = VK_FORMAT_ASTC_4x4_SRGB_BLOCK                           ,
			ASTC_5x4_UNormalized_Block                           = VK_FORMAT_ASTC_5x4_UNORM_BLOCK                          ,
			ASTC_5x4_SRGB_Block                                  = VK_FORMAT_ASTC_5x4_SRGB_BLOCK                           ,
			ASTC_5x5_UNormalized_Block                           = VK_FORMAT_ASTC_5x5_UNORM_BLOCK                          ,
			ASTC_5x5_SRGB_Block                                  = VK_FORMAT_ASTC_5x5_SRGB_BLOCK                           ,
			ASTC_6x5_UNormalized_Block                           = VK_FORMAT_ASTC_6x5_UNORM_BLOCK                          ,
			ASTC_6x5_SRGB_Block                                  = VK_FORMAT_ASTC_6x5_SRGB_BLOCK                           ,
			ASTC_6x6_UNormalized_Block                           = VK_FORMAT_ASTC_6x6_UNORM_BLOCK                          ,
			ASTC_6x6_SRGB_Block                                  = VK_FORMAT_ASTC_6x6_SRGB_BLOCK                           ,
			ASTC_8x5_UNormalized_Block                           = VK_FORMAT_ASTC_8x5_UNORM_BLOCK                          ,
			ASTC_8x5_SRGB_Block                                  = VK_FORMAT_ASTC_8x5_SRGB_BLOCK                           ,
			ASTC_8x6_UNormalized_Block                           = VK_FORMAT_ASTC_8x6_UNORM_BLOCK                          ,
			ASTC_8x6_SRGB_Block                                  = VK_FORMAT_ASTC_8x6_SRGB_BLOCK                           ,
			ASTC_8x8_UNormalized_Block                           = VK_FORMAT_ASTC_8x8_UNORM_BLOCK                          ,
			ASTC_8x8_SRGB_Block                                  = VK_FORMAT_ASTC_8x8_SRGB_BLOCK                           ,
			ASTC_10x5_UNormalized_Block                          = VK_FORMAT_ASTC_10x5_UNORM_BLOCK                         ,
			ASTC_10x5_SRGB_Block                                 = VK_FORMAT_ASTC_10x5_SRGB_BLOCK                          ,
			ASTC_10x6_UNormalized_Block                          = VK_FORMAT_ASTC_10x6_UNORM_BLOCK                         ,
			ASTC_10x6_SRGB_Block                                 = VK_FORMAT_ASTC_10x6_SRGB_BLOCK                          ,
			ASTC_10x8_UNormalized_Block                          = VK_FORMAT_ASTC_10x8_UNORM_BLOCK                         ,
			ASTC_10x8_SRGB_Block                                 = VK_FORMAT_ASTC_10x8_SRGB_BLOCK                          ,
			ASTC_10x10_UNormalized_Block                         = VK_FORMAT_ASTC_10x10_UNORM_BLOCK                        ,
			ASTC_10x10_SRGB_Block                                = VK_FORMAT_ASTC_10x10_SRGB_BLOCK                         ,
			ASTC_12x10_UNormalized_Block                         = VK_FORMAT_ASTC_12x10_UNORM_BLOCK                        ,
			ASTC_12x10_SRGB_Block                                = VK_FORMAT_ASTC_12x10_SRGB_BLOCK                         ,
			ASTC_12x12_UNormalize_Block                          = VK_FORMAT_ASTC_12x12_UNORM_BLOCK                        ,
			ASTC_12x12_SRGB_Block                                = VK_FORMAT_ASTC_12x12_SRGB_BLOCK                         ,
			G8_B8_G8_R8_422_UNormalized                          = VK_FORMAT_G8B8G8R8_422_UNORM                            ,
			B8_G8_R8_G8_422_UNormalized                          = VK_FORMAT_B8G8R8G8_422_UNORM                            ,
			G8_B8_R8_3Plane_420_UNormalized                      = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM                     ,
			G8_B8_R8_2Plane_420_UNormalized                      = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM                      ,
			G8_B8_R8_3Plane_422_UNormalized                      = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM                     ,
			G8_B8_R8_2Plane_422_UNormalized                      = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM                      ,
			G8_B8_R8_3Plane_444_UNormalized                      = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM                     ,
			R10x6_UNormalized_Pack16                             = VK_FORMAT_R10X6_UNORM_PACK16                            ,
			R10x6_G10x6_UNormalized_2Pack16                      = VK_FORMAT_R10X6G10X6_UNORM_2PACK16                      ,
			R10x6_G10x6_B10x6_A10x6_UNormalized_4Pack16          = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16            ,
			G10x6_B10x6_G10x6_R10x6_422_UNormalized_4Pack16      = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16        ,
			B10x6_G10x6_R10x6_G10x6_422_UNormalized_4Pack16      = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16        ,
			G10x6_B10x6_R10x6_3Plane_420_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16    ,
			G10x6_B10x6_R10x6_2Plane_420_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16     ,
			G10x6_B10x6_R10x6_3Plane_422_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16    ,
			G10x6_B10x6_R10x6_2Plane_422_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16     ,
			G10x6_B10x6_R10x6_3Plane_444_UNormalized_3Pack16     = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16    ,
			R12x4_UNormalized_Pack16                             = VK_FORMAT_R12X4_UNORM_PACK16                            ,
			R12x4_G12x4_UNormalized_2Pack16                      = VK_FORMAT_R12X4G12X4_UNORM_2PACK16                      ,
			R12x4_G12x4_B12x4_A12x4_UNormalized_4Pack16          = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16            ,
			G12x4_B12x4_G12x4_R12x4_422_UNormalized_4Pack16      = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16        ,
			B12x4_G12x4_R12x4_G12x4_422_UNormalized_4Pack16      = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16        ,
			G12x4_B12x4_R12x4_3Plane_420_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16    ,
			G12x4_B12x4_R12x4_2Plane_420_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16     ,
			G12x4_B12x4_R12x4_3Plane_422_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16    ,
			G12x4_B12x4_R12x4_2Plane_422_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16     ,
			G12x4_B12x4_R12x4_3Plane_444_UNormalized_3Pack16     = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16    ,
			G16_B16_G16_R16_422_UNormalized                      = VK_FORMAT_G16B16G16R16_422_UNORM                        ,
			B16_G16_R16_G16_422_UNormalized                      = VK_FORMAT_B16G16R16G16_422_UNORM                        ,
			G16_B16_R16_3Plane_420_UNormalized                   = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM                  ,
			G16_B16_R16_2Plane_420_UNormalized                   = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM                   ,
			G16_B16_3Plane_422_UNormalized                       = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM                  ,
			G16_B16_R16_2Plane_422_UNormalized                   = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM                   ,
			G16_B16_R16_3Plane_444_UNormalized                   = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM                  ,
			PVRTC1_2BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG                   ,
			PVRTC1_4BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG                   ,
			PVRTC2_2BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG                   ,
			PVRTC2_4BPP_UNormalized_Block_Image                  = VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG                   ,
			PVRTC1_2BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG                    ,
			PVRTC1_4BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG                    ,
			PVRTC2_2BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG                    ,
			PVRTC2_4BPP_SRGB_Block_Image                         = VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG                    ,
			ASTC_4x4_SFloat_Block_EXT                            = VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT                     ,
			ASTC_5x4_SFloat_Block_EXT                            = VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT                     ,
			ASTC_5x5_SFloat_Block_EXT                            = VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT                     ,
			ASTC_6x5_SFloat_Block_EXT                            = VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT                     ,
			ASTC_6x6_SFloat_Block_EXT                            = VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT                     ,
			ASTC_8x5_SFloat_Block_EXT                            = VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT                     ,
			ASTC_8x6_SFloat_Block_EXT                            = VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT                     ,
			ASTC_8x8_SFloat_Block_EXT                            = VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT                     ,
			ASTC_10x5_SFloat_Block_EXT                           = VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT                    ,
			ASTC_10x6_SFloat_Block_EXT                           = VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT                    ,
			ASTC_10x8_SFloat_Block_EXT                           = VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT                    ,
			ASTC_10x10_SFloat_Block_EXT                          = VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT                   ,
			ASTC_12x10_SFloat_Block_EXT                          = VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT                   ,
			ASTC_12x12_SFloat_Block_EXT                          = VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT                   ,
			G8_B8_G8_R8_422_UNormalized_KHR                      = VK_FORMAT_G8B8G8R8_422_UNORM_KHR                        ,
			B8_G8_R8_G8_422_UNormalized_KHR                      = VK_FORMAT_B8G8R8G8_422_UNORM_KHR                        ,
			G8_B8_R8_3Plane_420_UNormalized_KHR                  = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR                 ,
			G8_B8_R8_2Plane_420_UNormalized_KHR                  = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR                  ,
			G8_B8_R8_3Plane_422_UNormalized_KHR                  = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR                 ,
			G8_B8_R8_2Plane_422_Unormalized_KHR                  = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR                  ,
			G8_B8_R8_3Plane_444_UNormalized_KHR                  = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR                 ,
			R10x6_UNormalized_Pack16_KHR                         = VK_FORMAT_R10X6_UNORM_PACK16_KHR                        ,
			R10x6_G10x6_UNormalized_2Pack16_KHR                  = VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR                  ,
			R10x6_G10x6_B10x6_A10x6_UNormalized_4Pack16_KHR      = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR        ,
			G10x6_B10x6_G10x6_R10x6_422_UNormalized_4Pack16_KHR  = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR    ,
			B10x6_G10x6_R10x6_G10x6_422_UNormalized_4Pack16_KHR  = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR    ,
			G10x6_B10x6_3Plane_420_UNormalized_3Pac16_KHR        = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR,
			G10x6_B10x6_R10x6_2PLane_420_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR ,
			G10x6_B10x6_R10x6_3Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR,
			G10x6_B10x6_R10x6_2Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR ,
			G10x6_B10x6_R10x6_3Plane_444_UNormalized_3Pack16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR,
			R12X4_UNormalized_Pack16_KHR                         = VK_FORMAT_R12X4_UNORM_PACK16_KHR                        ,
			R12x4_G12x4_UNormalized_2Pack16_KHR                  = VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR                  ,
			R12x4_G12x4_B12x4_A12x4_UNormalized_4Pack16_KHR      = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR        ,
			G12x4_B12x4_G12x4_R12x4_422_UNormalized_4Pack16_KHR  = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR    ,
			B12x4_G12x4_R12x4_G12x4_422_UNormalized_4Pack16_KHR  = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR    ,
			G12x4_B12x4_R12x4_3Plane_410_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR,
			G12x4_B12x4_R12x4_2Plane_420_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR ,
			G12x4_B12x4_R12x4_3Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR,
			G12x4_B12x4_R12x4_2Plane_422_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR ,
			G12x4_B12x4_R12x4_3Plane_444_UNormalized_3Pack16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR,
			G16_B16_G16_R16_422_UNormalized_KHR                  = VK_FORMAT_G16B16G16R16_422_UNORM_KHR                    ,
			B16_G16_R16_G16_422_UNormalized_KHR                  = VK_FORMAT_B16G16R16G16_422_UNORM_KHR                    ,
			G16_B16_R16_3Plane_420_UNormalized_KHR               = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR              ,
			G16_B16_R16_2Plane_420_UNormalized_KHR               = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR               ,
			G16_B16_R16_3Plane_422_UNormalized_KHR               = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR              ,
			G16_B16_R16_2Plane_422_UNormalized_KHR               = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR               ,
			G16_B16_R16_3Plane_444_UNormalized_KHR               = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR                  // Specifies an unsigned normalized multi-planar format that has a 16-bit G component in each 16-bit word of plane 0, a 16-bit B component in each 16-bit word of plane 1, and a 16-bit R component in each 16-bit word of plane 2. Each plane has the same dimensions and each R, G and B component contributes to a single texel. The location of each plane when this image is in linear layout can be determined via vkGetImageSubresourceLayout, using VK_IMAGE_ASPECT_PLANE_0_BIT for the G plane, VK_IMAGE_ASPECT_PLANE_1_BIT for the B plane, and VK_IMAGE_ASPECT_PLANE_2_BIT for the R plane.
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFormatFeatureFlagBits">Specification</a>  */
		enum class EFormatFeatureFlag : uint32
		{
			SampledImage             = VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT              ,
			StorageImage             = VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT              ,
			ImageAtomic              = VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT       ,
			UniformTexelBuffer       = VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT       ,
			StroageTexelBuffer       = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT       ,
			StorageTexelBufferAtomic = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT,
			VertexBuffer             = VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT              ,
			ColorAttachment          = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT           ,
			ColorAttachmentBlend     = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT     ,
			DepthStencilAttachment   = VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT   ,
			BlitSource               = VK_FORMAT_FEATURE_BLIT_SRC_BIT                   ,
			BlitDestination          = VK_FORMAT_FEATURE_BLIT_DST_BIT                   ,
			SampledImageFilterLinear = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT,

			// Provided by VK_VERSION_1_1
			TransferSource                                                 = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT                                                           ,
			TransferDestination                                            = VK_FORMAT_FEATURE_TRANSFER_DST_BIT                                                           ,
			MidpointChromaSamples                                          = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT                                                ,
			SampledImageYCBCR_ConversionLinearFilter                        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT                           ,
			SampledImageYCBCR_ConversionSeparateReconstructionFilter        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplicit        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplictForcable = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT,
			Disjoint                                                       = VK_FORMAT_FEATURE_DISJOINT_BIT                                                               ,
			CositedChromaSamples                                           = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT                                                 ,

			SampledImageFilterMinMax              = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT             ,   // Provided by VK_VERSION_1_2
			SampledImageFilterCubic_IMG           = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG          ,   // Provided by VK_IMG_filter_cubic
			AccelerationStructureVertexBuffer_KHR = VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR,   // Provided by VK_KHR_ray_tracing
			FragmentDensityMap_EXT                = VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT                ,   // Provided by VK_EXT_fragment_density_map
			TransferSource_KHR                    = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR                        ,   // Provided by VK_KHR_maintenance1
			TransferDestination_KHR               = VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR                        ,   // Provided by VK_KHR_maintenance1
			SampledImageFilterMinMax_EXT          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT         ,   // Provided by VK_EXT_sampler_filter_minmax

			// Provided by VK_KHR_sampler_ycbcr_conversion
			MidpointChromaSamples_KHR                                             = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT_KHR                                                ,
			SampledImageYCBCR_ConversionLinearFilter_KHR                          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR                           ,
			SampledImageYCBCR_ConversionSeparateReconstructionFilter_KHR          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplicit_KHR          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR          ,
			SampledImageYCBCR_ConversionChromaReconstructionExplicit_Forcable_KHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR,
			Disjoint_KHR                                                          = VK_FORMAT_FEATURE_DISJOINT_BIT_KHR                                                               ,
			CositedChromaSamples_KHR                                              = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT_KHR                                                 ,
			SampledImageFilterCubic_EXT                                           = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT                                             ,   // Provided by VK_EXT_filter_cubic
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateFlagBits">Specification</a>  */
		enum class EFrameBufferCreateFlag : uint32 {};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFrontFace">Specification</a>  */
		enum class EFrontFace : uint32
		{
			CounterClockwise = VK_FRONT_FACE_COUNTER_CLOCKWISE,
			Clockwise        = VK_FRONT_FACE_CLOCKWISE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageAspectFlagBits">Specification</a>  */
		enum class EImageAspect : uint32
		{
			Color         = VK_IMAGE_ASPECT_COLOR_BIT             ,
			Depth         = VK_IMAGE_ASPECT_DEPTH_BIT             ,
			Stencil       = VK_IMAGE_ASPECT_STENCIL_BIT           ,
			MetaData      = VK_IMAGE_ASPECT_METADATA_BIT          ,
			Plane_0       = VK_IMAGE_ASPECT_PLANE_0_BIT           ,
			Plane_1       = VK_IMAGE_ASPECT_PLANE_1_BIT           ,
			Plane_2       = VK_IMAGE_ASPECT_PLANE_2_BIT           ,
			MemoryPlane_0 = VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT,
			MemoryPlane_1 = VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT,
			MemroyPlane_2 = VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT,
			MemoryPlane_3 = VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT,
			KHR_Plane_0   = VK_IMAGE_ASPECT_PLANE_0_BIT_KHR       ,
			KHR_Plane_1   = VK_IMAGE_ASPECT_PLANE_1_BIT_KHR       ,
			KHR_Plane_2   = VK_IMAGE_ASPECT_PLANE_2_BIT_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateFlagBits">Specification</a> */
		enum class EImageCreateFlag : uint32
		{
			SparseBinding                      = VK_IMAGE_CREATE_SPARSE_BINDING_BIT                       ,
			SparseResidency                    = VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT                     ,
			SparseAliased                      = VK_IMAGE_CREATE_SPARSE_ALIASED_BIT                       ,
			MutableFormat                      = VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT                       ,
			CubeCompatible                     = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT                      ,
			Alias                              = VK_IMAGE_CREATE_ALIAS_BIT                                ,
			SplitInstanceBindRegions           = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT          ,
			_2DArrayCompatible                 = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT                  ,
			BlockTexelViewCompatible           = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT          ,
			ExtendedUsage                      = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT                       ,
			Protected                          = VK_IMAGE_CREATE_PROTECTED_BIT                            ,
			Disjoint                           = VK_IMAGE_CREATE_DISJOINT_BIT                             ,
			CornerSampled                      = VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV                    ,
			SampleLocationsCompatibleDepth_Ext = VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT,
			Subsampled_Ext                     = VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT                       ,
			SplitInstanceBindRegions_KHR       = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR      ,
			_2DArrayCompatible_KHR             = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR              ,
			BlockTexelViewCompatible_KHR       = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR      ,
			ExtendedUsage_KHR                  = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR                   ,
			Disjoint_KHR                       = VK_IMAGE_CREATE_DISJOINT_BIT_KHR                         ,
			Alias_KHR                          = VK_IMAGE_CREATE_ALIAS_BIT_KHR                            
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageLayout">Specification</a>  */
		enum class EImageLayout : uint32
		{
			Undefined                                    = VK_IMAGE_LAYOUT_UNDEFINED                                     ,
			General                                      = VK_IMAGE_LAYOUT_GENERAL                                       ,
			Color_AttachmentOptimal                      = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL                      ,
			DepthStencil_AttachmentOptimal               = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL              ,
			DepthStencil_ReadonlyOptimal                 = VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL               ,
			Shader_ReadonlyOptimal                       = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL                      ,
			TransferSource_Optimal                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL                          ,
			TransferDestination_Optimal                  = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL                          ,
			Preinitalized                                = VK_IMAGE_LAYOUT_PREINITIALIZED                                ,
			Depth_Readonly_Stencil_AttachemntOptimal     = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL    ,
			Depth_Attachment_Stencil_ReadonlyOptimal     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL    ,
			Depth_AttachmentOptimal                      = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL                      ,
			Depth_ReadonlyOptimal                        = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL                       ,
			Stencil_AttachmentOptimal                    = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL                    ,
			Stencil_ReadonlyOptimal                      = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL                     ,
			PresentSource_KHR                            = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR                               ,
			SharedPresent_KHR                            = VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR                            ,
			ShadingRate_Optimal                          = VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV                       ,
			Fragment_DensityMapOptimal_EXT               = VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT              ,
			Depth_Readonly_Stencil_AttachmentOptimal_KHR = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR,
			Depth_Atteachment_StencilReadonlyOptimal_KHR = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR,
			Depth_AttachmentOptimal_KHR                  = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR                  ,
			Depth_ReadonlyOptimal_KHR                    = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR                   ,
			Stencil_AttachmentOptimal_KHR                = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR                ,
			Stencil_ReadonlyOptimal_KHR                  = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR                 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageTiling">Specification</a>  */
		enum class EImageTiling : uint32
		{
			Optimal                      = VK_IMAGE_TILING_OPTIMAL                ,
			Linear                       = VK_IMAGE_TILING_LINEAR                 ,
			DRM_FormatModifier_Extension = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageType">Specification</a>  */
		enum class EImageType : uint32
		{
			_1D = VK_IMAGE_TYPE_1D,
			_2D = VK_IMAGE_TYPE_2D,
			_3D = VK_IMAGE_TYPE_3D
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageUsageFlagBits">Specification</a> */
		enum class EImageUsage : uint32
		{
			TransferSource          = VK_IMAGE_USAGE_TRANSFER_SRC_BIT            ,
			TransferDestination     = VK_IMAGE_USAGE_TRANSFER_DST_BIT            ,
			Sampled                 = VK_IMAGE_USAGE_SAMPLED_BIT                 ,
			Storage                 = VK_IMAGE_USAGE_STORAGE_BIT                 ,
			Color_Attachment        = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT        ,
			DepthStencil_Attachment = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
			Transient_Attachment    = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT    ,
			Input_Attachemnt        = VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT        ,
			Image_ShadingRate       = VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV   ,
			DensityMap              = VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateFlagBits">Specification</a>  */
		enum class EImageViewCreateFlag : uint32
		{
			Fragment_DensityMapDynamiic = VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageView">Specification</a>  */
		enum class EImageViewType : uint32
		{
			_1D       = VK_IMAGE_VIEW_TYPE_1D        ,
			_2D       = VK_IMAGE_VIEW_TYPE_2D        ,
			_3D       = VK_IMAGE_VIEW_TYPE_3D        ,
			_Cube     = VK_IMAGE_VIEW_TYPE_CUBE      ,
			_1D_Array = VK_IMAGE_VIEW_TYPE_1D_ARRAY  ,
			_2D_Array = VK_IMAGE_VIEW_TYPE_2D_ARRAY  ,
			CubeArray = VK_IMAGE_VIEW_TYPE_CUBE_ARRAY
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkIndexType">Specification</a>  */
		enum class EIndexType : uint32
		{
			uInt16   = VK_INDEX_TYPE_UINT16   ,
			uInt32   = VK_INDEX_TYPE_UINT32   ,
			None_KHR = VK_INDEX_TYPE_NONE_KHR ,
			uInt8    = VK_INDEX_TYPE_UINT8_EXT,
			None_NV  = VK_INDEX_TYPE_NONE_NV 
		};

		/** @brief <a href="linkURL">Specification</a>  */
		enum class EInternalAllocationType
		{
			Executable = VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlagBits">Specification</a>  */
		enum class ELogicalDeviceQueueCreateFlag : uint32
		{
			CreateProtected = VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkLogicOp">Specification</a>  */
		enum class ELogicOperation : uint32
		{
			Clear         = VK_LOGIC_OP_CLEAR        ,
			And           = VK_LOGIC_OP_AND          ,
			And_Reverse   = VK_LOGIC_OP_AND_REVERSE  ,
			Copy          = VK_LOGIC_OP_COPY         ,
			And_Inverted  = VK_LOGIC_OP_AND_INVERTED ,
			No            = VK_LOGIC_OP_NO_OP        ,
			XOR           = VK_LOGIC_OP_XOR          ,
			Or            = VK_LOGIC_OP_OR           ,
			NOR           = VK_LOGIC_OP_NOR          ,
			Equivalent    = VK_LOGIC_OP_EQUIVALENT   ,
			Int           = VK_LOGIC_OP_INVERT       ,
			OR_Reverse    = VK_LOGIC_OP_OR_REVERSE   ,
			Copy_Inverted = VK_LOGIC_OP_COPY_INVERTED,
			Or_Inverted   = VK_LOGIC_OP_OR_INVERTED  ,
			NAND          = VK_LOGIC_OP_NAND         ,
			Set           = VK_LOGIC_OP_SET          
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeapFlagBits">Specification</a>  */
		enum class EMemoryHeapFlag : uint32
		{
			DeviceLocal       = VK_MEMORY_HEAP_DEVICE_LOCAL_BIT      ,
			MultiInstance     = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT    ,
			MultiInstance_KHR = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR 
		};

		enum class EMemoryOverallocationBehaviorAMD : uint32
		{
			Default    = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD   , 
			Allowed    = VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD   , 
			Disallowed = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryPropertyFlagBits">Specification</a>  */
		enum class EMemoryPropertyFlag : uint32
		{
			DeviceLocal        = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT       ,
			HostVisible        = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT       ,
			HostCoherent       = VK_MEMORY_PROPERTY_HOST_COHERENT_BIT      , 
			HostCached         = VK_MEMORY_PROPERTY_HOST_CACHED_BIT        ,
			LazilyAllocated    = VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT   ,
			Protected          = VK_MEMORY_PROPERTY_PROTECTED_BIT          ,
			DeviceCoherent_AMD = VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD,
			DeviceUncached_AMD = VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkObjectType">Specification</a>  */
		enum class EObjectType : uint32
		{
			Unknown                        = VK_OBJECT_TYPE_UNKNOWN                        ,
			Instance                       = VK_OBJECT_TYPE_INSTANCE                       ,
			PhysicalDevice                 = VK_OBJECT_TYPE_PHYSICAL_DEVICE                ,
			Device                         = VK_OBJECT_TYPE_DEVICE                         ,
			Queue                          = VK_OBJECT_TYPE_QUEUE                          ,
			Semaphore                      = VK_OBJECT_TYPE_SEMAPHORE                      ,
			CommandBuffer                  = VK_OBJECT_TYPE_COMMAND_BUFFER                 ,
			Fence                          = VK_OBJECT_TYPE_FENCE                          ,
			DeviceMemory                   = VK_OBJECT_TYPE_DEVICE_MEMORY                  ,
			Buffer                         = VK_OBJECT_TYPE_BUFFER                         ,
			Image                          = VK_OBJECT_TYPE_IMAGE                          ,
			Event                          = VK_OBJECT_TYPE_EVENT                          ,
			QueryPool                      = VK_OBJECT_TYPE_QUERY_POOL                     ,
			BufferView                     = VK_OBJECT_TYPE_BUFFER_VIEW                    ,
			ImageView                      = VK_OBJECT_TYPE_IMAGE_VIEW                     ,
			ShaderModule                   = VK_OBJECT_TYPE_SHADER_MODULE                  ,
			PipelineCache                  = VK_OBJECT_TYPE_PIPELINE_CACHE                 ,
			PipelineLayout                 = VK_OBJECT_TYPE_PIPELINE_LAYOUT                ,
			RenderPass                     = VK_OBJECT_TYPE_RENDER_PASS                    ,
			Pipeline                       = VK_OBJECT_TYPE_PIPELINE                       ,
			DescriptorSetLayout            = VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT          ,
			Sampler                        = VK_OBJECT_TYPE_SAMPLER                        ,
			DescriptorPool                 = VK_OBJECT_TYPE_DESCRIPTOR_POOL                ,
			DescriptorSet                  = VK_OBJECT_TYPE_DESCRIPTOR_SET                 ,
			FrameBuffer                    = VK_OBJECT_TYPE_FRAMEBUFFER                    ,
			CommandPool                    = VK_OBJECT_TYPE_COMMAND_POOL                   ,
			Sampler_YCBCR_Conversion       = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION       ,
			DescriptorUpdateTemplate       = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE     ,
			Surface_KHR                    = VK_OBJECT_TYPE_SURFACE_KHR                    ,
			SwapChain_KHR                  = VK_OBJECT_TYPE_SWAPCHAIN_KHR                  ,
			Display_KHR                    = VK_OBJECT_TYPE_DISPLAY_KHR                    ,
			DisplayMode_KHR                = VK_OBJECT_TYPE_DISPLAY_MODE_KHR               ,
			DebugReportCallback_EXT        = VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT      ,
			DebugUtilsMessenger_EXT        = VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT      ,
			AccelerationStructure_KHR      = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR     ,
			ValidationCache_EXT            = VK_OBJECT_TYPE_VALIDATION_CACHE_EXT           ,
			Intel_PerformanceConfiguration = VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL,
			DeferredOperation_KHR          = VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR         ,
			IndirectCommandsLayout         = VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV    ,
			//Extension_PrivateDataSlot = VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT,   // TODO: is this ok?
			PrivateDataSlot_EXT            = 1000295000,
			DescriptorUpdateTemplate_KHR   = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR ,
			Sampler_YCBCR_Conversion_KHR   = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR   ,
			AccelerationStructure          = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterDescriptionFlagBitsKHR">Specification</a>  */
		enum class EPerformanceCounterDescriptionFlag : uint32
		{
			PerformanceImpacting = VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR,
			ConcurrentlyImpacted = VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterScopeKHR">Specification</a>  */
		enum class EPerformanceCounterScope : uint32
		{
			Performance_CommandBuffer = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR,
			Performance_RenderPass    = VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR   ,
			Performance_Command       = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR       ,
			Query_Buffer              = VK_QUERY_SCOPE_COMMAND_BUFFER_KHR              ,
			Query_RenderPass          = VK_QUERY_SCOPE_RENDER_PASS_KHR                 ,
			Query_Command             = VK_QUERY_SCOPE_COMMAND_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterStorageKHR">Specification</a>  */
		enum class EPerformanceCounterStorage : uint32
		{
			VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR = 0,
			VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR = 1,
			VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR = 2,
			VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR = 3,
			VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR = 4,
			VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR = 5,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterUnitKHR">Specification</a>  */
		enum class EPerformanceCounterUnit : uint32
		{
			Generic        = VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR         ,
			Percentage     = VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR      ,
			Nanoseconds    = VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR     ,
			Bytes          = VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR           ,
			BytesPerSecond = VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR,
			Kelvin         = VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR          ,
			Watts          = VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR           ,
			Volts          = VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR           ,
			Amps           = VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR            ,
			Hertz          = VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR           ,
			Cycles         = VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR          
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineBindPoint">Specification</a>  */
		enum class EPipelineBindPoint : uint32
		{
			Graphics = VK_PIPELINE_BIND_POINT_GRAPHICS,
			Compute  = VK_PIPELINE_BIND_POINT_COMPUTE 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateFlagBits">Specification</a>  */
		enum class EPipelineCacheCreateFlag : uint32
		{
			Externally_Synchronized = VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCreateFlagBits">Specification</a>  */
		enum class EPipelineCreateFlag : uint32
		{
			DisableOptimization                    = VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT                        ,
			AllowDerivatives                       = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT                           ,
			Derivative                             = VK_PIPELINE_CREATE_DERIVATIVE_BIT                                  ,
			ViewIndexFromDeviceIndex               = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT                ,
			DispatchBase                           = VK_PIPELINE_CREATE_DISPATCH_BASE_BIT                               ,
			Raytracing_NoNull_AnyHit_Shaders       = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR     ,
			Raytracing_NoNull_ClosestHit_Shaders   = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR ,
			Raytracing_NoNull_Miss_Shaders         = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR        ,
			Raytracing_NoNull_Intersection_Shaders = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR,
			Raytracing_SkipTriangles               = VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR              ,
			Raytracing_Skip_AABBS                  = VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR                  ,
			DeferCompile                           = VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV                            ,
			CaptureStatistics                      = VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR                      ,
			CaptureInternalRepresentations         = VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR        ,
			IndirectBindable                       = VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV                        ,
			Library                                = VK_PIPELINE_CREATE_LIBRARY_BIT_KHR                                 ,
			FailOn_PipelineCompileRequired         = VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT       ,
			EarlyReturnOn_Failure                  = VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT                 ,
			DispatchBase2                          = VK_PIPELINE_CREATE_DISPATCH_BASE                                   ,
			ViewIndexFromDeviceInex                = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR            ,
			DispatchBase_KHR                       = VK_PIPELINE_CREATE_DISPATCH_BASE_KHR                               
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineShaderStageCreateFlagBits">Specification</a>  */
		enum class EPipelineShaderStageCreateFlag : uint32
		{
			AllowVaryingSubgroupSize = VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT,
			RequireFullSubgroups     = VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineStageFlagBits">Specification</a>  */
		enum class EPipelineStageFlag : uint32
		{
			TopOfPipe                    = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT                   ,
			DrawIndirect                 = VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT                 ,
			VertexInput                  = VK_PIPELINE_STAGE_VERTEX_INPUT_BIT                  ,
			VertexShader                 = VK_PIPELINE_STAGE_VERTEX_SHADER_BIT                 ,
			TessellationControlShader    = VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT   ,
			TessellationEvaluationShader = VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT,
			GeometryShader               = VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT               ,
			FragementShader              = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT               ,
			EarlyFragmentTests           = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT          ,
			LateFragmentTests            = VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT           ,
			ColorAttachmentOutput        = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT       ,
			ComputeShader                = VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT                ,
			Transfer                     = VK_PIPELINE_STAGE_TRANSFER_BIT                      ,
			BottomOfPipe                 = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT                ,
			Host                         = VK_PIPELINE_STAGE_HOST_BIT                          ,
			AllGraphics                  = VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT                  ,
			AllCommands                  = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#primsrast-polygonmode">Specification</a>  */
		enum class EPolygonMode : uint32
		{
			Fill              = VK_POLYGON_MODE_FILL             ,
			Line              = VK_POLYGON_MODE_LINE             ,
			Point             = VK_POLYGON_MODE_POINT            ,
			NV_Fill_Rectangle = VK_POLYGON_MODE_FILL_RECTANGLE_NV
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPresentModeKHR">Specification</a>  */
		enum class EPresentationMode : uint32
		{
			Immediate               = VK_PRESENT_MODE_IMMEDIATE_KHR                ,
			Mailbox                 = VK_PRESENT_MODE_MAILBOX_KHR                  ,
			FIFO                    = VK_PRESENT_MODE_FIFO_KHR                     ,
			FIFO_Relaxed            = VK_PRESENT_MODE_FIFO_RELAXED_KHR             ,
			SharedDemandRefresh     = VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR    ,
			SharedContinuousRefresh = VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPrimitiveTopology">Specification</a>  */
		enum class EPrimitiveTopology : uint32
		{
			PointList                   = VK_PRIMITIVE_TOPOLOGY_POINT_LIST                   ,
			LineList                    = VK_PRIMITIVE_TOPOLOGY_LINE_LIST                    ,
			LineStrip                   = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP                   ,
			TriangleList                = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST                ,
			TriangleStrip               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP               ,
			TriangleFan                 = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN                 ,
			LineList_WithAdjacency      = VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY     ,
			LineStrip_WithAdjacency     = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY    ,
			TriangleList_WithAdjaceny   = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY ,
			TriangleStrip_WithAdjacency = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY,
			PatchList                   = VK_PRIMITIVE_TOPOLOGY_PATCH_LIST                    
		};

		/**
		@brief Supported physical device types.

		@details
		The physical device type is advertised for informational purposes only, and does not directly affect the operation of the system. 
		However, the device type may correlate with other advertised properties or capabilities of the system, such as how many memory heaps there are.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkPhysicalDeviceType.html">Specification</a> 
		*/
		enum class EPhysicalDeviceType : uint32
		{
			Other          = VK_PHYSICAL_DEVICE_TYPE_OTHER         ,
			IntergratedGPU = VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU,
			DiscreteGPU    = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU  ,
			VirtualGPU     = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU   ,
			CPU            = VK_PHYSICAL_DEVICE_TYPE_CPU
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPointClippingBehavior">Specification</a>  */
		enum class EPointClippingBehavior : uint32
		{
			AllClipPlanes      = VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES      , 
			UserClipPlanesOnly = VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY, 

			// Provided by VK_KHR_maintenance2
			AllClipPlanes_KHR      = VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR      , 
			UserClipPlanesOnly_KHR = VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryControlFlagBits">Specification</a>  */
		enum class EQueryControlFlags : uint32
		{
			Precise = VK_QUERY_CONTROL_PRECISE_BIT
		};

		/**
		@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFlagBits">Specification</a> 
		*/
		enum class EQueueFlag : uint32
		{
			Graphics      = VK_QUEUE_GRAPHICS_BIT      ,
			Compute       = VK_QUEUE_COMPUTE_BIT       ,
			Transfer      = VK_QUEUE_TRANSFER_BIT      ,
			SparseBinding = VK_QUEUE_SPARSE_BINDING_BIT,
			Protected     = VK_QUEUE_PROTECTED_BIT     ,
			MaxEnum       = VK_QUEUE_FLAG_BITS_MAX_ENUM
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryPipelineStatisticFlagBits">Specification</a>  */
		enum class EQueryPipelineStatisticFlag : uint32
		{
			AssemblyVertices                        = VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT                   ,
			AssemblyPrimitives                      = VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT                 ,
			VertexShaderInovcations                 = VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT                 ,
			GeometryShaderInvocations               = VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT               ,
			GeometryShaderPrimitives                = VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT                ,
			ClippingInocation                       = VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT                      ,
			ClippingPrimitives                      = VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT                       ,
			FragmentShaderInvoations                = VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT               ,
			TessellationControlShaderPatches        = VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT       ,
			TessellationEvaluationShaderInvocations = VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT,
			ComputeShaderInvocations                = VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkResolveModeFlagBits">Specification</a> */
		enum class EResolveModeFlags : uint32
		{
			None       = VK_RESOLVE_MODE_NONE ,
			SampleZero = VK_RESOLVE_MODE_SAMPLE_ZERO_BIT ,
			Average    = VK_RESOLVE_MODE_AVERAGE_BIT ,
			Min        = VK_RESOLVE_MODE_MIN_BIT ,
			Max        = VK_RESOLVE_MODE_MAX_BIT ,

			// Provided by VK_KHR_depth_stencil_resolve
			None_KHR       = VK_RESOLVE_MODE_NONE_KHR           ,
			SampleZero_KHR = VK_RESOLVE_MODE_SAMPLE_ZERO_BIT_KHR,
			Average_KHR    = VK_RESOLVE_MODE_AVERAGE_BIT_KHR    ,
			Min_KHR        = VK_RESOLVE_MODE_MIN_BIT_KHR        ,
			Max_KHR        = VK_RESOLVE_MODE_MAX_BIT_KHR        ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkResult">Specification</a>  */
		enum class EResult : sint32
		{
			Success                                         = VK_SUCCESS                                           ,
			Not_Ready                                       = VK_NOT_READY                                         ,
			Timeout                                         = VK_TIMEOUT                                           ,
			Event_Set                                       = VK_EVENT_SET                                         ,
			Event_Reset                                     = VK_EVENT_RESET                                       ,
			Incomplete                                      = VK_INCOMPLETE                                        ,
			Error_OutOfHostMemory                           = VK_ERROR_OUT_OF_HOST_MEMORY                          ,
			Error_OutOfDeviceMemory                         = VK_ERROR_OUT_OF_DEVICE_MEMORY                        ,
			Error_InitalizationFailed                       = VK_ERROR_INITIALIZATION_FAILED                       ,
			Error_DeviceLost                                = VK_ERROR_DEVICE_LOST                                 ,
			Error_MemoryMap_Failed                          = VK_ERROR_MEMORY_MAP_FAILED                           ,
			Error_LayerNotPresent                           = VK_ERROR_LAYER_NOT_PRESENT                           ,
			Error_ExtensionNotPresent                       = VK_ERROR_EXTENSION_NOT_PRESENT                       ,
			Error_FeatureNotPresent                         = VK_ERROR_FEATURE_NOT_PRESENT                         ,
			Error_IncompatibleDriver                        = VK_ERROR_INCOMPATIBLE_DRIVER                         ,
			Error_TooManyObjects                            = VK_ERROR_TOO_MANY_OBJECTS                            ,
			Error_FormatNotSupported                        = VK_ERROR_FORMAT_NOT_SUPPORTED                        ,
			Error_FragmentedPool                            = VK_ERROR_FRAGMENTED_POOL                             ,
			Error_Unknown                                   = VK_ERROR_UNKNOWN                                     ,
			Error_OutOfPoolMemory                           = VK_ERROR_OUT_OF_POOL_MEMORY                          ,
			Error_InvalidExternalHandle                     = VK_ERROR_INVALID_EXTERNAL_HANDLE                     ,
			Error_Fragmentation                             = VK_ERROR_FRAGMENTATION                               ,
			Error_InvalidOpaqueCaptureAddress               = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS              ,
			Error_SurfaceLost_KHR                           = VK_ERROR_SURFACE_LOST_KHR                            ,
			Error_NativeWindowInUse_KHR                     = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR                    ,
			Suboptimal_KHR                                  = VK_SUBOPTIMAL_KHR                                    ,
			Error_OutOfDate_KHR                             = VK_ERROR_OUT_OF_DATE_KHR                             ,
			Error_IncompatbileDisplay_KHR                   = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR                    ,
			Error_Extension_ValidationFailed                = VK_ERROR_VALIDATION_FAILED_EXT                       ,
			Error_InvalidShader_NV                          = VK_ERROR_INVALID_SHADER_NV                           ,
			Error_IncompatibleVersion_KHR                   = VK_ERROR_INCOMPATIBLE_VERSION_KHR                    ,
			Error_Invalid_DRMFormat_ModifierPlaneLayout_EXT = VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT,
			Error_NotPermitted_EXT                          = VK_ERROR_NOT_PERMITTED_EXT                           ,
			Error_FullScreenExculsiveMode_Lost_EXT          = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT         ,
			Thread_Idle_KHR                                 = VK_THREAD_IDLE_KHR                                   ,
			Thread_Done_KHR                                 = VK_THREAD_DONE_KHR                                   ,
			OperationDeferred_KHR                           = VK_OPERATION_DEFERRED_KHR                            ,
			OperationNotDeferred_KHR                        = VK_OPERATION_NOT_DEFERRED_KHR                        ,
			PipelineCompileRequired_EXT                     = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT               ,
			Error_OutOfPoolMemory_KHR                       = VK_ERROR_OUT_OF_POOL_MEMORY_KHR                      ,
			Error_InvalidExternalHandle_KHR                 = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR                 ,
			Error_Fragmentation_EXT                         = VK_ERROR_FRAGMENTATION_EXT                           ,
			Error_InvalidDeviceAddress_EXT                  = VK_ERROR_INVALID_DEVICE_ADDRESS_EXT                  ,
			Error_InvalidOpaqueCaptureAddress_KHR           = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR          ,
			Error_PipelineCompileRequired_EXT               = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampleCountFlagBits">Specification</a>  */
		enum class ESampleCount : uint32
		{
			_1  = VK_SAMPLE_COUNT_1_BIT ,
			_2  = VK_SAMPLE_COUNT_2_BIT ,
			_4  = VK_SAMPLE_COUNT_4_BIT ,
			_8  = VK_SAMPLE_COUNT_8_BIT ,
			_16 = VK_SAMPLE_COUNT_16_BIT,
			_32 = VK_SAMPLE_COUNT_32_BIT,
			_64 = VK_SAMPLE_COUNT_64_BIT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerAddressMode">Specification</a>  */
		enum class ESamplerAddressMode : uint32
		{
			Repeat         = VK_SAMPLER_ADDRESS_MODE_REPEAT         ,
			MirroredRepeat = VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
			ClampToEdge    = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE  ,
			ClampToBorder  = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
			
			// Provided by VK_VERSION_1_2, VK_KHR_sampler_mirror_clamp_to_edge
			MirrorClampToEdge     = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE    ,
			MirrorClampToEdge_KHR = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateFlagBits">Specification</a>  */
		enum class ESamplerCreateFlag : uint32
		{
			Subsampled_EXT                     = VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT                      ,
			SubsampledCoarseReconstruction_EXT = VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerMipmapMode">Specification</a>  */
		enum class ESamplerMipmapMode : uint32
		{
			Nearest = VK_SAMPLER_MIPMAP_MODE_NEAREST,
			Linear  = VK_SAMPLER_MIPMAP_MODE_LINEAR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreImportFlagBits">Specification</a>  */
		enum class ESemaphoreImportFlag
		{
			Temporary     = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT    ,
			Temporary_KHR = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreType">Specification</a>  */
		enum class ESemaphoreType : uint32
		{
			Binary       = VK_SEMAPHORE_TYPE_BINARY      ,
			Timeline     = VK_SEMAPHORE_TYPE_TIMELINE    ,
			Binary_KHR   = VK_SEMAPHORE_TYPE_BINARY_KHR  ,
			Timeline_KHR = VK_SEMAPHORE_TYPE_TIMELINE_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitFlagBits">Specification</a>  */
		enum class ESemaphoreWaitFlag : uint32
		{
			Any     = VK_SEMAPHORE_WAIT_ANY_BIT    ,
			Any_KHR = VK_SEMAPHORE_WAIT_ANY_BIT_KHR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderFloatControlsIndependence">Specification</a>  */
		enum class EShaderFloatControlIndependence : uint32
		{
			_32Bit_Only = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY,
			All         = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL        ,
			None        = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE       ,

			// Provided by VK_KHR_shader_float_controls
			_32Bit_Only_KHR = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY_KHR,
			All_KHR         = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL_KHR        ,
			None_KHR        = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE_KHR       ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderStageFlagBits">Specification</a>  */
		enum class EShaderStageFlag : uint32
		{
			Vertex                 = VK_SHADER_STAGE_VERTEX_BIT                 ,
			TessellationControl    = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT   ,
			TessellationEvaluation = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT,
			Geometry               = VK_SHADER_STAGE_GEOMETRY_BIT               ,
			Fragment               = VK_SHADER_STAGE_FRAGMENT_BIT               ,
			Compute                = VK_SHADER_STAGE_COMPUTE_BIT                ,
			Graphics               = VK_SHADER_STAGE_ALL_GRAPHICS               ,
			All                    = VK_SHADER_STAGE_ALL                        ,
			Raygen_KHR             = VK_SHADER_STAGE_RAYGEN_BIT_KHR             ,
			AnyHit_KHR             = VK_SHADER_STAGE_ANY_HIT_BIT_KHR            ,
			ClosestHit_KHR         = VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR        ,
			Miss_KHR               = VK_SHADER_STAGE_MISS_BIT_KHR               ,
			Intersection_KHR       = VK_SHADER_STAGE_INTERSECTION_BIT_KHR       ,
			Callable_KHR           = VK_SHADER_STAGE_CALLABLE_BIT_KHR           ,
			Task_NV                = VK_SHADER_STAGE_TASK_BIT_NV                ,
			Mesh_NV                = VK_SHADER_STAGE_MESH_BIT_NV                ,
			Raygen_NV              = VK_SHADER_STAGE_RAYGEN_BIT_NV              ,
			AnyHit_NV              = VK_SHADER_STAGE_ANY_HIT_BIT_NV             ,
			ClosestHit_NV          = VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV         ,
			Miss_NV                = VK_SHADER_STAGE_MISS_BIT_NV                ,
			Intersection_NV        = VK_SHADER_STAGE_INTERSECTION_BIT_NV        ,
			Callable_NV            = VK_SHADER_STAGE_CALLABLE_BIT_NV            
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSharingMode">Specification</a>  */
		enum class ESharingMode : uint32
		{
			Exclusive  = VK_SHARING_MODE_EXCLUSIVE ,
			Concurrent = VK_SHARING_MODE_CONCURRENT
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkStencilOp">Specification</a>  */
		enum class EStencilOperation : uint32
		{
			Keep              = VK_STENCIL_OP_KEEP               ,
			Zero              = VK_STENCIL_OP_ZERO               ,
			Replace           = VK_STENCIL_OP_REPLACE            ,
			IncrementAndClamp = VK_STENCIL_OP_INCREMENT_AND_CLAMP,
			DecrementAndClamp = VK_STENCIL_OP_DECREMENT_AND_CLAMP,
			Invert            = VK_STENCIL_OP_INVERT             ,
			IncrementAndWrap  = VK_STENCIL_OP_INCREMENT_AND_WRAP ,
			DecrementAndWrap  = VK_STENCIL_OP_DECREMENT_AND_WRAP 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkStructureType">Specification</a>  */
		enum class EStructureType : uint32
		{
			ApplicationInformation                                      = VK_STRUCTURE_TYPE_APPLICATION_INFO                                               ,
			Instance_CreateInfo                                         = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO                                           ,
			DeviceQueue_CreateInfo                                      = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO                                       ,
			Device_CreateInfo                                           = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO                                             ,
			SubmitInfo                                                  = VK_STRUCTURE_TYPE_SUBMIT_INFO                                                    ,
			MemoryAllocateInfo                                          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO                                           ,
			MappedMemoryRange                                           = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE                                            ,
			BindSparseInfo                                              = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO                                               ,
			Fence_CreateInfo                                            = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO                                              ,
			Semaphore_CreateInfo                                        = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO                                          ,
			Event_CreateInfo                                            = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO                                              ,
			QueryPool_CreateInfo                                        = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO                                         ,
			Buffer_CreateInfo                                           = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO                                             ,
			BufferView_CreateInfo                                       = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO                                        ,
			Image_CreateInfo                                            = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO                                              ,
			ImageView_CreateInfo                                        = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO                                         ,  									     
			ShaderModule_CreateInfo                                     = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO                                      ,
			Pipeline_Cache_CreateInfo                                   = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO                                     ,
			Pipeline_ShaderStage_CreateInfo                             = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO                              ,
			Pipeline_VertexInputState_CreateInfo                        = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO                        ,
			Pipeline_InputAssemblyState_CreateInfo                      = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO                      ,
			Pipeline_TessellationState_CreateInfo                       = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO                        ,
			Pipeline_ViewportState_CreateInfo                           = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO                            ,
			Pipeline_RasterizationState_CreateInfo                      = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO                       ,
			Pipeline_MultisampleState_CreateInfo                        = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO                         ,
			Pipeline_DepthStencilState_CreateInfo                       = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO                       ,
			Pipeline_ColorBlendState_CreateInfo                         = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO                         ,   					   
			Pipeline_DynamicState_CreateInfo                            = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO                             ,
			GraphicsPipeline_CreateInfo                                 = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO                                  ,
			ComputePipeline_CreateInfo                                  = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO                                   ,
			Pipeline_Layout_CreateInfo                                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO                                    ,
			Sampler_CreateInfo                                          = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO                                            ,
			Descriptor_SetLayout_CreateInfo                             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO                              ,
			Descriptor_Pool_CreateInfo                                  = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO                                    ,     
			Descriptor_SetAllocateInfo                                  = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO                                   ,
			WriteDescriptor_Set                                         = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET                                           ,
			CopyDescriptor_Set                                          = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET                                            ,
			Framebuffer_CreateInfo                                      = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO                                        ,
			RenderPass_CreateInfo                                       = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO                                        ,
			CommandPool_CreateInfo                                      = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO                                       ,    
			CommandBuffer_AllocateInfo                                  = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO                                   ,
			CommandBuffer_InheritanceInfo                               = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO                                ,
			CommandBuffer_BeginInfo                                     = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO                                      ,
			RenderPass_BeginInfo                                        = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO                                         ,
			BufferMemory_Barrier                                        = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER                                          ,
			ImageMemory_Barrier                                         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER                                           ,
			Memory_Barrier                                              = VK_STRUCTURE_TYPE_MEMORY_BARRIER                                                 ,
			LoaderInstance_CreateInfo                                   = VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO                                    ,
			LoaderDevice_CreateInfo                                     = VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO                                      ,
			PhysicalDevice_SubgroupProperties                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES                            ,
			BindBuffer_MemoryInfo                                       = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO                                        ,
			BindImage_MemoryInfo                                        = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO                                         ,
			PhysicalDevice_16Bit_StorageFeatures                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES                         ,      
			MemoryDedicatedRequirements                                 = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS                                  ,
			MemoryDedicated_AllocateInfo                                = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO                                 ,
			Memory_AllocateFlagsInfo                                    = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO                                     ,
			DeviceGroup_RenderPass_BeginInfo                            = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO                            ,
			DeviceGroup_CommandBuffer_BeginInfo                         = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO                         ,
			DeviceGroup_SubmitInfo                                      = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO                                       ,
			DeviceGroup_BindSparseInfo                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO                                  ,
			BindBuffer_MemoryDevice_GroupInfo                           = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO                           ,
			BindImage_MemoryDevice_GroupInfo                            = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO                            ,
			PhysicalDevice_GroupProperties                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES                               ,
			Device_GroupDevice_CreateInfo                               = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO                                ,
			BufferMemory_RequirementsInfo_2                             = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2                              ,
			ImageMemory_RequirementsInfo_2                              = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2                               ,
			ImageSparseMemory_RequirementsInfo_2                        = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2                        ,
			MemoryRequirements_2                                        = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2                                          ,
			SparseImage_MemoryRequirements_2                            = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2                             ,
			PhysicalDevice_Features_2                                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2                                     ,
			PhysicalDevice_Properties_2                                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2                                   ,
			Format_Properties_2                                         = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2                                            ,
			ImageFormat_Properties_2                                    = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2                                      ,
			PhysicalDevice_ImageFormatInfo_2                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2                            ,
			QueueFamily_Properties_2                                    = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2                                      ,
			PhysicalDevice_MemoryProperties_2                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2                            ,
			SpareImageFormat_Properites2                                = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2                               ,
			PhysicalDevice_SparceImageFormatInfo_2                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2                     ,
			PhysicalDevice_PointClippingProperites                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES                      ,
			RenderPass_InputAttachmentAspectCreateInfo                  = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO                ,
			ImageViewUsage_CreateInfo                                   = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO                                   ,
			Pipeline_TessellationDomainOriginState_CreateInfo           = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO          ,
			RenderPassMulitivew_CreateInfo                              = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO                              ,
			PhysicalDevice_MultiviewFeatures                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES                             ,
			PhysicalDevice_MultivewProperties                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES                           ,
			PhysicalDevice_PointersFeatures                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES                     ,
			ProtectedSubmitInfo                                         = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO                                          ,
			PhysicalDevice_ProtectedMemoryFeatures                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES                      ,
			PhysicalDevice_ProtectedMemoryProperties                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES                    ,
			DeviceQueueInfo2                                            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2                                            ,
			SamplerYCBCR_Conversion_CreateInfo                          = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO                           ,
			SamplerYCBCR_Conversion_Info                                = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO                                  ,
			BindImagePlane_MemoryInfo                                   = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO                                   ,
			ImagePlaneMemory_RequirementsInfo                           = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO                           ,
			PhysicalDevice_SamplerYCBCR_ConversionFeatures              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES              ,
			SamplerYCBCR_Conversion_ImageFormatProperties               = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES               ,
			DescriptorUpdateTemplate_CreateInfo                         = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO                         ,
			PhysicalDevice_ExternalImageFormat_Info                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO                     ,
			ExternalImageFormat_Properties                              = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES                               ,
			PhysicalDevice_ExternalBuffer_Info                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO                           ,
			ExternalBuffer_Properites                                   = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES                                     ,
			PhysicalDevice_ID_Properties                                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES                                  ,
			ExternalMemoryBuffer_CreateInfo                             = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO                             ,
			ExtenralMemoryImage_CreateInfo                              = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO                              ,
			ExternalMemoryAllocate_Info                                 = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO                                    ,
			PhysicalDevice_ExternalFence_Info                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO                            ,
			ExternalFence_Properties                                    = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES                                      ,
			ExportFence_CreateInfo                                      = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO                                       ,
			ExportSemaphore_CreateInfo                                  = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO                                   ,
			PhysicalDevice_ExternalSemaphore_Info                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO                        ,
			ExternalSemaphore_Properties                                = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES                                  ,
			PhysicalDevice_Maintence_3_Properties                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES                       ,
			Descriptor_SetLayoutSupport                                 = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT                                  , 							    
			PhysicalDevice_ShaderDrawParameters_Features                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES                ,   		     
			PhysicalDevice_Vulkan_1_1_Features                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES                            ,
			PhysicalDevice_Vulkan_1_1_Properties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES                          ,
			PhysicalDevice_Vulkan_1_2_Features                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES                            ,
			PhysicalDevice_Vulkan_1_2_Properties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES                          ,   					    
			ImageFormatList_CreateInfo                                  = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO                                  ,
			AttachmentDescription_2                                     = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2                                       ,
			AttachmentReference_2                                       = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2                                         ,
			SubpassDescription_2                                        = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2                                          ,
			SubpassDependency_2                                         = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2                                           ,
			RenderPass_CreateInfo_2                                     = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2                                      ,
			Subpass_BeginInfo                                           = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO                                             ,
			Subpass_EndInfo                                             = VK_STRUCTURE_TYPE_SUBPASS_END_INFO                                               ,
			PhysicalDevice_8BitStorageFeatures                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES                          ,
			PhysicalDevice_DriverProperites                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES                              ,
			Physicaldevice_ShaderAtomic_Int64Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES                   ,
			PhysicalDevice_ShaderFloat16_Int8Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES                   ,
			PhysicalDevice_FloatControlsProperties                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES                      ,
			Descriptor_SetLayoutBindingFlags_CreateInfo                 = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO                ,
			PhysicalDevice_Descriptor_IndexingFeatures                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES                   ,
			PhysicalDevice_Descriptor_IndexingProperties                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES                 ,
			Descriptor_SetVariable_DescriptorCount_AllocateInfo         = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO         ,
			Descriptor_SetVariable_Descriptor_CountLayoutSupport        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT        ,
			PhysicalDevice_DepthStencil_ResolveProperties               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES               ,    
			SubpassDescription_DepthStencilResolve                      = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE                      ,
			PhysicalDevice_ScalarBlockLayoutFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES                   ,
			ImageStencilUsage_CreateInfo                                = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO                                ,
			PhysicalDevice_SamplerFilterMinMax_Properties               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES               ,
			Sampler_ReductionMode_CreateInfo                            = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO                             ,
			PhysicalDevice_VulkanMemoryModelFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES                   ,
			PhysicalDevice_ImagelessFramebufferFeatures                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES                 ,
			FramebufferAttachments_CreateInfo                           = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO                            ,   
			FramebufferAttachment_ImageInfo                             = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO                              ,
			RenderPassAttachment_BeginInfo                              = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO                              , 
			PhysicalDevice_UniformBuffer_StandardLayoutFeatures         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES        ,
			PhysicalDevice_ShaderSubgroup_ExtendedTypesFeatures         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES        ,
			PhysicalDevice_SeparateDepthStencilLayout_Features          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES        ,
			AttachmentReference_StencilLayout                           = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT                            ,
			AttachmentDescription_StencilLayout                         = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT                          ,
			PhysicalDevice_HostQueryReset_Features                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES                      ,
			PhysicalDevice_TimelineSemaphore_Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES                    ,
			PhysicalDevice_TimelineSemaphore_Properties                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES                  ,
			SemaphoreType_CreateInfo                                    = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO                                     ,
			TimelineSemaphore_SubmitInfo                                = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO                                 ,
			Semaphore_WaitInfo                                          = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO                                            ,
			Semaphore_SignalInfo                                        = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO                                          ,
			PhysicalDevice_BufferDeviceAddress_Features                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES                 ,      
			BufferDeviceAddress_Info                                    = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO                                     ,
			Buffer_OpaqueCaptureAddress_CreateInfo                      = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO                      ,
			Memory_OpaqueCaptureAddress_AllocateInfo                    = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO                    ,
			DeviceMemory_OpaqueCaptureAddress_Info                      = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO                      ,    
			SwapChain_CreateInfo_KHR                                    = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR                                      ,
			PresentInfo_KHR                                             = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR                                               ,
			DeviceGroup_PrsentCapabilitties_KHR                         = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR                          ,    
			ImageSwapChain_CreateInfo_KHR                               = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR                                ,
			BindImageMemory_SwapChain_Info_KHR                          = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR                           ,
			Acquire_NextImage_Info_KHR                                  = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR                                    ,
			DeviceGroup_PrsentInfo_KHR                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR                                  ,    							   
			DeviceGroup_SwapChain_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR                         ,
			DisplayMode_CreateInfo_KHR                                  = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR                                   ,
			DisplaySurface_CreateInfo_KHR                               = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR                                ,
			DispalyPrsent_Info_KHR                                      = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR                                       ,
			XLIB_Surface_CreateInfo_KHR                                 = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR                                   ,
			XCB_Surface_CreateInfo_KHR                                  = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR                                    ,
			Wayland_Surface_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR                                ,
			Andriod_Surface_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR                                ,
			Win32_Surface_CreateInfo_KHR                                = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR                                  ,
			DebugReport_Callback_CreateInfo_EXT                         = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT                          ,
			PipelineRasterizationState_RasterizationOrder_AMD           = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD           ,
			DebugMarkerObject_NameInfo_EXT                              = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT                              ,
			DebugMarkerObject_TagInfo_EXT                               = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT                               ,
			DebugMarker_MarkerInfo_EXT                                  = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT                                   ,
			DedicatedAllocationImage_CreateInfo_NV                      = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV                      ,
			DedicatedAllocationBuffer_CreateInfo_NV                     = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV                     ,
			DedicatedAllocationMemory_AllocateInfo_NV                   = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV                   ,
			PhysicalDevice_TransformFeedback_Features_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT                ,   
			PhysicalDevice_TransformFeedback_Properties_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT              ,
			PipelineRasterizationStateStream_CrateInfo_EXT              = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT            ,
			ImageView_HandleInfo_NVX                                    = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX                                     ,
			Texture_LOD_GatherFormat_Properties_AMD                     = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD                       ,
			StreamDescriptorSurface_CreateInfo_GGP                      = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP                      ,
			PhysicalDevice_CornerSampledImage_Features_NV               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV               ,
			ExternalMemoryImage_CreateInfo_NV                           = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV                           ,
			ExportMemory_AllocateInfo_NV                                = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV                                 ,   
			ImportMemory_Win32_HandleInfo_NV                            = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV                             ,
			ExportMemory_Win32_HandleInfo_NV                            = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV                             ,
			Win32_KeyedMutex_AquireRelease_Info_NV                      = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV                      ,
			ValidationFlags_EXT                                         = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT                                           ,
			VI_Surface_CreateInfo_NN                                    = VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN                                      ,
			PhysicalDevice_TextureCompression_ASTC_HDR_Features_EXT     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT      ,
			ImageView_ASTC_DecodeMode_EXT                               = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT                                ,
			PhysicalDevice_ASTC_Decode_Features_EXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT                       ,
			ImportMemory_Win32Handle_Info_KHR                           = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR                            ,
			ExportMemory_Win32Handle_Info_KHR                           = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR                            ,
			Memory_Win32Handle_Properties_KHR                           = VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR                             ,
			Memory_Get_Win32Handle_Info_KHR                             = VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR                               ,
			Import_Memory_FD_INFO_KHR                                   = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR                                      ,
			Memory_FD_Properites_KHR                                    = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR                                       ,
			Memory_GET_FD_Info_KHR                                      = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR                                         ,
			Win32_MutexAquireRelease_Info_KHR                           = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR                     ,
			ImportSemaphore_Win32Handle_Info_KHR                        = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR                         ,
			ExportSemaphore_Win32Handle_Info_KHR                        = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR                         ,
			D3D12_Fence_SubmitInfo_KHR                                  = VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR                                    ,
			Semaphore_GetWin32Handle_Info_KHR                           = VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR                            ,
			ImportSemaphore_FD_Info_KHR                                 = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR                                   ,
			Semaphore_Get_FD_Info_KHR                                   = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR                                      ,
			PhysicalDevice_PushDescriptor_Properties_KHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR                 ,
			CommandBuffer_Inheritance_ConditionalRendering_Info_EXT     = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT      ,
			PhysicalDevice_ConditionalRendering_Features_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT             ,
			ConditionalRendering_BeginInfo_EXT                          = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT                           ,
			PresentationRegions_KHR                                     = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR                                            ,
			Pipeline_Viewport_W_ScalingState_CreateInfo_NV              = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV               ,
			SurfaceCapabilitties_2_EXT                                  = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT                                     ,
			DisplayPower_Info_EXT                                       = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT                                         ,
			Device_EventInfo_EXT                                        = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT                                          ,
			Display_EventInfo_EXT                                       = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT                                         ,
			Swapchain_Counter_CreateInfo_EXT                            = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT                              ,
			PresentTimes_Info_Google                                    = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE                                      ,
			PhysicalDevice_MultiviewPerViewAttributes_Properties_NVX    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX   ,
			Pipeline_viewportSwizzleState_CreateInfo_NV                 = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV                 ,
			PhysicalDevice_DiscardRectangle_Properties_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT               ,
			Pipeline_Discard_RectangleState_CreateInfo_EXT              = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT               ,
			PhysicalDevice_ConservativeRasterization_Properties_EXT     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT      ,
			Pipeline_RasterizationConservativeState_CreateInfo_EXT      = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT      ,
			PhysicalDevice_DepthClipEnable_Features_EXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT                 ,
			Pipeline_Rasterization_DepthClipState_CreateInfo_EXT        = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT        ,
			HDR_MetaData_EXT                                            = VK_STRUCTURE_TYPE_HDR_METADATA_EXT                                               ,
			SharedPresentSurfaceCapabilities_KHR                        = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR                        ,
			ImportFence_Win32Handle_Info_KHR                            = VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR                             ,
			ExportFence_Win32Handle_Info_KHR                            = VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR                             ,
			Fence_GetWin32Handle_Info_KHR                               = VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR                                ,
			ImportFence_FD_Info_KHR                                     = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR                                       ,
			Fence_Get_FD_Info_KHR                                       = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR                                          ,
			PhysicalDevice_PerformanceQuery_Features_KHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR                 ,
			PhysicalDevice_PerformanceQuery_Properties_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR               ,
			QueryPool_Performance_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR                         ,
			PerformanceQuery_SubmitInfo_KHR                             = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR                              ,
			AcquireProfilingLock_Info_KHR                               = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR                                ,
			PerformacneCounter_KHR                                      = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR                                        ,
			PerformanceCounter_Description_KHR                          = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR                            ,
			PhysicalDevice_Surface_Info_2_KHR                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR                             ,
			SurfaceCapabilitties_2_KHR                                  = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR                                     ,
			SurfaceFormat_2_KHR                                         = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR                                           ,
			DisplayProperties_2_KHR                                     = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR                                       ,
			DisplayPlaneProperties_2_KHR                                = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR                                 ,
			DisplayModeProperties_2_KHR                                 = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR                                  ,
			DisplayPlane_Info_2_KHR                                     = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR                                       ,
			DisplayPlaneCapabilitties_2_KHR                             = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR                               ,
			Surface_CreateInfo_MVK                                      = VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK                                    ,
			MacOS_Surface_CreateInfo_MVK                                = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK                                  ,
			DebugUtils_ObjectName_Info_EXT                              = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT                               ,
			DebugUtils_ObjectTag_Info_EXT                               = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT                                ,
			DebugUtils_Label_EXT                                        = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT                                          ,
			DebugUtils_MessengerCallback_Data_EXT                       = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT                        ,
			DebugUtils_Messenger_CreateInfo_EXT                         = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT                          ,
			Android_HardwareBufferUsage_Andriod                         = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID                          ,
			Android_HardwareBuffer_Properties_Andrioid                  = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID                     ,
			Android_HardwareBufferFormat_Properties_Android             = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID              ,
			ImportAndroidHardwareBuffer_Info_Android                    = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID                    ,
			Memory_GetAndoridHardwareBuffer_Info_Android                = VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID                ,
			ExternalFormat_Android                                      = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID                                        ,
			PhysicalDevice_InlineUniformBlock_Features_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT              ,
			PhysicalDevice_InlineUniformBlock_Properties_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT            ,
			WriteDescriptor_SetInlineUniformBlock_EXT                   = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT                  ,
			DescriptorPool_InlineUniformBlock_CreateInfo_EXT            = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT           ,
			SampleLocations_Info_EXT                                    = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT                                      ,
			RenderPass_SampleLocations_BeginInfo_EXT                    = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT                    ,
			Pipeline_SampleLocationsState_CreateInfo_EXT                = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT                ,
			PhysicalDevice_SampleLocations_Properties_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT                ,
			Multisample_Properties_EXT                                  = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT                                     ,
			PhyscialDevice_BlendOperation_AdvancedFeatures_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT          ,
			PhysicalDevice_BlendOperationAdvanced_Properties_EXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT        ,
			Pipeline_ColorBlendAdvancedState_CreateInfo_EXT             = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT            ,
			Pipeline_CoverageToColorState_CreateInof_NV                 = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV                ,
			Bind_AccelerationStructureMemory_Info_KHR                   = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_KHR                    ,
			WriteDescriptorSet_AccelerationStruture_KHR                 = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR                ,
			AcclerationStructure_BuildGeometry_Info_KHR                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR                 ,
			AccelerationStructure_CreateGeometryType_Info_KHR           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_GEOMETRY_TYPE_INFO_KHR           ,
			AccelrationStructure_DeviceAddress_Info_KHR                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR                 ,
			AccelerationStructure_GeometryAABBS_Data_KHR                = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR                 ,
			AccelerationStructure_Geometry_Instance_Data_KHR            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR             ,
			AccelerationStructure_GeometryTriangles_Data_KHR            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR             ,
			AccelerationStructure_Geometry_KHR                          = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR                            ,
			//AccelerationStructure_Info_KHR                              = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_KHR                                ,
			AccelerationStructure_MemoryRequirements_Info_KHR           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_KHR            ,
			AccelerationStructure_Version_KHR                           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_KHR                             ,
			Copy_AccelerationStructure_Info_KHR                         = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR                           ,
			CopyAccelerationStructureTOMemory_Info_KHR                  = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR                 ,
			Copy_MemopryToAccelerationStructure_Info_KHR                = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR                 ,
			PhysicalDevice_Raytracing_Features_KHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_FEATURES_KHR                       ,
			PhysicalDevice_Raytracing_Properties_KHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_KHR                     ,
			Raytracing_Pipeline_CreateInfo_KHR                          = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR                           ,
			Raytracing_ShaderGroup_CreateInfo_KHR                       = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR                       ,
			AccelerationStructure_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR                         ,
			Raytracing_PipelineInterface_CreateInfo_KHR                 = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR                 ,
			Pipeline_CoverageModulationState_CreateInfo_NV              = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV              ,
			PhysicalDevice_ShaderSM_Builtins_Features_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV                 ,
			PhyscialDevice_ShaderSM_Builtins_Properties_NV              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV               ,
			DRM_FormatModifier_PropertiesList_EXT                       = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT                        ,
			DRM_FormatModifier_Properties_EXT                           = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT                             ,
			PhysicalDevice_ImageDRM_FormatModifier_Info_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT             ,
			ImageDRM_FomratModifierList_CreateInfo_EXT                  = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT                 ,
			ImageDRM_FormatModifierExplicit_CreateInfo_EXT              = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT             ,
			ImageDRM_FormatModifierProperties_EXT                       = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT                       ,
			ValidationCache_CreateInfo_EXT                              = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT                               ,
			ShaderModule_ValidationCache_CreateInfo_EXT                 = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT                 ,
			Pipeline_viewportShadingRateImageState_CreateInfo_NV        = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV      ,
			PhysicalDevice_ShadingRateImage_Features_NV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV                 ,
			PhysicalDevice_ShaderRateImage_Properties_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV               ,
			Pipeline_ViewportCoarseSampleOrder_State_CreateInfo_NV      = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV     ,
			Raytracing_Pipeline_CreateInfo_NV                           = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV                            ,
			AccelerationStructure_CreateInfo_NV                         = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV                          ,
			Geometry_NV                                                 = VK_STRUCTURE_TYPE_GEOMETRY_NV                                                    ,
			GeometryTriangles_NV                                        = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV                                          ,
			Geometry_AABB_NV                                            = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV                                               ,
			AccelerationStructure_MemoryRequirements_Info_NV            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV             ,
			PhysicalDevice_DeviceRaytracing_Properties_NV               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV                      ,
			Ratracing_ShaderGroup_CreateInfo_NV                         = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV                        ,
			AccelerationStructure_Info_NV                               = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV                                 ,
			PhysicalDevice_RepresentativeFragmentTest_Features_NV       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV       ,
			Pipeline_Representative_FragmentTestState_CreateInfo_NV     = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV     ,
			PhysicalDevice_ImageView_ImgeFormat_Info_EXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT               ,
			FilterCubic_ImageView_ImageFormat_Properties_EXT            = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT            ,
			DeviceQueue_GlobalPriority_CreateInfo_EXT                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT                   ,
			ImportMemory_HostPointer_Info_EXT                           = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT                            ,
			MemoryHost_PointerProperties_EXT                            = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT                             ,
			PhysicalDevice_ExternalMemoryHost_Properites_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT            ,
			PhysicalDevice_ShaderClock_Features_KHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR                      ,
			Pipeline_CompilerControl_CreateInfo_AMD                     = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD                      ,
			Calibrated_Timestamp_Info_EXT                               = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT                                  ,
			PhysicalDevice_ShaderCore_Properties_AMD                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD                     ,
			DeviceMemory_Overallocation_CreateInfo_AMD                  = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD                   ,
			PhysicalDevice_VertexAttributeDivisor_Properties_EXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT        ,
			Pipeline_VertexInput_DivisorState_CreateInfo_EXT            = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT            ,
			PhysicalDevice_VertexAttributeDevisor_Features_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT          ,
			PresentFrameToken_GGP                                       = VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP                                        ,
			Pipeline_CreationFeedback_CreateInfo_EXT                    = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT                     ,
			PhysicalDevice_ComputeShaderDerivatives_Features_NV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV         ,
			PhysicalDevice_MeshShader_Features_NV                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV                        ,
			PhysicalDevice_MeshShader_Properties_NV                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV                      ,
			PhysicalDevice_FragmentShaderBarycentric_Features_NV        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV        ,
			PhysicalDevice_ShaderImageFootprint_Features_NV             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV             ,
			Pipeline_ViewportExclusiveScissorState_CreateInfo_NV        = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV       ,
			PhysicalDevice_ExclusiveScissor_features_NV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV                  ,
			CheckpointData_NV                                           = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV                                             ,
			QueueFamilyCheckpoint_Properties_NV                         = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV                          ,
			PhysicalDevice_ShaderIntegerFunctions_2_Features_Intel      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL      ,
			QueryPool_CreateInfo_Intel                                  = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL                                   ,
			InitializePerformanceAPI_Info_Intel                         = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL                          ,
			PerformanceMarker_Info_Intel                                = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL                                  ,
			PerformanceStreamMarker_info_Intel                          = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL                           ,
			PerformanceOverride_Info_Intel                              = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL                                ,
			PerformanceConfiguration_Aquire_Info_Intel                  = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL                   ,
			PhysicalDevice_PCI_BUS_Info_Properties_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT                    ,
			Display_NativeHDR_SurfaceCapabbilitties_AMD                 = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD                    ,
			SwapChain_DisplayNativeHDR_CreateInfo_AMD                   = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD                   ,
			ImagepipeSurface_CreateInfo_FUCHSIA                         = VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA                          ,
			Metal_Surface_CreateInfo_EXT                                = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT                                  ,
			PhysicalDevice_FragmentDensity_MapFeatures_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT              ,
			PhysicalDevice_FragmentDensityMap_Properties_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT            ,
			RenderPass_FragmentDensityMap_CreateInfo_EXT                = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT               ,
			PhysicalDevice_SubgroupSizeControl_Properties_EXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT           ,
			Pipeline_ShaderStage_RequiredSubgroupSize_CreateInfo_EXT    = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT   ,
			PhysicalDevice_SubgroupSizeControl_Features_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT             ,
			PhysicalDevice_ShaderCore_Properties_2_AMD                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD                   ,
			PhysicalDeice_CoherentMemory_Features_AMD                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD                   ,
			PhysicalDevice_MemoryBudget_Properties_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT                   ,
			PhysicalDevice_MemoryPriority_Features_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT                   ,
			MemoryPriority_AllocateInfo_EXT                             = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT                              ,
			Surface_ProtectedCapabilitties_KHR                          = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR                             ,
			PhysicalDevice_DedicatedAllocationImageAliasing_Features_NV = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV,
			PhysicalDevice_BufferDeviceAddress_Features_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT             ,
			BufferDeviceAddress_CreateInfo_EXT                          = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT                          ,
			PhysicalDevice_ToolProperties_EXT                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT                            ,
			ValidationFeatures_EXT                                      = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT                                        ,
			PhysicalDevice_CooperativeMatrix_Features_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV                 ,
			CooperativeMatrix_Properties_NV                             = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV                               ,
			PhysicalDevice_CooperativeMatrix_Proeprties_NV              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV               ,
			PhysicalDevice_CoverageReductionMode_Features_NV            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV            ,
			Pipeline_CoverageReductionState_CreateInfo_NV               = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV               ,
			Framebufer_MixedSamplesCombination_NV                       = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV                       ,
			PhyscialDevice_FragmentShader_Interlock_Features_EXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT         ,
			PhysicalDevice_YCBCR_ImageArrays_Features_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT                ,
			Surface_FullscreenExclusive_Info_EXT                        = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT                         ,
			Surface_Capabilities_FullscreenExclusive_EXT                = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT                 ,
			Surface_FullscreenExclusive_Win32_Info_EXT                  = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT                   ,
			HeadlessSurface_CreateInfo_EXT                              = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT                               ,
			PhysicalDevice_LineRasterization_Features_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT                ,
			Pipeline_RasterizationLineState_CreateInfo_EXT              = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT              ,
			PhysicalDevice_LineRasterization_Properties_EXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT              ,
			PhysicalDevice_IndexType_Uint8_Features_EXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT                  ,
			DeferredOperation_Info_KHR                                  = VK_STRUCTURE_TYPE_DEFERRED_OPERATION_INFO_KHR                                    ,
			PhysicalDevice_PipelineExecutableProperties_Features_KHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR    ,
			Pipeline_Info_KHR                                           = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR                                              ,
			Pipeline_ExecutableProperties_KHR                           = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR                             ,
			Pipeline_ExecutableInfo_KHR                                 = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR                                   ,
			Pipeline_ExecutableStatistic_KHR                            = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR                              ,
			Pipeline_Executable_InternalRepresentation_KHR              = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR                ,
			PhysicalDevice_ShaderDemoteToHelperInvocationFeatures_EXT   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT,
			PhysicalDevice_DeviceGeneratedCommand_Properties_NV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV        ,
			GraphicsShaderGroup_CreateInfo_NV                           = VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV                           ,
			GraphicsPipeline_ShaderGroups_CreateInfo_NV                 = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV                 ,
			IndirectCommands_LayoutToken_NV                             = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV                              ,
			IndirectCommands_Layout_CreateInfo_NV                       = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV                        ,
			GeneratedCommands_Info_NV                                   = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV                                     ,
			GeneratedCommands_MemoryRequirements_Info_NV                = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV                 ,
			PhysicalDevice_DeviceGeneratedCommand_Features_NV           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV          ,
			PhysicalDevice_TexelBufferAlignment_Features_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT            ,
			PhysicalDevice_TEXELBuffer_AlignmentProperties_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT          ,
			CommandBufferInheritance_RenderPassTransform_Info_QCOM      = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM     ,
			RenderPass_Transform_BeginInfo_QCOM                         = VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM                          ,
			PipelineLibrary_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR                               ,
			PhysicalDevice_PipelineCreationCacheControl_Features_EXT    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT   ,
			PhysicalDevice_DiagnosticsConfig_Features_NV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV                 ,
			DeviceDiagnosticsConfig_CreateInfo_NV                       = VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV                       ,
			PhysicalDevice_VariablePointer_Features                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES                      , 
			PhysicalDevice_ShaderDrawParameter_Features                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES                 ,
			DebugReport_CreateInfo_EXT                                  = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT                                   ,
			RenderPass_Multiview_CreateInfo_KHR                         = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR                          ,
			PhysicalDevice_Multiview_Features_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR                         ,
			PhysicalDevice_multiview_Properties_KHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR                       ,
			PhysicalDevice_Features_2_KHR                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR                                 ,
			PhysicalDevice_Properties_2_KHR                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR                               ,
			FormatProperties_2_KHR                                      = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR                                        ,
			ImageFormat_Properties_2_KHR                                = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR                                  ,
			PhysicalDevice_ImageFormat_Info_2_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR                        ,
			QueueFamily_Properties_2_KHR                                = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR                                  ,
			PhysicalDevice_MemoryProperties_2_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR                        ,
			SpraseImageFormat_Properties_2_KHR                          = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR                           ,
			PhysicalDevice_SparseImageFormat_Info_2_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR                 ,
			MemoryAllocateFlags_Info_KHR                                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR                                 ,
			DeviceGroup_RenderPass_BeginInfo_KHR                        = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR                        ,
			DeviceGroup_CommandBuffer_BeginInfo_KHR                     = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR                     ,
			DeviceGroup_SubmitInfo_KHR                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR                                   ,
			DeviceGroup_BindSparse_Info_KHR                             = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR                              ,
			BindBuffer_MemoryDeviceGroup_Info_KHR                       = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR                       ,
			BindImage_MemoryDeviceGroup_Info_KHR                        = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR                        ,
			PhysicalDeviceGroup_Properties_KHR                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR                           ,
			DeviceGroup_Device_CreateInfo_KHR                           = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR                            ,
			PhysicalDevice_ExternalImageFormat_Inf_KHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR                 ,
			ExternalImageFormat_Properties_KHR                          = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR                           ,
			PhysicalDevice_ExternalBuffer_Info_KHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR                       ,
			ExternalBuffer_Propertis_KHR                                = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR                                 ,
			PhysicalDevice_ID_Properties_KHR                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR                              ,
			ExternalMemory_Buffer_CreateInfo_KHR                        = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR                         ,
			ExternalMemoryImage_CreateInfo_KHR                          = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR                          ,
			Export_MemoryAllocate_Info_KHR                              = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR                                ,
			PhysicalDevice_ExternalSemaphore_Info_KHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR                    ,
			External_Semaphore_Properties_KHR                           = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR                              ,
			Export_Semaphore_CreateInfo_KHR                             = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR                               ,
			PhysicalDevice_Shader_Float16_Int8_Features_KHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES_KHR               ,
			PhysicalDevice_Float16_Int8_Features_KHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR                      ,
			PhysicalDevice_16BitStorage_Features_KHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR                     ,
			Descriptor_UpdateTemplate_CreateInfo_KHR                    = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR                     ,
			Surface_Capabilities_2_EXT                                  = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES2_EXT                                      ,
			PhysicalDevice_Imageless_Framebuffer_Features_KHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR             ,
			Framebuffer_Attachments_CreateInfo_KHR                      = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR                        ,
			Framebuffer_Attachment_ImageInfo_KHR                        = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR                          ,
			RenderPass_Attachment_BeginInfo_KHR                         = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR                          ,
			Attachment_Description_2_KHR                                = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR                                   ,
			Attachment_Reference_2_KHR                                  = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR                                     ,
			Subpass_Description_2_KHR                                   = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR                                      ,
			Subpass_Dependency_2_KHR                                    = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR                                       ,
			RenderPass_CreateInfo_2_KHR                                 = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR                                  ,
			Subpass_BeginInfo_HR                                        = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR                                         ,
			Subpass_EndInfo_KHR                                         = VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR                                           ,
			PhysicalDevice_ExternalFence_Info_KHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR                        ,
			ExternalFence_Properties_KHR                                = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR                                  ,
			ExportFence_CreateInfo_KHR                                  = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR                                   ,
			PhysicalDevice_PointClipping_Properties_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR                  ,
			RenderPass_InputAttachmentAspect_CreateInfo_KHR             = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR            ,
			ImageViewUsage_CreateInfo_KHR                               = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR                               ,
			Pipeline_TessellationDomain_OriginState_CreateInfo_KHR      = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR      ,
			PhysicalDevice_VariablePointer_Features_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR                  ,
			PhysicalDevice_VariablePointers_Features_KHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR                 ,
			MemoryDedicated_Requirements_KHR                            = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR                              ,
			MemoryDedicated_AllocateInfo_KHR                            = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR                             ,
			PhysicalDevice_SamplerFilter_MinMax_Properties_EXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT           ,
			Sampler_ReductionMode_CreateInfo_EXT                        = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT                         ,
			Buffer_MemoryRequirements_Inof_2_KHR                        = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR                          ,
			Image_MemoryRequirements_Info_2_KHR                         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR                           ,
			ImageSparse_MemoryRequirements_Info_2_KHR                   = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR                    ,
			MemoryRequirements_2_KHR                                    = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR                                      ,
			SparseImage_MemoryRequirements_2_KHR                        = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR                         ,
			ImageFormatList_CreateInfo_KHR                              = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR                              ,
			SamplerYCBCR_Conversion_CreateInfo_KHR                      = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR                       ,
			Sampler_YCBCR_ConversionInfo_KHR                            = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR                              ,
			BindImagePlane_MemoryInfo_KHR                               = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR                               ,
			ImagePlane_MemoryRequirements_Info_KHR                      = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR                       ,
			PhysicalDevice_Sampler_YCBCR_Conversion_Features_KHR        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR          ,
			SamplerYCBCR_Conversion_ImageFormat_Properties_KHR          = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR           ,
			Buffer_MemoryInfo_KHR                                       = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR                                    ,
			BindImage_MemoryInfo_KHR                                    = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR                                     ,
			Descriptor_SetLayoutBindingFlags_CreateInfo_EXT             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT            ,
			PhysicalDevice_DescriptorIndexing_Features_EXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT               ,
			PhysicalDevice_Descriptor_IndexingProperties_EXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT             ,
			DescriptorSet_VariableDescriptorCount_AllocateInfo_EXT      = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT     ,
			DescriptorSet_VaraibleDescriptorCount_LayoutSupport_EXT     = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT    ,
			Bind_AccelerationStructure_MemoryInfo_NV                    = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV                     ,
			WriteDescriptorSet_AccelerationStructure_NV                 = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV                 ,
			PhysicalDevice_Maintenance_3_Properties_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR                   ,
			DescriptorSet_LayoutSupport_KHR                             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR                              ,
			PhysicalDevice_ShaderSubgroup_ExtendedTypes_Features_KHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR    ,
			PhysicalDevice_8BitStorage_Features_KHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR                      ,
			PhysicalDevice_Shader_AtomicInt64_Features_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR               ,
			PhysicalDevice_DriverProperties_KHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR                          ,
			PhysicalDevice_FloatControls_Properties_KHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR                  ,
			PhysicalDevice_DepthStencilResolve_Properties_KHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR           ,
			Subpass_Description_DepthStencilResolve_KHR                 = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR                  ,
			PhysicalDevice_TimelineSemaphore_Features_KHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR                ,
			PhysicalDevice_TimelineSemaphoreProperties_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR              ,
			SemaphoreType_CreateInfo_KHR                                = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO_KHR                                 ,
			TimelineSemaphore_SubmitInfo_KHR                            = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR                             ,
			Semaphore_WaitInfo_KHR                                      = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO_KHR                                        ,
			Sempaphore_SignalInfo_KHR                                   = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO_KHR                                      ,
			PhysicalDevice_Vulakn_MemoryModel_Features_KHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR               ,
			PhysicalDevice_ScalarBlock_LayoutFeatures_EXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT               ,
			PhysicalDevice_SeparateDepth_StencilLayouts_Features_KHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR    ,
			AttachmentReference_StencilLayout_KHR                       = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR                        ,
			AttachmentDescription_StencilLayout_KHR                     = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR                      ,
			PhysicalDevice_BufferAddress_Features_EXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT                    ,
			BufferDevice_AddressInfo_EXT                                = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_EXT                                 ,
			Extesnion_ImageStencilUsage_CreateInfo                      = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT                            ,
			PhysicalDevice_UniformBufferStandardLayout_Features_KHR     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR    ,
			PhysicalDevice_BufferDevice_AddressFeatures_KHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR             ,
			BufferDevice_Address_Info                                   = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_KHR                                 ,
			BufferOpaque_CaptureAddress_Createinfo                      = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR                  ,
			MemoryOpaque_CaptureAddressAllocate_Info_KHR                = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR                ,
			DeviceMemory_OpaqueCaptureAddress_Info_KHR                  = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR                  ,
			PhysicalDevice_HostQuery_ResetFeatures_EXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT                  ,

			// Not found... (1.2.141)
			Device_PrivateData_CreateInfo_EXT = 1000295001,	   // VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT,

			Max_Enum                                                    = VK_STRUCTURE_TYPE_MAX_ENUM
		};
		

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubgroupFeatureFlagBits">Specification</a>  */
		enum class ESubgroupFeaturesFlag : uint32
		{
			Basic           = VK_SUBGROUP_FEATURE_BASIC_BIT           ,
			Vote            = VK_SUBGROUP_FEATURE_VOTE_BIT            ,
			Arithemtic      = VK_SUBGROUP_FEATURE_ARITHMETIC_BIT      ,
			Ballot          = VK_SUBGROUP_FEATURE_BALLOT_BIT          ,
			Shuffle         = VK_SUBGROUP_FEATURE_SHUFFLE_BIT         ,
			ShuffleRealtive = VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT,
			Clustered       = VK_SUBGROUP_FEATURE_CLUSTERED_BIT       ,
			Quad            = VK_SUBGROUP_FEATURE_QUAD_BIT            ,

			// Provided by VK_NV_shader_subgroup_partitioned
			Partitioned_NV  =  VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV ,
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassContents">Specification</a>  */
		enum class ESubpassContents : uint32
		{
			Inline                  = VK_SUBPASS_CONTENTS_INLINE                   ,
			SecondaryCommandBuffers = VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDescriptionFlagBits">Specification</a>  */
		enum class ESubpassDescriptionFlag : uint32 {};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceTransformFlagBitsKHR">Specification</a>  */
		enum class ESurfaceTransformFlag : uint32
		{
			Identity                     = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR                    ,
			Rotate_90                    = VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR                   ,
			Rotate_180                   = VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR                  ,
			Rotate_270                   = VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR                  ,
			Horizontal_Mirror            = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR           ,
			Horizontal_Mirror_Rotate_90  = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR ,
			Horizontal_Mirror_Rotate_180 = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR,
			Horizontal_Mirror_Rotate_270 = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR,
			Inherit                      = VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSwapchainCreateFlagBitsKHR">Specification</a>  */
		enum class ESwapchainCreateFlag : uint32
		{
			SplitInstanceBindRegions = VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR ,
			CreateProtected          = VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR                   ,
			CreateMutableFormat      = VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSystemAllocationScope">Specification</a>  */
		enum class ESystemAllocationScope : uint32
		{
			Command  = VK_SYSTEM_ALLOCATION_SCOPE_COMMAND ,
			Object   = VK_SYSTEM_ALLOCATION_SCOPE_OBJECT  ,
			Cache    = VK_SYSTEM_ALLOCATION_SCOPE_CACHE   ,
			Device   = VK_SYSTEM_ALLOCATION_SCOPE_DEVICE  ,
			Instance = VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationCheckEXT">Specification</a>  */
		enum class EValidationCheck : uint32
		{
			All     = VK_VALIDATION_CHECK_ALL_EXT    ,
			Shaders = VK_VALIDATION_CHECK_SHADERS_EXT 
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFeatureEnableEXT">Specification</a>  */
		enum class EValidationFeatureEnable : uint32
		{
			GPU_Assisted                   = VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT                     ,
			GPU_AssistedReserveBindingSlot = VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT,
			BestPractices                  = VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT                   ,
			DebugPrintF                    = VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT 
		};

		/**
		* @details
		* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkVendorId.html">Specification</a> 
		* 
		* @todo Implement.
		*/
		enum class EVendorID : uint32
		{
			VIV      = VK_VENDOR_ID_VIV     ,
			VSI      = VK_VENDOR_ID_VSI     ,
			KAZAN    = VK_VENDOR_ID_KAZAN   ,
			CODEPLAY = VK_VENDOR_ID_CODEPLAY,
			MESA     = VK_VENDOR_ID_MESA    
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkVertexInputRate">Specification</a>  */
		enum class EVertexInputRate : uint32
		{
			Vertex   = VK_VERTEX_INPUT_RATE_VERTEX,
			Instance = VK_VERTEX_INPUT_RATE_INSTANCE
		};
		


		// Bitmask attribute specification

		SpecifyBitmaskable(EAccessFlag                       );
		SpecifyBitmaskable(EAttachmentDescriptionFlag        );
		SpecifyBitmaskable(EBufferCreateFlag                 );
		SpecifyBitmaskable(EBufferUsage                      );
		SpecifyBitmaskable(EColorComponentFlag               );
		SpecifyBitmaskable(ECommandBufferResetFlag           );
		SpecifyBitmaskable(ECommandBufferUsageFlag           );
		SpecifyBitmaskable(ECommandPoolCreateFlag            );
		SpecifyBitmaskable(ECommandPoolResetFlags            );
		SpecifyBitmaskable(ECompositeAlpha                   );
		SpecifyBitmaskable(ECullModeFlag                     );
		SpecifyBitmaskable(EDebugUtilities_MessageSeverity   );
		SpecifyBitmaskable(EDebugUtilities_MessageType       );
		SpecifyBitmaskable(EDependencyFlag                   );
		SpecifyBitmaskable(EDescriptorBindingFlag            );
		SpecifyBitmaskable(EDescriptorPoolCreateFlag         );
		SpecifyBitmaskable(EDescriptorSetLayoutCreateFlag    );
		SpecifyBitmaskable(EDeviceQueueCreateFlag            );
		SpecifyBitmaskable(EDeviceDiagnosticConfigFlag       );
		SpecifyBitmaskable(EExternalFenceHandleTypeFlag      );
		SpecifyBitmaskable(EExternalSemaphoreHandleTypeFlag  );
		SpecifyBitmaskable(EFenceCreateFlag                  );
		SpecifyBitmaskable(EFenceImportFlag                  );
		SpecifyBitmaskable(EFormatFeatureFlag                );
		SpecifyBitmaskable(EFrameBufferCreateFlag            );
		SpecifyBitmaskable(EImageAspect                      );
		SpecifyBitmaskable(EImageCreateFlag                  );
		SpecifyBitmaskable(EImageUsage                       );
		SpecifyBitmaskable(EImageViewCreateFlag              );
		SpecifyBitmaskable(ELogicalDeviceQueueCreateFlag     );
		SpecifyBitmaskable(EMemoryHeapFlag                   );
		SpecifyBitmaskable(EMemoryPropertyFlag               );
		SpecifyBitmaskable(EPerformanceCounterDescriptionFlag);
		SpecifyBitmaskable(EPipelineCacheCreateFlag          );
		SpecifyBitmaskable(EPipelineCreateFlag               );
		SpecifyBitmaskable(EPipelineShaderStageCreateFlag    );
		SpecifyBitmaskable(EPipelineStageFlag                );
		SpecifyBitmaskable(EQueryControlFlags                );
		SpecifyBitmaskable(EQueueFlag                        );
		SpecifyBitmaskable(EQueryPipelineStatisticFlag       );
		SpecifyBitmaskable(EResolveModeFlags                 );
		SpecifyBitmaskable(ESampleCount                      );
		SpecifyBitmaskable(ESamplerCreateFlag                );
		SpecifyBitmaskable(ESemaphoreImportFlag              );
		SpecifyBitmaskable(ESemaphoreWaitFlag                );
		SpecifyBitmaskable(EShaderStageFlag                  );
		SpecifyBitmaskable(ESubpassDescriptionFlag           );
		SpecifyBitmaskable(ESurfaceTransformFlag             );	
		SpecifyBitmaskable(ESwapchainCreateFlag              );
    }
}




/** @file VT_Backend.hpp

@brief Vaulted Thermals: Backend

@details Contains implementation related to library backend.
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V0
	{
		#ifdef VT_Option__Use_STL_Exceptions
			constexpr bool UseSTL_Exceptions = true;
		#else
			constexpr bool UseSTL_exceptions = false;
		#endif

		#ifdef VT_Option__Use_Inline_Hinting
			#define VT_InlineSpecifier inline
		#elif VT_Option__Use_Forced_Inlining
			#ifdef _WIN32
				#define VT_InlineSpecifier __forceinline
			#else
				#define VT_InlineSpecifier 
			#endif
		#else
			#define VT_InlineSpecifier 
		#endif

		/** @brief Determines whether to return an result code for a function based on if STL exceptions are enabled. */
		using ShouldUse_EResult = typename std::conditional<V0::UseSTL_Exceptions, void, EResult>::type;

		template<typename Type>
		/**
		 * @brief A custom dynamic container from the default can be used with specific functionality in the library.
		 * 
		 * @details Have a container that supports the following functions (They are equivalent to those used in std::vector)
		 * 
		 * @todo Add support?
		 */
		class IDynamicArray
		{
		public:
			~IDynamicArray() {};

			virtual void resize(DataSize _size) = NULL;

			virtual Type data() = NULL;

			virtual DataSize size() = NULL;

			virtual Type at(DataSize _index) = NULL;
		};

		/** @struct VKStruct_Base

			@brief Base struct for wrapping Vulkan native C API Structs.

			@details 
		*/
		template<typename VulkanType, EStructureType TemplateSpecifiedStype = EStructureType::Max_Enum>
		struct VKStruct_Base
		{
			/**
			 * @typedef EType
			 * 
			 * @brief Defines the EType enum to the default vkStructureType enum for now.
			 * 
			 * @todo Finish the proper enum...
			 */
			using EType = EStructureType;

			/** @brief Keeps track of the structure type enum for a native vulkan struct (If an enum does not exist Max_Enum is used instead) */
			static constexpr EType STypeEnum = TemplateSpecifiedStype;
			
			/** 
			@typdef VkType 
			
			@brief Keeps record of the struct's inherent vulkan equivalent.
			*/
			using VkType = VulkanType;   

			/*operator VulkanType()
			{
				return *reinterpret_cast<VulkanType*>(this);
			}*/

			/*operator const VulkanType&()
			{
				return *reinterpret_cast<VulkanType*>(this);
			}*/

			operator VulkanType*()
			{
				return reinterpret_cast<VulkanType*>(this);
			}

			operator const VulkanType*() const
			{
				return reinterpret_cast<const VulkanType*>(this);
			}
		};
	}
}




/*****************************************************************//**
 * \file   VT_Types.hpp
 * \brief  Vaulted Thermals: Types
 *********************************************************************/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
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
		struct Offset3D : V0::VKStruct_Base<VkOffset3D>
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
		struct Extent2D : V0::VKStruct_Base<VkExtent2D>
		{
			uint32 Width ;
			uint32 Height;

			bool operator== (const Extent2D& _other)
			{
				return

					Width  == _other.Width &&
					Height == _other.Height 
					? true : false;
			}
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
		struct Rect2D : V0::VKStruct_Base<VkRect2D>
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

		constexpr DeviceSize Description_MaxSize   = VK_MAX_DESCRIPTION_SIZE   ;   ///< Used for DescriptionStr definition.
		constexpr DeviceSize ExtensionName_MaxSize = VK_MAX_EXTENSION_NAME_SIZE;   ///< Used for ExtensionNameStr definition.

		using ExtensionNameStr = char[ExtensionName_MaxSize];   ///< Can hold an extension name.
		using DescrptionStr    = char[Description_MaxSize  ];   ///< Can hold a description string.

		/**
		@}
		 */


		/**
		@defgroup Flags & Bitmasks
		*/

		/**
		@addtogroup Flags & Bitmasks (General)
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
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a>  */
		struct ConformanceVersion : V0::VKStruct_Base<VkConformanceVersion>
		{
			uInt8 Major   ;
			uInt8 Minor   ;
			uInt8 Subminor;
			uInt8 Patch   ;
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
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFormatProperties">Specification</a>  */
		struct FormatProperties : V0::VKStruct_Base<VkFormatProperties>
		{
			FormatFeatureFlags    LinearTilingFeatures;
			FormatFeatureFlags    OptimalTilingFeatures;
			FormatFeatureFlags    BufferFeatures;
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
			EStencilOperation FailOp;
			EStencilOperation FassOp;
			EStencilOperation DepthFailOp;
			ECompareOperation CompareOp;
			uint32            CompareMask;
			uint32            WriteMask;
			uint32            Reference;
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
		};

		constexpr DeviceSize UUID_Size = VK_UUID_SIZE;

		using UUID = unsigned int[UUID_Size];   ///< Universally unique identifier.


		// TODO: Move these later...

		struct Display
		{
			using Handle = VkDisplayKHR;
		};
	}

	namespace V2
	{
		/**
		* @brief Currently hard coded to use STL vector for extensions.
		* 
		* @todo Make the extensions container a template type with enforcement for IDynamicArray.
		*/
		struct LayerAndExtensionProperties
		{
			LayerProperties                  Layer     ;
			std::vector<ExtensionProperties> Extensions;
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




/** 
@file VT_Constants.hpp

@brief Vaulted Thermals: Constants
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace Corridors
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_NULL_HANDLE">Specification</a> .
		 */
		template<typename HandleType>
		constexpr HandleType Null = VK_NULL_HANDLE;

		constexpr DeviceSize MaxMemoryHeaps = VK_MAX_MEMORY_HEAPS;
		constexpr DeviceSize MaxMemoryTypes = VK_MAX_MEMORY_TYPES;

		constexpr DeviceSize QueueFamily_Ignored = VK_QUEUE_FAMILY_IGNORED;

		constexpr uint32 Subpass_External = VK_SUBPASS_EXTERNAL;

		struct QueueMask
		{
			static constexpr uint32 ComputeAsync = 
				uint32(EQueueFlag::Compute ) | 
				uint32(EQueueFlag::Transfer) |
				uint32(EQueueFlag::SparseBinding);

			static constexpr uint32 TransferOnly = uint32(EQueueFlag::Transfer) | uint32(EQueueFlag::SparseBinding);
		};

		struct InstanceExt
		{
			static constexpr RoCStr DebugUtility = VK_EXT_DEBUG_UTILS_EXTENSION_NAME  ;
			static constexpr RoCStr Surface      = VK_KHR_SURFACE_EXTENSION_NAME      ;
			static constexpr RoCStr Win32Surface = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
		};

		struct DeviceExt
		{
			static constexpr RoCStr Swapchain = VK_KHR_SWAPCHAIN_EXTENSION_NAME;	
		};

		struct Layer
		{
			// Utility

			static constexpr RoCStr LunarG_API_Dump   = "VK_LAYER_LUNARG_api_dump";
			static constexpr RoCStr LunarG_Monitor    = "VK_LAYER_LUNARG_monitor";   // Shows FPS on the window.
			static constexpr RoCStr LunarG_Screenshot = "VK_LAYER_LUNARG_screenshot";

			// Validation

			// Deprecated (Fallback 3)

			static constexpr RoCStr LunarG_CoreValidation = "VK_LAYER_LUNARG_core_validation";

			// Deprecated (Fallback 2)

			static constexpr RoCStr LunarG_ParameterValidation = "VK_LAYER_LUNARG_parameter_validation";
			static constexpr RoCStr LunarG_ObjectTracker       = "VK_LAYER_LUNARG_object_tracker"      ;
			static constexpr RoCStr Google_Threading           = "VK_LAYER_GOOGLE_threading"           ;
			static constexpr RoCStr Google_UniqueObjedcts      = "VK_LAYER_GOOGLE_unique_objects"      ;

			// Meta Validation - Deprecated (Fallback 1)

			static constexpr RoCStr LunarG_StandardValidation = "VK_LAYER_LUNARG_standard_validation";
			
			// Default
			static constexpr RoCStr Khronos_Validation = "VK_LAYER_KHRONOS_validation";
		};
	}
}




/**
@file VT_Memory_Backend.hpp

@brief Vaulted Thermals: Memory: Preliminary Definitions

@details
Had to make this as there are definitions used by both application instance and physical device before full definitions done with the logical device.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V0
	{
		/**
		* @brief General memory definitions.
		*/
		struct Memory
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeapFlags">Specification</a>
			 */
			using HeapFlags = Bitmask<EMemoryHeapFlag, VkMemoryHeapFlags>;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryMapFlags">Specification</a>
			*/
			using MapFlags = Bitmask<EUndefined, VkMemoryMapFlags>;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryPropertyFlags">Specification</a> 
			*/
			using PropertyFlags = Bitmask<EMemoryPropertyFlag, VkMemoryPropertyFlags>;

			using FPtr_Allocation                     = PFN_vkAllocationFunction            ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkAllocationFunction">Specification</a> 
			using FPtr_Reallocation                   = PFN_vkReallocationFunction          ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkReallocationFunction">Specification</a> 
			using FPtr_Free                           = PFN_vkFreeFunction                  ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkFreeFunction">Specification</a> 
			using FPtr_InternalAllocationNotification = PFN_vkInternalAllocationNotification;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkInternalAllocationNotification">Specification</a> 
			using FPtr_InternalFreeNotification       = PFN_vkInternalFreeNotification      ;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#PFN_vkInternalFreeNotification">Specification</a> 


			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryAllocateInfo">Specification</a>  */
			struct AllocateInfo : V0::VKStruct_Base<VkMemoryAllocateInfo, EStructureType::MemoryAllocateInfo>
			{
				      EType      SType          ;
				const void*      Next           ;
				      DeviceSize AllocationSize ;
				      uint32     MemoryTypeIndex;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAllocationCallbacks">Specification</a> */
			struct AllocationCallbacks : V0::VKStruct_Base<VkAllocationCallbacks>
			{
				void*                               UserData          ;
				FPtr_Allocation                     Allocation        ;
				FPtr_Reallocation                   Reallocation      ;
				FPtr_Free                           Free              ;
				FPtr_InternalAllocationNotification InternalAllocation;
				FPtr_InternalFreeNotification       InternalFree      ;
			};

			static constexpr AllocationCallbacks* DefaultAllocator = nullptr;

			/**
			 * @brief Global memory barriers apply to memory accesses involving all memory objects that exist at the time of its execution..
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryBarrier">Specification</a> 
			 */
			struct Barrier : V0::VKStruct_Base<VkMemoryBarrier, EStructureType::Memory_Barrier>
			{
				      EType       SType        ;
				const void*       Next         ;
				      AccessFlags SrcAccessMask;
				      AccessFlags DstAccessMask;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryHeap">Specification</a> 
			 */
			struct Heap : V0::VKStruct_Base<VkMemoryHeap>
			{
				DeviceSize Size ;
				HeapFlags  Flags;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryRequirements">Specification</a> 
			 */
			struct Requirements : V0::VKStruct_Base<VkMemoryRequirements>
			{
				DeviceSize Size          ;
				DeviceSize Alignment     ;
				uint32     MemoryTypeBits;
			};

			/**
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkMemoryType ">Specification</a> 
			 */
			struct Type : V0::VKStruct_Base<VkMemoryType>
			{
				PropertyFlags PropertyFlags;
				uint32        HeapIndex    ;
			};
		};
	}
}




/** @file VT_PhysicalDevice.hpp

@brief VaultedThermals: Physical Device

@details
A physical device usually represents a single complete implementation of Vulkan 
(excluding instance-level functionality) available to the host, of which there are a finite number. 


<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		@brief Represents a physical device.
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
		 */
		struct PhysicalDevice
		{
			using Memory = V0::Memory;

			using Handle = VkPhysicalDevice;   ///< <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevice">Specification</a> 

			static constexpr DeviceSize MaxNameSize        = VK_MAX_PHYSICAL_DEVICE_NAME_SIZE;
			static constexpr DeviceSize MaxDeviceGroupSize = VK_MAX_DEVICE_GROUP_SIZE        ;

			static constexpr DeviceSize MaxDriverNameSize = VK_MAX_DRIVER_NAME_SIZE;
			static constexpr DeviceSize MaxDriverInfoSize = VK_MAX_DRIVER_INFO_SIZE;

			using NameStr = char[MaxNameSize];

			using DriverNameStr = char[MaxDriverNameSize];
			using DriverInfoStr = char[MaxDriverInfoSize];

		    using EDeviceType = EPhysicalDeviceType;	

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkConformanceVersion">Specification</a> 
			*/
			struct ConformanceVersion : V0::VKStruct_Base<VkConformanceVersion>
			{
				uInt8 Major   ;
				uInt8 Minor   ;
				uInt8 Subminor;
				uInt8 Patch   ;
			};

			/**
			@brief Structure describing the fine-grained features that can be supported by an implementation.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceFeatures">Specification</a> 
			*/
			struct Features : V0::VKStruct_Base<VkPhysicalDeviceFeatures>
			{
				Bool RobustBufferAccess                     ;   ///< Out of bounds buffer accesses are well defined.
				Bool FullDrawIndexUint32                    ;   ///< full 32-bit range of indices are supported for indexed draw calls using VK_INDEX_TYPE_UINT32.
				Bool ImageCubeArray                         ;
				Bool IndependentBlend                       ;
				Bool GeometryShader                         ;
				Bool TessellationShader                     ;
				Bool SampleRateShading                      ;
				Bool DualSrcBlend                           ;
				Bool LogicOperations                        ;
				Bool MultiDrawIndirect                      ;
				Bool drawIndirectFirstInstance              ;
				Bool DepthClamping                          ;
				Bool DepthBiasClamping                      ;
				Bool NonSolidFillModes                      ;   ///< Point and wireframe fill modes are supported.
				Bool DepthBounds                            ;   ///< Depth bounds test supported.
				Bool WideLines                              ;
				Bool LargePoints                            ;
				Bool AlphaToOne                             ;   ///< The implementation can replace the alpha value of the color fragment output to the maximum representable alpha value for fixed - point colors or 1.0 for floating - point colors.
				Bool MultiViewport                          ;   ///< Multiple viewports are supported. (VR)
				Bool SamplerAnisotropy                      ;
				Bool TextureCompressionETC2                 ;
				Bool TextureCompressionASTC_LDR             ;
				Bool TextureCompressionBC                   ;
				Bool OcclusionQueryPrecise                  ;
				Bool PipelineStatisticsQuery                ;
				Bool VertexPipelineStoresAndAtomics         ;
				Bool FragmentStoresAndAtomics               ;
				Bool ShaderTessellationAndGeometryPointSize ;
				Bool ShaderImageGatherExtended              ;
				Bool ShaderStorageImageExtendedFormats      ;
				Bool ShaderStorageImageMultisample          ;
				Bool ShaderStorageImageReadWithoutFormat    ;
				Bool ShaderStorageImageWriteWithoutFormat   ;
				Bool ShaderUniformBufferArrayDynamicIndexing;
				Bool ShaderSampledImageArrayDynamicIndexing ;
				Bool ShaderStorageBufferArrayDynamicIndexing;
				Bool ShaderStorageImageArrayDynamicIndexing ;
				Bool ShaderClipDistance                     ;
				Bool ShaderCullDistance                     ;
				Bool ShaderFloat64                          ;
				Bool ShaderInt64                            ;
				Bool ShaderInt16                            ;
				Bool ShaderResourceResidency                ;
				Bool ShaderResourceMinLod                   ;
				Bool SparseBinding                          ;
				Bool SparseResidencyBuffer                  ;
				Bool SparseResidencyImage2D                 ;
				Bool SparseResidencyImage3D                 ;
				Bool SparseResidency2Samples                ;
				Bool SparseResidency4Samples                ;
				Bool SparseResidency8Samples                ;
				Bool SparseResidency16Samples               ;
				Bool SparseResidencyAliased                 ;
				Bool VariableMultisampleRate                ;
				Bool InheritedQueries                       ;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceGroupProperties ">Specification</a> 
			*/
			struct Group : V0::VKStruct_Base<VkPhysicalDeviceGroupProperties, EStructureType::PhysicalDevice_GroupProperties>
			{
				using DeviceListing = Handle[MaxDeviceGroupSize];

				EType         SType              ;
				void*         Next               ;
				uint32        PhysicalDeviceCount;
				DeviceListing PhysicalDevices    ;
				Bool          SubsetAllocation   ;
			};

			/**
			@brief Structure reporting implementation-dependent physical device limits.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceLimits">Specification</a> 
			*/
			struct Limits : V0::VKStruct_Base<VkPhysicalDeviceLimits>
			{
				uint32           MaxImageDimension1D                            ;
				uint32           MaxImageDimension2D                            ;
				uint32           MaxImageDimension3D                            ;
				uint32           MaxImageDimensionCube                          ;
				uint32           MaxImageArrayLayers                            ;
				uint32           MaxTexelBufferElements                         ;
				uint32           MaxUniformBufferRange                          ;
				uint32           MaxStorageBufferRange                          ;
				uint32           MaxPushConstantsSize                           ;
				uint32           MaxMemoryAllocationCount                       ;
				uint32           MaxSamplerAllocationCount                      ;
				DeviceSize       BufferImageGranularity                         ;
				DeviceSize       SparseAddressSpaceSize                         ;
				uint32           MaxBoundDescriptorSets                         ;
				uint32           MaxPerStageDescriptorSamplers                  ;
				uint32           MaxPerStageDescriptorUniformBuffers            ;
				uint32           MaxPerStageDescriptorStorageBuffers            ;
				uint32           MaxPerStageDescriptorSampledImages             ;
				uint32           MaxPerStageDescriptorStorageImages             ;
				uint32           MaxPerStageDescriptorInputAttachments          ;
				uint32           MaxPerStageResources                           ;
				uint32           MaxDescriptorSetSamplers                       ;
				uint32           MaxDescriptorSetUniformBuffers                 ;
				uint32           MaxDescriptorSetUniformBuffersDynamic          ;
				uint32           MaxDescriptorSetStorageBuffers                 ;
				uint32           MaxDescriptorSetStorageBuffersDynamic          ;
				uint32           MaxDescriptorSetSampledImages                  ;
				uint32           MaxDescriptorSetStorageImages                  ;
				uint32           MaxDescriptorSetInputAttachments               ;
				uint32           MaxVertexInputAttributes                       ;
				uint32           MaxVertexInputBindings                         ;
				uint32           MaxVertexInputAttributeOffset                  ;
				uint32           MaxVertexInputBindingStride                    ;
				uint32           MaxVertexOutputComponents                      ;
				uint32           MaxTessellationGenerationLevel                 ;
				uint32           MaxTessellationPatchSize                       ;
				uint32           MaxTessellationControlPerVertexInputComponents ;
				uint32           MaxTessellationControlPerVertexOutputComponents;
				uint32           MaxTessellationControlPerPatchOutputComponents ;
				uint32           MaxTessellationControlTotalOutputComponents    ;
				uint32           MaxTessellationEvaluationInputComponents       ;
				uint32           MaxTessellationEvaluationOutputComponents      ;
				uint32           MaxGeometryShaderInvocations                   ;
				uint32           MaxGeometryInputComponents                     ;
				uint32           MaxGeometryOutputComponents                    ;
				uint32           MaxGeometryOutputVertices                      ;
				uint32           MaxGeometryTotalOutputComponents               ;
				uint32           MaxFragmentInputComponents                     ;
				uint32           MaxFragmentOutputAttachments                   ;
				uint32           MaxFragmentDualSrcAttachments                  ;
				uint32           MaxFragmentCombinedOutputResources             ;
				uint32           MaxComputeSharedMemorySize                     ;
				uint32           MaxComputeWorkGroupCount[3]                    ;
				uint32           MaxComputeWorkGroupInvocations                 ;
				uint32           MaxComputeWorkGroupSize[3]                     ;
				uint32           SubPixelPrecisionBits                          ;
				uint32           SubTexelPrecisionBits                          ;
				uint32           MipmapPrecisionBits                            ;
				uint32           MaxDrawIndexedIndexValue                       ;
				uint32           MaxDrawIndirectCount                           ;
				float32          MaxSamplerLodBias                              ;
				float32          MaxSamplerAnisotropy                           ;
				uint32           MaxViewports                                   ;
				uint32           MaxViewportDimensions[2]                       ;
				float32          ViewportBoundsRange[2]                         ;
				uint32           ViewportSubPixelBits                           ;
				size_t           MinMemoryMapAlignment                          ;
				DeviceSize       MinTexelBufferOffsetAlignment                  ;
				DeviceSize       MinUniformBufferOffsetAlignment                ;
				DeviceSize       MinStorageBufferOffsetAlignment                ;
				sint32           MinTexelOffset                                 ;
				uint32           MaxTexelOffset                                 ;
				sint32           MinTexelGatherOffset                           ;
				uint32           MaxTexelGatherOffset                           ;
				float32          MinInterpolationOffset                         ;
				float32          MaxInterpolationOffset                         ;
				uint32           SubPixelInterpolationOffsetBits                ;
				uint32           MaxFramebufferWidth                            ;
				uint32           MaxFramebufferHeight                           ;
				uint32           MaxFramebufferLayers                           ;
				SampleCountFlags FramebufferColorSampleCounts                   ;
				SampleCountFlags FramebufferDepthSampleCounts                   ;
				SampleCountFlags FramebufferStencilSampleCounts                 ;			    
				SampleCountFlags FramebufferNoAttachmentsSampleCounts           ;
				uint32           MaxColorAttachments                            ;
				SampleCountFlags SampledImageColorSampleCounts                  ;
				SampleCountFlags SampledImageIntegerSampleCounts                ;
				SampleCountFlags SampledImageDepthSampleCounts                  ;
				SampleCountFlags SampledImageStencilSampleCounts                ;
				SampleCountFlags StorageImageSampleCounts                       ;
				uint32           MaxSampleMaskWords                             ;
				Bool             TimestampComputeAndGraphics                    ;
				float32          TimestampPeriod                                ;
				uint32           MaxClipDistances                               ;
				uint32           MaxCullDistances                               ;
				uint32           MaxCombinedClipAndCullDistances                ;
				uint32           DiscreteQueuePriorities                        ;
				float32          PointSizeRange[2]                              ;
				float32          LineWidthRange[2]                              ;
				float32          PointSizeGranularity                           ;
				float32          LineWidthGranularity                           ;
				Bool             StrictLines                                    ;
				Bool             StandardSampleLocations                        ;
				DeviceSize       OptimalBufferCopyOffsetAlignment               ;
				DeviceSize       OptimalBufferCopyRowPitchAlignment             ;
				DeviceSize       NonCoherentAtomSize                            ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceMemoryProperties">Specification</a> 
			 */
			struct MemoryProperties : V0::VKStruct_Base<VkPhysicalDeviceMemoryProperties>
			{
				uint32       TypeCount            ;
				Memory::Type Types[MaxMemoryTypes];
				uint32       HeapCount            ;
				Memory::Heap Heaps[MaxMemoryHeaps];
			};

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterKHR">Specification</a> 
			*/
			struct PerformanceCounter : V0::VKStruct_Base<VkPerformanceCounterKHR, EStructureType::PerformacneCounter_KHR>
			{
				      EType                      SType      ;
				const void*                      Next       ;
				      EPerformanceCounterUnit    Unit       ;
				      EPerformanceCounterScope   Scope      ;
				      EPerformanceCounterStorage Storage    ;
				      UUID                       CounterUUID;


				using DescriptionFlags = Bitmask<EPerformanceCounterDescriptionFlag, VkPerformanceCounterDescriptionFlagsKHR>;

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceCounterDescriptionKHR">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Description : V0::VKStruct_Base<VkPerformanceCounterDescriptionKHR>
				{
					      EType            SType      ;
					const void*            Next       ;
					      DescriptionFlags Flags      ;
					      DescrptionStr    Name       ;
					      DescrptionStr    Category   ;
					      DescrptionStr    Description;
				};
			};

			/**
			@brief Structure specifying various sparse related properties of the physical device.

			@details
			Some features of the implementation are not possible to disable, and are reported to allow applications 
			to alter their sparse resource usage accordingly. These read-only capabilities are reported in the 
			VkPhysicalDeviceProperties::sparseProperties member, which is a structure of type VkPhysicalDeviceSparseProperties.
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#sparsememory-physicalprops">Specification</a> 
			*/
			struct SparseMemoryProperties : V0::VKStruct_Base<VkPhysicalDeviceSparseProperties>
			{
				Bool ResidencyStandard2DBlockShape           ;
				Bool ResidencyStandard2DMultisampleBlockShape;
				Bool ResidencyStandard3DBlockShape           ;
				Bool ResidencyAlignedMipSize                 ;
				Bool ResidencyNonResidentStrict              ;
			};

			/**
			@brief Container of query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties">Specification</a> 
			*/
			struct Properties : V0::VKStruct_Base<VkPhysicalDeviceProperties>
			{
				uint32                 API_Version      ;
				uint32                 DriverVersion    ;
				uint32                 VenderID         ;
				uint32                 ID               ;
				EDeviceType            Type             ;
				NameStr                Name             ;
				UUID                   PipelineCacheUUID;
				Limits                 LimitsSpec       ;
				SparseMemoryProperties SpareProperties  ;

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties">Specification</a> 
				*/
				struct DeviceID : V0::VKStruct_Base<VkPhysicalDeviceIDProperties >
				{
					EType  SType          ;
					void*  Next           ;
					UUID   DeviceUUID     ;
					UUID   DriverUUID     ;
					UUID   DeviceLUID     ;
					uint32 DeviceNodeMask ;
					Bool   DeviceLUIDValid;
				};	

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevicePCIBusInfoPropertiesEXT">Specification</a> 
				*/
				struct PCIBusInfo : V0::VKStruct_Base<VkPhysicalDevicePCIBusInfoPropertiesEXT, EStructureType::PhysicalDevice_PCI_BUS_Info_Properties_EXT>
				{
					EType  SType   ;
					void*  Next    ;
					uint32 Domain  ;
					uint32 Bus     ;
					uint32 Device  ;
					uint32 Function;
				};

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceVulkan11Properties">Specification</a> 
				*/
				struct Vulkan11 : V0::VKStruct_Base<VkPhysicalDeviceVulkan11Properties, EStructureType::PhysicalDevice_Vulkan_1_1_Properties>
				{
					using ShaderStageFlags = Bitmask<EShaderStageFlag, VkShaderStageFlags>;

					EType                  SType                            ;
					void*                  Next                             ;
					UUID                   DeviceUUID                       ;
					UUID                   DriverUUID                       ;
					UUID                   DeviceLUID                       ;
					uint32                 DeviceNodeMask                   ;
					Bool                   DeviceLUIDValid                  ;
					uint32                 SubgroupSize                     ;
					ShaderStageFlags       SubgroupSupportedStages          ;
					ESubgroupFeaturesFlag  SubgroupSupportedOperations      ;
					Bool                   SubgroupQuadOperationsInAllStages;
					EPointClippingBehavior PointClippingBehavior            ;
					uint32                 MaxMultiviewViewCount            ;
					uint32                 MaxMultiviewInstanceIndex        ;
					Bool                   ProtectedNoFault                 ;
					uint32                 MaxPerSetDescriptors             ;
					DeviceSize             MaxMemoryAllocationSize          ;
				};

				/**
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceVulkan12Properties">Specification</a> 
				*  
				* @todo Implement.
				*/
				struct Vulkan12 : V0::VKStruct_Base<VkPhysicalDeviceVulkan12Properties, EStructureType::PhysicalDevice_Vulkan_1_2_Properties>
				{
					EType                           SType                                               ;
					void*                           Next                                                ;
					EDriverID                       DriverID                                            ;
					DriverNameStr                   DriverName                                          ;
					DriverInfoStr                   DriverInfo                                          ;
					ConformanceVersion              ConformanceVersion                                  ;
					EShaderFloatControlIndependence DenormBehaviorIndependence                          ;
					EShaderFloatControlIndependence RoundingModeIndependence                            ;
					Bool                            ShaderSignedZeroInfNanPreserveFloat16               ;
					Bool                            ShaderSignedZeroInfNanPreserveFloat32               ;
					Bool                            ShaderSignedZeroInfNanPreserveFloat64               ;
					Bool                            ShaderDenormPreserveFloat16                         ;
					Bool                            ShaderDenormPreserveFloat32                         ;
					Bool                            ShaderDenormPreserveFloat64                         ;
					Bool                            ShaderDenormFlushToZeroFloat16                      ;
					Bool                            ShaderDenormFlushToZeroFloat32                      ;
					Bool                            ShaderDenormFlushToZeroFloat64                      ;
					Bool                            ShaderRoundingModeRTEFloat16                        ;
					Bool                            ShaderRoundingModeRTEFloat32                        ;
					Bool                            ShaderRoundingModeRTEFloat64                        ;
					Bool                            ShaderRoundingModeRTZFloat16                        ;
					Bool                            ShaderRoundingModeRTZFloat32                        ;
					Bool                            ShaderRoundingModeRTZFloat64                        ;
					uint32                          MaxUpdateAfterBindDescriptorsInAllPools             ;
					Bool                            ShaderUniformBufferArrayNonUniformIndexingNative    ;
					Bool                            ShaderSampledImageArrayNonUniformIndexingNative     ;
					Bool                            ShaderStorageBufferArrayNonUniformIndexingNative    ;
					Bool                            ShaderStorageImageArrayNonUniformIndexingNative     ;
					Bool                            ShaderInputAttachmentArrayNonUniformIndexingNative  ;
					Bool                            RobustBufferAccessUpdateAfterBind                   ;
					Bool                            QuadDivergentImplicitLod                            ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindSamplers        ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindUniformBuffers  ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindStorageBuffers  ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindSampledImages   ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindStorageImages   ;
					uint32                          MaxPerStageDescriptorUpdateAfterBindInputAttachments;
					uint32                          MaxPerStageUpdateAfterBindResources                 ;
					uint32                          MaxDescriptorSetUpdateAfterBindSamplers             ;
					uint32                          MaxDescriptorSetUpdateAfterBindUniformBuffers       ;
					uint32                          MaxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
					uint32                          MaxDescriptorSetUpdateAfterBindStorageBuffers       ;
					uint32                          MaxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
					uint32                          MaxDescriptorSetUpdateAfterBindSampledImages        ;
					uint32                          MaxDescriptorSetUpdateAfterBindStorageImages        ;
					uint32                          MaxDescriptorSetUpdateAfterBindInputAttachments     ;
					ResolveModeFlags                SupportedDepthResolveModes                          ;
					ResolveModeFlags                SupportedStencilResolveModes                        ;
					Bool                            IndependentResolveNone                              ;
					Bool                            IndependentResolve                                  ;
					Bool                            FilterMinmaxSingleComponentFormats                  ;
					Bool                            FilterMinmaxImageComponentMapping                   ;
					uInt64                          MaxTimelineSemaphoreValueDifference                 ;
					SampleCountFlags                FramebufferIntegerColorSampleCounts                 ;
				};
			};

			/**
			 * @brief.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDeviceProperties2">Specification</a> 
			 */
			struct Properties2 : V0::VKStruct_Base<VkPhysicalDeviceProperties2, EStructureType::PhysicalDevice_Properties_2>
			{
				EType      SType     ;
				void*      Next      ;
				Properties Properties;
			};

			/**
			@brief A set of queues that have common properties and support the same functionality.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties">Specification</a> 
			*/
			struct QueueFamilyProperties : V0::VKStruct_Base<VkQueueFamilyProperties>
			{
				/**
				* @brief Bitmask specifying capabilities of queues in a queue family.     
				* 
				* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFlags">Specification</a> 
				*/
				using Flags = Bitmask<EQueueFlag , VkQueueFlags>;

				Flags    QueueFlags                 ;
				uint32   QueueCount                 ;
				uint32   TimestampValidBits         ;
				Extent3D MinImageTransferGranularity;				
			};

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyProperties2">Specification</a> 
			*/
			struct QueueFamilyProperties2 : V0::VKStruct_Base<VkQueueFamilyProperties2, EStructureType::QueueFamily_Properties_2>
			{
				EType                 SType     ;
				void*                 Next      ;
				QueueFamilyProperties Properties;

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueueFamilyCheckpointPropertiesNV">Specification</a> 
				*/
				struct Checkpoint : V0::VKStruct_Base<VkQueueFamilyCheckpointPropertiesNV, EStructureType::QueueFamilyCheckpoint_Properties_NV>
				{
					using Pipeline_StageFlags = Bitmask<EPipelineStageFlag, VkPipelineStageFlags>;   ///< Not defined yet. (See VT_Pipelines.hpp)

					EType               SType                       ;
					void*               Next                        ;
					Pipeline_StageFlags CheckpointExecutionStageMask;
				};
			};

			/**
			@brief Query supported features. Reports capabilities of a physical device.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFeatures">Specification</a> 
			*/
			static void GetFeatures(Handle _handle, Features& _features)
			{
				vkGetPhysicalDeviceFeatures(_handle, _features.operator VkPhysicalDeviceFeatures*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceFormatProperties">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _format
			 * \param _properties
			 */
			static void GetFormatProperties(Handle _handle, EFormat _format, FormatProperties& _properties)
			{
				vkGetPhysicalDeviceFormatProperties(_handle, VkFormat(_format), _properties);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceMemoryProperties">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _properties
			 */
			static void GetMemoryProperties(Handle _handle, MemoryProperties& _properties)
			{
				vkGetPhysicalDeviceMemoryProperties(_handle, _properties);
			}

			/**
			@brief Query general properties of physical devices once enumerated.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties">Specification</a> 
			*/
			static void GetProperties(Handle _handle, Properties& _properties)
			{
				vkGetPhysicalDeviceProperties(_handle, _properties.operator VkPhysicalDeviceProperties*());
			}

			/**
			 * @brief Query general properties of physical devices once enumerated (Second Ver).
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceProperties2">Specification</a> 
			 */
			static void GetProperties2
			(
				Handle       _handle    ,
				Properties2& _properties
			)
			{
				vkGetPhysicalDeviceProperties2(_handle, _properties);
			}

			/**
			@brief Device extensions add new device-level functionality to the API, outside of the core specification.

			@details
			Query the extensions available to a given physical device.

			When pLayerName parameter is NULL, only extensions provided by the Vulkan implementation or by implicitly enabled layers are returned. 
			When pLayerName is the name of a layer, the device extensions provided by that layer are returned.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_device_extensions">Specification</a> 
			*/
			static EResult QueryExtensionProperties(Handle _handle, RoCStr _layerName, uint32* _numExtensions, ExtensionProperties* _extensionPropertiesContainer)
			{
				return EResult(vkEnumerateDeviceExtensionProperties(_handle, _layerName, _numExtensions, _extensionPropertiesContainer->operator VkExtensionProperties*()));
			}

			/**
			@brief Query properties of queues available on a physical device. Reports properties of the queues of the specified physical device.

			@details
			If pQueueFamilyProperties is NULL, then the number of queue families available is returned in pQueueFamilyPropertyCount. 
			Implementations must support at least one queue family. Otherwise, pQueueFamilyPropertyCount must point to a variable set 
			by the user to the number of elements in the pQueueFamilyProperties array, and on return the variable is overwritten 
			with the number of structures actually written to pQueueFamilyProperties.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties">Specification</a> 
			*/
			static void QueryQueueFamilyProperties(Handle _handle, uint32* _numQueueFamilies, QueueFamilyProperties* _queueFamilies)
			{
				vkGetPhysicalDeviceQueueFamilyProperties(_handle, _numQueueFamilies, _queueFamilies->operator VkQueueFamilyProperties*());
			}	

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceQueueFamilyProperties2">Specification</a> 
			*/
			static void QueryQueueFamilyProperties2
			(
				Handle                  _handle       ,
				uint32*                 _numProperties,
				QueueFamilyProperties2* _properties
			)
			{
				vkGetPhysicalDeviceQueueFamilyProperties2(_handle, _numProperties, _properties->operator VkQueueFamilyProperties2*());
			}

			/**
			* @brief.
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR">Specification</a> 
			*/
			static EResult QueryPerfomranceQueryCounters
			(
				Handle                           _handle             ,
				uint32                           _queueFamilyIndex   ,
				uint32*                          _numCounters        ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			)
			{
				return EResult(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
				(
					_handle,
					_queueFamilyIndex,
					_numCounters,
					_counters->operator VkPerformanceCounterKHR*(),
					_counterDescriptions->operator VkPerformanceCounterDescriptionKHR*()
				));
			}
		};
	}

	namespace V2
	{
		using V1::ExtensionProperties;

		/**
		@brief Represents a physical device.
		*/
		struct PhysicalDevice : V1::PhysicalDevice
		{
			using Parent = V1::PhysicalDevice;

			struct Group : public Parent::Group
			{
				Group()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct PerformanceCounter : public Parent::PerformanceCounter
			{
				PerformanceCounter()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct Description : public Parent::PerformanceCounter::Description
				{
					Description()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Properties : public Parent::Properties
			{
				struct DeviceID : public Parent::Properties::DeviceID
				{
					DeviceID()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct PCIBusInfo : public Parent::Properties::PCIBusInfo
				{
					PCIBusInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct Vulkan11 : public Parent::Properties::Vulkan11
				{
					Vulkan11()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct Vulkan12 : public Parent::Properties::Vulkan12
				{
					Vulkan12()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Properties2 : public Parent::Properties2
			{
				Properties2()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct QueueFamilyProperties2 : public Parent::QueueFamilyProperties2
			{
				QueueFamilyProperties2()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct Checkpoint : public Parent::QueueFamilyProperties2::Checkpoint
				{
					Checkpoint()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			/**
			* @brief Checks to see if the specified extensions are supported by the physical device.
			* 
			* @todo make the extensions specified container generic using an interface.
			*/
			static bool CheckExtensionSupport(Handle _handle, RoCStr _extensionSpecified)
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableLayerExtensions(_handle, nullptr, availableExtensions);

				bool isSupported = false;

				for (const auto& extension : availableExtensions)
				{
					if (strcmp(extension.ExtensionName, _extensionSpecified) == 0)
					{
						isSupported = true;
					}
				}

				return isSupported;
			}

			/**
			 * @brief Checks to see if the specified extensions are supported by the physical device.
			 * 
			 * @todo make the extensions specified container generic using an interface.
			 */
			static bool CheckExtensionSupport(Handle _handle, std::vector<RoCStr> _extensionsSpecified)
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableLayerExtensions(_handle, nullptr, availableExtensions);

				using ExtensionNameSet = std::set<std::string>;

				ExtensionNameSet requiredExtensions(_extensionsSpecified.begin(), _extensionsSpecified.end());

				for (const auto& extension : availableExtensions)
				{
					requiredExtensions.erase(extension.ExtensionName);
				}

				bool isSupported = requiredExtensions.empty();

				return isSupported;
			}

			static EResult FindSupportedFormat(Handle _handle, const std::vector<EFormat>& _canidates, EImageTiling _tiling, FormatFeatureFlags _features, EFormat& _format)
			{
				for (EFormat possibleFormat : _canidates)
				{
					FormatProperties formatProperties;

					Parent::GetFormatProperties(_handle, possibleFormat, formatProperties);

					switch (_tiling)
					{
						case EImageTiling::Linear:
						{
							if (formatProperties.LinearTilingFeatures.HasOrEither(_features))
							{
								_format = possibleFormat;

								return EResult::Success;
							}

							break;
						}
						case EImageTiling::Optimal:
						{
							if (formatProperties.OptimalTilingFeatures.HasOrEither(_features))
							{
								_format = possibleFormat;

								return EResult::Success;
							}

							break;
						}
					}
				}

				return EResult::Error_FormatNotSupported;
			}

			static uint32 FindMemoryType(Handle _handle, uint32 _typeFilter, Memory::PropertyFlags _properties)
			{
				MemoryProperties memProperties;

				GetMemoryProperties(_handle, memProperties);

				for (uint32 index = 0; index < memProperties.TypeCount; index++)
				{
					if
						(
						_typeFilter & (1 << index) &&
						(memProperties.Types[index].PropertyFlags & _properties) == _properties
						)
					{
						return index;
					}
				}

			#ifdef VT_Option__Use_STL_Exceptions
				throw std::runtime_error("Failed to find suitable memory type!");
			#endif
			}

			static EResult GetAvailableLayerExtensions(Handle _handle, RoCStr _layerName, std::vector<ExtensionProperties>& _extensionListing)
			{
				uint32 count;

				EResult returnCode = QueryExtensionProperties(_handle, _layerName, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_extensionListing.resize(count);

				returnCode = QueryExtensionProperties(_handle, _layerName, &count, _extensionListing.data());

				return returnCode;
			}

			/**
			 * @brief Gets all extensions for the known layers that the physical device supports.
			 * 
			 * @details 
			 * Note: The layers and extensions container must have the layer properties member of each element populated
			 * by the application instance.
			 * 
			 * \param _layersAndExtensions
			 * \return 
			 */
			static EResult GetAvailableLayersAndExtensions(Handle _handle, std::vector<LayerAndExtensionProperties>& _layersAndExtensions)
			{
				EResult result;

				for (uint32 index = 0; index < _layersAndExtensions.size(); index++)
				{
					result = GetAvailableLayerExtensions(_handle, _layersAndExtensions[index].Layer.Name, _layersAndExtensions[index].Extensions);

					if (result != EResult::Success) return result;
				}

				return result;
			}

			/**
			* @brief Provides the queue families for the respective device.
			* 
			* \param _device
			* \return 
			*/
			static std::vector<QueueFamilyProperties> GetAvailableQueueFamilies(Handle _handle)
			{
				std::vector<QueueFamilyProperties> queryResult; uint32 count;

				QueryQueueFamilyProperties(_handle, &count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(_handle, &count, queryResult.data());

				return queryResult;
			}

			static ESampleCount GetMaxSampleCount_ColorAndDepth(Handle _handle)
			{
				Properties properties;

				GetProperties(_handle, properties);

				SampleCountFlags counts
				(
					properties.LimitsSpec.FramebufferColorSampleCounts, 
					properties.LimitsSpec.FramebufferDepthSampleCounts
				);

				if (counts.Has(ESampleCount::_64)) return ESampleCount::_64;
				if (counts.Has(ESampleCount::_32)) return ESampleCount::_32;
				if (counts.Has(ESampleCount::_16)) return ESampleCount::_16;
				if (counts.Has(ESampleCount::_8 )) return ESampleCount::_8 ;
				if (counts.Has(ESampleCount::_4 )) return ESampleCount::_4 ;
				if (counts.Has(ESampleCount::_2 )) return ESampleCount::_2 ;

				return ESampleCount::_1;
			}
		};
	}

	namespace V3
	{
		class PhysicalDevice : public V2::PhysicalDevice
		{
		public:

			using Parent = V2::PhysicalDevice;
			
			PhysicalDevice()
			{
				handle = Null<Handle>;
			}

			void AssignHandle(Handle _handle) 
			{ 
				handle = _handle; 

				Parent::GetFeatures        (handle, features        );
				Parent::GetMemoryProperties(handle, memoryProperties);
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties      (handle, properties      );
				Parent::GetProperties2     (handle, properties2     );
			}

			/**
			* @brief Checks to see if the specified extensions are supported by the physical device.
			* 
			* @todo make the extensions specified container generic using an interface.
			*/
			bool CheckExtensionSupport(RoCStr _extensionSpecified) const
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableExtensions(nullptr, availableExtensions);

				bool isSupported = false;

				for (const auto& extension : availableExtensions)
				{
					if (strcmp(extension.ExtensionName, _extensionSpecified) == 0)
					{
						isSupported = true;
					}
				}

				return isSupported;
			}

			/**
			 * @todo make the extensions specified container generic using an interface.
			 * 
			 * \param _handle
			 */
			bool CheckExtensionSupport(std::vector<RoCStr> _extensionsSpecified) const
			{
				std::vector<ExtensionProperties> availableExtensions;

				GetAvailableExtensions(nullptr, availableExtensions);

				using ExtensionNameSet = std::set<std::string>;

				ExtensionNameSet requiredExtensions(_extensionsSpecified.begin(), _extensionsSpecified.end());

				for (const auto& extension : availableExtensions)
				{
					requiredExtensions.erase(extension.ExtensionName);
				}

				bool isSupported = requiredExtensions.empty();

				return isSupported;
			}

			uint32 FindMemoryType(uint32 _typeFilter, Memory::PropertyFlags _properties) const
			{
				for (uint32 index = 0; index < memoryProperties.TypeCount; index++)
				{
					auto flags = memoryProperties.Types[index].PropertyFlags;

					if
					(
						_typeFilter & (1 << index) &&
						(flags & _properties) == _properties
					)
					{
						return index;
					}
				}

			#ifdef VT_Option__Use_STL_Exceptions
				throw std::runtime_error("Failed to find suitable memory type!");
			#endif
			}

			EResult FindSupportedFormat(const std::vector<EFormat>& _canidates, EImageTiling _tiling, FormatFeatureFlags _features, EFormat& _format) const
			{
				return Parent::FindSupportedFormat(handle, _canidates, _tiling, _features, _format);
			}

			EResult GetAvailableExtensions(RoCStr _layerName, std::vector<ExtensionProperties>& _extensionListing) const
			{
				return EResult(Parent::GetAvailableLayerExtensions(handle, _layerName, _extensionListing));
			}

			std::vector<QueueFamilyProperties> GetAvailableQueueFamilies() const
			{
				std::vector<QueueFamilyProperties> queryResult; uint32 count;

				QueryQueueFamilyProperties(&count, nullptr);

				queryResult.resize(count);

				QueryQueueFamilyProperties(&count, queryResult.data());

				return queryResult;
			}

			const Features& GetFeatures() const
			{
				return features;
			}

			FormatProperties GetFormatProperties(EFormat _format) const
			{
				FormatProperties formatProperties;

				Parent::GetFormatProperties(handle, _format, formatProperties);

				return formatProperties;
			}

			Handle GetHandle() const
			{
				return handle;
			}

			ESampleCount GetMaxSampleCount_ColorAndDepth() const
			{
				SampleCountFlags counts
				(
					properties.LimitsSpec.FramebufferColorSampleCounts,
					properties.LimitsSpec.FramebufferDepthSampleCounts
				);

				if (counts.Has(ESampleCount::_64)) return ESampleCount::_64;
				if (counts.Has(ESampleCount::_32)) return ESampleCount::_32;
				if (counts.Has(ESampleCount::_16)) return ESampleCount::_16;
				if (counts.Has(ESampleCount::_8 )) return ESampleCount::_8 ;
				if (counts.Has(ESampleCount::_4 )) return ESampleCount::_4 ;
				if (counts.Has(ESampleCount::_2 )) return ESampleCount::_2 ;

				return ESampleCount::_1;
			}

			const MemoryProperties& GetMemoryProperties() const
			{
				return memoryProperties;
			}

			const Properties& GetProperties() const
			{
				return properties;
			}

			const Properties2& GetProperties2() const
			{
				return properties2;
			}

			EResult QueryExtensionProperties(RoCStr _layerName, uint32* _numExtensions, ExtensionProperties* _extensionPropertiesContainer) const
			{
				return Parent::QueryExtensionProperties(handle, _layerName, _numExtensions, _extensionPropertiesContainer);
			}

			void QueryQueueFamilyProperties(uint32* _numQueueFamilies, QueueFamilyProperties* _queueFamilies) const
			{
				return Parent::QueryQueueFamilyProperties(handle, _numQueueFamilies, _queueFamilies);
			}

			void QueryQueueFamilyProperties2(uint32* _numProperties, QueueFamilyProperties2* _properties) const
			{
				return Parent::QueryQueueFamilyProperties2(handle, _numProperties, _properties);
			}

			EResult QueryPerfomranceQueryCounters
			(
				uint32                           _queueFamilyIndex   ,
				uint32*                          _numCounters        ,
				PerformanceCounter*              _counters           ,
				PerformanceCounter::Description* _counterDescriptions
			) const
			{
				return Parent::QueryPerfomranceQueryCounters(handle, _queueFamilyIndex, _numCounters, _counters, _counterDescriptions);
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle&() const
			{
				return handle;
			}

		protected:

			Handle handle;

			EDeviceType type    ;
			EDriverID   driverID;
			EVendorID   vendorID;

			Features features; 

			MemoryProperties memoryProperties; 

			Properties  properties ;
			Properties2 properties2;
		};
	}
}




/** @file VT_Initialization.hpp

@brief Vaulted Thermals: Initialization

@details
Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization">Initialization Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace Corridors
	{
		/**
		 * @brief Construct an API version number.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VK_MAKE_VERSION">Specification</a> 
		 * 
		 * \param _major
		 * \param _minor
		 * \param _patch
		 * \return 
		 */
		inline uInt32 MakeVersion(uInt32 _major, uInt32 _minor, uInt32 _patch)
		{
			return VK_MAKE_VERSION(_major, _minor, _patch);
		}
	}

	namespace V1
	{
		/**
		@brief An object that manages the represented application process state within the GPU.

		Other Name: Application State Container

		@details
		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.
		
		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Application Instance Specification</a> 
		*/
		struct AppInstance
		{
			using Memory = V0::Memory;

			/**
			 * @brief Opaque handle to an instance object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Specification</a> 
			 */
			using Handle = VkInstance;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateFlags">Specification</a>
			 */
			using CreateFlags = Bitmask<EUndefined, VkInstanceCreateFlags>;

			/**
			@brief 
			A structure that specifies to the Vulkan driver information about an
			application that will run an instance.

			@details
			
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkApplicationInfo">Application Info Specification</a> 
			*/
			struct AppInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::ApplicationInformation>
			{
				      EType        SType        ;
				const void*        Next         ;
				      RoCStr       AppName      ;
				      uint32       AppVersion   ;
				      RoCStr       EngineName   ;
				      uint32       EngineVersion;
				      EAPI_Version API_Version  ;
			};

			/**
			@brief Structure specifying parameters of a newly created instance.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstanceCreateInfo">Create Info Specification</a> 
			*/
			struct CreateInfo : V0::VKStruct_Base<VkInstanceCreateInfo, EStructureType::Instance_CreateInfo>
			{
				      EType                SType                ;
				const void*                Next                 ;
				      CreateFlags          Flags                ;
				const AppInfo*             AppInfo              ;
				      uint32               EnabledLayerCount    ;
				      RoSCtr_roArray_Array EnabledLayerNames    ;
				      uint32               EnabledExtensionCount;
				      RoSCtr_roArray_Array EnabledExtensionNames;
			};

			struct Validation
			{
				/**
				* @brief.
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFeaturesEXT">Specification</a> 
				*/
				struct Features : V0::VKStruct_Base<VkValidationFeaturesEXT, EStructureType::ValidationFeatures_EXT>
				{
					      EType                     SType                         ;
					const void*                     Next                          ;
					      uint32                    EnabledValidationFeatureCount ;
					const EValidationFeatureEnable* EnabledValidationFeatures     ;
					      uint32                    DisabledValidationFeatureCount;
					const EValidationFeatureEnable* DisabledValidationFeatures    ;
				};

				/**
				* @brief.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkValidationFlagsEXT">Specification</a> 
				* 
				* @todo Implement.
				*/
				struct Flags : V0::VKStruct_Base<VkValidationFlagsEXT, EStructureType::ValidationFlags_EXT>
				{
					      EType             SType                       ;
					const void*             Next                        ;
					      uint32            DisabledValidationCheckCount;
					const EValidationCheck* DisabledValidationChecks    ;
				};
			};

			/**
			@brief Create a new Vulkan application instance.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateInstance">Create Instance Specification</a> 
			*/
			static EResult Create
			(
				const CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle&                      _handle
			)
			{
				return EResult(vkCreateInstance( _info, _allocator->operator const VkAllocationCallbacks*(), &_handle));
			}

			/**
			@brief Destroy an application instance of Vulkan.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyInstance">Destroy Instance Specification</a> 
			*/
			static void Destroy(Handle _handle , const Memory::AllocationCallbacks* _callbacks)
			{
				vkDestroyInstance(_handle, _callbacks->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief Query the version of application instance-level functionality supported by the implementation.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceVersion">Specification</a> 
			 * 
			 * \param _versionContainer
			 * \return 
			 */
			static EResult GetVersion(uint32& _versionContainer)
			{
				return EResult(vkEnumerateInstanceVersion(&_versionContainer));
			}

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceLayerProperties">Specification</a>  */
			static EResult QueryAvailableLayers(uint32& _numContainer, LayerProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceLayerProperties(&_numContainer, _propertiesContainer->operator VkLayerProperties * ()));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumerateInstanceExtensionProperties">Specification</a> .
			 */
			static EResult QueryAvailableAppExtensions(RoCStr _layerName, uint32& _numProperties, ExtensionProperties* _propertiesContainer)
			{
				return EResult(vkEnumerateInstanceExtensionProperties(_layerName, &_numProperties, _propertiesContainer->operator VkExtensionProperties*()));
			}

			/**
			@brief Retrieve a list of physical device objects representing the physical devices installed in the system, or get the number of them.

			@details
			If pPhysicalDevices is NULL, then the number of physical devices available is returned in pPhysicalDeviceCount. 
			Otherwise, pPhysicalDeviceCount must point to a variable set by the user to the number of elements in the pPhysicalDevices array, 
			and on return the variable is overwritten with the number of handles actually written to pPhysicalDevices.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-physical-device-enumeration">Specification</a> 
			*/
			static EResult QueryPhysicalDeviceListing(Handle _handle, uint32* _numDevices, PhysicalDevice::Handle* _deviceListing)
			{
				return EResult(vkEnumeratePhysicalDevices(_handle, _numDevices, _deviceListing));
			}

			/**
			* @brief 
			* 
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEnumeratePhysicalDeviceGroups">Specification</a> 
			*/
			static EResult QueryPhysicalDeviceGroups
			(
				Handle                 _handle         ,
				uint32*                _numGroups      ,
				PhysicalDevice::Group* _groupProperties
			)
			{
				return EResult(vkEnumeratePhysicalDeviceGroups(_handle, _numGroups, _groupProperties->operator VkPhysicalDeviceGroupProperties*()));
			}

			template<typename ReturnType>
			/**
			Function pointers for all Vulkan commands can be obtained with this command.

			vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
			Typically, the loader library will export this command as a function symbol, 
			so applications can link against the loader library, or load it dynamically 
			and look up the symbol using platform-specific APIs.

			Note: ReturnType is restricted to only function pointing types.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html
			*/
			static typename std::enable_if
			<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

			ReturnType>::type GetProcedureAddress(Handle& _handle, RoCStr _procedureName)
			{
				return reinterpret_cast<ReturnType>(vkGetInstanceProcAddr(_handle, _procedureName));
			}
		};
	}

	namespace V2
	{
		struct AppInstance : public V1::AppInstance
		{
			using Parent = V1::AppInstance;

			struct AppInfo : public Parent::AppInfo
			{
				AppInfo() 
				{ 
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo() 
				{
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			struct Validation : public Parent::Validation
			{
				struct Features : public Parent::Validation::Features
				{
					Features() 
					{ 
						SType = STypeEnum; 
					}
				};

				struct Flags : public Parent::Validation::Flags
				{
					Flags() 
					{ 
						SType = STypeEnum; 
					}
				};
			};

			/**
			@brief Create a new Vulkan application instance. (Use default allocator)
			*/
			static EResult Create(const CreateInfo& _info, Handle& _handle)
			{
				return Parent::Create(_info, Memory::DefaultAllocator, _handle);
			}
			
			using Parent::Create;

			/**
			@brief Destroy an application instance of Vulkan. (Use Default allocator)
			*/
			static void Destroy(Handle _handle)
			{
				Parent::Destroy(_handle, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			static EResult GetAvailableLayers(std::vector<LayerProperties>& _container)
			{
				uint32 layerCount;

				EResult result = QueryAvailableLayers(layerCount, nullptr);

				if (result != EResult::Success) return result;

				_container.resize(layerCount);

				result = QueryAvailableLayers(layerCount, _container.data());

				return result;
			}

			static EResult GetAvailableLayerExtensions(RoCStr _layerName, std::vector<ExtensionProperties>& _propertiesContainer)
			{
				uint32 layerCount;

				EResult result = QueryAvailableAppExtensions(_layerName, layerCount, nullptr);

				if (result != EResult::Success) return result;

				_propertiesContainer.resize(layerCount);

				result = QueryAvailableAppExtensions(_layerName, layerCount, _propertiesContainer.data());

				return result;
			}

			static EResult GetAvailableLayersAndExtensions(std::vector<LayerAndExtensionProperties>& _layersAndExtensions)
			{
				std::vector<LayerProperties> layers; EResult result = EResult::Incomplete;

				GetAvailableLayers(layers);

				_layersAndExtensions.resize(layers.size());

				for (uint32 index = 0; index < layers.size(); index++)
				{
					_layersAndExtensions[index].Layer = layers[index];

					result = GetAvailableLayerExtensions(_layersAndExtensions[index].Layer.Name, _layersAndExtensions[index].Extensions);

					if (result != EResult::Success) return result;
				}

				return result;
			}

			/** 
			@brief Provides the handles of all available physical devices.

			@todo Make the device listing container type specifiable using an interface.
			*/
			static EResult GetAvailablePhysicalDevices(Handle _handle, std::vector<PhysicalDevice::Handle>& _deviceListing)
			{
				uint32 count; 
				
				//auto casted = reinterpret_cast<Vault_0::IDynamicArray<PhysicalDevice::Handle>*>(_deviceListing);

				EResult returnCode = QueryPhysicalDeviceListing(_handle, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_deviceListing.resize(count);

				returnCode = QueryPhysicalDeviceListing(_handle, &count, _deviceListing.data());

				return returnCode;
			}

			/**
			 * @brief Provides a list of the device groups present in the system.
			 * 
			 * @todo Make the group listing container type specifiable using an interface.
			 * 
			 * \param _instance
			 * \param _groupListing
			 * \return 
			 */
			static EResult GetAvailablePhysicalDeviceGroups(Handle _handle, std::vector<PhysicalDevice::Group>& _groupListing)
			{
				uint32 count;

				EResult returnCode = QueryPhysicalDeviceGroups(_handle, &count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_groupListing.resize(count);

				returnCode = QueryPhysicalDeviceGroups(_handle, &count, _groupListing.data());

				return returnCode;
			}
		};
	}

	namespace V3
	{
		/**
		@brief An object that manages the represented application process state within the GPU.

		@details
		Other Name: Application State Container

		Vulkan has no global state reference: 
		Every application must keep track of their state using an instance object.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance">Application Instance Specification</a> 

		Note: This class is a singleton. There should really not be more than one app instance per process...
		*/
		class AppInstance : public V2::AppInstance
		{
		public:
			using Parent = V2::AppInstance;

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 */
			EResult Create(AppInstance::AppInfo& _appInfo, AppInstance::CreateInfo& _createinfo)
			{
				appInfo      = _appInfo   ;
				createInfo   = _createinfo;
				allocator    = nullptr    ;

				if (createInfo.AppInfo != &appInfo) createInfo.AppInfo = &appInfo;

				EResult returnCode = Parent::GetVersion(version);

				if (returnCode != EResult::Success) return returnCode;

				return Parent::Create(createInfo, handle);
			}

			/**
			 * @brief Create an application instance.
			 * 
			 * \param _appInfo
			 * \param _creationSpec
			 * \param _allocator
			 */
			EResult Create(AppInstance::AppInfo& _appInfo, AppInstance::CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				appInfo    = _appInfo   ;
				createInfo = _createInfo;
				allocator  = _allocator ;

				EResult returnCode = Parent::GetVersion(version);

				if (returnCode != EResult::Success) return returnCode;

				return Parent::Create(createInfo, allocator, handle);
			}

			/**
			 * @brief Destroy an application instance.
			 */
			void Destroy()
			{
				Parent::Destroy(handle, allocator);
			}

			/** 
			@brief Provides the handles of all available physical devices.

			@todo Make the device listing container type specifiable using an interface.
			*/
			EResult GetAvailablePhysicalDevices(std::vector<PhysicalDevice>& _deviceListing) const 
			{
				uint32 count; std::vector<PhysicalDevice::Handle> handleList;

				EResult returnCode = QueryPhysicalDeviceListing(&count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				handleList    .resize(count);
				_deviceListing.resize(count);

				returnCode = QueryPhysicalDeviceListing(&count, handleList.data());
				
				for (DeviceSize index = 0; index < count; index++)
				{
					_deviceListing[index].AssignHandle(handleList[index]);
				}

				return returnCode;
			}

			/**
			 * @brief Provides a list of the device groups present in the system.
			 * 
			 * @todo Make the group listing container type specifiable using an interface.
			 * 
			 * \param _instance
			 * \param _groupListing
			 * \return 
			 */
			EResult GetAvailablePhysicalDeviceGroups(std::vector<PhysicalDevice::Group>& _groupListing) const
			{
				uint32 count;

				EResult returnCode = QueryPhysicalDeviceGroups(&count, nullptr);

				if (returnCode != EResult::Success) return returnCode;

				_groupListing.resize(count);

				returnCode = QueryPhysicalDeviceGroups(&count, _groupListing.data());

				return returnCode;
			}

			const Handle& GetHandle() const
			{ 
				return handle; 
			}

			/**
			 * @brief Get application version.
			 * 
			 * \return 
			 */
			uint32 GetVersion() const
			{
				return version;
			}

			template<typename ReturnType>
			/**
			Function pointers for all Vulkan commands can be obtained with this command.

			vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner. 
			Typically, the loader library will export this command as a function symbol, 
			so applications can link against the loader library, or load it dynamically 
			and look up the symbol using platform-specific APIs.

			Note: ReturnType is restricted to only function pointing types.

			https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkGetInstanceProcAddr.html
			*/
			typename std::enable_if
			<
				std::bool_constant
				< 
					std::is_pointer <                             ReturnType       >::value &&
					std::is_function<typename std::remove_pointer<ReturnType>::type>::value
				>::value,

			ReturnType>::type GetProcedureAddress(RoCStr _procedureName) const
			{
				return Parent::GetProcedureAddress(handle, _procedureName);  // reinterpret_cast<ReturnType>(vkGetInstanceProcAddr(handle, _procedureName));
			}

			EResult QueryPhysicalDeviceListing(uint32* _numDevices, PhysicalDevice::Handle* _deviceListing) const
			{
				return Parent::QueryPhysicalDeviceListing(handle, _numDevices, _deviceListing);
			}

			EResult QueryPhysicalDeviceGroups(uint32* _numGroups, PhysicalDevice::Group* _groupProperties) const
			{
				return Parent::QueryPhysicalDeviceGroups(handle, _numGroups, _groupProperties);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle     handle    ;
			AppInfo    appInfo   ;   
			CreateInfo createInfo;
			uint32     version   ;

			const Memory::AllocationCallbacks* allocator;
		};
	}
}




/** @file VT_LogicalDevice.hpp

@brief Vaulted Thermals: Logical Device
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief Represent logical connections to physical devices. 
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#devsandqueues-devices">Specification</a> 
		 */
		struct LogicalDevice
		{
			using Memory = V0::Memory;

			using Handle = VkDevice;   ///< Opaque handle to a device object.  

			using CreateFlags = Bitmask<EUndefined, Flags>;   ///< Reserved for future use.

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceDiagnosticsConfigCreateInfoNV">Specification</a> 
			*/
			struct DiagnosticsConfigCreateInfo : V0::VKStruct_Base<VkDeviceDiagnosticsConfigCreateInfoNV, EStructureType::DeviceDiagnosticsConfig_CreateInfo_NV>
			{
				using ConfigFlags = Bitmask<EDeviceDiagnosticConfigFlag, VkDeviceDiagnosticsConfigFlagsNV>;

				      EType       SType;
				const void*       Next ;
				      ConfigFlags Flags;
			};

			/**
			 * @brief Queues handle different types of batched commands for the GPU to complete.
			 * 
			 * @details 
			 * Vulkan queues provide an interface to the execution engines of a device. 
			 * Commands for these execution engines are recorded into command buffers ahead of execution time.
			 * These command buffers are then submitted to queues with a queue submission command for execution in a number of batches. 
			 * Once submitted to a queue, these commands will begin and complete execution without further application intervention,
			 * though the order of this execution is dependent on a number of implicit and explicit ordering constraints.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals-queueoperation">Specification</a> 
			 */
			struct Queue
			{
				using Handle = VkQueue;   ///< Opaque handle to a queue object

				using PresentationInfo = VkPresentInfoKHR;   ///< Proper structure is defined later. (See VT_Swapchain.hpp)

				using SubmitInfo = VkSubmitInfo;   ///< Proper structure is defined later. (See VT_Command.hpp)

				using Fence_Handle = VkFence;

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateInfo">Specification</a> 
				 * 
				 * @details
				 * 
				 * A queue is allocated by the family, as in each queue allocated must have their index in the family tracked.
				 * This means that the logical device is passed a queue's create info by the family with its specified index,
				 * queue count from that family to be associated with the logical device, and the family's priority.
				 * 
				 * If a queue family is to be used for a specific task (transfer, etc), it is advantageous that that queue family 
				 * have as little flags for other functionality as possible.
				 */
				struct CreateInfo : V0::VKStruct_Base<VkDeviceQueueCreateInfo, EStructureType::DeviceQueue_CreateInfo>
				{
					using ECreateFlag = ELogicalDeviceQueueCreateFlag                 ;
					using CreateFlags = Bitmask<ECreateFlag, VkDeviceQueueCreateFlags>;

						  EType       SType           ;
					const void*       Next            ;
						  CreateFlags Flags           ;
						  uint32      QueueFamilyIndex;
						  uint32      QueueCount      ;
					const float*      QueuePriorities ;
				};

				/**
				* @brief Get a queue handle from a device.
				* 
				* @details
				* vkGetDeviceQueue must only be used to get queues that were created with the flags parameter of VkDeviceQueueCreateInfo set to zero. 
				* To get queues that were created with a non-zero flags parameter use vkGetDeviceQueue2.
				* 
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDeviceQueue">Specification</a> 
				* 
				* \param _handle
				* \param _queueFamilyIndex
				* \param _queueIndex
				* \param _queueReturn
				*/
				static void Get(LogicalDevice::Handle _device, uint32 _queueFamilyIndex, uint32 _queueIndex, Handle& _queueReturn)
				{
					vkGetDeviceQueue(_device, _queueFamilyIndex, _queueIndex, &_queueReturn);
				}

				/**
				* @brief.
				* 
				* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueuePresentKHR">Specification</a> 
				* 
				* \param _queue
				* \param _presentation
				* \return 
				*/
				static EResult QueuePresentation(LogicalDevice::Queue::Handle _queue, const PresentationInfo& _presentation)
				{
					return EResult(vkQueuePresentKHR(_queue, &_presentation));
				}

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueSubmit">Specification</a> 
				 *
				 * \param _queue
				 * \param _submitCount
				 * \param _submissions
				 * \param _fence
				 * \return 
				 */
				static EResult SubmitToQueue
				(
							LogicalDevice::Queue::Handle _queue      ,
							uint32                       _submitCount,
					  const SubmitInfo*                  _submissions,
					        Fence_Handle                 _fence
				)
				{
					return EResult(vkQueueSubmit(_queue, _submitCount, _submissions, _fence));
				}

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkQueueWaitIdle">Specification</a> 
				 * 
				 * \param _queue
				 * \return 
				 */
				static EResult WaitUntilIdle(Handle _queue)
				{
					return EResult(vkQueueWaitIdle(_queue));
				}
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueInfo2">Specification</a> 
			* 
			* @todo Implement.
			*/
			struct Queue2 : V0::VKStruct_Base<VkDeviceQueueInfo2, EStructureType::DeviceQueueInfo2>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceQueueCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EDeviceQueueCreateFlag ,VkDeviceQueueCreateFlags>;

				      EType       SType           ;
				const void*       Next            ;
				      CreateFlags Flags           ;
				      uint32      QueueFamilyIndex;
				      uint32      QueueIndex      ;

				/**
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDeviceQueue2">Specification</a> 
				* 
				* @todo Implement.
				*/
				static void Get
				(
					      Handle         _device   ,
					const Queue2*        _queueInfo,
					      Queue::Handle* _queue
				)
				{
					vkGetDeviceQueue2(_device, _queueInfo->operator const VkDeviceQueueInfo2*(), _queue);
				}
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupDeviceCreateInfo">Specification</a> 
			*/
			struct GroupCreateInfo : V0::VKStruct_Base<VkDeviceGroupDeviceCreateInfo, EStructureType::Device_GroupDevice_CreateInfo>
			{
				      EType   SType              ;
				const void*   Next               ;
				      uint32  PhysicalDeviceCount;
				const Handle* PhysicalDevices    ;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemoryOverallocationCreateInfoAMD">Specification</a> 
			*/
			struct MemoryOverallocationCreateInfo : V0::VKStruct_Base<VkDeviceMemoryOverallocationCreateInfoAMD, EStructureType::DeviceMemory_Overallocation_CreateInfo_AMD>
			{
				      EType                            SType                 ;
				const void*                            Next                  ;
				      EMemoryOverallocationBehaviorAMD OverallocationBehavior;
			};

			/**
			* @details
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDevicePrivateDataCreateInfoEXT">Specification</a> 
			*/
			struct PrivateDataCreateInfo : V0::VKStruct_Base<VkDevicePrivateDataCreateInfoEXT, EStructureType::Device_PrivateData_CreateInfo_EXT>
			{
				      EType  SType                      ;
				const void*  Next                       ;
				      uint32 PrivateDataSlotRequestCount;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceCreateInfo">Specification</a> 
			 */
			struct CreateInfo : V0::VKStruct_Base<VkDeviceCreateInfo, EStructureType::Device_CreateInfo>
			{
					  EType                     SType                ;
				const void*                     Next                 ;
					  CreateFlags               Flags                ;
					  uint32                    QueueCreateInfoCount ;
				const Queue::CreateInfo*        QueueCreateInfos     ;
					  uint32                    EnabledLayerCount    ;
				      RoSCtr_roArray_Array      EnabledLayerNames    ;
					  uint32                    EnabledExtensionCount;
				      RoSCtr_roArray_Array      EnabledExtensionNames;
				const PhysicalDevice::Features* EnabledFeatures      ;
			};

			/**
			 * @brief A logical device is created as a connection to a physical device.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDevice">Specification</a> 
			 * 
			 * \param _physicalDevice
			 * \param _createSpec
			 * \param _allocator
			 * \param _device
			 * \return 
			 */
			static EResult Create
			(
				      PhysicalDevice::Handle       _physicalDevice,
				const CreateInfo&                  _info          ,
				const Memory::AllocationCallbacks* _allocator     ,
				      Handle&                      _device
			)
			{
				return EResult(vkCreateDevice(_physicalDevice, _info.operator const VkDeviceCreateInfo *(), _allocator->operator const VkAllocationCallbacks*(), &_device));
			}

			/**
			 * @brief Destroy a logical device.
			 * 
			 * @details
			 * To ensure that no work is active on the device, vkDeviceWaitIdle can be used to gate the destruction of the device. 
			 * Prior to destroying a device, an application is responsible for destroying/freeing any Vulkan objects that were created 
			 * using that device as the first parameter of the corresponding vkCreate* or vkAllocate* command.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDevice">Specification</a> 
			 * 
			 * \param _handle
			 * \param _allocator
			 */
			static void Destroy(Handle _device, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyDevice(_device, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDeviceWaitIdle">Specification</a> .
			 * 
			 * \param _device
			 * \return 
			 */
			static EResult WaitUntilIdle(Handle _device)
			{
				return EResult(vkDeviceWaitIdle(_device));
			}

			template<typename ReturnType>
			/** 
			@brief Function pointers for all Vulkan commands directly addressed from the device.

			@details
			In order to support systems with multiple Vulkan implementations, the function pointers returned by vkGetInstanceProcAddr
			may point to dispatch code that calls a different real implementation for different VkDevice objects or their child objects.
			The overhead of the internal dispatch for VkDevice objects can be avoided by obtaining device-specific function pointers
			for any commands that use a device or device-child object as their dispatchable object.

			Note: ReturnType is restricted to only function pointing types.

			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetInstanceProcAddr">Specification</a> 
			*/
			static typename std::enable_if
			<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,

			ReturnType>::type GetProcedureAddress(Handle& _appInstance, RoCStr _procedureName)
			{
				return reinterpret_cast<ReturnType>(vkGetDeviceProcAddr(_appInstance, _procedureName));
			}
		};
	}

	namespace V2
	{
		struct LogicalDevice : public V1::LogicalDevice
		{
			using Parent = V1::LogicalDevice;

			struct DiagnosticsConfigCreateInfo : public Parent::DiagnosticsConfigCreateInfo
			{
				DiagnosticsConfigCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct Queue : public Parent::Queue
			{
				struct CreateInfo : public Parent::Queue::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Queue2 : public Parent::Queue2
			{
				Queue2()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct GroupCreateInfo : public Parent::GroupCreateInfo
			{
				GroupCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct MemoryOverallocationCreateInfo : public Parent::MemoryOverallocationCreateInfo
			{
				MemoryOverallocationCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct PrivateDataCreateInfo : public Parent::PrivateDataCreateInfo
			{
				PrivateDataCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			 * @brief A logical device is created as a connection to a physical device. (Uses default allocator)
			 * 
			 * \param _physicalDevice
			 * \param _createSpec
			 * \param _allocator
			 * \param _device
			 * \return 
			 */
			static EResult Create
			(
				      PhysicalDevice::Handle _physicalDevice,
				const CreateInfo&            _createSpec    ,
				      Handle&                _device
			)
			{
				return Create(_physicalDevice, _createSpec, Memory::DefaultAllocator, _device);
			}

			using Parent::Create;

			/**
			* @brief Destroy a logical device. (Uses default allocator)
			* 
			* \param _handle
			* \param _allocator
			*/
			static void Destroy(Handle _device)
			{
				vkDestroyDevice(_device, Memory::DefaultAllocator->operator const VkAllocationCallbacks*());
			}

			using Parent::Destroy;
		};
	}

	namespace V3
	{
		class LogicalDevice : public V2::LogicalDevice
		{
		public:
			using Parent = V2::LogicalDevice;

			struct Queue : public Parent::Queue
			{
				using Parent = Parent::Queue;

				Queue() { assignment = EQueueFlag::MaxEnum; }

				void Assign(const LogicalDevice& _logicalDevice, CreateInfo& _info)
				{
					device = &_logicalDevice;
					info   = &_info         ;
					//info   = _info         ;

					queueIndex = 0;
				}

				void Assign(const LogicalDevice& _logicalDevice, CreateInfo& _info, uint32 _queueIndex, EQueueFlag _type)
				{
					device = &_logicalDevice;
					info   = &_info         ;
					//info   = _info         ;

					queueIndex = _queueIndex;

					assignment = _type;
				}

				uint32 GetFamilyIndex() const
				{
					return info->QueueFamilyIndex;
				}

				uint32 GetQueueIndex() const
				{
					return queueIndex;
				}

				const Handle& GetHandle() const
				{
					return handle;
				}

				const CreateInfo& GetInfo() const
				{
					return *info;
				}

				const EQueueFlag& GetType() const
				{
					return assignment;
				}

				void Retrieve()
				{
					Parent::Get(*device, info->QueueFamilyIndex, queueIndex, handle);
				}

				bool FamilySpecified() const
				{
					return assignment != EQueueFlag::MaxEnum ? true : false;
				}

				EResult QueuePresentation(const PresentationInfo& _presentationInfo) const
				{
					return Parent::QueuePresentation(handle, _presentationInfo);
				}

				/**
				 * 
				 * @todo remove.
				 * 
				 * \param _index
				 * \param _type
				 */
				void SpecifyFamily(uint32 _index, EQueueFlag _type)
				{
					queueIndex = _index; 
					assignment = _type ;
				}

				EResult SubmitToQueue(uint32 _submitCount, const SubmitInfo* _submissions, Fence_Handle _fence) const
				{
					return Parent::SubmitToQueue(handle, _submitCount, _submissions, _fence);
				}

				EResult WaitUntilIdle() const
				{
					return Parent::WaitUntilIdle(handle);
				}

				operator const Handle&() const
				{
					return handle;
				}
				
			protected:

				Handle handle;

				//CreateInfo* info;   // TODO Change to this
				CreateInfo* info;   

				EQueueFlag assignment;

				const LogicalDevice* device;

				uint32 queueIndex;
			};

			void AssignPhysicalDevice(const PhysicalDevice& _physicalDevice)
			{
				physicalDevice = &_physicalDevice;
			}

			EResult Create(CreateInfo& _createInfo)
			{
				info           = _createInfo             ;
				allocator      = Memory::DefaultAllocator;

				return Parent::Create(*physicalDevice, info, handle);
			}

			EResult Create(CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				info           = _createInfo     ;
				allocator      = _allocator      ;

				return Parent::Create(*physicalDevice, info, allocator, handle);
			}

			EResult Create(const PhysicalDevice& _physicalDevice, CreateInfo& _createInfo)
			{
				physicalDevice = &_physicalDevice        ;
				info           = _createInfo             ;
				allocator      = Memory::DefaultAllocator;

				return Parent::Create(*physicalDevice, info, handle);
			}

			EResult Create(const PhysicalDevice& _physicalDevice, CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				physicalDevice = &_physicalDevice;
				info           = _createInfo     ;
				allocator      = _allocator      ;

				return Parent::Create(*physicalDevice, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			const PhysicalDevice& GetPhysicalDevice() const
			{
				return *physicalDevice;
			}

			EResult WaitUntilIdle() const
			{
				return Parent::WaitUntilIdle(handle);
			}
			
			template<typename ReturnType>
			typename std::enable_if
			<
			std::bool_constant
			< 
				std::is_pointer <                             ReturnType       >::value &&
				std::is_function<typename std::remove_pointer<ReturnType>::type>::value
			>::value,
			ReturnType>::type GetProcedureAddress(RoCStr _procedurename) const
			{
				return Parent::GetProcedureAddress<ReturnType>(handle, _procedurename);
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			CreateInfo info;

			const PhysicalDevice* physicalDevice;

			const Memory::AllocationCallbacks* allocator;
		};
	}
}




/**
@file VT_Memory.hpp

@brief Vaulted Thermals: Memory

@details
Contains the full definition of the intended memory structure.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#memory">Specification</a>
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		struct Memory : public V0::Memory
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceMemory">Specification</a>  */
			using Handle = VkDeviceMemory;

			static constexpr DeviceSize ZeroOffset = 0;

			/**
			* @brief.
			* 
			* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateMemory">Specification</a> 
			* 
			* \param _device
			* \param _allocateInfo
			* \param _allocator
			* \param _memory
			* \return 
			*/
			static EResult Allocate
			(
				      LogicalDevice::Handle _device      ,
				const AllocateInfo&         _allocateInfo,
				const AllocationCallbacks*  _allocator   ,
				      Handle&               _memory
			)
			{
				return EResult(vkAllocateMemory(_device, _allocateInfo, _allocator->operator const VkAllocationCallbacks*(), &_memory) );
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeMemory">Specification</a> 
			* 
			* \param _device
			* \param _memory
			* \param _allocator
			* \return 
			*/
			static void Free
			(
				      LogicalDevice::Handle _device   ,
				      Handle                _memory   ,
				const AllocationCallbacks*  _allocator
			)
			{
				vkFreeMemory(_device, _memory, _allocator->operator const VkAllocationCallbacks*());
			}

			/** 
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkMapMemory">Specification</a>
			* 
			* \param _device
			* \param _memory
			* \param _offset
			* \param _size
			* \param _flags
			* \param _data
			* \return 
			*/
			static EResult Map
			(
				LogicalDevice::Handle _device,
				Handle                _memory,
				DeviceSize            _offset,
				DeviceSize            _size  ,
				MapFlags              _flags ,
				VoidPtr&              _data
			)
			{
				return EResult(vkMapMemory(_device, _memory, _offset, _size, _flags, &_data));
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkUnmapMemory">Specification</a>
			* 
			* \param _device
			* \param _memory
			*/
			static void Unmap(LogicalDevice::Handle _device, Handle _memory)
			{
				vkUnmapMemory(_device, _memory);
			}
		};
	}

	namespace V2
	{
		struct Memory : public V1::Memory
		{
			using Parent = V1::Memory;

			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo() 
				{ 
					SType           = STypeEnum; 
					Next            = nullptr  ;
					AllocationSize  = 0        ;
					MemoryTypeIndex = 0        ;
				}
			};

			struct Barrier : public Parent::Barrier
			{
				Barrier() 
				{ 
					SType = STypeEnum; 
					Next  = nullptr  ;
				}
			};

			/**
			* @brief.
			* 
			* \param _device
			* \param _allocateInfo
			* \param _allocator
			* \param _memory
			* \return 
			*/
			static EResult Allocate
			(
				      LogicalDevice::Handle _device      ,
				const AllocateInfo&         _allocateInfo,
				      Handle&               _memory
			)
			{
				return EResult(vkAllocateMemory(_device, _allocateInfo, Memory::DefaultAllocator->operator const VkAllocationCallbacks*(), &_memory) );
			}

			using Parent::Allocate;

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeMemory">Specification</a> 
			* 
			* \param _device
			* \param _memory
			* \param _allocator
			* \return 
			*/
			static void Free(LogicalDevice::Handle _device, Handle _memory)
			{
				vkFreeMemory(_device, _memory, Memory::DefaultAllocator->operator const VkAllocationCallbacks*());
			}

			using Parent::Free;

			/**
			 * @brief Writes to GPU memory by mapping to device memory specified by a 
			 * handle and then using memcpy to copy data specified in _data.
			 * 
			 * \param _device
			 * \param _memory
			 * \param _offset
			 * \param _size
			 * \param _flags
			 * \param _data
			 */
			static void WriteToGPU
			(
				      LogicalDevice::Handle _device,
				      Handle                _memory,
				      DeviceSize            _offset,
				      DeviceSize            _size  ,
				      MapFlags              _flags ,
				const VoidPtr&              _data
			)
			{
				VoidPtr gpuAddressing;

				Map(_device, _memory, _offset, _size, _flags, gpuAddressing);   ///< @todo Add exception handling for this / return code...

					memcpy(gpuAddressing, _data, _size);

				Unmap(_device, _memory);
			}
		};
	}

	namespace V3
	{
		class Memory : public V2::Memory
		{
		public:

			using Parent = V2::Memory;

			EResult Allocate(LogicalDevice::Handle _device, AllocateInfo& _allocateInfo)
			{
				device    = _device                 ;
				info      = _allocateInfo           ;
				allocator = Memory::DefaultAllocator;

				return Parent::Allocate(device, info, handle);
			}

			EResult Allocate(LogicalDevice::Handle _device, AllocateInfo& _allocateInfo, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device      ;
				info      = _allocateInfo;
				allocator = _allocator   ;

				return Parent::Allocate(device, info, allocator, handle);
			}

			void Free()
			{
				Parent::Free(device, handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult Map
			(
				DeviceSize _offset, DeviceSize _size, MapFlags _flags, VoidPtr& _data
			)
			{
				return Parent::Map(device, handle, _offset, _size, _flags, _data);
			}

			void Unmap()
			{
				Parent::Unmap(device, handle);
			}

			void WriteToGPU(DeviceSize _offset, DeviceSize _size, MapFlags _flags, VoidPtr& _data)
			{
				Parent::WriteToGPU(device, handle, _offset, _size, _flags, _data);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			AllocateInfo info;

			const AllocationCallbacks* allocator;

			LogicalDevice::Handle device;
		};
	}
}




/*
@file VT_Sampler.hpp
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
        /**
         * @brief.
         */
		struct Sampler
		{
            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampler">Specification</a>  */
			using Handle = VkSampler;

            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateFlags">Specification</a>  */
            using CreateFlags = Bitmask<ESamplerCreateFlag, VkSamplerCreateFlags>;

            using EMipmapMode = ESamplerMipmapMode ; 
            using AddressMode = ESamplerAddressMode;

            /** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSamplerCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkSamplerCreateInfo, EStructureType::Sampler_CreateInfo>
			{
                      EType             SType                  ;
                const void*             Next                   ;
                      CreateFlags       Flags                  ;
                      EFilter           MagnificationFilter    ;
                      EFilter           MinimumFilter          ;
                      EMipmapMode       MipmapMode             ;
                      AddressMode       AddressModeU           ;
                      AddressMode       AddressModeV           ;
                      AddressMode       AddressModeW           ;
                      float32           MipLodBias             ;
                      Bool              AnisotropyEnable       ;
                      float32           MaxAnisotropy          ;
                      Bool              CompareEnable          ;
                      ECompareOperation CompareOperation       ;
                      float32           MinimumLod             ;
                      float32           MaxLod                 ;
                      EBorderColor      BorderColor            ;
                      Bool              UnnormalizedCoordinates;
			};

            /**
             * @brief.
             * 
             * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSampler">Specification</a> 
             * 
             * \param _device
             * \param _createInfo
             * \param _allocator
             * \param _sampler
             * \return 
             */
            static EResult Create
            (
				      LogicalDevice::Handle        _device    ,
				const CreateInfo&                  _createInfo,
				const Memory::AllocationCallbacks* _allocator ,
				      Handle&                      _sampler
            )
            {
                return EResult(vkCreateSampler(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_sampler));
            }

            /**
             * @brief.
             * 
             * @details
             * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySampler">Specification</a> 
             * 
             * \param _device
             * \param _sampler
             * \param _allocator
             */
            static void Destroy
            (
                      LogicalDevice::Handle        _device   ,
                      Handle                       _sampler  ,
                const Memory::AllocationCallbacks* _allocator
            )
            {
                vkDestroySampler(_device, _sampler, _allocator->operator const VkAllocationCallbacks*());
            }
		};
	}

    namespace V2
    {
        struct Sampler : public V1::Sampler
        {
            using Parent = V1::Sampler;

            struct CreateInfo : public Parent::CreateInfo
            {
                CreateInfo()
                {
                    SType = STypeEnum;
                    Next  = nullptr  ;
                }
            };

            /**
             * @brief.

             * \param _device
             * \param _createInfo
             * \param _allocator
             * \param _sampler
             * \return 
             */
            static EResult Create
            (
				      LogicalDevice::Handle _device    ,
				const CreateInfo&           _createInfo,
				      Handle&               _sampler
            )
            {
                return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _sampler);
            }

            using Parent::Create;

            /**
             * @brief.
             * 
             * @details
             * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySampler">Specification</a> 
             * 
             * \param _device
             * \param _sampler
             * \param _allocator
             */
            static void Destroy(LogicalDevice::Handle _device , Handle _sampler)
            {
                Parent::Destroy(_device, _sampler, Memory::DefaultAllocator);
            }

            using Parent::Destroy;
        };
    }

    namespace V3
    {
        class Sampler : public V2::Sampler
        {
        public:

            using Parent = V2::Sampler;

            EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
            {
                device    = _device;
                info      = _info                   ;
                allocator = Memory::DefaultAllocator;

                return Parent::Create(device, info, allocator, handle);
            }

            EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
            {
                device    = _device;
                info      = _info  ;
                allocator = _allocator;

                return Parent::Create(device, info, allocator, handle);
            }

            void Destroy()
            {
                Parent::Destroy(device, handle, allocator);
            }

            const Handle& GetHandle() const
            {
                return handle;
            }

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

        protected:

            Handle handle;

            CreateInfo info;

            const Memory::AllocationCallbacks* allocator;

            LogicalDevice::Handle device;
        };
    }
}




/** 
@file VT_Resource.hpp

@brief Vaulted Thermals: Resources

@details
Vulkan supports two primary resource types: buffers and images. 
Resources are views of memory with associated formatting and dimensionality. 
Buffers are essentially unformatted arrays of bytes whereas images contain format information, 
can be multidimensional and may have associated metadata.

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief A linear array of data.
		 * 
		 * @details
		 * Buffers represent linear arrays of data which are used for various purposes by binding them
		 * to a graphics or compute pipeline via descriptor sets or via certain commands, or by
		 * directly specifying them as parameters to certain commands.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-buffers">Specification</a> 
		 */
		struct Buffer
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBuffer">Specification</a>  */
			using Handle = VkBuffer;

			using ECreateFlag = EBufferCreateFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EBufferCreateFlag, VkBufferCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferUsageFlags">Specification</a>  */
			using UsageFlags = Bitmask<EBufferUsage, VkBufferUsageFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCreateInfo">Specification</a>
			 */
			struct CreateInfo : V0::VKStruct_Base<VkBufferCreateInfo, EStructureType::Buffer_CreateInfo>
			{
				      EType        SType                ;
				const void*        Next                 ;
				      CreateFlags  Flags                ;
					  DeviceSize   Size                 ;
					  UsageFlags   Usage                ;
				      ESharingMode SharingMode          ;
					  uint32       QueueFamilyIndexCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferCopy">Specification</a>  */
			struct CopyInfo : V0::VKStruct_Base<VkBufferCopy>
			{
				DeviceSize SourceOffset;
				DeviceSize DestinationOffset;
				DeviceSize Size;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferMemoryBarrier">Specification</a>
			 */
			struct Memory_Barrier : V0::VKStruct_Base<VkBufferMemoryBarrier, EStructureType::BufferMemory_Barrier>
			{
				      EType       SType              ;
				const void*       Next               ;
				      AccessFlags SrcAccessMask      ;
				      AccessFlags DstAccessMask      ;
				      uint32      SrcQueueFamilyIndex;
				      uint32      DstQueueFamilyIndex;
				      Handle      Buffer             ;
				      DeviceSize  Offset             ;
				      DeviceSize  Size               ;
			};

			/**
			 * @brief.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBindBufferMemory">Specification</a> 
			 * 
			 * \param _device
			 * \param _buffer
			 * \param _memory
			 * \param _memoryOffset
			 * \return 
			 */
			static EResult BindMemory
			(
				LogicalDevice::Handle _device      ,
				Handle                _buffer      ,
				Memory::Handle        _memory      ,
				DeviceSize            _memoryOffset
			)
			{
				return EResult(vkBindBufferMemory(_device, _buffer, _memory, _memoryOffset));
			}

			/**
			 * @brief Create a new buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateBuffer">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _buffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator, Handle& _buffer)
			{
				return EResult(vkCreateBuffer(_device, _createInfo.operator const VkBufferCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_buffer));
			}

			

			/**
			 * @brief Destroy a buffer object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyBuffer">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _buffer
			 * \param _allocator
			 * \return 
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _buffer, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyBuffer(_device, _buffer, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetBufferMemoryRequirements">Specification</a>
			 * 
			 * \param _device
			 * \param _buffer
			 * \param _memoryRequirements
			 */
			static void GetMemoryRequirements
			(
				LogicalDevice::Handle _device             ,
				Handle                _buffer             ,
				Memory::Requirements& _memoryRequirements
			)
			{
				vkGetBufferMemoryRequirements(_device, _buffer, _memoryRequirements);
			}
		};

		/**
		 * @brief A buffer view represents a contiguous range of a buffer and a specific format to be used to interpret the data.
		 * 
		 * @details
		 * Buffer views are used to enable shaders to access buffer contents interpreted as formatted data. 
		 * In order to create a valid buffer view, the buffer must have been created with at least one of 
		 * the following usage flags: UnformTexelBuffer or StorageTexelBuffer
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-buffer-views">Specification</a> 
		 */
		struct BufferView
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferView">Specification</a>  */
			using Handle = VkBufferView;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferViewCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EUndefined, VkBufferViewCreateFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkBufferViewCreateInfo.html">Specification</a> .
			 */
			struct CreateInfo : V0::VKStruct_Base<VkBufferViewCreateInfo, EStructureType::BufferView_CreateInfo>
			{
				      EType          SType  ;
				const void*          Next   ;
				      CreateFlags    Flags  ;
				      Buffer::Handle VBuffer;
				      EFormat        Format ;
				      DeviceSize     Offset ;
				      DeviceSize     Range  ;
			};

			/**
			 * @brief Create a new buffer view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateBufferView">Specification</a> .
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _bufferView
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _info, const Memory::AllocationCallbacks* _allocator, Handle& _bufferView)
			{
				return EResult(vkCreateBufferView(_device, _info.operator const VkBufferViewCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_bufferView));
			}

			/**
			 * @brief Destroy a buffer view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/vkDestroyBufferView.html">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _bufferView
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _bufferView, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyBufferView(_device, _bufferView, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/** 
		@brief
		Images represent multidimensional - up to 3 - arrays of data which can be used for various purposes 
		(e.g. attachments, textures), by binding them to a graphics or compute pipeline via descriptor sets, 
		or by directly specifying them as parameters to certain commands.

		<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-images">Specification</a> 
		*/
		struct Image
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImage">Specification</a>  */
			using Handle = VkImage;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageAspectFlags">Specification</a>  */
			using AspectFlags = Bitmask<EImageAspect, VkImageAspectFlags>;

			using ECreateFlag = EImageCreateFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EImageCreateFlag, VkImageCreateFlags>;

			using ETiling = EImageTiling;

			using EUsage = EImageUsage;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageUsageFlags">Specification</a>  */
			using UsageFlags = Bitmask<EImageUsage, VkImageUsageFlags>;   ///< Bitmask specifying intended usage of an image.

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkImageCreateInfo, EStructureType::Image_CreateInfo>
			{
				      EType        SType                ;
				const void*        Next                 ;
				      CreateFlags  Flags                ;
				      EImageType   ImageType            ;
				      EFormat      Format               ;
				      Extent3D     Extent               ;
				      uint32       MipmapLevels         ;
				      uint32       ArrayLayers          ;
				      ESampleCount Samples              ;
				      ETiling      Tiling               ;
					  UsageFlags   Usage                ;
				      ESharingMode SharingMode          ;
				      uint32       QueueFamilyIndexCount;
				const uint32*      QueueFamilyIndices   ;
					  EImageLayout InitalLayout         ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageSubresourceLayers">Specification</a>  */
			struct SubresourceLayers : V0::VKStruct_Base<VkImageSubresourceLayers>
			{
				AspectFlags AspectMask    ;
				uint32      MipLevel      ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageSubresourceRange">Specification</a>  */
			struct SubresourceRange : V0::VKStruct_Base<VkImageSubresourceRange>
			{
				AspectFlags AspectMask    ;
				uint32      BaseMipLevel  ;
				uint32      LevelCount    ;
				uint32      BaseArrayLayer;
				uint32      LayerCount    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageMemoryBarrier">Specification</a>  */
			struct Memory_Barrier : V0::VKStruct_Base<VkImageMemoryBarrier, EStructureType::ImageMemory_Barrier>
			{
				      EType            SType              ;
				const void*            Next               ;
				      AccessFlags      SrcAccessMask      ;
				      AccessFlags      DstAccessMask      ;
				      EImageLayout     OldLayout          ;
				      EImageLayout     NewLayout          ;
				      uint32           SrcQueueFamilyIndex;
				      uint32           DstQueueFamilyIndex;
				      Handle           Image              ;
				      SubresourceRange SubresourceRange   ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageBlit">Specification</a>  */
			struct Blit : V0::VKStruct_Base<VkImageBlit>
			{
				SubresourceLayers SrcSubresource;
				Offset3D          SrcOffsets[2] ;
				SubresourceLayers DstSubresource;
				Offset3D          DstOffsets[2] ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBindImageMemory">Specification</a> 
			 * 
			 * \param _device
			 * \param _image
			 * \param _memory
			 * \param _memoryOffset
			 * \return 
			 */
			static EResult BindMemory
			(
				LogicalDevice::Handle _device      ,
				Handle                _image       ,
				Memory::Handle        _memory      ,
				DeviceSize            _memoryOffset
			)
			{
				return EResult(vkBindImageMemory(_device, _image, _memory, _memoryOffset));
			}

			/**  
			 * @brief  Create an image object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateImage">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _imageHandle
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator, Handle& _imageHandle)
			{
				return EResult(vkCreateImage(_deviceHandle, _createInfo.operator const VkImageCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_imageHandle));
			}

			/** 
			 * @brief Destroy an image object.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyImage">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _image
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _image, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyImage(_deviceHandle, _image, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetImageMemoryRequirements">Specification</a> 
			 * 
			 * \param _device
			 * \param _image
			 * \param _memoryRequirements
			 */
			static void GetMemoryRequirements(LogicalDevice::Handle _device, Handle _image, Memory::Requirements& _memoryRequirements)
			{
				vkGetImageMemoryRequirements(_device, _image, _memoryRequirements);
			}
		};

		/**
		* @brief An object that represents an image subresource range of a specific image, 
		* and state that controls how the contents are interpreted.
		* 
		* @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#resources-image-views">Specification</a> 
		*/
		struct ImageView
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageView">Specification</a>  */
			using Handle = VkImageView;

			using EViewType = EImageViewType;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkImageViewCreateInfo, EStructureType::ImageView_CreateInfo>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImageViewCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EImageViewCreateFlag, VkImageViewCreateFlags>;

				      EType                   SType           ;			
				const void*                   Next            ;
				      CreateFlags             Flags           ;
				      Image::Handle           Image           ;
				      EViewType               ViewType        ;
				      EFormat                 Format          ;
				      ComponentMapping        Components      ;
				      Image::SubresourceRange SubresourceRange;
			};

			

			/**
			 * @brief Create an image view object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateImageView">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _imageView
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _creationSpec,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _imageView
			)
			{
				return EResult(vkCreateImageView(_deviceHandle, _creationSpec, _allocator->operator const VkAllocationCallbacks*(), &_imageView));
			}

			/**
			 * @brief Destroy an image view.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyImageView">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _imageView
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle _deviceHandle,
				      Handle                _imageView   ,
				const Memory::AllocationCallbacks*  _allocator
			)
			{
				vkDestroyImageView(_deviceHandle, _imageView, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-sets">Specification</a>
		 */
		struct DescriptorSet
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSet">Specification</a>  */
			using Handle = VkDescriptorSet;

			

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBufferInfo">Specification</a>  */
			struct BufferInfo : V0::VKStruct_Base<VkDescriptorBufferInfo>
			{
				Buffer::Handle Buffer;
				DeviceSize     Offset;
				DeviceSize     Range ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCopyDescriptorSet">Specification</a>  */
			struct Copy : V0::VKStruct_Base<VkCopyDescriptorSet>
			{
				      EType  SType          ;
				const void*  Next           ;
				      Handle SrcSet         ;
				      uint32 SrcBinding     ;
				      uint32 SrcArrayElement;
				      Handle DstSet         ;
				      uint32 DstBinding     ;
				      uint32 DstArrayElement;
				      uint32 DescriptorCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorImageInfo">Specification</a>  */
			struct ImageInfo : V0::VKStruct_Base<VkDescriptorImageInfo>
			{
				Sampler::Handle   Sampler    ;
				ImageView::Handle ImageView  ;
				EImageLayout      ImageLayout;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWriteDescriptorSet">Specification</a>  */
			struct Write : V0::VKStruct_Base<VkWriteDescriptorSet, EStructureType::WriteDescriptor_Set>
			{
				      EType               SType          ;
				const void*               Next           ;
				      Handle              DstSet         ;
				      uint32              DstBinding     ;
				      uint32              DstArrayElement;
				      uint32              DescriptorCount;
				      EDescriptorType     DescriptorType ;
				const ImageInfo*          ImageInfo      ;
				const BufferInfo*         BufferInfo     ;
				const BufferView::Handle* TexelBufferView;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkUpdateDescriptorSets">Specification</a> .
			 * 
			 * \param _device
			 * \param _descriptorWriteCount
			 * \param _descriptorWrites
			 * \param _descriptorCopyCount
			 * \param _descriptorCopies
			 */
			static void Update
			(
				      LogicalDevice::Handle _device              ,
				      uint32                _descriptorWriteCount,
				const Write*                _descriptorWrites    ,
				      uint32                _descriptorCopyCount ,
				const Copy*                 _descriptorCopies
			)
			{
				vkUpdateDescriptorSets(_device, _descriptorWriteCount, _descriptorWrites->operator const VkWriteDescriptorSet*(), _descriptorCopyCount, _descriptorCopies->operator const VkCopyDescriptorSet*());
			}
		};	

		struct DescriptorPool
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPool">Specification</a>  */
			using Handle = VkDescriptorPool;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EDescriptorPoolCreateFlag, VkDescriptorPoolCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolResetFlags">Specification</a>  */
			using ResetFlags = Bitmask<EUndefined, VkDescriptorPoolResetFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetAllocateInfo">Specification</a>  */
			struct AllocateInfo : V0::VKStruct_Base<VkDescriptorSetAllocateInfo, EStructureType::Descriptor_SetAllocateInfo>
			{
				using PipelineLayoutDescriptorSetHandle = VkDescriptorSetLayout;   // Pipeline definitions not defined yet.

					  EType                              SType             ;
				const void*                              Next              ;
					  Handle                             DescriptorPool    ;
					  uint32                             DescriptorSetCount;
				const PipelineLayoutDescriptorSetHandle* SetLayouts        ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolSize">Specification</a>  */
			struct Size : V0::VKStruct_Base<VkDescriptorPoolSize>
			{
				EDescriptorType Type ;
				uint32          Count;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorPoolCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkDescriptorPoolCreateInfo, EStructureType::Descriptor_Pool_CreateInfo>
			{
					  EType       SType        ;
				const void*       Next         ;
					  CreateFlags Flags        ;
					  uint32      MaxSets      ;
					  uint32      PoolSizeCount;
				const Size*       PoolSizes    ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateDescriptorSets">Specification</a> 
			 * 
			 * \param _device
			 * \param _allocateInfo
			 * \param _descriptorSets
			 * \return 
			 */
			static EResult Allocate
			(
					  LogicalDevice::Handle  _device        ,
				const AllocateInfo&          _allocateInfo  ,
					  DescriptorSet::Handle* _descriptorSets
			)
			{
				return EResult(vkAllocateDescriptorSets(_device, _allocateInfo, _descriptorSets));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDescriptorPool">Specification</a>
			 * 
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _descriptorPool
			 * \return 
			 */
			static EResult Create
			(
					  LogicalDevice::Handle         _device        ,
				const CreateInfo&                   _createInfo    ,
				const Memory::AllocationCallbacks*  _allocator     ,
					  Handle&                       _descriptorPool
			)
			{
				return EResult(vkCreateDescriptorPool(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_descriptorPool));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDescriptorPool">Specification</a> 
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _device,
				      Handle                       _descriptorPool,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyDescriptorPool(_device, _descriptorPool, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeDescriptorSets">Specification</a> 
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _descriptorSetCount
			 * \param _descriptorSets
			 * \return 
			 */
			static EResult Free
			(
				      LogicalDevice::Handle  _device            ,
				      Handle                 _descriptorPool    ,
				      uint32                 _descriptorSetCount,
				const DescriptorSet::Handle* _descriptorSets
			)
			{
				return EResult(vkFreeDescriptorSets(_device, _descriptorPool, _descriptorSetCount, _descriptorSets));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetDescriptorPool">Specification</a> 
			 * 
			 * \param _device
			 * \param _descriptorPool
			 * \param _flags
			 * \return 
			 */
			static EResult Reset
			(
				LogicalDevice::Handle _device        ,
				Handle                _descriptorPool,
				ResetFlags&           _flags
			)
			{
				return EResult(vkResetDescriptorPool(_device, _descriptorPool, _flags));
			}
		};
	}

	namespace V2
	{
		struct Buffer : V1::Buffer
		{
			using Parent = V1::Buffer;

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo() 
				{
					SType                 = STypeEnum;
					Next                  = nullptr  ;
					Size                  = 0        ;
					QueueFamilyIndexCount = 0        ;
				}

				CreateInfo(UsageFlags _usage, ESharingMode _sharingMode)
				{
					SType                 = STypeEnum   ;
					Next                  = nullptr     ;
					Size                  = 0           ;
					Usage                 = _usage      ;
					SharingMode           = _sharingMode;
					QueueFamilyIndexCount = 0           ;
				}
			};

			struct Memory_Barrier : Parent::Memory_Barrier
			{
				Memory_Barrier()
				{
					SType = STypeEnum;

					Next = nullptr;
				}
			};

			/**
			 * @brief Create a new buffer object. (Default allocator)
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _buffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _createInfo, Handle& _buffer)
			{
				return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _buffer);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a buffer object. (Default allocator)

			 * \param _deviceHandle
			 * \param _buffer
			 * \param _allocator
			 * \return 
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _buffer)
			{
				Parent::Destroy(_device, _buffer, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Will create a buffer and immediately bind it to allocated memory made just for it.
			 * 
			 * \param _bufferInfo
			 * \param _propertyFlags
			 * \param _buffer
			 * \param _bufferMemory
			 * \param _bufferMemoryOffset
			 * \param _physicalDevice
			 * \param _device
			 * \param _allcator
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle _physicalDevice,
				LogicalDevice::Handle  _device        ,
				CreateInfo             _bufferInfo    ,
				Handle&                _buffer        , 
				Memory::PropertyFlags  _propertyFlags , 
				Memory::Handle&        _bufferMemory      
			)
			{
				EResult returnCode = Buffer::Create(_device, _bufferInfo, Memory::DefaultAllocator, _buffer);

				if (returnCode != EResult::Success)
					return returnCode;

				Memory::Requirements memReq;

				Buffer::GetMemoryRequirements(_device, _buffer, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, Memory::DefaultAllocator, _bufferMemory);

				if (returnCode != EResult::Success)
					return returnCode;

				Buffer::BindMemory(_device, _buffer, _bufferMemory, Memory::ZeroOffset);

				return returnCode;
			}

			/**
			 * @brief Will create a buffer and immediately bind it to allocated memory made just for it.
			 * 
			 * \param _bufferInfo
			 * \param _propertyFlags
			 * \param _buffer
			 * \param _bufferMemory
			 * \param _bufferMemoryOffset
			 * \param _physicalDevice
			 * \param _device
			 * \param _allcator
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle       _physicalDevice,
				LogicalDevice::Handle        _device        ,
				CreateInfo                   _bufferInfo    ,
				Handle&                      _buffer        , 
				Memory::PropertyFlags        _propertyFlags , 
				Memory::Handle&              _bufferMemory  ,
				Memory::AllocationCallbacks* _allcator
			)
			{
				EResult returnCode = Buffer::Create(_device, _bufferInfo, _allcator, _buffer);

				if (returnCode != EResult::Success) return returnCode;

				Memory::Requirements memReq;

				Buffer::GetMemoryRequirements(_device, _buffer, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, _allcator, _bufferMemory);

				if (returnCode != EResult::Success) return returnCode;

				Buffer::BindMemory(_device, _buffer, _bufferMemory, Memory::ZeroOffset);

				return returnCode;
			}
		};

		struct BufferView : public V1::BufferView
		{
			using Parent = V1::BufferView;

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			* @brief Create a new buffer view object.
			* 
			* \param _deviceHandle
			* \param _creationSpec
			* \param _allocator
			* \param _bufferView
			* \return 
			*/
			static EResult Create(LogicalDevice::Handle _device, const CreateInfo& _info, Handle& _bufferView)
			{
				return Parent::Create(_device, _info, Memory::DefaultAllocator, _bufferView);
			}

			using Parent::Create;

			/**
			* @brief Destroy a buffer view object.
			* 
			* \param _deviceHandle
			* \param _bufferView
			* \param _allocator
			*/
			static void Destroy(LogicalDevice::Handle _device, Handle _bufferView)
			{
				Parent::Destroy(_device, _bufferView, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		struct Image : public V1::Image
		{
			using Parent = V1::Image;

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct Memory_Barrier : public Parent::Memory_Barrier
			{
				Memory_Barrier()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**  
			 * @brief  Create an image object.
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _imageHandle
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHandle, const CreateInfo& _createInfo, Handle& _imageHandle)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _imageHandle);
			}

			using Parent::Create;

			/** 
			 * @brief Destroy an image object.
			 * 
			 * \param _deviceHandle
			 * \param _image
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _image)
			{
				Parent::Destroy(_deviceHandle, _image, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Will create an image and immediately bind it to memory made just for it.
			 * 
			 * \param _physicalDevice
			 * \param _device
			 * \param _info
			 * \param _image
			 * \param _propertyFlags
			 * \param _imageMemory
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle _physicalDevice,
				LogicalDevice::Handle  _device        ,
				CreateInfo             _info          ,
				Handle&                _image         , 
				Memory::PropertyFlags  _propertyFlags , 
				Memory::Handle&        _imageMemory      
			)
			{
				EResult returnCode = Image::Create(_device, _info, _image);

				if (returnCode != EResult::Success)
					return returnCode;

				Memory::Requirements memReq;

				Image::GetMemoryRequirements(_device, _image, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, _imageMemory);

				if (returnCode != EResult::Success)
					return returnCode;

				Image::BindMemory(_device, _image, _imageMemory, Memory::ZeroOffset);

				return returnCode;
			}

			/**
			 * @brief Will create an image and immediately bind it to memory made just for it..
			 * 
			 * \param _physicalDevice
			 * \param _device
			 * \param _info
			 * \param _image
			 * \param _propertyFlags
			 * \param _imageMemory
			 * \return 
			 */
			static EResult CreateAndBind
			(
				PhysicalDevice::Handle       _physicalDevice,
				LogicalDevice::Handle        _device        ,
				CreateInfo                   _info          ,
				Handle&                      _image         , 
				Memory::PropertyFlags        _propertyFlags , 
				Memory::Handle&              _imageMemory   ,
				Memory::AllocationCallbacks* _allcator
			)
			{
				EResult returnCode = Image::Create(_device, _info, _allcator, _image);

				if (returnCode != EResult::Success)
					return returnCode;

				Memory::Requirements memReq;

				Image::GetMemoryRequirements(_device, _image, memReq);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize  = memReq.Size;
				allocationInfo.MemoryTypeIndex = PhysicalDevice::FindMemoryType(_physicalDevice, memReq.MemoryTypeBits, _propertyFlags);

				returnCode = Memory::Allocate(_device, allocationInfo, _allcator, _imageMemory);

				if (returnCode != EResult::Success)
					return returnCode;

				Image::BindMemory(_device, _image, _imageMemory, Memory::ZeroOffset);

				return returnCode;
			}
		};

		struct ImageView : public V1::ImageView
		{
			using Parent = V1::ImageView;

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;

					Components.R = Corridors::EComponentSwizzle::R;
					Components.G = Corridors::EComponentSwizzle::G;
					Components.B = Corridors::EComponentSwizzle::B;
					Components.A = Corridors::EComponentSwizzle::A;
				}
			};

			/**
			 * @brief Create an image view object.
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _imageView
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _creationSpec,
				      Handle&                      _imageView
			)
			{
				return Parent::Create(_deviceHandle, _creationSpec, Memory::DefaultAllocator, _imageView);
			}

			using Parent::Create;

			/**
			 * @brief Destroy an image view.
			 * 
			 * \param _deviceHandle
			 * \param _imageView
			 * \param _allocator
			 */
			static void Destroy
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _imageView   
			)
			{
				return Parent::Destroy(_deviceHandle, _imageView, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		struct DescriptorSet : public V1::DescriptorSet
		{
			using Parent = V1::DescriptorSet;

			struct Copy : public Parent::Copy
			{
				Copy()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct Write : public Parent::Write
			{
				Write()
				{
					SType = STypeEnum;
					Next  = nullptr;
				}
			};

			
		};

		struct DescriptorPool : public V1::DescriptorPool
		{
			using Parent = V1::DescriptorPool;

			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _descriptorPool
			 * \return 
			 */
			static EResult Create
			(
					  LogicalDevice::Handle _device        ,
				const CreateInfo&           _createInfo    ,
					  Handle&               _descriptorPool
			)
			{
				return Parent::Create(_device, _createInfo, Memory::DefaultAllocator, _descriptorPool);
			}

			using Parent::Create;

			/**
			 * \param _device
			 * \param _descriptorPool
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _device, Handle _descriptorPool)
			{
				Parent::Destroy(_device, _descriptorPool, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			static EResult Free
			(
				      LogicalDevice::Handle  _device,
				const AllocateInfo&          _info,
				const DescriptorSet::Handle* _descriptorSets
			)
			{
				return Parent::Free(_device, _info.DescriptorPool, _info.DescriptorSetCount, _descriptorSets);
			}

			using Parent::Free;
		};
	}

	namespace V3
	{
		class Buffer : public V2::Buffer
		{
		public:

			using Parent = V2::Buffer;

			EResult BindMemory(Memory::Handle _memory, DeviceSize _memoryOffset)
			{
				memory       = _memory      ;
				memoryOffset = _memoryOffset;

				return Parent::BindMemory(device, handle, memory, memoryOffset);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _createInfo)
			{
				device    = _device                 ;
				info      = _createInfo             ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Parent::Create(device, info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(device, handle, memoryRequirements);
				
				return returnCode;
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _createInfo, const Memory::AllocationCallbacks* _allocator)
			{
				device    =  _device    ;
				info      = _createInfo ;
				allocator = _allocator  ;

				EResult returnCode = Parent::Parent::Create(device, info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(device, handle, memoryRequirements);
				
				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&        _device        ,  
				      CreateInfo&           _info          ,  
				      Memory::PropertyFlags _memoryFlags   ,
				      Memory&               _memory
			)
			{
				device    = _device.GetHandle()    ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Create(device, info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(device, handle, memoryRequirements);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(device, allocationInfo, allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory.GetHandle(), Memory::ZeroOffset);

				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&               _device        ,  
				      CreateInfo&                  _info          , 
				      Memory::PropertyFlags        _memoryFlags   ,
				      Memory&                      _memory        ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = _device.GetHandle();
				info      = _info              ;
				allocator = _allocator         ;

				EResult returnCode = Parent::Create(device, info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(device, handle, memoryRequirements);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(device, allocationInfo, allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory.GetHandle(), Memory::ZeroOffset);

				return returnCode;
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			const Memory::Requirements& GetMemoryRequirements() const
			{
				return memoryRequirements;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}
			
			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			CreateInfo info;

			LogicalDevice::Handle device;

			Memory::Handle memory;

			DeviceSize memoryOffset;

			Memory::Requirements memoryRequirements;

			const Memory::AllocationCallbacks* allocator;
		};

		class BufferView : public V2::BufferView
		{
		public:
			using Parent = V2::BufferView;

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device                 ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, allocator, handle);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			CreateInfo info;

			LogicalDevice::Handle device;

			const Memory::AllocationCallbacks* allocator;
		};

		class Image : public V2::Image
		{
		public:
			using Parent = V2::Image;


			void Assign(LogicalDevice::Handle _device, Handle _handle)
			{
				device = _device;
				handle = _handle;
			}

			EResult BindMemory(Memory::Handle _memory, DeviceSize _memoryOffset)
			{
				memory       = _memory      ;
				memoryOffset = _memoryOffset;

				return Parent::BindMemory(device, handle, memory, memoryOffset);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device                 ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Create(device, info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(device, handle, memoryRequirements);

				return returnCode;
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				EResult returnCode = Parent::Create(device, info, allocator, handle);

				if (returnCode == EResult::Success)
					Parent::GetMemoryRequirements(device, handle, memoryRequirements);

				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&        _device        ,  
				      CreateInfo&           _info          ,  
				      Memory::PropertyFlags _memoryFlags   ,
				      Memory&               _memory
			)
			{
				device    = _device.GetHandle()    ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				EResult returnCode = Parent::Create(device, info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(device, handle, memoryRequirements);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(device, allocationInfo, allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory.GetHandle(), Memory::ZeroOffset);

				return returnCode;
			}

			EResult CreateAndBind
			(
				const LogicalDevice&               _device        ,  
				      CreateInfo&                  _info          , 
				      Memory::PropertyFlags        _memoryFlags   ,
				      Memory&                      _memory        ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = _device.GetHandle();
				info      = _info              ;
				allocator = _allocator         ;

				EResult returnCode = Parent::Create(device, info, allocator, handle);

				if (returnCode != EResult::Success) return returnCode;

				Parent::GetMemoryRequirements(device, handle, memoryRequirements);

				Memory::AllocateInfo allocationInfo{};

				allocationInfo.AllocationSize = memoryRequirements.Size;

				allocationInfo.MemoryTypeIndex = 
					_device.GetPhysicalDevice().FindMemoryType(memoryRequirements.MemoryTypeBits, _memoryFlags);

				returnCode = _memory.Allocate(device, allocationInfo, allocator);

				if (returnCode != EResult::Success) return returnCode;

				BindMemory(_memory.GetHandle(), Memory::ZeroOffset);

				return returnCode;
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			Handle GetHandle() const
			{
				return handle;
			}

			const Memory::Requirements& GetMemoryRequirements() const
			{
				return memoryRequirements;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			Memory::Handle memory;

			DeviceSize memoryOffset;

			Memory::Requirements memoryRequirements;

			LogicalDevice::Handle device;
		};

		class ImageView : public V2::ImageView
		{
		public:
			using Parent = V2::ImageView;

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device                 ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, allocator, handle);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			Handle GetHandle()
			{
				return handle;
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:	

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};

		class DescriptorSet : public V2::DescriptorSet
		{
		public:
			using Parent = V2::DescriptorSet;

			void Assign(LogicalDevice::Handle& _device, Handle _handle)
			{
				device = _device;
				handle = _handle;
			}
			
			const Handle& GetHandle() const
			{
				return handle;
			}

			void Update
			(
				      uint32                _descriptorWriteCount,
				const Write*                _descriptorWrites    ,
				      uint32                _descriptorCopyCount ,
				const Copy*                 _descriptorCopies
			)
			{
				Parent::Update(device, _descriptorWriteCount, _descriptorWrites, _descriptorCopyCount, _descriptorCopies);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			LogicalDevice::Handle device;
		};

		class DescriptorPool : public V2::DescriptorPool
		{
		public:
			using Parent = V2::DescriptorPool;


			EResult Allocate(AllocateInfo& _info, DescriptorSet::Handle* _handlesContainer)
			{
				return Parent::Allocate(device, _info, _handlesContainer);
			}

			EResult Allocate
			(
				AllocateInfo&                       _info   ,
				std::vector<DescriptorSet>&         _sets   ,
				std::vector<DescriptorSet::Handle>& _handles
			)
			{
				_sets.resize(_info.DescriptorSetCount); _handles.resize(_info.DescriptorSetCount);

				EResult returnCode = Parent::Allocate(device, _info, _handles.data());

				if (returnCode != EResult::Success) return returnCode;

				for (DeviceSize index = 0; index < _info.DescriptorSetCount; index++)
				{
					_sets[index].Assign(device, _handles[index]);
				}

				return returnCode;
			}

			EResult Create(const LogicalDevice& _device, CreateInfo& _info)
			{
				device    = _device.GetHandle()     ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, allocator, handle);
			}

			EResult Create(const LogicalDevice& _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device.GetHandle();
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			EResult Free(uint32 _count, DescriptorSet::Handle* _handles)
			{
				return Parent::Free(device, handle, _count, _handles);
			}

			EResult Free(std::vector<DescriptorSet::Handle> _handles)
			{
				return Parent::Free(device, handle, static_cast<uint32>(_handles.size()), _handles.data());
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult Reset(ResetFlags& _flags)
			{
				return Parent::Reset(device, handle, _flags);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};
	}
}




/*
@file VT_SyncAndCacheControl

@brief Vaulted Thermals: Synchronization and Cache Control

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-events">Specification</a> 
		 */
		struct Event
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkEvent">Specification</a>  */
			using Handle = VkEvent;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkEventCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkEventCreateInfo, EStructureType::Event_CreateInfo>
			{
				using CreateFlags = Bitmask<EUndefined, VkEventCreateFlags>;

				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			 * @brief.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateEvent">Specification</a> 
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
				return EResult(vkCreateEvent(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_event));
			}

			/**
			 * @brief 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyEvent">Specification</a> 
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
				vkDestroyEvent(_device, _event, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetEventStatus">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetEvent">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkSetEvent">Specification</a> 
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
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-fences">Specification</a> 
		 */
		struct Fence
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFence">Specification</a>  */
			using Handle = VkFence;

			using EExternalHandleTypeFlag = EExternalFenceHandleTypeFlag;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateFlags">Specification</a> 
			 */
			using CreateFlags = Bitmask<EFenceCreateFlag, VkFenceCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalFenceHandleTypeFlags">Specification</a>  */
			using ExternalHandleFlags = Bitmask<EExternalFenceHandleTypeFlag, VkExternalFenceHandleTypeFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateInfo">Specification</a> 
			 */
			struct CreateInfo : V0::VKStruct_Base<VkFenceCreateInfo, EStructureType::Fence_CreateInfo>
			{
				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceEventInfoEXT">Specification</a> 
			*/
			struct DeviceEventInfo : V0::VKStruct_Base<VkDeviceEventInfoEXT, EStructureType::Device_EventInfo_EXT>
			{
				      EType            SType      ;
				const void*            Next       ;
				      EDeviceEventType DeviceEvent;
			};

/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDisplayEventInfoEXT">Specification</a> 
			*/
			struct DisplayEventInfo : V0::VKStruct_Base<VkDisplayEventInfoEXT, EStructureType::Display_EventInfo_EXT>
			{
				      EType             SType       ;
				const void*             Next        ;
				      EDisplayEventType DisplayEvent;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportFenceWin32HandleInfoKHR">Specification</a> 
			*/
			struct ExportableWin32 : V0::VKStruct_Base<VkExportFenceWin32HandleInfoKHR, EStructureType::ExportFence_Win32Handle_Info_KHR>
			{
				      EType                SType     ;
				const void*                Next      ;
				const SECURITY_ATTRIBUTES* Attributes;
				      DWORD                DW_Access ;
				      LPCWSTR              Name      ;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceGetFdInfoKHR">Specification</a> 
			*/
			struct GetPOSIX_FileDescriptorInfo : V0::VKStruct_Base<VkFenceGetFdInfoKHR, EStructureType::Fence_Get_FD_Info_KHR>
			{
				      EType                   SType     ;
				const void*                   Next      ;
				      Handle                  Fence     ;
					  EExternalHandleTypeFlag HandleType;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceGetWin32HandleInfoKHR">Specification</a> 
			*/
			struct GetWin32HandleInfo : V0::VKStruct_Base<VkFenceGetWin32HandleInfoKHR, EStructureType::Fence_GetWin32Handle_Info_KHR>
			{
				      EType                   SType     ;
				const void*                   Next      ;
				      Handle                  Fence     ;
					  EExternalHandleTypeFlag HandleType;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportFenceFdInfoKHR">Specification</a>
			 */
			struct ImportFencePOSIX_FileDescriptorInfo : V0::VKStruct_Base<VkImportFenceFdInfoKHR, EStructureType::ImportFence_FD_Info_KHR>
			{
				      EType                        SType         ;
				const void*                        Next          ;
				      Handle                       Fence         ;
				      FenceImportFlags             Flags         ;
					  EExternalHandleTypeFlag HandleType    ;
				      int                          FileDescriptor;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportFenceWin32HandleInfoKHR">Specification</a> 
			 */
			struct ImportFenceWin32HandleInfo : V0::VKStruct_Base<VkImportFenceWin32HandleInfoKHR, EStructureType::ImportFence_Win32Handle_Info_KHR>
			{
				      EType                        SType     ;
				const void*                        Next      ;
				      Handle                       Fence     ;
					  FenceImportFlags             Flags     ;
					  EExternalHandleTypeFlag HandleType;
				      HANDLE                       Handle    ;
				      LPCWSTR                      Name      ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportFenceCreateInfo">Specification</a> 
			 */
			struct ExportCreateInfo : V0::VKStruct_Base<VkExportFenceCreateInfo, EStructureType::ExportFence_CreateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      ExternalHandleFlags HandleTypes;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateFence">Specification</a> 
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
				return EResult(vkCreateFence(_logicalDevice, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyFence">Specification</a> 
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
				vkDestroyFence(_logicalDevice, _fence, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceStatus">Specification</a> 
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
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceWin32HandleKHR">Specification</a>  
			* \return 
			*/
			static EResult GetWin32Handle
			(
				      LogicalDevice::Handle _device            ,
				const GetWin32HandleInfo&   _getWin32HandleInfo,
				      HANDLE&               _winHandle
			)
			{
				return EResult(vkGetFenceWin32HandleKHR(_device, _getWin32HandleInfo, &_winHandle));
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceFdKHR">Specification</a>  
			* 
			* \param device
			* \param pGetFdInfo
			* \param pFd
			* \return 
			*/
			static EResult GetPOSIX_FileDescriptor
			(
				      LogicalDevice::Handle        _device        ,
				const GetPOSIX_FileDescriptorInfo& _fdInfo        ,
				      int*                         _fileDescriptor
			)
			{
				return EResult(vkGetFenceFdKHR(_device, _fdInfo, _fileDescriptor));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportFenceFdKHR">Specification</a>
			 * 
			 * \param _device
			 * \param _importInfo
			 * \return 
			 */
			static EResult ImportFence_POSIX_FileDescriptor
			(
				      LogicalDevice::Handle                _device    ,
				const ImportFencePOSIX_FileDescriptorInfo& _importInfo
			)
			{
				return EResult(vkImportFenceFdKHR(_device, _importInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportFenceWin32HandleKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pImportFenceWin32HandleInfo
			 * \return 
			 */
			static EResult ImportFenceWin32Handle
			(
				      LogicalDevice::Handle       _device    ,
				const ImportFenceWin32HandleInfo& _importInfo
			)
			{
				return EResult(vkImportFenceWin32HandleKHR(_device, _importInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkRegisterDeviceEventEXT">Specification</a> 
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
				return EResult(vkRegisterDeviceEventEXT(_device, _deviceEventInfo, _allocator->operator const VkAllocationCallbacks*(), &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkRegisterDisplayEventEXT">Specification</a> 
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
				return EResult(vkRegisterDisplayEventEXT(_device, _display, _displayEventInfo, _allocator->operator const VkAllocationCallbacks*(), &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetFences">Specification</a> 
			 * 
			 * \param _logicalDevice
			 * \param _fences
			 * \param _fenceCount
			 * \return 
			 */
			static EResult Reset(LogicalDevice::Handle _logicalDevice, Handle* _fences, uint32 _fenceCount)
			{
				return EResult(vkResetFences(_logicalDevice, _fenceCount, _fences));
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
				const Handle*               _fences    ,
				      Bool                  _waitAll   ,
				      uInt64                _timeout
			)
			{
				return EResult(vkWaitForFences(_device, _fenceCount, _fences, _waitAll, _timeout));
			}
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-semaphores">Specification</a> 
		 */
		struct Semaphore
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphore">Specification</a> .
			 */
			using Handle = VkSemaphore;

			using EExternalHandleType = EExternalSemaphoreHandleTypeFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreImportFlags">Specification</a>  */
			using ImportFlags = Bitmask<ESemaphoreImportFlag, VkSemaphoreImportFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitFlags">Specification</a>  */
			using WaitFlags = Bitmask<ESemaphoreWaitFlag, VkSemaphoreWaitFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreCreateInfo">Specification</a> 
			 */
			struct CreateInfo : V0::VKStruct_Base<VkSemaphoreCreateInfo, EStructureType::Semaphore_CreateInfo>
			{
				using CreateFlags = Bitmask<EUndefined, VkSemaphoreCreateFlags>;

				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportSemaphoreCreateInfo">Specification</a> 
			 */
			struct ExportCreateInfo : V0::VKStruct_Base<VkExportSemaphoreCreateInfo, EStructureType::Export_Semaphore_CreateInfo_KHR>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalSemaphoreHandleTypeFlags">Specification</a>  */
				using ExternalHandleTypeFlags = Bitmask<EExternalSemaphoreHandleTypeFlag, VkExternalSemaphoreHandleTypeFlags>;

				      EType                   SType      ;
				const void*                   Next       ;
				      ExternalHandleTypeFlags HandleTypes;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportSemaphoreWin32HandleInfoKHR">Specification</a>  */
				struct Win32HandleInfo : V0::VKStruct_Base<VkExportSemaphoreWin32HandleInfoKHR, EStructureType::ExportSemaphore_Win32Handle_Info_KHR>
				{
					      EType                SType     ;
					const void*                Next      ;
					const SECURITY_ATTRIBUTES* Attributes;
					      DWORD                DWAccess  ;
					      LPCWSTR              Name      ;
				};
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreGetFdInfoKHR">Specification</a>  */
			struct GetPOSIX_FileDescriptorInfo : V0::VKStruct_Base<VkSemaphoreGetFdInfoKHR, EStructureType::Semaphore_Get_FD_Info_KHR>
			{
				      EType               SType     ;
				const void*               Next      ;
				      Handle              Semaphore ;
				      EExternalHandleType HandleType;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreGetWin32HandleInfoKHR">Specification</a>  */
			struct GetWin32HandleInfo : V0::VKStruct_Base<VkSemaphoreGetWin32HandleInfoKHR, EStructureType::Semaphore_GetWin32Handle_Info_KHR>
			{
				      EType               SType     ;
				const void*               Next      ;
				      Handle              Semaphore ;
				      EExternalHandleType HandleType;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportSemaphoreFdInfoKHR">Specification</a>  */
			struct ImportPOSIX_FileDescriptorInfo : V0::VKStruct_Base<VkImportSemaphoreFdInfoKHR, EStructureType::ImportSemaphore_FD_Info_KHR>
			{
				      EType               SType         ;
				const void*               Next          ;
				      Handle              Semaphore     ;
				      ImportFlags         Flags         ;
				      EExternalHandleType HandleType    ;
				      int                 FileDescriptor;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportSemaphoreWin32HandleInfoKHR">Specification</a>  */
			struct ImportWin32HandleInfo : V0::VKStruct_Base<VkImportSemaphoreWin32HandleInfoKHR, EStructureType::ImportSemaphore_Win32Handle_Info_KHR>
			{
				      EType               SType     ;
				const void*               Next      ;
				      Handle              Semaphore ;
				      ImportFlags         Flags     ;
				      EExternalHandleType HandleType;
				      HANDLE              Handle    ;
				      LPCWSTR             Name      ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreSignalInfo">Specification</a>  */
			struct SignalInfo : V0::VKStruct_Base<VkSemaphoreSignalInfo, EStructureType::Semaphore_SignalInfo>
			{
				      EType  SType    ;
				const void*  Next     ;
				      Handle Semaphore;
				      uInt64 Value    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreTypeCreateInfo">Specification</a>  */
			struct TypeSpecifiedCreateInfo : V0::VKStruct_Base<VkSemaphoreTypeCreateInfo, EStructureType::SemaphoreType_CreateInfo>
			{
				      EType  SType        ;
				const void*  Next         ;
				      Handle SemaphoreType;
				      uInt64 InitialValue ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitInfo">Specification</a>  */
			struct WaitInfo : V0::VKStruct_Base<VkSemaphoreWaitInfo, EStructureType::Semaphore_WaitInfo>
			{
				      EType     SType         ;
				const void*     Next          ;
				      WaitFlags Flags         ;
				      uint32    SemaphoreCount;
				const Handle*   Semaphores    ;
				const uInt64*   Values        ;
			};


			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSemaphore">Specification</a> 
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
				return EResult(vkCreateSemaphore(_device, _createInfo.operator const VkSemaphoreCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_semaphore));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySemaphore">Specification</a> 
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
				vkDestroySemaphore(_device, _semaphore, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreCounterValue">Specification</a> 
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
				uInt64&               _value
			)
			{
				return EResult(vkGetSemaphoreCounterValue(_device, _semaphore, &_value));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreFdKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pGetFdInfo
			 * \param pFd
			 * \return 
			 */
			static EResult GetPOSIX_FileDescriptor
			(
				      LogicalDevice::Handle        _device        ,
				const GetPOSIX_FileDescriptorInfo& _getInfo       ,
				      int*                         _fileDescriptor
			)
			{
				return EResult(vkGetSemaphoreFdKHR(_device, _getInfo, _fileDescriptor));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreWin32HandleKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pGetWin32HandleInfo
			 * \param pHandle
			 * \return 
			 */
			static EResult GetWin32Handle
			(
				      LogicalDevice::Handle _device ,
				const GetWin32HandleInfo&   _getInfo,
				      HANDLE&               _handle
			)
			{
				return EResult(vkGetSemaphoreWin32HandleKHR(_device, _getInfo, &_handle));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportSemaphoreFdKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pImportSemaphoreFdInfo
			 * \return 
			 */
			static EResult ImportPOSIX_FileDescriptor(LogicalDevice::Handle _device, const ImportPOSIX_FileDescriptorInfo& _importPOSIX_Info)
			{
				return EResult(vkImportSemaphoreFdKHR(_device, _importPOSIX_Info));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportSemaphoreWin32HandleKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pImportSemaphoreWin32HandleInfo
			 * \return 
			 */
			static EResult ImportWin32Handle(LogicalDevice::Handle _device, const ImportWin32HandleInfo& _importHandleInfo)
			{
				return EResult(vkImportSemaphoreWin32HandleKHR(_device, _importHandleInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkSignalSemaphore">Specification</a> 
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
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkWaitSemaphores">Specification</a>.
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
				      uInt64                _timeout
			)
			{
				return EResult(vkWaitSemaphores(_device, _waitInfo, _timeout));
			}
		};
	}

	namespace V2
	{
		struct Event : public V1::Event
		{
			using Parent = V1::Event;

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			 * @brief.
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
			 * @brief 

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

		struct Fence : public V1::Fence
		{
			using Parent = V1::Fence;
			
			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct DeviceEventInfo : Parent::DeviceEventInfo
			{
				DeviceEventInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct DisplayEventInfo : Parent::DisplayEventInfo
			{
				DisplayEventInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ExportableWin32 : Parent::ExportableWin32
			{
				ExportableWin32()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct GetPOSIX_FileDescriptorInfo : Parent::GetPOSIX_FileDescriptorInfo
			{
				GetPOSIX_FileDescriptorInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct GetWin32HandleInfo : Parent::GetWin32HandleInfo
			{
				GetWin32HandleInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ImportFencePOSIX_FileDescriptorInfo : Parent::ImportFencePOSIX_FileDescriptorInfo
			{
				ImportFencePOSIX_FileDescriptorInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ImportFenceWin32HandleInfo : Parent::ImportFenceWin32HandleInfo
			{
				ImportFenceWin32HandleInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ExportCreateInfo : Parent::ExportCreateInfo
			{
				ExportCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			 * @brief 
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
			 * @brief 
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

		struct Semaphore : public V1::Semaphore
		{
			using Parent = V1::Semaphore;

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ExportCreateInfo : Parent::ExportCreateInfo
			{
				ExportCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct Win32HandleInfo : Parent::ExportCreateInfo::Win32HandleInfo
				{
					Win32HandleInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct GetPOSIX_FileDescriptorInfo : Parent::GetPOSIX_FileDescriptorInfo
			{
				GetPOSIX_FileDescriptorInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct GetWin32HandleInfo : Parent::GetWin32HandleInfo
			{
				GetWin32HandleInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ImportPOSIX_FileDescriptorInfo : Parent::ImportPOSIX_FileDescriptorInfo
			{
				ImportPOSIX_FileDescriptorInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct ImportWin32HandleInfo : Parent::ImportWin32HandleInfo
			{
				ImportWin32HandleInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct SignalInfo : Parent::SignalInfo
			{
				SignalInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct TypeSpecifiedCreateInfo : Parent::TypeSpecifiedCreateInfo
			{
				TypeSpecifiedCreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct WaitInfo : Parent::WaitInfo
			{
				WaitInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

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
	}

	namespace V3
	{
		class Event : public V2::Event
		{
		public:
			using Parent = V2::Event;

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult GetStatus()
			{
				return Parent::GetStatus(device, handle);
			}

			EResult Reset()
			{
				return Parent::Reset(device, handle);
			}

			EResult Set()
			{
				return Parent::Set(device, handle);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};

		class Fence : public V2::Fence
		{
		public:
			using Parent = V2::Fence;

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			LogicalDevice::Handle GetDeviceHandle() const
			{
				return device;
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult GetStatus()
			{
				return Parent::GetStatus(device, handle);
			}

			EResult GetWin32Handle(const GetWin32HandleInfo& _win32Info, HANDLE& _winHandle)
			{
				return Parent::GetWin32Handle(device, _win32Info, _winHandle);
			}

			EResult GetPOSIX_FileDescriptor(const GetPOSIX_FileDescriptorInfo& _fdInfo, int* _fileDescriptor)
			{
				return Parent::GetPOSIX_FileDescriptor(device, _fdInfo, _fileDescriptor);
			}

			EResult ImportFence_POSIX_FileDescriptor(const ImportFencePOSIX_FileDescriptorInfo& _importInfo)
			{
				return Parent::ImportFence_POSIX_FileDescriptor(device, _importInfo);
			}

			EResult ImportFenceWin32Handle(const ImportFenceWin32HandleInfo& _importInfo)
			{
				return Parent::ImportFenceWin32Handle(device, _importInfo);
			}

			EResult RegisterDeviceEvent(const DeviceEventInfo _eventInfo)
			{
				return Parent::RegisterDeviceEvent(device, _eventInfo, allocator, handle);
			}

			EResult RegisterDisplayEvent(Display::Handle _display, const DisplayEventInfo& _eventInfo)
			{
				return Parent::RegisterDisplayEvent(device, _display, _eventInfo, allocator, handle);
			}

			EResult Reset()
			{
				return Parent::Reset(device, &handle, 1);
			}

			static EResult Reset(std::vector<Fence> _fences)
			{
				auto device = _fences[0].GetDeviceHandle();

				std::vector<Fence::Handle> handles;

				for (auto fence : _fences) handles.push_back(fence.GetHandle());

				return Parent::Reset(device, handles.data(), static_cast<uint32>(_fences.size()));
			}

			EResult WaitFor(uInt64 _timeout)
			{
				return Parent::WaitForFences(device, 1, &handle, false, _timeout);
			}

			static EResult WaitForFence(std::vector<Fence> _fences, bool _waitForAll, uInt64 _timeout)
			{
				auto device = _fences[0].GetDeviceHandle();

				std::vector<Fence::Handle> handles;

				for (auto fence : _fences) handles.push_back(fence.GetHandle());

				return Parent::WaitForFences(device, static_cast<uint32>(_fences.size()), handles.data(), _waitForAll, _timeout);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};

		class Semaphore : public V2::Semaphore
		{
		public:
			using Parent = V2::Semaphore;

			EResult Create(const LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    =  _device  ;
				info      = _info     ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create(const LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			EResult GetCounterValue(uInt64& _value)
			{
				return Parent::GetCounterValue(device, handle, _value);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult GetPOSIX_FileDescriptor(const GetPOSIX_FileDescriptorInfo& _getInfo, int* _fileDescriptor)
			{
				return Parent::GetPOSIX_FileDescriptor(device, _getInfo, _fileDescriptor);
			}

			EResult GetWin32Handle(const GetWin32HandleInfo& _getInfo, HANDLE& _winHandle)
			{
				return Parent::GetWin32Handle(device, _getInfo, _winHandle);
			}

			EResult ImportPOSIX_FileDescriptor(const ImportPOSIX_FileDescriptorInfo& _importPOSIX_Info)
			{
				return Parent::ImportPOSIX_FileDescriptor(device, _importPOSIX_Info);
			}

			EResult ImportWin32Handle(const ImportWin32HandleInfo& _importHandleInfo)
			{
				return Parent::ImportWin32Handle(device, _importHandleInfo);
			}

			EResult Signal(const SignalInfo& _info)
			{
				return Parent::Signal(device, _info);
			}

			EResult WaitFor(const WaitInfo& _info, uInt64 _timeout)
			{
				return Parent::WaitFor(device, _info, _timeout);
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};
	}
}




/**
@file VT_Shaders.hpp

@brief 

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shaders">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief 
		 * Shader modules contain shader code and one or more entry points. 
		 * 
		 * @details
		 * Shaders are selected from a shader module by specifying an entry point as part of pipeline creation. 
		 * The stages of a pipeline can use shaders that come from different modules.
		 * 
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#shader-modules">Specification</a> 
		 */
		struct ShaderModule
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModule">Specification</a>  */
			using Handle = VkShaderModule;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a>  */
			using CreateFlags = Bitmask<EUndefined, Flags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderModuleCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkShaderModuleCreateInfo, EStructureType::ShaderModule_CreateInfo>
			{
				      EType             SType    ;
				const void*             Next     ;
				      CreateFlags       Flags    ;
				      DataSize          CodeSize ;
				const SPIR_V::Bytecode* Code     ;
			};

			/**
			 * @brief Create a sher module.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateShaderModule">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _shaderModule
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _creationSpec,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _shaderModule
			)
			{
				return EResult(vkCreateShaderModule(_deviceHandle, _creationSpec.operator const VkShaderModuleCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_shaderModule));
			}

			/**
			 * @brief Destroy a shader module.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyShaderModule">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _moduleHandle
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _moduleHandle, const Memory::AllocationCallbacks* _allocator)
			{
				return vkDestroyShaderModule(_deviceHandle, _moduleHandle, _allocator->operator const VkAllocationCallbacks*());
			}
		};
	}

	namespace V2
	{
		struct ShaderModule : public V1::ShaderModule
		{
			using Parent = V1::ShaderModule;

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType    = STypeEnum;
					Next     = nullptr  ;
					CodeSize = 0        ;
					Code     = nullptr  ;
				}

				CreateInfo(RoCStr _code, DataSize _codeSize)
				{
					using SPIR_V::Bytecode;

					SType    = STypeEnum;
					Next     = nullptr  ;
					CodeSize = _codeSize;
					Code     = reinterpret_cast<const Bytecode*>(_code);
				}
			};

			/**
			 * @brief Create a sher module.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _shaderModule
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _creationSpec,
				      Handle&               _shaderModule
			)
			{
				return Parent::Create(_deviceHandle, _creationSpec, Memory::DefaultAllocator, _shaderModule);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a shader module.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _moduleHandle
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _moduleHandle)
			{
				Parent::Destroy(_deviceHandle, _moduleHandle, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};
	}

	namespace V3
	{
		class ShaderModule : public V2::ShaderModule
		{
		public:
			
			using Parent = V2::ShaderModule;

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    =  _device                ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create
			(
				      LogicalDevice::Handle        _device   ,
				      CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};
	}
}




/**
@file VT_Pipelines.hpp

@brief Vaulted Thermals: Pipelines

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief A monolithic object describing the entire graphics, raytracing, or compute pipeline.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
		 */
		struct Pipeline
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipeline">Specification</a>  */
			using Handle = VkPipeline;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderStageFlags">Specification</a>  */
			using ShaderStageFlags = Bitmask<EShaderStageFlag, VkShaderStageFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineStageFlags">Specification</a>  */
			using StageFlags = Bitmask<EPipelineStageFlag, VkPipelineStageFlags>;

			/**
			 * @brief Pipeline cache objects allow the result of pipeline construction to be reused between pipelines and between runs of an application. 
			 * 
			 * @details
			 * Reuse between pipelines is achieved by passing the same pipeline cache object when creating multiple related pipelines. 
			 * Reuse across runs of an application is achieved by retrieving pipeline cache contents in one run of an application, saving the contents, 
			 * and using them to preinitialize a pipeline cache on a subsequent run. The contents of the pipeline cache objects are managed by the implementation. 
			 * Applications can manage the host memory consumed by a pipeline cache object and control the amount of data retrieved from a pipeline cache object.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-cache">Specification</a> 
			 */
			struct Cache
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.htmal#VkPipelineCache">Specification</a>  */
				using Handle = VkPipelineCache;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EPipelineCacheCreateFlag, VkPipelineCacheCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCacheCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineCacheCreateInfo, EStructureType::Pipeline_Cache_CreateInfo>
				{
					      EType       SType          ;
					const void*       Next           ;
					      CreateFlags Flags          ;
					      DataSize    InitialDataSize;
					const void*       InitialData    ;
				};

				/**
				 * @brief Create a pipeline cache.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreatePipelineCache">Specification</a>
				 * 
				 * \param _deviceHandle
				 * \param _createInfo
				 * \param _allocator
				 * \param _pipelineCache
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle ,
					const CreateInfo&                  _createInfo   ,
					const Memory::AllocationCallbacks* _allocator    ,
					      Cache::Handle&               _pipelineCache
				)
				{
					return EResult(vkCreatePipelineCache(_deviceHandle, _createInfo.operator const VkPipelineCacheCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_pipelineCache));
				}

				/**
				 * @brief Destroy a pipeline cache.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyPipelineCache">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _allocator
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Cache::Handle _cache, const Memory::AllocationCallbacks* _allocator)
				{
					vkDestroyPipelineCache(_deviceHandle, _cache, _allocator->operator const VkAllocationCallbacks*());
				}
			};

			/** @brief  */
			struct ColorBlendState
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineColorBlendAttachmentState">Specification</a>  */
				struct AttachmentState : V0::VKStruct_Base<VkPipelineColorBlendAttachmentState, EStructureType::Pipeline_ColorBlendAdvancedState_CreateInfo_EXT>
				{
					Bool                EnableBlend                 ;
					EBlendFactor        Source_ColorBlendFactor     ;
					EBlendFactor        Destination_ColorBlendFactor;
					EBlendOperation     ColorOperation              ;
					EBlendFactor        Source_AlphaBlendFactor     ;
					EBlendFactor        Destination_AlphaBlendFactor;
					EBlendOperation     AlphaOperation              ;
					ColorComponentFlags ColorWriteMask              ;
				};

				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineColorBlendStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineColorBlendStateCreateInfo, EStructureType::Pipeline_ColorBlendState_CreateInfo>
				{
					      EType            SType                ;
					const void*            Next                 ;
					      CreateFlags      Flags                ;
					      Bool             EnableLogicOperations;
					      ELogicOperation  LogicOperation       ;
					      uint32           AttachmentCount      ;
					const AttachmentState* Attachments          ;
					      float32          BlendConstants[4]    ;
				};
			};

			/** @brief */
			struct DepthStencilState
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDepthStencilStateCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EUndefined, VkPipelineDepthStencilStateCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDepthStencilStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineDepthStencilStateCreateInfo, EStructureType::Pipeline_DepthStencilState_CreateInfo>
				{
					      EType                 SType                ;			   
					const void*                 Next                 ;
					      CreateFlags           Flags                ;
					      Bool                  DepthTestEnable      ;
					      Bool                  DepthWriteEnable     ;
					      ECompareOperation     DepthCompareOp       ;
 					      Bool                  DepthBoundsTestEnable;
					      Bool                  StencilTestEnable    ;   
						  StencilOperationState Front                ;
						  StencilOperationState Back                 ;
					      float32               MinDepthBounds       ;
					      float32               MaxDepthBounds       ;
				};
			};

			/** @brief */
			struct DynamicState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineDynamicStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineDynamicStateCreateInfo, EStructureType::Pipeline_DynamicState_CreateInfo>
				{
					      EType          SType     ;
					const void*          Next      ;
					      CreateFlags    Flags     ;
					      uint32         StateCount;
					const EDynamicState* States    ;
				};
			};

			/** @brief */
			struct InputAssemblyState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineInputAssemblyStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineInputAssemblyStateCreateInfo, EStructureType::Pipeline_InputAssemblyState_CreateInfo>
				{
						  EType              SType                 ;
					const void*              Next                  ;
						  CreateFlags        Flags                 ;
						  EPrimitiveTopology Topology              ;
						  Bool               PrimitiveRestartEnable;
				};
			};

			/**
			 * @brief Access to descriptor sets from a pipeline is accomplished through a pipeline layout.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-pipelinelayout">Specification</a> 
			 */
			struct Layout
			{
				/** @ */
				using Handle = VkPipelineLayout;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPushConstantRange">Specification</a>  */
				struct PushConstantRange : V0::VKStruct_Base<VkPushConstantRange>
				{
					ShaderStageFlags StageFlags;
					uint32           Offset    ;
					uint32           Size      ;
				};


				/**
				 * @brief Descriptors are grouped together into descriptor set objects. 
				 * 
				 * @details
				 * A descriptor set object is an opaque object containing storage for a set of descriptors, 
				 * where the types and number of descriptors is defined by a descriptor set layout. 
				 * 
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#descriptorsets-setlayout">Specification</a> 
				 * @todo See if this should be outside of the layout structure.
				 */
				struct DescriptorSet
				{
					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayout">Specification</a>  */
					using Handle = VkDescriptorSetLayout;

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBinding">Specification</a>  */
					struct Binding : V0::VKStruct_Base<VkDescriptorSetLayoutBinding>
					{
						      uint32           BindingID        ;
						      EDescriptorType  Type             ;
						      uint32           Count            ;
						      ShaderStageFlags StageFlags       ;
						const Sampler::Handle* ImmutableSamplers;

						/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorBindingFlags">Specification</a>  */
						using CreateFlags = Bitmask<EDescriptorBindingFlag ,VkDescriptorBindingFlags>;

						/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutBindingFlagsCreateInfo">Specification</a>  */
						struct FlagsCreateInfo : V0::VKStruct_Base<VkDescriptorSetLayoutBindingFlagsCreateInfo, EStructureType::Descriptor_SetLayoutBindingFlags_CreateInfo>
						{
								   EType       SType       ;
							const void*        Next        ;
								  uint32       BindingCount;
							const CreateFlags* BindingFlags;
						};
					};

					using CreateFlags = Bitmask<EDescriptorSetLayoutCreateFlag, Flags>;

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutCreateInfo">Specification</a>  */
					struct CreateInfo : V0::VKStruct_Base<VkDescriptorSetLayoutCreateInfo, EStructureType::Descriptor_SetLayout_CreateInfo>
					{
						      EType       SType       ;
						const void*       Next   ;
						      CreateFlags Flags       ;
						      uint32      BindingCount;
						const Binding*    Bindings    ;
					};

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetLayoutSupport">Specification</a>  */
					struct Support : V0::VKStruct_Base<VkDescriptorSetLayoutSupport, EStructureType::Descriptor_SetLayoutSupport>
					{
						EType SType    ;
						void* Next     ;
						Bool  Supported;

						/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDescriptorSetVariableDescriptorCountLayoutSupport">Specification</a>  */
						struct SetVariableCount : V0::VKStruct_Base<VkDescriptorSetVariableDescriptorCountLayoutSupport, EStructureType::Descriptor_SetVariable_Descriptor_CountLayoutSupport>
						{
							EType  SType           ;
							void*  Next            ;
							uint32 MaxVariableCount;
						};
					};

					/**
					 * @brief Create a descriptor set layout.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDescriptorSetLayout">Specification</a> 
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _allocator
					 * \param _setLayout
					 * \return 
					 */
					static EResult Create
					(
						      LogicalDevice::Handle        _deviceHandle,
						const CreateInfo&                  _createInfo  ,
						const Memory::AllocationCallbacks* _allocator   ,
						      Handle&                      _setLayout
					)
					{
						return EResult(vkCreateDescriptorSetLayout(_deviceHandle, _createInfo.operator const VkDescriptorSetLayoutCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_setLayout));
					}

					/**
					 * @brief Destroy a descriptor set layout.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDescriptorSetLayout">Specification</a> 
					 * 
					 * \param _deviceHandle
					 * \param _descriptorSet
					 * \param _allocator
					 */
					static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _descriptorSet, const Memory::AllocationCallbacks* _allocator)
					{
						vkDestroyDescriptorSetLayout(_deviceHandle, _descriptorSet, _allocator->operator const VkAllocationCallbacks*());
					}

					/**
					 * @brief Query whether a descriptor set layout can be created.
					 * 
					 * @details
					 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetDescriptorSetLayoutSupport">Specification</a> 
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _support
					 */
					static void GetSupport(LogicalDevice::Handle _deviceHandle, CreateInfo& _createInfo, Support& _support)
					{
						vkGetDescriptorSetLayoutSupport(_deviceHandle, _createInfo, _support);
					}
				};

				
				using CreateFlags = Bitmask<EUndefined, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineLayoutCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineLayoutCreateInfo, EStructureType::Pipeline_Layout_CreateInfo>
				{
					      EType                  SType                 ;
					const void*                  Next                  ;
					      CreateFlags            Flags                 ;
					      uint32                 SetLayoutCount        ;
					const DescriptorSet::Handle* SetLayouts            ;
					      uint32                 PushConstantRangeCount;
					const PushConstantRange*     PushConstantRanges    ;
				};

				/**
				 * @brief Create a pipeline layout.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreatePipelineLayout">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _creationSpec
				 * \param _allocator
				 * \param _pipelineLayout
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle  ,
					const CreateInfo&                  _creationSpec  ,
					const Memory::AllocationCallbacks* _allocator     ,
					      Handle&                      _pipelineLayout
				)
				{
					return EResult(vkCreatePipelineLayout(_deviceHandle, _creationSpec.operator const VkPipelineLayoutCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_pipelineLayout));
				}

				/**
				 * @brief Destroy a pipeline layout.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyPipelineLayout">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _pipelineLayout
				 * \param _allocator
				 */
				static void Destroy
				(
					      LogicalDevice::Handle        _deviceHandle  ,
					      Handle                       _pipelineLayout,
					const Memory::AllocationCallbacks* _allocator
				)
				{
					vkDestroyPipelineLayout(_deviceHandle, _pipelineLayout, _allocator->operator const VkAllocationCallbacks*());
				}
			};

			/** @brief */
			struct MultiSampleState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSampleMask">Specification</a>  */
				using SampleMask = VkSampleMask;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineMultisampleStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineMultisampleStateCreateInfo, EStructureType::Pipeline_MultisampleState_CreateInfo>
				{
					      EType        SType                ;
					const void*        Next                 ;
					      CreateFlags  Flags                ;
					      ESampleCount RasterizationSamples ;
					      Bool         EnableSampleShading  ;
					      float32      MinSampleShading     ;
					const SampleMask*  SampleMask           ;
					      Bool         EnableAlphaToCoverage;
					      Bool         EnableAlphaToOne     ;
				};
			};

			/** @brief  */
			struct RasterizationState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCullModeFlags">Specification</a>  */
				using CullModeFlags = Bitmask<ECullModeFlag, VkCullModeFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineRasterizationStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineRasterizationStateCreateInfo, EStructureType::Pipeline_RasterizationState_CreateInfo>
				{
						  EType         SType                  ;
					const void*         Next                   ;
						  CreateFlags   Flags                  ;
						  Bool          EnableDepthClamp       ;
						  Bool          EnableRasterizerDiscard;
						  EPolygonMode  PolygonMode            ;
						  CullModeFlags CullMode               ;
						  EFrontFace    FrontFace              ;
						  Bool          EnableDepthBias        ;
						  float32       DepthBiasConstantFactor;
						  float32       DepthBiasClamp         ;
						  float32       DepthBiasSlopeFactor   ;
						  float32       LineWidth              ;
				};
			};

			/** 
			@brief
			Specialization constants are a mechanism whereby constants in a SPIR-V module can have their constant value specified 
			at the time the VkPipeline is created. This allows a SPIR-V module to have constants that can be modified 
			while executing an application that uses the Vulkan API.

			@details
			<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationMapEntry">Specification</a> 
			*/
			struct Specialization
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationMapEntry">Specification</a>  */
				struct MapEntry : V0::VKStruct_Base<VkSpecializationMapEntry>
				{
					uint32   ConstantID;
					uint32   Offset    ;
					DataSize Size      ;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSpecializationInfo">Specification</a>  */
				struct Info : V0::VKStruct_Base<VkSpecializationInfo>
				{
					      uint32    MapEntryCount;
					const MapEntry* MapEntires   ;
					      DataSize  SizeOfData   ;
					const void*     Data         ;
				};
			};

			/**
			 * @brief Used to handle shader staging within a pipeline, more than one shader can be staged in a pipeline.
			 */
			struct ShaderStage
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkShaderStageFlags">Specification</a>  */
				using CreateFlags = Bitmask<EPipelineShaderStageCreateFlag, VkShaderStageFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineShaderStageCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineShaderStageCreateInfo , EStructureType::Pipeline_ShaderStage_CreateInfo>
				{
						  EType                 SType         ;
					const void*                 Next          ;
						  CreateFlags           Flags         ;
						  EShaderStageFlag      Stage         ;
						  ShaderModule::Handle  Module        ;
						  RoCStr                Name          ;
					const Specialization::Info* Specialization;
				};
			};
			
			/** @brief */
			struct TessellationState
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineTessellationStateCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EUndefined, VkPipelineTessellationStateCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineTessellationStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineTessellationStateCreateInfo, EStructureType::Pipeline_TessellationState_CreateInfo>
				{
					      EType       SType             ;
					const void*       Next              ;
					      CreateFlags Flags             ;
					      uint32      PatchControlPoints;
				};
			};

			/**
			 * @brief.
			 */
			struct VertexInputState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkVertexInputAttributeDescription">Specification</a>  */
				struct AttributeDescription : V0::VKStruct_Base<VkVertexInputAttributeDescription>
				{
					uint32  Location;
					uint32  Binding ;
					EFormat Format  ;
					uint32  Offset  ;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkVertexInputBindingDescription">Specification</a>  */
				struct BindingDescription : V0::VKStruct_Base<VkVertexInputBindingDescription>
				{
					uint32           Binding  ;
					uint32           Stride   ;
					EVertexInputRate InputRate;
				};

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineVertexInputStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineVertexInputStateCreateInfo, EStructureType::Pipeline_VertexInputState_CreateInfo>
				{
						  EType                 SType                        ;
					const void*                 Next                         ;
						  CreateFlags           Flags                        ;
						  uint32                VertexBindingDescriptionCount;
					const BindingDescription*   BindingDescriptions          ;
						  uint32                AttributeDescriptionCount    ;
					const AttributeDescription* AttributeDescription         ;
				};
			};

			/** @brief */
			struct ViewportState
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;   // Reserved for future use.

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineViewportStateCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkPipelineViewportStateCreateInfo, EStructureType::Pipeline_ViewportState_CreateInfo>
				{
						  EType       SType        ;
					const void*       Next         ;
					      CreateFlags Flags        ;
						  uint32      ViewportCount;
					const Viewport*   Viewports    ;
						  uint32      ScissorCount ;
					const Rect2D*     Scissors     ;
				};
			};

			/**
			 * @brief The compute pipeline represents a compute shader.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-compute">Specification</a> 
			 */
			struct Compute
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EPipelineCreateFlag, VkPipelineCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkComputePipelineCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkComputePipelineCreateInfo, EStructureType::ComputePipeline_CreateInfo>
				{
					      EType                   SType             ;
					const void*                   Next              ;
					      CreateFlags             Flags             ;
					      ShaderStage::CreateInfo ShaderStage       ;
					      Layout::Handle          Layout            ;
					      Pipeline::Handle        BasePipelineHandle;
					      sint32                  BasePipelineIndex ;
				};

				/**
				 * @brief Create a compute pipeline.
				 * 
				 * @details <a href="linkURL">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _allocator
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle   ,
					      Cache::Handle                _cache          ,
					      uint32                       _createInfoCount,
					const CreateInfo*                  _createInfos    ,
					const Memory::AllocationCallbacks* _allocator      ,
					      Handle*                      _pipelines
				)
				{
					return EResult(vkCreateComputePipelines(_deviceHandle, _cache, _createInfoCount, _createInfos->operator const VkComputePipelineCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), _pipelines));
				}
			};

			/**
			 * @brief Graphics pipelines consist of multiple shader stages, multiple fixed-function pipeline stages, and a pipeline layout.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines-graphics">Specification</a> 
			 */
			struct Graphics
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPipelineCreateFlags">Specification</a>  */
				using CreateFlags = Bitmask<EPipelineCreateFlag, VkPipelineCreateFlags>;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsPipelineCreateInfo">Specification</a>  */
				struct CreateInfo : V0::VKStruct_Base<VkGraphicsPipelineCreateInfo, EStructureType::GraphicsPipeline_CreateInfo>
				{
					using RenderPass_Handle = VkRenderPass;   // RenderPass::Handle not defined yet. (Defined in VT_RenderPass.hpp)

					      EType                           SType             ;
					const void*                           Next              ;
					      CreateFlags                     Flags             ;
					      uint32                          StageCount        ;
					const ShaderStage::CreateInfo*        Stages            ;
					const VertexInputState::CreateInfo*   VertexInputState  ;
					const InputAssemblyState::CreateInfo* InputAssemblyState;
					const TessellationState::CreateInfo*  TessellationState ;
					const ViewportState::CreateInfo*      ViewportState     ;
					const RasterizationState::CreateInfo* RasterizationState;
					const MultiSampleState::CreateInfo*   MultisampleState  ;
					const DepthStencilState::CreateInfo*  DepthStencilState ;
					const ColorBlendState::CreateInfo*    ColorBlendState   ;
					const DynamicState::CreateInfo*       DynamicState      ;
					      Pipeline::Layout::Handle        Layout            ;
						  RenderPass_Handle               RenderPass        ;
					      uint32                          Subpass           ;
					      Pipeline::Handle                BasePipelineHandle;
					      sint32                          BasePipelineIndex ;
				};

				/**
				 * @brief Graphics pipelines can contain multiple shader groups that can be bound individually. \
				 * Each shader group behaves as if it was a pipeline using the shader groups state.
				 * 
				 * @details
				 *  When the pipeline is bound by regular means, it behaves as if the state of group 0 is active, 
				 * use vkCmdBindPipelineShaderGroupNV to bind an individual shader group. The primary purpose 
				 * of shader groups is allowing the device to bind different pipeline state using Device-Generated Commands.
				 * 
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#pipelines">Specification</a> 
				 */
				struct ShaderGroup 
				{
					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsShaderGroupCreateInfoNV">Specification</a>  */
					struct CreateInfo : V0::VKStruct_Base<VkGraphicsShaderGroupCreateInfoNV, EStructureType::GraphicsShaderGroup_CreateInfo_NV>
					{
						      EType                          SType            ;
						const void*                          Next             ;
						      uint32                         StageCount       ;
						const ShaderStage::CreateInfo*       Stages           ;
						const VertexInputState::CreateInfo*  VertexInputState ;
						const TessellationState::CreateInfo* TessellationState;
					};

					/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkGraphicsPipelineShaderGroupsCreateInfoNV">Specification</a>  */
					struct MultipleCreateInfo : V0::VKStruct_Base<VkGraphicsPipelineShaderGroupsCreateInfoNV, EStructureType::GraphicsPipeline_ShaderGroups_CreateInfo_NV>
					{
						      EType             SType;
						const void*             Next;
						      uint32            GroupCount;
						const CreateInfo*       Groups;
						      uint32            PipelineCount;
						const Pipeline::Handle* Pipelines;
					};
				};

				/**
				 * @brief Create a graphics pipeline.
				 * 
				 * @details
				 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateGraphicsPipelines">Specification</a> 
				 * 
				 * \param _deviceHandle
				 * \param _pipelineCache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _allocator
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle   ,
					      Cache::Handle                _pipelineCache  ,
					      uint32                       _createInfoCount,
					const CreateInfo*                  _createInfos    ,
					const Memory::AllocationCallbacks* _allocator      ,
					      Handle*                      _pipelines
				)
				{
					return EResult(vkCreateGraphicsPipelines(_deviceHandle, _pipelineCache, _createInfoCount, _createInfos->operator const VkGraphicsPipelineCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), _pipelines));
				}
			};

			/**
			 * @brief Destroy a pipeline object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyPipeline">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _pipeline
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipeline, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyPipeline(_deviceHandle, _pipeline, _allocator->operator const VkAllocationCallbacks*());
			}
		};
	}

	namespace V2
	{
		struct Pipeline : public V1::Pipeline
		{
			using Parent = V1::Pipeline;

			struct Cache : public Parent::Cache
			{
				using Parent = Parent::Cache;

				struct CreateInfo : public Parent::Cache::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				* @brief Create a pipeline cache.
				* 
				* @details
				* <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreatePipelineCache">Specification</a>
				* 
				* \param _deviceHandle
				* \param _createInfo
				* \param _pipelineCache
				* \return 
				*/
				static EResult Create
				(
					LogicalDevice::Handle  _deviceHandle ,
					const CreateInfo&      _createInfo   ,
					Cache::Handle&         _pipelineCache
				)
				{
					return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _pipelineCache);
				}

				using Parent::Create;

				/**
				 * @brief Destroy a pipeline cache.
				 * 
				 * @details

				 * \param _deviceHandle
				 * \param _cache
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Cache::Handle _cache)
				{
					Parent::Destroy(_deviceHandle, _cache, Memory::DefaultAllocator);
				}

				using Parent::Destroy;
			};

			struct ColorBlendState : public Parent::ColorBlendState
			{
				struct CreateInfo : public Parent::ColorBlendState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct DepthStencilState : public Parent::DepthStencilState
			{
				struct CreateInfo : public Parent::DepthStencilState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
						
						MinDepthBounds = 0;
						MaxDepthBounds = 0;
					}
				};
			};
			
			struct DynamicState : public Parent::DynamicState
			{
				struct CreateInfo : public Parent::DynamicState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct InputAssemblyState : public Parent::InputAssemblyState
			{
				struct CreateInfo : public Parent::InputAssemblyState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Layout : public Parent::Layout
			{
				using Parent = Parent::Layout;

				struct DescriptorSet : public Parent::DescriptorSet
				{
					using Parent = Parent::DescriptorSet;

					struct Binding : public Parent::Binding
					{
						struct FlagsCreateInfo : public Parent::Binding::FlagsCreateInfo
						{
							FlagsCreateInfo()
							{
								SType = STypeEnum;
								Next  = nullptr  ;
							}
						};
					};

					struct CreateInfo : public Parent::CreateInfo
					{
						CreateInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					struct Support : public Parent::Support
					{
						Support()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}

						struct SetVariableCount : public Parent::Support::SetVariableCount
						{
							SetVariableCount()
							{
								SType = STypeEnum;
								Next  = nullptr  ;
							}
						};
					};

					/**
					 * @brief Create a descriptor set layout.
					 * 
					 * @details
					 * 
					 * \param _deviceHandle
					 * \param _createInfo
					 * \param _setLayout
					 * \return 
					 */
					static EResult Create
					(
						      LogicalDevice::Handle _deviceHandle,
						const CreateInfo&           _createInfo  ,
						      Handle&               _setLayout
					)
					{
						return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _setLayout);
					}

					using Parent::Create;

					/**
					 * @brief Destroy a descriptor set layout.
					 * 
					 * @details
					 * 
					 * \param _deviceHandle
					 * \param _descriptorSet
					 */
					static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _descriptorSet)
					{
						Parent::Destroy(_deviceHandle, _descriptorSet, Memory::DefaultAllocator);
					}

					using Parent::Destroy;
				};

				struct CreateInfo : public Parent::Layout::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				* @brief Create a pipeline layout.
				* 
				* @details
				* 
				* \param _deviceHandle
				* \param _creationSpec
				* \param _pipelineLayout
				* \return 
				*/
				static EResult Create
				(
						  LogicalDevice::Handle _deviceHandle  ,
					const CreateInfo&           _creationSpec  ,
						  Handle&               _pipelineLayout
				)
				{
					return Parent::Create(_deviceHandle, _creationSpec, Memory::DefaultAllocator, _pipelineLayout);
				}

				using Parent::Create;

				/**
				 * @brief Destroy a pipeline layout.
				 * 
				 * @details
				 * 
				 * \param _deviceHandle
				 * \param _pipelineLayout
				 */
				static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipelineLayout)
				{
					Parent::Destroy(_deviceHandle, _pipelineLayout, Memory::DefaultAllocator);
				}

				using Parent::Destroy;
			};

			struct MultiSampleState : public Parent::MultiSampleState
			{
				struct CreateInfo : public Parent::MultiSampleState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct RasterizationState : public Parent::RasterizationState
			{
				struct CreateInfo : public Parent::RasterizationState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct ShaderStage : public Parent::ShaderStage
			{
				struct CreateInfo : public Parent::ShaderStage::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
						Module = Null<ShaderModule::Handle>;
						Name = nullptr;
						Specialization = nullptr;
					}
				};
			};

			struct TessellationState : public Parent::TessellationState
			{
				struct CreateInfo : public Parent::TessellationState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct VertexInputState : public Parent::VertexInputState
			{
				struct CreateInfo : public Parent::VertexInputState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct ViewportState : public Parent::ViewportState
			{
				struct CreateInfo : public Parent::ViewportState::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct Compute : public Parent::Compute
			{
				using Parent = Parent::Compute;

				struct CreateInfo : public Parent::Compute::CreateInfo
				{
					CreateInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				/**
				 * @brief Create a compute pipeline.
				 * 
				 * @details 
				 * 
				 * \param _deviceHandle
				 * \param _cache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle        _deviceHandle   ,
					      Cache::Handle                _cache          ,
					      uint32                       _createInfoCount,
					const CreateInfo*                  _createInfos    ,
					      Handle*                      _pipelines
				)
				{
					return Parent::Create(_deviceHandle, _cache, _createInfoCount, _createInfos, Memory::DefaultAllocator, _pipelines);
				}

				using Parent::Create;


			};

			struct Graphics : public Parent::Graphics
			{
				using Parent = Parent::Graphics;

				struct CreateInfo : public Parent::Graphics::CreateInfo
				{
					CreateInfo() 
					{
						SType = STypeEnum;
						Next  = nullptr  ;
						StageCount = 0;

						Stages = nullptr;
						VertexInputState = nullptr;
						InputAssemblyState = nullptr;
						TessellationState = nullptr;
						ViewportState = nullptr;
						RasterizationState = nullptr;
						MultisampleState = nullptr;
						DepthStencilState = nullptr;
						ColorBlendState = nullptr;
						DynamicState = nullptr;
						Layout = Null<Layout::Handle>;
						RenderPass = Null<RenderPass_Handle>;
						Subpass = 0;
						BasePipelineHandle = Null<Pipeline::Handle>;
						BasePipelineIndex = 0;

					}
				};

				struct ShaderGroup : public Parent::Graphics::ShaderGroup
				{
					struct CreateInfo : public Parent::Graphics::ShaderGroup::CreateInfo
					{
						CreateInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};

					struct MultipleCreateInfo : public Parent::Graphics::ShaderGroup::MultipleCreateInfo
					{
						MultipleCreateInfo()
						{
							SType = STypeEnum;
							Next  = nullptr  ;
						}
					};
				};

				/**
				 * @brief Create a graphics pipeline.
				 * 
				 * @details
				 * 
				 * \param _deviceHandle
				 * \param _pipelineCache
				 * \param _createInfoCount
				 * \param _createInfos
				 * \param _pipelines
				 * \return 
				 */
				static EResult Create
				(
					      LogicalDevice::Handle _deviceHandle   ,
					      Cache::Handle         _pipelineCache  ,
					      uint32                _createInfoCount,
					const CreateInfo*           _createInfos    ,
					      Handle*               _pipelines
				)
				{
					return Parent::Create(_deviceHandle, _pipelineCache, _createInfoCount, _createInfos, Memory::DefaultAllocator, _pipelines);
				}

				using Parent::Create;
			};

			/**
			 * @brief Destroy a pipeline object.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _pipeline
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _pipeline)
			{
				Parent::Destroy(_deviceHandle, _pipeline, Memory::DefaultAllocator);
			}
		};
	}

	namespace V3
	{
		class Pipeline : public V2::Pipeline
		{
		public:
			using Parent = V2::Pipeline;

			class Cache : public Parent::Cache
			{
			public:
				using Parent = V2::Pipeline::Cache;

				EResult Create
				(
					LogicalDevice::Handle _device,
					CreateInfo&           _info  
				)
				{
					device    = _device                 ;
					info      = _info                   ;
					allocator = Memory::DefaultAllocator;

					return Parent::Create(device, info, allocator, handle);
				}

				EResult Create
				(
					      LogicalDevice::Handle        _device   ,
					      CreateInfo&                  _info     ,
					const Memory::AllocationCallbacks* _allocator
				)
				{
					device    = _device   ;
					info      = _info     ;
					allocator = _allocator;

					return Parent::Create(device, info, allocator, handle);
				}

				void Destroy()
				{
					Parent::Destroy(device, handle, allocator);
				}

				const Handle& GetHandle() const
				{
					return handle;
				}

				operator Handle()
				{
					return handle;
				}

				operator Handle() const
				{
					return handle;
				}

				operator const Handle& () const
				{
					return handle;
				}

			protected:

				Handle handle;

				const Memory::AllocationCallbacks* allocator;
				
				CreateInfo info;

				LogicalDevice::Handle device;
			};

			class Layout : public Parent::Layout
			{
			public:
				using Parent = V2::Pipeline::Layout;

				class DescriptorSet : public Parent::DescriptorSet
				{
				public:
					using Parent = V2::Pipeline::Layout::DescriptorSet;

					void Assign(LogicalDevice::Handle _device, CreateInfo& _info)
					{
						device    = _device                 ;
						info      = _info                   ;
						allocator = Memory::DefaultAllocator;

						Parent::GetSupport(device, info, support);
					}

					void Assign
					(
						      LogicalDevice::Handle        _device   ,
						      CreateInfo&                  _info     ,
						const Memory::AllocationCallbacks* _allocator
					)
					{
						device    = _device   ;
						info      = _info     ;
						allocator = _allocator;

						Parent::GetSupport(device, info, support);
					}

					EResult Create()
					{
						return Parent::Create(device, info, allocator, handle);
					}

					void Destroy()
					{
						Parent::Destroy(device, handle, allocator);
					}

					const Handle& GetHandle() const
					{
						return handle;
					}

					const Support& GetSupport() const
					{
						return support;
					}

					operator Handle()
					{
						return handle;
					}

					operator Handle() const
					{
						return handle;
					}

					operator const Handle& () const
					{
						return handle;
					}

				protected:

					Handle handle;

					const Memory::AllocationCallbacks* allocator;

					CreateInfo info;

					LogicalDevice::Handle device;

					Support support;
				};

				EResult Create
				(
					LogicalDevice::Handle _device,
					CreateInfo&           _info  
				)
				{
					device    = _device                 ;
					info      = _info                   ;
					allocator = Memory::DefaultAllocator;

					return Parent::Create(device, info, allocator, handle);
				}

				EResult Create
				(
					      LogicalDevice::Handle        _device   ,
					      CreateInfo&                  _info     ,
					const Memory::AllocationCallbacks* _allocator
				)
				{
					device    = _device   ;
					info      = _info     ;
					allocator = _allocator;

					return Parent::Create(device, info, allocator, handle);
				}

				void Destroy()
				{
					Parent::Destroy(device, handle, allocator);
				}

				Handle GetHandle() const
				{
					return handle;
				}

				operator Handle()
				{
					return handle;
				}

				operator Handle() const
				{
					return handle;
				}

				operator const Handle& () const
				{
					return handle;
				}

			protected:

				Handle handle;

				const Memory::AllocationCallbacks* allocator;

				CreateInfo info;

				LogicalDevice::Handle device;
			};

			void Destroy()
			{
				Parent::Destroy(device, handle);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			Cache* cache;

			const Memory::AllocationCallbacks* allocator;

			LogicalDevice::Handle device;
		};

		class ComputePipeline : public Pipeline
		{
		public:

			using CreateInfo = Parent::Compute::CreateInfo;

			void Assign
			(
				      LogicalDevice::Handle&       _device   ,
				      Cache*                       _cache    ,
				      CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle                       _handle
			)
			{
				handle    = _handle   ;
				allocator = _allocator;
				cache     =  _cache   ;
				device    = _device   ;
				info      = _info     ;	
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device ;
				cache     = nullptr ;
				info      = _info   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Compute::Create
				(
					device,
					Null<Cache::Handle>,
					1,
					&info,
					allocator,
					&handle
				);
			}

			EResult Create(LogicalDevice::Handle _device, Cache& _cache, CreateInfo& _info)
			{
				device    = _device ;
				cache     = &_cache ;
				info      = _info   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Compute::Create
				(
					device,
					cache ->GetHandle(),
					1                  ,
					&info              ,
					allocator          ,
					&handle
				);
			}

			EResult Create
			(
				      LogicalDevice::Handle        _device   , 
				      Cache&                       _cache    , 
				      CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = _device   ;
				cache     = &_cache   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Parent::Compute::Create
				(
					device             ,
					cache ->GetHandle(),
					1                  ,
					&info              ,
					allocator          ,
					&handle
				);
			}

			static EResult Create
			(
				      LogicalDevice::Handle          _device         ,
				      Cache*                         _cache          ,
				      uint32                         _createInfoCount,
				      CreateInfo*                    _createInfos    ,
				const Memory::AllocationCallbacks*   _allocator      ,
				      std::vector<ComputePipeline>& _pipelines
			)
			{
				_pipelines.resize(_createInfoCount);

				Handle* handles;

				EResult returnCode = 
					Parent::Parent::Compute::Create
					(
						_device,
						_cache->GetHandle(),
						_createInfoCount   ,
						_createInfos       ,
						_allocator         ,
						handles
					);

				if (returnCode != EResult::Success) return returnCode;

				int index = 0;

				for (auto pipeline : _pipelines)
				{
					pipeline.Assign(_device, _cache, _createInfos[index++], _allocator, handles[index]);
				}

				return returnCode;
			}

		protected:

			CreateInfo info;
		};

		class GraphicsPipeline : public Pipeline
		{
		public:
			using CreateInfo = Parent::Graphics::CreateInfo;

			void Assign
			(
				      LogicalDevice::Handle        _device   ,
				      Cache*                       _cache    ,
				      CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator,
				      Handle                       _handle
			)
			{
				handle    = _handle   ;
				allocator = _allocator;
				cache     = _cache    ;
				device    = _device   ;
				info      = _info     ;	
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device ;
				cache     = nullptr ;
				info      = _info   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Graphics::Create
				(
					device,
					Null<Cache::Handle>,
					1                  ,
					&info              ,
					allocator          ,
					&handle
				);
			}

			EResult Create(LogicalDevice::Handle _device, Cache& _cache, CreateInfo& _info)
			{
				device    = _device ;
				cache     = &_cache ;
				info      = _info   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Parent::Graphics::Create
				(
					device,
					cache ->GetHandle(),
					1                  ,
					&info              ,
					allocator          ,
					&handle
				);
			}

			EResult Create
			(
				      LogicalDevice::Handle        _device   , 
				      Cache&                       _cache    , 
				      CreateInfo&                  _info     ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				device    = _device   ;
				cache     = &_cache   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Parent::Graphics::Create
				(
					device,
					cache ->GetHandle(),
					1                  ,
					&info              ,
					allocator          ,
					&handle
				);
			}

			static EResult Create
			(
				      LogicalDevice::Handle          _device         ,
				      Cache*                         _cache          ,
				      uint32                         _createInfoCount,
				      CreateInfo*                    _createInfos    ,
				const Memory::AllocationCallbacks*   _allocator      ,
				      std::vector<GraphicsPipeline>& _pipelines
			)
			{
				_pipelines.resize(_createInfoCount);

				Handle* handles;

				EResult returnCode = 
					Parent::Parent::Graphics::Create
					(
						_device,
						_cache->GetHandle(),
						_createInfoCount   ,
						_createInfos       ,
						_allocator         ,
						handles
					);

				if (returnCode != EResult::Success) return returnCode;

				int index = 0;

				for (auto pipeline : _pipelines)
				{
					pipeline.Assign(_device, _cache, _createInfos[index++], _allocator, handles[index]);
				}

				return returnCode;
			}

		protected:

			CreateInfo info;
		};
	}
}




/**
@file VT_RenderPass.hpp

@brief Vaulted Thermals: Render Pass

@details

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief Render passes operate in conjunction with framebuffers. Framebuffers represent a collection of specific memory attachments that a render pass instance uses.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_framebuffers">Specification</a> 
		 */
		struct Framebuffer
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebuffer">Specification</a>  */
			using Handle = VkFramebuffer;
			
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateFlags">Specification</a>  */
			using CreateFlags = Bitmask<EFrameBufferCreateFlag, VkFramebufferCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkFramebufferCreateInfo, EStructureType::Framebuffer_CreateInfo>
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
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateFramebuffer">Specification</a> 
			 * 
			 * \param _deviceHanle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _framebuffer
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHanle ,
				const CreateInfo&                  _creationSpec,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _framebuffer
			)
			{
				return EResult(vkCreateFramebuffer(_deviceHanle, _creationSpec.operator const VkFramebufferCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_framebuffer));
			}

			/**
			 * @brief Destroy a framebuffer.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyFramebuffer">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _framebuffer
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _framebuffer, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyFramebuffer(_deviceHandle, _framebuffer, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/**
		 * @brief A render pass represents a collection of attachments, subpasses, and dependencies between the subpasses, and describes how the attachments are used over the course of the subpasses.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
		 */
		struct RenderPass
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPass">Specification</a>  */
			using Handle = VkRenderPass;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescriptionFlags">Specification</a>  */
			using AttachmentDescriptionFlags = Bitmask<EAttachmentDescriptionFlag, VkAttachmentDescriptionFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDescriptionFlags">Specification</a>  */
			using SubpassDesriptionFlags     = Bitmask<ESubpassDescriptionFlag   , VkSubpassDescriptionFlags   >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassCreateFlags">Specification</a>  */
			using CreateFlags                = Bitmask<EUndefined                , VkRenderPassCreateFlags     >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescription">Specification</a>  */
			struct AttachmentDescription : V0::VKStruct_Base<VkAttachmentDescription>
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
			struct AttachmentReference : V0::VKStruct_Base<VkAttachmentReference>
			{
				uint32       Attachment;
				EImageLayout Layout    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassBeginInfo">Specification</a>  */
			struct BeginInfo : V0::VKStruct_Base<VkRenderPassBeginInfo, EStructureType::RenderPass_BeginInfo>
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
			struct SubpassDescription : V0::VKStruct_Base<VkSubpassDescription>
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
			struct SubpassDependency : V0::VKStruct_Base<VkSubpassDependency>
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
			struct CreateInfo : V0::VKStruct_Base<VkRenderPassCreateInfo, EStructureType::RenderPass_CreateInfo>
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
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _createInfo  ,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _renderPass
			)
			{
				return EResult(vkCreateRenderPass(_deviceHandle, _createInfo.operator const VkRenderPassCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_renderPass));
			}

			/**
			 * @brief Destroy a render pass.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyRenderPass">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _renderPass
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _renderPass, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyRenderPass(_deviceHandle, _renderPass, _allocator->operator const VkAllocationCallbacks*());
			}
		};
	}

	namespace V2
	{
		struct Framebuffer : public V1::Framebuffer
		{
			using Parent = V1::Framebuffer;

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			/**
			 * @brief Creates a framebuffer.
			 * 
			 * @details
			 * 
			 * \param _deviceHanle
			 * \param _creationSpec
			 * \param _framebuffer
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHanle ,
				const CreateInfo&           _creationSpec,
				      Handle&               _framebuffer
			)
			{
				return Parent::Create(_deviceHanle, _creationSpec, Memory::DefaultAllocator, _framebuffer);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a framebuffer.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _framebuffer
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _framebuffer)
			{
				Parent::Destroy(_deviceHandle, _framebuffer, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		struct RenderPass : public V1::RenderPass
		{
			using Parent = V1::RenderPass;

			struct BeginInfo : public Parent::BeginInfo
			{
				BeginInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next = nullptr;
				}
			};

			/*struct AttachmentDescription : public Parent::AttachmentDescription
			{
			};*/

			struct SubpassDescription : public Parent::SubpassDescription
			{
				SubpassDescription()
				{
					InputAttachmentCount = 0;
					InputAttachments = nullptr;
					ColorAttachmentCount = 0;
					ColorAttachments = nullptr;
					ResolveAttachments = nullptr;
					DepthStencilAttachment = nullptr;
					PreserveAttachmentCount = 0;
					PreserveAttachments = nullptr;
				}
			};

			/**
			 * @brief Create a render pass.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _renderPass
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _createInfo  ,
				      Handle&               _renderPass
			)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _renderPass);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a render pass.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _renderPass
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _renderPass)
			{
				Parent::Destroy(_deviceHandle, _renderPass, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};
	}

	namespace V3
	{
		class Framebuffer : public V2::Framebuffer
		{
		public:
			using Parent = V2::Framebuffer;

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device                 ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			CreateInfo info;

			const Memory::AllocationCallbacks* allocator;

			LogicalDevice::Handle device;
		};

		class RenderPass : public V2::RenderPass
		{
		public:
			using Parent = V2::RenderPass;



			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info)
			{
				device    = _device                 ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create(LogicalDevice::Handle _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = _device   ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle, allocator);
			}

			uint32 GetAttachmentCount()
			{
				return info.AttachmentCount;
			}

			Handle GetHandle()
			{
				return handle;
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle&() const
			{
				return handle;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			LogicalDevice::Handle device;
		};
	}
}




/**
@file VT_Command.hpp

@brief Vaulted Thermals: Command Buffers

@details

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers">Specification</a> 
		 */
		struct CommandBuffer
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBuffer">Specification</a>  */
			using Handle = VkCommandBuffer;

			using EBufferLevel = ECommandBufferLevel;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryControlFlags">Specification</a>  */
			using QueryControlFlags           = Bitmask<EQueryControlFlags         , VkQueryControlFlags          >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkQueryPipelineStatisticFlags">Specification</a>  */
			using QueryPipelineStatisticFlags = Bitmask<EQueryPipelineStatisticFlag, VkQueryPipelineStatisticFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferResetFlags">Specification</a>  */
			using ResetFlags                  = Bitmask<ECommandBufferResetFlag    , VkCommandBufferResetFlags    >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferUsageFlags">Specification</a>  */
			using UsageFlags                  = Bitmask<ECommandBufferUsageFlag    , VkCommandBufferUsageFlags    >;

			

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkBufferImageCopy">Specification</a>  */
			struct BufferImageRegion : V0::VKStruct_Base<VkBufferImageCopy>
			{
				DeviceSize               BufferOffset     ;
				uint32                   BufferRowLength  ;
				uint32                   BufferImageHeight;
				Image::SubresourceLayers ImageSubresource ;
				Offset3D                 ImageOffset      ;
				Extent3D                 ImageExtent      ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceInfoURL">Specification</a>
			 */
			struct InheritanceWindow : V0::VKStruct_Base<VkCommandBufferInheritanceInfo, EStructureType::CommandBuffer_InheritanceInfo>
			{
				      EType                       SType               ;
				const void*                       Next                ;
				      RenderPass::Handle          RenderPass          ;
				      uint32                      Subpass             ;
				      Framebuffer::Handle         Framebuffer         ;
				      Bool                        OcclusionQueryEnable;
				      QueryControlFlags           QueryFlags          ;
				      QueryPipelineStatisticFlags PipelineStatistics  ;

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceConditionalRenderingInfoEXT">Specification</a>
				 */
				struct ConditionalRenderingInfo : V0::VKStruct_Base<VkCommandBufferInheritanceConditionalRenderingInfoEXT, EStructureType::CommandBuffer_Inheritance_ConditionalRendering_Info_EXT>
				{
					      EType SType ;
					const void* Next  ;
					      Bool  Enable;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferInheritanceRenderPassTransformInfoQCOM">Specification</a> 
				 */
				struct PassTransformInfo : V0::VKStruct_Base
					<VkCommandBufferInheritanceRenderPassTransformInfoQCOM, EStructureType::CommandBufferInheritance_RenderPassTransform_Info_QCOM>
				{
					EType                 SType     ;
					void*                 Next      ;
					ESurfaceTransformFlag Transform ;
					Rect2D                RenderArea;
				};
			};	

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferBeginInfo">Specification</a>
			 */
			struct BeginInfo : V0::VKStruct_Base<VkCommandBufferBeginInfo, EStructureType::CommandBuffer_BeginInfo>
			{
				      EType              SType          ;
				const void*              Next           ;
				      UsageFlags         Flags          ;
				const InheritanceWindow* InheritanceInfo;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubmitInfo">Specification</a>
			 */
			struct SubmitInfo : V0::VKStruct_Base<VkSubmitInfo, EStructureType::SubmitInfo>
			{
				      EType                 SType               ;
				const void*                 Next                ;
				      uint32                WaitSemaphoreCount  ;
				const Semaphore::Handle*    WaitSemaphores      ;   
				const Pipeline::StageFlags* WaitDstStageMask    ;
				      uint32                CommandBufferCount  ;
				const Handle*               CommandBuffers      ;
				      uint32                SignalSemaphoreCount;
				const Semaphore::Handle*    SignalSemaphores    ;   


				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkTimelineSemaphoreSubmitInfo">Specification</a>
				 */
				struct TimelineSemaphore : V0::VKStruct_Base<VkTimelineSemaphoreSubmitInfo>
				{
					      EType   SType                    ;
					const void*   Next                     ;
					      uint32  WaitSemaphoreValueCount  ;
					const uInt64* WaitSemaphoreValues      ;
					      uint32  SignalSemaphoreValueCount;
					const uInt64* SignalSemaphoreValues    ;
				};	

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkD3D12FenceSubmitInfoKHR">Specification</a>	
				 */
				struct D3D12Fence : V0::VKStruct_Base<VkD3D12FenceSubmitInfoKHR>
				{
					      EType   SType                     ;
					const void*   Next                      ;
					      uint32  WaitSemaphoreValuesCount  ;
					const uInt64* WaitSemaphoreValues       ;
					      uint32  SignalSemaphoreValuesCount;
					const uInt64* SignalSemaphoreValues     ;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32KeyedMutexAcquireReleaseInfoKHR">Specification</a> 
				 */
				struct Win32KeyedMutexAcquireRelease : V0::VKStruct_Base<VkWin32KeyedMutexAcquireReleaseInfoKHR>
				{
					      EType           SType          ;
					const void*           Next           ;
					      uint32          AcquireCount   ;
					const Memory::Handle* AcquireSyncs   ;
					const uInt64*         AcquireKeys    ;
					const uint32*         AcquireTimeouts;
					      uint32          ReleaseCount   ;
					const Memory::Handle* ReleaseSyncs   ;
					const uInt64*         ReleaseKeys    ;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkProtectedSubmitInfo">Specification</a> 
				 */
				struct Protected : V0::VKStruct_Base<VkProtectedSubmitInfo>
				{
					      EType SType          ;
					const void* Next           ;
					      Bool  ProtectedSubmit;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupSubmitInfo">Specification</a>
				 */
				struct DeviceGroup : V0::VKStruct_Base<VkDeviceGroupSubmitInfo>
				{
					      EType   SType                       ;
					const void*   Next                        ;
					      uint32  WaitSemaphoreCount          ;
					const uint32* WaitSemaphoreDeviceIndices  ;
					      uint32  CommandBufferCount          ;
					const uint32* CommandBufferDeviceMasks    ;
					      uint32  SignalSemaphoreCount        ;
					const uint32* SignalSemaphoreDeviceIndices;
				};

				/**
				 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPerformanceQuerySubmitInfoKHR">Specification</a> 
				 */
				struct PerformanceQuery : V0::VKStruct_Base<VkPerformanceQuerySubmitInfoKHR>
				{
					      EType  Type            ;
					const void*  Next            ;
					      uint32 CounterPassIndex;
				};
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceGroupCommandBufferBeginInfo">Specification</a> 
			 */
			struct DeviceGroupBeginInfo : V0::VKStruct_Base<VkDeviceGroupCommandBufferBeginInfo>
			{
				      EType  SType     ;
				const void*  Next      ;
				      uint32 DeviceMask;
			};

			

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkBeginCommandBuffer">Specification</a> 
			 * 
			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult BeginRecord(const Handle _commandBuffer, const BeginInfo& _info)
			{
				return EResult(vkBeginCommandBuffer(_commandBuffer, _info.operator const VkCommandBufferBeginInfo*()));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBeginRenderPass">Specification</a>.
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _bufferCount
			 * \param _commandBuffers
			 */
			static void BeginRenderPass
			(
				const Handle                 _commandBuffer,
				const RenderPass::BeginInfo& _beginInfo    ,
				      ESubpassContents       _contents
			)
			{
				vkCmdBeginRenderPass(_commandBuffer, _beginInfo.operator const VkRenderPassBeginInfo*(), VkSubpassContents(_contents));
			}

			
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindDescriptorSets">Specification</a> 
			 */
			static void BindDescriptorSets
			(
				      Handle                   _commandBuffer     ,
				      EPipelineBindPoint       _pipelineBindPoint ,
				      Pipeline::Layout::Handle _layout            ,
				      uint32                   _firstSet          ,
				      uint32                   _descriptorSetCount,
				const DescriptorSet::Handle*   _descriptorSets    ,
				      uint32                   _dynamicOffsetCount,
				const uint32*                  _dynamicOffsets
			)
			{
				vkCmdBindDescriptorSets
				(
					_commandBuffer                         , 
					VkPipelineBindPoint(_pipelineBindPoint), 
					_layout                                , 
					_firstSet                              , 
					_descriptorSetCount                    ,
					_descriptorSets                        , 
					_dynamicOffsetCount                    , 
					_dynamicOffsets
				);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindIndexBuffer">Specification</a> 
			 */
			static void BindIndexBuffer
			(
				Handle         _commandBuffer,
				Buffer::Handle _buffer       ,
				DeviceSize     _offset       ,
				EIndexType     _indexType
			)
			{
				vkCmdBindIndexBuffer(_commandBuffer, _buffer, _offset, VkIndexType(_indexType));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindVertexBuffers">Specification</a>.
			 */
			static void BindVertexBuffers
			(
				      Handle          _commandBuffer,
				      uint32          _firstBinding ,
				      uint32          _bindingCount ,
				const Buffer::Handle* _buffers      ,
				const DeviceSize*     _offsets
			)
			{
				vkCmdBindVertexBuffers(_commandBuffer, _firstBinding, _bindingCount, _buffers, _offsets);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBindPipeline">Specification</a>
			 * 
			 * \param commandBuffer
			 * \param event
			 * \param stageMask
			 * \return 
			 */
			static void BindPipeline
			(
				Handle             _commandBuffer    ,
				EPipelineBindPoint _pipelineBindPoint,
				Pipeline::Handle   _pipeline
			)
			{
				vkCmdBindPipeline(_commandBuffer, VkPipelineBindPoint(_pipelineBindPoint), _pipeline);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdBlitImage">Specification</a> .
			 * 
			 * \param commandBuffer
			 * \param event
			 * \param stageMask
			 * \return 
			 */
			static void BlitImage
			(
				      Handle        _commandBuffer,
				      Image::Handle _srcImage,
				      EImageLayout  _srcImageLayout,
				      Image::Handle _dstImage,
				      EImageLayout  _dstImageLayout,
				      uint32        _regionCount,
				const Image::Blit*  _regions,
				      EFilter       _filter
			)
			{
				vkCmdBlitImage
				(
					_commandBuffer, 
					_srcImage, 
					VkImageLayout(_srcImageLayout), 
					_dstImage, 
					VkImageLayout(_dstImageLayout), 
					_regionCount, 
					_regions->operator const VkImageBlit*(), 
					VkFilter(_filter)
				);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdCopyBuffer">Specification</a>
			 * 
			 * \return 
			 */
			static void CopyBuffer
			(
				      Handle            _commandBuffer    ,
				      Buffer::Handle    _sourceBuffer     ,
				      Buffer::Handle    _destinationBuffer,
				      uint32            _regionCount      ,
				const Buffer::CopyInfo* _regions
			)
			{
				vkCmdCopyBuffer(_commandBuffer, _sourceBuffer, _destinationBuffer, _regionCount, _regions->operator const VkBufferCopy*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdCopyBufferToImage">Specification</a> 
			 */
			static void CopyBufferToImage
			(
				      Handle             _commandBuffer ,
				      Buffer::Handle     _srcBuffer     ,
				      Image::Handle      _dstImage      ,
				      EImageLayout       _dstImageLayout,
				      uint32			 _regionCount   ,
				const BufferImageRegion* _regions
			)
			{
				vkCmdCopyBufferToImage(_commandBuffer, _srcBuffer, _dstImage, VkImageLayout(_dstImageLayout), _regionCount, _regions->operator const VkBufferImageCopy*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDraw">Specification</a> 
			 */
			static void Draw
			(
				Handle _commandBuffer,
				uint32 _firstVertex  ,
				uint32 _vertexCount  , 
				uint32 _firstInstance,
				uint32 _instanceCount
			)
			{
				vkCmdDraw(_commandBuffer, _vertexCount, _instanceCount, _firstVertex, _firstInstance);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdDrawIndexed">Specification</a> 
			 */
			static void DrawIndexed
			(
				Handle _commandBuffer,
				uint32 _indexCount   ,
				uint32 _instanceCount,
				uint32 _firstIndex   ,
				sint32 _vertexOffset ,
				uint32 _firstInstance
			)
			{
				vkCmdDrawIndexed(_commandBuffer, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkEndCommandBuffer">Specification</a> 
			 * 
			 * \param _commandBuffer
			 * \return 
			 */
			static EResult EndRecord(Handle _commandBuffer)
			{
				return EResult(vkEndCommandBuffer(_commandBuffer));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdEndRenderPass">Specification</a> .
			 */
			static void EndRenderPass(Handle _commandBuffer)
			{
				vkCmdEndRenderPass(_commandBuffer);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdExecuteCommands">Specification</a> 
			 * 
			 * \param _primaryCommandBuffer
			 * \param _secondaryBufferCount
			 * \param _secondaryBuffers
			 */
			static void Execute
			(
				Handle        _primaryCommandBuffer,
				uint32        _secondaryBufferCount,
				const Handle* _secondaryBuffers
			)
			{
				vkCmdExecuteCommands(_primaryCommandBuffer, _secondaryBufferCount, _secondaryBuffers);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetCommandBuffer">Specification</a> 
			 * 
			 * \param _commandBuffer
			 * \param _flags
			 * \return 
			 */
			static EResult Reset(Handle _commandBuffer, ResetFlags _flags)
			{
				return EResult(vkResetCommandBuffer(_commandBuffer, _flags));
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdResetEvent">Specification</a> 
			*/
			static void ResetEvent
			(
				Handle               _commandBuffer,
				Event::Handle        _event        ,
				Pipeline::StageFlags _stageMask
			)
			{
				vkCmdResetEvent(_commandBuffer, _event, _stageMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdPipelineBarrier">Specification</a>
			 */
			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				vkCmdPipelineBarrier
				(
					_commandBuffer, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers->operator const VkMemoryBarrier*(), 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers->operator const VkBufferMemoryBarrier*(), 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers->operator const VkImageMemoryBarrier*()
				);
			}

			/**
			 * 
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetDeviceMask">Specification</a> 
			 * 
			 */
			static void SetDeviceMask(Handle _commandBuffer, uint32 _deviceMask)
			{
				vkCmdSetDeviceMask(_commandBuffer, _deviceMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdSetEvent">Specification</a> 
			 */
			static void SetEvent
			(
				Handle               _commandBuffer,
				Event::Handle        _event        ,
				Pipeline::StageFlags _stageMask
			)
			{
				vkCmdSetEvent(_commandBuffer, _event, _stageMask);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCmdWaitEvents">Specification</a> 
			 */
			static void WaitForEvents
			(
				      Handle                  _commandBuffer           ,
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				vkCmdWaitEvents
				(
					_commandBuffer, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers->operator const VkMemoryBarrier*(), 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers->operator const VkBufferMemoryBarrier*(),
					_imageMemoryBarrierCount,
					_imageMemoryBarriers->operator const VkImageMemoryBarrier*()
				);
			}
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#commandbuffers-pools">Specification</a> 
		 */
		struct CommandPool
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPool">Specification</a>  */
			using Handle = VkCommandPool;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateFlags">Specification</a>  */
			using CreateFlgas = Bitmask<ECommandPoolCreateFlag, VkCommandPoolCreateFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolResetFlags">Specification</a>  */
			using ResetFlags  = Bitmask<ECommandPoolResetFlags, VkCommandPoolResetFlags >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolTrimFlags">Specification</a>  */
			using TrimFlags   = Bitmask<EUndefined            , VkCommandPoolTrimFlags  >;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandBufferAllocateInfo">Specification</a> .
			 */
			struct AllocateInfo : V0::VKStruct_Base<VkCommandBufferAllocateInfo, EStructureType::CommandBuffer_AllocateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      Handle              Pool       ;
					  ECommandBufferLevel Level      ;
				      uint32              BufferCount;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCommandPoolCreateInfo">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkCommandPoolCreateInfo, EStructureType::CommandPool_CreateInfo>
			{
				      EType       SType           ;
				const void*       Next            ;
				      CreateFlgas Flags           ;
				      uint32      QueueFamilyIndex;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAllocateCommandBuffers">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _allocateInfo
			 * \param _commandBuffers
			 * \return 
			 */
			static EResult Allocate
			(
				      LogicalDevice::Handle  _deviceHandle  ,
				const AllocateInfo&          _allocateInfo  ,
				      CommandBuffer::Handle* _commandBuffers
			)
			{
				return EResult(vkAllocateCommandBuffers(_deviceHandle, _allocateInfo.operator const VkCommandBufferAllocateInfo*(), _commandBuffers));
			}

			/**
			 * @brief Create a command pool.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateCommandPool">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _commandPool
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _createInfo  ,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _commandPool
			)
			{
				return EResult(vkCreateCommandPool(_deviceHandle, (const VkCommandPoolCreateInfo*)(&_createInfo), _allocator->operator const VkAllocationCallbacks*(), &_commandPool));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyCommandPool">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _deviceHandle,
				      Handle                       _commandPool ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyCommandPool(_deviceHandle, _commandPool, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkFreeCommandBuffers">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _bufferCount
			 * \param _commandBuffers
			 */
			static void Free
			(
				      LogicalDevice::Handle _deviceHandle   ,
				      Handle                 _commandPool   ,
				      uint32                 _bufferCount   ,
				const CommandBuffer::Handle* _commandBuffers
			)
			{
				vkFreeCommandBuffers(_deviceHandle, _commandPool, _bufferCount, _commandBuffers);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetCommandPool">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _flags
			 */
			static EResult Reset
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _commandPool ,
				ResetFlags            _flags
			)
			{
				return EResult(vkResetCommandPool(_deviceHandle, _commandPool, _flags));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkTrimCommandPool">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _commandPool
			 * \param _flags
			 */
			static void Trim
			(
				LogicalDevice::Handle _deviceHandle,
				Handle                _commandPool ,
				TrimFlags             _flags
			)
			{
				vkTrimCommandPool(_deviceHandle, _commandPool, _flags);	
			}
		};
	}

	namespace V2
	{
		struct CommandPool : public V1::CommandPool
		{
			using Parent = V1::CommandPool;

			using CommandBuffer = V1::CommandBuffer;
			
			struct AllocateInfo : public Parent::AllocateInfo
			{
				AllocateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _createInfo  ,
				      Handle&                      _commandPool
			)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _commandPool);
			}

			using Parent::Create;

			static void Destroy
			(
				      LogicalDevice::Handle        _deviceHandle,
				      Handle                       _commandPool 
			)
			{
				Parent::Destroy(_deviceHandle, _commandPool, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			static void Free
			(
				      LogicalDevice::Handle  _device        ,
				const AllocateInfo&          _info          ,
				const CommandBuffer::Handle* _commandBuffers
			)
			{
				Parent::Free(_device, _info.Pool, _info.BufferCount, _commandBuffers);	
			}

			using Parent::Free;

		#pragma region SingleTimeCommands

			/**
			 * @brief.
			 */
			static CommandBuffer::Handle BeginSingleTimeCommands(LogicalDevice::Handle _device, CommandPool::Handle _commandPool)
			{
				AllocateInfo allocationInfo{};

				allocationInfo.Level       = ECommandBufferLevel::Primary;
				allocationInfo.Pool        = _commandPool                ;
				allocationInfo.BufferCount = 1                           ;

				CommandBuffer::Handle commandBuffer;

				Allocate(_device, allocationInfo, &commandBuffer);

				CommandBuffer::BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				CommandBuffer::BeginRecord(commandBuffer, beginInfo);

				return commandBuffer;
			}

			/**
			 * @brief.
			 */
			static void EndSingleTimeCommands
			(
				CommandBuffer       ::Handle _commandBuffer, 
				CommandPool         ::Handle _commandPool  , 
				LogicalDevice       ::Handle _device       , 
				LogicalDevice::Queue::Handle _queue
			)
			{
				CommandBuffer::EndRecord(_commandBuffer);

				CommandBuffer::SubmitInfo submitInfo{};

				submitInfo.CommandBufferCount = 1              ;
				submitInfo.CommandBuffers     = &_commandBuffer;

				LogicalDevice::Queue::SubmitToQueue(_queue, 1, submitInfo, Null<Fence::Handle>);

				LogicalDevice::Queue::WaitUntilIdle(_queue);

				Parent::Free(_device, _commandPool, 1, &_commandBuffer);
			}

		#pragma endregion SingleTimeCommands	
		};

		struct CommandBuffer : public V1::CommandBuffer
		{
			using Parent = V1::CommandBuffer;

			struct InheritanceWindow : public Parent::InheritanceWindow
			{
				using Parent = Parent::InheritanceWindow;

				InheritanceWindow()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}

				struct ConditionalRenderingInfo : public Parent::ConditionalRenderingInfo
				{
					ConditionalRenderingInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct PassTransformInfo : public Parent::PassTransformInfo
				{
					PassTransformInfo()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			struct BeginInfo : public Parent::BeginInfo
			{
				BeginInfo()
				{
					SType           = STypeEnum;
					Next            = nullptr  ;
					InheritanceInfo = nullptr;
				}
			};

			struct SubmitInfo : public Parent::SubmitInfo
			{
				using Parent = Parent::SubmitInfo;

				SubmitInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
					WaitSemaphoreCount = 0;
					WaitSemaphores = nullptr;
					WaitDstStageMask = nullptr; 
					CommandBufferCount = 0;
					CommandBuffers = 0;
					SignalSemaphoreCount = 0;
					SignalSemaphores = nullptr;
				}

				struct TimelineSemaphore : public Parent
				{
					TimelineSemaphore()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};

				struct D3D12Fence : public Parent
				{
					D3D12Fence()
					{
						SType = STypeEnum;
						Next  = nullptr  ;
					}
				};
			};

			/** @brief  */
			static void CopyBuffer
			(
				Buffer::Handle               _sourceBuffer     , 
				Buffer::Handle               _destinationBuffer, 
				Buffer::CopyInfo             _regionInfo       ,
				LogicalDevice::Handle        _device           ,
				CommandPool::Handle          _pool             ,
				LogicalDevice::Queue::Handle _queue
			)
			{
				Handle commandBuffer = CommandPool::BeginSingleTimeCommands(_device, _pool);

				Parent::CopyBuffer(commandBuffer, _sourceBuffer, _destinationBuffer, 1, &_regionInfo);

				CommandPool::EndSingleTimeCommands(commandBuffer, _pool, _device, _queue);
			}	

			using Parent::CopyBuffer;

			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer,
					_sourceStageMask,
					_destinationStageMask,
					_dependencyFlags,
					_memoryBarrierCount,
					_memoryBarriers,
					0, nullptr,
					0, nullptr
				);
			}

			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer,
					_sourceStageMask,
					_destinationStageMask,
					_dependencyFlags,
					0, nullptr,
					_bufferMemoryBarrierCount,
					_bufferMemoryBarriers,
					0, nullptr
				);
			}

			static void SubmitPipelineBarrier
			(
				      Handle                  _commandBuffer           ,
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			)
			{
				Parent::SubmitPipelineBarrier
				(
					_commandBuffer,
					_sourceStageMask,
					_destinationStageMask,
					_dependencyFlags,
					0, nullptr,
					0, nullptr,
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			using Parent::SubmitPipelineBarrier;

			static void WaitForEvents
			(
				      Handle               _commandBuffer,
				      uint32               _eventCount,
				const Event::Handle*       _events,
				      Pipeline::StageFlags _srcStageMask,
				      Pipeline::StageFlags _dstStageMask,
				      uint32               _memoryBarrierCount,
				const Memory::Barrier*     _memoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount, _events,
					_srcStageMask, _dstStageMask,
					_memoryBarrierCount, _memoryBarriers,
					0, nullptr, 
					0, nullptr
				);
			}

			static void WaitForEvents
			(
				      Handle                  _commandBuffer,
				      uint32                  _eventCount,
				const Event::Handle*          _events,
				      Pipeline::StageFlags    _srcStageMask,
				      Pipeline::StageFlags    _dstStageMask,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount, _events,
					_srcStageMask, _dstStageMask,
					0, nullptr,
					_bufferMemoryBarrierCount, _bufferMemoryBarriers,
					0, nullptr
				);
			}

			static void WaitForEvents
			(
				      Handle                 _commandBuffer,
				      uint32                 _eventCount,
				const Event::Handle*         _events,
				      Pipeline::StageFlags   _srcStageMask,
				      Pipeline::StageFlags   _dstStageMask,
				      uint32                 _imageMemoryBarrierCount,
				const Image::Memory_Barrier* _imageMemoryBarriers
			)
			{
				Parent::WaitForEvents
				(
					_commandBuffer,
					_eventCount, _events,
					_srcStageMask, _dstStageMask,
					0, nullptr,
					0, nullptr,
					_imageMemoryBarrierCount, _imageMemoryBarriers
				);
			}

			using Parent::WaitForEvents;
		};
	}

	namespace V3
	{
		class CommandBuffer : public V2::CommandBuffer
		{
		public:

			using Parent = V2::CommandBuffer;

			using AllocateInfo = V2::CommandPool::AllocateInfo;

			const AllocateInfo& GetAllocateInfo() const
			{
				return info;
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			void Assign(const LogicalDevice& _device, AllocateInfo& _info, Handle& _handle)
			{
				device = &_device ;
				info   = _info    ;
				handle = _handle  ;
			}

			EResult BeginRecord(const BeginInfo& _info) const
			{
				return Parent::BeginRecord(handle, _info);
			}

			void BeginRenderPass(const RenderPass::BeginInfo& _info, ESubpassContents _contents) const
			{
				Parent::BeginRenderPass(handle, _info, _contents);
			}

			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint          ,
				      Pipeline::Layout&      _layout            ,
				      uint32                 _firstSet          ,
				      uint32                 _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets
			) const
			{
				Parent::BindDescriptorSets(handle, _bindPoint, _layout.GetHandle(), _firstSet, _descritporSetCount, _descriptorSets, 0, nullptr);
			}

			void BindDescriptorSets
			(
				      EPipelineBindPoint     _bindPoint         ,
				      Pipeline::Layout&      _layout            ,
				      uint32                 _firstSet          ,
				      uint32                 _descritporSetCount,
				const DescriptorSet::Handle* _descriptorSets    ,
				      uint32                 _dynamicOffsetCount,
				const uint32*                _dynamicOffsets
			) const
			{
				Parent::BindDescriptorSets(handle, _bindPoint, _layout.GetHandle(), _firstSet, _descritporSetCount, _descriptorSets, _dynamicOffsetCount, _dynamicOffsets);
			}

			void BindIndexBuffer(Buffer& _buffer, DeviceSize _offset, EIndexType _type) const
			{
				Parent::BindIndexBuffer(handle, _buffer.GetHandle(), _offset, _type);
			}

			void BindVertexBuffers(uint32 _firstBinding, uint32 _bindingCount, const Buffer::Handle* _buffers) const
			{
				Parent::BindVertexBuffers(handle, _firstBinding, _bindingCount, _buffers, 0);
			}

			void BindVertexBuffers(uint32 _firstBinding, uint32 _bindingCount, const Buffer::Handle* _buffers, const DeviceSize* _offsets) const
			{
				Parent::BindVertexBuffers(handle, _firstBinding, _bindingCount, _buffers, _offsets);
			}

			void BindPipeline(EPipelineBindPoint _bindPoint, Pipeline& _pipeline) const
			{
				Parent::BindPipeline(handle, _bindPoint, _pipeline.GetHandle());
			}

			void BlitImage(Image& _src, EImageLayout _srcLayout, Image& _dst, EImageLayout _dstLayout, uint32 _regionCount, const Image::Blit* _regions, EFilter _filter) const
			{
				Parent::BlitImage(handle, _src.GetHandle(), _srcLayout, _dst.GetHandle(), _dstLayout, _regionCount, _regions, _filter);
			}

			void CopyBuffer
			(
				      Buffer&                 _sourceBuffer     ,
				      Buffer&                 _destinationBuffer,
				      uint32                  _regionCount      ,
				const Buffer::CopyInfo*       _regions
			) const
			{
				Parent::Parent::CopyBuffer(handle, _sourceBuffer.GetHandle(), _destinationBuffer.GetHandle(), _regionCount, _regions);
			}

			void CopyBufferToImage
			(
				      Buffer&            _srcBuffer     ,
				      Image&             _dstImage      ,
				      EImageLayout       _dstImageLayout,
				      uint32		     _regionCount   ,
				const BufferImageRegion* _regions
			) const
			{
				Parent::CopyBufferToImage(handle, _srcBuffer.GetHandle(), _dstImage.GetHandle(), _dstImageLayout, _regionCount, _regions);
			}

			void Draw
			(
				uint32 _firstVertex  ,
				uint32 _vertexCount  , 
				uint32 _firstInstance,
				uint32 _instanceCount
			) const
			{
				Parent::Draw(handle, _firstVertex, _vertexCount, _firstInstance, _instanceCount);
			}

			void DrawIndexed
			(
				uint32 _indexCount   ,
				uint32 _instanceCount,
				uint32 _firstIndex   ,
				sint32 _vertexOffset ,
				uint32 _firstInstance
			) const
			{
				Parent::DrawIndexed(handle, _indexCount, _instanceCount, _firstIndex, _vertexOffset, _firstInstance);
			}

			EResult EndRecord() const
			{
				return Parent::EndRecord(handle);
			}

			void EndRenderPass() const
			{
				Parent::EndRenderPass(handle);
			}

			void Execute
			(
				      uint32   _secondaryBufferCount,
				const Handle* _secondaryBuffers
			) const
			{
				Parent::Execute(handle, _secondaryBufferCount, _secondaryBuffers);
			}

			void ResetEvent(Event& _event, Pipeline::StageFlags _stageMask) const
			{
				Parent::ResetEvent(handle, _event.GetHandle(), _stageMask);
			}

		#pragma region SubmitPipelineBarrier_OO

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			void SubmitPipelineBarrier
			(
				      Pipeline::StageFlags    _sourceStageMask         ,
				      Pipeline::StageFlags    _destinationStageMask    ,
				      DependencyFlags         _dependencyFlags         ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::SubmitPipelineBarrier
				(
					handle, 
					_sourceStageMask, 
					_destinationStageMask, 
					_dependencyFlags, 
					_memoryBarrierCount, 
					_memoryBarriers, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers, 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

		#pragma endregion SubmitPipelineBarrier_OO

			void SetDeviceMask(uint32 _deviceMask) const
			{
				Parent::SetDeviceMask(handle, _deviceMask);
			}

			void SetEvent(Event& _event, Pipeline::StageFlags _stageMask) const
			{
				Parent::SetEvent(handle, _event.GetHandle(), _stageMask);
			}

		#pragma region WaitForEvents_OO

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers
				);
			}

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers
				);
			}

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

			void WaitForEvents
			(
				      uint32                  _eventCount              ,
				const Event::Handle*          _events                  ,
				      Pipeline::StageFlags    _srcStageMask            ,
				      Pipeline::StageFlags    _dstStageMask            ,
				      uint32                  _memoryBarrierCount      ,
				const Memory::Barrier*        _memoryBarriers          ,
				      uint32                  _bufferMemoryBarrierCount,
				const Buffer::Memory_Barrier* _bufferMemoryBarriers    ,
				      uint32                  _imageMemoryBarrierCount ,
				const Image::Memory_Barrier*  _imageMemoryBarriers
			) const
			{
				Parent::WaitForEvents
				(
					handle, 
					_eventCount, 
					_events, 
					_srcStageMask, 
					_dstStageMask, 
					_memoryBarrierCount, 
					_memoryBarriers, 
					_bufferMemoryBarrierCount, 
					_bufferMemoryBarriers,
					_imageMemoryBarrierCount,
					_imageMemoryBarriers
				);
			}

		#pragma endregion WaitForEvents_OO

			operator Handle()
			{
				return handle;
			}

			operator const Handle&() const
			{
				return handle;
			}

		protected:

			Handle handle;

			AllocateInfo info;

			const LogicalDevice* device;
		};

		class CommandPool : public V2::CommandPool
		{
		public:
			using Parent = V2::CommandPool;

			using CommandBuffer = V3::CommandBuffer;

			EResult Allocate(AllocateInfo& _info, CommandBuffer& _buffer)
			{
				CommandBuffer::Handle bufferHandle;

				EResult returnCode = Parent::Allocate(*device, _info, &bufferHandle);

				if (returnCode != EResult::Success) return returnCode;

				_buffer.Assign(*device, _info, bufferHandle);

				return returnCode;
			}

			EResult Allocate(AllocateInfo& _info, CommandBuffer::Handle* _handles)
			{
				EResult returnCode = Parent::Allocate(*device, _info, _handles);

				return returnCode;
			}

			EResult Allocate(ECommandBufferLevel _level, uint32 _count, CommandBuffer::Handle* _handles)
			{
				AllocateInfo allocInfo; 

				allocInfo.Level       = _level; 
				allocInfo.Pool        = handle; 
				allocInfo.BufferCount = _count;

				EResult returnCode = Parent::Allocate(*device, allocInfo, _handles);

				return returnCode;
			}

			EResult Allocate
			(
				ECommandBufferLevel                 _level         ,
				uint32                              _count         ,
				std::vector<CommandBuffer>&         _commandBuffers,
				std::vector<CommandBuffer::Handle>& _handles
			)
			{
				AllocateInfo allocInfo; 
				
				allocInfo.Level       = _level; 
				allocInfo.Pool        = handle; 
				allocInfo.BufferCount = _count;

				_commandBuffers.resize(_count); _handles.resize(_count);

				EResult returnCode = Parent::Allocate(*device, allocInfo, _handles.data());

				if (returnCode != EResult::Success) return returnCode;

				for (DeviceSize index = 0; index < _count; index++)
				{
					_commandBuffers[index].Assign(*device, allocInfo, _handles[index]);
				}

				return returnCode;
			}

			EResult Create(const LogicalDevice& _device, CreateInfo& _info)
			{
				device    = &_device                ;
				info      = _info                   ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(*device, info, handle);	
			}

			EResult Create(const LogicalDevice& _device, CreateInfo& _info, const Memory::AllocationCallbacks* _allocator)
			{
				device    = &_device  ;
				info      = _info     ;
				allocator = _allocator;

				return Parent::Create(*device, info, allocator, handle);	
			}

			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);
			}

			void Free(uint32 _bufferCount, const CommandBuffer::Handle* _commandBuffers)
			{
				Parent::Free(*device, handle, _bufferCount, _commandBuffers);
			}

			void Free
			(
				const AllocateInfo&          _info          ,
				const CommandBuffer::Handle* _commandBuffers
			)
			{
				Parent::Free(*device, handle, _info.BufferCount, _commandBuffers);	
			}

			void Free(CommandBuffer& _commandBuffer)
			{
				Parent::Free(*device, handle, 1, &_commandBuffer.GetHandle());
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult Reset(ResetFlags _flags)
			{
				return Parent::Reset(*device, handle, _flags);
			}

			void Trim(TrimFlags _flags)
			{
				Parent::Trim(*device, handle, _flags);
			}

			operator Handle()
			{
				return handle;
			}

			operator const Handle&() const
			{
				return handle;
			}

		#pragma region SingleTimeCommands

			/**
			 * @brief.
			 */
			CommandBuffer BeginSingleTimeCommands(EResult& _result)
			{
				AllocateInfo allocationInfo{};

				allocationInfo.Level       = ECommandBufferLevel::Primary;
				allocationInfo.Pool        = handle                      ;
				allocationInfo.BufferCount = 1                           ;

				CommandBuffer commandBuffer;

				_result = Allocate(allocationInfo, commandBuffer);

				if (_result != EResult::Success) return commandBuffer;

				CommandBuffer::BeginInfo beginInfo{};

				beginInfo.Flags = ECommandBufferUsageFlag::OneTimeSubmit;

				_result = commandBuffer.BeginRecord(beginInfo);

				return commandBuffer;
			}

			/**
			 * @brief.
			 */
			EResult EndSingleTimeCommands
			(
				      CommandBuffer&        _commandBuffer, 
				const LogicalDevice::Queue& _queue
			)
			{
				EResult result = EResult::Incomplete;

				result = _commandBuffer.EndRecord();

				if (result != EResult::Success) return result;

				CommandBuffer::SubmitInfo submitInfo{};

				submitInfo.CommandBufferCount = 1                          ;
				submitInfo.CommandBuffers     = &_commandBuffer.GetHandle();

				result = _queue.SubmitToQueue(1, submitInfo, Null<Fence::Handle>);

				if (result != EResult::Success) return result;

				result = _queue.WaitUntilIdle();

				if (result != EResult::Success) return result;

				Free(_commandBuffer);

				return result;
			}

			EResult CopyBuffer
			(
				      Buffer&               _sourceBuffer     , 
				      Buffer&               _destinationBuffer, 
				      Buffer::CopyInfo&     _regionInfo       ,
				const LogicalDevice::Queue& _queue
			) 
			{
				EResult result;

				CommandBuffer commandBuffer = BeginSingleTimeCommands(result);

				if (result != EResult::Success) return result;

				commandBuffer.CopyBuffer(_sourceBuffer, _destinationBuffer, 1, &_regionInfo);

				result = EndSingleTimeCommands(commandBuffer, _queue);

				return result;
			}

		#pragma endregion SingleTimeCommands

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			CreateInfo info;

			const LogicalDevice* device;
		};
	}
}




/** @file VT_Surface.hpp

@brief Vaulted Thermals: Surface

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_surface">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V0
	{
		/**
		 * @brief Cross-Platform set of definitions for a Surface.
		 */
		struct Surface_PlatformAgnostic
		{
			using Image = V1::Image;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceKHR">Specification</a>  */
			using Handle = VkSurfaceKHR;   ///< Opaque handle to a surface object.

			using ETransform = ESurfaceTransformFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceTransformFlagsKHR">Specification</a>  */
			using ETransformFlags     = Bitmask<ESurfaceTransformFlag, VkSurfaceTransformFlagsKHR>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkCompositeAlphaFlagsKHR">Specification</a>  */
			using CompositeAlphaFlags = Bitmask<ECompositeAlpha      , VkCompositeAlphaFlagsKHR  >;

			/**
			 * @brief Structure describing capabilities of a surface.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceCapabilitiesKHR">Specification</a> 
			 */
			struct Capabilities : V0::VKStruct_Base<VkSurfaceCapabilitiesKHR>
			{
				uint32              MinImageCount          ;
				uint32              MaxImageCount          ;
				Extent2D            CurrentExtent          ;
				Extent2D            MinImageExtent         ;
				Extent2D            MaxImageExtent         ;
				uint32              MaxImageArrayLayers    ;
				ETransformFlags     SupportedTransforms    ;
				ETransform          CurrentTransform       ;
				CompositeAlphaFlags SupportedCompositeAlpha;
				Image::UsageFlags   SupportedUsageFlags    ;
			};

			/**
			 * @brief Structure describing a supported swapchain format-color space pair.
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSurfaceFormatKHR">Specification</a> 
			 */
			struct Format : V0::VKStruct_Base<VkSurfaceFormatKHR>
			{
				EFormat     Format    ;
				EColorSpace ColorSpace;
			};
		};

		/** @brief Used to create an OS platform's surface type. */
		template<EOS_Platform>
		struct Surface_Maker;

		/** @brief Defines a Surface's extended definitions for Windows. */
		template<>
		struct Surface_Maker<EOS_Platform::Windows> : public Surface_PlatformAgnostic
		{
			using OS_AppHandle    = PlatformTypes::OS_AppHandle   ;
			using OS_WindowHandle = PlatformTypes::OS_WindowHandle;

			static constexpr RoCStr OSSurface = InstanceExt::Win32Surface;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkWin32SurfaceCreateInfoKHR">Specification</a> */
			struct CreateInfo : V0::VKStruct_Base<VkWin32SurfaceCreateInfoKHR, EStructureType::Win32_Surface_CreateInfo_KHR>
			{
				using CreateFlags = Bitmask<EUndefined, VkWin32SurfaceCreateFlagsKHR>;   ///< Reserved for future use.

				      EType           SType      ;
				const void*           Next       ;
				      CreateFlags     Flags      ;
				      OS_AppHandle    OSAppHandle;
				      OS_WindowHandle OSWinHandle;
			};

			/**
			 * @brief Returns the handle for the current process.
			 * 
			 * @details
			 * <a href="https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea">Specification</a> 
			 * 
			 * \return 
			 */
			static OS_AppHandle GetOS_AppHandle()
			{
				return GetModuleHandle(nullptr);
			}

			/**
			 * @brief Create a slink:VkSurfaceKHR object for an Win32 native window.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateWin32SurfaceKHR">Specification</a> 
			 * 
			 * \param _appHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _surfaceHandle
			 * \return 
			 */
			static EResult Create
			(
				      V1::AppInstance::Handle      _appHandle    ,
				      CreateInfo&                  _createInfo   ,
				const Memory::AllocationCallbacks* _allocator    ,
				      Handle&                      _surfaceHandle
			)
			{
				return EResult(vkCreateWin32SurfaceKHR(_appHandle, _createInfo.operator const VkWin32SurfaceCreateInfoKHR*(), _allocator->operator const VkAllocationCallbacks*(), &_surfaceHandle));
			}
		};

		/** @brief Surface definition for the currently detected OS platform. */
		using Surface = Surface_Maker<OS_Platform>;
	}

	namespace V1
	{
		/** @brief Surfaces hook onto a window to use as a rendering target. */
		struct Surface : public V0::Surface
		{
			/**
			 * @brief Destroy a VkSurfaceKHR object.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySurfaceKHR">Specification</a> 
			 * 
			 * \param _appHandle
			 * \param _surfaceHandle
			 * \param _allocator
			 */
			static void Destroy(AppInstance::Handle _appHandle, Surface::Handle _surfaceHandle, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroySurfaceKHR(_appHandle, _surfaceHandle, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief Query if presentation is supported.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfaceSupportKHR">Specification</a> 
			 * 
			 * \param _physDeviceHandle
			 * \param _queueFamilyIndex
			 * \param _surfaceHandle
			 * \param _checkResult
			 * \return 
			 */
			static EResult CheckPhysicalDeviceSupport
			(
				V1::PhysicalDevice::Handle _physDeviceHandle,
				uint32                     _queueFamilyIndex,
				Surface::Handle            _surfaceHandle   ,
				Bool& _checkResult
			)
			{
				return EResult(vkGetPhysicalDeviceSurfaceSupportKHR(_physDeviceHandle, _queueFamilyIndex, _surfaceHandle, &_checkResult));
			}

			/**
			 * @brief Query surface capabilities.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfaceCapabilitiesKHR">Specification</a>  
			 * 
			 * \param _deviceHandle
			 * \param _surface
			 * \param _capabilitiesResult
			 * \return 
			 */
			static EResult GetPhysicalDeviceCapabilities(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surface, Surface::Capabilities& _capabilitiesResult)
			{
				return EResult(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_deviceHandle, _surface, (VkSurfaceCapabilitiesKHR*)(&_capabilitiesResult)));
			}

			/**
			 * @brief Query color formats supported by surface.
			 * 
			 * @details 
			 * If pSurfaceFormats is NULL, then the number of format pairs supported for the given surface is returned in pSurfaceFormatCount. 
			 * Otherwise, pSurfaceFormatCount must point to a variable set by the user to the number of elements in the pSurfaceFormats array, 
			 * and on return the variable is overwritten with the number of structures actually written to pSurfaceFormats.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfaceFormatsKHR">Specification</a>  
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _numFormats
			 * \param _formatsContainer
			 * \return 
			 */
			static EResult GetFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, uint32& _numFormats, Surface::Format* _formatsContainer)
			{
				return EResult(vkGetPhysicalDeviceSurfaceFormatsKHR(_deviceHandle, _surfaceHandle, &_numFormats, _formatsContainer->operator VkSurfaceFormatKHR*()));
			}

			/**
			 * @brief Query supported presentation modes.
			 * 
			 * @details
			 * If pPresentModes is NULL, then the number of presentation modes supported for the given surface is returned in pPresentModeCount. 
			 * Otherwise, pPresentModeCount must point to a variable set by the user to the number of elements in the pPresentModes array, 
			 * and on return the variable is overwritten with the number of values actually written to pPresentModes.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetPhysicalDeviceSurfacePresentModesKHR">Specification</a>  
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _numPresentationModes
			 * \param _presentationModesContainer
			 * \return 
			 */
			static EResult QuerySupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, uint32& _numPresentationModes, EPresentationMode* _presentationModesContainer)
			{
				return EResult(vkGetPhysicalDeviceSurfacePresentModesKHR(_deviceHandle, _surfaceHandle, &_numPresentationModes, (VkPresentModeKHR*)(_presentationModesContainer)));
			}
		};
	}

	namespace V2
	{
		/** @brief Surfaces hook onto a window to use as a rendering target. */
		struct Surface : public  V1::Surface
		{
			using Parent = V1::Surface;

			struct Capabilities : public Parent::Capabilities
			{
				bool operator== (const Capabilities& _other)
				{
					return
						MinImageCount           == _other.MinImageCount           &&
						MaxImageCount           == _other.MaxImageCount           &&
						CurrentExtent           == _other.CurrentExtent           &&
						MinImageExtent          == _other.MinImageExtent          &&
						MaxImageExtent          == _other.MaxImageExtent          &&
						MaxImageArrayLayers     == _other.MaxImageArrayLayers     &&
						SupportedTransforms     == _other.SupportedTransforms     &&
						SupportedCompositeAlpha == _other.SupportedCompositeAlpha &&
						SupportedUsageFlags     == _other.SupportedUsageFlags 
						? true : false;
				}

				bool operator!= (const Capabilities& _other)
				{
					return
						MinImageCount           == _other.MinImageCount           &&
						MaxImageCount           == _other.MaxImageCount           &&
						CurrentExtent           == _other.CurrentExtent           &&
						MinImageExtent          == _other.MinImageExtent          &&
						MaxImageExtent          == _other.MaxImageExtent          &&
						MaxImageArrayLayers     == _other.MaxImageArrayLayers     &&
						SupportedTransforms     == _other.SupportedTransforms     &&
						SupportedCompositeAlpha == _other.SupportedCompositeAlpha &&
						SupportedUsageFlags     == _other.SupportedUsageFlags 
						? false : true;
				}
			};

			struct CreateInfo : public Parent::CreateInfo
			{
				CreateInfo()
				{
					SType       = STypeEnum        ;
					Next        = nullptr          ;
					OSAppHandle = GetOS_AppHandle();
				}
			};

			static EResult Create
			(
				AppInstance::Handle _appHandle    ,
				CreateInfo&         _createInfo   ,
				Handle&             _surfaceHandle
			)
			{
				return Parent::Create(_appHandle, _createInfo, Memory::DefaultAllocator, _surfaceHandle);
			}

			using Parent::Create;

			static void Destroy(AppInstance::Handle _appHandle, Surface::Handle _surfaceHandle)
			{
				Parent::Destroy(_appHandle, _surfaceHandle, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Provides the available surface formats.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _formatsContainer
			 * \return 
			 */
			static EResult GetAvailableFormats(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, std::vector<Surface::Format>& _formatsContainer)
			{
				uint32 numFormats; 
				
				EResult result = GetFormats(_deviceHandle, _surfaceHandle, numFormats, nullptr);

				if (result != EResult::Success) return result;

				_formatsContainer.resize(numFormats);

				result = GetFormats(_deviceHandle, _surfaceHandle, numFormats, _formatsContainer.data());

				return result;
			}

			/**
			 * @brief Provides the supported presentation modes.
			 * 
			 * \param _deviceHandle
			 * \param _surfaceHandle
			 * \param _presentationModesContainer
			 * \return 
			 */
			static EResult GetSupportedPresentationModes(PhysicalDevice::Handle _deviceHandle, Surface::Handle _surfaceHandle, std::vector<EPresentationMode>& _presentationModesContainer)
			{
				uint32 numPresentationModes; 
				
				EResult result = QuerySupportedPresentationModes(_deviceHandle, _surfaceHandle, numPresentationModes, nullptr);

				if (result != EResult::Success) return result;

				_presentationModesContainer.resize(numPresentationModes);

				result = QuerySupportedPresentationModes(_deviceHandle, _surfaceHandle, numPresentationModes, _presentationModesContainer.data());
				
				return result;
			}
		};
	}

	namespace V3
	{
		class Surface : public V2::Surface
		{
		public:

			using Parent = V2::Surface;

			void AssignPhysicalDevice(const PhysicalDevice::Handle _physicalDevice)
			{
				physicalDevice = _physicalDevice;
			}

			EResult Create(AppInstance::Handle _app, OS_WindowHandle _window)
			{
				CreateInfo geninfo {}; geninfo.OSWinHandle = _window;

				app       = _app                    ;
				info      = geninfo                 ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(app, info, handle);
			}

			EResult Create
			(
				AppInstance::Handle _appHandle ,
				CreateInfo&  _createInfo
			)
			{
				app       = _appHandle;
				info      = _createInfo;
				allocator = Memory::DefaultAllocator;
				
				return Parent::Create(app, info, handle);
			}

			EResult Create
			(
				      AppInstance::Handle          _appHandle ,
				      CreateInfo&                  _createInfo,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				app       = _appHandle ;
				info      = _createInfo;
				allocator = _allocator ;
				
				return Parent::Create(app, info, allocator, handle);
			}

			EResult CheckPhysicalDeviceSupport
			(
				uint32 _queueFamilyIndex,
				Bool&  _checkResult
			)
			{
				return Parent::CheckPhysicalDeviceSupport(physicalDevice, _queueFamilyIndex, handle, _checkResult);
			}

			void Destroy()
			{
				Parent::Destroy(app, handle);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult GetAvailableFormats(std::vector<Format>& _formatsContainer) const
			{
				return Parent::GetAvailableFormats(physicalDevice, handle, _formatsContainer);
			}

			EResult GetPhysicalDeviceCapabilities(Capabilities& _result) const
			{
				return Parent::GetPhysicalDeviceCapabilities(physicalDevice, handle, _result);
			}

			EResult GetSupportedPresentationModes(std::vector<EPresentationMode>& _presentationModesContainer) const
			{
				return Parent::GetSupportedPresentationModes(physicalDevice, handle, _presentationModesContainer);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle&() const
			{
				return handle;
			}

		protected:

			AppInstance::Handle app;

			PhysicalDevice::Handle physicalDevice;

			CreateInfo info;

			const Memory::AllocationCallbacks* allocator;

			Handle handle;
		};
	}
}




/** @file VT_SwapChain.hpp

@brief Vaulted Thermals: Swap Chain

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_swapchain">Specification</a> 
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		/**
		 * @brief A queue of images that can be presented to a surface.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_wsi_swapchain">Specification</a> 
		 */
		struct Swapchain
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSwapchainKHR">Specification</a>  */
			using Handle = VkSwapchainKHR;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkSwapchainCreateInfoKHR.html">Specification</a> .
			 */
			struct CreateInfo : V0::VKStruct_Base<VkSwapchainCreateInfoKHR, EStructureType::SwapChain_CreateInfo_KHR>
			{
				using ECreateFlag = ESwapchainCreateFlag;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSwapchainCreateFlagsKHR">Specification</a>  */
				using CreateFlags = Bitmask<ECreateFlag, VkSwapchainCreateFlagsKHR >;

				      EType                 SType                ;
				const void*                 Next                 ;
				      CreateFlags           Flags                ;
				      Surface::Handle       Surface              ; 
				      uint32                MinImageCount        ;
				      EFormat               ImageFormat          ;
				      EColorSpace           ImageColorSpace      ;
				      Extent2D              ImageExtent          ;
				      uint32                ImageArrayLayers     ;
				      Image::UsageFlags	    ImageUsage           ;
				      ESharingMode          ImageSharingMode     ;
				      uint32                QueueFamilyIndexCount;
				const uint32*               QueueFamilyIndices   ;
				      ESurfaceTransformFlag PreTransform         ;
				      ECompositeAlpha       CompositeAlpha       ;
				      EPresentationMode     PresentationMode     ;
				      Bool                  Clipped              ;
				      Handle                OldSwapchain         ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPresentInfoKHR">Specification</a>  */
			struct PresentationInfo : V0::VKStruct_Base<VkPresentInfoKHR, EStructureType::PresentInfo_KHR>
			{
				      EType              SType             ;
				const void*              Next              ;
				      uint32             WaitSemaphoreCount;
				const Semaphore::Handle* WaitSemaphores    ;
				      uint32             SwapchainCount    ;
				const Handle*            Swapchains        ;
				const uint32*            ImageIndices      ;
				      EResult*           Results           ;
			};

			/**
			 * @brief
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkAcquireNextImageKHR">Specification</a>
			 * 
			 * \param _device
			 * \param _swapchain
			 * \param _timeout
			 * \param _semaphore
			 * \param _fence
			 * \param _imageIndex
			 * \return 
			 */
			static EResult AcquireNextImage
			(
				LogicalDevice::Handle _device    ,
				Handle                _swapchain ,
				uInt64                _timeout   ,
				Semaphore::Handle     _semaphore ,
				Fence::Handle         _fence     ,
				uint32&               _imageIndex
			)
			{
				return EResult(vkAcquireNextImageKHR(_device, _swapchain, _timeout, _semaphore, _fence, &_imageIndex));
			}

			/**
			 * @brief Create a swapchain.
			 * 
			 * @details
			 * If the oldSwapchain parameter of pCreateInfo is a valid swapchain, which has exclusive full-screen access, that access is released from oldSwapchain. 
			 * If the command succeeds in this case, the newly created swapchain will automatically acquire exclusive full-screen access from oldSwapchain.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSwapchainKHR">link text</a> 
			 * 
			 * \param _deviceHandle
			 * \param _creationSpecification
			 * \param _allocator
			 * \param _swapChain
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _info        ,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _swapChain
			)
			{
				return EResult(vkCreateSwapchainKHR(_deviceHandle, _info, _allocator->operator const VkAllocationCallbacks*(), &_swapChain));
			};

			/**
			 * @brief Destroy a swapchain object.
			 * 
			 * @details
			 * The application must not destroy a swapchain until after completion of all outstanding operations on images that were acquired from the swapchain. 
			 * swapchain and all associated VkImage handles are destroyed, and must not be acquired or used any more by the application.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySwapchainKHR">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _swapChainToDestroy
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _swapChainToDestroy, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroySwapchainKHR(_deviceHandle, _swapChainToDestroy, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief Obtain the array of presentable images associated with a swapchain.
			 * 
			 * @details
			 * If pSwapchainImages is NULL, then the number of presentable images for swapchain is returned in pSwapchainImageCount. 
			 * Otherwise, pSwapchainImageCount must point to a variable set by the user to the number of elements in the pSwapchainImages array, 
			 * and on return the variable is overwritten with the number of structures actually written to pSwapchainImages.
			 * 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSwapchainImagesKHR">Specification</a> 
			 * 
			 * \param _deviceHandle
			 * \param _swapChain
			 * \param _numImages
			 * \param _images
			 * \return 
			 */
			static EResult QueryImages(LogicalDevice::Handle _deviceHandle, Handle _swapChain, uint32& _numImages, Image::Handle* _imagesContainer)
			{
				return EResult(vkGetSwapchainImagesKHR(_deviceHandle, _swapChain, &_numImages, _imagesContainer));
			}
		};
	}

	namespace V2
	{
		struct Swapchain : V1::Swapchain
		{
			using Parent = V1::Swapchain;

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct PresentationInfo : Parent::PresentationInfo
			{
				PresentationInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};
			
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _info        ,
				      Handle&               _swapChain
			)
			{
				return Parent::Create(_deviceHandle, _info, Memory::DefaultAllocator, _swapChain);
			}

			using Parent::Create;

			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _swapChainToDestroy)
			{
				Parent::Destroy(_deviceHandle, _swapChainToDestroy, Memory::DefaultAllocator);
			}

			using Parent::Destroy;

			/**
			 * @brief Provides all presentable images with the swapchain.
			 * 
			 * \param _deviceHandle
			 * \param _swapChain
			 * \param _images
			 * \return 
			 */
			static EResult GetImages
			(
				LogicalDevice::Handle       _deviceHandle,
				Handle                      _swapChain   ,
				std::vector<Image::Handle>* _images
			)
			{
				uint32 numImages;

				EResult result = QueryImages(_deviceHandle, _swapChain, numImages, nullptr);

				if (result != EResult::Success) return result;

				_images->resize(numImages);
					
				result = QueryImages(_deviceHandle, _swapChain, numImages, _images->data());

				return result;
			}
		};
	}

	namespace V3
	{
		class Swapchain : public V2::Swapchain
		{
		public:

			using Parent = V2::Swapchain;

			EResult AcquireNextImage
			(
				uInt64                _timeout   ,
				Semaphore::Handle     _semaphore ,
				Fence::Handle         _fence     ,
				uint32&               _imageIndex
			)
			{
				return Parent::AcquireNextImage(device, handle, _timeout, _semaphore, _fence, _imageIndex);
			}

			EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _info        
			)
			{
				device    = _deviceHandle;
				info      = _info        ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(device, info, handle);
			}

			EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _info        ,
				const Memory::AllocationCallbacks* _allocator   
			)
			{
				device    = _deviceHandle;
				info      = _info        ;
				allocator = _allocator   ;

				return Parent::Create(device, info, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(device, handle);
			}

			const Handle& GetHandle() const
			{
				return handle;
			}

			EResult GetImages(std::vector<Image>& _images)
			{
				uint32 numImages;

				EResult result = QueryImages(numImages, nullptr);

				if (result != EResult::Success) return result;

				_images.resize(numImages);	std::vector<Image::Handle> handles(numImages);

				result = QueryImages(numImages, handles.data());

				for (DeviceSize index = 0; index < numImages; index++)
				{
					_images[index].Assign(device, handles[index]);
				}

				return result;
			}

			uint32 GetMinimumImageCount() const
			{
				return info.MinImageCount;
			}

			EResult QueryImages(uint32& _numImages, Image::Handle* _imagesContainer)
			{
				return Parent::QueryImages(device, handle, _numImages, _imagesContainer);
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			Handle handle;

			CreateInfo info;

			const Memory::AllocationCallbacks* allocator;

			LogicalDevice::Handle device;
		};
	}
}




/**
VT_Debug.hpp
*/



#ifndef VT_Option__Use_Short_Namespace
namespace VaultedThermals
#else
namespace VT
#endif
{
	namespace V1
	{
		using CallbackDataFlags = Bitmask<EUndefined , Flags>;   ///< TODO: Add comment on what this is for.

		/** @brief Pointer to the Create Debug Messenger Command. */ 
		using FPtr_CreateMessenger = PFN_vkCreateDebugUtilsMessengerEXT;

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageSeverityFlagsEXT">Specification</a>  */
		using MessageServerityFlags = Bitmask<EDebugUtilities_MessageSeverity, VkDebugUtilsMessageSeverityFlagsEXT>;
		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessageTypeFlagsEXT">Specification</a>  */
		using MessageTypeFlags      = Bitmask<EDebugUtilities_MessageType    , VkDebugUtilsMessageTypeFlagsEXT>;

		

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsLabelEXT">Specification</a>  */
		struct Label : V0::VKStruct_Base<VkDebugUtilsLabelEXT, EStructureType::DebugUtils_Label_EXT>
		{
				  EType   SType    ;
			const void*   Next;
			const char*   Name     ;
				  float32 Color[4] ;
		};

		/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsObjectNameInfoEXT">Specification</a>  */
		struct ObjectInfo : V0::VKStruct_Base<VkDebugUtilsObjectNameInfoEXT, EStructureType::DebugUtils_ObjectName_Info_EXT>
		{
				  EType       SType    ;
			const void*       Next;
				  EObjectType Type     ;
				  uInt64      Handle   ;
			const char*       Name     ;
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#debugging-debug-utils">Specification</a>
		 */
		struct DebugMessenger
		{
		public:
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerEXT">Specification</a>  */
			using Handle = VkDebugUtilsMessengerEXT;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCallbackDataEXT">Specification</a>  */
			struct CallbackData : V0::VKStruct_Base<VkDebugUtilsMessengerCallbackDataEXT, EStructureType::DebugUtils_MessengerCallback_Data_EXT>
			{
				using FlagsMask = Bitmask<EUndefined, Flags>;

					  EType       SType               ;
				const void*       Next                ;
					  FlagsMask   Flags               ;
				const char*       MesssageIDName      ;
					  sint32      MessageIDNumber     ;
				const char*       Message             ;
					  uint32      QueueLabelCount     ;
				const Label*      QueueLabels         ;
					  uint32      CMDBufferLabel_Count;
				const Label*      CMDBufferLabels     ;
					  uint32      ObjectCount         ;
				const ObjectInfo* Objects             ;
			};

			using CallbackDelegate = VK_FPtr<Bool, MessageServerityFlags, MessageTypeFlags, const CallbackData, void* >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDebugUtilsMessengerCreateInfoEXT">Specification</a>  */
			struct CreateInfo : V0::VKStruct_Base<VkDebugUtilsMessengerCreateInfoEXT, EStructureType::DebugUtils_Messenger_CreateInfo_EXT>
			{
				using CreateFlags = Bitmask<EUndefined, Flags>;

					  EType                 SType       ;
				const void*                 Next        ;
					  CreateFlags           Flags       ;
					  MessageServerityFlags Serverity   ;
					  MessageTypeFlags      Type        ;
					  CallbackDelegate      UserCallback;
					  void*                 UserData    ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateDebugUtilsMessengerEXT">Specification</a> 
			 * 
			 * \param _appInstance
			 * \param _createSpec
			 * \param _allocator
			 * \param _messenger
			 * \return 
			 */
			static EResult Create
			(
					  AppInstance::Handle          _appInstance,
				const DebugMessenger::CreateInfo&  _createSpec ,
				const Memory::AllocationCallbacks* _allocator  ,
					  DebugMessenger::Handle&      _messenger
			)
			{
				static FPtr_CreateMessenger delegate = nullptr;

				if (delegate == nullptr) delegate = AppInstance::GetProcedureAddress<FPtr_CreateMessenger>(_appInstance, "vkCreateDebugUtilsMessengerEXT");

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

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyDebugUtilsMessengerEXT">Specification</a> .
			 * 
			 * \param _appInstance
			 * \param _messenger
			 * \param _allocator
			 */
			static void Destroy
			(
					  AppInstance::Handle          _appInstance,
					  DebugMessenger::Handle       _messenger  ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				using FPtr_DestroyMessenger = PFN_vkDestroyDebugUtilsMessengerEXT;

				static FPtr_DestroyMessenger delegate = nullptr;
				
				if (delegate == nullptr) delegate = AppInstance::GetProcedureAddress<FPtr_DestroyMessenger>(_appInstance, "vkDestroyDebugUtilsMessengerEXT");

				if (delegate != nullptr)
				{
					delegate(_appInstance, _messenger, _allocator->operator const VkAllocationCallbacks*());
				}
			}
		}; 
	}

	namespace V2
	{
		using V1::CallbackDataFlags;
		using V1::FPtr_CreateMessenger;
		using V1::MessageServerityFlags;
		using V1::MessageTypeFlags;

		struct Label : V1::Label
		{
			Label()
			{
				SType = STypeEnum;
				Next  = nullptr  ;
			}
		};

		struct ObjectInfo : V1::ObjectInfo
		{
			ObjectInfo()
			{
				SType = STypeEnum;
				Next  = nullptr  ;
			}
		};

		struct DebugMessenger : public V1::DebugMessenger
		{
			using Parent = V1::DebugMessenger;

			struct CallbackData : Parent::CallbackData
			{
				CallbackData()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			struct CreateInfo : Parent::CreateInfo
			{
				CreateInfo()
				{
					SType = STypeEnum;
					Next  = nullptr  ;
				}
			};

			static EResult Create
			(
				      AppInstance::Handle          _appInstance,
				const DebugMessenger::CreateInfo&  _createSpec ,
				      DebugMessenger::Handle&      _messenger
			)
			{
				return Parent::Create(_appInstance, _createSpec, Memory::DefaultAllocator,_messenger);
			}

			using Parent::Create;

			static void Destroy
			(
				      AppInstance::Handle          _appInstance,
				      DebugMessenger::Handle       _messenger  
			)
			{
				Parent::Destroy(_appInstance, _messenger, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		
	}

	namespace V3
	{
		using V2::CallbackDataFlags;
		using V2::FPtr_CreateMessenger;
		using V2::MessageServerityFlags;
		using V2::MessageTypeFlags;

		class DebugMessenger : public V2::DebugMessenger
		{
		public:

			using Parent = V2::DebugMessenger;

			void AssignInfo(const CreateInfo& _info)
			{
				info = _info;
			}

			EResult Create
			(
				AppInstance::Handle _appInstance
			)
			{
				app       = _appInstance ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(app, info, handle);
			}

			EResult Create
			(
					  AppInstance::Handle          _appInstance,
				const Memory::AllocationCallbacks* _allocator  
			)
			{
				app       = _appInstance;
				allocator = _allocator  ;

				return Parent::Create(app, info, allocator, handle);
			}

			EResult Create
			(
				      AppInstance::Handle _appInstance,
				const CreateInfo&         _createSpec 
			)
			{
				app       = _appInstance ;
				info      = _createSpec  ;
				allocator = Memory::DefaultAllocator;

				return Parent::Create(app, _createSpec, handle);
			}

			EResult Create
			(
					  AppInstance::Handle          _appInstance,
				const CreateInfo&                  _createSpec ,
				const Memory::AllocationCallbacks* _allocator  
			)
			{
				app       = _appInstance ;
				info      = _createSpec  ;
				allocator = _allocator   ;

				return Parent::Create(app, _createSpec, allocator, handle);
			}

			void Destroy()
			{
				Parent::Destroy(app, handle, allocator);
			}

			const CreateInfo& GetInfo() const
			{
				return info;
			}

			operator Handle()
			{
				return handle;
			}

			operator Handle() const
			{
				return handle;
			}

			operator const Handle& () const
			{
				return handle;
			}

		protected:

			AppInstance::Handle app;

			CreateInfo info;

			const Memory::AllocationCallbacks* allocator;

			Handle handle;
		};
	}
}
