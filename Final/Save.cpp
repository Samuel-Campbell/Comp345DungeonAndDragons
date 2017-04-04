#include "stdafx.h"
#include "Save.h"


Save::Save()
{
}

// Saved an existing campaign
void Save::saveCampaign(Campaign* campaign) {
	int campaignSize = campaign->getCampaignSize();

	for (int i = 0; i < campaignSize; i++) {		
		// format: C:\Users\user\Desktop\SavedInstances\Campaign\<campaignName>.txt"
		std::string fileName = DIR + "Campaign\\" + campaign->getName() + ".txt";
		// Output stream
		std::ofstream outfile;
		if (i == 0){
			outfile.open(fileName, std::ios_base::trunc);
		}
		else {
			outfile.open(fileName, std::ios_base::app);
		}
		
		outfile << campaign->getMapName(i);
		outfile << "\n";
		outfile.close();
		Save::saveMap(campaign->returnMap(i));	
	}
}

// Save a map
void Save::saveMap(Map* map) {
	int width, length;
	width = map->getSizeWidth();
	length = map->getSizeLength();

	std::ofstream outfile;
	std::string fileName = DIR + "Map\\" + map->getName() + ".txt";
	outfile.open(fileName, std::ios_base::trunc);
	outfile << "Width: " << width << "\n";
	outfile << "Length: " << length << "\n";
	outfile.close();

	char cell;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++){					
			// Output stream
			outfile.open(fileName, std::ios_base::app);						
			cell = map->getCell(i, j);			
			outfile << cellOutput(cell, map->getPanel(i, j));
			outfile << "\n";
			outfile.close();
			Save::savePanel(map->getPanel(i, j));
			//Will save panel if it is important
		}
	}
}


// Only save special panels
void Save::savePanel(panel* _panel) {
	char entity = _panel->getPanelType();

	// Save The right Object
	if (entity == 'p') {
		Save::savePlayer(_panel->getPlayer());
	}
	else if (entity == 'e') {
		Save::saveEntrance(_panel);
	} 
	else if (entity == 'x') {
		Save::saveExit(_panel);
	}
}

// Save Entrance panel
void Save::saveEntrance(panel* p) {
	std::ofstream outfile;
	std::string fileName = DIR + "Panel\\Entrance\\" + p->getMapName() + ".txt";
	outfile.open(fileName, std::ios_base::trunc);
	//save entrance pointer
	outfile << "Exit: " << p->getExit()->getMapName() << "\n";
	outfile << "X: " << p->getExit()->getCoordinateX() << "\n";
	outfile << "Y: " << p->getExit()->getCoordinateY() << "\n";
	outfile.close();
}

// Save Exit panel
void Save::saveExit(panel* p) {
	std::ofstream outfile;
	std::string fileName = DIR + "Panel\\Exit\\" + p->getMapName() + ".txt";
	outfile.open(fileName, std::ios_base::trunc);
	//save entrance pointer
	outfile << "Entrance: " << p->getEntrance()->getMapName() << "\n";
	outfile << "X: " << p->getEntrance()->getCoordinateX() << "\n";
	outfile << "Y: " << p->getEntrance()->getCoordinateY() << "\n";
	outfile.close();
}

// Save Player
void Save::savePlayer(Character* player) {
	
	std::ofstream outfile;
	std::string fileName = DIR + "Player\\" + player->getCharacterName() + ".txt";
	outfile.open(fileName, std::ios_base::trunc);
	// save character...
	outfile << "Name: " << player->getCharacterName() << "\n";
	outfile << "Level: " << player->getLevel() << "\n";
	outfile << "HP: " << player->getHitPoints() << "\n";
	outfile << "SubClass: " << player->getSubClass() << "\n";
	outfile << "Ability Scores: ";
	for (int i = 0; i < 6; i++) {
		outfile << player->getAbilityScore(i) << ", ";
	}
	outfile.close();
}

// Outputs readable stuff
std::string Save::cellOutput(char cell, panel* p) {
	std::string output = "";

	if (cell == ' ') {
		output = "Empty";
	}
	else if (cell == 'e') {
		output = "e -> " + p->getExit()->getMapName();
	}
	else if (cell == 'x') {
		output = "x -> " + p->getEntrance()->getMapName();
	}
	else if (cell == 's') {
		output = "s";
	}
	else if (cell == 'm') {
		output = "m";
	}
	else if (cell == 'c') {
		output = "c";
	}
	else if (cell == 'p') {
		output = "p -> " + p->getPlayer()->getCharacterName();
	}
	else if (cell == 'w') {
		output = "w";
	}
	

	return output;
}