#pragma once
#include "Core/Object.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IWorldInterface.h"

class UActorComponent : public UObject, public IWorldInterface
{
private:
	AActor* Owner = nullptr;

public:
	inline void SetOwner(AActor* InOwner) { Owner = InOwner; }
	inline AActor* GetOwner() const { return Owner; }

// World Section
	virtual UWorld* GetWorld() const { return Owner ? Owner->GetWorld() : nullptr; }
};

