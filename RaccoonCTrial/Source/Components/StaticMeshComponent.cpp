#include "StaticMeshComponent.h"

string UStaticMeshComponent::GetScreenString()
{
	return ScreenString;
}

void UStaticMeshComponent::SetScreenString(string NewScreenString)
{
	ScreenString = NewScreenString;
}
