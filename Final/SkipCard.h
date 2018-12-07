//
//	Assignment name:	Final Project
//  File name:			SkipCard.h
//  Author:				Jing Zhang
//	Notes:				Skip Card header
//

#pragma once

#include "Card.h"

class SkipCard :
	public Card
{
public:
	SkipCard(string = DEF_CARD_NAME);
	~SkipCard();
	void play() override;
};
