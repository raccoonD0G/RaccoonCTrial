#pragma once
#include "CoreMinimal.h"
#include "Components/ShapeComponent.h"
#include "functional"
#include "Core/Collision/CollisionChannel.h"

class UBoxComponent : public UShapeComponent
{
public:
	UBoxComponent();
	~UBoxComponent();

public:
	virtual void TickComponent(float DeltaTime) override;

private:
	FBox BoundingBox;

public:
	void SetBoxSize(const FVector2D& InSize);
	inline const FBox& GetBoundingBox() const { return BoundingBox; }

// Actor Section
public:
	virtual AActor* GetSelfActor() const override;

// Overlap Section
public:
	virtual bool CheckOverlap(ICollisionInterface* InCollisionInterface) const override;
	virtual void OnOverlap(AActor* OtherActor) override;

	using FOverlapDelegate = std::function<void(AActor* OtherActor)>;
	FOverlapDelegate OnOverlapDelegate;
	

// Block Section
private:
	FVector2D PreviousLocation;

public:
	virtual bool ShouldBlock(ICollisionInterface* Other) const override;
	virtual void OnBlock(AActor* OtherActor) override;

	using FBlockDelegate = std::function<void(AActor* OtherActor)>;
	FBlockDelegate OnBlockDelegate;

// Collision Channel Section
private:
	ECollisionChannel CollisionChannel = ECollisionChannel::None;
	TMap<ECollisionChannel, ECollisionResponse> ChannelResponses;

public:
	virtual void SetCollisionChannel(ECollisionChannel InChannel) override;
	virtual ECollisionChannel GetCollisionChannel() const override;

	virtual void SetCollisionResponseToChannel(ECollisionChannel TargetChannel, ECollisionResponse Response) override;
	virtual ECollisionResponse GetResponseToChannel(ECollisionChannel TargetChannel) const override;
};

