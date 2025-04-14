#pragma once
#include "Core/Math/Vector2.h"

class ILocationInterface
{
public:
	virtual FVector2 GetLocation() = 0;
	virtual void SetLocation(FVector2 NewLocation) = 0;
};

