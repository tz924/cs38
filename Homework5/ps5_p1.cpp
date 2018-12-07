/**
 * Assignment name:	Problem Set 5 Problem 1
 * File name:		ps5_p1.cpp
 * Author:			Jing Zhang
 */

#include "ps5.h"

using namespace std;

/* Class version of Money */
void problem1()
{
	// Instance and test the Money class
	Money myMoney;
	myMoney.showMoney();		// Should default to $0.00

	myMoney.addMoney(4);		// Should be $4.00
	myMoney.showMoney();

	myMoney.addMoney(0, 200);	// Should be $6.00
	myMoney.showMoney();

	myMoney.addMoney(1, 234);	// Should be $9.34
	myMoney.showMoney();
	cout << endl;

	Money myDollars(300);		// Should be $300.00
	myDollars.showMoney();
	cout << endl;

	Money myCents(0, 500);		// Should be $5.00
	myCents.showMoney();
	cout << endl;

	Money myCash(1, 2);
	myCash.showMoney();			// Should be $6.02
	cout << endl;
}

// Money class implementations

/* Money 2-arg constructor */
Money::Money(int dollars /* = 0 */, int cents /* = 0 */)
{
	// Initialize instance variables
	this->mDollars = 0;
	this->mCents = 0;

	// User may enter >= 100 cents, use method avoid code repetition
	addMoney(dollars, cents);
}

/* Add money to a money struct */
void Money::addMoney(int dollars, int cents)
{
	// Dollars addition - simply add the integral part
	this->mDollars += dollars;

	// Cents addition - add the dollar parts and cents parts respectively
	if (cents >= DOLLAR)    // [100, inf)
	{
		// Use the divmod operation to get its dollars and cents part
		this->mDollars += cents / DOLLAR;
		this->mCents += cents % DOLLAR;		// [0, 99]
	}
	else    // [0, 99]
		this->mCents += cents;
}

/* Displays a money structure as $d.cc */
void Money::showMoney()
{
	cout << "Balance: $" << this->mDollars << ".";
	if (!this->mCents)
		cout << "00";
	else if (this->mCents < DIME)
		cout << "0" << this->mCents;
	else
		cout << this->mCents;
	cout << endl;
}
