#pragma once
#include "IScreenPrintInterface.h"

class Wall : public IScreenPrintInterface
{
public:
	Wall() { ; }

private:
	Vector2 CurrentLocation;

public:
	virtual string GetScreenString() override;
	virtual Vector2 GetLocation() override;
	virtual void SetLocation(Vector2 NewLocation) override;
};

