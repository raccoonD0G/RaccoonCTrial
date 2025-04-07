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
	vector<Card> ComputerCard;
	vector<Card> PlayerCard;

	DrawCardFromDeck(ComputerCard);
	DrawCardFromDeck(ComputerCard);

	DrawCardFromDeck(PlayerCard);
	DrawCardFromDeck(PlayerCard);

	cout << "ComputerCard : " << endl << ComputerCard[0] << endl << ComputerCard[1] << endl;

	cout << "PlayerCard : " << endl << PlayerCard[0] << endl << PlayerCard[1] << endl;

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

void CardGameTable::DrawCardFromDeck(vector<Card>& TargetHand)
{
	if (CurrentDeck->LeftCardCount() > 0)
	{
		TargetHand.push_back(CurrentDeck->Draw());
	}
}
