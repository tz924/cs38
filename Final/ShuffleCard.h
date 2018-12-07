//
//	Assignment name:	Final Project
//  File name:			ShuffleCard.h
//  Author:				Jing Zhang
//	Notes:				Shuffle Card header
//

#pragma once

#include "Card.h"

class ShuffleCard :
	public Card
{
public:
	ShuffleCard(string = DEF_CARD_NAME);
	~ShuffleCard();
	void play() override;
};
