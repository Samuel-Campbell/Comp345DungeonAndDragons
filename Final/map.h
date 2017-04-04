//! @file
//! @brief Implementation file for the Item class
//!
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "mapobserver.h"
#include "panel.h"

class Item;
class MapObserver;
class panel;
//! Class implementing a game map
class Map
{

public:
    Map();
    Map (std::string name);
    bool validatePath(int x, int y);
    void fillCell(int x, int y, char obj); 
    bool isOccupied(int x, int y);
    void resize(int width, int height);
    void printMap();
    void setRelations();
    bool findPath();
    void attach(MapObserver * obs);
    void detach(MapObserver * obs);
    void notify(std::string s);
    std::vector<MapObserver *> getViews();
    void setCampaignName(std::string cName);
    char getCell(int x, int y);
    std::string getName();
    void setName(std::string name);
	panel* getPanel(int x, int y);
    int getSizeWidth();
    int getSizeLength();
	bool verifyMapLinks();

	void setSpawnPanel(panel* p);
	panel* getSpawnPanel();

	void setSpawn(bool val);
	bool haveSpawn();

	void setVisited(bool var);
	bool getVisited();

private:
    std::string campaignName;
    std::string name;

	bool mapVisited = false;

	bool spawn = false;

    //! constant for map length
    int const MAP_LENGTH = 2;
    //! constant for map width
    int const MAP_WIDTH = 2;

    //map will be a variable length 2-dimensional vector of chars
    std::vector<std::vector<panel *>> map; //I assume that user will use any chars he pleases to plot a map (look at Dwarf Fortress, the game, for an example of this).
    std::vector<std::vector<bool>> visited;

    std::vector < MapObserver * > views; //the map observing array

 
	panel* spawnPanel;
};
