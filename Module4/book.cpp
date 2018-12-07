#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

struct Book
{
	string title;
	unsigned int numberOfPages;
	string author;
};

int main()
{
	// Create two books
	Book book1 = { "Educated: A Memoir", 352, "Tara Westover" };
	Book book2 = { "The C++ Programming Language",1376, "Bjarne Stroustrup" };

	// Display them
	cout << "Title: " << book1.title << '\n'
		<< "Pages: " << book1.numberOfPages << '\n'
		<< "Author: " << book1.author << "\n\n"
		<< "Title: " << book2.title << '\n'
		<< "Pages: " << book2.numberOfPages << '\n'
		<< "Author: " << book2.author << endl;

	system("pause");
	return EXIT_SUCCESS;
}
