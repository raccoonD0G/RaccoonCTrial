#pragma once
#include "ActorComponent.h"
#include "Interfaces/ILocationInterface.h"
class USceneComponent : public UActorComponent, public virtual ILocationInterface
{
private:
	FVector2 CurrentLocation;

public:
	virtual FVector2 GetLocation() override;
	virtual void SetLocation(FVector2 NewLocation) override;
};

