#include "World.h"

void UWorld::MoveRenderTarger(FVector2 Target, FVector2 Destination)
{
	if (IsEmpty(Destination.X, Destination.Y))
	{
		RenderInterfaces[Destination.X][Destination.Y] = RenderInterfaces[Target.X][Target.Y];
		RenderInterfaces[Destination.X][Destination.Y]->SetLocation(Destination);
		RenderInterfaces[Target.X][Target.Y] = nullptr;
	}	
}