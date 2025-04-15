#pragma once

#include "Pair.h"
#include "UnorderedSet.h"

template<typename KeyType, typename ValueType>
class TMap
{
private:
	using PairType = TPair<KeyType, ValueType>;
	TSet<PairType> Pairs;

public:
	void Add(const KeyType& InKey, const ValueType& InValue)
	{
		Remove(InKey);
		Pairs.Add(PairType(InKey, InValue));
	}

	bool Remove(const KeyType& InKey)
	{
		return Pairs.Remove(PairType(InKey, ValueType()));
	}

	bool Contains(const KeyType& InKey) const
	{
		return Pairs.Contains(PairType(InKey, ValueType()));
	}

	ValueType* Find(const KeyType& InKey)
	{
		PairType* Found = Pairs.Find(PairType(InKey, ValueType()));
		return Found ? &Found->Value : nullptr;
	}

	const ValueType* Find(const KeyType& InKey) const
	{
		const PairType* Found = Pairs.Find(PairType(InKey, ValueType()));
		return Found ? &Found->Value : nullptr;
	}

	ValueType& operator[](const KeyType& InKey)
	{
		if (!Contains(InKey))
		{
			Add(InKey, ValueType());
		}
		return *Find(InKey);
	}

	bool IsEmpty() const
	{
		return Pairs.IsEmpty();
	}

	void Clear()
	{
		Pairs.Clear();
	}

	int Num() const
	{
		return Pairs.Num();
	}
};
