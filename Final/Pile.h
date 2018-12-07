//
//	Assignment name:	Final Project
//  File name:			Pile.cpp
//  Author:				Jing Zhang
//	Notes:				Base class Pile header
//

#pragma once

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

#include "Card.h"
#include "Player.h"

typedef unsigned int unit;

using std::vector;
using std::string;

// Default values constants
static const string DEF_PILE_NAME = "Pile";
static const string DRAW_PILE = "Draw Pile";
static const string DISCARD_PILE = "Discard Pile";
static const unit DISPLAY_INDEX_START = 1;

// Base class Pile
class Pile
{
protected:
	vector<Card *> mCards;
	string mPileName;
public:
	Pile(string = DEF_PILE_NAME);
	virtual ~Pile();
	int getSize() const;

	// By default not showing the description of each card
	void display(bool = false) const;

	// Insert a card into the pile
	void insert(Card *);

	// Randomly shuffle the deck
	void shuffle();

	// Insert the same card n times
	void insert(Card *card, unit howMany);

	// Deal how many cards to player
	void deal(Player *player, int howMany = 1, bool show = true);

	// Deal how many cards to another pile
	void deal(Pile *pile, int howMany = 1);
};
