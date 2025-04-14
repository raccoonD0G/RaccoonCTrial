#pragma once

class UClass;

class UObject
{
    virtual UClass* GetClass() const;
    bool IsA(const UClass* Other) const;
    static UClass* StaticClass();
};

