#pragma once
#include "IRenderInterface.h"
#include "DynamicArray.h"

class URenderer
{
private:
	TArray<IRenderInterface*> RenderTargets;

	void PrintOnScreen(IRenderInterface* InScreenPrintInterface) const;

public:
	void PrintAllOnScrean() const;
	inline TArray<IRenderInterface*>& GetScreenPrints() { return RenderTargets; }
};

