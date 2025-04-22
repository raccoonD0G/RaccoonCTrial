#include "World.h"

UWorld::UWorld()
{
	PhysScene = new FPhysScene();
	Renderer = new URenderer();

	FCollisionResponseContainer PlayerProfile(ECollisionChannel::Player);
	PlayerProfile.SetResponseToChannel(ECollisionChannel::Monster, ECollisionResponse::Block);
	PlayerProfile.SetResponseToChannel(ECollisionChannel::Wall, ECollisionResponse::Block);
	UCollisionProfile::Get().AddProfile("Player", PlayerProfile);

	FCollisionResponseContainer MonsterProfile(ECollisionChannel::Monster);
	MonsterProfile.SetResponseToChannel(ECollisionChannel::Player, ECollisionResponse::Block);
	MonsterProfile.SetResponseToChannel(ECollisionChannel::Wall, ECollisionResponse::Block);
	UCollisionProfile::Get().AddProfile("Monster", MonsterProfile);

	FCollisionResponseContainer WallProfile(ECollisionChannel::Wall);
	WallProfile.SetResponseToChannel(ECollisionChannel::Monster, ECollisionResponse::Block);
	WallProfile.SetResponseToChannel(ECollisionChannel::Player, ECollisionResponse::Block);
	UCollisionProfile::Get().AddProfile("Wall", WallProfile);

	FCollisionResponseContainer MeshProfile(ECollisionChannel::Mesh);
	MeshProfile.SetResponseToChannel(ECollisionChannel::Monster, ECollisionResponse::Ignore);
	MeshProfile.SetResponseToChannel(ECollisionChannel::Player, ECollisionResponse::Ignore);
	MeshProfile.SetResponseToChannel(ECollisionChannel::Wall, ECollisionResponse::Ignore);
	MeshProfile.SetResponseToChannel(ECollisionChannel::Mesh, ECollisionResponse::Ignore);
	UCollisionProfile::Get().AddProfile("Mesh", MeshProfile);
}

UWorld::~UWorld()
{
	for (int i = 0; i < Actors.Num(); i++)
	{
		delete Actors[i];
	}

	delete Renderer;
	delete PhysScene;
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

	PhysScene->PerformCollisionChecks();
}
