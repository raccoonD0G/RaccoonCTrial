#pragma once

#include "Core/Object.h"
#include "Core/Container/DynamicArray.h"
#include "Interfaces/ICollisionInterface.h"

class UCollisionSystem : public UObject
{
public:
    UCollisionSystem();
    ~UCollisionSystem();

public:
    void Register(ICollisionInterface* CollisionObject);
    void Unregister(ICollisionInterface* CollisionObject);
    void PerformCollisionChecks();

private:
    TArray<ICollisionInterface*> CollisionInterfaces;
};
