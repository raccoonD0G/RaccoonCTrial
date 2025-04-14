#include "CollisionSystem.h"
#include "Core/DynamicArray.h"
#include "Interfaces/ICollisionInterface.h"

void UCollisionSystem::Register(ICollisionInterface* CollisionObject)
{
    if (CollisionObject && !CollisionInterfaces.Contains(CollisionObject))
    {
        CollisionInterfaces.Add(CollisionObject);
    }
}

void UCollisionSystem::Unregister(ICollisionInterface* CollisionObject)
{
    CollisionInterfaces.Remove(CollisionObject);
}

void UCollisionSystem::PerformCollisionChecks()
{
    for (int i = 0; i < CollisionInterfaces.Num(); ++i)
    {
        for (int j = i + 1; j < CollisionInterfaces.Num(); ++j)
        {
            ICollisionInterface* A = CollisionInterfaces[i];
            ICollisionInterface* B = CollisionInterfaces[j];

            if (A && B)
            {
                if (A->CheckOverlap(B))
                {

                }
                if (B->CheckOverlap(A))
                {

                }
            }
        }
    }
}