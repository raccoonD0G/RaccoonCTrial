#include "Player.h"

string APlayer::GetScreenString()
{
    return "P";
}

void APlayer::Move(FVector2 Destination)
{
    OwningMap->MoveScreenPrintTarget(this->GetLocation(), Destination);
}
