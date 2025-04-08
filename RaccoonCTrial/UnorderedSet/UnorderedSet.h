#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>  

using namespace std;

template<typename T>
struct SetIndex
{
public:
	T Index;
	SetIndex<T>* NextIndex;

public:
	SetIndex(T NewIndex) : Index(NewIndex), NextIndex(nullptr) { ; } ;
};


template<typename T>
class UnorderedSet
{
public:
	UnorderedSet() : BucketSize(32)
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

	void Remove(T NewIndex)
	{
		if (this->Contain(NewIndex) == false)
		{
			return;
		}

		
		int HashNum = Hash(NewIndex) % BucketSize;
		SetIndex<T>* CheckingIndex = Container[HashNum];
		SetIndex<T>* BeforeCheckingIndex = nullptr;

		// No index in vector.
		if (CheckingIndex == nullptr)
		{
			return;
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
		}
	}

	bool Contain(T InIndex) const
	{
		SetIndex<T>* NewSetIndex = new SetIndex<T>(InIndex);
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

