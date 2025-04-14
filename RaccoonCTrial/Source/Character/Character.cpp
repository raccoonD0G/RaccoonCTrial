#include "Character.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ACharacter::ACharacter()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();
	AddOwnedComponent<UBoxComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetScreenString("M");
	}
}
