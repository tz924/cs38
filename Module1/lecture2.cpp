#include <string>
#include <iostream>
using namespace std;

int x;	// global variable
void helloWolrd();

int main()
{
	/* read into a string */
	string s;
	getline(cin, s);

	/* read into a char array */
	char s2[80];
	cin.getline(s2, 80);

	helloWolrd();

	system("pause");
	return 0;
}

/* function */
void helloWolrd()
{
	cout << "Hello World" << endl;
}

void operators()
{
}