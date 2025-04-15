#include "Monster.h"
#include "random"
#include "World/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AMonster::AMonster()
{
	UStaticMeshComponent* StaticMeshComponent = this->GetComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("M");
	}

	UBoxComponent* BoxComponent = this->GetComponentByClass<UBoxComponent>();
	if (BoxComponent)
	{
		BoxComponent->SetCollisionChannel(ECollisionChannel::Monster);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Player, ECollisionResponse::Block);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::Wall, ECollisionResponse::Block);
	}
}

void AMonster::Tick(float DeltaSeconds)
{
	AActor::Tick(DeltaSeconds);
	RandomMove();
}

void AMonster::RandomMove()
{
	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_int_distribution<> Distribution(0, 3);
	int MonsterValue = Distribution(Generator);

	FVector2 TargetVector;
	switch (MonsterValue)
	{
	case 0:
		TargetVector = FVector2(RootComponent->GetLocation().X, RootComponent->GetLocation().Y - 1);
		break;
	case 1:
		TargetVector = FVector2(RootComponent->GetLocation().X - 1, RootComponent->GetLocation().Y);
		break;
	case 2:
		TargetVector = FVector2(RootComponent->GetLocation().X, RootComponent->GetLocation().Y + 1);
		break;
	case 3:
		TargetVector = FVector2(RootComponent->GetLocation().X + 1, RootComponent->GetLocation().Y);
		break;
	}

	SetActorLocation(TargetVector);
}