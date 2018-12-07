//
//	Assignment name:	Extra Credit Summer
//  File name:			ArrayBoundsException.h
//  Author:				Jing Zhang
//

#pragma once

#include <iostream>
#include <string>

#include "SafeArray.h"

using std::exception;
using std::string;

// ArrayBoundsException is a child of std exception class
class ArrayBoundsException : public exception
{
private:
	string mMesseage;
public:
	// Index is int instead of unit because it may be invalid
	ArrayBoundsException(const SafeArray & arr, int index);
	~ArrayBoundsException();
	void errorMessage() const;
};
