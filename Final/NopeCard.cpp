//
//	Assignment name:	Final Project
//  File name:			NopeCard.cpp
//  Author:				Jing Zhang
//	Notes:				Nope Card Implementation
//

#include "NopeCard.h"
#include "EK.h"

using namespace std;

// Constructor
NopeCard::NopeCard(string name/* = DEF_CARD_NAME */) :
	Card(TYPE_NOPE, name, DESC_NOPE)
{
}

// Destructor
NopeCard::~NopeCard()
{}

void NopeCard::play()
{
	// Increase nopes
	currentPlayer->mNumNopes++;

	// Remove turns
	currentPlayer->removeTurns();

	// Player draw a card
	drawPile->deal(currentPlayer);

	cout << "Nope card played" << endl;
	OK();
}
