#pragma once
#include "campaign.h"
#include "character.h"
#include "map.h"
#include "panel.h"
#include "bully.h"
#include "nimble.h"
#include "tank.h"

class Load
{
public:
	Load();
	Campaign* loadCampaign(std::string name);
	Character* loadPlayer(std::string name);
	Map* loadMap(std::string name);
	Elemental* loadEnemy(std::string name);

	void loadExit(panel* _panel, Campaign*, std::string mapName);
	void loadEntrance(panel* _panel, Campaign*, std::string mapName);

	//std::string cellOutput(char cell, panel* p);
private:
	std::string DIR = "C:\\Users\\Charmander\\Desktop\\SavedInstances\\";

};

// C:\\Users\\Vanessa\\Desktop\\temp\\SavedInstances\\ != C:\\Users\\Vanessa\\Desktop\\temp\\SavedInstances
///////////////////////////////////////////////////o//////////////////////////////k/////////////////////////////////