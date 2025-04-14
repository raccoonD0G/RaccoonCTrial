#include "CardGameTable.h"
#include "CardDeck.h"
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
	CurrentDeck = nullptr;
}

void CardGameTable::Play()
{
	vector<Card> ComputerCard;
	vector<Card> PlayerCard;

	DrawCardFromDeck(ComputerCard);
	DrawCardFromDeck(ComputerCard);

	DrawCardFromDeck(PlayerCard);
	DrawCardFromDeck(PlayerCard);

	cout << "ComputerCard : " << endl << ComputerCard[0].GetAsString() << endl << ComputerCard[1].GetAsString() << endl;

	cout << "PlayerCard : " << endl << PlayerCard[0].GetAsString() << endl << PlayerCard[1].GetAsString() << endl;

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
	else
	{
		cout << "No More Card In Deck";
	}
}
