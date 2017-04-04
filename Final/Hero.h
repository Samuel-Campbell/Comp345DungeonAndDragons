#pragma once
#include "string"
#include "characterbuilder.h"
#include "subject.h"
#include <vector>
#include "subject.h"
#include "item.h"
#include "itemvector.h"

class Hero : public Subject
{
public:
	Hero();
	Hero(std::string characterClass, std::string subClass);
	
	void displayStats();
	void levelUp();	


	vector<Item> getVector();
	void displayAvailableItems();
	void displayItems(string type);
	void useItem(int itemNum);
	ItemVector f;
	vector<Item> charItems;

private:
	CharacterBuilder* hero;
};

