#define NOMINMAX
#include "windows.h"

#include "iostream"
#include "conio.h"
#include "cstdlib"
#include "ctime"
#include "World/World.h"
#include "RaccoonCTrial/Character/Player.h"
#include "RaccoonCTrial/Gimmick/Wall.h"
#include "RaccoonCTrial/Gimmick/EndPoint.h"
#include "Character/Boar.h"
#include "Character/Slime.h"
#include "Character/Goblin.h"

int main()
{
	UWorld* CurrentWorld = new UWorld();

	APlayer* Player0 = CurrentWorld->SpawnActor<APlayer>(FVector2D(25, 12));

	
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 0 || i == 49 || j == 0 || j == 49)
			{
				CurrentWorld->SpawnActor<AWall>(FVector2D((float)i, (float)j));
			}
		}
	}

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int MonsterCount = 8 + (std::rand() % 8);

	TArray<FVector2D> UsedPositions;
	UsedPositions.Add(FVector2D(25, 12));

	for (int i = 0; i < MonsterCount; ++i)
	{
		FVector2D SpawnPos;

		float x = 1 + std::rand() % 48;
		float y = 1 + std::rand() % 48;
		SpawnPos = FVector2D(x, y);

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
			
			FVector2D TargetVector = Player0->GetActorLocation();
			switch (Input)
			{
			case 'w':
				TargetVector = FVector2D(Player0->GetActorLocation().X, Player0->GetActorLocation().Y - 1);
				break;
			case 'a':
				TargetVector = FVector2D(Player0->GetActorLocation().X - 1, Player0->GetActorLocation().Y);
				break;
			case 's':
				TargetVector = FVector2D(Player0->GetActorLocation().X, Player0->GetActorLocation().Y + 1);
				break;
			case 'd':
				TargetVector = FVector2D(Player0->GetActorLocation().X + 1, Player0->GetActorLocation().Y);
				break;
			case 27:
				bShouldExit = true;
				break;
			}
			
			Player0->SetControlledLocation(TargetVector);

		}

		// Tick
		CurrentWorld->Tick(0.0);

		// Render
		system("cls");
		CurrentWorld->GetRenderer().RenderAll();

	}

	delete CurrentWorld;
}
