//
//	Assignment name:	Final Project
//  File name:			EK_main.cpp
//  Author:				Jing Zhang
//	Notes:				Exploding Kittens
//

#include "EK.h"

using namespace std;

vector<Player *> players;
Player *currentPlayer;
unit numPlayers;
DrawPile *drawPile;

int main()
{
	// Seed random
	srand(static_cast<unit>(time(nullptr)));

	// testSuites();
	cout << "=== EXPLODING KITTEN ===" << endl;

	numPlayers = getNumPlayers();

	populate();
	cout << endl;

	displayPlayers();

	// Generate a standard deck with EK and Defuse cards removed
	drawPile = new DrawPile;

	// Store removed defuse cards
	Pile defusePile("Defuse Pile");
	for (int i = 0; i < NUM_DEFUSE; i++)
	{
		defusePile.insert(new DefuseCard(NAMES_DEFUSE[i]));
	}

	// Store removed EK cards
	Pile EKPile("EK Pile");
	EKPile.insert(new ExplodingKitten, NUM_EXPLODING_KITTEN);

	// Shuffle the deck
	drawPile->shuffle();

	// Deal 5 cards to each player from the draw pile
	for (auto player : players)
	{
		drawPile->deal(player, 5, false);
	}

	// Deal 1 Defuse Card to each player
	for (auto player : players)
	{
		defusePile.deal(player, 1, false);
	}

	// Insert (# players - 1) EK cards back into the deck
	EKPile.deal(drawPile, numPlayers - 1);

	// For 2 players, only put back 2 defuse deck
	int numDefuse = (numPlayers == 2) ? 2 : defusePile.getSize();

	// Insert extra defuse card back into the deck
	defusePile.deal(drawPile, numDefuse);

	// Shuffle the deck
	drawPile->shuffle();

	cout << "Draw Pile generated and shuffled. Ready to Play" << endl;
	OK();

	// Big game loop
	do
	{
		// Go through each player
		for (auto player : players)
		{
			if (gameOver())
				break;

			// Bypassing recursive header with global (move to the next player)
			currentPlayer = player;

			// Skip exploded player's remains
			if (!currentPlayer->isAlive())
				continue;

			// The player must be alive
			currentPlayer->addTurns();

			cout << endl;

			// Show info
			cout << "Player " << currentPlayer->getIndex()
				<< "'s turn..." << endl;

			cout << endl;
			currentPlayer->display();
			currentPlayer->showHand();

			int action;
			double chanceToExplode;
			do
			{
				cout << "===" << endl;

				// Show chance to explode
				chanceToExplode = getChanceOfExplosion() * 100;
				cout << fixed << setprecision(2) << chanceToExplode << "% to explode!" << endl;

				// Show # remaining cards in deck
				cout << drawPile->getSize() << " cards left in the draw pile" << endl;

				action = getAction();

				cout << action << endl;

				if (action == PASS)
				{
					cout << "You chose PASS" << endl << endl;
					cout << "Turn passed" << endl;
					currentPlayer->removeTurns();
					// Player draw a card
					drawPile->deal(currentPlayer);
					OK();
				}
				else if (action == PLAY)
				{
					cout << "You chose PLAY" << endl << endl;
					cout << "Pick a card to play" << endl;
					Card *card = currentPlayer->getCard();	// Pop it
					card->play();
				}
			} while (currentPlayer->getTurnsLeft());
		}
	} while (!gameOver());

	cout << getWinner()->getName() << " WINs" << endl;

	cout << endl;
	cout << "Deallocating..." << endl;

	// Deallocate players
	for (auto&& player : players)
	{
		delete player;
	}
	players.clear();

	system("pause");
	return EXIT_SUCCESS;
}
