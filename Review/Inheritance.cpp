#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string m_name;
public:
	Animal(string name) : m_name(name) {}
	void speak() { cout << "animal talk"; }
	void show() { cout << "The name is " << m_name << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	void speak() { cout << m_name << " says woof"; }
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	void speak() { cout << m_name << " says meow"; }
};

int main()
{
	Animal a = string("no name");
	Dog fido = string("Fido");
	Cat felix = string("Felix");

	felix.speak();
	fido.show(); // Only in parent

	system("pause");
	return 0;
}
