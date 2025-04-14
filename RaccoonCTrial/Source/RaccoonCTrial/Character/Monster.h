#pragma once
#include "Character/Character.h"
#include "string"

using namespace std;
class AMonster : public ACharacter
{
public:
	AMonster();

// AI Section
public:
	void RandomMove();
};

