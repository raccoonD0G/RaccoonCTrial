#pragma once
#include "Character.h"

using namespace std;

class Player : public Character
{
public:
	Player() : Character() { ; }

// Screen Print Section
public:
	virtual string GetScreenString() override;

};

