#pragma once

#include "Set.h"
#include "Pair.h"
#include "iostream"

#include "Core/Collision/CollisionChannel.h"

template<typename KeyType, typename ValueType>
class TMap
{
private:
    using PairType = TPair<KeyType, ValueType>;
    TSet<PairType> Pairs;

public:
    TMap()
    {
        ;
    }

    TMap(const TMap& Other) : Pairs(Other.Pairs) { }

    TMap(TMap&& Other) noexcept : Pairs(std::move(Other.Pairs)) { }
    
    ~TMap()
    {
        ;
    }

    TMap& operator=(const TMap& Other)
    {
        if (this != &Other)
            Pairs = Other.Pairs;
        return *this;
    }

    TMap& operator=(TMap&& Other) noexcept
    {
        if (this != &Other)
            Pairs = std::move(Other.Pairs);
        return *this;
    }

    void Add(const KeyType& InKey, const ValueType& InValue)
    {
        Remove(InKey);
        Pairs.Add(PairType(InKey, InValue));
    }

    bool Remove(const KeyType& InKey)
    {
        return Pairs.Remove(PairType(InKey, ValueType()));
    }

    bool Contains(const KeyType& InKey) const
    {
        return Pairs.Contains(PairType(InKey, ValueType()));
    }

    ValueType* Find(const KeyType& InKey)
    {
        PairType* Found = Pairs.Find(PairType(InKey, ValueType()));
        return Found ? &Found->Value : nullptr;
    }

    const ValueType* Find(const KeyType& InKey) const
    {
        const PairType* Found = Pairs.Find(PairType(InKey, ValueType()));
        return Found ? &Found->Value : nullptr;
    }

    ValueType& operator[](const KeyType& InKey)
    {
        ValueType* Found = Find(InKey);
        if (!Found)
        {
            std::cout << "Cant Find" << std::endl;
            Add(InKey, ValueType());
            Found = Find(InKey);
        }
        return *Found;
    }

    void Clear()
    {
        Pairs.Clear();
    }

    std::size_t Num() const
    {
        return Pairs.Num();
    }

    bool IsEmpty() const
    {
        return Pairs.IsEmpty();
    }
};
