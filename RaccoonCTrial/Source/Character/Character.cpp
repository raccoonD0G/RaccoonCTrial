#include "Character.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ACharacter::ACharacter()
{
	RootComponent = AddOwnedComponent<UBoxComponent>();

	UStaticMeshComponent* StaticMeshComponent = AddOwnedComponent<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("C");
	}
}

void ACharacter::GetDamaged(IFightInterface* Other)
{
}

void ACharacter::DoAttack(IFightInterface* Target)
{
}
