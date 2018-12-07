/**
* Assignment name:	Problem Set 4 Problem 2
* File name:		ps4_p2.cpp
* Author:			Jing Zhang
*/

#include "ps4.h"

/* Problem 2 - Dynamic Memory Allocation */
void problem2()
{
	// Call allocName
	string *fullName = allocName("Jing", "Zhang");

	// Display the full name
	cout << "Full name: " << *fullName << endl;

	// Deallocate the memory block
	delete fullName;
}

// This function should take as input a first name and a last name.
string *allocName(const string &firstName, const string &lastName)
{
	// Dynamically allocate a memory block
	string *fullNamePtr = new string;

	// Check if permission is granted
	if (!fullNamePtr)
	{
		cout << "Failed to allocate memory for full name" << endl;
		exit(EXIT_FAILURE);
	}

	// Store the full name
	*fullNamePtr = firstName + " " + lastName;

	// Return a pointer to the beginning of the memory block
	return fullNamePtr;
}
