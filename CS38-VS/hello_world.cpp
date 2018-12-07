#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
	cout << "Hello World!\n";

	// size
	int numBytes, x;
	numBytes = sizeof(int);
	numBytes = sizeof(x);

	// character
	char c;
	c = 'x';
	cout << c << endl;

	// string using char array
	char cstr[] = "hello";	// 6 char including \0
	cout << cstr << endl;

	// string class
	string cstr2 = "hello";
	cout << cstr2 << endl;

	/* create variables and constants */
	int x;				// declare and define a variable
	int y = 1;			// declare, define and initialize a variable
	extern int z;		// declare a variable
	const int X = 1;	// declare, define and initialize a constant
	extern const int Y;	// declare a constant

	// auto
	auto m = 10;
	auto n = 3.14f;
	m += 0.5;
	cout << m << endl;

	system("pause");
	return 0;
}
