/**
 * Assignment name:	Problem Set 4
 * File name:		ps4.h
 * Author:			Jing Zhang
 */

#pragma once	// Include guard
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/* Problem 1 - Fibonacci Sequence */
const unsigned int FIBO_SIZE = 30;
// The index of the third number in the Fibonacci Sequence
const unsigned int START_INDEX = 2;
// The first two elements in the Fibonacci Sequence
const unsigned int FIRST_FIBO = 0, SECOND_FIBO = 1;

// Redo the Fibonacci sequence problem with pointers and an array
void problem1Part1();

// The Fibonacci sequence problem with dynamic memory allocation
void problem1Part2();

// Dynamically generate a Fibonacci Sequence given user input
void makeFibSeries(unsigned int *arr, const int howmMany);

/* Problem 2 - Dynamic Memory Allocation */
void problem2();

// Generate full name with dynamic memory allocation
string *allocName(const string &firstName, const string &lastName);

/* Problem 3 - Structure */
void problem3();

// Create a structure called money
struct MoneyType
{
	// Contains an int for dollars and cents.
	int dollars, cents;
};

// Add money to a money struct
void addMoney(MoneyType &money, const int dollars, const int cents);

// Displays a money structure as $d.cc
void showMoney(const MoneyType &money);

/* Problem 4 - subString */
void problem4();
void problem4Graduate();

// Default howMany value if omitted
const int NOT_SPECIFIED = 0;

// Destructive version of subString (mutate the original string)
char *subString(char *str, int index, int howMany = NOT_SPECIFIED);

// Non-destructive version of subString (does not mutate the original string)
char *subStringCopy(char * const str, int index, int howMany = NOT_SPECIFIED);
