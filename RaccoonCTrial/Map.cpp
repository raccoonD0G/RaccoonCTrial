#include "Map.h"

void Map::MoveScreenPrintInterface(Vector2 Target, Vector2 Destination)
{
	if (IsEmpty(Destination.X, Destination.Y))
	{
		ScreenPrintInterfaces[Destination.X][Destination.Y] = ScreenPrintInterfaces[Target.X][Target.Y];
		ScreenPrintInterfaces[Destination.X][Destination.Y]->SetLocation(Destination);
		ScreenPrintInterfaces[Target.X][Target.Y] = nullptr;
	}	
}
