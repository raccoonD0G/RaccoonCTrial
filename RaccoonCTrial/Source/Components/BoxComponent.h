#pragma once
#include "CoreMinimal.h"
#include "Components/ShapeComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/CollisionProfile.h"
#include "functional"

class UBoxComponent : public UShapeComponent
{
public:
	UBoxComponent();
	~UBoxComponent();

public:
	virtual void TickComponent(float DeltaTime) override;

private:
	FBox BoundingBox;

public:
	void SetBoxSize(const FVector2D& InSize);
	inline const FBox& GetBoundingBox() const { return BoundingBox; }

// Overlap Section
public:
	virtual bool ShouldOverlap(UPrimitiveComponent* Other) const override;

	virtual bool ShouldBlock(UPrimitiveComponent* Other) const override;

};

