#include "BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Core/Collision/CollisionChannel.h"


UBoxComponent::UBoxComponent()
{
	SetBoxSize(FVector2D(0, 0));
}

UBoxComponent::~UBoxComponent()
{
}

void UBoxComponent::TickComponent(float DeltaTime)
{
	UPrimitiveComponent::TickComponent(DeltaTime);
	PreviousLocation = GetOwner()->GetActorLocation();
}

void UBoxComponent::SetBoxSize(const FVector2D& InSize)
{
	FVector2D Center = this->GetLocation();
	BoundingBox.Min = FVector2D(Center.X - InSize.X / 2.0f, Center.Y - InSize.Y / 2.0f);
	BoundingBox.Max = FVector2D(Center.X + InSize.X / 2.0f, Center.Y + InSize.Y / 2.0f);
}

AActor* UBoxComponent::GetSelfActor() const
{
	return GetOwner();
}

bool UBoxComponent::CheckOverlap(ICollisionInterface* InCollisionInterface) const
{
	if (UBoxComponent* OtherBox = dynamic_cast<UBoxComponent*>(InCollisionInterface))
	{
		FVector2D MyPos = this->GetWorldLocation();
		FVector2D OtherPos = OtherBox->GetWorldLocation();

		FBox MyBox = FBox(
			BoundingBox.Min + MyPos,
			BoundingBox.Max + MyPos
		);

		FBox OtherBoxBounds = FBox(
			OtherBox->GetBoundingBox().Min + OtherPos,
			OtherBox->GetBoundingBox().Max + OtherPos
		);

		return !(MyBox.Max.X < OtherBoxBounds.Min.X ||
			MyBox.Min.X > OtherBoxBounds.Max.X ||
			MyBox.Max.Y < OtherBoxBounds.Min.Y ||
			MyBox.Min.Y > OtherBoxBounds.Max.Y);
	}

	return false;
}


void UBoxComponent::OnOverlap(AActor* OtherActor)
{
	if (OnOverlapDelegate)
	{
		OnOverlapDelegate(OtherActor);
	}
}

bool UBoxComponent::ShouldBlock(ICollisionInterface* Other) const
{
	UBoxComponent* OtherBox = dynamic_cast<UBoxComponent*>(Other);
	if (!OtherBox)
	{
		return false;
	}

	ECollisionChannel OtherChannel = OtherBox->GetCollisionChannel();

	return GetResponseToChannel(OtherChannel) == ECollisionResponse::Block;
}

void UBoxComponent::OnBlock(AActor* OtherActor)
{
	GetOwner()->SetActorLocation(PreviousLocation);
	if (OnBlockDelegate)
	{
		OnBlockDelegate(OtherActor);
	}
}

void UBoxComponent::SetCollisionChannel(ECollisionChannel InChannel)
{
	CollisionChannel = InChannel;
}

ECollisionChannel UBoxComponent::GetCollisionChannel() const
{
	return CollisionChannel;
}

void UBoxComponent::SetCollisionResponseToChannel(ECollisionChannel TargetChannel, ECollisionResponse Response)
{
	ChannelResponses[TargetChannel] = Response;
}

ECollisionResponse UBoxComponent::GetResponseToChannel(ECollisionChannel TargetChannel) const
{
	const ECollisionResponse* Found = ChannelResponses.Find(TargetChannel);
	if (Found)
	{
		return *Found;
	}

	return ECollisionResponse::Ignore;
}