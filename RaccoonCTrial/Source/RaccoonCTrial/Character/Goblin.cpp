#include "Goblin.h"
#include "Components/StaticMeshComponent.h"

AGoblin::AGoblin()
{
	UStaticMeshComponent* StaticMeshComponent = this->GetComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRenderString("G");
	}
}

void AGoblin::Run()
{
}
