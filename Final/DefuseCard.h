//
//	Assignment name:	Final Project
//  File name:			DefuseCard.h
//  Author:				Jing Zhang
//	Notes:				Defuse Card header
//

#pragma once

#include "Card.h"

class DefuseCard :
	public Card
{
public:
	DefuseCard(string = DEF_CARD_NAME);
	~DefuseCard();
	void play() override;
};
