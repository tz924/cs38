//
//	Assignment name:	Problem Set 5 Problem 3a
//	File name:			ps5_p3a.cpp
//	Author:				Jing Zhang
//	Notes:				Source of common names: FiveThirtyEight
//

#include "ps5.h"

using namespace std;

/* Problem 3a - Read and display names */
void problem3a()
{
	ifstream namesStream;
	namesStream.open("names.txt");

	// Crash if things go wrong
	if (namesStream.fail())
	{
		cout << "Can't open file\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	int nameCount = 0;
	string name;
	while (!namesStream.eof())
	{
		// Read each line from the file
		getline(namesStream, name);

		// Display the name
		cout << name << endl;

		// Count the number of lines as you read from the file
		nameCount++;
	}

	// Display how many names there were.
	cout << nameCount << " names displayed" << endl;

	namesStream.close();
}
