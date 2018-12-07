//
//	Assignment name:	Final Project
//  File name:			FavorCard.cpp
//  Author:				Jing Zhang
//	Notes:				Favor Card Implementation
//

#include "FavorCard.h"
#include "EK.h"

using namespace std;

// Constructor
FavorCard::FavorCard(string name /* = DEF_CARD_NAME */) :
	Card(TYPE_FAVOR, name, DESC_FAVOR)
{}

// Destructor
FavorCard::~FavorCard()
{}

void FavorCard::play()
{
	// Dummy Favor like skip
	// Skip without drawing
	currentPlayer->removeTurns();
	cout << "Dummy Favor card played" << endl;
	OK();
}
