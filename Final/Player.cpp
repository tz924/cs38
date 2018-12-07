//
//	Assignment name:	Final Project
//  File name:			Player.cpp
//  Author:				Jing Zhang
//	Notes:				Player class implementation
//

#include "Player.h"

using namespace std;

// Constructor
Player::Player(
	string nickname /* = DEF_NICKNAME */,
	unit index /* = DEF_INDEX */
) :
	mNickname(nickname), mIndex(index),
	mTurnsLeft(DEF_TURNS_LEFT), mAlive(DEF_ALIVE),
	mHand(vector<Card *>()),
	mNumNopes(0)	// Default nope is 0
{}

// Destructor
Player::~Player()
{
	// Deallocate all the memories
	for (auto&& card : mHand)
	{
		delete card;
	}
	mHand.clear();
	cout << this->mNickname << " destructed!" << endl;
}

// Getters
string Player::getName() const
{
	return mNickname;
}

int Player::getTurnsLeft()
{
	return mTurnsLeft;
}

bool Player::isAlive() const
{
	return mAlive;
}

// Display player info and hand info
void Player::display() const
{
	cout << "=== Player " << this->mIndex << " Info ===" << endl
		<< "Nickname:   " << this->mNickname << endl
		<< "Status:     " << (this->isAlive() ? "Alive" : "Exploded") << endl
		<< "Turns Left: " << this->mTurnsLeft << endl;
}

// Show the player's hand
void Player::showHand(bool showDesc /* = false */) const
{
	cout << "=== Hand Info ===" << endl;

	// If no card in hand, tell the user and return
	if (this->mHand.empty())
	{
		cout << "No card in hand" << endl;
		return;
	}

	// Otherwise display hand
	int index = 1;
	cout << "You have " << this->mHand.size() << " cards in hand.\n" << endl;
	for (auto card : this->mHand)
	{
		cout << index << endl;
		card->display(showDesc);
		cout << endl;
		index++;
	}
}

// Insert a card into the player's hand
void Player::insert(Card *card)
{
	this->mHand.push_back(card);
}

// Insert the same card n times
void Player::insert(Card *card, unit howMany)
{
	for (unit i = 0; i < howMany; i++)
		this->insert(card);
}

// Add turns to the player
void Player::addTurns(unit howMany /* = 1 */)
{
	for (unit i = 0; i < howMany; i++)
		this->mTurnsLeft++;
}

// Remove a turn from the player
void Player::removeTurns()
{
	this->mTurnsLeft--;
}

// Kill the player
void Player::explode()
{
	cout << "YOU HAVE EXPLODED!" << endl;
	cout << "YOU ARE LITTERED WITH SHAME!" << endl;
	this->mAlive = false;
}

// Detect if the player has a defuse card
int Player::hasDefuse()
{
	int handSize = this->mHand.size();
	// If found return its index
	for (int index = 0; index < handSize; index++)
	{
		if ((this->mHand.at(index))->isDefuse)
			return index;
	}

	// Otherwise return not found
	return DEFUSE_NOT_FOUND;
}

// Remove a card from hand given position
Card *Player::removeFromHand(int index)
{
	Card *temp = this->mHand.at(index);
	this->mHand.erase(this->mHand.begin() + index);
	return temp;
}

// Get index of the player
unit Player::getIndex() const
{
	return this->mIndex;
}

// Get Card index from the player
Card *Player::getCard()
{
	string input;
	int cardIndex;
	do
	{
		this->showHand(true);

		cout << "Your choice: ";
		getline(cin, input);

		stringstream sInput(input);
		sInput >> cardIndex;
	} while (cardIndex < static_cast<int>(DEF_INDEX)
		|| cardIndex > static_cast<int>(this->mHand.size()));

	// Pop the card
	return this->removeFromHand(cardIndex - DEF_INDEX);
}
