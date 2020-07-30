#pragma once



#include <type_traits>



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
			return mask & Representation(_bit);
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




