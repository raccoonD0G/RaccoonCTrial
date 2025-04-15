#pragma once
#include "SceneComponent.h"
#include "string"

class UPrimitiveComponent : public USceneComponent
{
public:
	virtual void TickComponent(float DeltaTime) override;
};

