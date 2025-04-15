#pragma once
#include "PrimitiveComponent.h"
#include "Interfaces/IRenderInterface.h"

class UStaticMeshComponent : public UPrimitiveComponent, public IRenderInterface
{
private:
	std::string ScreenString;

public:
	virtual std::string GetRenderString() override;
	virtual void SetRenderString(const std::string& NewScreenString) override;
};

