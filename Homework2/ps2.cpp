/*
 * Assignment name:	Problem Set 2
 * File name:		ps2.cpp
 * Author:			Jing Zhang
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void problem1();
void problem2();
void problem3();

// Helper functions
int getPostPromotionQuantity(const int quantity, const int everyN);

/* The entry point of the program */
int main()
{
	// problem1();
	// problem2();
	problem3();

	system("pause");
	return 0;
}

/* Operator and If Practice */
void problem1()
{
	// Create three variables: x, y, z, all integers and a double called d.
	int x, y, z;
	double d;

	// Set x and y to 10
	x = 10;
	y = 10;

	// Add one to x using the = and + operators. Display
	x = x + 1;
	cout << "x: " << x << endl;

	// Add one to x using the ++ operator. Display
	x++;
	cout << "x: " << x << endl;

	// Add one to x using the += operator. Display
	x += 1;
	cout << "x: " << x << endl;

	// Set y to 4 and z to 8. Divide z by y and store the result in x. Display
	y = 4;
	z = 8;
	x = z / y;
	cout << "x: " << x << endl;

	// Divide y by z and store the result in d. Display(Should get .5)
	d = static_cast<double>(y) / z;
	cout << "d: " << d << endl;

	// If x is greater than 0, add 10 to x.Display x.
	if (x > 0)
		x += 10;
	cout << "x: " << x << endl;

	// If x is greater than 0 and y is less than 10, add 1 to d. Display x, y, d
	if (x > 0 && y < 10)
		d++;
	cout << "x: " << x << " y: " << y << " d: " << d << endl;

	// If x is greater than 0 or y is less than 10, add 1 to d. Display x, y, d
	if (x > 0 || y < 10)
		d++;
	cout << "x: " << x << " y: " << y << " d: " << d << endl;
}

/* Joe's Hotdogs - version 2 */
void problem2()
{
	// Initialize constants
	const double HOTDOG_COST = 3.50;
	const double FRIES_COST = 2.50;
	const double SODA_COST = 1.25;
	const double TAX_RATE = 6.25;		// 6.25% tax rate
	const double DISCOUNT_RATE = 10;	// 10% discount rate
	const int NBR_DECIMALS = 2;
	const int MONDAY = 1;				// Sunday = 0, Monday = 1, etc.
	const int EVERY_N = 4;				// For every 4 you get one free

	// Declare and define variables
	int nbrHotdogs;
	int nbrFries;
	int nbrSodas;
	int dayOfWeek;

	double subtotal;
	double tax;
	double total;

	// Get the order from the user
	cout << "Welcome to Joe's" << endl;

	cout << "How many hotdogs >  ";
	cin >> nbrHotdogs;

	cout << "How many fries >  ";
	cin >> nbrFries;

	cout << "How many drinks >  ";
	cin >> nbrSodas;

	// 1. If there are no items in the order
	if (nbrHotdogs == 0 &&
		nbrFries == 0 &&
		nbrSodas == 0)
	{
		// Let the user know and end the program.
		cout << "You didn't order anything!" << endl;
		return;
	}

	// 4. Implement a "buy 3 get 1 free" day on Mondays.

	// Get the day of week - https://en.cppreference.com/w/c/chrono/localtime
	struct tm myTime;
	time_t now = time(0);
	localtime_s(&myTime, &now);	// Thread-safe
	dayOfWeek = myTime.tm_wday;

	// If the local time is Monday
	if (dayOfWeek == MONDAY)
	{
		// Calculate subtotal with the quantity you would actually pay for
		subtotal = getPostPromotionQuantity(nbrHotdogs, EVERY_N) * HOTDOG_COST
			+ getPostPromotionQuantity(nbrFries, EVERY_N) * FRIES_COST
			+ getPostPromotionQuantity(nbrSodas, EVERY_N) * SODA_COST;
	}
	else
	{
		// Calculate the normal subtotal, tax and total
		subtotal = nbrHotdogs * HOTDOG_COST
			+ nbrFries * FRIES_COST
			+ nbrSodas * SODA_COST;
	}

	// 2. If the order is at least $20 (before sales tax is added)
	if (subtotal >= 20)
	{
		// Apply the discount
		subtotal *= 1 - DISCOUNT_RATE / 100;	// Convert to percentage
	}

	tax = subtotal * (TAX_RATE / 100);	// Convert to percentage
	total = subtotal + tax;

	// 3. Display the order summary
	cout << "\nYour order:\n"
		<< nbrHotdogs << " Hotdogs\n"
		<< nbrFries << " French Fries\n"
		<< nbrSodas << " Sodas\n\n"
		// Display the result to exactly 2 decimal places
		<< setprecision(NBR_DECIMALS) << setiosflags(ios::fixed)
		<< "Subtotal: $" << subtotal << '\n'
		<< "Meals Tax (" << TAX_RATE << "%): $" << tax << '\n'
		<< "Total Due: $" << total << endl;
}

/* Fibonacci Sequence */
void problem3()
{
	const int TOTAL_NUMBERS = 30;	// Set up the total numbers in the sequence
	const int FIRST = 0;
	const int SECOND = 1;

	int current,
		prev1 = SECOND,		// the last one
		prev2 = FIRST,		// second to last one
		nbrToDisplay;

	// Create and store the first 30 Fibonacci numbers in an array
	int sequence[TOTAL_NUMBERS] = { prev2, prev1 };

	// Start with the third
	for (int index = 2; index < TOTAL_NUMBERS; index++)
	{
		// Get the current and store it in the sequence
		current = prev1 + prev2;
		sequence[index] = current;

		// Update the previous two
		prev2 = prev1;
		prev1 = current;
	}

	// Get the number of Fibonacci numbers that the user wants to display
	do
	{
		cout << "How many Fibonacci numbers to display [1, 30]: ";
		cin >> nbrToDisplay;
	} while (nbrToDisplay < 1 || nbrToDisplay > 30);	// Check validity

	// Display the numbers
	for (int count = 1; count <= nbrToDisplay; count++)
	{
		cout << sequence[count - 1] << ' ';
	}
	cout << endl;
}

/* Given a quantity, get the quantity you would actually pay for */
int getPostPromotionQuantity(const int quantity, const int everyN)
{
	return quantity - quantity / everyN;
}
