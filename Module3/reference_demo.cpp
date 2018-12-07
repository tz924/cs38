#include <iostream>
using namespace std;

void makeMoney(double amount, 
	           int & dollars, int &cents)
{
	dollars = static_cast<int>(amount);
	amount -= dollars;
	amount *= 100;
	cents = static_cast<int>(amount);
}

int main()
{

	int dollars, cents;
	makeMoney(3.05, dollars, cents);
	cout << "The amount is: $" 
		<< dollars << "." << cents << endl;
	system("pause");
	return 0;
}
