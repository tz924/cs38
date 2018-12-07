//
//	Assignment name:	Game Project 5
//  File name:			gp5.cpp
//  Author:				Jing Zhang
//  Note:				Implementation of Scene class
//

#include "gp5.h"

using namespace std;

// Default constructor
Scene::Scene(string text /* = "" */,
	vector<Prompt> prompts /* = vector<string>() */,
	Scene * nextScene /* = nullptr */) :
	mText(text), mPrompts(prompts), mNextScene(nextScene)
{};

// A scene with no prompts is an end scene.
bool Scene::isEndScene() const
{
	// Not having a next scene implies end scene
	return this->mPrompts.empty();
};

// Display the scene text in proper format
void Scene::displaySceneText() const
{
	cout << (this->mText.empty() ? "Empty Scene Text" : this->mText) << endl;
};

// Display prompts in proper format
void Scene::displayPrompt(bool debug /* = false */) const
{
	// No prompt displayed for end scene
	if (this->isEndScene())
		cout << "End Scene" << endl;
	else
		for (auto prompt : this->mPrompts)
		{
			cout << prompt.promptText;
			if (debug)
				cout << ": " << prompt.choice;
			cout << endl;
		}
};

// Display the scene in proper format
void Scene::display(bool debug /* = true */) const
{
	cout << "Scene Text:" << endl;
	this->displaySceneText();

	cout << endl;

	cout << "Prompts:" << endl;
	this->displayPrompt(debug);
}

bool Scene::isValidOption(const int option) const
{
	return (option > 0 && option <= static_cast<int>(this->mPrompts.size()));
}

void Scene::update(const int option, const vector<Scene *> &scenes)
{
	int choice = this->mPrompts.at(option - 1).choice;
	this->mNextScene = scenes.at(choice - 1);
}

Scene * Scene::getNextScene() const
{
	return this->mNextScene;
}
