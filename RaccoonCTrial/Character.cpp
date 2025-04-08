#include "Character.h"


Vector2 Character::GetLocation()
{
    return CurrentLocation;
}

void Character::SetLocation(Vector2 NewLocation)
{
    CurrentLocation = NewLocation;
}
