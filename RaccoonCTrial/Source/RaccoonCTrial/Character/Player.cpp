#include "Player.h"
#include "World/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

APlayer::APlayer()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();
	AddOwnedComponent<UBoxComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetScreenString("P");
	}
}

void APlayer::Move(FVector2 Destination)
{
    World->MoveRenderTarger(RootComponent->GetLocation(), Destination);
}
