#pragma once
#include "DynamicArray.h"
#include "IScreenPrintInterface.h"
#include "ScreenPrinter.h"
#include "iostream"

using namespace std;

class Map
{
public:
	Map(size_t InSizeX, size_t InSizeY) : SizeX(InSizeX), SizeY(InSizeY)
	{
		Printer = new ScreenPrinter();
		ScreenPrintInterfaces.Reserve(SizeX);
		for (int i = 0; i < SizeX; i++)
		{
			ScreenPrintInterfaces[i].Reserve(SizeY);
		}
	}

private:
	DynamicArray<DynamicArray<IScreenPrintInterface*>> ScreenPrintInterfaces;
	size_t SizeX;
	size_t SizeY;

	ScreenPrinter* Printer;

// Printer Section
public:
	inline const ScreenPrinter* GetScreenPrinter() { return Printer; };

// Spawn Section
public:
	template<typename T>
	T* SpawnScreenPrintTarget(const Vector2& SpawnLocation)
	{
		T* Target = new T();
		IScreenPrintInterface* ScreenPrintInterface = static_cast<IScreenPrintInterface*>(Target);
		if (ScreenPrintInterface)
		{
			ScreenPrintInterface->SetLocation(SpawnLocation);
			if (Printer)
			{
				Printer->GetScreenPrints().PushBack(ScreenPrintInterface);
			}
			ScreenPrintInterfaces[SpawnLocation.X][SpawnLocation.Y] = ScreenPrintInterface;
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
	inline bool IsEmpty(int InX, int InY) { return (ScreenPrintInterfaces[InX][InY] == nullptr); }
	void MoveScreenPrintTarget(Vector2 Target, Vector2 Destination);
};

