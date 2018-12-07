//
//	Assignment name:	Problem Set 5 Problem 2
//	File name:			ps5_p2.cpp
//	Author:				Jing Zhang
//

#include "ps5.h"

using namespace std;

/* Problem 2 - String Stream */
void problem2()
{
	// Create a string with a series of six numbers
	string numbers = "1 2 3 4 5 6";

	// With the help of a stringstream
	istringstream numbersStream(numbers);

	// Add all numbers in the string
	int number, sum = 0;
	while (!numbersStream.eof())
	{
		numbersStream >> number;
		sum += number;
	}
	cout << "The sum is: " << sum << endl;
}
