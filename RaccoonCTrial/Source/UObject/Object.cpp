#include "Object.h"

UClass* UObject::GetClass() const
{
    return nullptr;
}

bool UObject::IsA(const UClass* Other) const
{
    return false;
}

UClass* UObject::StaticClass()
{
    return nullptr;
}
