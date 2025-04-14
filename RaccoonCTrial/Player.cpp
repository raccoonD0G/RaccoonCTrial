#include "Player.h"

string Player::GetScreenString()
{
    return "P";
}

void Player::Move(Vector2 Destination)
{
    OwningMap->MoveScreenPrintTarget(this->GetLocation(), Destination);
}
