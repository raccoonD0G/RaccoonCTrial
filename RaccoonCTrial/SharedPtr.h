#pragma once

using namespace std;

template<typename T>
class SharedPtr
{
private:
	T* Pointer;

public:
	explicit SharedPtr()
	{
		Pointer = nullptr;
		RefCount = nullptr;
	}

	SharedPtr(T* NewPointer)
	{
		this->Pointer = NewPointer;
		IncreaseRefCount();
	}

	SharedPtr(const SharedPtr& Other)
	{
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;
		IncreaseRefCount();
	}

	SharedPtr& operator=(const SharedPtr& Other)
	{
		this->DecreaseRefCount();
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;
		this->IncreaseRefCount();

		return *this;
	}

	SharedPtr& operator=(SharedPtr&& Other) noexcept
	{
		this->DecreaseRefCount();
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;

		Other.Pointer = nullptr;
		Other.RefCount = nullptr;
		return *this;
	}

	SharedPtr(SharedPtr&& Other)
	{
		this->Pointer = Other.Pointer;
		this->RefCount = Other.RefCount;

		Other.Pointer = nullptr;
		Other.RefCount = nullptr;
	}

	~SharedPtr()
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