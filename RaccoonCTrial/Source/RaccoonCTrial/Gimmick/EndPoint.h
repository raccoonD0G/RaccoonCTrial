#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class AEndPoint : public AActor
{
public:
	AEndPoint();
	virtual ~AEndPoint() { ; }

public:
	void OnOverlap(AActor* OtherActor);
};

