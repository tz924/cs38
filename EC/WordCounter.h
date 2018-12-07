//
//	Assignment name:	Extra Credit Summer
//  File name:			WordCounter.h
//  Author:				Jing Zhang
//

#pragma once

#include <iostream>
#include <algorithm>	// std::remove_if
#include <map>
#include <vector>
#include <string>
#include <sstream>

using std::map;
using std::vector;
using std::string;
using std::istream;

typedef unsigned int unit;

using wordCountPair = std::pair<string, unit>;

class WordCounter
{
private:
	// This is for counting
	map<string, unit> mWordMap;

	// This is for sorting
	vector<wordCountPair> mWordVec;
public:
	// Default constructor
	WordCounter();

	// Sort the word counts by counts
	void sortByCounts(bool descending = true);

	// Display the word counts
	void display();

	// Overloaded >> for each counting
	friend istream & operator>>(istream &in, WordCounter &wc);
};