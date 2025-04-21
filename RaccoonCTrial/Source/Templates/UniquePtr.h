#pragma once

using namespace std;

template<typename T>
class TUniquePtr
{

public:
	TUniquePtr()
	{
		Pointer = nullptr;
	}

	TUniquePtr(const TUniquePtr&) = delete;

	TUniquePtr(TUniquePtr&& Other)
	{
		Pointer = Other.Pointer;
		Other.Pointer = nullptr;
	}

	~TUniquePtr()
	{
		delete Pointer;
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

	TUniquePtr& operator=(const TUniquePtr&) = delete;

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

private:
	T* Pointer;
};

