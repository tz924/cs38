#include <iostream>
using namespace std;

int main()
{
	const int TOTAL_NUMBERS = 20;
	int current,
		prev1 = 1,		// the last one
		prev2 = 0,		// second to last one
		count = 3;

	cout << "0 1 ";

	while (count <= TOTAL_NUMBERS)
	{
		current = prev1 + prev2;
		cout << current << ' ';
		prev2 = prev1;
		prev1 = current;
		count++;
	}
	cout << endl;

	system("pause");
	return 0;
}
