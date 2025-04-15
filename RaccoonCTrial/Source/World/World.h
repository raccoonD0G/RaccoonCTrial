#pragma once
#include "Core/Container/DynamicArray.h"
#include "Interfaces/IRenderInterface.h"
#include "Rendering/Renderer.h"
#include "CollisionSystem.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

class UWorld : public UObject
{
public:
	UWorld();
	~UWorld();

public:
	void BeginPlay();

private:
	TArray<AActor*> Actors;

public:
	inline const TArray<AActor*>& GetAllActors() { return Actors; }

// Printer Section
public:
	inline const URenderer& GetRenderer() const { return *Renderer; };

private:
	URenderer* Renderer;

// Spawn Section
public:
	template<typename T>
	T* SpawnActor(const FVector2& SpawnLocation)
	{
		static_assert(std::is_base_of<AActor, T>::value, "T must be derived from Actor");

		T* Target = new T();

		AActor* ActorTarget = dynamic_cast<AActor*>(Target);
		ActorTarget->SetWorld(this);
		ActorTarget->SetActorLocation(SpawnLocation);
		Actors.Add(ActorTarget);

		UStaticMeshComponent* StaticMeshComponent = ActorTarget->GetComponentByClass<UStaticMeshComponent>();
		if (StaticMeshComponent)
		{
			IRenderInterface* RenderInterface = dynamic_cast<IRenderInterface*>(StaticMeshComponent);
			if (RenderInterface)
			{
				if (Renderer)
				{
					Renderer->RegisterRenderTargets(RenderInterface);
				}
			}
		}

		UBoxComponent* BoxComponent = ActorTarget->GetComponentByClass<UBoxComponent>();
		if (BoxComponent)
		{
			ICollisionInterface* CollisionInterface = dynamic_cast<ICollisionInterface*>(BoxComponent);
			if (CollisionInterface)
			{
				if (CollisionSystem)
				{
					CollisionSystem->Register(CollisionInterface);
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

