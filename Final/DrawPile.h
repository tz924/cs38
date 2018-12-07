//
//	Assignment name:	Final Project
//  File name:			DrawPile.h
//  Author:				Jing Zhang
//	Notes:				DrawPile class header
//

#pragma once

#include "Pile.h"
#include "Card.h"

class DrawPile :
	public Pile
{
public:
	// Constructor
	DrawPile();

	// Destructor
	~DrawPile();

	// You can count the cards left in the draw Pile
	void countCards() const;

	// Generate a standard deck without Exploding Kittens and Defuse cards
	void generateStandardDeck();

	// Show last how many
	void showLastThree() const;
};
