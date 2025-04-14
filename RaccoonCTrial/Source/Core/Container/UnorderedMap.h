#pragma once
#include "UnorderedSet.h"
#include "Pair.h"

template<typename Key, typename Value>
class TMap
{
private:
	TSet<TPair<Key, Value>> Pairs;
	size_t IndexCount;

public:
	void Add(Key key, Value value)
	{

	}

	bool Remove(Key key)
	{

	}

	bool Contains(Key key) const
	{

	}

	Value* Find(Key key)
	{

	}

	Value& operator[](const Key& key)
	{

	}

	bool IsEmpty() const
	{

	}

	void Clear()
	{

	}

	int Num() const
	{

	}
};

