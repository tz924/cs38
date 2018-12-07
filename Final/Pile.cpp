//
//	Assignment name:	Final Project
//  File name:			Pile.cpp
//  Author:				Jing Zhang
//	Notes:				Base class Pile implementation
//

#include "Pile.h"
#include "ExplodingKitten.h"

using namespace std;

// Constructor
Pile::Pile(string pileName/* = DEF_PILE_NAME */) :
	mPileName(pileName), mCards(vector<Card *>())
{}

// Virtual (default) destructor
Pile::~Pile()
{
	// Deallocate all the memories
	unit index = DISPLAY_INDEX_START;	// For better visualization
	for (auto&& card : mCards)
	{
		cout << index << " ";
		delete card;
		index++;
	}
	mCards.clear();
	cout << this->mPileName << " destructed" << endl;
}

// Getter
int Pile::getSize() const
{
	return this->mCards.size();
}

// Randomly shuffle the card
void Pile::shuffle()
{
	random_shuffle(this->mCards.begin(), this->mCards.end());
}

// Display the pile (restricted)
void Pile::display(bool showDesc/* = false */) const
{
	cout << "=== " << mPileName << " Info ===" << endl;

	// If no card in pile, tell the user and return
	if (this->mCards.empty())
	{
		cout << "No card in the " << mPileName << endl;
		return;
	}

	// Otherwise display the pile
	cout << "There are " << this->mCards.size()
		<< " cards in the " << mPileName << endl;

	unit index = DISPLAY_INDEX_START;
	for (auto card : this->mCards)
	{
		cout << index << endl;
		card->display(showDesc);
		cout << endl;
		index++;
	}
}

// Insert a card into the pile
void Pile::insert(Card * card)
{
	this->mCards.push_back(card);
}

// Insert the same card n times
void Pile::insert(Card *card, unit howMany)
{
	for (unit i = 0; i < howMany; i++)
		this->insert(card);
}

// Deal how many cards to player (assume valid input - internal call)
void Pile::deal(Player *player, int howMany /* = 1 */, bool show /* = true */)
{
	for (int i = 0; i < howMany; i++)
	{
		Card *card = this->mCards.back();

		// Move the card
		player->mHand.push_back(card);
		mCards.pop_back();

		if (show)
		{
			cout << endl;
			cout << "New card dealt: " << endl;
			card->display(true);
			cout << endl;
		}

		// If card is exploding kitten
		if (card->isEK) {
			if (player->hasDefuse() < 0)	// Index not found
			{
				// The player explode
				player->explode();
			}
			else
			{
				// Removed the defused
				player->removeFromHand(player->hasDefuse());

				// Let the user know
				cout << "Explosion defused" << endl;

				// Put it back
				player->mHand.pop_back();
				this->mCards.push_back(card);
			}
		}
	}
}

// Deal how many cards to another pile
void Pile::deal(Pile *pile, int howMany /* = 1 */)
{
	for (int i = 0; i < howMany; i++)
	{
		pile->mCards.push_back(this->mCards.back());
		this->mCards.pop_back();
	}
}
