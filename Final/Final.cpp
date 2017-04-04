#include <iostream>
#include "miscfunc.h"
#include <string>
#include "nimble.h"
#include "bully.h"
#include "tank.h"
#include "Save.h"
#include "Load.h"
#include "item.h"
#include "itemsSaving.h"

using namespace std;



int main() {
	/////////////////////////////////////
	// DELCARE VARIABLES/POINTERS HERE //
	/////////////////////////////////////	
	Campaign* campaign;
	Character* character;

	////Load map items
	ItemsSaving *save = new ItemsSaving(); 



	panel* spawn;
	std::string userInput;
	//////////////////////////////////////
	// GREETING MESSAGE NOITHING TO SEE //
	//////////////////////////////////////
	greeting();
	
	////////////////////////////////////
	// Create campaign
	campaign = loadOrCreate();
	spawn = campaign->getSpawnPanel();

	//////////////////////////////
	// CHARACTER BUILDER
	character = loadOrCreateChar();
	

	//game items loaded
	save->loadGameItems(character->getLevel());
	///////////////////////////////
	// MAIN LOOP
	play(character, campaign, spawn);


	system("pause");
	return 0;
}

