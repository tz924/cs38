//
//	Assignment name:	Final Project
//  File name:			ExplodinKitten.h
//  Author:				Jing Zhang
//	Notes:				Exploding Kittens Card header
//

#pragma once

#include "Card.h"

class ExplodingKitten :
	public Card
{
public:
	ExplodingKitten();
	~ExplodingKitten();
	void play() override;
};
