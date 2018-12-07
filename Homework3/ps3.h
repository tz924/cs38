/**
 * Assignment name:	Problem Set 3
 * File name:		ps3.h
 * Author:			Jing Zhang
 */

#pragma once	// Include guard

// Libraries
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>	// stringstream
#include <string>
#include <vector>

using std::string;

// Definitions for problem 3
const double DISCOUNT_AMOUNT = 20;
const double DISCOUNT_RATE = 0.1;	// 10% discount rate
const int NUM_DECS = 2;
const int NUM_ITEMS = 4;
const double TAX_RATE = 0.0625;		// 6.25% tax rate
const double PRICES[] = { 3.5, 2.5, 1.5, 3 };
const string STR_ITEMS[] = { "hotdog", "fries", "soda", "sauerkraut" };

// Definitions for problem 4
const int NUM_TRIALS = 100;	// Change this to see shuffle functionality
const int NUM_SUITS = 4;
const int JACK_INDEX = 10;
enum Suit { club, diamond, heart, spade };
const string STR_SUITS[] = { "club", "diamond", "heart", "spade" };
const int NUM_RANKS = 13;
const string STR_RANKS[] =
{
	"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Jack", "Queen", "King"
};

// Graduate portion
const int NUM_CARDS_IN_DECK = NUM_SUITS * NUM_RANKS;
const int TIME_TO_SHUFFLE = NUM_CARDS_IN_DECK - 7;

// Problems prototypes
void problem1();
void problem2();
void problem3();
void problem4();

// Function prototypes in problem 3
void displayMenu();
void getOrder(int quantities[]);	// Modifies quantities
void displayOrderSummary(const int quantities[]);
double getSubtotal(const int quantities[]);
double getDiscount(const double subtotal);
double getTax(const double subtotal);
string formatMoney(const double amount);

// Function prototypes in problem 4
int dealACard(Suit &suit, string &rank);

// Helper functions
double dotProduct(const int vector1[], const double vector2[], const int dim);
bool ordered(const int quantities[]);
bool isDuplicate(const int deckIndex, const bool deck[]);
int getDeckIndex(const Suit suit, const string rank);
void shuffle(bool deck[]);
int getNumDealt(const bool deck[]);
