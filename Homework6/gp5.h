//
//	Assignment name:	Game Project 5
//  File name:			gp5.cpp
//  Author:				Jing Zhang
//  Note:				Story Map https://goo.gl/21eHUc
//

#pragma once	// Include guard

#include <iomanip>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

typedef unsigned int unit;

// Constants
const string IN_FILE_STORY = "story.txt";
const char SCENE_INDICATOR = '#';
const char PROMPT_INDICATOR = '@';

// Wrapper of promptText and its corresponding choice (route)
struct Prompt
{
	string promptText;
	unit choice;
};

class Scene
{
private:
	// The story text
	string mText;

	// Choice prompts
	vector<Prompt> mPrompts;

	// Pointers to the other scenes to jump to
	Scene *mNextScene;
public:
	// Default constructor
	Scene(string text = "",
		vector<Prompt> prompts = vector<Prompt>(),
		Scene * nextScene = nullptr);

	// Display the scene in proper format
	void displaySceneText() const;

	// Display the prompt
	void displayPrompt(bool debug = false) const;

	// Mainly for debugging purposes
	void display(bool debug = true) const;

	// A scene with no prompts is an end scene.
	bool isEndScene() const;

	// Check if a user input is valid
	bool isValidOption(int option) const;

	// Update next scene
	void update(const int option, const vector<Scene *> &scenes);

	// Getter of next scene
	Scene * getNextScene() const;
};

/* Helper functions */

// Check if read file is successful
void checkFile(const ifstream &storyStream);

// Read through file once and get the number of scenes
void getSceneCount(ifstream &storyStream, int &sceneCount);

// Remove the delimiter in scene text
void formatSceneText(string &sceneText);

// Parse scene text from scene stream (contains scene text + prompts)
void parseSceneText(istringstream &sceneStream, string &sceneText);

// Parse scene text and vector of prompts into Scene, return a Scene pointer
Scene * parseScene(string &sceneLines, vector<Prompt> &prompts);

// Parse prompt text into vector
void parsePrompt(istringstream &sceneStream, vector<Prompt> &prompts);

/* Parse raw text into block of Scene text + prompts */
void parseSceneLines(ifstream &storyStream, string &sceneLines);

// Test Suites
void testConstructor();
void testSuites();
