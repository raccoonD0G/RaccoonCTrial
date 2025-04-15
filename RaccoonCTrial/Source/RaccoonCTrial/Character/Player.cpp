#include "Player.h"
#include "World/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

APlayer::APlayer()
{
	UStaticMeshComponent* StaticMeshComponent = this->GetComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("P");
	}

	UBoxComponent* BoxComponent = this->GetComponentByClass<UBoxComponent>();
	if (BoxComponent)
	{
		BoxComponent->SetCollisionChannel(ECollisionChannel::Player);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Monster, ECollisionResponse::Block);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Wall, ECollisionResponse::Block);

	}
}

void APlayer::PostInitializeComponents()
{
	AActor::PostInitializeComponents();
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();

	ControlledLocation = GetActorLocation();
}

void APlayer::Tick(float DeltaSeconds)
{
	AActor::Tick(DeltaSeconds);

	SetActorLocation(ControlledLocation);
}
