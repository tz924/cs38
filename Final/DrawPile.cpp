//
//	Assignment name:	Final Project
//  File name:			DrawPile.cpp
//  Author:				Jing Zhang
//	Notes:				DrawPile class implementation
//

#include "DrawPile.h"
#include "EK.h"

using namespace std;

// Constructor
DrawPile::DrawPile() : Pile(DRAW_PILE)
{
	generateStandardDeck();
}

// Destructor
DrawPile::~DrawPile()
{}

// You can count the cards left in the draw Pile
void DrawPile::countCards() const
{
	// Note that the draw pile can't be empty because the losers
	// would have been exploded by then.

	cout << this->getSize() << " cards left in the " << this->mPileName;
}

// Generate a standard deck without Exploding Kittens and Defuse cards
void DrawPile::generateStandardDeck()
{
	// Nope cards
	for (int i = 0; i < NUM_NOPE; i++)
	{
		mCards.push_back(new NopeCard(NAMES_NOPE[i]));
	}

	// Attack cards
	for (int i = 0; i < NUM_ATTACK; i++)
	{
		mCards.push_back(new AttackCard(NAMES_ATTACK[i]));
	}

	// Skip cards
	for (int i = 0; i < NUM_SKIP; i++)
	{
		mCards.push_back(new SkipCard(NAMES_SKIP[i]));
	}

	// Favor cards
	for (int i = 0; i < NUM_FAVOR; i++)
	{
		mCards.push_back(new FavorCard(NAMES_FAVOR[i]));
	}

	// Shuffle cards
	for (int i = 0; i < NUM_SHUFFLE; i++)
	{
		mCards.push_back(new ShuffleCard(NAMES_SHUFFLE[i]));
	}

	// See The Future cards
	for (int i = 0; i < NUM_SEE_THE_FUTURE; i++)
	{
		mCards.push_back(new SeeTheFutureCard(NAMES_SEE_THE_FUTURE[i]));
	}
}

// Show last three cards
void DrawPile::showLastThree() const
{
	int howMany = (3 > this->getSize()) ? this->getSize() : 3;

	for (int i = 1; i <= howMany; i++)
		this->mCards.end()[-i]->display();

	// int lastIndex = this->getSize() - 1;

	// if (lastIndex < 0)
	// {
	// 	cout << "Empty" << endl;
	// 	return;
	// }

	// for (int i = lastIndex; i > lastIndex - 2; i--)
	// {
	// 	if (i < 0)
	// 		return;
	// 	(this->mCards.at(i))->display();
	// }
}
