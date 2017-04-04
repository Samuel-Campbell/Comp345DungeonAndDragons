//! @file
//! @brief Implementation file for the Map class
//!
#include "map.h"

//For testing purposes, I assume:
//'T' is an empty tile
//'B' is beginning
//'E' is exit
//Anything else is considered undefined and thus not navigable.

Map::Map(){
    views.clear();
    resize(2, 2); //this was default size originally
}

Map::Map(std::string mName){
    // Create an empty map
    views.clear();
    resize(2, 2);
    name = mName;
}

void Map::resize(int width, int height){
    if (width >= 0 && height >= 0){
        map.resize(width);
        visited.resize(width);
        for (int i=0; i < map.size(); i++){
            map[i].resize(height);
            visited[i].resize(height, false);
        }

        for (int i = 0; i < map.size(); i++){
            for (int j = 0; j < map[i].size(); j++){
                map[i][j] = new panel();
				map[i][j]->setCoordinates(i, j);
            }
        }

        std::string a = "resize: w = " + std::to_string(width);
        std::string b = " h = " + std::to_string(height);
        std::string c = a + b;
        notify(c); //must notify observers of change;
    }
    else{
        std::cout << "INVALID DIMENSIONS" << std::endl;
    }
}

void Map::printMap(){
	std::cout << "\n" << Map::getName() << std::endl;
	/*
    for (int row = 0; row < map.size(); row++){
        for (int col = 0; col < map.size[row](); col++){
            std::cout << map[row][col]->getPanelType() << " ";
        }
        std::cout << std::endl;
    }
	*/

	// print x coordinates
	std::cout << " ";
	for (int i = 0; i < map.size(); i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < map[0].size(); i++) {
		std::cout << i;
		for (int j = 0; j < map.size(); j++) {
			std::cout << map[j][i]->getPanelType() << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @brief Map::validatePath
 * @param x
 * @param y
 * @param initx
 * @param inity
 * @return
 */
bool Map::validatePath(int x, int y){
    bool validPath = false;

    // Mark node as visited
    visited[x][y] = true;

    // Depth first search

    // Success condition when an entrance is found
    if ((map[x][y]->getPanelType() == 'e') || (map[x][y]->getPanelType() == 's'))
        return true;

    if (map[x][y]->getDown() != NULL){
        if ((map[x][y]->getDown()->walkable()) && visited[x][y-1] == false){
        validPath = Map::validatePath(x, y - 1);
        }

        if (validPath)
            goto skip;
    }

    if (map[x][y]->getLeft() != NULL){
        if ((map[x][y]->getLeft()->walkable()) && visited[x-1][y] == false){
            validPath = Map::validatePath(x-1, y);
        }
        if (validPath)
            goto skip;
    }

    if (map[x][y]->getUp() != NULL){
        if ((map[x][y]->getUp()->walkable()) && visited[x][y+1] == false){
            validPath = Map::validatePath(x, y + 1);
        }
        if (validPath)
            goto skip;
    }

    if (map[x][y]->getRight() != NULL){
        if ((map[x][y]->getRight()->walkable()) && visited[x+1][y] == false){
            validPath = Map::validatePath(x + 1, y);
        }
        if (validPath)
            goto skip;
    }

    skip:
    return validPath;
}

// create map linked list...
void Map::setRelations(){
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[i].size(); j++){

            if (i == 0){
                map[i][j]->setRight(map[i+1][j]);
            }else if ((i + 1) == map.size()){
                map[i][j]->setLeft(map[i-1][j]);
            }else{
                map[i][j]->setRight(map[i+1][j]);
                map[i][j]->setLeft(map[i-1][j]);
            }

            if (j == 0){
                map[i][j]->setUp(map[i][j+1]);
            }else if ((j + 1) == map[i].size()){
                map[i][j]->setDown(map[i][j-1]);
            }else{
                map[i][j]->setUp(map[i][j+1]);
                map[i][j]->setDown(map[i][j-1]);
            }

        }
    }
}

/**
 * @brief Map::findPath
 * @return
 */
bool Map::findPath(){
    bool validPath = false;
    bool atLeastOneExit = false;
    Map::setRelations();

    for (int i = 0; i < map.size(); i ++){
        for (int j = 0; j < map[i].size(); j++){
            visited[i][j] = false;
        }
    }

	bool spawn = false;
	bool entrance = false;
	// check if an entrance and spawn exist on same map
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j]->getPanelType() == 's') {
				spawn = true;
				setSpawnPanel(map[i][j]);
			}
			else if (map[i][j]->getPanelType() == 'e') {
				entrance = true;
			}
		}
	}

	// checks for max 1 exit and max 1 entrance and max 1 spawn
	int spawnCnt = 0;
	int entranceCnt = 0;
	int exitCnt = 0;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j]->getPanelType() == 'e') {
				entranceCnt++;
			}
			else if (map[i][j]->getPanelType() == 'x') {
				exitCnt++;
			}
			else if (map[i][j]->getPanelType() == 's') {
				spawnCnt++;
			}
		}
	}

	if ((spawnCnt > 1) || (exitCnt > 1) || (entranceCnt > 1)) {
		return false;
	}

	// Can't have both an entrance and a spawn on the same map
	if (entrance && spawn) {
		return false;
	}

    // If there is a connecting room then there is an entrance
    for (int i = 0; i < map.size(); i ++){
        for (int j = 0; j < map[i].size(); j++){
            if (map[i][j]->getPanelType() == 'x'){
                atLeastOneExit = true;
                validPath = Map::validatePath(i, j);
            }
        }
    }

	// No exit with an entrance is valid
    if (atLeastOneExit == false){
        for (int i = 0; i < map.size(); i ++){
            for (int j = 0; j < map[i].size(); j++){
                if ((map[i][j]->getPanelType() == 'e') || (map[i][j]->getPanelType() == 's')){
                    validPath = true;
                }
            }
        }
    }

    return validPath;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @param obj: a character value of object that fills the cell
void Map::fillCell(int x, int y, char obj)
{
    map[x][y]->setPanelType(obj);
	// Enters name of map.. Acts as primary key
	map[x][y]->setMapName(name);

	if (obj == 's') {
		Map::setSpawn(true);
	}

    std::string a = "Cell Filled: x = " + std::to_string(x);
    std::string b = " y = " + std::to_string(y);
    std::string c = " char = ";
    c.push_back(obj);
    std::string d = a + b + c;
    notify(d); //must notify observers of change
}
 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//! Implementation occupation of a cell, check if a cell is occupied
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return : a boolean true if the cell is occupeid false otherwise
bool Map::isOccupied(int x, int y)
{
    if (map[x][y]->getPanelType() != ' '){
        return true;
    }
    return false;
}

void Map::notify(std::string s) {
    // 5. Publisher broadcasts
    for (int i = 0; i < views.size(); i++)
        views[i]->update(s);
}


void Map::attach(MapObserver * obs) {
    views.push_back(obs);
}


void Map::detach(MapObserver * obs) { //want to get rid of a specific observer
    for (int x = 0; x < views.size(); x++) {

        if (views[x] == obs){
            views.erase(views.begin()+x);
        }
    }
}

std::vector < MapObserver * > Map::getViews(){
    return views;
}

void Map::setCampaignName(std::string cName){
    campaignName = cName;
}



//Returns what is occupying a cell
char Map::getCell(int x, int y){
    return map[x][y]->getPanelType();
}

std::string Map:: getName(){
    return name;
}

void Map::setName(std::string mName){
    name = mName;
}

int Map::getSizeWidth(){
    return map.size();
}

int Map::getSizeLength(){
    return map[0].size();
}

panel* Map::getPanel(int x, int y) {
	return map[x][y];
}

// Verifies that every exit and entrance are linked to at least 1 map
bool Map::verifyMapLinks() {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j]->gateWay() == false) {
				return false;
			}
		}
	}
	return true;
}

void Map::setSpawn(bool val) {
	spawn = val;
}

bool Map::haveSpawn() {
	return spawn;
}

void Map::setSpawnPanel(panel* p) {
	spawnPanel = p;
}

panel* Map::getSpawnPanel() {
	return spawnPanel;
}

bool Map::getVisited() {
	return mapVisited;
}

void Map::setVisited(bool var) {
	mapVisited = var;
}