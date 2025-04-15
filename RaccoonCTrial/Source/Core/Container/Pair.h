#pragma once

#include "cstdint"
#include "Hash.h"

template<typename KeyType, typename ValueType>
struct TPair
{
	KeyType Key;
	ValueType Value;

	TPair() = default;

	TPair(const KeyType& InKey, const ValueType& InValue)
		: Key(InKey), Value(InValue) {}

	bool operator==(const TPair& Other) const
	{
		return Key == Other.Key;
	}
};

template<typename KeyType, typename ValueType>
struct Hash<TPair<KeyType, ValueType>>
{
	uint32_t operator()(const TPair<KeyType, ValueType>& Pair) const
	{
		return Hash<KeyType>()(Pair.Key);
	}
};
