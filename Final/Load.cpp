#include "stdafx.h"
#include "Load.h"
#include <cstdlib>


Load::Load()
{
}


Campaign* Load::loadCampaign(std::string campaignName) {
	std::string fileName = DIR + "Campaign\\" + campaignName + ".txt";
	std::ifstream readFile;
	readFile.open(fileName);

	std::string newLineDelim = "\n";
	std::string line;
	std::string mapName;
	Campaign* campaign = new Campaign();
	campaign->setName(campaignName);

	while (getline(readFile, line)) {
		mapName = line.substr(0, line.find(newLineDelim));		
		Map* map = loadMap(mapName);
		if (map->findPath()) {
			campaign->addMap(map);
		}
		else {
			map->printMap();
			std::cout << "Some maps are not acceptable in the campaign..." << std::endl;
			system("pause");
			exit(0);
			break;
		}
	}
	
	// Set map relations and we ARE DONE
	for (int i = 0; i < campaign->getCampaignSize(); i++) {
		Map* map = campaign->returnMap(i);
		for (int j = 0; j < map->getSizeWidth(); j++) {
			for (int k = 0; k < map->getSizeLength(); k++) {
				if (map->getPanel(j, k)->getPanelType() == 'x') {
					panel* p = map->getPanel(j, k);
					loadExit(p, campaign, map->getName());
				}
				else if (map->getPanel(j, k)->getPanelType() == 'e') {
					panel* p = map->getPanel(j, k);
					loadEntrance(p, campaign, map->getName());
				}
			}
		}
	}


	return campaign;
}

Map* Load::loadMap(std::string mapName) {
	std::string fileName = DIR + "Map\\" + mapName + ".txt";
	std::ifstream readFile;
	readFile.open(fileName);
	
	std::string newLineDelim = "\n";
	std::string spaceDelim = " ";
	std::string arrowDelim = "-> ";
	std::string line;
	std::string panel;
	std::string tempStr;

	// Map size
	int x, y, index, x1, y1;
	index = 0;
	x1 = 0;
	y1 = 0;
	Map* map = new Map();

	//set map name
	map->setName(mapName);

	// Read Width and Length of map
	while (getline(readFile, line)) {
		if (index == 0) {
			x = std::stoi(line.substr(line.find(spaceDelim) + 1, line.find(newLineDelim)));
			index++;
		}
		else if (index == 1) {
			y = std::stoi(line.substr(line.find(spaceDelim) + 1, line.find(newLineDelim)));			
			index++;
			map->resize(x, y);
		}
		else if (index > 1) {			
			// If empty cell
			if (line == "Empty") {
				map->fillCell(x1, y1, ' ');
			}
			// chest
			else if (line.substr(0, 1) == "c") {
				map->fillCell(x1, y1, 'c');
			}
			// Read entire line for entrance --> link later
			else if (line.substr(0, 1) == "e") {
				map->fillCell(x1, y1, 'e');				
			}
			// read entire line for monster
			// We can load this now
			else if (line.substr(0, 1) == "m") {
				map->fillCell(x1, y1, 'm');						
			}
			// player -> create character
			// We can load this now
			else if (line.substr(0, 1) == "p") {
				std::string playerName = line.substr(line.find(arrowDelim) + 3, line.find(newLineDelim));
				map->fillCell(x1, y1, 'p');
				map->getPanel(x1, y1)->setPlayer(loadPlayer(playerName));
			}
			// Read entire line for exit --> link later
			else if (line.substr(0, 1) == "x"){
				map->fillCell(x1, y1, 'x');
				//std::cout << line.substr(line.find(arrowDelim) + 3, line.find(newLineDelim));
			}
			// spawn Area
			else if (line == "s") {
				map->fillCell(x1, y1, 's');
			}
			// wall
			else if (line == "w") {
				map->fillCell(x1, y1, 'w');
			}
			y1++;
			if (y1 == map->getSizeLength()) {
				x1++;
				y1 = 0;
			}
		}		
	}	
	return map;
}

// Load character. Don't read the code
Character* Load::loadPlayer(std::string name) {
	Character* character = new Character();
	std::string fileName = DIR + "Player\\" + name + ".txt";
	std::ifstream readFile;
	readFile.open(fileName);
	std::string newLineDelim = "\n";
	std::string line;
	

	
	int index = 0;
	int level, hp;
	int ability[6];
	int lineIndex = 0;
	std::string subClass;
	std::string abilityScores;

	while (getline(readFile, line)) {
		if (index == 1) {
			level = stoi(line.substr(line.find(":") + 1, line.find(newLineDelim)));			
		}
		else if (index == 2) {
			hp = stoi(line.substr(line.find(":") + 1, line.find(newLineDelim)));
		}
		else if (index == 3) {
			subClass = line.substr(line.find(":") + 2, line.find(newLineDelim));		
		}
		else if (index == 4) {		
			abilityScores = line.substr(line.find(":") + 2, line.find(newLineDelim));
			ability[0] = stoi(abilityScores.substr(0, abilityScores.find(",")));

			abilityScores = abilityScores.substr(abilityScores.find(",") + 2, abilityScores.find(newLineDelim));
			ability[1] = stoi(abilityScores.substr(0, abilityScores.find(",")));
			
			abilityScores = abilityScores.substr(abilityScores.find(",") + 2, abilityScores.find(newLineDelim));
			ability[2] = stoi(abilityScores.substr(0, abilityScores.find(",")));

			abilityScores = abilityScores.substr(abilityScores.find(",") + 2, abilityScores.find(newLineDelim));
			ability[3] = stoi(abilityScores.substr(0, abilityScores.find(",")));

			abilityScores = abilityScores.substr(abilityScores.find(",") + 2, abilityScores.find(newLineDelim));
			ability[4] = stoi(abilityScores.substr(0, abilityScores.find(",")));

			abilityScores = abilityScores.substr(abilityScores.find(",") + 2, abilityScores.find(newLineDelim));
			ability[5] = stoi(abilityScores.substr(0, abilityScores.find(",")));
		}
		index++;
	}


	// Get character
	if (subClass == "Bully") {
		character = new Bully();
		std::cout << "bully" << std::endl;
	}
	else if (subClass == "Nimble") {
		character = new Nimble();
	}
	else if (subClass == "Tank") {
		character = new Tank();
	}

	character->setCharacterName(name);
	character->setLevel(level);
	character->setHitPoint(hp);
	for (int i = 0; i < 6; i++) {		
		character->setAbilityScore(i, ability[i]);
	}
	character->setAbilityChar();

	

	return character;
}

//Hard coded enemy
Elemental* Load::loadEnemy(std::string size) {
	Elemental* elemental = new Elemental(size);
	return elemental;
}


void Load::loadExit(panel* p, Campaign* campaign, std::string mapName) {
	std::string fileName = DIR + "Panel\\Exit\\" + mapName + ".txt";
	std::ifstream readFile;
	readFile.open(fileName);
	std::string newLineDelim = "\n";
	std::string spaceDelim = " ";
	std::string line;

	int index = 0;
	int x, y;
	std::string targetName;

	
	
	while (getline(readFile, line)) {
		if (index == 0) {
			targetName = line.substr(line.find(":") + 2, line.find(newLineDelim));

		}
		else if (index == 1) {
			x = stoi(line.substr(line.find(":") + 2, line.find(newLineDelim)));
		}
		else if (index == 2) {
			y = stoi(line.substr(line.find(":") + 2, line.find(newLineDelim)));
		}
		index++;
	}

	panel* anotherPanel = new panel();
	for (int i = 0; i < campaign->getCampaignSize(); i++) {
		if (campaign->returnMap(i)->getName() == targetName) {
			anotherPanel = campaign->returnMap(i)->getPanel(x, y);
			
		}
	}
	p->setMapName(mapName);
	p->setEntrance(anotherPanel);
}

void Load::loadEntrance(panel* p, Campaign* campaign, std::string mapName) {
	std::string fileName = DIR + "Panel\\Entrance\\" + mapName + ".txt";
	std::ifstream readFile;
	readFile.open(fileName);
	std::string newLineDelim = "\n";
	std::string spaceDelim = " ";
	std::string line;

	int index = 0;
	int x, y;
	std::string targetName;



	while (getline(readFile, line)) {
		if (index == 0) {
			targetName = line.substr(line.find(":") + 2, line.find(newLineDelim));
		}
		else if (index == 1) {
			x = stoi(line.substr(line.find(":") + 2, line.find(newLineDelim)));
		}
		else if (index == 2) {
			y = stoi(line.substr(line.find(":") + 2, line.find(newLineDelim)));
		}
		index++;
	}

	panel* anotherPanel = new panel();
	for (int i = 0; i < campaign->getCampaignSize(); i++) {
		if (campaign->returnMap(i)->getName() == targetName) {
			anotherPanel = campaign->returnMap(i)->getPanel(x, y);

		}
	}
	p->setMapName(mapName);
	p->setExit(anotherPanel);
}