#include "SceneComponent.h"

FVector2 USceneComponent::GetLocation()
{
	return CurrentLocation;
}

void USceneComponent::SetLocation(FVector2 NewLocation)
{
	CurrentLocation = NewLocation;
}
