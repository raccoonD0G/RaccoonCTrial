#include "iostream"
#include "conio.h"
#include "Player.h"
#include "Monster.h"
#include "IScreenPrintInterface.h"
#include "ScreenPrinter.h"
#include "DynamicArray.h"
#include "Wall.h"
#include "Map.h"


using namespace std;

int main()
{
	// Begin Play
	Map* CurrentMap = new Map(10, 10);

	Player* Player0 = CurrentMap->SpawnScreenPrintTarget<Player>(Vector2(1, 1));
	Monster* Monster0 = CurrentMap->SpawnScreenPrintTarget<Monster>(Vector2(1, 2));
	Monster* Monster1 = CurrentMap->SpawnScreenPrintTarget<Monster>(Vector2(4, 5));
	Monster* Monster2 = CurrentMap->SpawnScreenPrintTarget<Monster>(Vector2(1, 7));
	Monster* Monster3 = CurrentMap->SpawnScreenPrintTarget<Monster>(Vector2(3, 8));

	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9)
			{
				CurrentMap->SpawnScreenPrintTarget<Wall>(Vector2(i, j));
			}

			if (i >= 1 && i <= 8)
			{
				if (j == 0 || j == 9)
				{
					CurrentMap->SpawnScreenPrintTarget<Wall>(Vector2(i, j));
				}
			}
		}
	}

	system("cls");
	CurrentMap->GetScreenPrinter()->PrintAllOnScrean();

	while (true)
	{
		// Input
		if (_kbhit())
		{
			char Input = _getch();
			
			Vector2 TargetVector;
			switch (Input)
			{
			case 'w':
				TargetVector = Vector2(Player0->GetLocation().X, Player0->GetLocation().Y - 1);
				break;
			case 'a':
				TargetVector = Vector2(Player0->GetLocation().X - 1, Player0->GetLocation().Y);
				break;
			case 's':
				TargetVector = Vector2(Player0->GetLocation().X, Player0->GetLocation().Y + 1);
				break;
			case 'd':
				TargetVector = Vector2(Player0->GetLocation().X + 1, Player0->GetLocation().Y);
				break;
			}
			
			Player0->Move(TargetVector);

		}

		// Tick

		Monster0->RandomMove();
		Monster1->RandomMove();
		Monster2->RandomMove();
		Monster3->RandomMove();


		// Render
		system("cls");
		CurrentMap->GetScreenPrinter()->PrintAllOnScrean();


	}
}
