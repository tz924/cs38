/*
 * Assignment name:	Problem Set 1
 * File name:		pset1.cpp
 * Author:			Jing Zhang
 */

#include <iostream>
#include <string>
using namespace std;

void problem1();
void problem2();
void problem3();
double formatPrice(const double price);	// Helper function

/* The entry point of the program */
int main()
{
	problem1();
	problem2();
	problem3();

	system("pause");
	return 0;
}

/* Declare, define and initialize some variables */
void problem1()
{
	// a. age of a cat
	int catAge = 1;  // My cat Mocha is a 1 year old rag doll

	// b. grade average of a student
	double gradeAverage = 89.95;

	// c. name of a football team
	string teamName = "Seahawks";

	// d. number of jelly beans in a hot tub
	unsigned long long nbrJellies = 123456789;  // Large positive integer

	// e. whether or not to eat pizza
	bool eatPizza = true;

	// f. the maximum number of people allowed in a specific night club
	int clubCapacity = 350;
}

/* Ask the user about his/her address and display it in a nice format */
void problem2()
{
	// Declare all as strings - street No. & zip don't carry arithmetic meanings
	string firstName, lastName,
		streetNumber, streetName, streetType,
		city, state, zip;

	// Ask the user for information
	cout << "Enter your first name: ";
	getline(cin, firstName);

	cout << "Enter your last name: ";
	getline(cin, lastName);

	cout << "Enter your street number: ";
	getline(cin, streetNumber);

	cout << "Enter your street name: ";
	getline(cin, streetName);

	cout << "Enter your street type (i.e. street, road, etc): ";
	getline(cin, streetType);

	cout << "Enter your city: ";
	getline(cin, city);

	cout << "Enter your state: ";
	getline(cin, state);

	cout << "Enter your zip code: ";
	getline(cin, zip);

	// Display in a three line format
	cout << firstName << ' ' << lastName << '\n'
		<< streetNumber << ' ' << streetName << ' ' << streetType << '\n'
		<< city << ", " << state << ' ' << zip << endl;
}

/* Simple online ordering program for "Joe's Hotdogs" */
void problem3()
{
	// Initialize constants
	const double HOTDOG_COST = 3.50;
	const double FRIES_COST = 2.50;
	const double SODA_COST = 1.25;
	const double TAX_RATE = 6.25;

	// Declare and define variables
	int nbrHotdogs;
	int nbrFries;
	int nbrSodas;

	double subtotal;
	double tax;
	double total;

	// Get the order from the user
	cout << "Welcome to Joe's" << '\n';

	cout << "How many hotdogs >  ";
	cin >> nbrHotdogs;

	cout << "How many fries >  ";
	cin >> nbrFries;

	cout << "How many drinks >  ";
	cin >> nbrSodas;

	// Calculate subtotal, tax and total
	subtotal = nbrHotdogs * HOTDOG_COST
		+ nbrFries * FRIES_COST
		+ nbrSodas * SODA_COST;
	tax = subtotal * (TAX_RATE / 100);
	total = subtotal + tax;

	// Display the order summary
	cout << "\nYour order:\n"
		<< nbrHotdogs << " Hotdogs\n"
		<< nbrFries << " French Fries\n"
		<< nbrSodas << " Sodas\n\n"
		<< "Subtotal: $" << formatPrice(subtotal) << '\n'
		<< "Meals Tax (" << TAX_RATE << "%): $" << formatPrice(tax) << '\n'
		<< "Total Due: $" << formatPrice(total) << endl;
}

/* Format the price to be no more than 2 decimal points */
double formatPrice(const double price)
{
	return round(price * 100) / 100.;
}
