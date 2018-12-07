//
//	Assignment name:	Final Project
//  File name:			DefuseCard.cpp
//  Author:				Jing Zhang
//	Notes:				Defuse Card Implementation
//

#include "DefuseCard.h"
#include "EK.h"

using namespace std;

// Constructor
DefuseCard::DefuseCard(string name /* = DEF_CARD_NAME */) :
	Card(TYPE_DIFFUSE, name, DESC_DIFFUSE)
{
	this->isDefuse = true;
}

// Destructor
DefuseCard::~DefuseCard()
{}

void DefuseCard::play()
{
	// If actively played -> like skip
	cout << "Nothing to defuse!" << endl
		<< "Turn PASSed" << endl;

	// Remove turns
	currentPlayer->removeTurns();

	// Player draw a card
	drawPile->deal(currentPlayer);

	OK();
}
