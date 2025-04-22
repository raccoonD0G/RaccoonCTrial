#pragma once

#include "utility"

#include "Core/Collision/CollisionChannel.h"

template<typename KeyType, typename ValueType>
struct TPair
{
	KeyType Key;
	ValueType Value;

	TPair() : Key(KeyType()), Value(ValueType())
	{
		;
	}

	explicit TPair(const KeyType& InKey, const ValueType& InValue) : Key(InKey), Value(InValue)
	{
		;
	}

	~TPair()
	{
		;
	}

	TPair(const TPair& Other) = default;
	TPair(TPair&& Other) noexcept = default;

	TPair& operator=(const TPair& Other)
	{
		this->Key = Other.Key;
		this->Value = Other.Value;

		return *this;
	}

	TPair(KeyType&& InKey, ValueType&& InValue) : Key(std::move(InKey)), Value(std::move(InValue))
	{
		;
	}

	TPair& operator=(TPair&& Other) noexcept
	{
		Key = std::move(Other.Key);
		Value = std::move(Other.Value);

		return *this;
	}


	bool operator==(const TPair& Other) const
	{
		return Key == Other.Key;
	}
};