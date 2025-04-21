#pragma once
#include "UObject/Object.h"
#include "Interfaces/IWorldInterface.h"

class AActor;

class UActorComponent : public UObject
{
public:
	UActorComponent();
	~UActorComponent();

public:
	virtual void TickComponent(float DeltaTime);

private:
	AActor* Owner = nullptr;

public:
	inline void SetOwner(AActor* InOwner) { Owner = InOwner; }
	inline AActor* GetOwner() const { return Owner; }

// World Section
	virtual UWorld* GetWorld() const;
};

