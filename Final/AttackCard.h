//
//	Assignment name:	Final Project
//  File name:			AttackCard.h
//  Author:				Jing Zhang
//	Notes:				Attack Card header
//

#pragma once

#include "Card.h"

class AttackCard :
	public Card
{
public:
	AttackCard(string = DEF_CARD_NAME);
	~AttackCard();
	void play() override;
};
