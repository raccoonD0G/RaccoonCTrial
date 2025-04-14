#pragma once

#include "/GitHub/RaccoonCTrial/RaccoonCTrial/UnorderedSet/UnorderedSet.h"
#include "string"

using namespace std;

class RandomBallBox
{

public:
	RandomBallBox();

private:
	int BallCount;
	int MinNum;
	int MaxNum;
	UnorderedSet<int> Remainingballs;
	UnorderedSet<int> PickedBalls;

public:
	string PickBall();

private:
	void AddBall(int MinNum, int MaxNum);
};

