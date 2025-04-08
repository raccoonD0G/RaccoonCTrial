#pragma once
#include "IScreenPrintInterface.h"
#include "DynamicArray.h"

class ScreenPrinter
{
private:
	DynamicArray<IScreenPrintInterface*> ScreenPrints;

	void PrintOnScreen(IScreenPrintInterface* InScreenPrintInterface);

public:
	template<typename T>
	T* SpawnScreenPrintTarget(const Vector2& SpawnLocation)
	{
		T* Target = new T();
		IScreenPrintInterface* ScreenPrintInterface = static_cast<IScreenPrintInterface*>(Target);
		if (ScreenPrintInterface)
		{
			ScreenPrintInterface->SetLocation(SpawnLocation);
			ScreenPrints.PushBack(ScreenPrintInterface);
			return Target;
		}
		else
		{
			delete Target;
			Target = nullptr;
			return nullptr;
		}
	}

	void PrintAllOnScrean();
};

