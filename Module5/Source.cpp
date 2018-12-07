#include <iostream>
#include <string>
using namespace std;
int & max(int numbers[5]);
int main()
{
	string *pstring = new string[5];

	system("pause");
	return 0;
}

int & max(int numbers[5])
{
	static int x = numbers[0];
	return x;
}