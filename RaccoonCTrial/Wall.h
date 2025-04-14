#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall() { ; }

public:
	virtual string GetScreenString() override;
};

