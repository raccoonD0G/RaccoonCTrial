#pragma once

#include "CardDeck.h"
class CardGameTable
{
	
public:
	CardGameTable();
	~CardGameTable();

private:
	CardDeck* CurrentDeck;

public:
	void Play();
};

