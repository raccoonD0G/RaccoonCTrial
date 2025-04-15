#pragma once

#include <functional>

template<typename T>
struct Hash
{
    uint32_t operator()(const T& Key) const
    {
        return static_cast<uint32_t>(std::hash<T>{}(Key));
    }
};
