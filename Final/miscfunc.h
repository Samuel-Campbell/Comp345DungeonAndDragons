#include "campaign.h"
#include "character.h"
#include "mapobserver.h"
#include "nimble.h"
#include "tank.h"
#include "bully.h" 

#ifndef MISCFUNC_H
#define MISCFUNC_H

///////////////////////////
// Greeting Message
void greeting();

///////////////////////////
//Character Creator
Character* makeCharacter();

///////////////////////////
//LOAD CHARACTER
Character* loadCharacter();

//////////////////////////
//Make Or Create character
Character* loadOrCreateChar();

///////////////////////////
// Create Enemy ADDTHIS
Character* makeEnemy();

///////////////////////////
// Campaign Creator
Campaign* createCampaign();


///////////////////////////
// Load Campaign
Campaign* loadCampaign(); 

//////////////////////////
// Display user's directory
void displayDirectory(std::string);

/////////////////////////
// LOAD OR CREATE CAMPAIGN
Campaign* loadOrCreate();
Character* loadCharacter();

//////////////////////////
//Play
void play(Character* player, Campaign* campaign, panel* playerOnMap);

static const std::string DIRECTORY = "C:\\Users\\Charmander\\Desktop\\SavedInstances\\";
#endif // MISCFUNC_H
 