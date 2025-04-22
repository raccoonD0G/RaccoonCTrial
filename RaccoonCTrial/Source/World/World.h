#pragma once
#include "CoreMinimal.h"
#include "Rendering/Renderer.h"
#include "PhysicsInterfaceDeclaresCore.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

class UWorld : public UObject
{
public:
	UWorld();
	virtual ~UWorld();

public:
	void BeginPlay();

public:
	inline const TArray<AActor*>& GetAllActors() { return Actors; }

private:
	TArray<AActor*> Actors;

// Printer Section
public:
	inline const URenderer& GetRenderer() const { return *Renderer; };

private:
	URenderer* Renderer;

// Spawn Section
public:
	template<typename T>
	T* SpawnActor(const FVector2D& SpawnLocation)
	{
		static_assert(std::is_base_of<AActor, T>::value, "T must be derived from Actor");

		T* Target = new T();

		AActor* ActorTarget = dynamic_cast<AActor*>(Target);
		ActorTarget->SetWorld(this);
		ActorTarget->SetActorLocation(SpawnLocation);
		Actors.Add(ActorTarget);

		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ActorTarget->GetComponents<UPrimitiveComponent>(PrimitiveComponents);
		for (int i = 0; i < PrimitiveComponents.Num(); i++)
		{
			if (PrimitiveComponents[i]->IsVisible())
			{
				if (Renderer)
				{
					Renderer->RegisterVisiblePrimitiveComponent(PrimitiveComponents[i]);
				}
			}
		}

		for (int i = 0; i < PrimitiveComponents.Num(); i++)
		{
			if (PrimitiveComponents[i])
			{
				if (PhysScene)
				{
					PhysScene->RegisterPrimitiveComponent(PrimitiveComponents[i]);
				}
			}
		}

		ActorTarget->PostInitializeComponents();

		return Target;
	}

// Tick Section
public:
	void Tick(float DeltaSeconds);

// Collison Section
private:
	FPhysScene* PhysScene;
};

