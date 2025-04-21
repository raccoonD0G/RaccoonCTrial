#pragma once
#include "CoreMinimal.h"
#include "Character/Character.h"

class APlayer : public ACharacter
{
public:
	APlayer();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

// Controll Section
public:
	inline void SetControlledLocation(const FVector2D& NewControlledLocation) { ControlledLocation = NewControlledLocation; }

private:
	FVector2D ControlledLocation;
};

