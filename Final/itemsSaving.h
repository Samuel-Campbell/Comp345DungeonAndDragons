#pragma once
#include <iostream>
#include <fstream>
#include <string> 
#include "helmet.h" 
#include "boots.h"
#include "belt.h"
#include "ring.h"
#include "shield.h"
#include "weapon.h"
#include <vector> 
#include "character.h" 


class ItemsSaving
{
public:
	ItemsSaving();
	void displayGameItems();
	void deleteItem(int position);
	void push_Game(Item * a);
	void loadGameItems(int level); 
	void loadInventoryItems(Character * c, std::string path); 
	void saveInventoryPlayer(Character * c);
	std::vector<Item*> gameVector;
};

