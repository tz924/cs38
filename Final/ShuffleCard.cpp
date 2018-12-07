//
//	Assignment name:	Final Project
//  File name:			ShuffleCard.cpp
//  Author:				Jing Zhang
//	Notes:				Shuffle Card Implementation
//

#include "ShuffleCard.h"
#include "EK.h"

using namespace std;

// Constructor
ShuffleCard::ShuffleCard(string name /* = DEF_CARD_NAME */) :
	Card(TYPE_SHUFFLE, name, DESC_SHUFFLE)
{}

// Destructor
ShuffleCard::~ShuffleCard()
{}

void ShuffleCard::play()
{
	drawPile->shuffle();
	cout << "Shuffle card played" << endl;
	cout << "The draw pile is now shuffled" << endl;
	OK();
}
