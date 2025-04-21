#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/IRenderInterface.h"

class URenderer : public UObject
{
public:
	URenderer();
	virtual ~URenderer();

public:
	void RenderAll() const;
	inline void RegisterRenderTargets(IRenderInterface* InRenderInterface) { RenderTargets.Add(InRenderInterface); }

private:
	TArray<IRenderInterface*> RenderTargets;

private:
	void Render(IRenderInterface* InScreenPrintInterface) const;
};

