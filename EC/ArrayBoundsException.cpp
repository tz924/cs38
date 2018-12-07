//
//	Assignment name:	Extra Credit Summer
//  File name:			ArrayBoundsException.cpp
//  Author:				Jing Zhang
//

#include "ArrayBoundsException.h"

using namespace std;

ArrayBoundsException::ArrayBoundsException(const SafeArray & sfArr, int index)
{
	// Initialize the message
	mMesseage = "Index out of bound. Please enter a valid index.\n"
		"Current size of the SafeArray: " + to_string(sfArr.size()) + "\n"
		"Valid index range: [0, " + to_string(sfArr.size() - 1) + "]\n"
		"Index attempted: " + to_string(index);
}

ArrayBoundsException::~ArrayBoundsException()
{}

void ArrayBoundsException::errorMessage() const
{
	cout << this->mMesseage << endl;
}