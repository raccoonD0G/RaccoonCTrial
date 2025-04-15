#pragma once

class AActor;
enum class ECollisionChannel;
enum class ECollisionResponse;

class ICollisionInterface
{
public:
	virtual ~ICollisionInterface() { ; }

	virtual AActor* GetSelfActor() const = 0;

	virtual bool CheckOverlap(ICollisionInterface* InCollisionInterface) const = 0;
	virtual void OnOverlap(AActor* OtherActor) = 0;

	virtual bool ShouldBlock(ICollisionInterface* Other) const = 0; 
	virtual void OnBlock(AActor* OtherActor) = 0;

	virtual void SetCollisionChannel(ECollisionChannel InChannel) = 0;
	virtual ECollisionChannel GetCollisionChannel() const = 0;

	virtual void SetCollisionResponseToChannel(ECollisionChannel TargetChannel, ECollisionResponse Response) = 0;
	virtual ECollisionResponse GetResponseToChannel(ECollisionChannel TargetChannel) const = 0;
};

