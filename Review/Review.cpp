#include <iostream>
#include <string>

using namespace std;

enum Colors { red, blue, green };
string strColors[] = { "red","blue", "green" };

// Normally blue would be 1
ostream & operator << (ostream & out, const Colors & c)
{
	out << strColors[c];
	return out;
}

int &foo()
{
	static int x = 3;
	cout << x;
	return x;
}

int main()
{
	Colors myColor = blue;
	cout << myColor << endl;

	int y = 5;
	foo() = y;
	foo();

	system("pause");
	return 0;
}
