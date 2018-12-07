/**
 * Assignment name:	Problem Set 3
 * File name:		ps3_p3.cpp
 * Author:			Jing Zhang
 */

#include "ps3.h"
using namespace std;

/* Joe's Hotdogs - version 3 */
void problem3()
{
	double subtotal, discount, tax, total;
	int quantities[NUM_ITEMS] = { 0 };	// Initialize quantities to 0
	string continueOrder;

	cout << "Welcome to Joe's\n\n";

	// Get the order from the user
	do
	{
		getOrder(quantities);
		displayOrderSummary(quantities);
		cout << "Continue ordering ([yes] or [no])? ";
		cin >> continueOrder;
	} while (continueOrder == "yes");

	// If there are no items in the order
	if (!ordered(quantities))
	{
		// Let the user know and end the program.
		cout << "You didn't order anything!" << endl;
		return;
	}

	subtotal = getSubtotal(quantities);
	discount = getDiscount(subtotal);	// For the receipt
	subtotal -= discount;	// Apply the discount
	tax = getTax(subtotal);
	total = subtotal + tax;

	// Display the receipt
	cout << "\nYour order:\n"
		// Display the result to exactly 2 decimal places
		<< "Subtotal:    " << formatMoney(subtotal) << '\n'
		<< "Discount:    " << formatMoney(discount) << '\n'
		<< "Tax:         " << formatMoney(tax) << '\n'
		<< "Total:       " << formatMoney(total) << endl;
}

/* Displays the "menu" */
void displayMenu()
{
	cout << "Choose next item (order by item number)\n";
	for (int index = 0; index < NUM_ITEMS; index++)
	{
		cout << index + 1	// Item number start at 1
			<< ": " << STR_ITEMS[index] << '\n';
	}
	cout << endl;
}

/**
* Get an order item(item and quantity)
* Calls the display menu function
*/
void getOrder(int quantities[])
{
	int itemIndex, quantity;

	do
	{
		displayMenu();
		cin >> itemIndex;
		itemIndex--;	// Adjust for 0-based index (from 1-based)
	} while (itemIndex < 0 || itemIndex >= NUM_ITEMS);	// Index must be valid

	do
	{
		cout << "How many orders of "
			<< STR_ITEMS[itemIndex]
			<< " do you want? ";
		cin >> quantity;
	} while (quantity < 0);	// Quantity must be positive

	// Record the quantity
	quantities[itemIndex] += quantity;
}

/* Displays all items in the order along with quantities ordered */
void displayOrderSummary(const int quantities[])
{
	cout << "Your order\n";
	for (int index = 0; index < NUM_ITEMS; index++)
	{
		cout << STR_ITEMS[index] << ": " << quantities[index] << '\n';
	}
	cout << endl;
}

/* Calculates and returns the subtotal */
double getSubtotal(const int quantities[])
{
	// Calculate subtotal by the dot product of quantities and prices vectors
	return dotProduct(quantities, PRICES, NUM_ITEMS);
}

/* Takes the subtotal as input and returns the discount amount */
double getDiscount(const double subtotal)
{
	// If the order is at least $20 (before sales tax is added)
	return (subtotal >= DISCOUNT_AMOUNT) ?
		subtotal * DISCOUNT_RATE : // Return the discount
		0;	// Else no discount
}

/* Takes the subtotal as input and returns the tax amount */
double getTax(const double subtotal)
{
	return subtotal * TAX_RATE;
}

/**
* A function that takes a double as input and returns a string representing the
* formatted dollar amount.
*/
string formatMoney(const double amount)
{
	// Same idea as using StringBuilder to format String in Java
	stringstream stream;	// Use the stringstream to get the precision
	stream << fixed << setprecision(NUM_DECS) << amount;
	return "$" + stream.str();	// Convert it back to string
}

// Helper functions

/* Return the dot product of two vectors of the same dimension dim */
double dotProduct(const int vector1[], const double vector2[], const int dim)
{
	// Dot product of two vectors is the sum of their elementwise product
	double sum = 0;

	for (int index = 0; index < dim; index++)
	{
		sum += vector1[index] * vector2[index];
	}

	return sum;
}

/* Returns true if anything is ordered false otherwise */
bool ordered(const int quantities[])
{
	// Logical initializer for logical AND
	bool allZeros = true;

	for (int index = 0; index < NUM_ITEMS; index++)
	{
		// Any non-zero quantity makes it false
		allZeros = allZeros && (quantities[index] == 0);
	}

	return !allZeros;	// Any quantity is not zero <=> ordered
}
