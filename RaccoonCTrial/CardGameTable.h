#pragma once
#include "vector"
#include "CardDeck.h"

class Card;

class CardGameTable
{
public:
	CardGameTable();
	~CardGameTable();

private:
	CardDeck* CurrentDeck;

// Game Section
public:
	void Play();
	void DrawCardFromDeck(vector<Card>& TargetHand);

};

