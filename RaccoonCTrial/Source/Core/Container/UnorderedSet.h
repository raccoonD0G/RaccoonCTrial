#pragma once

#include "vector"
#include "cstdlib"
#include "ctime"
#include "Core/Object.h"

using namespace std;

template<typename T>
struct SetIndex
{
public:
	SetIndex(T NewIndex) : Index(NewIndex), NextIndex(nullptr) { ; };

public:
	T Index;
	SetIndex<T>* NextIndex;
};


template<typename T>
class TSet : public UObject
{
public:
	TSet() : BucketSize(32)
	{
		Container.resize(BucketSize);
	}

	void Add(T NewIndex)
	{
		if (this->Contain(NewIndex))
		{
			return;
		}

		int HashNum = Hash(NewIndex) % BucketSize;
		SetIndex<T>* CheckingIndex = Container[HashNum];

		if (CheckingIndex == nullptr)
		{
			Container[HashNum] = new SetIndex<T>(NewIndex);
			return;
		}
		else
		{
			while (CheckingIndex->NextIndex != nullptr)
			{
				CheckingIndex = CheckingIndex->NextIndex;
			}

			CheckingIndex->NextIndex = new SetIndex<T>(NewIndex);
			return;
		}
	}

	bool Remove(T NewIndex)
	{
		if (this->Contain(NewIndex) == false)
		{
			return false;
		}

		
		int HashNum = Hash(NewIndex) % BucketSize;
		SetIndex<T>* CheckingIndex = Container[HashNum];
		SetIndex<T>* BeforeCheckingIndex = nullptr;

		// No index in vector.
		if (CheckingIndex == nullptr)
		{
			return false;
		}
		else
		{
			
			while (CheckingIndex->NextIndex != nullptr)
			{
				if (CheckingIndex->Index == NewIndex)
				{
					break;
				}
				BeforeCheckingIndex = CheckingIndex;
				CheckingIndex = CheckingIndex->NextIndex;
			}

			// First index is what we find.
			if (BeforeCheckingIndex == nullptr)
			{
				delete CheckingIndex;
				Container[HashNum] = nullptr;
			}
			else
			{
				BeforeCheckingIndex->NextIndex = CheckingIndex->NextIndex;
				delete CheckingIndex;
			}

			return true;
		}
	}

	bool Contain(T InIndex) const
	{
		SetIndex<T>* CheckingIndex = Container[Hash(InIndex)];
		while (CheckingIndex != nullptr)
		{
			if (CheckingIndex->Index == InIndex)
			{
				return true;
			}
			CheckingIndex = CheckingIndex->NextIndex;
		}

		return false;
	}

	T* Find(const T& InIndex)
	{
		if (!this->Contain(InIndex))
		{
			return nullptr;
		}
		
		int HashNum = Hash(InIndex) % BucketSize;
		SetIndex<T>* CheckingIndex = Container[HashNum];

		while (CheckingIndex != nullptr)
		{
			if (CheckingIndex->Index == InIndex)
			{
				return &(CheckingIndex->Index);
			}
			CheckingIndex = CheckingIndex->NextIndex;
		}

		return nullptr;
	}

	int Hash(const T& key) const
	{
		return static_cast<int>(hash<T>{}(key) % BucketSize);
	}

	bool IsEmpty() const
	{
		for (const auto& bucket : Container)
		{
			if (bucket != nullptr) return false;
		}
		return true;
	}

private:
	vector<SetIndex<T>*> Container;
	int BucketSize;
};

