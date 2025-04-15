#pragma once
#include "Components/MeshComponent.h"

class UStaticMeshComponent : public UMeshComponent
{
private:
	std::string ScreenString;

public:
	virtual std::string GetRenderString() override;
	virtual void SetRenderString(const std::string& NewScreenString) override;
};

