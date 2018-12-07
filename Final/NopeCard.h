//
//	Assignment name:	Final Project
//  File name:			NopeCard.h
//  Author:				Jing Zhang
//	Notes:				Nope Card header
//

#pragma once

#include "Card.h"

class NopeCard :
	public Card
{
public:
	NopeCard(string = DEF_CARD_NAME);
	~NopeCard();
	void play() override;
};
