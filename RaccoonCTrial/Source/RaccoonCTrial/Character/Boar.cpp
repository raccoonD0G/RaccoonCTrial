#include "Boar.h"
#include "Components/StaticMeshComponent.h"

ABoar::ABoar()
{
	UStaticMeshComponent* StaticMeshComponent = this->GetComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("B");
	}
}

void ABoar::Charge()
{
}
