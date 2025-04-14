#pragma once

using namespace std;

template<typename T>
class TSharedPtr
{
private:
	T* Pointer;

public:
	explicit TSharedPtr()
	{
		Pointer = nullptr;
		RefCount = nullptr;
	}

	TSharedPtr(T* NewPointer)
	{
		this->Pointer = NewPointer;
		IncreaseRefCount();
	}

	TSharedPtr(const TSharedPtr& Other)
	{
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;
		IncreaseRefCount();
	}

	TSharedPtr& operator=(const TSharedPtr& Other)
	{
		this->DecreaseRefCount();
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;
		this->IncreaseRefCount();

		return *this;
	}

	TSharedPtr& operator=(TSharedPtr&& Other) noexcept
	{
		this->DecreaseRefCount();
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;

		Other.Pointer = nullptr;
		Other.RefCount = nullptr;
		return *this;
	}

	TSharedPtr(TSharedPtr&& Other)
	{
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;

		Other.Pointer = nullptr;
		Other.RefCount = nullptr;
	}

	~TSharedPtr()
	{
		DecreaseRefCount();
	}

// Count Reference Section
private:
	int* RefCount;

	void DecreaseRefCount()
	{
		if (RefCount != nullptr)
		{
			(*RefCount)--;
			if (*RefCount == 0)
			{
				delete RefCount;
				delete Pointer;
			}
		}
	}

	void IncreaseRefCount()
	{
		if (RefCount != nullptr)
		{
			(*RefCount)++;
		}
		else
		{
			RefCount = new int(1);
		}
	}

public:
	inline int GetRefCount() const { return *RefCount; }

};