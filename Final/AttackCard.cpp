//
//	Assignment name:	Final Project
//  File name:			AttackCard.cpp
//  Author:				Jing Zhang
//	Notes:				Attack Card Implementation
//

#include "AttackCard.h"
#include "EK.h"

using namespace std;

// Constructor
AttackCard::AttackCard(string name /* = DEF_CARD_NAME */) :
	Card(TYPE_ATTACK, name, DESC_ATTACK)
{}

// Destructor
AttackCard::~AttackCard()
{}

void AttackCard::play()
{
	string input;
	int playerIndex;
	cout << "Choose a player # to attack" << endl;
	displayPlayers();
	do
	{
		getline(cin, input);
		stringstream sInput(input);
		sInput >> playerIndex;
	} while (playerIndex < static_cast<int>(INDEX_START)
		|| playerIndex > static_cast<int>(players.size()));

	// Adjust offset
	playerIndex--;

	Player *opponent;
	opponent = players.at(playerIndex);

	// If the opponent has nope, reduce its nope, otherwise add turns
	if (opponent->mNumNopes)
	{
		opponent->mNumNopes--;
	}
	else
	{
		opponent->addTurns();
	}

	// Remove turns
	currentPlayer->removeTurns();

	// Player draw a card
	drawPile->deal(currentPlayer);

	cout << "You attacked " << opponent->getName() << endl;
	opponent->display();
	cout << "Attack card played" << endl;

	OK();
}
