#pragma once
#include "Actor.h"

class ACharacter : public AActor
{
public:
    ACharacter() { ; }

public:
    virtual string GetScreenString() override;
};

