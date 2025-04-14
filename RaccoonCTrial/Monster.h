#pragma once
#include "Character.h"
#include "string"

using namespace std;
class AMonster : public ACharacter
{

// Screen Print Section
public:
	virtual string GetScreenString() override;

// AI Section
public:
	void RandomMove();
};

