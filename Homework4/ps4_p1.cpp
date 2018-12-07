/**
* Assignment name:	Problem Set 4 Problem 1
* File name:		ps4_p1.cpp
* Author:			Jing Zhang
*/

#include "ps4.h"

/* Redo the Fibonacci sequence problem with pointers and an array. */
void problem1Part1()
{
	// Initialize the first two elements in the sequence
	unsigned int fiboSeq[FIBO_SIZE] = { FIRST_FIBO, SECOND_FIBO };

	// Store the first 30 elements in the sequence in the array.
	for (unsigned int *fiboPtr = &fiboSeq[START_INDEX];
		fiboPtr - fiboSeq < FIBO_SIZE;			// Equivalent to "index < size"
		fiboPtr++)
	{
		// The value is the sum of the values at its two previous addresses
		*fiboPtr = *(fiboPtr - 1) + *(fiboPtr - 2);
	}

	// Display the array.
	for (auto number : fiboSeq)
		cout << number << " ";
	cout << endl;
}

/* The Fibonacci sequence problem with dynamic memory allocation. */
void problem1Part2()
{
	const unsigned int MIN_NUM_FIBOS = 1;
	const unsigned int MIN_ARRAY_SIZE = 2;

	unsigned int howMany;
	do
	{
		// Ask the user for how many numbers
		cout << "How many Fibonacci numbers? ";
		cin >> howMany;
	} while (howMany < MIN_NUM_FIBOS);

	// Make sure the array is at least size 2 for delete[]
	const unsigned int SIZE = (howMany == MIN_NUM_FIBOS) ?
		MIN_ARRAY_SIZE : howMany;

	// Dynamically allocate memory to store the numbers.
	auto *fiboArray = new unsigned int[SIZE];

	// Safeguarding
	if (!fiboArray)
	{
		cout << "Failed to allocate memory for Fibonacci Series" << endl;
		exit(EXIT_FAILURE);
	}

	// Call makeFibSeries()
	makeFibSeries(fiboArray, howMany);

	// Display the numbers
	for (unsigned int index = 0; index < howMany; index++)
	{
		cout << fiboArray[index] << ' ';
	}
	cout << endl;

	// Delete the allocated memory
	delete[] fiboArray;
}

/* Make a Fibonacci Series with dynamic memory allocation */
void makeFibSeries(unsigned int *arr, const int howmMany)
{
	// Initialize the first two elements in the sequence
	arr[0] = FIRST_FIBO;
	arr[1] = SECOND_FIBO;

	if (howmMany <= START_INDEX)	// Only asked for 1 or 2
		return;

	// Store the howMany elements in the sequence in the array.
	for (unsigned int *fiboPtr = &arr[START_INDEX];
		fiboPtr - arr < howmMany;			// Equivalent to "index < size"
		fiboPtr++)
	{
		// The value is the sum of the values at its two previous addresses
		*fiboPtr = *(fiboPtr - 1) + *(fiboPtr - 2);
	}
}
