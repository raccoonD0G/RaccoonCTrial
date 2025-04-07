#include "CardDeck.h"
#include "random"
#include "stdlib.h"
#include "vector"

using namespace std;

ostream& operator<<(ostream& OS, const Card& P)
{
	string str = string();
	str.append("Suit : ");
	switch (P.GetCurrentSuit())
	{
	case Suit::Spades:
		str.append("Spades");
		break;
	case Suit::Hearts:
		str.append("Hearts");
		break;
	case Suit::Clubs:
		str.append("Clubs");
		break;
	case Suit::Diamonds:
		str.append("Diamonds");
		break;
	default:
		break;
	}

	str.append(", Number : ");
	switch (P.GetCurrentNum())
	{
	case 0:
		str.append("A");
		break;
	case 11:
		str.append("J");
		break;
	case 12:
		str.append("Q");
		break;
	case 13:
		str.append("K");
		break;
	default:
		str.append(to_string(P.GetCurrentNum()));
		break;
	}

	OS << str;
	return OS;
}


CardDeck::CardDeck()
{
	Deck.reserve(52);
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Deck.push_back(Card(static_cast<Suit>(j), i));
		}
	}
}

const Card CardDeck::Draw()
{
	Card card = Deck.back();
	Deck.pop_back();
	return card;
}

void CardDeck::Shuffle(int ShuffleCount)
{
	random_device Rd;
	mt19937 Gen(Rd());

	uniform_int_distribution<> Dist(0, Deck.size() - 1);

	for (int i = 0; i < ShuffleCount; i++)
	{
		int RandIndex0 = Dist(Gen);
		int RandIndex1 = Dist(Gen);

		SwapCard(RandIndex0, RandIndex1);
	}
}
