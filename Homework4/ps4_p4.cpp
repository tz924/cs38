/**
* Assignment name:	Problem Set 4 Problem 4
* File name:		ps4_p4.cpp
* Author:			Jing Zhang
*/

#include "ps4.h"

/* Problem 4 - subString */
void problem4()
{
	char s1[80] = "Hello There";
	/* Undergraduate portion - only run one of the following */
	// cout << '"' << subString(s1, 3, 4) << '"' << endl; // returns "lo T"
	// cout << '"' << subString(s1, 3, 99) << '"' << endl; // returns "lo There"
	// cout << '"' << subString(s1, 3) << '"' << endl; // returns "lo There"
	// subString(s1); // should not compile
}

/* Problem 4 - subString graduate version */
void problem4Graduate()
{
	char s1[80] = "Hello There";
	char *sub = subStringCopy(s1, 3, 4);		// returns "lo T"
	// char *sub = subStringCopy(s1, 3, 99);	// returns "lo There"
	// char *sub = subStringCopy(s1, 3);		// returns "lo There"
	// char *sub = subStringCopy(s1);			// should not compile
	cout << '"' << sub << '"' << endl;	// Test the above

	// sub is an array of characters
	delete[] sub;
}

/**
 * The function should return a substring that is formed from the index
 * position of the input string for howMany characters or until the termination
 * character ('\0') is encountered.
 */
char *subString(char *str, int index, int howMany)
{
	// Get a pointer that point to the start of the substring
	char *subStr = &str[index];

	// Get a traversing pointer, initialize it to point to subStr
	char *travPtr = subStr;

	// If the user doesn't specify how many, return the sub string
	if (!howMany)
		return subStr;	// The original position of '\0' is unchanged

						// Otherwise the user must have specified how many
	while (howMany)	// Do the following howMany times
	{
		// If index + how many longer than the original string
		if (*subStr == '\0')	// i.e. original '\0' reached
			return subStr;		// Return subStr and end prematurely
								// Otherwise move the traversing pointer forward
		travPtr++;
		howMany--;
	}

	// End the sub string "early"
	*travPtr = '\0';

	// Return the pointer to the start of the sub string
	return subStr;
}

/* An alternate form that allocates sufficient memory for the substring */
char *subStringCopy(char * const str, int index, int howMany)
{
	// Get a pointer and point it to the start of the string
	char *startStr = &str[index];

	// Get a traversing pointer and point it to the start of the string
	char *travPtr = &str[index];

	// Get the distance to the end of the string - assuming valid index
	int distance = 0;
	while (*travPtr)	// As long as its value isn't '\0'
	{
		distance++;
		travPtr++;
	}

	// Make sure it how many does not exceed the last letter of the string
	if (!howMany ||				// howMany not specified
		howMany > distance)		// howMany exceeds the end
		howMany = distance;		// Set it to distance

	// Allocate the memory for sub string
	auto *subStr = new char[distance + 1];	// Plus 1 for null terminator

	// Safeguarding
	if (!subStr)
	{
		cout << "Failed to allocate memory for the sub-string" << endl;
		exit(EXIT_FAILURE);
	}

	// Copy the substring to the new allocated space
	strcpy_s(subStr, distance + 1, startStr);

	// Point traversing pointer to the start of the sub-string
	travPtr = subStr;

	// Put null terminator after howMany characters in the sub-string
	while (howMany)
	{
		travPtr++;
		howMany--;
	}

	// Terminate the sub-string early
	*travPtr = '\0';

	// Return a pointer to the new memory block
	return subStr;
}
