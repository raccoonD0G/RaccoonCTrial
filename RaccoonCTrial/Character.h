#pragma once
#include "IScreenPrintInterface.h"

class Character : public IScreenPrintInterface
{
public:
    Character() : CurrentLocation(Vector2()) { ; }
protected:
    Vector2 CurrentLocation;

public:
    virtual Vector2 GetLocation() override;
    virtual void SetLocation(Vector2 NewLocation) override;
};

