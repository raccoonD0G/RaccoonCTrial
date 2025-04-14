#pragma once
#include "IScreenPrintInterface.h"
#include "DynamicArray.h"

class ScreenPrinter
{
private:
	DynamicArray<IScreenPrintInterface*> ScreenPrints;

	void PrintOnScreen(IScreenPrintInterface* InScreenPrintInterface) const;

public:
	void PrintAllOnScrean() const;
	inline DynamicArray<IScreenPrintInterface*>& GetScreenPrints() { return ScreenPrints; }
};

