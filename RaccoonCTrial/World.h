#pragma once
#include "DynamicArray.h"
#include "IRenderInterface.h"
#include "Renderer.h"
#include "iostream"

using namespace std;

class UWorld
{
public:
	UWorld(size_t InSizeX, size_t InSizeY) : SizeX(InSizeX), SizeY(InSizeY)
	{
		Printer = new URenderer();
		RenderInterfaces.Reserve(SizeX);
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
	T* SpawnScreenPrintTarget(const FVector2& SpawnLocation)
	{
		T* Target = new T();
		IRenderInterface* RenderInterface = static_cast<IRenderInterface*>(Target);
		if (RenderInterface)
		{
			RenderInterface->SetLocation(SpawnLocation);
			if (Printer)
			{
				Printer->GetScreenPrints().PushBack(RenderInterface);
			}
			RenderInterfaces[SpawnLocation.X][SpawnLocation.Y] = RenderInterface;
			RenderInterface->SetOwningMap(this);
			return Target;
		}
		else
		{
			delete Target;
			Target = nullptr;
			return nullptr;
		}
	}

// Move Section
public:
	inline bool IsEmpty(int InX, int InY) { return (RenderInterfaces[InX][InY] == nullptr); }
	void MoveScreenPrintTarget(FVector2 Target, FVector2 Destination);
};

