//
//	Assignment name:	Extra Credit Summer
//  File name:			SafeArray.h
//  Author:				Jing Zhang
//

#pragma once	// Include guard

#include <iostream>
#include <vector>
#include <initializer_list>

using std::vector;
using std::ostream;
using std::istream;

typedef unsigned int unit;

// Constants
const int DEF_VALUE = 0;
const int NOT_SPECIFIED = -1;
const int REMOVE_SUCCESS = 0;
const int REMOVE_FAILURE = 1;

// Part II : Create a SafeArray class to hold a collection of integers
// The class will contain a dynamic data array of int plus a data member
// called size which reflects the current size of the data array.

class SafeArray
{
private:
	int * mArray;
	int mSize;

public:
	// "Default constructor
	SafeArray();

	// "Copy constructor
	SafeArray(const SafeArray &safeArray);

	// "Constructor with initializer list - initializes the data array to the
	// items in the list
	SafeArray(std::initializer_list<int> args);

	// "Destructor - frees memory
	~SafeArray();

	// "addItems(int howMany, int value) - adds howMany slots to the data array.
	// New items should be set to optional value. If value is not provided,
	// set them to 0.
	void addItems(int howMany, int value = DEF_VALUE);

	// "removeItems(int howMany, int start) - removes howMany items from the
	// start index - or from the end if no start index is specified
	int removeItems(int howMany, int start = NOT_SPECIFIED);

	// "at(int index) - return the value of the item at the specified index.
	// Throw out of bounds exception if user attempts to exceed array boundaries
	int at(int index) const;

	// "put(int index, int data) - store data at the specified index.
	// Throw out of bounds exception if user attempts to exceed array boundaries
	void put(int index, int data);

	// "put(int index, int *data, int howMany) store howMany items pointed to
	// by data starting at the specified index.
	// Throw out of bounds exception if user attempts to exceed array boundaries
	void put(int index, int *data, int howMany);

	// Copy all data in the SafeArray to the vector
	void copyTo(vector<int> &v);

	// size() - returns the number of elements(integers) in the data array
	int size() const;

	// "clear() - empties the array
	void clear();

	// Helper - Debugging
	void show();
};

// Test Suites
void part1Test();
void part2Test();
