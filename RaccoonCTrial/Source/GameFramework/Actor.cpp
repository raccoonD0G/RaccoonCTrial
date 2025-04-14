#include "Actor.h"
#include "World/World.h"

void AActor::PostInitializeComponents()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick(float DeltaSeconds)
{
}

void AActor::SetWorld(UWorld* InOwningMap)
{
    World = InOwningMap;
}

UWorld* AActor::GetWorld()
{
    return World;
}
