#include <string>
#ifndef PANEL_H
#define PANEL_H
#include "map.h"
#include "character.h"
#include "Elemental.h"
class Map;

class panel
{
public:

    panel();
    void setPanelType(char type);
    void setLeft(panel* p);
    void setRight(panel* p);
    void setUp(panel* p);
    void setDown(panel* p);
    void setEntrance(panel* p);
	void setExit(panel* p);
	void setPlayer(Character* character);
	void setEnemy(Elemental* enemy);
	void setChest(Item* item);
    void setCoordinates(int a, int b);
	void setMapName(std::string map);
	std::string getMapName();

	bool gateWay();

    panel* getLeft();
    panel* getRight();
    panel* getUp();
    panel* getDown();

	bool Combat();

	panel* moveRight();
	panel* moveLeft();
	panel* moveUp();
	panel* moveDown();


    bool walkable();
    char getPanelType();

    int getCoordinateX();
    int getCoordinateY();

	//////////////////////////////
	// Get pointers
	panel* getEntrance();
	panel* getExit();
	Character* getPlayer();
	Elemental* getEnemy();
	Item* getChest(); 	/////////////////////////////////////////////////////////////NEW
	//Monster* monster
	//Friendly* friendly

	std::string getEntity();
	void setEntity(std::string);

	
private:
	//////////////////////////////////
	// Pointers of surrounding panels
    panel* left;
    panel* right;
    panel* up;
    panel* down;
	
	
	//////////////////////////////////
	// Object occupying a panel
	panel* entrance;
	panel* exit;
	Character* player;
	Elemental* enemy;
	Item* chest;

	//////////////////
	// Coordinates
    int coordinateX;
    int coordinateY;
    
	std::string mapName;
	/////////////////
	// Type
    char type;
	std::string entity;
};

#endif // PANEL_H
