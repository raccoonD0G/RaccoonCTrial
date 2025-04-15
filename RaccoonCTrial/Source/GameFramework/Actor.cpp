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
