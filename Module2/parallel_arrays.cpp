#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int NUM_ITEMS = 3;
	string items[NUM_ITEMS] = { "hotdogs", "fries", "soda" };
	double prices[NUM_ITEMS] = { 3.5,2.5,1.25 };

	for (int index = 0; index < NUM_ITEMS; index++)
	{
		cout << items[index] << " $"
			<< setiosflags(ios::fixed) << setprecision(2)
			<< prices[index] << endl;
	}

	system("pause");
	return 0;
}
