#pragma once
#include "Interfaces/IRenderInterface.h"
#include "Core/Container/DynamicArray.h"
#include "Core/Object.h"

class URenderer : public UObject
{
public:
	URenderer();
	~URenderer();

private:
	TArray<IRenderInterface*> RenderTargets;

public:
	void RenderAll() const;
	inline void RegisterRenderTargets(IRenderInterface* InRenderInterface) { RenderTargets.Add(InRenderInterface); }

private:
	void Render(IRenderInterface* InScreenPrintInterface) const;
};

