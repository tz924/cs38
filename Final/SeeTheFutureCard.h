//
//	Assignment name:	Final Project
//  File name:			SeeTheFutureCard.h
//  Author:				Jing Zhang
//	Notes:				SeeTheFuture Card header
//

#pragma once

#include "Card.h"

class SeeTheFutureCard :
	public Card
{
public:
	SeeTheFutureCard(string = DEF_CARD_NAME);
	~SeeTheFutureCard();
	void play() override;
};
