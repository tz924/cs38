#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;
int numbers[] = { 1, 4, 7, 12, 34, 44, 67, 68, 69, 72, 78, 82, 85, 88, 90, 101, 110, 115, 121, 132 };

int main()
{
	int n;
	cout << "Enter a number to find: "; cin >> n;

	int *p1 = numbers , *pend = numbers + SIZE;

	while (p1 <= pend)
	{
		if (*p1 == n)
			break;
		p1++;
	}

	if (p1 > pend)
		cout << "not found\n";
	else
		cout << "found at the " << (p1 - numbers + 1) << "th item\n";

	return 0;
}