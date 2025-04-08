#include "iostream"
#include "vector"
#include "random"

#include "LotteryGame.h"

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
	TestLottery();
}
