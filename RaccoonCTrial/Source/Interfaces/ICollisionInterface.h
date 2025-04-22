#pragma once

enum class ECollisionChannel;
enum class ECollisionResponse;
struct FCollisionProfileName;
class UPrimitiveComponent;

class ICollisionInterface
{
public:
	virtual ~ICollisionInterface() { ; }

	virtual const FCollisionProfileName& GetCollisionProfileName() const = 0;

	virtual void SetCollisionProfileName(const FCollisionProfileName& ProfileName) = 0;

	virtual bool ShouldOverlap(UPrimitiveComponent* Other) const = 0;
	virtual void OnOverlap(UPrimitiveComponent* Other) = 0;

	virtual bool ShouldBlock(UPrimitiveComponent* Other) const = 0;
	virtual void OnBlock(UPrimitiveComponent* Other) = 0;

	virtual void SetCollisionChannel(ECollisionChannel InChannel) = 0;
	virtual ECollisionChannel GetCollisionChannel() const = 0;

	virtual void SetCollisionResponseToChannel(ECollisionChannel TargetChannel, ECollisionResponse Response) = 0;
	virtual ECollisionResponse GetResponseToChannel(ECollisionChannel TargetChannel) const = 0;
};

