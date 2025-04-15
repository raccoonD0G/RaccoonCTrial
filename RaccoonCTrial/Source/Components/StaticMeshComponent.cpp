#include "StaticMeshComponent.h"

std::string UStaticMeshComponent::GetRenderString()
{
	return ScreenString;
}

void UStaticMeshComponent::SetRenderString(const std::string& NewScreenString)
{
	ScreenString = NewScreenString;
}
