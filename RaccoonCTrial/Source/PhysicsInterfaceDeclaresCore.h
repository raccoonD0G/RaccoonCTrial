#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/ICollisionInterface.h"

class UPrimitiveComponent;

class FPhysScene : public UObject
{
public:
    FPhysScene();
    virtual ~FPhysScene();

public:
    void RegisterPrimitiveComponent(UPrimitiveComponent* InPrimitiveComponent);
    void UnregisterPrimitiveComponent(UPrimitiveComponent* InPrimitiveComponent);
    void PerformCollisionChecks();

private:
    TArray<UPrimitiveComponent*> PrimitiveComponents;
};
