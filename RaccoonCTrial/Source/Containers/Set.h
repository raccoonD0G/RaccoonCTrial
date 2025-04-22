#pragma once

#include "cstdint"
#include "cstddef"
#include "utility"
#include "cassert"
#include "Hash.h"
#include "iostream"

#include "Core/Collision/CollisionChannel.h"

template<typename T>
class TSet
{
public:
	TSet() : CurrentSize(0), CurrentCapacity(32)
	{
		Data = new Slot[CurrentCapacity];
	}

	TSet(const TSet& Other) : CurrentSize(Other.CurrentSize), CurrentCapacity(Other.CurrentCapacity)
	{
		Data = new Slot[CurrentCapacity];
		for (std::size_t i = 0; i < CurrentCapacity; ++i)
		{
			Data[i] = Other.Data[i];
		}
	}

	TSet(TSet&& Other) noexcept : Data(Other.Data), CurrentSize(Other.CurrentSize), CurrentCapacity(Other.CurrentCapacity)
	{
		Other.Data = nullptr;
		Other.CurrentSize = 0;
		Other.CurrentCapacity = 0;
	}

	~TSet()
	{
		delete[] Data;
	}


	TSet& operator=(const TSet& Other)
	{
		if (this == &Other) return *this;

		delete[] Data;

		CurrentSize = Other.CurrentSize;
		CurrentCapacity = Other.CurrentCapacity;
		Data = new Slot[CurrentCapacity];
		for (std::size_t i = 0; i < CurrentCapacity; ++i)
		{
			Data[i] = Other.Data[i];
		}

		return *this;
	}

	TSet& operator=(TSet&& Other) noexcept
	{
		if (this == &Other) return *this;

		delete[] Data;

		Data = Other.Data;
		CurrentSize = Other.CurrentSize;
		CurrentCapacity = Other.CurrentCapacity;

		Other.Data = nullptr;
		Other.CurrentSize = 0;
		Other.CurrentCapacity = 0;

		return *this;
	}


	bool Add(const T& Item)
	{
		if (Contains(Item))
		{
			return false;
		}

		
		if (LoadFactor() > 0.7f)
		{
			Resize(CurrentCapacity * 2);
		}

		std::size_t HashIndex = Hash<T>()(Item) % CurrentCapacity;

		for (std::size_t i = 0; i < CurrentCapacity; i++)
		{
			std::size_t Index = (HashIndex + i) % CurrentCapacity;
			if (Data[Index].CurrentState == SlotState::Empty || Data[Index].CurrentState == SlotState::Deleted)
			{
				Data[Index].Value = Item;
				Data[Index].CurrentState = SlotState::Occupied;
				CurrentSize++;
				return true;
			}
		}

		assert(false);

		return false;
	}

	T* Find(const T& SearchItem) const
	{
		std::size_t Index = FindIndex(SearchItem);
		if (Index == CurrentCapacity)
		{
			return nullptr;
		}
		else
		{
			return &(Data[Index].Value);
		}
	}

	bool Remove(const T& Item)
	{
		std::size_t Index = FindIndex(Item);
		if (Index == CurrentCapacity)
		{
			return false;
		}

		Data[Index].CurrentState = SlotState::Deleted;
		CurrentSize--;
		return true;
	}

	bool Contains(const T& Item) const
	{
		return FindIndex(Item) != CurrentCapacity;
	}

	inline std::size_t Num() const { return CurrentSize; }

	inline bool IsEmpty() const { return CurrentSize == 0; }

private:
	enum class SlotState : uint8_t
	{
		Empty,
		Occupied,
		Deleted,
	};

	struct Slot
	{
	public:
		T Value;
		SlotState CurrentState;

	public:
		Slot() : CurrentState(SlotState::Empty)
		{
			;
		}
	};

	Slot* Data;
	std::size_t CurrentSize;
	std::size_t CurrentCapacity;

private:
	inline float LoadFactor() const { return static_cast<float>(CurrentSize) / static_cast<float>(CurrentCapacity); }

	void Resize(std::size_t NewCapacity)
	{
		Slot* OldData = Data;
		std::size_t OldCapacity = CurrentCapacity;

		Data = new Slot[NewCapacity];
		CurrentSize = 0;
		CurrentCapacity = NewCapacity;

		for (std::size_t i = 0; i < OldCapacity; ++i)
		{
			if (OldData[i].CurrentState == SlotState::Occupied)
			{
				Add(std::move(OldData[i].Value));
			}
		}

		delete[] OldData;
	}

	std::size_t FindIndex(const T& Item) const
	{
		std::size_t HashIndex = Hash<T>()(Item) % CurrentCapacity;

		for (std::size_t i = 0; i < CurrentCapacity; ++i)
		{
			std::size_t Index = (HashIndex + i) % CurrentCapacity;
			const Slot& SlotRef = Data[Index];

			// std::cout << *Data[Index] << std::endl;
			if (SlotRef.CurrentState == SlotState::Empty)
				return CurrentCapacity;

			if (SlotRef.CurrentState == SlotState::Occupied && SlotRef.Value == Item)
				return Index;
		}

		return CurrentCapacity;
	}
};