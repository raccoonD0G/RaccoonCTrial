#include "iostream"
#include "LotteryGame.h"
#include "DynamicArray.h"

using namespace std;

void TestLottery()
{
	LotteryGame* Game = new LotteryGame();

	Game->Play();
	Game->Play();
	Game->Play();
	Game->Play();

}


int main()
{
	DynamicArray<int> Arr;

	for (int i = 0; i < 10; i++)
	{
		Arr.PushBack((i + 1) * 3);
		cout << Arr.GetSize() << endl;
		cout << Arr.GetMemSize() << endl << endl;
	}
	
	for (int i = 10; i < 20; i++)
	{
		Arr.PushBack((i + 1) * 4);
		cout << Arr.GetSize() << endl;
		cout << Arr.GetMemSize() << endl << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << Arr[i] << ", ";
	}

}
