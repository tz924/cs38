#include <iostream>
using namespace std;

int main()
{
	try {
		int *p;
		p = new int;
		p[1] = 20;
		delete p;
		cout << "success!\n";
	}
	catch (...)
	{
		cout << "exception!\n";
	}
}