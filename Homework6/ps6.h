//
//	Assignment name:	Problem Set 6
//  File name:			ps6.h
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
const int DEF_DOLLARS = 0;
const int DEF_CENTS = 0;
const int CENT = 1;
const int DIME = 10 * CENT;
const int DOLLAR = 100 * CENT;
const int DEF_VALUE = 0;
const int NOT_SPECIFIED = -1;
const int REMOVE_SUCCESS = 0;
const int REMOVE_FAILURE = 1;

// Part 1
// Create a class called money with members as listed below.
class Money
{
private:
	// dollars, cents(should be private)
	int mDollars;
	int mCents;
public:
	// Default constructor
	Money();

	/* Constructor that takes amount of dollars and cents as input
	   with cents defaulted to 0 */
	Money(int dollars, int cents = DEF_CENTS);

	/* Constructor that takes a double as a parameter and
	   converts appropriately to dollars and cents */
	Money(double balance);

	// Copy constructor : initialize this Money object from another Money object
	Money(const Money &money);

	// Destructor : the destructor should display "My wallet is now empty".
	~Money();

	/* Setters */

	// Set the amount of dollars and cents using individual integer values
	void set(int dollars, int cents);

	// "set" method to set the amount of dollars and cents using a double
	void set(double balance);

	// "increase" method to add to the amount of dollars and cents using
	// individual integer values to represent the amount of
	// dollars / cents to be added
	void increase(int dollars, int cents);

	// "decrease" method to add to the amount of dollars and cents using
	// individual integer values to represent the amount of
	// dollars / cents to be subtracted
	void decrease(int dollars, int cents);

	// "show" to display the monetary value
	void show() const;

	/* operator += : to increase this Money object with the value of
	   another Money object myWallet += m; */
	Money &operator+=(const Money &money);

	// *operator += : to increase this Money object with a double
	Money &operator+=(double amount);

	// * << and >> operators to allow output / input respectively
	// using cout / cin or a file
	friend ostream &operator<<(ostream &out, const Money &money);

	// Assumer the user enter valid dollars and cents (validation elsewhere)
	friend istream &operator>>(istream &in, Money &money);

	// *comparison and equality operators(< > == !=)
	friend bool operator>(const Money &m1, const Money &m2);
	friend bool operator<(const Money &m1, const Money &m2);
	friend bool operator==(const Money &m1, const Money &m2);
	friend bool operator!=(const Money &m1, const Money &m2);
};

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
