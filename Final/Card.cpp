//
//	Assignment name:	Final Project
//  File name:			Card.cpp
//  Author:				Jing Zhang
//	Notes:				Exploding Kittens
//

#include "Card.h"

using namespace std;

// Getters
string Card::getType() const
{
	return this->mType;
}

string Card::getName() const
{
	return this->mName;
}

string Card::getDescription() const
{
	return this->mDescription;
}

// Constructor
Card::Card(
	string type /* = "Type" */,
	string name	/* = "Name" */,
	string description /* = "Description" */
) :
	mType(type), mName(name), mDescription(description), isDefuse(false), isEK(false)
{}

// Default Destructor
Card::~Card()
{
	cout << mName << " destructed!" << endl;
}

void Card::display(bool desc /* = false */) const
{
	cout << "Type: " << this->mType << " Card" << endl
		<< "Name: " << this->mName << endl;

	if (desc)
		cout << "Description:\n" << this->mDescription << endl;
}
