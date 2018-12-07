//
//	Assignment name:	Final Project
//  File name:			test.cpp
//  Author:				Jing Zhang
//	Notes:				Exploding Kittens Test Suites (complimentary) - Maybe incomplete
//

#include "EK.h"

using namespace std;

void testNumPlayers()
{
	cout << GAME_TITLE << endl;
	int numPlayers = getNumPlayers();

	cout << "Test: " << numPlayers << endl;
}

void testPlayer()
{
	Player p1;
	p1.display();
	cout << endl;
	p1.showHand();
}

void testExplodingKitten()
{
	// Card c;	// Not allowed
	ExplodingKitten ek;
	ek.display();

	cout << endl;

	Card *cPtr = &ek;
	cPtr->display();
	// card.play();
}

void testPile()
{
	Pile p;
	p.display();

	// Test polymorphism
	// Pile * pPtr;
	// pPtr = &p;
	// pPtr->display();

	// DrawPile p1;
	// pPtr = &p1;
	// pPtr->display();

	// DiscardPile p2;
	// pPtr = &p2;
	// pPtr->display();
}

void testDrawPile()
{
	// Test default
	DrawPile p;
	cout << p.getSize() << endl;

	int n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	// Test setup
	p.display(false);

	p.shuffle();
	p.display(false);
}

void testDefuseCard()
{
	DefuseCard card;
	card.display();
	// card.play();
}

void testNopeCard()
{
	NopeCard card;
	card.display();
	// card.play();
}

void testAttackCard()
{
	AttackCard card;
	card.display();
	// card.play();
}

void testSkipCard()
{
	SkipCard card;
	card.display();
	// card.play();
}

void testFavorCard()
{
	FavorCard card;
	card.display();
	// card.play();
}

void testShuffleCard()
{
	ShuffleCard card;
	card.display();
	// card.play();
}

void testSeeTheFutureCard()
{
	SeeTheFutureCard card;
	card.display();
	// card.play();
}

// Comment out the tests you don't want to see
void testSuites()
{
	/* Test Player */
	// testNumPlayers();
	// testPlayer();

	/* Test Pile */
	// testPile();
	testDrawPile();

	/* Test Card */
	// testExplodingKitten();
	// testDefuseCard();
	// testNopeCard();
	// testAttackCard();
	// testSkipCard();
	// testFavorCard();
	// testShuffleCard();
	// testSeeTheFutureCard();
}
