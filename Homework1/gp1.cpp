/*
 * Assignment name:	Game Project 1
 * File name:		gp1.cpp
 * Author:			Jing Zhang
 */

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void fortuneTeller();
void shellGame();

/* The entry point of the program */
int main()
{
	fortuneTeller();
	shellGame();

	system("pause");
	return 0;
}

/* A simulated Fortune Teller game that randomly gives an answer */
void fortuneTeller()
{
	string question, answer;

	// Get the question from the user
	cout << "What is your burning question?  > ";
	cin >> question;

	// Use current time as random seed
	srand(static_cast<unsigned int>(time(0)));
	int luckyNumber = rand() % 6 + 1;	// [1, 6]

	// Randomly choose generate one of the 6 answers
	if (luckyNumber == 1)
	{
		answer = "Not in your lifetime";
	}
	else if (luckyNumber == 2)
	{
		answer = "Maybe next week";
	}
	else if (luckyNumber == 3)
	{
		answer = "Yes!";
	}
	else if (luckyNumber == 4)
	{
		answer = "Probably!";
	}
	else if (luckyNumber == 5)
	{
		answer = "Give me $100 and I'll tell you";
	}
	else
	{
		answer = "Of course!";
	}

	// Display the answer
	cout << "The fortune teller has answered:  " << answer << endl;
}

/* A game in which user can guess which box contains the shell (2 tries) */
void shellGame()
{
	// Save the strings to avoid repetition
	const string BINGO = "Correct!\n";
	const string INCORRECT = "This is incorrect.\n";
	const string PROMPT = "Where is the shell?  Choose box 1 - 5  > ";

	// Randomly generate the correct box (once generated it won't change)
	srand(static_cast<unsigned int>(time(0)));
	const int correct = rand() % 5 + 1;	// [1, 5]

	// Let the user guess
	int guess;	// Assume valid input
	cout << PROMPT;
	cin >> guess;

	// First try
	if (guess == correct)
	{
		cout << BINGO;
	}
	// Second try (Only if the user missed the first)
	else
	{
		cout << INCORRECT
			<< "You may try again.\n"
			<< PROMPT;
		cin >> guess;

		if (guess == correct)
		{
			cout << BINGO;
		}
		else
		{
			cout << INCORRECT;
		}
	}
}
