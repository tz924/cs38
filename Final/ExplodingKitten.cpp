//
//	Assignment name:	Final Project
//  File name:			ExplodinKitten.cpp
//  Author:				Jing Zhang
//	Notes:				Exploding Kittens Card implementation
//

#include "ExplodingKitten.h"
#include "Player.h"
#include "EK.h"
using namespace std;

ExplodingKitten::ExplodingKitten() :
	Card(TYPE_EXPLODING, NAME_EXPLODING, DESC_EXPLODING)
{
	this->isEK = true;
}

ExplodingKitten::~ExplodingKitten()
{}

void ExplodingKitten::play()
{
	// Do nothing (player can't player it)
}
