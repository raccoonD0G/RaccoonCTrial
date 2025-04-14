#include "iostream"
#include "conio.h"
#include "Player.h"
#include "Monster.h"
#include "Renderer.h"
#include "Wall.h"
#include "World.h"
#include "EndPoint.h"
#include "windows.h"


using namespace std;

int main()
{
	// Begin Play
	UWorld* CurrentWorld = new UWorld(10, 10);

	APlayer* Player0 = CurrentWorld->SpawnActor<APlayer>(FVector2(1, 1));
	AMonster* Monster0 = CurrentWorld->SpawnActor<AMonster>(FVector2(1, 2));
	AMonster* Monster1 = CurrentWorld->SpawnActor<AMonster>(FVector2(4, 5));
	AMonster* Monster2 = CurrentWorld->SpawnActor<AMonster>(FVector2(1, 7));
	AMonster* Monster3 = CurrentWorld->SpawnActor<AMonster>(FVector2(3, 8));

	AEndPoint* EndPoint = CurrentWorld->SpawnActor<AEndPoint>(FVector2(8, 8));
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9)
			{
				CurrentWorld->SpawnActor<AWall>(FVector2(i, j));
			}

			if (i >= 1 && i <= 8)
			{
				if (j == 0 || j == 9)
				{
					CurrentWorld->SpawnActor<AWall>(FVector2(i, j));
				}
			}
		}
	}



	system("cls");
	CurrentWorld->GetScreenPrinter()->PrintAllOnScrean();

	while (true)
	{
		// Input
		if (_kbhit())
		{
			char Input = _getch();
			
			FVector2 TargetVector;
			switch (Input)
			{
			case 'w':
				TargetVector = FVector2(Player0->GetLocation().X, Player0->GetLocation().Y - 1);
				break;
			case 'a':
				TargetVector = FVector2(Player0->GetLocation().X - 1, Player0->GetLocation().Y);
				break;
			case 's':
				TargetVector = FVector2(Player0->GetLocation().X, Player0->GetLocation().Y + 1);
				break;
			case 'd':
				TargetVector = FVector2(Player0->GetLocation().X + 1, Player0->GetLocation().Y);
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
		CurrentWorld->GetScreenPrinter()->PrintAllOnScrean();

		Sleep(100);

	}
}
