#include <iostream>
using namespace std;

class Date
{
public:
	int m_month;
	int m_day;

	// Constructors
	Date(int month = 1, int day = 1);

	void set(int month, int day);
	void display();
};

void Date::display()
{
	cout << this->m_month << '/' << this->m_day << endl;
}

void Date::set(int month, int day)
{
	this->m_month = month;
	this->m_day = day;
}

Date::Date(int month /* = 1 */, int day /* = 1 */)
{
	this->m_month = month;
	this->m_day = day;
}

int main()
{
	Date day;
	day.display();

	Date bmonth(9);
	bmonth.display();

	Date bday(9, 24);
	bday.display();

	system("pause");
	return 0;
}
