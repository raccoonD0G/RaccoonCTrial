#include "Class.h"

bool UClass::IsChildOf(const UClass* Other) const
{
    const UClass* Current = this;
    while (Current)
    {
        if (Current == Other) return true;
        Current = Current->SuperClass;
    }
    return false;
}
