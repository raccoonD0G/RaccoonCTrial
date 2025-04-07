#include "UnorderedSet.h"

using namespace std;

#pragma once
class RandomBallBox
{
	UnorderedSet<int> Remainingballs;
	UnorderedSet<int> PickedBalls;

public:
	RandomBallBox();

	int PickBall();
};

