#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UPrimitiveComponent;

class AEndPoint : public AActor
{
public:
	AEndPoint();
	virtual ~AEndPoint() { ; }

public:
	void OnOverlap(UPrimitiveComponent* Other);
};

