//
//	Assignment name:	Game Project 5
//  File name:			gp5_main.cpp
//  Author:				Jing Zhang
//  Note:				Story Map https://goo.gl/21eHUc
//

#include "gp5.h"

using namespace std;

/* The entry point of the program */
int main()
{
	// Read in the story file
	ifstream storyStream;
	storyStream.open(IN_FILE_STORY);

	// Crash if things go wrong
	checkFile(storyStream);

	// Read through the file one time to get a line count
	int sceneCount = 0;
	getSceneCount(storyStream, sceneCount);

	// Create a vector to hold all the scene pointers
	vector<Scene *> scenes;

	string sceneLines = "";
	// Parse the story file (assuming proper format)
	for (int i = 0; i < sceneCount - 1; i++)
	{
		// for count - 1 times, read until the next #
		do
		{
			parseSceneLines(storyStream, sceneLines);
		} while (storyStream.peek() != SCENE_INDICATOR);

		// Push the its pointer to the scenes vector
		vector<Prompt> prompts;
		scenes.push_back(parseScene(sceneLines, prompts));

		// Reset at the end
		sceneLines = "";
	}

	// Do once more for the last one (without the next #)
	while (!storyStream.eof())
	{
		parseSceneLines(storyStream, sceneLines);
	}

	vector<Prompt> prompts;
	scenes.push_back(parseScene(sceneLines, prompts));
	storyStream.close();

	// Game loop
	Scene *currentScene = scenes.at(0);
	unit sceneCounter = 1;

	do
	{
		cout << "\n--- Scene " << sceneCounter << " ---" << endl;

		// Display
		currentScene->displaySceneText();

		// Get and validate user input
		int option;
		do
		{
			// Prompt the user
			cout << "---\nWhat would you do?" << endl;
			currentScene->displayPrompt(); // Display options
			cout << "Enter an option (a number): ";
			cin >> option;
		} while (!currentScene->isValidOption(option));

		// Update scene
		currentScene->update(option, scenes);

		// Go to the next scene
		currentScene = currentScene->getNextScene();

		sceneCounter++;
		// If the story ends, break out of the loop
	} while (!currentScene->isEndScene());

	// Display the end scene
	cout << "--- Result ---" << endl;
	currentScene->displaySceneText();
	cout << "--- The End ---" << endl;

	// Deallocate scenes
	for (auto scene : scenes)
	{
		delete scene;
	}

	// testSuites();

	system("pause");
	return 0;
}
