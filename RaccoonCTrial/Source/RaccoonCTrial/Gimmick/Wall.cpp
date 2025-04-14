#include "Wall.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AWall::AWall()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();
	AddOwnedComponent<UBoxComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetScreenString("*");
	}
}
