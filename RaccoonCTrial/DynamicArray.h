#pragma once
template<typename T>
class DynamicArray
{
private:
	T* ArrPtr;

	size_t Size;
	size_t MemSize;

public:
	DynamicArray()
	{
		ArrPtr = new T[2];
		Size = 0;
		MemSize = 2;
	}

	~DynamicArray()
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
		
		MemSize = NewMemSize;
	}

	void Resize(size_t NewSize)
	{
		Reserve(NewSize);
		for (int i = Size; i < NewSize; i++)
		{
			ArrPtr[i] = T();
		}
	}

	T& operator[](const unsigned int& Index)
	{
		return ArrPtr[Index];
	}

	DynamicArray(const DynamicArray& Other)
	{
		Size = Other.Size;
		MemSize = Other.MemSize;
		ArrPtr = new T[MemSize];

		for (size_t i = 0; i < Size; i++)
		{
			ArrPtr[i] = Other.ArrPtr[i];
		}
	}

	DynamicArray& operator=(const DynamicArray& Other)
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
