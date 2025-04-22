#include "PrimitiveComponent.h"
#include "GameFramework/Actor.h"

UPrimitiveComponent::UPrimitiveComponent() : CollisionChannel(ECollisionChannel::None)
{
}

void UPrimitiveComponent::TickComponent(float DeltaTime)
{
	USceneComponent::TickComponent(DeltaTime);
    PreviousLocation = GetOwner()->GetActorLocation();
}

bool UPrimitiveComponent::ShouldOverlap(UPrimitiveComponent* Other) const
{
	return false;
}

void UPrimitiveComponent::OnOverlap(UPrimitiveComponent* Other)
{
    if (OnOverlapDelegate)
    {
        OnOverlapDelegate(Other);
    }
}

bool UPrimitiveComponent::ShouldBlock(UPrimitiveComponent* Other) const
{
    return false;
}

void UPrimitiveComponent::OnBlock(UPrimitiveComponent* Other)
{
    GetOwner()->SetActorLocation(PreviousLocation);
    if (OnBlockDelegate)
    {
        OnBlockDelegate(Other);
    }
}

const FCollisionProfileName& UPrimitiveComponent::GetCollisionProfileName() const
{
    return CollisionProfile;
}

void UPrimitiveComponent::SetCollisionProfileName(const FCollisionProfileName& ProfileName)
{
    FCollisionResponseContainer OutContainer;
    if (UCollisionProfile::Get().GetResponseContainer(ProfileName.Name, OutContainer))
    {
        CollisionProfile = ProfileName;
        CollisionResponses = OutContainer;
        SetCollisionChannel(OutContainer.GetChannel());
    }
}

void UPrimitiveComponent::SetCollisionChannel(ECollisionChannel InChannel)
{
    CollisionChannel = InChannel;
}

ECollisionChannel UPrimitiveComponent::GetCollisionChannel() const
{
    return CollisionChannel;
}

void UPrimitiveComponent::SetCollisionResponseToChannel(ECollisionChannel TargetChannel, ECollisionResponse Response)
{
    CollisionResponses.SetResponseToChannel(TargetChannel, Response);
}

ECollisionResponse UPrimitiveComponent::GetResponseToChannel(ECollisionChannel TargetChannel) const
{
    return CollisionResponses.GetResponseToChannel(TargetChannel);
}

