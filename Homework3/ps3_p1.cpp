/**
 * Assignment name:	Problem Set 3
 * File name:		ps3_p1.cpp
 * Author:			Jing Zhang
 */

#include "ps3.h"
using namespace std;

/* Color Array */
void problem1()
{
	const int NUM_COLORS = 6;
	const int LEN_COLOR_ARRAY = 4;
	const string STR_COLORS[] = { "red", "green", "blue",
		"purple", "orange", "yellow" };

	// Create an enumeration to represent the colors as an enum data type
	enum Color { red, green, blue, purple, orange, yellow };

	// Create the array to hold 4 of the colors
	string colorArray[LEN_COLOR_ARRAY];

	// Randomly choose a color for each slot in the array
	for (int index = 0; index < LEN_COLOR_ARRAY; index++)
	{
		// Randomly get pick a color from Colors
		Color color = static_cast<Color>(rand() % NUM_COLORS);	// [0, 5]

																// Store that color (in word) in the array
		colorArray[index] = STR_COLORS[color];
	}

	// Display the array
	for (auto color : colorArray)
	{
		cout << color << endl;
	}
}
