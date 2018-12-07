//
//	Assignment name:	Final Project
//  File name:			SkipCard.cpp
//  Author:				Jing Zhang
//	Notes:				Skip Card Implementation
//

#include "SkipCard.h"
#include "EK.h"

using namespace std;

// Constructor
SkipCard::SkipCard(string name /* = DEF_CARD_NAME */) :
	Card(TYPE_SKIP, name, DESC_SKIP)
{}

// Destructor
SkipCard::~SkipCard()
{}

void SkipCard::play()
{
	// Skip without drawing
	currentPlayer->removeTurns();
	cout << "Skip card played" << endl;

	OK();
}
