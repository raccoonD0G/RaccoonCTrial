#include "EndPoint.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AEndPoint::AEndPoint()
{
	RootComponent = AddOwnedComponent<UStaticMeshComponent>();
	AddOwnedComponent<UBoxComponent>();

	UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(RootComponent);
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetScreenString("E");
	}
}
