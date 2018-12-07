#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;
int numbers[] = { 1, 4, 7, 12, 34, 44, 67, 68, 69, 72, 78, 82, 85, 88, 90, 101, 110, 115, 121, 132 };

int main()
{
	int n, count = 0;
	cout << "Enter a number to find: "; cin >> n;

	int *p1 = numbers+SIZE/2 , *pend = numbers + SIZE,
		*rangeStart = numbers, *rangeEnd = numbers+SIZE;


	do 
	{
		count++;
		if (*p1 == n)
			break;
		else if (*p1 < n)
		{
			rangeStart = p1;
			p1 = rangeStart + (rangeEnd-rangeStart) / 2;
		}
		else
		{
			rangeEnd = p1;
			p1 = rangeStart + (rangeEnd - rangeStart) / 2;
		}
	} while (rangeEnd - rangeStart > 1);

	if (rangeEnd - rangeStart <= 1)
		cout << "not found\n";
	else
		cout << "found at the " << (p1 - numbers + 1) << "th item\n";

	cout << "Iterations needed: " << count << endl;
	return 0;
}