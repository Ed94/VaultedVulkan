/*!
@file VT_Backend.hpp

@brief Vaulted Thermals: Backend

@details Contains implementation related to library backend.
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"



#ifndef BITMASK_DEFINED
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

#endif



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
	/** @namespace Vault_0

	@brief Backend vault for VaultedThermals

	@details For now only abstracts away OS Platform details and basic meta-structure definitions.
	*/
	namespace V0
	{
		/** 
		@addtogroup Vault_0
		@{
		*/

		#ifdef VT_Option__Use_STL_Exceptions
			/**
			@brief STL Exceptions (Note: right now the library does not STL exceptions but may in the future...):
			*/
			constexpr bool UseSTL_Exceptions = true;
		#else
			/**
			@brief STL Exceptions (Note: right now the library does not STL exceptions but may in the future...):
			*/
			constexpr bool UseSTL_exceptions = false;
		#endif

		/**
		@brief Note: I do not use these as no optimization via inlining has been looked into as of yet...
		*/
		#ifdef VT_Option__Use_Inline_Hinting

			/** @brief Inline specification set to standard inline. */
			#define VT_InlineSpecifier inline

		#elif VT_Option__Use_Forced_Inlining

			#ifdef _WIN32

				/** @brief Inline specification set to _forceinline. (Will force compiler to inline) */
				#define VT_InlineSpecifier __forceinline

			#else

				/** @brief Inline specification set to none. (Does not do influence compiler) */
				#define VT_InlineSpecifier 

			#endif
		#else

			/** @brief Inline specification set to none. (Does not do influence compiler) */
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
		 * @todo Add support for IDynamic?
		 */
		class IDynamicArray   // #TODO: Add support for IDynamic?
		{
		public:
			~IDynamicArray() {};

			virtual Type at(DataSize _index) = NULL;

			virtual Type data() = NULL;

			virtual void push_back() = NULL;

			virtual void resize(DataSize _size) = NULL;

			virtual DataSize size() = NULL;
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
			 */
			using EType = EStructureType;

			/** @brief Keeps track of the structure type enum for a native vulkan struct (If an enum does not exist Max_Enum is used instead) */
			static constexpr EType STypeEnum = TemplateSpecifiedStype;
			
			/** 
			@typdef VkType 
			
			@brief Keeps record of the struct's inherent vulkan equivalent.
			*/
			using VkType = VulkanType;   

			/**
			@brief Does a pointer r-cast to the desired struct type. 
			(Since any wrapped vulkan struct have the same members this is possible)
			*/
			operator VulkanType()
			{
				return *reinterpret_cast<VulkanType*>(this);
			}

			/**
			@brief Does a pointer r-cast to the desired struct type. 
			(Since any wrapped vulkan struct have the same members this is possible)
			*/
			operator const VulkanType& ()
			{
				return *reinterpret_cast<VulkanType*>(this);
			}

			/**
			@brief Does a pointer r-cast to the desired struct type. 
			(Since any wrapped vulkan struct have the same members this is possible)
			*/
			operator VulkanType*()
			{
				return reinterpret_cast<VulkanType*>(this);
			}

			/**
			@brief Does a pointer r-cast to the desired struct type. 
			(Since any wrapped vulkan struct have the same members this is possible)
			*/
			operator const VulkanType*() const
			{
				return reinterpret_cast<const VulkanType*>(this);
			}
		};

	// Used for collapsing macro in visual studio...
	#pragma region VT_VKStruct_Base
		/**
		@brief Macro variant of the template for wrapping a vulkan structure.

		@details this will be used if its decided to implement the library feature of generating the library via macros
		if its decided to support the only one vault implementation without inheritance...
		(If this is supported, it will be a different repo, to avoid obfuscating the source of the main repository.
		*/
		#define VT_VKStruct_Base(_VulkanType, _EStructure) \
			/** \
			* @typedef EType \
			* \
			* @brief Defines the EType enum to the default vkStructureType enum for now.\
			*/ \
			using EType = EStructureType; \
		\
			/** @brief Keeps track of the structure type enum for a native vulkan struct (If an enum does not exist Max_Enum is used instead) */ \
			static constexpr EType STypeEnum = _EStructure; \
		\
			/** \
			@typdef VkType \
		\
			@brief Keeps record of the struct's inherent vulkan equivalent. \
			*/ \
			using VkType = _VulkanType; \
		\
			/** \
			@brief Does a pointer r-cast to the desired struct type. \
			(Since any wrapped vulkan struct have the same members this is possible) \
			*/ \
			operator _VulkanType() \
			{ \
				return *reinterpret_cast<_VulkanType*>(this); \
			} \
		\
			/** \
			@brief Does a pointer r-cast to the desired struct type. \
			(Since any wrapped vulkan struct have the same members this is possible) \
			*/ \
			operator const _VulkanType& () \
			{ \
				return *reinterpret_cast<_VulkanType*>(this); \
			} \
		\
			/** \
			@brief Does a pointer r-cast to the desired struct type. \
			(Since any wrapped vulkan struct have the same members this is possible) \
			*/ \
			operator _VulkanType*() \
			{ \
				return reinterpret_cast<_VulkanType*>(this); \
			} \
		\
			/** \
			@brief Does a pointer r-cast to the desired struct type. \
			(Since any wrapped vulkan struct have the same members this is possible) \
			*/ \
			operator const VulkanType*() const \
			{ \
				return reinterpret_cast<const _VulkanType*>(this); \
			}

	#pragma endregion VKStruct_Base

		template
		<
			typename EnumType             ,
			typename BitmaskRepresentation
		>
		struct Bitmask
		{
		private:
			EnforceConstraint(Bitmaskable<EnumType>::specified, "EnumType must be of Bitmaskable type.");

			using _ThisType = Bitmask<EnumType, BitmaskRepresentation>;

		public:

			using Representation = BitmaskRepresentation;
			using Enum = EnumType;

			Bitmask() : mask(0) {}

			template<typename... BitTypes>
			Bitmask(BitTypes... _bits) : mask(0)
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
			void Remove(const BitType... _bits)
			{
				if (mask <= 0) return;

				mask &= ~(Representation(_bits) | ...);
			}

			template<typename... BitType>
			void Set(const BitType... _bits)
			{
				mask = (Representation(_bits) | ...);
			}

			_ThisType& operator = (const BitmaskRepresentation _mask) { mask = _mask; return *this; }

			operator Representation() const
			{
				return mask;
			}

			bool operator== (const Representation _other)
			{
				return mask == _other;
			}

			bool operator== (const _ThisType& _other)
			{
				return mask == _other.mask;
			}

		private:
			Representation mask;
		};

		/** @} */
	}
}
