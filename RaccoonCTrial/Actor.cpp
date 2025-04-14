#include "Actor.h"

string Actor::GetScreenString()
{
    return "A";
}

Vector2 Actor::GetLocation()
{
    return CurrentLocation;
}

void Actor::SetLocation(Vector2 NewLocation)
{
    CurrentLocation = NewLocation;
}

void Actor::SetOwningMap(Map* InOwningMap)
{
    OwningMap = InOwningMap;
}
