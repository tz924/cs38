#include <string>
#include <iostream>
using namespace std;

class divide_zero
{
public:
	int m_numerator;
	divide_zero(int);
	string errMsg();
};

divide_zero::divide_zero(int n) : m_numerator(n)
{
}

string  divide_zero::errMsg()
{
	string s = "Exception: dividing ";
	s = s + to_string(m_numerator);
	s += " by zero\n";
	return s;
}

int divide(int x, int y)
{
	if (y == 0)
		throw divide_zero(x);
	return x / y;
}

int main()
{
	int result;

	try
	{
		result = divide(10, 2);
		cout << result << '\n';

		result = divide(10, 0);
		cout << result << '\n';
	}
	catch (divide_zero e)
	{
		cout << e.errMsg();
	}

	system("pause");
}
