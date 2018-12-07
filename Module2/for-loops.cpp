#include <iostream>
using namespace std;

int main()
{
	// for (int n = 1; n <= 20; n += 2)
	// {
	// 	cout << n << endl;
	// }

	// for (int n = 1; n <= 20; n++)
	// {
	// 	if (n % 2 == 0)
	// 		continue;
	// 	cout << n << endl;
	// }

	// for (int n = 1; n <= 20; cout << n << endl, n += 2)
	// {
	// }

	int n1, n2;
	int start, end;
	cout << "Enter two numbers: ";
	cin >> n1 >> n2;

	if (n1 > n2)
	{
		start = n2;
		end = n1;
	}
	else
	{
		start = n1;
		end = n2;
	}

	for (int i = end; i >= start; i--)
	{
		if (i % 2 == 0)
			continue;
		cout << i << endl;
	}

	system("pause");
	return 0;
}
