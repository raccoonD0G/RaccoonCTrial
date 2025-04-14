#pragma once
#include "Interfaces/IRenderInterface.h"
#include "Core/DynamicArray.h"
#include "Core/Object.h"

class URenderer : public UObject
{
private:
	TArray<IRenderInterface*> RenderTargets;

	void PrintOnScreen(IRenderInterface* InScreenPrintInterface) const;

public:
	void PrintAllOnScreen() const;
	inline TArray<IRenderInterface*>& GetScreenPrints() { return RenderTargets; }
};

