#include "CardGameTable.h"
#include "iostream"
using namespace std;

CardGameTable::CardGameTable()
{
	CurrentDeck = new CardDeck();
	CurrentDeck->Shuffle();
}

CardGameTable::~CardGameTable()
{
	delete CurrentDeck;
}

void CardGameTable::Play()
{
	Card ComputerCard[2];
	Card PlayerCard[2];

	ComputerCard[0] = CurrentDeck->Draw();
	ComputerCard[1] = CurrentDeck->Draw();

	PlayerCard[0] = CurrentDeck->Draw();
	PlayerCard[1] = CurrentDeck->Draw();

	cout << "ComputerCard : " << ComputerCard[0] << " + " << ComputerCard[1] << endl;

	cout << "PlayerCard : " << PlayerCard[0] << " + " << PlayerCard[1] << endl;

	int ComputerScore = ComputerCard[0].GetCurrentNum() + ComputerCard[1].GetCurrentNum() + 2;
	int PlayerScore = PlayerCard[0].GetCurrentNum() + PlayerCard[1].GetCurrentNum() + 2;

	if (PlayerScore > 21)
	{
		cout << "Computer Win (Player Bust)";
	}
	else if (ComputerScore > 21)
	{
		cout << "Player Win (Computer Bust)";
	}
	else if (PlayerScore > ComputerScore)
	{
		cout << "Player Win";
	}
	else if (PlayerScore < ComputerScore)
	{
		cout << "Computer Win";
	}
	else
	{
		cout << "Draw";
	}
}
