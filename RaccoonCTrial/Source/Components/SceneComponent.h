#pragma once
#include "ActorComponent.h"
#include "Interfaces/ILocationInterface.h"

class USceneComponent : public UActorComponent, public ILocationInterface
{
public:
	virtual void TickComponent(float DeltaTime) override;

private:
	FVector2 CurrentLocation;

public:
	virtual FVector2 GetLocation() const override;
	virtual FVector2 GetWorldLocation() const override;
	virtual void SetLocation(const FVector2& NewLocation) override;
};

