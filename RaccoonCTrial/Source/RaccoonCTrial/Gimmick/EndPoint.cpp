#include "EndPoint.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

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
		;
	}
}
