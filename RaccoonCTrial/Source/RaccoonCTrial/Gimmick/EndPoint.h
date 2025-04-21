#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class AEndPoint : public AActor
{
public:
	AEndPoint();

public:
	void OnOverlap(AActor* OtherActor);
};

