#include "campaign.h"
//Default constructor
Campaign::Campaign(){
    for (int i = 0; i < CAMPAIGN_SIZE; i++){
        campaign[i] = NULL;
    }
}

//Sets camapaign name
void Campaign::setName (std::string cName){
    name = cName;
}

//Checks if a map exist
bool Campaign::mapExist(int index){
    if (campaign[index] == NULL){
        return false;
    }else{
        return true;
    }
}

// Add a map to the campaign
void Campaign::addMap(Map* map){
	for (int i = 0; i < CAMPAIGN_SIZE; i++) {
		if (campaign[i] == NULL) {
			campaign[i] = map;
			break;
		}
	}
}


// Gets the info of a cell in a map
char Campaign::getMapCell(int map, int x, int y){
    return campaign[map] -> getCell(x, y);
}

// Gets name of a map
std::string Campaign:: getMapName(int index){
    return campaign[index]->getName();
}


// returns camapaign name
std::string Campaign::getName(){
    return name;
}

Map* Campaign::returnMap(int index){
    return campaign[index];
}

int Campaign::getCampaignSize(){
	int size = 0;
	for (int i = 0; i < CAMPAIGN_SIZE; i++) {
		if (campaign[i] != NULL) {
			size++;
		}
		else {
			break;
		}
	}
	return size;
}

// Links 2 maps together by their panels
bool Campaign::linkMaps(panel* p1, panel* p2) {
	if((p1->getPanelType() == 'e') && (p2->getPanelType() == 'x')){
		p1->setExit(p2);
		p2->setEntrance(p1);
		return true;
	}
	else if ((p1->getPanelType() == 'x') && (p2->getPanelType() == 'e')) {
		p1->setEntrance(p2);
		p2->setExit(p1);
		return true;
	}
	return false;
}

// Display a list of maps to the user
void Campaign::displayMaps() {
	for (int i = 0; i < Campaign::getCampaignSize(); i++) {
		std::cout << Campaign::getMapName(i) << std::endl;
	}
}

// checks if a spawn area exists in the campaign
bool Campaign::spawnLocation() {
	for (int i = 0; i < Campaign::getCampaignSize(); i++) {
		if (campaign[i]->haveSpawn()) {
			return true;
		}
	}
	return false;
}


void Campaign::setDefaultCurrentMap() {
	for (int i = 0; i < getCampaignSize(); i++) {
		if (campaign[i]->haveSpawn()) {
			setCurrentMap(campaign[i]);
		}
	}
}

Map* Campaign::getCurrentMap() {
	return currentMap;
}
// Sets the current map we view
void Campaign::setCurrentMap(Map* map) {
	MapObserver* mapOvserver = new MapObserver(map);
	currentMap = map;
}

// Loads the map a panel connects to
Map* Campaign::travelFrom(panel* p) {
	std::string mapName;
	panel* p1;

	if (p->getPanelType() == 'x') {
		p1 = p->getEntrance();
		mapName = p1->getMapName();
	}
	else if (p->getPanelType() == 'e') {
		p1 = p->getExit();
		mapName = p1->getMapName();
	}
	
	Map* map = new Map();

	for (int i = 0; i < getCampaignSize(); i++) {
		if (campaign[i]->getName() == mapName) {
			map = returnMap(i);
		}
	}
	return map;
}

panel* Campaign::getSpawnPanel() {
	for (int i = 0; i < getCampaignSize(); i++) {
		if (campaign[i]->haveSpawn()) {
			return campaign[i]->getSpawnPanel();
		}
	}
}