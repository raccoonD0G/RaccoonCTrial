#pragma once

#include "Core/Object.h"
#include "Core/DynamicArray.h"

class ICollisionInterface;

class UCollisionSystem : public UObject
{
private:
    TArray<ICollisionInterface*> CollisionInterfaces;

public:
    void Register(ICollisionInterface* CollisionObject);

    void Unregister(ICollisionInterface* CollisionObject);

    void PerformCollisionChecks();
};
