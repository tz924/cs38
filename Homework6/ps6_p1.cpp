//
//	Assignment name:	Problem Set 6
//  File name:			ps6_p1.cpp
//  Author:				Jing Zhang
//

#include "ps6.h"

using namespace std;

// Default constructor
Money::Money() :mDollars(DEF_DOLLARS), mCents(DEF_CENTS)
{}

/* Constructor that takes amount of dollars and cents as input
   with cents defaulted to 0 */
Money::Money(int dollars, int cents /* = DEF_CENTS */) :
	mDollars(DEF_DOLLARS), mCents(DEF_CENTS)
{
	this->increase(dollars, cents);
}

/* Constructor that takes a double as a parameter and
   converts appropriately to dollars and cents */
Money::Money(double balance) :
	mDollars(DEF_DOLLARS), mCents(DEF_CENTS)
{
	// Simply get rid of the digits
	int dollars = static_cast<int>(balance);

	// Convert the remainder to int times the correct ratio
	int cents = static_cast<int>((balance - dollars) * DOLLAR);

	// Once converted to 2 int, increase take care of the rest
	increase(dollars, cents);
}

// Copy constructor : initialize this Money object from another Money object
Money::Money(const Money &money) : Money(money.mDollars, money.mCents)
{}

// Destructor : the destructor should display "My wallet is now empty".
Money::~Money()
{
	this->set(DEF_DOLLARS, DEF_CENTS);
	cout << "My wallet is now empty" << endl;
}

/* Setters */

// Set the amount of dollars and cents using individual integer values
void Money::set(int dollars, int cents)
{
	// Can add >= 100 cents but not set
	if (cents >= DOLLAR)
	{
		throw "Cents must be [0, 99]";
	}

	this->mDollars = dollars;
	this->mCents = cents;
}

// Set the amount of dollars and cents using a double
void Money::set(double balance)
{
	// Simply get rid of the digits
	int dollars = static_cast<int>(balance);

	// Convert the remainder to int times the correct ratio
	int cents = static_cast<int>((balance - dollars) * DOLLAR);

	this->set(dollars, cents);
}

// "increase" method to add to the amount of dollars and cents using individual
// integer values to represent the amount of dollars / cents to be added
void Money::increase(int dollars, int cents)
{
	// Dollars addition - simply add the integral part
	this->mDollars += dollars;

	// Cents addition - add the dollar parts and cents parts respectively
	if (abs(cents) >= DOLLAR)    // [100, inf)
	{
		// Use the divmod operation to get its dollars and cents part
		this->mDollars += cents / DOLLAR;
		this->mCents += cents % DOLLAR;		// [0, 99]
	}
	else    // [0, 99]
		this->mCents += cents;
}

// "decrease" method to add to the amount of dollars and cents using individual
// integer values to represent the amount of dollars / cents to be subtracted
void Money::decrease(int dollars, int cents)
{
	this->increase(-dollars, -cents);
}

// "show" to display the monetary value
void Money::show() const
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

/* operator += : to increase this Money object with the value of
   another Money object myWallet += m; */
Money & Money::operator+=(const Money &money)
{
	this->increase(money.mDollars, money.mCents);

	return *this;
}

// *operator += : to increase this Money object with a double
Money & Money::operator+=(double amount)
{
	// Simply get rid of the digits
	int dollars = static_cast<int>(amount);

	// Convert the remainder to int times the correct ratio
	int cents = static_cast<int>((amount - dollars) * DOLLAR);
	this->increase(dollars, cents);

	return *this;
}

// Overload << to output money
ostream &operator<<(ostream &out, const Money &money)
{
	// Just like show() except we are using reference not pointer
	cout << "Balance: $" << money.mDollars << ".";
	if (!money.mCents)
		cout << "00";
	else if (money.mCents < DIME)
		cout << "0" << money.mCents;
	else
		cout << money.mCents;
	cout << endl;

	return out;
}

// Assumer the user enter valid dollars and cents (validation elsewhere)
istream &operator>>(istream &in, Money &money)
{
	in >> money.mDollars >> money.mCents;
	return in;
}

// *comparison and equality operators(< > == !=)
bool operator>(const Money &m1, const Money &m2)
{
	return (m1.mDollars > m2.mDollars) || (m1.mCents > m2.mCents);
}

bool operator<(const Money &m1, const Money &m2)
{
	return (m1.mDollars < m2.mDollars) || (m1.mCents < m2.mCents);
}

bool operator==(const Money &m1, const Money &m2)
{
	return (m1.mDollars == m2.mDollars) && (m1.mCents == m2.mCents);
}

bool operator!=(const Money &m1, const Money &m2)
{
	return (m1.mDollars != m2.mDollars) || (m1.mCents != m2.mCents);
}
