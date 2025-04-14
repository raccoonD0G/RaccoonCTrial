#include "ActorComponent.h"
#include "GameFramework/Actor.h"

UWorld* UActorComponent::GetWorld() const
{
	return Owner ? Owner->GetWorld() : nullptr;
}
