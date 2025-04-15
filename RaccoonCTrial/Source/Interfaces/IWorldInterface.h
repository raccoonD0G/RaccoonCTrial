#pragma once

class UWorld;

class IWorldInterface
{
public:
	virtual ~IWorldInterface() { ; }
	virtual void SetWorld(UWorld* InWorld) = 0;
	virtual UWorld* GetWorld() = 0;
};

