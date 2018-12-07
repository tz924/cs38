//
//	Assignment name:	Extra Credit Summer
//  File name:			ec_p2.cpp
//  Author:				Jing Zhang
//

#include "ec.h"

using namespace std;

// Parse American Pie's lyrics into word counts
void partII()
{
	// Read the lyrics from the song American Pie from the file ampie.txt.
	ifstream lyricsStream;
	lyricsStream.open(IN_FILE_LYRICS);

	// Crash if things go wrong
	if (lyricsStream.fail())
	{
		cout << "Can't open file " << IN_FILE_LYRICS << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	int studentCount = 0;

	// Start the word counter, and count
	WordCounter wordCounter;
	string line;
	while (!lyricsStream.eof())
	{
		// Read each line from the file
		getline(lyricsStream, line);

		// Remove all punctuation
		removePunctuation(line);

		// Count the words (with overloaded >> I wrote)
		istringstream lineParser(line);
		while (!lineParser.eof())
			lineParser >> wordCounter;
	}

	// Words with a higher frequency count should appear first
	// bool descending = false;	// Also support ascending
	// wordCounter.sortByCounts(descending);	// Can pass descending here
	wordCounter.display();	// "Push a button" design
}

// Remove all punctuation from a string
void removePunctuation(string &line)
{
	// Erase from the line if the following is true:
	// Iterate through line's begin to end
	// Remove if the character is a punctuation
	line.erase(remove_if(line.begin(), line.end(), ispunct));
}
