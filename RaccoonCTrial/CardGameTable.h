#pragma once

#include "CardDeck.h"
#include "vector"

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

