/**
 * Assignment name:	Game Project 3
 * File name:		gp3.h
 * Author:			Jing Zhang
 * Notes:
 * C++ implementation of the game "Hangman".
 * I draw the ASCII art myself.
 */

#pragma once

#include <algorithm>	// all_of
#include <ctime>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

const int NUM_WORDS = 20;
const string VOCABULARY_EASY[NUM_WORDS] =
{
	"LEE","SHOUT","LUNGS","CAST","NUTS","BREEZE","DONKEY","SOLAR",
	"NEIGHBORHOOD","FLOATING","MYSTERIOUS","SILLY","PENNSYLVANIA","FACING",
	"COACH","CASEY","ATTEMPT","DEEPLY","SATELLITES","HABIT"
};
const string VOCABULARY_MEDIUM[NUM_WORDS] =
{
	"EQUIVOCAL","LUCID","FERVID","DISSONANCE","ENERVATE","PRECIPITATE","ENIGMA",
	"ZEAL","ASSUAGE","LOQUACIOUS","LAUDABLE","EPHEMERAL","PRODIGAL","PLACATE",
	"GULLIBLE","OBDURATE","HOMOGENOUS","OSTENTATION","LETHARGIC","ANOMALY"
};
const string VOCABULARY_HARD[NUM_WORDS] =
{
	"ZIGZAG","FJORD","HAIKU","ZEALOUS","UNZIP","NUMBSKULL","MEMENTO",
	"BAGPIPES","BANJO","SPHINX","ROGUE","JAZZY","JUKEBOX","FISHHOOK",
	"OSTRACIZE","ZIPPY","POLKA","PHLEGM","JIFFY","TOADY"
};
enum Difficulty { EASY = 1, MEDIUM, HARD };
enum Choice { LETTER = 1, WORD };
const char FIRST_LETTER = 'A';
const char LAST_LETTER = 'Z';
const int NUM_LETTERS = LAST_LETTER - FIRST_LETTER + 1;
const char BLANK = '_';
const int CHANCES = 6;
const string HANGMAN[] =
{
	"_____________   \n"
	"	|         |	 \n"
	"	|          	 \n"
	"	|            \n"
	"	|            \n"
	"	|			 \n"
	"	|			 \n"
	"				 \n",

	"_____________   \n"
	"	|         |	 \n"
	"	|         0	 \n"
	"	|            \n"
	"	|            \n"
	"	|			 \n"
	"	|			 \n"
	"				 \n",

	"_____________   \n"
	"	|         |	 \n"
	"	|         0	 \n"
	"	|         |  \n"
	"	|            \n"
	"	|			 \n"
	"	|			 \n"
	"				 \n",

	"_____________   \n"
	"	|         |	 \n"
	"	|         0	 \n"
	"	|        /|  \n"
	"	|            \n"
	"	|			 \n"
	"	|			 \n"
	"				 \n",

	"_____________   \n"
	"	|         |	 \n"
	"	|         0	 \n"
	"	|        /|\\\n"
	"	|            \n"
	"	|			 \n"
	"	|			 \n"
	"				 \n",

	"_____________   \n"
	"	|         |	 \n"
	"	|         0	 \n"
	"	|        /|\\\n"
	"	|        /   \n"
	"	|			 \n"
	"	|			 \n"
	"				 \n",

	"_____________   \n"
	"	|         |	 \n"
	"	|         0	 \n"
	"	|        /|\\\n"
	"	|        / \\\n"
	"	|			 \n"
	"	|			 \n"
	"				 \n"
};

const string DEAD =
"_____________   \n"
"	|         |	 \n"
"	|         0	 \n"
"	|        /|\\\n"
"	|        / \\\n"
"	|		 DEAD\n"
"	|			 \n"
"				 \n";

// Function prototypes
void displayWord(const string word, const vector<bool> revealed);
int getLetterIndex(const char letter);
bool isInWord(const char letter, const vector<vector<int>> matrix);
bool win(const vector<bool> revealed);
bool lose(const int incorrect);
void showHangman(const int incorrect);
void displayUsed(const bool used[]);
void flush();
