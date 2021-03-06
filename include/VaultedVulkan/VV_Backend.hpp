/*!
@file VV_Backend.hpp

@brief Vaulted Vulkan: Backend

@details Contains implementation related to library backend.
*/



#pragma once



// VV
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
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
			constexpr bool UseSTL_Exceptions = false;
		#endif

		/**
		@brief Note: I do not use these as no optimization via inlining has been looked into as of yet...
		*/
		#ifdef VV_Option__Use_Inline_Hinting

			/** @brief Inline specification set to standard inline. */
			#define VT_InlineSpecifier inline

		#elif VV_Option__Use_Forced_Inlining

			#ifdef _WIN32

				/** @brief Inline specification set to _forceinline. (Will force compiler to inline) */
				#define VV_InlineSpecifier __forceinline

			#else

				/** @brief Inline specification set to none. (Does not do influence compiler) */
				#define VV_InlineSpecifier 

			#endif
		#else

			/** @brief Inline specification set to none. (Does not do influence compiler) */
			#define VV_InlineSpecifier 

		#endif

		/** @brief Determines whether to return an result code for a function based on if STL exceptions are enabled. */
		using ShouldUse_EResult = typename std::conditional<V0::UseSTL_Exceptions, void, EResult>::type;

		/**
		@brief Used when creating fake VulkanAPI structures for platform abstraction uses.
		*/
		struct DummyBase
		{};

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
			operator const VulkanType& () const
			{
				return *reinterpret_cast<const VulkanType*>(this);
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

		template<typename Enum, typename = void>
		/**
		@brief Used when the enum does not meet the criteria for bitmaskable.
		*/
		struct IsBitmaskable : std::false_type
		{};

		template<typename Enum>
		/**
		@brief Will be defined with a true_type when enum has the VV_SpecifyBitmaskable enum value.
		*/
		struct IsBitmaskable<Enum, decltype(static_cast<void>(Enum::VV_SpecifyBitmaskable))> : std::is_enum<Enum>
		{};

		template <typename Enum>
		/**
		@brief Returns true if IsBitmaskable is false.
		*/
		constexpr typename std::enable_if<IsBitmaskable<Enum>::value, bool>::
		type Bitmaskable() noexcept
		{
			return static_cast<std::size_t>(Enum::VV_SpecifyBitmaskable) > std::size_t(0) ? true : false;
		}

		template <typename Enum> 
		/**
		@brief Returns false if bitmaskable is false (Default case).
		*/
		constexpr typename std::enable_if<!IsBitmaskable<Enum>::value, bool>::
		type Bitmaskable() noexcept
		{
			return false;
		}

		template<typename EnumType, typename BitmaskRepresentation>
		/**
		A wrapper object for bitmasks that allows for typesafe bitmask operations.
		*/
		class Bitfield
		{
		private:
			static_assert(Bitmaskable<EnumType>(), "EnumType must be of Bitmaskable type.");

			using _ThisType = Bitfield<EnumType, BitmaskRepresentation>;

		public:

			using Enum           = EnumType             ;
			using Representation = BitmaskRepresentation;

			Bitfield() : bitfield(0) {}

			Bitfield(Representation _mask) : bitfield(_mask)
			{}

			template<typename... BitTypes>
			Bitfield(const BitTypes... _bits) : bitfield(0)
			{
				bitfield = (Representation(_bits) | ...);
			}

			template<typename... BitType>
			void Add(const BitType... _bits)
			{
				bitfield |= (Representation(_bits) | ...);
			}

			template<typename... BitType>
			bool CheckForEither(const BitType... _bits) const
			{
				return (bitfield & (Representation(_bits) | ...)) != 0;
			}

			template<typename... BitType>
			void Clear(const BitType... _bits)
			{
				if (bitfield <= 0) return;

				bitfield &= ~(Representation(_bits) | ...);
			}

			bool HasFlag(const Enum _bit) const
			{
				return (bitfield & Representation(_bit)) == Representation(_bit);
			}

			template<typename... BitType>
			bool HasExactly(const BitType... _bits) const
			{
				return (bitfield & (Representation(_bits) | ...)) == bitfield;
			}

			bool HasAnyFlag() const { return bitfield != 0 ? true : false; }
			bool IsZero    () const { return bitfield == 0 ? true : false; }	

			void Reset() { bitfield = 0; }

			template<typename... BitType>
			void Set(const BitType... _bits)
			{
				bitfield = (Representation(_bits) | ...);
			}

			template<typename... BitType>
			void Toggle(const BitType... _bits)
			{
				bitfield ^= (Representation(_bits) | ...);
			}

			operator Representation() const { return bitfield; }

			_ThisType& operator= (const Representation _mask ) { bitfield = _mask      ; return *this; }
			_ThisType& operator= (const _ThisType      _other) { bitfield = _other.bitfield; return *this; }

			_ThisType& operator&= (const Representation _mask ) { bitfield &= bitfield       ; return *this; }
			_ThisType& operator&= (const _ThisType      _other) { bitfield &= _other.bitfield; return *this; }

			_ThisType& operator|= (const Representation _mask ) { bitfield |= bitfield       ; return *this; }
			_ThisType& operator|= (const _ThisType      _other) { bitfield |= _other.bitfield; return *this; }	

			_ThisType& operator^= (const Representation _mask ) { bitfield ^= bitfield       ; return *this; }
			_ThisType& operator^= (const _ThisType      _other) { bitfield ^= _other.bitfield; return *this; }	

			_ThisType& operator<<= (const Representation _mask ) { bitfield <<= bitfield       ; return *this; }
			_ThisType& operator>>= (const _ThisType      _other) { bitfield >>= _other.bitfield; return *this; }	

			_ThisType operator~ () const { return ~bitfield; }

			Representation operator& (const Representation _other) const { return bitfield & _other     ; }
			_ThisType      operator& (const _ThisType      _other) const { return bitfield & _other.bitfield; }

			Representation operator| (const Representation _other) const { return bitfield | _other     ; }
			_ThisType      operator| (const _ThisType      _other) const { return bitfield | _other.bitfield; }

			Representation operator^ (const Representation _other) const { return bitfield ^ _other     ; }
			_ThisType      operator^ (const _ThisType      _other) const { return bitfield ^ _other.bitfield; }

			Representation operator<< (const Representation _other) const { return bitfield << _other     ; }
			_ThisType      operator>> (const _ThisType      _other) const { return bitfield >> _other.bitfield; }

			bool operator== (const Representation _other) const { return bitfield == _other     ; }
			bool operator== (const _ThisType      _other) const { return bitfield == _other.bitfield; }

			bool operator!= (const Representation _other) const { return bitfield != _other     ; }
			bool operator!= (const _ThisType      _other) const { return bitfield != _other.bitfield; }

		protected:

			Representation bitfield;
		};

		/** @} */
	}
}
