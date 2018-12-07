/**
 * Assignment name:	Problem Set 3
 * File name:		ps3_p4.cpp
 * Author:			Jing Zhang
 */

#include "ps3.h"
using namespace std;

/* Using References */
void problem4()
{
	Suit suit;
	string rank;
	int rankValue, deckIndex, trials = NUM_TRIALS;
	// deck is a boolean array to track if a card has been dealt
	bool deck[NUM_CARDS_IN_DECK] = { false };	// Initialize all to false

	for (int iter = 1; iter <= trials; iter++)
	{
		// Deal a card until it is not a duplicate
		do
		{
			rankValue = dealACard(suit, rank);
			deckIndex = getDeckIndex(suit, rank);
		} while (isDuplicate(deckIndex, deck));

		// Update deck
		deck[deckIndex] = true;

		// Display the randomly dealt card
		cout << iter << " cards dealt: "
			<< "[" << rankValue << "] "
			<< rank << " of " << STR_SUITS[suit] << "s\n";

		// The deck should be "shuffled" when there are 7 cards left in the deck
		if (getNumDealt(deck) >= TIME_TO_SHUFFLE)
		{
			shuffle(deck);
			cout << "Deck shuffled" << endl;
		}
	}

	// Keep track of cards that have been "dealt" (hint: use an	array) to avoid
	// duplicate cards.
}

/**
* Takes two parameters passed using "call by reference" and returns an int
* Return a random card each time it is called
*
*	- The first parameter is the suit of the card (Suit)
*	- The second parameter is the rank (string)
*
* The return value of the function is the value of the card (an int).
* Ace is 1, Jack, Queen, King are 10, all others are their stated value
*/
int dealACard(Suit &suit, string &rank)
{
	// Get a random rank
	int rankIndex = rand() % NUM_RANKS;	// [0, 12]
	int suitIndex = rand() % NUM_SUITS;	// [0, 3]

										// Store the card's rank as string
	rank = STR_RANKS[rankIndex];

	// Store the card's suit value
	suit = static_cast<Suit>(suitIndex);

	// Return an integer representation of the randomly generated card's rank
	return (rankIndex < JACK_INDEX) ? // ACE to TEN
		rankIndex + 1 :		// Value is stated value (0-based -> 1-based)
		JACK_INDEX;			// Jack, Queen, King are 10 (Jack's index)
}

// Helper functions

/* Check if a card is duplicate */
bool isDuplicate(const int deckIndex, const bool deck[])
{
	// true -> dealt -> duplicate; false -> not dealt -> not duplicate
	return deck[deckIndex];
}

/* Calculate the deck index given a suit and rank */
int getDeckIndex(const Suit suit, const string rank)
{
	int suitIndex = suit;	// Conversion to int

							// Find rank index in the STR_RANK array
	int rankIndex;
	for (int index = 0; index < NUM_RANKS; index++)
	{
		if (STR_RANKS[index] == rank)
			rankIndex = index;
	}

	return suitIndex * NUM_RANKS	// Get to the "starting point"
		+ rankIndex;	// Starting point + [0, 12]
}

/* Shuffle the deck - set all entry to false */
void shuffle(bool deck[])
{
	for (int index = 0; index < NUM_CARDS_IN_DECK; index++)
		deck[index] = false;
}

/* Get the number of cards being dealt in a deck */
int getNumDealt(const bool deck[])
{
	// Simple iterative sum
	int sum = 0;

	for (int index = 0; index < NUM_CARDS_IN_DECK; index++)
		sum += deck[index];

	return sum;
}
