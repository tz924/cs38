/**
 * Assignment name:	Game Project 3
 * File name:		gp3.cpp
 * Author:			Jing Zhang
 * Notes:
 * C++ implementation of the game "Hangman".
 * I draw the ASCII art myself.
 */

#include "g3.h"
using namespace std;

/* The entry point of the program */
int main()
{
	// Use the system time as random seed
	srand(static_cast<unsigned int>(time(0)));

	// Ask the user to pick a difficulty level
	int difficulty;
	do
	{
		cout << "Pick a difficulty level:\n"
			<< "[1] EASY\n"
			<< "[2] MEDIUM\n"
			<< "[3] HARD\n"
			<< "> ";
		cin >> difficulty;
		flush();

		// Consider all possibilities for we
	} while (difficulty < EASY || difficulty > HARD);

	// Randomly get the word from the corresponding list
	int wordIndex = rand() % NUM_WORDS;
	const string word = (difficulty == EASY) ?
		VOCABULARY_EASY[wordIndex] :	// Easy
		(difficulty == MEDIUM) ?
		VOCABULARY_MEDIUM[wordIndex] :	// Medium
		VOCABULARY_HARD[wordIndex];		// Hard

	// Dynamic programming - avoid repetitive calls
	int size = word.size();

	// Use a boolean vector to track word display
	vector<bool> revealed(size);

	// Used letters board
	bool used[NUM_LETTERS] = { false };

	// Initialize to false
	for (int index = 0; index < size; index++)
	{
		revealed.at(index) = false;
	}

	// Use a matrix to record the word's letters' indices
	vector<vector<int>> wordMatrix(NUM_LETTERS);	// vector of vectors of int

	for (int index = 0; index < size; index++)
	{
		// Grab that letter in the word
		char letter = word.at(index);

		// Store the index of that letter to a vector
		wordMatrix.at(getLetterIndex(letter)).push_back(index);
	}

	int correct = 0, incorrect = 0, choice;
	string guessedWord;
	// This is for correctly guess the word
	bool bingo = false;
	char guessed;

	do
	{
		// Show the picture of hangman
		showHangman(incorrect);
		cout << '\n';

		// Display the word to be guessed as a series of underscores
		displayWord(word, revealed);
		cout << '\n';

		// Display used letter board
		displayUsed(used);
		cout << '\n';

		do
		{
			cout << "Do you want to a guess letter or word?\n"
				<< "[1] Letter\n"
				<< "[2] Word\n"
				<< "> ";
			cin >> choice;
			flush();
		} while (choice < LETTER || choice > WORD);

		if (choice == LETTER)
		{
			// Ask the user to guess a letter [A-Z]
			do
			{
				cout << "Guess a letter [A-Z]: ";
				cin >> guessed;
				flush();
			} while (guessed < FIRST_LETTER || guessed > LAST_LETTER);

			int letterIndex = getLetterIndex(guessed);

			// If the letter is used
			if (used[letterIndex])
			{
				cout << "You have already guessed " << guessed
					<< ". Pick another!\n";
				continue;
			}

			// If the letter is in the word
			if (isInWord(guessed, wordMatrix))
			{
				// Indicate to the user where that letter belongs
				for (auto index : wordMatrix.at(letterIndex))
				{
					revealed[index] = true;
					cout << "Letter at index " << index << " revealed\n";
				}

				// Redisplay the word to be guessed with those letters filled in
				displayWord(word, revealed);

				// Update guess count
				correct++;

				// Update used board
				used[letterIndex] = true;
			}
			else	// If the letter is not in the word
			{
				// The user has used one incorrect guess
				incorrect++;
			}
		}
		else if (choice == WORD)
		{
			cout << "Enter your a word: ";
			cin >> guessedWord;
			flush();
			if (guessedWord == word)
			{
				correct++;
				bingo = true;	// Shortcut to win
				break;
			}
			else
			{
				incorrect++;
			}
		}

		// Show summary
		cout << "Correct guesses: " << correct << '\n'
			<< "Incorrect guesses: " << incorrect << '\n';

		cout << endl;

		// Can play as along as not lose and not win
	} while (!win(revealed) && !lose(incorrect));

	if (bingo || win(revealed))
	{
		cout << "You won!" << '\n';
	}
	else
	{
		cout << "The word is: " << word << endl;
		cout << DEAD << endl;
		cout << "You lost!" << endl;
	}

	system("pause");
	return 0;
}

/* Properly display the word */
void displayWord(const string word, const vector<bool> revealed)
{
	int size = word.size();

	for (int index = 0; index < size; index++)
	{
		// If revealed, show letter otherwise blank
		cout << (revealed[index] ? word.at(index) : BLANK) << ' ';
	}
	cout << '\n';
}

/**
 * Analyze the word and store its information in a matrix
 *
 * For example, take the word "hello"
 * {
 *		index of 'h': { 0 },
 *		index of 'e': { 1 },
 *		index of 'l': { 2, 3 },
 *		index of 'o': { 4 }
 * }
 */
void analyzeWord(const string word, vector<vector<int>> &matrix)
{
}

/* Get the index of an upper case letter - e.g. A - 0, C - 2 */
int getLetterIndex(const char letter)
{
	return letter - FIRST_LETTER;
}

/* Check if a letter is in a word */
bool isInWord(const char letter, const vector<vector<int>> matrix)
{
	// Check if the vector at that letter index in the matrix is non-empty
	return !matrix.at(getLetterIndex(letter)).empty();
}

/* Check revealed vector for win condition */
bool win(const vector<bool> revealed)
{
	// Check if all the elements of revealed is true
	return all_of(revealed.begin(), revealed.end(), [](bool b) {return b; });
}

/* Check incorrect for lose condition */
bool lose(const int incorrect)
{
	return incorrect >= CHANCES;
}

/* Show the hangman ASCII art accordingly */
void showHangman(const int incorrect)
{
	cout << HANGMAN[incorrect] << endl;
}

/* Show used letters as underscores */
void displayUsed(const bool used[])
{
	int mid = NUM_LETTERS / 2;
	for (int index = 0; index < NUM_LETTERS; index++)
	{
		// Give it some spacing
		if (index == mid) cout << '\n';

		// ASCII value plus 'A'
		cout << (used[index] ?
			BLANK : static_cast<char>(index + FIRST_LETTER)) << " ";
	}
	cout << '\n';
}

/* Flush stream for cin */
void flush()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
