#include "World.h"

UWorld::UWorld()
{
	CollisionSystem = new UCollisionSystem();
	Renderer = new URenderer();
}

UWorld::~UWorld()
{
	for (int i = 0; i < Actors.Num(); i++)
	{
		delete Actors[i];
	}

	delete Renderer;
	delete CollisionSystem;
}

void UWorld::BeginPlay()
{
	for (int i = 0; i < Actors.Num(); i++)
	{
		Actors[i]->BeginPlay();
	}
}

void UWorld::Tick(float DeltaSeconds)
{
	for (int i = 0; i < Actors.Num(); i++)
	{
		Actors[i]->Tick(DeltaSeconds);
	}

	CollisionSystem->PerformCollisionChecks();
}
