//
//	Assignment name:	Final Project
//  File name:			FavorCard.h
//  Author:				Jing Zhang
//	Notes:				Favor Card header
//

#pragma once

#include "Card.h"

class FavorCard :
	public Card
{
public:
	FavorCard(string = DEF_CARD_NAME);
	~FavorCard();
	void play() override;
};
