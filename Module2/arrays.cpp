#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int SIZE = 3;
	string animals[SIZE];
	animals[0] = "dog";
	animals[1] = "cat";
	animals[2] = "fish";

	cout << animals[0] << " "
		<< animals[1] << " "
		<< animals[2] << endl;

	for (int index = 0; index < SIZE; index++)
	{
		cout << animals[index] << " ";
	}
	cout << endl;

	string animals2[SIZE] = { "dog", "cat", "fish" };

	// Automatically figure out size
	string animals3[] = { "dog", "cat", "fish" };

	// Zero out
	int numbers[5] = { 0 };
	int numbers2[5] = {};

	// for-each
	for (auto animal : animals)
	{
		cout << animal << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
