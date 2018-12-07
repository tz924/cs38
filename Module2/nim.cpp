#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int MAX_BUNDLES = 5;
	const int MAX_STICKS = 7;

	srand(static_cast<unsigned int>(time(0)));

	int bundles[MAX_BUNDLES];
	for (int index = 0; index < MAX_BUNDLES; index++)
	{
		bundles[index] = rand() % MAX_STICKS + 1;
	}

	for (int n = 0; n < MAX_BUNDLES; n++)
	{
		cout << n + 1 << "] ";
		for (int i = 0; i < bundles[n]; i++)
			cout << "|";
		cout << endl;
	}

	int sum = 0;
	for (int numSticks : bundles)
		sum += numSticks;
	cout << "Total number of sticks: " << sum << endl;

	system("pause");
	return 0;
}
