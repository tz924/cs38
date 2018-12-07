//
//	Assignment name:	Extra Credit Summer
//  File name:			test.cpp
//  Author:				Jing Zhang
//

#include "SafeArray.h"
#include "ArrayBoundsException.h"
#include "ec.h"

using namespace std;

// at(int index) - return the value of the item at the specified index.
// Throw out of bounds exception if user attempts to exceed array boundaries
void testAt()
{
	cout << "Testing at(int index)..." << endl;

	SafeArray s({ 1, 2, 3, 4, 5 });
	cout << s.size() << endl;	// Should be 5
	s.show();

	int bigIndex = 6;
	int obnoxiousIndex = -1;

	try { s.at(bigIndex); }
	catch (ArrayBoundsException & e1) {
		e1.errorMessage();

		cout << endl;

		try { s.at(obnoxiousIndex); }
		catch (ArrayBoundsException & e2) { e2.errorMessage(); }
	}

	cout << endl;
}

// put(int index, int data) - store data at the specified index.
// Throw out of bounds exception if user attempts to exceed array boundaries
void test2ArgPut()
{
	cout << "Testing put(int index, int data)..." << endl;

	SafeArray s({ 1, 2, 3, 4, 5 });
	cout << s.size() << endl;	// Should be 5
	s.show();

	int bigIndex = 6;
	int obnoxiousIndex = -1;
	int data = 1;

	try { s.put(bigIndex, data); }
	catch (ArrayBoundsException & e1) {
		e1.errorMessage();

		cout << endl;

		try { s.put(obnoxiousIndex, data); }
		catch (ArrayBoundsException & e2) { e2.errorMessage(); }
	}

	cout << endl;
}

// put(int index, int *data, int howMany) store howMany items pointed to by data
// starting at the specified index.
// Throw out of bounds exception if user attempts to exceed array boundaries
void test3ArgPut()
{
	cout << "Testing put(int index, int *data, int howMany)..." << endl;

	SafeArray s({ 1, 2, 3, 4, 5 });
	cout << s.size() << endl;	// Should be 5
	s.show();

	int bigIndex = 6;
	int obnoxiousIndex = -1;
	int data[2] = { 9, 9 };
	int howMany = 2;

	try { s.put(bigIndex, data, howMany); }
	catch (ArrayBoundsException & e1) {
		e1.errorMessage();

		cout << endl;

		try { s.put(obnoxiousIndex, data, howMany); }
		catch (ArrayBoundsException & e2) { e2.errorMessage(); }
	}

	cout << endl;
}

// removeItems(int howMany, int start) -
// removes howMany items from the start index - or from the end
// if no start index is specified
void testRemoveItems()
{
	cout << "Testing removeItems(int howMany, int start)..." << endl;

	SafeArray s({ 1, 2, 3, 4, 5 });
	cout << s.size() << endl;	// Should be 5
	s.show();

	int bigStart = 6;
	int obnoxiousStart = -1;
	int howMany = 2;

	try { s.removeItems(howMany, bigStart); }
	catch (ArrayBoundsException & e1) {
		e1.errorMessage();

		cout << endl;

		try { s.removeItems(howMany, obnoxiousStart); }
		catch (ArrayBoundsException & e2) { e2.errorMessage(); }
	}

	cout << endl;
}

void testSuitesPartI()
{
	testAt();
	test2ArgPut();
	test3ArgPut();
	testRemoveItems();
}
