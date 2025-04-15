#include "Actor.h"
#include "World/World.h"

AActor::AActor()
{
}

AActor::~AActor()
{
    for (int i = 0; i < ActorComponents.Num(); i++)
    {
        delete ActorComponents[i];
    }
    ActorComponents.Clear();

    for (int i = 0; i < SceneComponents.Num(); i++)
    {
        delete SceneComponents[i];
    }
    SceneComponents.Clear();
}

void AActor::PostInitializeComponents()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick(float DeltaSeconds)
{
    for (int i = 0; i < ActorComponents.Num(); i++)
    {
        ActorComponents[i]->TickComponent(DeltaSeconds);
    }

    for (int i = 0; i < SceneComponents.Num(); i++)
    {
        SceneComponents[i]->TickComponent(DeltaSeconds);
    }
}

void AActor::SetWorld(UWorld* InOwningMap)
{
    World = InOwningMap;
}

UWorld* AActor::GetWorld()
{
    return World;
}

void AActor::SetActorLocation(FVector2 NewLocation)
{
    UBoxComponent* Box = GetComponentByClass<UBoxComponent>();
    if (Box)
    {
        FVector2 OldLocation = RootComponent->GetLocation();

        RootComponent->SetLocation(NewLocation);

        for (int i = 0; i < World->GetAllActors().Num(); i++)
        {
            AActor* Other = World->GetAllActors()[i];

            if (Other == this) continue;

            if (UBoxComponent* OtherBox = Other->GetComponentByClass<UBoxComponent>())
            {
                if (Box->CheckOverlap(OtherBox) && Box->ShouldBlock(OtherBox))
                {
                    RootComponent->SetLocation(OldLocation);
                    Box->OnBlock(Other);
                    return;
                }
            }
        }
    }
    else
    {
        RootComponent->SetLocation(NewLocation);
    }
}
