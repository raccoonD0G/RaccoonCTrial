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

	UBoxComponent* BoxComponent = this->AddOwnedComponent<UBoxComponent>();
	if (BoxComponent)
	{
		BoxComponent->SetCollisionProfileName(FCollisionProfileName("Wall"));
	}
}
