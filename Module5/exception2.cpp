#include <iostream>
#include <string>
using namespace std;

enum ball {bounce};
enum fish {fillet};

void func1(bool);
void func2();
void func3();

int main()
{
	try {
		cout << "before function1\n";
		func1(false);
		cout << "after function1\n";
		func2();
	}
	catch (ball) { cout << "Caught: ball\n"; }
	catch (fish) { cout << "Caught: fish\n"; }
	system("pause");
	return 0;
}

void func1(bool hasException)
{ 
	if (hasException)
		throw ball(); 
}

void func2() 
{ 
	throw fish(); 
}

void func3() 
{ 
	throw ("Something is wrong here"); 
}