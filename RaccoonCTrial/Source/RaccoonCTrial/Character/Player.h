#pragma once
#include "Character/Character.h"

using namespace std;

class APlayer : public ACharacter
{
public:
	APlayer() : ACharacter() { ; }

// Screen Print Section
public:
	virtual string GetScreenString() override;

// Move Section
public:
	void Move(FVector2 Destination);

};

