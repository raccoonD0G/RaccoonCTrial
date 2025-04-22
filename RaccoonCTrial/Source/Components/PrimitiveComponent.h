#pragma once
#include "SceneComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/EngineTypes.h"
#include "Interfaces/ICollisionInterface.h"
#include "Interfaces/IRenderInterface.h"
#include "string"

class UPrimitiveComponent : public USceneComponent, public ICollisionInterface, public IRenderInterface
{
public:
	UPrimitiveComponent();

public:
	virtual void TickComponent(float DeltaTime) override;

// Overlap Section;
public:
	using FOverlapDelegate = std::function<void(UPrimitiveComponent* Other)>;
	FOverlapDelegate OnOverlapDelegate;

	virtual bool ShouldOverlap(UPrimitiveComponent* Other) const override;
	virtual void OnOverlap(UPrimitiveComponent* Other) override;

// Block Section
public:
	using FBlockDelegate = std::function<void(UPrimitiveComponent* Other)>;
	FBlockDelegate OnBlockDelegate;

	virtual bool ShouldBlock(UPrimitiveComponent* Other) const override;
	virtual void OnBlock(UPrimitiveComponent* Other) override;

// Collision Section

public:
	virtual const FCollisionProfileName& GetCollisionProfileName() const override;

	virtual void SetCollisionProfileName(const FCollisionProfileName& ProfileName) override;

	virtual void SetCollisionChannel(ECollisionChannel InChannel) override;
	virtual ECollisionChannel GetCollisionChannel() const override;

	virtual void SetCollisionResponseToChannel(ECollisionChannel TargetChannel, ECollisionResponse Response) override;
	virtual ECollisionResponse GetResponseToChannel(ECollisionChannel TargetChannel) const override;

private:
	FCollisionProfileName CollisionProfile;
	ECollisionChannel CollisionChannel;
	FCollisionResponseContainer CollisionResponses;

private:
	FVector2D PreviousLocation;

// Visible Section
public:
	inline bool IsVisible() const { return bVisible; };
	inline void SetVisibility(bool bNewVisiblity) { bVisible = bNewVisiblity; };
	virtual std::string GetRenderString() override;
	virtual void SetRenderString(const std::string& NewScreenString) override;

private:
	bool bVisible;
	std::string ScreenString;
};

