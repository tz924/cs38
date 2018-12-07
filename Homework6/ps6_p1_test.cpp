//
//	Assignment name:	Problem Set 6
//  File name:			ps6_p1_test.cpp
//  Author:				Jing Zhang
//

#include "ps6.h"

using namespace std;

void part1Test()
{
	int dollar12 = 12;
	int cents3 = 3;
	int cents30 = 30;
	int cents300 = 300;
	double goodCash = 12.3;
	double badCash = 1.234;
	double crazyCash = 123.456;

	// Test default constructor
	Money m;
	m.show();	// Should be $0.00

	// Test 2-arg int constructor
	Money m21(dollar12, cents3);
	m21.show();	// Should be $12.03

	Money m22(dollar12, cents30);
	m22.show();	// Should be $12.30

	Money m23(dollar12, cents300);
	m23.show();	// Should be $15.00

	Money m24(dollar12);
	m24.show();	// Should be $12.00

	// Test 1-arg double constructor
	Money m11(goodCash);	// Should be $12.30
	m11.show();

	Money m12(badCash);		// Should be $1.23
	m12.show();

	Money m13(crazyCash);	// Should be $123.45
	m13.show();

	// Test copy constructor
	Money mCopy = m13;
	mCopy.show();	// Should be $123.45

	// Test destructor
	Money *cash = new Money(mCopy);
	mCopy.show();	// Should be $123.45
	delete cash;

	// Test 2-arg int set
	mCopy.set(dollar12, cents3);	// Should be $12.3
	mCopy.show();

	try
	{
		mCopy.set(dollar12, cents300);	// Won't allow
	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	// Test 1-arg double set
	mCopy.set(goodCash);
	mCopy.show();	// Should be $12.30

	// Test increase
	mCopy.increase(dollar12, cents30);
	mCopy.show();	// Should be $24.60
	mCopy.increase(dollar12, cents300);
	mCopy.show();	// Should be $39.60

	// Test decrease
	mCopy.decrease(dollar12, cents30);
	mCopy.show();	// Should be $27.30
	mCopy.decrease(dollar12, cents300);
	mCopy.show();	// Should be $12.30 (Back)

	// Test += with another object
	Money myWallet;
	myWallet.show();
	myWallet += mCopy;
	myWallet.show();	// Should be $12.30

	// Test += with a double
	myWallet += 12.3;	// double literal
	myWallet += goodCash;	// double variable
	myWallet.show();	// Should be $36.90

	// Test << and >>
	cin >> m;	// 11 22 will be $11.22
	cout << m;	// Display the above

	// Test comparison (Should show all 4)
	Money treasure(1);
	Money bank(2);
	if (treasure < bank)
		cout << "I'm richer" << endl;

	if (bank > treasure)
		cout << "I'm poorer" << endl;

	treasure += 1;
	if (treasure == bank)
		cout << "I am lucky" << endl;

	bank += 1;
	if (treasure != bank)
		cout << "I don't care" << endl;
}
