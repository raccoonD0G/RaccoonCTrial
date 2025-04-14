#include "Actor.h"
#include "World/World.h"

string AActor::GetScreenString()
{
    return "A";
}

FVector2 AActor::GetLocation()
{
    return CurrentLocation;
}

void AActor::SetLocation(FVector2 NewLocation)
{
    CurrentLocation = NewLocation;
}

void AActor::SetWorld(UWorld* InOwningMap)
{
    World = InOwningMap;
}

UWorld* AActor::GetWorld()
{
    return World;
}
