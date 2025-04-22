#include "MeshComponent.h"

UMeshComponent::UMeshComponent()
{
	this->SetVisibility(true);
	this->SetCollisionProfileName(FCollisionProfileName("Mesh"));
}
