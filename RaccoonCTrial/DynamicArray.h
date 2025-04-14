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

	inline size_t GetSize() const { return Size; }
	inline size_t GetMemSize() const { return MemSize; }
	void PushBack(T NewIndex)
	{
		if (Size >= MemSize)
		{
			MemSize *= 2;
			Reserve(MemSize);
		}

		ArrPtr[Size] = NewIndex;
		Size++;
	}

	void Reserve(size_t NewMemSize)
	{
		T* NewArrPtr = new T[NewMemSize];

		for (int i = 0; i < Size; i++)
		{
			NewArrPtr[i] = ArrPtr[i];
		}

		delete[] ArrPtr;
		ArrPtr = nullptr;

		ArrPtr = NewArrPtr;
		
		MemSize = MemSize;
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
		return ArrPtr[Index];
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
