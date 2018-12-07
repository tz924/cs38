//
//	Assignment name:	Problem Set 6
//  File name:			ps6_p2_test.cpp
//  Author:				Jing Zhang
//

#include "ps6.h"

using namespace std;

void part2Test()
{
	// Note destructor is constant being testing (see output)
	cout << "Test default constructor" << endl;
	SafeArray sArr;
	cout << sArr.size() << endl;	// Should be 0
	cout << endl;

	cout << "Test initializer list constructor" << endl;
	SafeArray sArr2({ 1, 2, 3, 4, 5 });
	cout << sArr2.size() << endl;	// Should be 5
	sArr2.show();
	cout << endl;

	cout << "Test Copy constructor" << endl;
	SafeArray sArrCopy = sArr2;
	sArrCopy.show();
	cout << endl;

	cout << "Test add items" << endl;
	int many = 5;
	int val = 1;

	// With default value
	sArrCopy.addItems(many);
	sArrCopy.show();

	// Without default value
	sArrCopy.addItems(many, val);
	sArrCopy.show();

	// Invalid how many
	try
	{
		sArrCopy.addItems(many * (-1), val);
	}
	catch (const char * e)
	{
		cout << e << endl;
	}
	cout << endl;

	cout << "Test remove items" << endl;
	int status;

	// Good remove
	sArrCopy.show();
	status = sArrCopy.removeItems(5, 3);
	sArrCopy.show();
	if (status == REMOVE_SUCCESS)
		cout << "Success" << endl;

	// Bad remove
	try
	{
		status = sArrCopy.removeItems(5, NOT_SPECIFIED);
		sArrCopy.removeItems(5, 100);
	}
	catch (const char * e)
	{
		cout << e << endl;
		if (status == REMOVE_FAILURE)
			cout << "Failed" << endl;
	}
	cout << endl;

	cout << "Test at" << endl;
	try
	{
		cout << sArrCopy.at(2) << endl;
		cout << sArrCopy.at(100) << endl;
	}
	catch (const char * e)
	{
		cout << e << endl;
	}
	cout << endl;

	cout << "Test put" << endl;
	try
	{
		// Version 1
		sArrCopy.show();
		sArrCopy.put(2, 99);
		sArrCopy.show();

		// Bad
		cout << sArrCopy.at(100) << endl;
		sArrCopy.show();
	}
	catch (const char * e)
	{
		cout << e << endl;
	}
	cout << endl;

	try
	{
		// Version 2
		int data[] = { 1, 2, 3, 4 };
		sArrCopy.show();
		sArrCopy.put(5, data, 3);
		sArrCopy.show();
		sArrCopy.put(5, data, 100);
	}
	catch (const char * e)
	{
		cout << e << endl;
	}
	cout << endl;

	cout << "Test copyTo" << endl;
	vector<int> vect;
	sArrCopy.copyTo(vect);
	for (auto n : vect)
		cout << n << " ";
	cout << endl;

	cout << "Test size and show" << endl;
	cout << sArrCopy.size() << endl;
	sArrCopy.clear();
	cout << sArrCopy.size() << endl;
}
