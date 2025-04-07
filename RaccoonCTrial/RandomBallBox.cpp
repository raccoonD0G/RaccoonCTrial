#include "RandomBallBox.h"

RandomBallBox::RandomBallBox()
{
	for (int i = 1; i < 53; i++)
	{
		Remainingballs.Add(i);
	}
}

int RandomBallBox::PickBall()
{
	int RadomIndex = Remainingballs.GetRandomIndex();
	Remainingballs.Remove(RadomIndex);
	return RadomIndex;
}
