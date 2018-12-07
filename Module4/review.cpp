#include <iostream>
#include <string>
using namespace std;

string doSomething(string s, double myDoubles[], long &max, int n = 0);

int getNumbers()
{
	int inRange = 0, sum = 0, number;
	while (inRange < 10) // run from[0, 9] -> 10 times
	{
		cout << "Enter a number: ";
		cin >> number;
		if (number < 100 || number > 199) continue;
		sum += number;
		inRange++;
	}
	return sum;
}

int main()
{
	int numbers[20];
	string cities[] = { "shanghai", "paris", };
	string sorted[]

		int length = 0;
	// Get length of the cities array
	for (auto city : cities)
	{
		length++;
	}
	string temp;
	// Bubble sort
	for (int n = 1; n < length - 2; n++)
	{
		// middle condition ->[length - 1, 2]
		for (int index = 0; index < length - n; index++)
		{
			// First "greater than" (in natural order) the second
			if (cities[index].compare(cities[index + 1]) > 0)
			{
				// swap
				string temp = cities[index];
				cities[index] = cities[index + 1];
				cities[index + 1] = temp;
			}
		}
	}
	for (auto city : cities)
	{
		cout << city << endl;
	}

	system("pause");
	return 0;
}
