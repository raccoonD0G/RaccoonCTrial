#include "Monster.h"
#include "random"
#include "World/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AMonster::AMonster()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();
	AddOwnedComponent<UBoxComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetScreenString("M");
	}
}

void AMonster::RandomMove()
{
	random_device RandomDevice;
	mt19937 Generator(RandomDevice());
	uniform_int_distribution<> Distribution(0, 3);
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

	World->MoveRenderTarger(RootComponent->GetLocation(), TargetVector);
}
