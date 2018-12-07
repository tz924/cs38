#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name = "anonymous";
	int age = 0;

	cout << "Hello World!\n";

	cout << "What is your name? ";
	cin >> name;

	cout << name << ", how old are you? ";
	cin >> age;

	cout << "Hello " << name
		<< ", you are " << age << " years old\n";

	system("pause");
	return 0;
}
