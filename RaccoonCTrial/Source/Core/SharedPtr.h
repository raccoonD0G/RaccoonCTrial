#pragma once

template<typename T>
class TSharedPtr
{

public:
	TSharedPtr()
	{
		Pointer = nullptr;
		RefCount = nullptr;
	}

	explicit TSharedPtr(T* NewPointer)
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

private:
	T* Pointer;

// Count Reference Section
public:
	inline int GetRefCount() const { return *RefCount; }

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
};