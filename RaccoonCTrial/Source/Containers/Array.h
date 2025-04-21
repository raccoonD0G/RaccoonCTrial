#pragma once
#include "cassert"
#include "cstddef"
#include "utility"



template<typename T>
class TArray
{

public:
	TArray() : Data(nullptr), CurrentNum(0), CurrentCapacity(0)
	{
		;
	}

	virtual ~TArray()
	{
		this->Clear();
		::operator delete[](this->Data);
	}

	TArray(const TArray& Other): CurrentNum(Other.CurrentNum), CurrentCapacity(Other.Capacity())
	{
		this->Data = static_cast<T*>(::operator new[](sizeof(T)* Other.Capacity()));
		for (std::size_t i = 0; i < Other.Num(); i++)
		{
			new (&(this->Data[i])) T(Other[i]);
		}
	}

	TArray& operator=(const TArray& Other)
	{
		if (this != &Other)
		{
			this->Clear();
			::operator delete[](this->Data);
			this->Data = nullptr;

			this->CurrentNum = Other.Num();
			this->CurrentCapacity = Other.Capacity();
			this->Data = static_cast<T*>(::operator new[](sizeof(T)* Other.Capacity()));
			for (std::size_t i = 0; i < Other.Num(); i++)
			{
				new (&(this->Data[i])) T(Other[i]);
			}
		}
		return *this;
	}

	TArray(TArray&& Other) : Data(Other.Data), CurrentNum(Other.CurrentNum), CurrentCapacity(Other.Capacity)
	{
		Other.Data = nullptr;
		Other.CurrentNum = 0;
		Other.CurrentCapacity = 0;
	}

	TArray& operator=(TArray&& Other) noexcept
	{
		if (this != &Other)
		{
			this->Clear();
			::operator delete[](this->Data);
			this->Data = nullptr;

			this->Data = Other.Data;
			this->CurrentNum = Other.Num();
			this->CurrentCapacity = Other.CurrentCapacity;

			Other.Data = nullptr;
			Other.CurrentNum = 0;
			Other.CurrentCapacity = 0;
		}
	}

	T& operator[](std::size_t Index)
	{
		assert(Index < this->Num());
		return Data[Index];
	}

	const T& operator[](std::size_t Index) const
	{
		assert(Index < this->Num());
		return Data[Index];
	}

	void Add(const T& NewItem)
	{
		if (CurrentNum + 1 >= this->Capacity())
		{
			Reserve(this->Capacity() != 0 ? this->Capacity() * 2 : 4);
		}
		
		new (&Data[CurrentNum]) T(NewItem);
		
		CurrentNum++;
	}

	void Reserve(std::size_t NewCapacity)
	{
		T* NewData = static_cast<T*>(::operator new[](sizeof(T)* NewCapacity));

		for (std::size_t i = 0; i < this->Num(); i++)
		{
			new (&(NewData[i])) T(std::move(this->Data[i]));
		}

		for (std::size_t i = 0; i < this->Num(); i++)
		{
			this->Data[i].~T();
		}

		::operator delete[](this->Data);

		this->Data = NewData;
		CurrentCapacity = NewCapacity;
	}

	void Clear()
	{
		for (std::size_t i = 0; i < this->Num(); i++)
		{
			this->Data[i].~T();
		}
		this->CurrentNum = 0;
	}

	void RemoveAt(std::size_t Index)
	{
		assert(Index < this->Num());

		Data[Index].~T();

		for (std::size_t i = Index; i < this->Num() - 1; i++)
		{
			new (&Data[i]) T(std::move(Data[i + 1]));
			Data[i + 1].~T();
		}

		CurrentNum--;
	}

	void Remove(const T& Item)
	{
		std::size_t WriteIndex = 0;

		for (std::size_t ReadIndex = 0; ReadIndex < this->Num(); ReadIndex++)
		{
			if (!(Data[ReadIndex] == Item))
			{
				if (WriteIndex != ReadIndex)
				{
					Data[WriteIndex] = std::move(Data[ReadIndex]);
				}
				++WriteIndex;
			}
			else
			{
				Data[ReadIndex].~T();
			}
		}

		for (std::size_t i = WriteIndex; i < this->Num(); ++i)
		{
			Data[i].~T();
		}

		CurrentNum = WriteIndex;
	}

	bool Contains(const T& Item)
	{
		for (std::size_t i = 0; i < this->Num(); i++)
		{
			if (Data[i] == Item)
			{
				return true;
			}
		}
		return false;
	}

	void Resize(std::size_t NewSize)
	{
		if (NewSize < CurrentNum)
		{
			for (std::size_t i = NewSize; i < CurrentNum; ++i)
			{
				Data[i].~T();
			}
		}
		else if (NewSize > CurrentNum)
		{
			if (NewSize > CurrentCapacity)
			{
				Reserve(NewSize);
			}

			for (std::size_t i = CurrentNum; i < NewSize; ++i)
			{
				new (&Data[i]) T();
			}
		}

		CurrentNum = NewSize;
	}


	inline std::size_t Num() const { return CurrentNum; }
	inline std::size_t Capacity() const { return CurrentCapacity; }

	inline T* begin() { return Data; }
	inline T* end() { return Data + CurrentNum; }

	inline const T* begin() const { return Data; }
	inline const T* end() const { return Data + CurrentNum; }

private:
	T* Data;
	std::size_t CurrentNum;
	std::size_t CurrentCapacity;
};
