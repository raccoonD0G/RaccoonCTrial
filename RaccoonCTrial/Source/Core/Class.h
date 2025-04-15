#pragma once
#include "string"

class UClass
{
    std::string Name;
    const UClass* SuperClass;

    UClass(const std::string& InName, const UClass* InSuperClass) : Name(InName), SuperClass(InSuperClass) { ; }

    bool IsChildOf(const UClass* Other) const;
};

