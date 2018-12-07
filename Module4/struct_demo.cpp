#include <iostream>
#include <string>
using namespace std;

struct DateType
{
	int year;
};
struct BookType
{
	string name;
	int numPages;
	string author;
	DateType yearReleased;
};

void displayBook(const BookType & b)
{
	cout << b.name << endl
		<< b.author << endl
		<< b.numPages << endl << endl;
}
int main()
{
	BookType book1 = { "Moby Dick", 700, "Herman Melville" };
	BookType book2;
	book2.name = "Heart of Darkness";
	book2.numPages = 500;
	book2.author = "Joseph Conrad";

//	cout << book1.name << endl
//		<< book1.author << endl
//		<< book1.numPages << endl;

	BookType twoBooks[2] = 
	{
		{ "Moby Dick", 700, "Herman Melville" },
		{ "Moby Dick", 700, "Herman Melville" }
	};

	for (int i = 0; i < 2; i++)
	{
//		cout << twoBooks[i].name << endl
//			<< twoBooks[i].author << endl
//			<< twoBooks[i].numPages << endl << endl;
		displayBook(twoBooks[i]);
	}

	system("pause");
	return 0;
}