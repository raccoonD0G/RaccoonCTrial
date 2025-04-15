#include "Slime.h"
#include "Components/StaticMeshComponent.h"

ASlime::ASlime()
{
	UStaticMeshComponent* StaticMeshComponent = this->GetComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("S");
	}
}

void ASlime::Slide()
{
}
