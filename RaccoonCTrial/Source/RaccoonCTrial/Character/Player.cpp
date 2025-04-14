#include "Player.h"
#include "World/World.h"

string APlayer::GetScreenString()
{
    return "P";
}

void APlayer::Move(FVector2 Destination)
{
    OwningMap->MoveRenderTarger(this->GetLocation(), Destination);
}
