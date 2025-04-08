#include "iostream"
#include "conio.h"
#include "Player.h"
#include "Monster.h"
#include "IScreenPrintInterface.h"
#include "ScreenPrinter.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
	ScreenPrinter* Printer = new ScreenPrinter();

	Player* Player0 = Printer->SpawnScreenPrintTarget<Player>(Vector2(1, 1));





	Monster* Monster0 = Printer->SpawnScreenPrintTarget<Monster>(Vector2(1, 2));

	Monster* Monster1 = Printer->SpawnScreenPrintTarget<Monster>(Vector2(4, 5));

	Monster* Monster2 = Printer->SpawnScreenPrintTarget<Monster>(Vector2(1, 7));

	Monster* Monster3 = Printer->SpawnScreenPrintTarget<Monster>(Vector2(3, 8));

	system("cls");
	Printer->PrintAllOnScrean();

	while (true)
	{
		
		
		if (_kbhit())
		{
			char Input = _getch();
			switch (Input)
			{
			case 'w':
				Player0->SetLocation(Vector2(Player0->GetLocation().X, Player0->GetLocation().Y - 1));
				break;
			case 'a':
				Player0->SetLocation(Vector2(Player0->GetLocation().X - 1, Player0->GetLocation().Y));
				break;
			case 's':
				Player0->SetLocation(Vector2(Player0->GetLocation().X, Player0->GetLocation().Y + 1));
				break;
			case 'd':
				Player0->SetLocation(Vector2(Player0->GetLocation().X + 1, Player0->GetLocation().Y));
				break;
			}

			system("cls");
			Printer->PrintAllOnScrean();
		}
	}
}
