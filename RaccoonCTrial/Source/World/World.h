#pragma once
#include "Core/DynamicArray.h"
#include "Interfaces/IRenderInterface.h"
#include "Rendering/Renderer.h"
#include "iostream"
#include "CollisionSystem.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"

using namespace std;

class UWorld : public UObject
{
public:
	UWorld(size_t InSizeX, size_t InSizeY) : SizeX(InSizeX), SizeY(InSizeY)
	{
		CollisionSystem = new UCollisionSystem();
		Printer = new URenderer();
		RenderInterfaces.Resize(SizeX);
		for (int i = 0; i < SizeX; i++)
		{
			RenderInterfaces[i].Reserve(SizeY);
		}
	}

private:
	TArray<TArray<IRenderInterface*>> RenderInterfaces;
	size_t SizeX;
	size_t SizeY;

	URenderer* Printer;

// Printer Section
public:
	inline const URenderer* GetScreenPrinter() { return Printer; };

// Spawn Section
public:
	template<typename T>
	T* SpawnActor(const FVector2& SpawnLocation)
	{
		static_assert(is_base_of<AActor, T>::value, "T must be derived from Actor");

		T* Target = new T();

		AActor* ActorTarget = dynamic_cast<AActor*>(Target);
		ActorTarget->SetWorld(this);

		UStaticMeshComponent* StaticMeshComponent = ActorTarget->GetComponentByClass<UStaticMeshComponent>();
		if (StaticMeshComponent)
		{
			IRenderInterface* RenderInterface = dynamic_cast<IRenderInterface*>(StaticMeshComponent);
			if (RenderInterface)
			{
				RenderInterface->SetLocation(SpawnLocation);
				if (Printer)
				{
					Printer->GetScreenPrints().Add(RenderInterface);
				}
				RenderInterfaces[SpawnLocation.X][SpawnLocation.Y] = RenderInterface;
				return Target;
			}
		}
	}

// Move Section
public:
	inline bool IsEmpty(int InX, int InY) { return (RenderInterfaces[InX][InY] == nullptr); }
	void MoveRenderTarger(FVector2 Target, FVector2 Destination);

// Tick Section
public:
	void Tick(float DeltaSeconds);

// Collison Section
private:
	UCollisionSystem* CollisionSystem;

};

