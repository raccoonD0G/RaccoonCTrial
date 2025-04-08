#include "LotteryGame.h"
#include "random"
#include "iostream"
#include "UnorderedSet/UnorderedSet.h"

using namespace std;

LotteryGame::LotteryGame()
{
	ResetGame();
}

const vector<int> LotteryGame::GetAnswerBalls()
{
	vector<int> AnswerBalls;
	AnswerBalls.reserve(6);

	for (int i = 0; i < 6; i++)
	{
		AnswerBalls.push_back(Balls[i]);
	}

	return AnswerBalls;
}

const int LotteryGame::GetBall()
{
	if (Balls.size() == 0)
	{
		cout << "No More Ball";
		return -1;
	}
	int OupBall = Balls.back();
	Balls.pop_back();
	return OupBall;
}

void LotteryGame::SwapBall(int& InRef0, int& InRef1)
{
	int Temp = InRef0;
	InRef0 = InRef1;
	InRef1 = Temp;
}

void LotteryGame::Suffle(int SuffleCount)
{
	random_device Rd;
	mt19937 Gen(Rd());

	uniform_int_distribution<> Dist(MinNum - 1, MaxNum - 1);

	for (int i = 0; i < SuffleCount; i++)
	{
		int RandomValue0 = Dist(Gen);
		int RandomValue1 = Dist(Gen);

		this->SwapBall(Balls[RandomValue0], Balls[RandomValue1]);
	}
}

void LotteryGame::Play()
{
	int MyNumsTemp[6] = { 0, };

	cout << "1부터 45까지의 숫자 중 6개를 입력하세요:\n";

	UnorderedSet<int> PickedNums;

	for (int i = 0; i < 6; i++)
	{
		int NumBuffer = 0;
		cout << i + 1 << "번째 번호: ";
		cin >> NumBuffer;

		
		if (NumBuffer < 1 || NumBuffer > 45)
		{
			cout << "잘못된 입력입니다. 1부터 45 사이의 숫자를 입력해주세요.\n";
			i++;
		}

		if (!PickedNums.Contain(NumBuffer))
		{
			PickedNums.Add(NumBuffer);
			MyNumsTemp[i] = NumBuffer;
		}
		else
		{
			cout << "이미 골랐던 숫자입니다. 다시 고르세요.\n";
			i++;
		}
	}

	cout << "입력하신 번호는: ";
	for (int i = 0; i < 6; i++)
	{
		cout << MyNumsTemp[i] << " ";
	}

	cout << endl;
	const vector<int> AnswerBalls = this->GetAnswerBalls();
	int CorrectCount = 0;

	cout << "정답은 ";
	for (int i = 0; i < 6; i++)
	{
		cout << AnswerBalls[i] << " ";
		if (PickedNums.Contain(AnswerBalls[i]))
		{
			CorrectCount++;
		}
	}

	cout << endl;

	switch (CorrectCount)
	{
	case 6:
		cout << "6개 맞췄습니다" << endl;
		break;
	case 5:
		cout << "5개 맞췄습니다" << endl;
		break;
	case 4:
		cout << "4개 맞췄습니다" << endl;
		break;
	case 3:
		cout << "3개 맞췄습니다" << endl;
		break;
	case 2:
		cout << "2개 맞췄습니다" << endl;
		break;
	case 1:
		cout << "1개 맞췄습니다" << endl;
		break;
	case 0:
		cout << "꽝입니다" << endl;
		break;
	}

	cout << "공을 다시 넣고 섞습니다.\n";
	ResetGame();
}

void LotteryGame::ResetGame()
{
	Balls.clear();
	Balls.reserve(MaxNum - MinNum + 1);
	for (int i = MinNum; i < MaxNum + 1; i++)
	{
		Balls.push_back(i);
	}
	Suffle();
}

