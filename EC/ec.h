//
//	Assignment name:	Extra Credit Summer
//  File name:			ec.h
//  Author:				Jing Zhang
//

#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "SafeArray.h"
#include "ArrayBoundsException.h"
#include "WordCounter.h"

const string IN_FILE_LYRICS = "ampie.txt";

// Part I testing
void testAt();
void test2ArgPut();
void test3ArgPut();
void testRemoveItems();
void testSuitesPartI();

// Part II
void partII();
void removePunctuation(string &line);
