//
//	Assignment name:	Problem Set 5
//  File name:			ps5.h
//  Author:				Jing Zhang
//

#pragma once	// Include guard

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

typedef unsigned int unit;
using std::string;

// Problem 1
const int DOLLAR = 100;
const int DIME = 10;

/* Class version of Money */
void problem1();

// Money class
class Money
{
private:	// Don't want the user to access and modify private data members
	int mDollars;
	int mCents;

public:
	// Public constructor to initialize dollars and cents to 0
	Money(int dollars = 0, int cents = 0);

	/* Public methods */

	// Add money to the wallet
	void addMoney(int dollars, int cents = 0);

	// Displays a money object as $d.cc
	void showMoney();
};

/* Problem 2 - String Stream */
void problem2();

/* Problem 3a - Read and display names */
void problem3a();

/* Problem 3b - Read, store, sort and write names */
const string IN_FILE_NAMES = "names.txt";
const string OUT_FILE_NAMES = "names_sorted.txt";
void problem3b();

// Bubble Sort for string
void swap(string *strPtr1, string *strPtr2);	// Bubble Sort's helper
void bubbleSort(string strArr[], unit len);

/* Problem 3c - Compute grade average of people */
const string IN_FILE_GRADES = "grades.txt";
void problem3c();

// Contain the first and last name and the computed average
class Student
{
private:
	string mfirstName;
	string mlastName;
	double mAverage;

public:
	// Public constructor
	Student(string firstName = "", string lastName = "", double average = 0);

	/* Public methods */
	void display();

	// > operator overloading for sorting (Graduate)
	friend bool operator> (const Student&, const Student&);
};

// Overloaded bubble sort for Student
void swap(Student *studentPtr1, Student *studentPtr2);
void bubbleSort(Student students[], unit len);
