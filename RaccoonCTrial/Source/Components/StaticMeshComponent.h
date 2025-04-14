#pragma once
#include "PrimitiveComponent.h"
#include "Interfaces/IRenderInterface.h"

class UStaticMeshComponent : public UPrimitiveComponent, public IRenderInterface
{
private:
	string ScreenString;

public:
	virtual string GetScreenString() override;
	virtual void SetScreenString(string NewScreenString) override;
};

