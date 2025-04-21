#pragma once
#include "CoreMinimal.h"
#include "Character/Character.h"

class AMonster : public ACharacter
{
public:
	AMonster();

protected:
	virtual void Tick(float DeltaSeconds) override;

// AI Section
public:
	void RandomMove();
};

