#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/ICollisionInterface.h"

class UCollisionSystem : public UObject
{
public:
    UCollisionSystem();
    ~UCollisionSystem();

public:
    void RegisterCollisionTarget(ICollisionInterface* CollisionObject);
    void Unregister(ICollisionInterface* CollisionObject);
    void PerformCollisionChecks();

private:
    TArray<ICollisionInterface*> CollisionInterfaces;
};
