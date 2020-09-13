/*!
@file VT_Backend.hpp

@brief Vaulted Thermals: Backend

@details Contains implementation related to library backend.
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_APISpecGroups.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"



#ifndef VT_Option__Use_Long_Namespace
namespace VT
#else
namespace VaultedThermals
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

			virtual Type at(WordSize _index) = NULL;

			virtual Type data() = NULL;

			virtual void push_back() = NULL;

			virtual void resize(WordSize _size) = NULL;

			virtual WordSize size() = NULL;
		};

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
		@brief Will be defined with a true_type when enum has the VT_SpecifyBitmaskable enum value.
		*/
		struct IsBitmaskable<Enum, decltype(static_cast<void>(Enum::VT_SpecifyBitmaskable))> : std::is_enum<Enum>
		{};

		template <typename Enum>
		/**
		@brief Returns true if IsBitmaskable is false.
		*/
		constexpr typename std::enable_if<IsBitmaskable<Enum>::value, bool>::
		type Bitmaskable() noexcept
		{
			return static_cast<WordSize>(Enum::VT_SpecifyBitmaskable) > WordSize(0) ? true : false;
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

		template
		<
			typename EnumType             ,
			typename BitmaskRepresentation
		>
		class Bitmask
		{
		private:
			static_assert(Bitmaskable<EnumType>(), "EnumType must be of Bitmaskable type.");

			using _ThisType = Bitmask<EnumType, BitmaskRepresentation>;

		public:

			using Enum           = EnumType             ;
			using Representation = BitmaskRepresentation;

			Bitmask() : mask(0) {}

			Bitmask(Representation _mask) : mask(_mask)
			{}

			template<typename... BitTypes>
			Bitmask(const BitTypes... _bits) : mask(0)
			{
				mask = (Representation(_bits) | ...);
			}

			template<typename... BitType>
			void Add(const BitType... _bits)
			{
				mask |= (Representation(_bits) | ...);
			}

			template<typename... BitType>
			bool CheckForEither(const BitType... _bits) const
			{
				return (mask & (Representation(_bits) | ...)) != 0;
			}

			template<typename... BitType>
			void Clear(const BitType... _bits)
			{
				if (mask <= 0) return;

				mask &= ~(Representation(_bits) | ...);
			}

			bool HasFlag(const Enum _bit) const
			{
				return (mask & Representation(_bit)) == Representation(_bit);
			}

			template<typename... BitType>
			bool HasExactly(const BitType... _bits) const
			{
				return (mask & (Representation(_bits) | ...)) == mask;
			}

			bool HasAnyFlag() const { return mask != 0 ? true : false; }
			bool IsZero    () const { return mask == 0 ? true : false; }	

			void Reset() { mask = 0; }

			template<typename... BitType>
			void Set(const BitType... _bits)
			{
				mask = (Representation(_bits) | ...);
			}

			template<typename... BitType>
			void Toggle(const BitType... _bits)
			{
				mask ^= (Representation(_bits) | ...);
			}

			operator Representation() const { return mask; }

			_ThisType& operator= (const Representation _mask ) { mask = _mask      ; return *this; }
			_ThisType& operator= (const _ThisType      _other) { mask = _other.mask; return *this; }

			_ThisType& operator&= (const Representation _mask ) { mask &= mask       ; return *this; }
			_ThisType& operator&= (const _ThisType      _other) { mask &= _other.mask; return *this; }

			_ThisType& operator|= (const Representation _mask ) { mask |= mask       ; return *this; }
			_ThisType& operator|= (const _ThisType      _other) { mask |= _other.mask; return *this; }	

			_ThisType& operator^= (const Representation _mask ) { mask ^= mask       ; return *this; }
			_ThisType& operator^= (const _ThisType      _other) { mask ^= _other.mask; return *this; }	

			_ThisType& operator<<= (const Representation _mask ) { mask <<= mask       ; return *this; }
			_ThisType& operator>>= (const _ThisType      _other) { mask >>= _other.mask; return *this; }	

			_ThisType operator~ () const { return ~mask; }

			Representation operator& (const Representation _other) const { return mask & _other     ; }
			_ThisType      operator& (const _ThisType      _other) const { return mask & _other.mask; }

			Representation operator| (const Representation _other) const { return mask | _other     ; }
			_ThisType      operator| (const _ThisType      _other) const { return mask | _other.mask; }

			Representation operator^ (const Representation _other) const { return mask ^ _other     ; }
			_ThisType      operator^ (const _ThisType      _other) const { return mask ^ _other.mask; }

			Representation operator<< (const Representation _other) const { return mask << _other     ; }
			_ThisType      operator>> (const _ThisType      _other) const { return mask >> _other.mask; }

			bool operator== (const Representation _other) const { return mask == _other     ; }
			bool operator== (const _ThisType      _other) const { return mask == _other.mask; }

			bool operator!= (const Representation _other) const { return mask != _other     ; }
			bool operator!= (const _ThisType      _other) const { return mask != _other.mask; }

		protected:

			Representation mask;
		};

		/** @} */
	}
}
