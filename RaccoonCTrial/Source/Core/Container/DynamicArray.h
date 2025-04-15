#pragma once
#include "Core/Object.h"
#include "cstddef"
#include "type_traits"
#include "stdexcept"

template<typename T>
class TArray : public UObject
{
private:
	T* ArrPtr;

	std::size_t Size;
	std::size_t MemSize;

public:
	TArray()
	{
		ArrPtr = new T[2];
		Size = 0;
		MemSize = 2;
	}

	~TArray()
	{
		this->Clear();
	}

	inline std::size_t Num() const { return Size; }
	inline std::size_t Capacity() const { return MemSize; }

	void Add(const T& NewIndex)
	{
		if (Size >= MemSize)
		{
			Reserve(MemSize * 2);
		}

		ArrPtr[Size] = NewIndex;
		Size++;
	}

	void Remove(T InIndex)
	{
		for (std::size_t i = 0; i < Size; ++i)
		{
			if (ArrPtr[i] == InIndex)
			{
				for (std::size_t j = i; j < Size - 1; ++j)
				{
					ArrPtr[j] = ArrPtr[j + 1];
				}
				--Size;
				return;
			}
		}
	}

	bool Contains(T InIndex) const
	{
		for (std::size_t i = 0; i < Size; ++i)
		{
			if (ArrPtr[i] == InIndex)
			{
				return true;
			}
		}
		return false;
	}


	void Reserve(std::size_t NewMemSize)
	{
		if (NewMemSize <= MemSize)
		{
			return;
		}

		T* NewArrPtr = new T[NewMemSize];

		for (std::size_t i = 0; i < Size; i++)
		{
			NewArrPtr[i] = ArrPtr[i];
		}

		delete[] ArrPtr;
		ArrPtr = NewArrPtr;

		MemSize = NewMemSize;
	}


	void Resize(std::size_t NewSize)
	{
		Reserve(NewSize);
		for (int i = Size; i < NewSize; i++)
		{
			ArrPtr[i] = T();
			Size++;
		}
	}

	T& operator[](const std::size_t& Index)
	{
		if (Index < Size)
		{
			return ArrPtr[Index];
		}
		else
		{
			throw std::out_of_range("Index out of bounds");
		}
	}

	const T& operator[](const std::size_t& Index) const
	{
		if (Index < Size)
		{
			return ArrPtr[Index];
		}
		else
		{
			throw std::out_of_range("Index out of bounds");
		}
	}

	TArray(const TArray& Other)
	{
		Size = Other.Size;
		MemSize = Other.MemSize;
		ArrPtr = new T[MemSize];

		for (std::size_t i = 0; i < Size; i++)
		{
			ArrPtr[i] = Other.ArrPtr[i];
		}
	}


	TArray& operator=(const TArray& Other)
	{
		if (this == &Other)
		{
			return *this;
		}

		delete[] ArrPtr;

		Size = Other.Size;
		MemSize = Other.MemSize;
		ArrPtr = new T[MemSize];

		for (std::size_t i = 0; i < Size; i++)
		{
			ArrPtr[i] = Other.ArrPtr[i];
		}

		return *this;
	}

	bool IsEmpty() const
	{
		return Size == 0;
	}

	void Clear()
	{
		if (!this->IsEmpty())
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
			Size = 0;
			MemSize = 0;
		}
	}
};
