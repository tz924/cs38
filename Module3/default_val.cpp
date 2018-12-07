#include <iostream>
#include <string>
using namespace std;

// default values example
void showNames(string first, string last, 
	           string middle = "");

// reference example
void showNames2(string & name, string first,
	string last, string middle = "");

int main()
{
	showNames("sam", "sneed");
	showNames("sam", "sneed", "archibald");

	// Create an L-value to store the name
	string fullName;
	showNames2(fullName, "sam", "sneed");
	cout << fullName << endl;

	system("pause");
	return 0;
}

// default values example
void showNames(string first,
	string last,
	string middle)
{
	if (middle != "")
		middle += " ";
	cout << first << " " << middle
		<< last << endl;
}

// reference example
void showNames2(string &name, string first,
	string last,
	string middle /* defaults to empty string */)
{
	if (middle != "")
		middle += " ";
	name =  first + " " + middle + last;
}
