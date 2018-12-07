#include "ps3.h"
using namespace std;
#include <iomanip> // setprecision

int main()
{
	double x[] = { 20.0, 20.004, 20.04, 20.999, 1.9, 1.09 };
	for (auto y : x)
	{
		cout << formatMoney(y) << endl;
	}

	system("pause");
	return 0;
}

string formatMoney(const double amount)
{
	stringstream stream;
	stream << fixed << setprecision(2) << amount;
	return "$" + stream.str();
}
