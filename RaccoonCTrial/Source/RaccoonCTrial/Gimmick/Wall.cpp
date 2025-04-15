#include "Wall.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AWall::AWall()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("*");
	}

	UBoxComponent* BoxComponent = AddOwnedComponent<UBoxComponent>();
	if (BoxComponent)
	{
		BoxComponent->SetCollisionChannel(ECollisionChannel::Wall);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Player, ECollisionResponse::Block);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Monster, ECollisionResponse::Block);
	}
}
