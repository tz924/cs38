/*
 * Assignment name:	Game Project 2
 * File name:		gp2.cpp
 * Author:			Jing Zhang
 * Note:			Story Map https://goo.gl/21eHUc
 * Originally I was going to use a tree and write helper functions involves
 * pointers but then I thought about practicing the materials covered and
 * changed them back to arrays.
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/* The entry point of the program */
int main()
{
	const int NBR_ELEMENTS = 18;
	const int MAX_OPTIONS = 2;
	const int INVALID_OPTION = -1;
	const int END = -2;

	// Initialize story elements
	const string STORY_ELEMENTS[NBR_ELEMENTS] =
	{
		// Element 0
		"You are an engineer who works in a game company.\n"
		"You and your company are ready to make a new game.",

		// Element 1
		"D (stands for Dream) is a well-known game developer"
		" who just lost a lot of money in his last game.\n"
		"He proposed a completely new idea for that game.\n"
		"However, his co-workers don't believe that the game can make any"
		" money because it is too risky.",

		// Element 2
		"Play safe.\n"
		"You and your co-workers decide to use an old idea to make the game.\n"
		"The process is pretty smooth.",

		// Element 3
		"You quit your job and join D.\n"
		"You two struggle to design, code and test the game.\n"
		"You learn new skills and meet different people every single day.",

		// Element 4
		"D understands that your company doesn't want to take a risk.\n"
		"\"We would never be afraid to get up if every new day is simply the\n"
		"same as the days before. However, if every day is simply repeating\n"
		"the previous ones, why would we ever want to get up?\" - D",

		// Element 5
		"You made 1,000 dollars! The game you designed is very similar to many"
		" others in the market.\nIt stops making money in a short period of "
		" time.\nYou have to continue to make another one so that you can"
		" keep making money.",

		// Element 6
		"THE END:\nYou lost 2,000 dollars!\n"
		"You started to hate your career and decided to quit the job.",

		// Element 7
		"YOU WIN!\nYou and D created a great game.\nYour company became the"
		" leader in the game industry!",

		// Element 8
		"The game doesn't end up well. You lose 5,000 dollars.",

		// Element 9
		"You made a game based on the old idea.",

		// Element 10
		"You learned from your failures and immediately made another"
		" innovative game!",

		// Element 11
		"THE END:\nYou lose 5,000 dollars!\n"
		"You regret the decision of quitting your job.",

		// Element 12
		"THE END:\nYou lose 2,000 dollars!\n"
		"Do you regret your decision?",

		// Element 13
		"THE END:\nYou lose 5,000 dollars!\n"
		"Do you regret your decision?",

		// Element 14
		"YOU WIN!\nYou and D created a great game.\nYour company became the "
		" leader in the game industry!",

		// Element 15
		"You make 2,000 dollars! Do you regret your choices?",

		// Element 16
		"FUTURE AWAITS!",

		// Element 17
		"THE END"
	};

	const string OPTIONS[NBR_ELEMENTS] =
	{
		// Options for element 0
		"1] Look for new ideas\n"
		"2] Do whatever your boss wants you to do\n",

		// Options for element 1
		"1] Accept the proposal\n"
		"2] Reject the proposal\n",

		// Options for element 2
		"1] Work very hard\n"
		"2] Slack off\n",

		// Options for element 3
		"1] Work as hard as you can\n"
		"2] Put a little effort\n",

		// Options for element 4
		"1] Change your mind\n"
		"2] Remain silent\n",

		// Options for element 5
		"1] Okay, let's make another one.\n",

		// Options for element 6
		"",

		// Options for element 7
		"",

		// Options for element 8
		"1] Don't give up\n"
		"2] Give up\n",

		// Options for element 9
		"1] Take the project seriously,"
		" but you will feel exhausted every single day\n"
		"2] Don't take it seriously\n",

		// Options for element 10
		"1] Work really hard and enjoy your work\n"
		"2] Work for money only\n",

		// Options for element 11
		"",

		// Options for element 12
		"",

		// Options for element 13
		"",

		// Options for element 14
		"",

		// Options for element 15
		"1] I got a new idea! Let's do it!\n"
		"2] Let's keep up the good work and make a great game\n",

		// Options for element 16
		"",

		// Options for element 17
		""
	};

	const int OPTION_MAP[NBR_ELEMENTS][NBR_ELEMENTS] =
	{
		{ 1, 2 },				// Element 0
		{ 3, 4},				// Element 1
		{ 5, 6 },				// Element 2
		{ 7, 8 },				// Element 3
		{ 3, 9 },				// Element 4
		{ 0, INVALID_OPTION },	// Element 5
		{ END, END },			// Element 6
		{ END, END },			// Element 7
		{ 10, 11 },				// Element 8
		{ 12, 13 },				// Element 9
		{ 14, 15 },				// Element 10
		{ END, END },			// Element 11
		{ END, END },			// Element 12
		{ END, END },			// Element 13
		{ END, END },			// Element 14
		{ 16, 17 },				// Element 15
		{ END, END },			// Element 16
		{ END, END },			// Element 17
	};

	int elementIndex = 0, option;

	// The logical part of the non-linear story program begins
	while (true)
	{
		// Display the story element
		cout << "---\n" << STORY_ELEMENTS[elementIndex] << endl;

		// If the story ends, break out of the loop
		if (elementIndex	// Ignore the first time (short-circuiting)
			&& OPTION_MAP[elementIndex][option - 1] == END)
			break;

		// Get and validate user input
		do
		{
			// Prompt the user
			cout << "---\nWhat would you do?\n\n"
				<< OPTIONS[elementIndex] << '\n'	// Display options
				<< "Enter an option (a number): ";
			cin >> option;

			// Little spacing after user input
			cout << endl;
		} while ((option <= 0 || option > MAX_OPTIONS)	// Invalid range
			|| OPTION_MAP[elementIndex][option - 1] == INVALID_OPTION);

		// Update the story element
		elementIndex = OPTION_MAP[elementIndex][option - 1];
	}

	system("pause");
	return 0;
}
