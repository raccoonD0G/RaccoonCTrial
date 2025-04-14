#include "Wall.h"

string Wall::GetScreenString()
{
    return "*";
}

Vector2 Wall::GetLocation()
{
    return CurrentLocation;
}

void Wall::SetLocation(Vector2 NewLocation)
{
    CurrentLocation = NewLocation;
}
