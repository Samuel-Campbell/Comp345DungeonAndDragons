#pragma once
#include "campaign.h"
#include "character.h"
#include "map.h"
#include "panel.h"


class Save
{
public:
	Save();
	void saveCampaign(Campaign* campaign);
	void savePlayer(Character* character);
	void saveMap(Map* map);
	void savePanel(panel* _panel);
	void saveEntrance(panel* _panel);
	void saveExit(panel* _panel);

	std::string cellOutput(char cell, panel* p);
private:
	std::string DIR = "C:\\Users\\Charmander\\Desktop\\SavedInstances\\";
};

