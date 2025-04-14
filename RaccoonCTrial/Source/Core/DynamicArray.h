#pragma once
#include "Object.h"

template<typename T>
class TArray : public UObject
{
private:
	T* ArrPtr;

	size_t Size;
	size_t MemSize;

public:
	TArray()
	{
		ArrPtr = new T[2];
		Size = 0;
		MemSize = 2;
	}

	~TArray()
	{
		delete[] ArrPtr;
		ArrPtr = nullptr;
	}

	inline const T& GetByIndex(int Index) const { return ArrPtr[Index]; }

	inline size_t Num() const { return Size; }
	inline size_t Capacity() const { return MemSize; }

	void Add(T NewIndex)
	{
		if (Size >= MemSize)
		{
			MemSize *= 2;
			Reserve(MemSize);
		}

		ArrPtr[Size] = NewIndex;
		Size++;
	}

	void Remove(T InIndex)
	{
		for (size_t i = 0; i < Size; ++i)
		{
			if (ArrPtr[i] == InIndex)
			{
				for (size_t j = i; j < Size - 1; ++j)
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
		for (size_t i = 0; i < Size; ++i)
		{
			if (ArrPtr[i] == InIndex)
				return true;
		}
		return false;
	}


	void Reserve(size_t NewMemSize)
	{
		if (NewMemSize <= MemSize)
			return;

		T* NewArrPtr = new T[NewMemSize];

		for (size_t i = 0; i < Size; i++)
		{
			NewArrPtr[i] = ArrPtr[i];
		}

		delete[] ArrPtr;
		ArrPtr = NewArrPtr;

		MemSize = NewMemSize;
	}


	void Resize(size_t NewSize)
	{
		Reserve(NewSize);
		for (int i = Size; i < NewSize; i++)
		{
			ArrPtr[i] = T();
			Size++;
		}
	}

	T& operator[](const unsigned int& Index)
	{
		if (Index < Size)
		{
			return ArrPtr[Index];
		}
	}

	TArray(const TArray& Other)
	{
		Size = Other.Size;
		MemSize = Other.MemSize;
		ArrPtr = new T[MemSize];

		for (size_t i = 0; i < Size; i++)
		{
			ArrPtr[i] = Other.ArrPtr[i];
		}
	}

	TArray& operator=(const TArray& Other)
	{
		if (this == &Other)
			return *this;

		delete[] ArrPtr;

		Size = Other.Size;
		MemSize = Other.MemSize;
		ArrPtr = new T[MemSize];

		for (size_t i = 0; i < Size; i++)
		{
			ArrPtr[i] = Other.ArrPtr[i];
		}

		return *this;
	}
};
