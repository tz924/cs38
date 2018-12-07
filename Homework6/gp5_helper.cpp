//
//	Assignment name:	Game Project 5
//  File name:			gp5_helper.cpp
//  Author:				Jing Zhang
//  Note:				Story Map https://goo.gl/21eHUc
//

#include "gp5.h"

using namespace std;

// Check if file reading is successful
void checkFile(const ifstream &storyStream)
{
	if (storyStream.fail()) {
		cout << "Can't open file " << IN_FILE_STORY << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
}

// Read through file once and get the number of scenes
void getSceneCount(ifstream &storyStream, int &sceneCount)
{
	string line;
	while (!storyStream.eof())
	{
		// Read each line from the file
		getline(storyStream, line);

		// Count the number of scenes (must be non-empty line)
		if (line.at(0) == SCENE_INDICATOR)
			sceneCount++;
	}

	// Once done, move back to the beginning to the file
	storyStream.clear();
	storyStream.seekg(0, ios::beg);
}

/* Remove the delimiter in scene text */
void formatSceneText(string &sceneText)
{
	regex delim("\\#[0-9]+\\s");
	sceneText = regex_replace(sceneText, delim, "");
}

// Parse scene text from scene stream (contains scene text + prompts)
void parseSceneText(istringstream &sceneStream, string &sceneText)
{
	string line;

	while (sceneStream.peek() != PROMPT_INDICATOR)
	{
		getline(sceneStream, line);
		if (!sceneText.empty())
			sceneText += '\n';
		sceneText += line;
	}
	formatSceneText(sceneText);
}

// Parse prompt text into vector
void parsePrompt(istringstream &sceneStream, vector<Prompt> &prompts)
{
	string promptText, choiceText;
	unit choice;
	while (!sceneStream.eof())
	{
		// Each time we get 2 lines
		getline(sceneStream, promptText);
		getline(sceneStream, choiceText);

		// Convert choice from text to number
		istringstream choiceStream(choiceText);
		choiceStream >> choice;

		// Start at index 1, remove the delimiter
		Prompt prompt = { promptText.substr(1), choice };
		prompts.push_back(prompt);
	}
}

// Parse scene text and vector of prompts into Scene, return a Scene pointer
Scene * parseScene(string &sceneLines, vector<Prompt> &prompts)
{
	string prompt, sceneText = "";
	Scene * scene = new Scene;

	// If the the scene lines contain any prompt (not end scene)
	if (sceneLines.find(PROMPT_INDICATOR) != string::npos)
	{
		istringstream sceneStream(sceneLines);
		parseSceneText(sceneStream, sceneText);

		parsePrompt(sceneStream, prompts);

		// Store the parsed value into scene
		*scene = Scene(sceneText, prompts);
	}
	// Must be end scene
	else
	{
		formatSceneText(sceneLines);

		// Scene text = Scene lines
		*scene = Scene(sceneLines);
	}

	return scene;
}

/* Parse raw text into block of Scene text + prompts */
void parseSceneLines(ifstream &storyStream, string &sceneLines)
{
	string line;

	getline(storyStream, line);

	// Add back the newline char that getline removed
	if (!sceneLines.empty())
		sceneLines += '\n';

	sceneLines += line;
}
