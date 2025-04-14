#pragma once
#include "IScreenPrintInterface.h"
#include "Map.h"

class Actor : public IScreenPrintInterface
{
protected:
    Vector2 CurrentLocation;
    Map* OwningMap;

public:
    virtual string GetScreenString() override;
    virtual Vector2 GetLocation() override;
    virtual void SetLocation(Vector2 NewLocation) override;
    virtual void SetOwningMap(Map* InOwningMap) override;
};

