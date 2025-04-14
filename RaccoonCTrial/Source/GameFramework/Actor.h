#pragma once
#include "Interfaces/IRenderInterface.h"
#include "Interfaces/IWorldInterface.h"
#include "Core/Object.h"

class UWorld;

class AActor : public UObject, public IRenderInterface, public IWorldInterface
{
protected:
    FVector2 CurrentLocation;
    UWorld* World;

// Rendering Section
public:
    virtual string GetScreenString() override;

// Location Section
public:
    virtual FVector2 GetLocation() override;
    virtual void SetLocation(FVector2 NewLocation) override;

// World Section
public:
    virtual void SetWorld(UWorld* InWorld) override;
    virtual UWorld* GetWorld() override;

// Component Section
private:

};

