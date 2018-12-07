/**
 * Assignment name:	Problem Set 4 Problem 3
 * File name:		ps4_p3.cpp
 * Author:			Jing Zhang
 */

#include "ps4.h"

 /* Problem 3 - Structure */
void problem3()
{
	// Create some money
	MoneyType money;

	// Add $3.75 to it using addMoney
	addMoney(money, 3, 75);

	// Display the resulting amount using showMoney()
	showMoney(money);
}

/* Add money to a money struct */
void addMoney(MoneyType &money, const int dollars, const int cents)
{
	money.dollars = dollars;
	money.cents = cents;
}

/* Displays a money structure as $d.cc */
void showMoney(const MoneyType &money)	// Display shouldn't change its value
{
	cout << '$' << money.dollars << '.' << money.cents << endl;
}
