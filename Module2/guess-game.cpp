#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int guess, correct;

	srand(static_cast<unsigned int>(time(0)));
	correct = rand() % 10 + 1;	// [1, 10]
	// cout << "The answer is " << correct << endl;

	for (int n = 1; n <= 5; n++)
	{
		cout << "Please enter a number from 1 to 10: ";
		cin >> guess;

		if (guess < 1 || guess > 10)
		{
			cout << "Enter a number between 1 to 10\n";
		}
		else
		{
			if (guess > correct)
			{
				cout << "Too high\n";
			}
			else if (guess < correct)
			{
				cout << "Too low\n";
			}
			else
			{
				cout << "Correct\n";
				break;
			}
		}	// end else
	}

	if (guess != correct)
	{
		cout << "Sorry - you used all of your guesses. Try again!\n";
	}

	system("pause");
	return 0;
}
