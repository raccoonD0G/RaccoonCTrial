#pragma once

#include "vector"
#include "cstdlib"
#include "ctime"
#include "functional"
#include "Core/Object.h"
#include "Core/Container/DynamicArray.h"
#include "Hash.h"

template<typename T>
struct SetIndex
{
public:
    SetIndex(T NewIndex) : Index(NewIndex), NextIndex(nullptr) { }

public:
    T Index;
    SetIndex<T>* NextIndex;
};

template<typename T>
class TSet : public UObject
{
public:
    TSet() : BucketSize(32)
    {
        Container.Resize(BucketSize);
    }

    void Add(T NewIndex)
    {
        if (this->Contains(NewIndex))
            return;

        int HashNum = Hash<T>()(NewIndex) % BucketSize;
        SetIndex<T>* CheckingIndex = Container[HashNum];

        if (CheckingIndex == nullptr)
        {
            Container[HashNum] = new SetIndex<T>(NewIndex);
            return;
        }
        else
        {
            while (CheckingIndex->NextIndex != nullptr)
            {
                CheckingIndex = CheckingIndex->NextIndex;
            }

            CheckingIndex->NextIndex = new SetIndex<T>(NewIndex);
            return;
        }
    }

    bool Remove(T NewIndex)
    {
        if (!this->Contains(NewIndex))
            return false;

        int HashNum = Hash<T>()(NewIndex) % BucketSize;
        SetIndex<T>* CheckingIndex = Container[HashNum];
        SetIndex<T>* BeforeCheckingIndex = nullptr;

        while (CheckingIndex != nullptr)
        {
            if (CheckingIndex->Index == NewIndex)
                break;

            BeforeCheckingIndex = CheckingIndex;
            CheckingIndex = CheckingIndex->NextIndex;
        }

        if (BeforeCheckingIndex == nullptr)
        {
            Container[HashNum] = CheckingIndex->NextIndex;
        }
        else
        {
            BeforeCheckingIndex->NextIndex = CheckingIndex->NextIndex;
        }

        delete CheckingIndex;
        return true;
    }

    bool Contains(T InIndex) const
    {
        int HashNum = Hash<T>()(InIndex) % BucketSize;
        SetIndex<T>* CheckingIndex = Container[HashNum];

        while (CheckingIndex != nullptr)
        {
            if (CheckingIndex->Index == InIndex)
                return true;

            CheckingIndex = CheckingIndex->NextIndex;
        }

        return false;
    }

    T* Find(const T& InIndex) const
    {
        if (!this->Contains(InIndex))
            return nullptr;

        int HashNum = Hash<T>()(InIndex) % BucketSize;
        SetIndex<T>* CheckingIndex = Container[HashNum];

        while (CheckingIndex != nullptr)
        {
            if (CheckingIndex->Index == InIndex)
                return &(CheckingIndex->Index);

            CheckingIndex = CheckingIndex->NextIndex;
        }

        return nullptr;
    }

    bool IsEmpty() const
    {
        for (int i = 0; i < Container.Num(); i++)
        {
            if (Container[i] != nullptr)
            {
                return false;
            }
        }
        return true;
    }

private:
    TArray<SetIndex<T>*> Container;
    int BucketSize;
};
