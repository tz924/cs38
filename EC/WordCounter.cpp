//
//	Assignment name:	Extra Credit Summer
//  File name:			WordCounter.cpp
//  Author:				Jing Zhang
//

#include "WordCounter.h"

using namespace std;

// Constructor simply initialize the two private containers
WordCounter::WordCounter() :
	mWordMap(map<string, unit>()), mWordVec(vector<wordCountPair>())
{}

// Sorting by dump into a vector (support both directions)
void WordCounter::sortByCounts(bool descending /* = true */)
{
	// Push every word count into a vector
	for (auto iter = mWordMap.begin(); iter != mWordMap.end(); iter++)
		mWordVec.push_back(*iter);

	if (descending)	// Looked up lambda expression online
		sort(begin(mWordVec), end(mWordVec),
			[&](const wordCountPair& p1, const wordCountPair& p2)
	{ return p1.second > p2.second; });

	// Ascending
	else
		sort(begin(mWordVec), end(mWordVec),
			[&](const wordCountPair& p1, const wordCountPair& p2)
	{ return p1.second < p2.second; });
}

// Overloaded >> for each counting
istream & operator>>(istream &in, WordCounter &wc)
{
	string temp;
	in >> temp;
	// Don't store whitespace though
	if (!temp.empty())
		wc.mWordMap[temp]++;
	return in;
}

// C++ 11 onward syntax. Note that in C++ 17 you can do const& wc [word, count]
void WordCounter::display()
{
	// If not sorted, sort it
	if (mWordVec.empty())
		sortByCounts();

	for (auto const& wc : this->mWordVec)
	{
		cout << wc.first	// word (key)
			<< ": "
			<< wc.second	// count (value)
			<< endl;
	}
}
