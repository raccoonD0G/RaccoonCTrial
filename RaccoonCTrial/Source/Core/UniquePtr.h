#pragma once

using namespace std;

template<typename T>
class TUniquePtr
{
private:
	T* Pointer;

public:
	explicit TUniquePtr()
	{
		Pointer = nullptr;
	}

	explicit TUniquePtr(TUniquePtr&& Other)
	{
		Pointer = Other.Pointer;
		Other.Pointer = nullptr;
	}

	TUniquePtr& operator=(TUniquePtr&& Other)
	{
		if (this != &Other)
		{
			delete Pointer;
			this->Pointer = Other.Pointer;
			Other.Pointer = nullptr;
		}
		return *this;
	}

	TUniquePtr(const TUniquePtr&) = delete;
	TUniquePtr& operator=(const TUniquePtr&) = delete;

	~TUniquePtr()
	{
		delete Pointer;
	}

	T* operator->() const
	{
		return Pointer;
	}

	T& operator*() const
	{
		return *Pointer;
	}
	
	T* Get() const
	{
		return Pointer;
	}

	void Reset(T* NewPointer = nullptr)
	{
		if (Pointer)
		{
			delete Pointer;
		}
		Pointer = NewPointer;
	}
};

