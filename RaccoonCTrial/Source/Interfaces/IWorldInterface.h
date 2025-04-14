#pragma once

class UWorld;

class IWorldInterface
{
public:
	virtual void SetWorld(UWorld* InWorld) = 0;
	virtual UWorld* GetWorld() = 0;
};

