#include <iostream>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction();	// Default constructor
	Fraction(int n, int d = 1);	// Normal (Overloaded Constructor)
	Fraction(const Fraction & f);	// Copy constructor
	void display() const;
	void setDenominator(int d);
	int getDenominator()  const;
	double add(double d) const;

	// Const is a valid overload
	void method1() const;
	void method1();
};

void Fraction::method1() const
{
	cout << "in the const method\n";
}

void Fraction::method1()
{
	cout << "in the non-const method\n";
}

// Not modifying members -> const
double Fraction::add(double d) const
{
	double result = static_cast<double>(m_numerator) / m_denominator;
	result += d;
	return result;
}

void Fraction::setDenominator(int d)
{
	// Make sure d is not zero
	if (!d)
	{
		throw "can't divide by zero!\n";
	}
	m_denominator = d;
}

int Fraction::getDenominator() const
{
	return m_denominator;
}

void Fraction::display() const
{
	cout << m_numerator << '/' << m_denominator << endl;
}

// Default constructor
Fraction::Fraction() :m_numerator(1), m_denominator(1)
{ }

Fraction::Fraction(int n, int d) : m_numerator(n)
{
	setDenominator(d);
}

Fraction::Fraction(const Fraction & f)
{
	// Private access allowed because within the same class
	this->m_denominator = f.m_denominator;
	this->m_numerator = f.m_numerator;
}

int main()
{
	Fraction f1, f2(2), f3(2, 4);
	cout << "Expected output: 2/4\n";
	f3.display();
	cout << f3.add(3.25) << endl;

	//Fraction f5(1, 0);

	Fraction f4 = f3;
	f4.method1();
	const Fraction f8;
	f8.method1();
	system("pause");
	return 0;
}