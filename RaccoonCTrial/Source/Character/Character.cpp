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
