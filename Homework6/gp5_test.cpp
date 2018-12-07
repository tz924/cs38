//
//	Assignment name:	Game Project 5 Test File
//  File name:			gp5_test.cpp
//  Author:				Jing Zhang
//  Note:				For convenience of the grader (Jack)
//

#include "gp5.h"

using namespace std;

void testSuites()
{
	testConstructor();
}

void testConstructor()
{
	string text = "Story text!";
	Prompt p1 = { "Hello", 1 };
	Prompt p2 = { "Hola", 2 };
	vector<Prompt> vec{ p1, p2 };

	// Test Default constructor
	Scene s;
	s.display();
	cout << endl;

	// Test 1-arg constructor
	Scene s1(text);
	s1.display();
	cout << endl;

	// Test 2-arg constructor
	Scene s2(text, vec);
	s2.display();	// Shouldn't display prompts because it's an end scene
	cout << endl;

	// Test 3-arg constructor
	Scene s3(text, vec, &s2);
	s3.display();
}
