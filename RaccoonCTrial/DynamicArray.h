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
	}

	inline size_t GetSize() { return Size; }
	inline size_t GetMemSize() { return MemSize; }
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
		T* Tmp = new T[Size];

		for (int i = 0; i < Size; i++)
		{
			Tmp[i] = ArrPtr[i];
		}

		delete[] ArrPtr;
		ArrPtr = nullptr;

		ArrPtr = new T[NewMemSize];

		for (int i = 0; i < Size; i++)
		{
			ArrPtr[i] = Tmp[i];
		}

		MemSize = NewMemSize;

		delete[] Tmp;
		Tmp = nullptr;
	}

	void Resize(size_t NewSize)
	{
		Reserve(NewSize);
		for (int i = Size; i < NewSize; i++)
		{
			ArrPtr[i] = new T();
		}
	}

	T& operator[](const unsigned int& Index)
	{
		return ArrPtr[Index];
	}

};
