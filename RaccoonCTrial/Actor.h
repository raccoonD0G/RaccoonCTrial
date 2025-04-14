#pragma once
#include "IRenderInterface.h"

class UWorld;

class AActor : public IRenderInterface
{
protected:
    FVector2 CurrentLocation;
    UWorld* OwningMap;

public:
    virtual string GetScreenString() override;
    virtual FVector2 GetLocation() override;
    virtual void SetLocation(FVector2 NewLocation) override;
    virtual void SetOwningMap(UWorld* InOwningMap) override;
};

