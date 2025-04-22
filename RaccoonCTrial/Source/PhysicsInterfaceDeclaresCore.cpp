#include "PhysicsInterfaceDeclaresCore.h"
#include "Components/PrimitiveComponent.h"

FPhysScene::FPhysScene()
{
    ;
}

FPhysScene::~FPhysScene()
{
    ;
}

void FPhysScene::RegisterPrimitiveComponent(UPrimitiveComponent* InPrimitiveComponent)
{
    if (InPrimitiveComponent && !PrimitiveComponents.Contains(InPrimitiveComponent))
    {
        PrimitiveComponents.Add(InPrimitiveComponent);
    }
}

void FPhysScene::UnregisterPrimitiveComponent(UPrimitiveComponent* InPrimitiveComponent)
{
    PrimitiveComponents.Remove(InPrimitiveComponent);
}

void FPhysScene::PerformCollisionChecks()
{
    for (int i = 0; i < PrimitiveComponents.Num(); ++i)
    {
        for (int j = i + 1; j < PrimitiveComponents.Num(); ++j)
        {
            UPrimitiveComponent* A = PrimitiveComponents[i];
            UPrimitiveComponent* B = PrimitiveComponents[j];

            if (!A || !B) continue;

            const FCollisionProfileName& ProfileA = A->GetCollisionProfileName();
            const FCollisionProfileName& ProfileB = B->GetCollisionProfileName();

            FCollisionResponseContainer ContainerA;
            FCollisionResponseContainer ContainerB;

            if (!UCollisionProfile::Get().GetResponseContainer(ProfileA.Name, ContainerA)) continue;
            if (!UCollisionProfile::Get().GetResponseContainer(ProfileB.Name, ContainerB)) continue;

            ECollisionResponse ResponseA = ContainerA.GetResponseToChannel(ContainerB.GetChannel());
            ECollisionResponse ResponseB = ContainerB.GetResponseToChannel(ContainerA.GetChannel());

            if (A->ShouldOverlap(B))
            {
                if (ResponseA == ECollisionResponse::Overlap || ResponseB == ECollisionResponse::Overlap)
                {
                    A->OnOverlap(B);
                    B->OnOverlap(A);
                }
            }

            if (A->ShouldBlock(B))
            {
                if (ResponseA == ECollisionResponse::Block && ResponseB == ECollisionResponse::Block)
                {
                    A->OnBlock(B);
                    B->OnBlock(A);
                }
            }
        }
    }
}
