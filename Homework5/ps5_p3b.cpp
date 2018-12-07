//
//	Assignment name:	Problem Set 5 Problem 3b
//	File name:			ps5_p3b.cpp
//	Author:				Jing Zhang
//

#include "ps5.h"

using namespace std;

/* Problem 3b - Read, store, sort and write names */
void problem3b()
{
	ifstream namesStream;
	namesStream.open(IN_FILE_NAMES);

	// Crash if things go wrong
	if (namesStream.fail())
	{
		cout << "Can't open file " << IN_FILE_NAMES << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	// Read through the file one time to get a line count
	int nameCount = 0;
	string name;
	while (!namesStream.eof())
	{
		// Read each line from the file
		getline(namesStream, name);

		// Count the number of lines as you read from the file
		nameCount++;
	}

	// Create a dynamic array large enough to store all of the names
	string *names = nullptr;
	try
	{
		names = new string[nameCount];
	}
	catch (bad_alloc)
	{
		cout << "Allocation Error" << endl;
	}

	// Make a constant pointer to the start of names
	string const *start = names;

	// Read all names from the file in an array
	string *namePtr = names;

	// Move to the beginning to the file
	namesStream.clear();
	namesStream.seekg(0, ios::beg);

	while (!namesStream.eof())
	{
		// Read each line from the file
		getline(namesStream, name);

		// Store the name in the array
		*namePtr = name;

		// Move to the next element in array
		namePtr++;
	}

	// Names stored, no longer need name stream
	namesStream.close();

	// Sort the names (by first name)
	bubbleSort(names, nameCount);

	// Write the sorted names to a new file
	ofstream outStream(OUT_FILE_NAMES, ios::trunc);

	if (outStream.fail())
	{
		cout << "Can't open file " << OUT_FILE_NAMES << endl;
		exit(EXIT_FAILURE);
	}

	// Simply loop through the names array and store lines in the out file
	for (int i = 0; i < nameCount; i++)
	{
		outStream << names[i] << endl;
	}

	// Let the user know when it's done
	cout << OUT_FILE_NAMES << " generated." << endl;

	// Close the out file
	outStream.close();

	// Delete allocated memory (start is guaranteed to be not changed)
	delete[] start;
}

/* Swap the values given two string pointers */
void swap(string *strPtr1, string *strPtr2)
{
	// Create a placeholder to store the value of string pointer 1
	string temp = *strPtr1;

	// Put the value of string pointer 2 into the value of string pointer 1
	*strPtr1 = *strPtr2;

	// Set the value of string pointer 2 to the placeholder
	*strPtr2 = temp;
}

/* Standard Bubble Sort for string */
void bubbleSort(string strArr[], unit len)
{
	unit i, j;
	bool isSwapped;

	// len - 1 because there's only n - 1 adjacent pairs in n elements
	for (i = 0; i < len - 1; i++)
	{
		// Initialize is swapped to false
		isSwapped = false;

		/* Len - i - 1 because in each outer iteration, the last element will be
		the largest (as it is "bubbled up" to the last), so we only need to look
		at n - 1 elements in the next iteration */
		for (j = 0; j < len - i - 1; j++)
		{
			// If any adjacent pair is in the wrong order
			if (strArr[j] > strArr[j + 1])	// > overloaded for string class
			{
				// Swap them (pass in the addresses of them)
				swap(&strArr[j], &strArr[j + 1]);

				// If anything is swapped, set is swapped to true
				isSwapped = true;
			}
		}

		// If nothing is swapped, then it is sorted
		if (!isSwapped)
			break;	// We are done
	}
}
