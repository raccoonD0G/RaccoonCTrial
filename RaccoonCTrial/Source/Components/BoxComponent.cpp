#include "BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/CollisionProfile.h"

UBoxComponent::UBoxComponent()
{
    SetBoxSize(FVector2D(1, 1));
}

UBoxComponent::~UBoxComponent()
{
}

void UBoxComponent::TickComponent(float DeltaTime)
{
    UPrimitiveComponent::TickComponent(DeltaTime);
}

void UBoxComponent::SetBoxSize(const FVector2D& InSize)
{
    FVector2D Center = this->GetLocation();
    BoundingBox.Min = FVector2D(Center.X - InSize.X / 2.0f, Center.Y - InSize.Y / 2.0f);
    BoundingBox.Max = FVector2D(Center.X + InSize.X / 2.0f, Center.Y + InSize.Y / 2.0f);
}

bool UBoxComponent::ShouldOverlap(UPrimitiveComponent* Other) const
{
    UPrimitiveComponent::ShouldOverlap(Other);

    UBoxComponent* OtherBox = dynamic_cast<UBoxComponent*>(Other);
    if (!OtherBox) return false;

    FVector2D MyPos = GetWorldLocation();
    FVector2D OtherPos = OtherBox->GetWorldLocation();

    FBox MyBox(BoundingBox.Min + MyPos, BoundingBox.Max + MyPos);
    FBox OtherBoxBounds(OtherBox->GetBoundingBox().Min + OtherPos, OtherBox->GetBoundingBox().Max + OtherPos);

    if (!MyBox.Intersects(OtherBoxBounds)) return false;

    ECollisionChannel OtherChannel = OtherBox->GetCollisionChannel();
    return GetResponseToChannel(OtherChannel) == ECollisionResponse::Overlap;
}

bool UBoxComponent::ShouldBlock(UPrimitiveComponent* Other) const
{
    UPrimitiveComponent::ShouldBlock(Other);

    UBoxComponent* OtherBox = dynamic_cast<UBoxComponent*>(Other);
    if (!OtherBox) return false;

    FVector2D MyPos = GetWorldLocation();
    FVector2D OtherPos = OtherBox->GetWorldLocation();

    FBox MyBox(BoundingBox.Min + MyPos, BoundingBox.Max + MyPos);
    FBox OtherBoxBounds(OtherBox->GetBoundingBox().Min + OtherPos, OtherBox->GetBoundingBox().Max + OtherPos);

    if (!MyBox.Intersects(OtherBoxBounds)) return false;

    ECollisionChannel OtherChannel = OtherBox->GetCollisionChannel();

    return GetResponseToChannel(OtherChannel) == ECollisionResponse::Block;
}

