#include <iostream>
#include <string>
using namespace std;

int main()
{
	string verb;
	string bodyPart;
	string largeNumber;
	string activity;
	string beverage;
	string smallNumber;
	string noun;
	string animal;
	string nickName;

	cout << "Enter a verb present tense: ";
	getline(cin, verb);

	cout << "Enter a body part: ";
	getline(cin, bodyPart);

	cout << "Enter a large number: ";
	getline(cin, largeNumber);

	cout << "Enter an activity: ";
	getline(cin, activity);

	cout << "Enter a beverage: ";
	getline(cin, beverage);

	cout << "Enter a small number: ";
	getline(cin, smallNumber);

	cout << "Enter a noun: ";
	getline(cin, noun);

	cout << "Enter a type of animal: ";
	getline(cin, animal);

	cout << "Enter your nickname: ";
	getline(cin, nickName);

	cout << "Dear Professor Plum,\n"
		<< "I cannot make it to class this afternoon. "
		<< "I am very sick and cannot stop " << verb
		<< " my " << bodyPart << ". "
		<< "I have a fever of " << largeNumber
		<< " degrees and the doctor ordered me to " << activity
		<< " and drink lots of " << beverage << ". "
		<< "Also, can I have a " << smallNumber
		<< " day extension on the essay about " << noun << "? "
		<< "My " << animal << " ate it and now I have to start all over.\n\n"
		<< "Best wishes,\n"
		<< nickName << "!" << endl;

	system("pause");
	return 0;
}