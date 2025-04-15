#include "EndPoint.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "RaccoonCTrial/Character/Player.h"
#include "iostream"

AEndPoint::AEndPoint()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("E");
	}

	UBoxComponent* BoxComponent = AddOwnedComponent<UBoxComponent>();
	if (BoxComponent)
	{
		BoxComponent->SetCollisionChannel(ECollisionChannel::EndPoint);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Player, ECollisionResponse::Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Monster, ECollisionResponse::Block);

		BoxComponent->OnOverlapDelegate = [this](AActor* OtherActor) { this->OnOverlap(OtherActor); };
	}
}

void AEndPoint::OnOverlap(AActor* OtherActor)
{
	APlayer* Player = dynamic_cast<APlayer*>(OtherActor);
	if (Player)
	{
		std::cout << "Game End";
	}
}
