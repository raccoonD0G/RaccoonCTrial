#include "CollisionSystem.h"

UCollisionSystem::UCollisionSystem()
{
    ;
}

UCollisionSystem::~UCollisionSystem()
{
    ;
}

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
                    A->OnOverlap(B->GetSelfActor());
                    if (A->ShouldBlock(B) && B->ShouldBlock(A))
                    {
                        A->OnBlock(B->GetSelfActor());
                    }
                }
                if (B->CheckOverlap(A))
                {
                    B->OnOverlap(A->GetSelfActor());
                    if (B->ShouldBlock(A) && A->ShouldBlock(B))
                    {
                        B->OnBlock(A->GetSelfActor());
                    }
                }
            }
        }
    }
}