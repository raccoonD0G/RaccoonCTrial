#pragma once

#include "Core/Math/Vector2.h"

class ILocationInterface
{
public:
	virtual ~ILocationInterface() { ; }
	virtual FVector2 GetLocation() const = 0;
	virtual FVector2 GetWorldLocation() const = 0;
	virtual void SetLocation(const FVector2& NewLocation) = 0;
};

