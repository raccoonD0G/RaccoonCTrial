#include "ActorComponent.h"
#include "GameFramework/Actor.h"

UActorComponent::UActorComponent()
{
}

UActorComponent::~UActorComponent()
{
}

void UActorComponent::TickComponent(float DeltaTime)
{
}

UWorld* UActorComponent::GetWorld() const
{
	return Owner ? Owner->GetWorld() : nullptr;
}
