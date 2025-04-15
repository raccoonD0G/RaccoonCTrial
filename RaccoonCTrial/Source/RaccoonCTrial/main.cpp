#include "iostream"
#include "conio.h"
#include "cstdlib"
#include "ctime"
#include "windows.h"
#include "World/World.h"
#include "RaccoonCTrial/Character/Player.h"
#include "RaccoonCTrial/Gimmick/Wall.h"
#include "RaccoonCTrial/Gimmick/EndPoint.h"
#include "Core/Container/DynamicArray.h"
#include "Character/Boar.h"
#include "Character/Slime.h"
#include "Character/Goblin.h"

int main()
{
	UWorld* CurrentWorld = new UWorld();

	APlayer* Player0 = CurrentWorld->SpawnActor<APlayer>(FVector2(25, 12));

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 0 || i == 49 || j == 0 || j == 49)
			{
				CurrentWorld->SpawnActor<AWall>(FVector2(i, j));
			}
		}
	}

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int MonsterCount = 8 + (std::rand() % 8);

	TArray<FVector2> UsedPositions;
	UsedPositions.Add(FVector2(25, 12));

	for (int i = 0; i < MonsterCount; ++i)
	{
		FVector2 SpawnPos;

		int x = 1 + std::rand() % 48;
		int y = 1 + std::rand() % 48;
		SpawnPos = FVector2(x, y);

		UsedPositions.Add(SpawnPos);

		int Type = std::rand() % 3;
		switch (Type)
		{
		case 0:
			CurrentWorld->SpawnActor<ASlime>(SpawnPos);
			break;
		case 1:
			CurrentWorld->SpawnActor<AGoblin>(SpawnPos);
			break;
		case 2:
			CurrentWorld->SpawnActor<ABoar>(SpawnPos);
			break;
		}
	}
	
	// Begin Play
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
		CurrentWorld->Tick(0.2);

		// Render
		system("cls");
		CurrentWorld->GetRenderer().RenderAll();

		Sleep(200);

	}

	delete CurrentWorld;
}
