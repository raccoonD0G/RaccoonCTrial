#include "SceneComponent.h"
#include "GameFramework/Actor.h"
void USceneComponent::TickComponent(float DeltaTime)
{
	UActorComponent::TickComponent(DeltaTime);
}

FVector2D USceneComponent::GetLocation() const
{
	return CurrentLocation;
}

FVector2D USceneComponent::GetWorldLocation() const
{
	if (this != GetOwner()->GetRootComponent())
	{
		return CurrentLocation + GetOwner()->GetActorLocation();
	}
	else
	{
		return CurrentLocation;
	}
}

void USceneComponent::SetLocation(const FVector2D& NewLocation)
{
	CurrentLocation = NewLocation;
}
