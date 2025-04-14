#pragma once
#include "Character/Character.h"

using namespace std;

class APlayer : public ACharacter
{
public:
	APlayer();

// Move Section
public:
	void Move(FVector2 Destination);

};

