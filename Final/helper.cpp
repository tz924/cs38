#include "EK.h"

using namespace std;

// Get a number of input from the user - validate user input
int getNumPlayers()
{
	string input;
	int numPlayers;
	do
	{
		cout << "Enter number of players ([2] 3 4 5): ";
		getline(cin, input);

		if (input.empty())
			return DEF_NUM_PLAYERS;

		stringstream sInput(input);
		sInput >> numPlayers;
	} while (!isValidNumPlayers(numPlayers));

	return numPlayers;
}

// Return if number of players entered is in the right range
bool isValidNumPlayers(int numPlayers)
{
	return (numPlayers >= static_cast<int>(MIN_NUM_PLAYERS))
		&& (numPlayers <= static_cast<int>(MAX_NUM_PLAYERS));
}

// Display the information of each player
void displayPlayers()
{
	for (auto p : players)
	{
		p->display();
		cout << endl;
	}
}

// Populate players
void populate()
{
	for (unit i = INDEX_START; i <= numPlayers; i++)
	{
		cout << "Player #" << i << ", Enter your name: ";

		// Initialize the game according to the number of players
		string name;
		int times = INDEX_START;
		do
		{
			if (times != INDEX_START)
			{
				cout << "Name must be no longer than " << MAX_NAME_LEN
					<< " characters, enter again: " << endl;
			}
			getline(cin, name);
			times++;
		} while (name.size() > MAX_NAME_LEN);

		if (name.empty())
			name = "Anonymous Cat " + to_string(i);

		players.push_back(new Player(name, i));
	}
}

// Check if game is over (all exploded but one)
bool gameOver()
{
	// Only one player standing => win
	return getSurvived() == SOLE_SURVIVOR;
}

int getSurvived()
{
	int numSurvived = 0;
	for (auto player : players)
	{
		if (player->isAlive())
			numSurvived++;
	}
	return numSurvived;
}

// Get an action from user each turn
int getAction()
{
	string input;
	int actionIndex;
	do
	{
		cout << "Pick an option:" << endl
			<< "[1] PASS" << endl
			<< "[2] PLAY" << endl;

		cout << "Your choice: ";
		getline(cin, input);

		// Default is PASS
		if (input.empty())
			return PASS;

		stringstream sInput(input);
		sInput >> actionIndex;
	} while (!isValidAction(actionIndex));

	return actionIndex;
}

// Check if an action is valid
bool isValidAction(int actionIndex)
{
	return (actionIndex >= static_cast<int>(MIN_ACTION_INDEX))
		&& (actionIndex <= static_cast<int>(MAX_ACTION_INDEX));
}

// Pause
void OK()
{
	// Pause it
	string temp;
	cout << "OK...";
	getline(cin, temp);
}

double getChanceOfExplosion()
{
	int exploded = numPlayers - getSurvived();
	int totalEK = numPlayers - 1;
	if (!drawPile->getSize())
	{
		cout << "Not enough exploding kittens" << endl;
		exit(EXIT_FAILURE);
	}
	return (totalEK - exploded) / static_cast<double>(drawPile->getSize());
}

Player *getWinner()
{
	for (auto player : players)
	{
		if (player->isAlive())
			return player;
	}
	return nullptr;
}
