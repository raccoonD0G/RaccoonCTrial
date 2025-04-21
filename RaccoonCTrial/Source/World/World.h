#pragma once
#include "CoreMinimal.h"
#include "Rendering/Renderer.h"
#include "CollisionSystem.h"
#include "GameFramework/Actor.h"
#include "Components/MeshComponent.h"
#include "Components/ShapeComponent.h"

class UWorld : public UObject
{
public:
	UWorld();
	~UWorld();

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

		TArray<UMeshComponent*> MeshComponents;
		ActorTarget->GetComponents<UMeshComponent>(MeshComponents);
		for (int i = 0; i < MeshComponents.Num(); i++)
		{
			IRenderInterface* RenderInterface = dynamic_cast<IRenderInterface*>(MeshComponents[i]);
			if (RenderInterface)
			{
				if (Renderer)
				{
					Renderer->RegisterRenderTargets(RenderInterface);
				}
			}
		}

		TArray<UShapeComponent*> BoxComponents;
		ActorTarget->GetComponents<UShapeComponent>(BoxComponents);
		for (int i = 0; i < BoxComponents.Num(); i++)
		{
			ICollisionInterface* CollisionInterface = dynamic_cast<ICollisionInterface*>(BoxComponents[i]);
			if (CollisionInterface)
			{
				if (CollisionSystem)
				{
					CollisionSystem->RegisterCollisionTarget(CollisionInterface);
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
	UCollisionSystem* CollisionSystem;
};

