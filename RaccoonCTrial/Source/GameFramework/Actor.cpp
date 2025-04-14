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

void AActor::SetOwningMap(UWorld* InOwningMap)
{
    OwningMap = InOwningMap;
}
