#pragma once
#include "GameFramework/Actor.h"
#include "Interfaces/IFightInterface.h"


class ACharacter : public AActor, public IFightInterface
{
public:
    ACharacter();

public:
    virtual void GetDamaged(IFightInterface* Other) override;
    virtual void DoAttack(IFightInterface* Target) override;
};

