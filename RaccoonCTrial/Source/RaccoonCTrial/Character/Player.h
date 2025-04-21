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
private:
	FVector2 ControlledLocation;

public:
	inline void SetControlledLocation(const FVector2& NewControlledLocation) { ControlledLocation = NewControlledLocation; }
};

