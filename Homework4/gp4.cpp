/**
* Assignment name:	Game Project 4 - Jotto
* File name:		gp4.cpp
* Author:			Jing Zhang
*/

#include "gp4.h"

/* The entry point of the program */
int main()
{
	/* Select a 5 letter word at random */
	srand(static_cast<unsigned int>(time(nullptr)));
	unit wordIndex = rand() % LEN_VOCAB; // [0, 9]

	// Contains the space for null
	char secret[LEN_WORD_ARR];

	// Writes null char automatically
	strncpy_s(secret, LEN_WORD_ARR,		// Destination, Capacity of Destination
		VOCAB + wordIndex * LEN_WORD,	// Start using pointer arithmetic
		LEN_WORD);						// For how many chars

	unit numGuess = 0;
	char guess[BUFFER_SIZE];	// User may type long string

	// Record responses
	ResponseType responses[MAX_NUM_GUESSES];

	// Game loop
	do
	{
		// User makes the first guess - a valid 5 letter word
		do
		{
			cout << "Make a guess: ";
			cin >> guess;
			cout << endl;	// Extra space
		} while (!isValidWord(guess));

		// If the guess is correct, break
		if (strcmp(secret, guess) == SAME)
		{
			cout << "Correct! The word is " << secret
				<< ". You WIN!" << endl;

			// Clean memory
			for (unit index = 0; index < numGuess; index++)
			{
				clean(responses[index]);
			}

			system("pause");
			return EXIT_SUCCESS;
		}

		/* Create a new response */
		ResponseType response;

		// Dynamically set up word
		char *word = new char[LEN_WORD_ARR];
		if (!word)
		{
			return EXIT_FAILURE;
		}
		strcpy_s(word, LEN_WORD_ARR, guess);
		response.guess = word;

		// Dynamically set up matches
		char *matches = new char[LEN_WORD_ARR];
		if (!matches)
		{
			return EXIT_FAILURE;
		}
		matches[0] = '\0';
		response.matches = matches;

		// Dynamically set up elims
		char *elims = new char[LEN_WORD_ARR];
		if (!elims)
		{
			return EXIT_FAILURE;
		}
		elims[0] = '\0';
		response.elims = elims;

		// Get the matches
		getResponse(response, secret, guess);

		// Record the response
		responses[numGuess] = response;

		// Display all guesses / responses after each user turn
		cout << "GUESS HISTORY" << endl;
		for (unit index = 0; index <= numGuess; index++)
		{
			showResponse(responses[index]);
		}

		// Show guesses left
		numGuess++;
		cout << "Number of guesses left: "
			<< MAX_NUM_GUESSES - numGuess << endl;

		/* Ask the user if he/she is going to give up */
		int choice;
		do
		{
			cout << "Give up? [1]Yes [2]No: ";
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (choice != YES && choice != NO);

		// Break the loop if the user gives up
		if (choice == YES)
		{
			cout << "You give up!" << endl;
			break;
		}
	} while (numGuess < MAX_NUM_GUESSES);

	cout << "You LOSE! The correct word is " << secret << endl;

	// Clean memory
	for (unit index = 0; index < numGuess; index++)
	{
		clean(responses[index]);
	}

	system("pause");
	return EXIT_SUCCESS;
}

/* Check if a word is valid in length and characters (lowercase) */
bool isValidWord(const char *word)
{
	// Check length
	if (strlen(word) != LEN_WORD)
		return false;

	// Get a pointer to constant character
	const char *travPtr = word;

	// While that character is not '\0'
	while (*travPtr)
	{
		// If the character is not valid
		if (!isValidChar(*travPtr))
			return false;

		// Move to the next character
		travPtr++;
	}

	// Nothing wrong with it, must be valid
	return true;
}

/* Fill the information in response for each turn */
void getResponse(ResponseType &response, const char *secret, const char *word)
{
	// inWord is a boolean array (alphabet) representing if a letter is in word
	unit wordCounter[SIZE_ALPHABET] = { 0 };

	// secretCounter records the letter counts in secret
	unit secretCounter[SIZE_ALPHABET] = { 0 };

	/* Get the unique characters in guess (record in alphabet) */
	// Get a traversing pointer
	const char *travPtr = nullptr;

	// Loop through the word
	for (travPtr = word; *travPtr; travPtr++)
	{
		// Set occurred letter to be true - true would still be true
		wordCounter[getIndex(*travPtr)]++;
	}

	// Loop through the secret word
	for (travPtr = secret; *travPtr; travPtr++)
	{
		// If the letter is in the word (match)
		if (wordCounter[getIndex(*travPtr)])	// Non-zero -> true
		{
			// Take the matched count out of word and put into secret counter
			wordCounter[getIndex(*travPtr)]--;
			secretCounter[getIndex(*travPtr)]++;
			append(response.matches, *travPtr);
		}
	}

	// Whatever left in the wordCounter should be eliminated
	for (unit index = 0; index < SIZE_ALPHABET; index++)
	{
		if (wordCounter[index])
			append(response.elims, getChar(index));
	}

	// Fill response
	response.numMatches = sum(secretCounter, SIZE_ALPHABET);
}

/* Append a char to a string */
void append(char *str, const char letter)
{
	unit len = strlen(str);
	str[len] = letter;
	str[len + 1] = '\0';
}

/* Get the sum of numbers in a counter array */
unit sum(const unit counter[], const unit length)
{
	unit total = 0;

	for (unit index = 0; index < length; index++)
		total += counter[index];

	return total;
}

/* Get the index of a lower case letter */
unit getIndex(const char letter)
{
	return letter - FIRST_LETTER;
}

/* Get the lower case letter from the index */
char getChar(const unit index)
{
	return static_cast<char>(index + FIRST_LETTER);
}

/* Check if a letter is in the lower case alphabet */
bool isValidChar(const char letter)
{
	// Simply check if the letter is between the first and last letter
	return (letter >= FIRST_LETTER) && (letter <= LAST_LETTER);
}

/* Display response */
void showResponse(const ResponseType &response)
{
	cout << "Guess: " << response.guess << '\n'
		<< "Number of letters matched: " << response.numMatches << '\n'
		<< "Letter matched: " << response.matches << '\n'
		<< "Letters eliminated: " << response.elims << '\n' << endl;
}

/* Clean memory leaks */
void clean(ResponseType &response)
{
	delete[] response.matches;
	delete[] response.elims;
	delete[] response.guess;
}
