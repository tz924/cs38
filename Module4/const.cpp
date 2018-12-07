#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2 = v1;

	for (auto number : v2)
	{
		cout << number << endl;
	}

	system("pause");

	return EXIT_SUCCESS;
}