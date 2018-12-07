#pragma once

#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <vector>

typedef unsigned int unit;
using std::string;
using std::vector;

#include "Player.h"

#include "Pile.h"
#include "DrawPile.h"

#include "Card.h"
#include "ExplodingKitten.h"
#include "DefuseCard.h"
#include "NopeCard.h"
#include "AttackCard.h"
#include "SkipCard.h"
#include "FavorCard.h"
#include "ShuffleCard.h"
#include "SeeTheFutureCard.h"

// Constants
static unit MIN_NUM_PLAYERS = 2;
static unit MAX_NUM_PLAYERS = 5;
static unit DEF_NUM_PLAYERS = 2;
static string GAME_TITLE = "EXPLODING KITTENS";
static unit INDEX_START = 1;
static unit MAX_NAME_LEN = 20;
static unit SOLE_SURVIVOR = 1;
static unit MIN_ACTION_INDEX = 1;
static unit MAX_ACTION_INDEX = 2;
static unit PASS = 1;
static unit PLAY = 2;

// Helper functions
int getNumPlayers();
bool isValidNumPlayers(int numPlayers);

void displayPlayers();
void populate();
// Check if game is over (all exploded but one)
bool gameOver();
int getSurvived();
double getChanceOfExplosion();

// Get the actions the player is going to take
int getAction();
bool isValidAction(int actionIndex);
// Simple pause
void OK();
Player *getWinner();

// Complimentary Testing Suites
void testSuites();

// Global var
extern vector<Player *> players;
extern Player *currentPlayer;
extern unit numPlayers;
extern DrawPile *drawPile;
