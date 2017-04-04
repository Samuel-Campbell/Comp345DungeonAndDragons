#include "map.h"
#include <string>
#include <iostream>
#include <fstream>
#include "mapobserver.h"

#ifndef CAMPAIGN_H
#define CAMPAIGN_H


class Map;
class Campaign
{
public:
    Campaign();

	// Sets campaign name
    void setName (std::string cName);

	// Returns name of campaign
	std::string getName();

	// Returns the name of a map
    std::string getMapName(int index);

	// Checks if a map exists at an index
    bool mapExist(int index);

	// Maybe not useful
    char getMapCell(int map, int x, int y);

	// Returns map at index
    Map* returnMap(int index);

	int getCampaignSize();

	void addMap(Map* map);

	bool linkMaps(panel* p1, panel* p2);

	void displayMaps();

	bool spawnLocation();

	panel* getSpawnPanel();

	void setDefaultCurrentMap();

	/////////////////////////
	// Current Map
	void setCurrentMap(Map* map);
	Map* travelFrom(panel* p);
	Map* getCurrentMap();

private:
    static const int CAMPAIGN_SIZE = 10;
    Map* campaign[CAMPAIGN_SIZE];
    std::string name;

	bool spawnSet = false;

	//Current map we are viewing
	Map* currentMap;
};

#endif // CAMPAIGN_H
