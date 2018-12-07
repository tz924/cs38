/**
 * Assignment name:	Problem Set 3
 * File name:		ps3_p2.cpp
 * Author:			Jing Zhang
 */

#include "ps3.h"
using namespace std;

/* Fibonacci Sequence using Vector */
void problem2()
{
	const int MIN_NUM_TO_DISPLAY = 1;
	const int FST_EL = 0;
	const int SND_EL = 1;
	const int START_INDEX = 2;

	// Ask the user how many numbers they want displayed in the sequence
	int nbrToDisplay;

	do
	{
		cout << "How many Fibonacci numbers to display (at least one): ";
		cin >> nbrToDisplay;
	} while (nbrToDisplay < MIN_NUM_TO_DISPLAY);	// At least 1

													// Special case - one number to display
	if (nbrToDisplay == MIN_NUM_TO_DISPLAY)
	{
		// Display the first number and return
		cout << FST_EL << endl;
		return;
	}

	// Create and "seed" the vector with the first two elements(0, 1)
	vector<int> fiboSeq = { FST_EL, SND_EL };

	/* Fill the vector with the remaining of elements in the sequence up to the
	number specified by the user. */
	int prev1 = SND_EL;
	int prev2 = FST_EL;
	int current;

	// Start with the third
	for (int index = START_INDEX; index < nbrToDisplay; index++)
	{
		// Get the current
		current = prev1 + prev2;

		// Push it to the vector
		fiboSeq.push_back(current);

		// Update the previous two
		prev2 = prev1;
		prev1 = current;
	}

	// Display the vector
	for (int number : fiboSeq)
		cout << number << endl;
}
