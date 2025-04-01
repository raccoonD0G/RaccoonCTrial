#pragma once

using namespace std;

template<typename T>
class UniquePtr
{
private:
	T* Pointer;

public:
	explicit UniquePtr()
	{
		Pointer = nullptr;
	}

	explicit UniquePtr(UniquePtr&& Other)
	{
		Pointer = Other.Pointer;
		Other.Pointer = nullptr;
	}

	UniquePtr& operator=(UniquePtr&& Other)
	{
		if (this != &Other)
		{
			delete Pointer;
			this->Pointer = Other.Pointer;
			Other.Pointer = nullptr;
		}
		return *this;
	}

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	~UniquePtr()
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

