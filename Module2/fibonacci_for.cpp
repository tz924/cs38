#include <iostream>
using namespace std;

int main()
{
	const int TOTAL_NUMBERS = 20;
	int current,
		prev1 = 1,		// the last one
		prev2 = 0,		// second to last one
		count;

	cout << "0 1 ";
	for (int count = 3; count <= TOTAL_NUMBERS; count++)
	{
		current = prev1 + prev2;
		cout << current << ' ';
		prev2 = prev1;
		prev1 = current;
	}
	cout << endl;

	system("pause");
	return 0;
}
