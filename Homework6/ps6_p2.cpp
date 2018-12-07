//
//	Assignment name:	Problem Set 6
//  File name:			ps6_p2.cpp
//  Author:				Jing Zhang
//

#include "ps6.h"

using namespace std;

// Default constructor
SafeArray::SafeArray() : mArray(nullptr), mSize(0)
{};

// Copy constructor
SafeArray::SafeArray(const SafeArray &safeArray)
{
	this->mSize = safeArray.mSize;

	try
	{
		this->mArray = new int[this->mSize];
	}
	catch (bad_alloc)
	{
		cout << "Allocation Error" << endl;
	}

	// Loop in the values
	for (int index = 0; index < this->mSize; index++)
	{
		this->mArray[index] = safeArray.mArray[index];
	}
}

// Constructor with initializer list - initializes the data array to the
// items in the list
SafeArray::SafeArray(initializer_list<int> args)
{
	this->mSize = args.size();

	try
	{
		this->mArray = new int[this->mSize];
	}
	catch (bad_alloc)
	{
		cout << "Allocation Error" << endl;
	}

	// Load the initializer list to a vector
	vector<int> temp = args;

	// Loop in the values
	for (int index = 0; index < this->mSize; index++)
	{
		this->mArray[index] = temp.at(index);
	}
}

// Destructor - frees memory
SafeArray::~SafeArray()
{
	delete[] this->mArray;
	cout << "Safe array is deleted safely!" << endl;
}

// addItems(int howMany, int value) - adds howMany slots to the data array.
// New items should be set to optional value. If value is not provided,
// set them to 0.
void SafeArray::addItems(int howMany, int value /* = DEF_VALUE */)
{
	if (howMany < 0)
	{
		throw "How Many must be non-negative";
	}

	int newSize = this->mSize + howMany;

	// Allocate a new[] array and store it in a temporary pointer.
	int *tempArray = nullptr;
	try
	{
		tempArray = new int[newSize];
	}
	catch (bad_alloc)
	{
		cout << "Allocation Error" << endl;
	}

	// Copy over the old one to the new one
	int index = 0;
	for (; index < this->mSize; index++)
		tempArray[index] = this->mArray[index];

	// Fill till the end with the value
	while (index < newSize)
		tempArray[index++] = value;

	// Get rid of the old one
	delete[] this->mArray;

	// Point to the new one
	this->mArray = tempArray;

	// Update size
	this->mSize = newSize;
}

// removeItems(int howMany, int start) - removes howMany items from the
// start index - or from the end if no start index is specified
int SafeArray::removeItems(int howMany, int start /* = NOT_SPECIFIED */)
{
	// Start is end if not specified
	if (start == NOT_SPECIFIED)
	{
		start = this->mSize - 1;
		return REMOVE_FAILURE;	// Nothing removed
	}

	if (howMany < 0)
	{
		throw "How many must be non-negative";
	}

	// Invalid index
	if (start < 0 || start >= this->mSize || start + howMany >= this->mSize)
	{
		throw "Index out of bound";
	}

	// Start removal
	int newSize = this->mSize - howMany;

	// Allocate a new[] array and store it in a temporary pointer.
	int *tempArray = nullptr;
	try
	{
		tempArray = new int[newSize];
	}
	catch (bad_alloc)
	{
		cout << "Allocation Error" << endl;
	}

	// Copy the first half to temp
	int index;
	for (index = 0; index < start; index++)
		tempArray[index] = this->mArray[index];

	// Skip "how many"
	int oldIndex = index;
	oldIndex += howMany;

	for (; oldIndex < this->mSize; index++, oldIndex++)
	{
		tempArray[index] = this->mArray[oldIndex];
	}

	// Get rid of the old one
	delete[] this->mArray;

	// Point to the new one
	this->mArray = tempArray;

	// Update size
	this->mSize = newSize;

	return REMOVE_SUCCESS;
}

// at(int index) - return the value of the item at the specified index.
// Throw out of bounds exception if user attempts to exceed array boundaries
int SafeArray::at(int index) const
{
	// Invalid index
	if (index < 0 || index >= this->mSize)
	{
		throw "Index out of bound";
	}

	return this->mArray[index];
}

// put(int index, int data) - store data at the specified index.
// Throw out of bounds exception if user attempts to exceed array boundaries
void SafeArray::put(int index, int data)
{
	// Invalid index
	if (index < 0 || index >= this->mSize)
	{
		throw "Index out of bound";
	}

	this->mArray[index] = data;
}

// put(int index, int *data, int howMany) store howMany items pointed to
// by data starting at the specified index.	Assume good data
// Throw out of bounds exception if user attempts to exceed array boundaries
void SafeArray::put(int index, int *data, int howMany)
{
	// End Index can't = how many (0 based)
	if (index < 0 || index >= this->mSize || index + howMany >= this->mSize)
	{
		throw "Index out of bound";
	}

	if (howMany < 0)
	{
		throw "How many must be non-negative";
	}

	// Assume good data
	for (int offset = 0; offset < howMany; offset++)
	{
		this->mArray[index + offset] = data[offset];
	}
}

// Copy all data in the SafeArray to the vector
void SafeArray::copyTo(vector<int> &v)
{
	for (int index = 0; index < this->mSize; index++)
	{
		v.push_back(this->mArray[index]);
	}
}

// size() - returns the number of elements(integers) in the data array
int SafeArray::size() const
{
	return this->mSize;
}

// clear() - empties the array
void SafeArray::clear()
{
	delete[] this->mArray;
	this->mArray = nullptr;
	this->mSize = 0;
}

// helper function
void SafeArray::show()
{
	for (int index = 0; index < this->mSize; index++)
	{
		cout << this->mArray[index] << " ";
	}
	cout << endl;
}
