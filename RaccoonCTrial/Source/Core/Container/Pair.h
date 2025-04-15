#pragma once

#include "cstdint"
#include "Hash.h"

/*
* TODO: 인터넷 보고 배낌, 다시 공부 할것, Pair 는 원래 Key 값 기준으로만 비교하는 게 맞는지?
*/
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
