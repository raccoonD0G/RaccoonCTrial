#pragma once
#include "PrimitiveComponent.h"
#include "Interfaces/ICollisionInterface.h"

class UBoxComponent : public UPrimitiveComponent, public ICollisionInterface
{
public:
	virtual bool CheckOverlap(ICollisionInterface* InCollisionInterface) override;
};

