#include <iostream>
#include <string>
using namespace std;

const int NUM_ITEMS = 3;
enum Items { hotdog, fries, soda, invalid };
double prices[] = { 3.5, 2.25, 1.5 };
string strItems[] = { "hotdog", "fries", "soda" };

int main()
{
	string itemChoice;
	Items item1;
	//item1 = hotdog;
	cout << "What item do you want? ";
	cin >> itemChoice;

	/*	if (itemChoice == "hotdog")
			item1 = hotdog;
		if (itemChoice == "fries")
			item1 = fries;
		else
			item1 = soda;
	*/
	item1 = invalid;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (itemChoice == strItems[i])
			item1 = static_cast<Items> (i);
	}

	if (item1 == invalid)
		cout << "poor choice\n";
	else
		cout << "cost of a " << strItems[item1]
		<< " is $ " << prices[item1] << endl;

	system("pause");
}
