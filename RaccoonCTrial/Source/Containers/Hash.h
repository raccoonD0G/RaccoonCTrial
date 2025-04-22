#pragma once

#include "functional"
#include "Containers/Pair.h"
#include "string"

template<typename T>
struct Hash
{
    uint32_t operator()(const T& Key) const
    {
        return static_cast<uint32_t>(std::hash<T>()(Key));
    }
};

template<typename KeyType, typename ValueType>
struct Hash<TPair<KeyType, ValueType>>
{
    std::size_t operator()(const TPair<KeyType, ValueType>& Pair) const {
        return Hash<KeyType>()(Pair.Key);
    }
};