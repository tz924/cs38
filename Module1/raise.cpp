#include <iostream>
using namespace std;

int main()
{
	int raisePct = 7;
	double salary;
	cout << "What is your salary: ";
	cin >> salary;
	cout << "Your new salary after 7% raise is: " << salary * 1.07 << endl;

	system("pause");
	return 0;
}