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
		SetIndex<T>** BeforeCheckingIndex = nullptr;

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
				BeforeCheckingIndex = &(CheckingIndex->NextIndex);
				CheckingIndex = CheckingIndex->NextIndex;
			}

			if (BeforeCheckingIndex != nullptr)
			{
				*BeforeCheckingIndex = CheckingIndex->NextIndex;
				delete CheckingIndex;
			}
			else
			{
				delete CheckingIndex;
				Container[HashNum] = nullptr;
			}
			
		}
	}

	bool Contain(T InIndex)
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

	T GetRandomIndex() const
	{
		srand(time(nullptr));

		if (IsEmpty())
		{
			return NULL;
		}

		while (true)
		{
			int BucketIndex = rand() % BucketSize;
			SetIndex<T>* Node = Container[BucketIndex];

			if (Node != nullptr)
			{
				int Count = 0;
				SetIndex<T>* Temp = Node;
				while (Temp)
				{
					++Count;
					Temp = Temp->NextIndex;
				}

				int RandomIndex = rand() % Count;

				for (int i = 0; i < RandomIndex; ++i)
				{
					Node = Node->NextIndex;
				}

				return Node->Index;
			}
		}
	}

	int Hash(const T& key) const
	{
		return static_cast<int>(std::hash<T>{}(key) % BucketSize);
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

