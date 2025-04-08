#pragma once

#include "vector"

using namespace std;
class LotteryGame
{
public:
	LotteryGame();
	const int MinNum = 1;
	const int MaxNum = 45;

	const vector<int> GetAnswerBalls();

	void Play();

private:
	vector<int> Balls;

	void SwapBall(int& InRef0, int& InRef1);
	void Suffle(int SuffleCount = 100);

	const int GetBall();

	void ResetGame();
};

