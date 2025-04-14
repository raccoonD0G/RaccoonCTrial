#pragma once
#include "string"
using namespace std;

class UClass
{
    string Name;
    const UClass* SuperClass;

    UClass(const string& InName, const UClass* InSuperClass) : Name(InName), SuperClass(InSuperClass) { ; }

    bool IsChildOf(const UClass* Other) const;
};

