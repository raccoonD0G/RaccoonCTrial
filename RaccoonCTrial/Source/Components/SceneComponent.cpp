#include "SceneComponent.h"
#include "GameFramework/Actor.h"
void USceneComponent::TickComponent(float DeltaTime)
{
	UActorComponent::TickComponent(DeltaTime);
}

FVector2 USceneComponent::GetLocation() const
{
	return CurrentLocation;
}

FVector2 USceneComponent::GetWorldLocation() const
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

void USceneComponent::SetLocation(const FVector2& NewLocation)
{
	CurrentLocation = NewLocation;
}
