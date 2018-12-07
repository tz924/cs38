#include <iostream>
#include <string>
using namespace std;

const unsigned int LENGTH = 10;
int arr[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int ones[LENGTH] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int* displayFirstEven(int *a)
{
	static int *p;
	for (p = a; p - a < LENGTH; p++)
	{
		if (!(*p % 2)) return p;
	}

	return nullptr;
}

int main()
{
	// int sum = 0;
	// for (int *p = arr; p - arr < LENGTH; p++)
	// {
	// 	sum += (*p);
	// }
	// cout << sum << endl;

	if (displayFirstEven(ones) == nullptr)
		cout << "No even number in array" << endl;

	cout << "First even: " << *displayFirstEven(arr) << endl;

	system("pause");
	return 0;
}
