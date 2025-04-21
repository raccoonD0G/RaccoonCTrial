#pragma once
#include "ActorComponent.h"
#include "Interfaces/ILocationInterface.h"

class USceneComponent : public UActorComponent, public ILocationInterface
{
public:
	virtual void TickComponent(float DeltaTime) override;

private:
	FVector2D CurrentLocation;

public:
	virtual FVector2D GetLocation() const override;
	virtual FVector2D GetWorldLocation() const override;
	virtual void SetLocation(const FVector2D& NewLocation) override;
};

