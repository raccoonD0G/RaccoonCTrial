#pragma once
#include "Actor.h"

class Character : public Actor
{
public:
    Character() { ; }

public:
    virtual string GetScreenString() override;
};

