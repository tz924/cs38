/**
* Assignment name:	Game Project 4 - Jotto
* File name:		gp4.h
* Author:			Jing Zhang
*/

#pragma once	// Include guard
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned int unit;

// Maximum number of guesses
const unit MAX_NUM_GUESSES = 10;

// For user input
const size_t BUFFER_SIZE = 80;
const size_t SIZE_ALPHABET = 26;

const int SAME = 0;	// For strcmp

// First and last lower case letter
const char FIRST_LETTER = 'a';
const char LAST_LETTER = 'z';

// Length of a word in the game
const unit LEN_WORD = 5;
const unit LEN_WORD_ARR = LEN_WORD + 1;	// Plus one for null

// For give up or not
const unit YES = 1;
const unit NO = 2;

// Set up vocabulary
const unit LEN_VOCAB = 10;	// Number of actual words in vocab
const unit LEN_VOCAB_ARR = LEN_VOCAB * LEN_WORD + 1;	// Length as char array

// 10 words in VOCAB as a single string
const char VOCAB[LEN_VOCAB_ARR] =
"abyss""angry""chime""digit""hello"
"ruins""trump""pride""nasty""moose";

// Response type that record all the information in each turn
struct ResponseType
{
	char *guess;		// The guessed word
	unit numMatches;	// Number of letters that matched
	char *matches;		// Matched letters
	char *elims;		// Eliminated letters
};

// Function prototypes

/* Check if a word is valid in length and characters (lowercase) */
bool isValidChar(const char letter);

/* Check if a word is valid by the game's rule */
bool isValidWord(const char *word);

/* Fill the information in response for each turn */
void getResponse(ResponseType &response, const char *secret, const char *word);

/* Get the index of a lower case letter */
unit getIndex(const char letter);

/* Get the sum of numbers in a counter array */
unit sum(const unit counter[], const unit length);

/* Append a char to a string */
void append(char *str, const char letter);

/* Display the response */
void showResponse(const ResponseType &response);

/* Get the lower case letter from the index */
char getChar(const unit index);

/* Delete allocated memory */
void clean(ResponseType &response);
