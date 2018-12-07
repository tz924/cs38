//
//	Assignment name:	Final Project
//  File name:			Card.cpp
//  Author:				Jing Zhang
//	Notes:				This is the base class Card - "The mother of all cards"
//

#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef unsigned int unit;

using std::vector;
using std::string;

// # of cards constants
static const unit NUM_TYPES = 8;	// Without the cats cards
static const unit NUM_EXPLODING_KITTEN = 4;
static const unit NUM_DEFUSE = 6;
static const unit NUM_NOPE = 5;
static const unit NUM_ATTACK = 4;
static const unit NUM_SKIP = 4;
static const unit NUM_FAVOR = 4;
static const unit NUM_SHUFFLE = 4;
static const unit NUM_SEE_THE_FUTURE = 5;

static const unit DEFUSE_NOT_FOUND = -1;

static const unit STANDARD[NUM_TYPES] =
{
	NUM_EXPLODING_KITTEN,
	NUM_DEFUSE,
	NUM_NOPE,
	NUM_ATTACK,
	NUM_SKIP,
	NUM_FAVOR,
	NUM_SHUFFLE,
	NUM_SEE_THE_FUTURE
};

// static const unit NUM_CATS = 16;	// Expansion

// Default values constants
static const string DEF_TYPE = "Unspecified type";
static const string DEF_CARD_NAME = "Card Name";
static const string DEF_DESC = "Describe what this card does";

// Card type constants
static const string TYPE_EXPLODING = "Exploding";
static const string TYPE_DIFFUSE = "Diffuse";
static const string TYPE_NOPE = "Nope";
static const string TYPE_ATTACK = "Attack";
static const string TYPE_SKIP = "Skip";
static const string TYPE_FAVOR = "Favor";
static const string TYPE_SHUFFLE = "Shuffle";
static const string TYPE_SEE_THE_FUTURE = "See the future";
// static const string CATS = "Cats";	// Expansion feature

// Card name constants
static const string NAME_EXPLODING = "Exploding Kitten";

static const string NAMES_DEFUSE[NUM_DEFUSE] =
{
	"Belly Rubs",
	"Kitten Therapy",
	"3 a.m. Flatulence",
	"Catnip Sandwiches",
	"Kitten Yoga",
	"Laser Pointer"
};

static const string NAMES_NOPE[NUM_NOPE] =
{
	"Win The Nope-Bell Peace Prize",
	"Feed Your Opponent A Nope Sandwich With Extra Nope Sauce",
	"Nope-stradamus Peaks The Truth",
	"A Jackanope Bounds Into The Room",
	"A Nope Ninja Delivers A Wicked Dragon Kick"
};

static const string NAMES_ATTACK[NUM_ATTACK] =
{
	"Awaken The Bear-O-Dactyl",
	"Deploy The Thousand Year Back Hair",
	"Unleash The Catterwocky",
	"Fire The Crab-A-Pult"
};

static const string NAMES_SKIP[NUM_SKIP] =
{
	"Commandeer A Bunny-Raptor",
	"Engage The Hyper-goat",
	"Don A Portable Cheetah Butt",
	"Crab Walk With Some Crabs"
};

static const string NAMES_FAVOR[NUM_FAVOR] =
{
	"Get Enslaved By Party Squirrels",
	"Ask For A Back Hair Shampoo",
	"Rub Peanut Butter On Your Belly Button And Get Some New Friends",
	"Take Your Friends Beard-Sailing On Your Beard Boat"
};

static const string NAMES_SHUFFLE[NUM_SHUFFLE] =
{
	"An Electromagnetic Pomeranian Storm Rolls In From The East",
	"A Plague Of Bat Farts Descend From The Sky",
	"Abra-Crab Lincoln Is Elected President",
	"A Trans-dimensional Litter Box Materializes"
};

static const string NAMES_SEE_THE_FUTURE[NUM_SEE_THE_FUTURE] =
{
	"Feast Upon A Unicorn Enchilada and Gain Its Enchilada Powers",
	"Ask The All-Seeing Eye Goat Wizard",
	"Summon The Mantis Shrimp",
	"Rub The Belly Of A Pig-A-Corn",
	"Deploy The Special Ops Bunnies"
};

// Card description constants
static const string DESC_EXPLODING = "EXPLODING KITTEN";

static const string DESC_DIFFUSE =
"If you drew an Exploding Kitten, you can play this card instead of dying.";

static const string DESC_NOPE =
"Stop any action except for an Exploding Kitten or a Defuse Card.";

static const string DESC_ATTACK =
"Immediately end your turn without drawing and "
"force the next player to take 2 turns in a row.";

static const string DESC_SKIP =
"Immediately end your turn without drawing a card.";

static const string DESC_FAVOR =
"Force any other player to give you 1 card from their hand. "
"They choose which card to give you.";

static const string DESC_SHUFFLE =
"Shuffle the Draw Pile without viewing the cards until told to stop.";

static const string DESC_SEE_THE_FUTURE =
"Peek at the top 3 cards from the Draw Pile.";

// static const string DESC_CATS =
// "These cards are powerless on their own, but if you collect any 2 matching Cat Cards, you can play them as a Pair to steal a random card from any player";

// The base class Card
class Card
{
private:	// Restricted access
	string mType;
	string mName;
	string mDescription;

protected:	// For derived
	// Getter functions (End user don't need to call them)
	string getType() const;
	string getName() const;
	string getDescription() const;

public:
	bool isDefuse;
	bool isEK;
	// Default constructor
	Card(string = "Type", string = "Name", string = "Description");

	// Default destructor
	virtual ~Card();

	/* Polymorphic methods */

	// Pure virtual functions
	virtual void play() = 0;

	// Virtual function with default implementation
	virtual void display(bool = false) const;
};
