#pragma once

#include "CoreMinimal.h"

class ILocationInterface
{
public:
	virtual ~ILocationInterface() { ; }
	virtual FVector2D GetLocation() const = 0;
	virtual FVector2D GetWorldLocation() const = 0;
	virtual void SetLocation(const FVector2D& NewLocation) = 0;
};

