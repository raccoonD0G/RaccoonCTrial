#pragma once
#include "IRenderInterface.h"
#include "DynamicArray.h"
#include "Object.h"

class URenderer : public UObject
{
private:
	TArray<IRenderInterface*> RenderTargets;

	void PrintOnScreen(IRenderInterface* InScreenPrintInterface) const;

public:
	void PrintAllOnScreen() const;
	inline TArray<IRenderInterface*>& GetScreenPrints() { return RenderTargets; }
};

