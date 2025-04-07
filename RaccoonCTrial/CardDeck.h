#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum class Suit;
struct Card;

enum class Suit
{
	Spades,
	Hearts,
	Clubs,
	Diamonds
};

struct Card
{
public:
	Card() : CurrentSuit(Suit::Spades), CurrentNum(-1) { ; }
	Card(Suit InSuit, int InNum) : CurrentSuit(InSuit), CurrentNum(InNum) { ; }

public:
	inline Suit GetCurrentSuit() const { return CurrentSuit;} 
	inline int GetCurrentNum() const { return CurrentNum; }

private:
	Suit CurrentSuit;
	int CurrentNum;
};

ostream& operator<<(ostream& OS, const Card& Card);

class CardDeck
{
public:
	CardDeck();

private:
	vector<Card> Deck;

// Util Section
public:
	inline int LeftCardCount() const { return Deck.size(); }

private:
	inline void SwapCard(int Index0, int Index1)
	{
		const Card Temp = Deck[Index0];
		Deck[Index0] = Deck[Index1];
		Deck[Index1] = Temp;
	}

// Game Section
public:
	void Shuffle(int ShuffleCount = 100);
	const Card Draw();


};

