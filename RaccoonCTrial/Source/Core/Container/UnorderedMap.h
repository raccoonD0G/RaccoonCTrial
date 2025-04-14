#pragma once
#include "UnorderedSet.h"
#include "Pair.h"

template<typename Key, typename Value>
class TMap
{
private:
	TSet<TPair<Key, Value>> Pairs;

public:
	void Add(Key InKey, Value InValue)
	{
		this->Remove(InKey);
		this->Pairs.Add(TPair<Key, Value>(InKey, InValue));
	}

	bool Remove(Key InKey)
	{
		return this->Pairs.Remove(TPair<Key, Value>(InKey, Value()));
	}

	bool Contains(Key InKey) const
	{
		return this->Pairs.Contains(TPair<Key, Value>(InKey, Value()));
	}

	Value* Find(const Key& InKey)
	{
		return &(this->Pairs.Find(InKey)->CurrentValue);
	}

	Value& operator[](const Key& InKeykey)
	{
		if (!this->Pairs.Contains(InKeykey))
		{
			this->Add(TPair<Key, Value>(InKeykey, Value()));
		}

		return *(this->Pairs.Find(InKeykey));
	}

	bool IsEmpty() const
	{
		return this->Pairs.IsEmpty();
	}

	void Clear()
	{
		return this->Pairs.Clear();
	}

	int Num() const
	{
		return this->Pairs.Num();
	}
};

