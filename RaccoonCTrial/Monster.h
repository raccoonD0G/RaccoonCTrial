#pragma once
#include "Character.h"
#include "string"

using namespace std;
class Monster : public Character
{

// Screen Print Section
public:
	virtual string GetScreenString() override;
};

