#include <iostream>
#include <ctime>
#include <string>
using namespace std;

void fortuneTeller();

int main()
{
	int x = 15, y = 8;
	int z = x < 20 || (y = 3);
	cout << x << ' ' << y << endl;

	fortuneTeller();

	system("pause");
	return 0;
}

void fortuneTeller()
{
	int answer;
	string question;

	// Get the question from the user
	cout << "What is your burning question?  > ";
	cin >> question;

	// Use current time as random seed
	srand(static_cast<unsigned int>(time(0)));
	answer = rand() % 6 + 1;	// [1, 6]

	// Randomly choose generate one of the 6 answers
	switch (answer)
	{
	case 1:
		cout << "Not in your lifetime\n";
		break;
	case 2:
		cout << "Maybe next week\n";
		break;
	case 3:
		cout << "Yes!\n";
		break;
	case 4:
		cout << "Probably!\n";
		break;
	case 5:
		cout << "Give me $100 and I'll tell you\n";
		break;
	default:	// case 6
		cout << "Of course!\n";
		break;
	}
}
