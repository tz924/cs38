//
//	Assignment name:	Final Project
//  File name:			Player.h
//  Author:				Jing Zhang
//	Notes:				Player class header
//

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Card.h"

typedef unsigned int unit;

using std::vector;
using std::string;

// Constants
static const string DEF_NICKNAME = "Player";
static const bool DEF_ALIVE = true;
static const int DEF_TURNS_LEFT = 0;
static const int DEF_INDEX = 1;

class Player
{
private:
	// Each player has a hand of cards
	vector<Card *> mHand;
	string mNickname;
	unit mIndex;
	int mTurnsLeft;
	bool mAlive;
public:
	unit mNumNopes;

	// Each turn
	Player(string = DEF_NICKNAME, unit = DEF_INDEX);
	~Player();

	// Getters
	string getName() const;
	unit getIndex() const;
	int getTurnsLeft();
	bool isAlive() const;
	void display() const;
	void showHand(bool showDesc = false) const;

	// Insert a card into the player's hand
	void insert(Card *card);

	// Insert the same card n times
	void insert(Card *card, unit howMany);

	// Add turns to the player
	void addTurns(unit howMany = 1);

	// Kill the player by explosion
	void explode();

	// Remove a turn from the player
	void removeTurns();

	// Detect if the player has a defuse card
	int hasDefuse();

	// Remove a card from hand given position and return it
	Card *removeFromHand(int index);

	// Get Card index from the player
	Card *getCard();

	friend class Pile;
};
