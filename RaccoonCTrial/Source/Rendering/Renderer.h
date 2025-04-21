#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/IRenderInterface.h"

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

