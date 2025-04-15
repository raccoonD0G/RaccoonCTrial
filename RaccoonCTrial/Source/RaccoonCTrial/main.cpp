#include "iostream"
#include "conio.h"
#include "windows.h"
#include "World/World.h"
#include "RaccoonCTrial/Character/Player.h"
#include "RaccoonCTrial/Character/Monster.h"
#include "RaccoonCTrial/Gimmick/Wall.h"
#include "RaccoonCTrial/Gimmick/EndPoint.h"
#include "Core/Container/DynamicArray.h"

int main()
{
	// Begin Play
	UWorld* CurrentWorld = new UWorld();

	APlayer* Player0 = CurrentWorld->SpawnActor<APlayer>(FVector2(4, 4));
	
	CurrentWorld->SpawnActor<AMonster>(FVector2(1, 7));
	CurrentWorld->SpawnActor<AMonster>(FVector2(3, 8));
	
	CurrentWorld->SpawnActor<AEndPoint>(FVector2(8, 8));
	
	
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
	
	CurrentWorld->BeginPlay();

	system("cls");
	CurrentWorld->GetRenderer().RenderAll();

	bool bShouldExit = false;
	
	while (!bShouldExit)
	{
		// Input
		if (_kbhit())
		{
			char Input = _getch();
			
			FVector2 TargetVector = Player0->GetActorLocation();
			switch (Input)
			{
			case 'w':
				TargetVector = FVector2(Player0->GetActorLocation().X, Player0->GetActorLocation().Y - 1);
				break;
			case 'a':
				TargetVector = FVector2(Player0->GetActorLocation().X - 1, Player0->GetActorLocation().Y);
				break;
			case 's':
				TargetVector = FVector2(Player0->GetActorLocation().X, Player0->GetActorLocation().Y + 1);
				break;
			case 'd':
				TargetVector = FVector2(Player0->GetActorLocation().X + 1, Player0->GetActorLocation().Y);
				break;
			case 27:
				bShouldExit = true;
				break;
			}
			
			Player0->SetControlledLocation(TargetVector);

		}

		// Tick
		CurrentWorld->Tick(200);

		// Render
		system("cls");
		CurrentWorld->GetRenderer().RenderAll();

		Sleep(200);

	}

	delete CurrentWorld;
}
