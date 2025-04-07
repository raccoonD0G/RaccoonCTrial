#include "RandomBallBox.h"
#include "iostream"
#include "string"
#include "random"

RandomBallBox::RandomBallBox()
{
	BallCount = 0;
	MinNum = 1;
	MaxNum = 52;
	AddBall(MinNum, MaxNum);
}

/// <summary>
/// Return ball num as string, return No Ball if there is no ball.
/// </summary>
/// <returns></returns>
string RandomBallBox::PickBall()
{
	if (BallCount == 0)
	{
		return "No Ball";
	}

	random_device Rd;
	mt19937 Gen(Rd());

	uniform_int_distribution<> Dist(MinNum, MaxNum);

	int RandomValue = Dist(Gen);

	while (!Remainingballs.Contain(RandomValue))
	{
		RandomValue = Dist(Gen);
	}

	Remainingballs.Remove(RandomValue);
	PickedBalls.Add(RandomValue);

	BallCount--;

	return to_string(RandomValue);
}

/// <summary>
/// Add all balls between MinNum(included) and MaxNum(included).
/// </summary>
/// <param name="MinNum">MinNum(included)</param>
/// <param name="MaxNum">MaxNum(included)</param>
void RandomBallBox::AddBall(int MinNum, int MaxNum)
{
	for (int Index = MinNum; Index <= MaxNum; Index++)
	{
		Remainingballs.Add(Index);
		BallCount++;
	}
}