#pragma once
class IWorldServiceInterface
{
public:
    virtual void BeginPlay() = 0;
    virtual void Tick(float DeltaSeconds) = 0;
};

