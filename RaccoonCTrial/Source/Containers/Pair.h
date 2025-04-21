#pragma once

#include "utility"

template<typename KeyType, typename ValueType>
struct TPair
{
	KeyType Key;
	ValueType Value;

	TPair()
	{
		;
	}

	~TPair()
	{
		;
	}

	TPair(const KeyType& InKey, const ValueType& InValue) : Key(InKey), Value(InValue)
	{
		;
	}

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

	TPair& operator=(const TPair&& Other) noexcept
	{
		this->Key = Other.Key;
		this->Value = Other.Value;

		return *this;
	}

	bool operator==(const TPair& Other) const
	{
		return Key == Other.Key;
	}
};