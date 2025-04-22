#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"

class UPrimitiveComponent;

class URenderer : public UObject
{
public:
	URenderer();
	virtual ~URenderer();

public:
	void RenderAll() const;
	inline void RegisterVisiblePrimitiveComponent(UPrimitiveComponent* PrimitiveComponent) { VisiblePrimitiveComponents.Add(PrimitiveComponent); }

private:
	TArray<UPrimitiveComponent*> VisiblePrimitiveComponents;

private:
	void Render(UPrimitiveComponent* InPrimitiveComponent) const;
};

