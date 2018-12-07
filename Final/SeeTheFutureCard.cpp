//
//	Assignment name:	Final Project
//  File name:			SeeTheFutureCard.cpp
//  Author:				Jing Zhang
//	Notes:				SeeTheFuture Card Implementation
//

#include "SeeTheFutureCard.h"
#include "EK.h"

using namespace std;

// Constructor
SeeTheFutureCard::SeeTheFutureCard(string name /* = DEF_CARD_NAME */) :
	Card(TYPE_SEE_THE_FUTURE, name, DESC_SEE_THE_FUTURE)
{}

// Destructor
SeeTheFutureCard::~SeeTheFutureCard()
{}

void SeeTheFutureCard::play()
{
	drawPile->showLastThree();

	// Remove turns
	currentPlayer->removeTurns();

	// Player draw a card
	drawPile->deal(currentPlayer);

	cout << "SeeTheFuture card played" << endl;

	OK();
}
