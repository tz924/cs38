#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int n1 = 3, n2 = 4;

	// Technique 1: width, precision, fill
	cout.width(8);
	cout << n1;

	cout.width(5);
	cout.fill('-');

	cout << n2;
	cout << endl;

	// Technique 2
	int x = 10;
	cout << dec << x << ' '
		<< oct << x << ' '
		<< hex << x << '\n';

	// Technique 3
	cout << setw(8) << setfill(' ') << n1 << endl;

	// Technique 4
	cout << setiosflags(ios::dec) << 10;

	system("pause");
	return 0;
}
