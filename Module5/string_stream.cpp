#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string sentence = "Look at all these words";
	string word;
	vector<string> words;
	istringstream s(sentence);
	while (!s.eof())
	{
		s >> word;
		words.push_back(word);
	}
	for (string word: words)
		cout << word << endl;


	//--------------------------------------

	string numbers = "1 2 3 4 5";
	istringstream s2(numbers);
	int n, sum= 0;
	while (!s2.eof())
	{
		s2 >> n;
		sum += n;
	}
	cout << "The sum is: " << sum << endl;

	string order, item;
	int quantity;
	cout << "Enter quantity and item to order: ";
	getline(cin, order);

	istringstream s(order);
	s >> quantity;
	s >> item;

	cout << "Item: " << item << endl
		<< "Quantity: " << quantity << endl;

	double total = quantity * 3.63;
	ostringstream output;

	output << setprecision(2) << fixed << "$" << total;

	cout << output.str();

	ostringstream oss;
	oss << "hello " << 123 << " there\n";
	cout << oss.str();

	system("pause");
	return 0;
}