#include "panel.h"

//Panel constructor
panel::panel()
{
    left = NULL;
    right = NULL;
    up = NULL;
    down = NULL;
    entrance = NULL;
	exit = NULL;
    type = ' ';
	entity = "";
}

// Returns true if a panel is walkable
// Only wall prevent from walking
bool panel::walkable(){
	if (type == 'w') {
		return false;
	}
	return true;
}

// Setters
void panel::setPanelType(char _type){
    type = _type;
	if (type == 'c') {
		setEntity("Chest");
	}
	else if (type == 'e') {
		setEntity("Entrance");
	}
	else if (type == 'p') {
		setEntity("Player");
	}
	else if (type == 'm') {
		setEntity("Monster");
	}
	else if (type == 'x') {
		setEntity("Exit");
	}
	else if (type == 'w') {
		setEntity("Wall");
	}
	else if (type == 's') {
		setEntity("Spawn");
	}
	else if (type == ' ') {
		setEntity("Empty");
	}
}

void panel::setLeft(panel* p){
    left = p;
}

void panel::setRight(panel* p){
    right = p;
}

void panel::setUp(panel* p){
    up = p;
}

void panel::setDown(panel* p){
    down = p;
}

void panel::setEntrance(panel* p){
    entrance = p;
}

void panel::setExit(panel* p) {
	exit = p;
}

//Getters
char panel::getPanelType(){
    return type;
}


panel* panel::getLeft(){
    return left;
}

panel* panel::getRight(){
    return right;
}

panel* panel::getUp(){
    return up;
}

panel* panel::getDown(){
    return down;
}

void panel::setMapName(std::string _map) {
	mapName = _map;
}

std::string panel::getMapName() {
	return mapName;
}

void panel::setCoordinates(int x, int y){
    coordinateX = x;
    coordinateY = y;
}

int panel::getCoordinateX(){
    return coordinateX;
}

int panel::getCoordinateY(){
    return coordinateY;
}

std::string panel::getEntity() {
	return entity;
}

void panel::setEntity(std::string state) {
	entity = state;
}

panel* panel::getEntrance() {
	return entrance;
}
panel* panel::getExit() {
	return exit;
}

Character* panel::getPlayer() {
	return player;
}

Elemental* panel::getEnemy() {
	return enemy;
}

Item* panel::getChest() {
	return chest;
}

// If an entrance has no exit or an exit has no entrance then it is false
bool panel::gateWay() {
	if ((type == 'e') && (exit == NULL)) {
		return false;
	}
	else if ((type == 'x') && (entrance == NULL)) {
		return false;
	}
	return true;
}

void panel::setPlayer(Character* character) {
	player = character;
}

void panel::setEnemy(Elemental* elemental) {
	enemy = elemental;
}
void panel::setChest(Item* item){
	chest = item;
}
////////////////////////////////////////////////////////////////////////////////NEW
//function uses on move... function
bool panel::Combat() {
	if (getRight() != NULL) {
		if ((getRight()->getPanelType() == 'm')) {
			getPlayer()->Fight(getRight()->getEnemy());
			getRight()->setPanelType(' ');
			return true;
		}
	}

	if (getLeft() != NULL) {
		if ((getLeft()->getPanelType() == 'm')) {
			getPlayer()->Fight(getLeft()->getEnemy());
			getLeft()->setPanelType(' ');
			return true;
		}
	}

	if (getUp() != NULL) {
		if ((getUp()->getPanelType() == 'm')) {
			getPlayer()->Fight(getUp()->getEnemy());
			getUp()->setPanelType(' ');
			return true;
		}
	}

	if (getDown() != NULL) {
		if ((getDown()->getPanelType() == 'm')) {
			getPlayer()->Fight(getDown()->getEnemy());	
			getDown()->setPanelType(' ');
			return true;
		}
	}
	return false;
}

panel* panel::moveRight() {
	bool movePossible = false;

	if (getRight() != NULL) {
		if (getRight()->walkable()) {
			movePossible = true;
		}
	}
	//We check if there is any monsters


	if (movePossible) { //we collect the item
		if (getRight()->getPanelType() == 'c') { //collect the item to the backpack
			player->pushItem(getChest());		 
		}
			if ((getPanelType() != 's') && (getPanelType() != 'e') && (getPanelType() != 'x')) {
				setPanelType(' ');
			}
			if ((getRight()->getPanelType() != 's') && (getRight()->getPanelType() != 'e') && (getRight()->getPanelType() != 'x')) {
				getRight()->setPanelType('p');
			}

			getRight()->setPlayer(getPlayer());
			setPlayer(NULL);
			return getRight();	
		}
	return this;
}

panel* panel::moveLeft() {
	bool movePossible = false;

	if (getLeft() != NULL) {
		if (getLeft()->walkable()) {
			movePossible = true;
		}
	}
	//We check if there is any monsters
	

	if (movePossible) { //we collect the item
		if (getLeft()->getPanelType() == 'c') { //collect the item to the backpack
			player->pushItem(getChest());												//backpack->ItemVector::pushItem(*(p->getChest()));
		}

		if ((getPanelType() != 's') && (getPanelType() != 'e') && (getPanelType() != 'x')) {
			setPanelType(' ');
		}
		if ((getLeft()->getPanelType() != 's') && (getLeft()->getPanelType() != 'e') && (getLeft()->getPanelType() != 'x')) {
			getLeft()->setPanelType('p');
		}
			
		getLeft()->setPlayer(getPlayer());
		setPlayer(NULL);
		return getLeft();
	}	
	return this;
}

panel* panel::moveUp() {
	bool movePossible = false;

	if (getUp() != NULL) {
		if (getUp()->walkable()) {
			movePossible = true;
		}
	}
	//We check if there is any monsters


	if (movePossible) { //we collect the item		
			if (getUp()->getPanelType() == 'c') { 
				player->pushItem(getChest());		 
			}
			if ((getPanelType() != 's') && (getPanelType() != 'e') && (getPanelType() != 'x')) {
				setPanelType(' ');
			}
			if ((getUp()->getPanelType() != 's') && (getUp()->getPanelType() != 'e') && (getUp()->getPanelType() != 'x')) {
				getUp()->setPanelType('p');
			}
			getUp()->setPlayer(getPlayer());
			setPlayer(NULL);
			return getUp();
		}	
	return this;
}

panel* panel::moveDown() {
	bool movePossible = false;

	if (getDown() != NULL) {
		if (getDown()->walkable()) {
			movePossible = true;
		}
	}
	//We check if there is any monsters


	if (movePossible) { //we collect the item		
		if (getDown()->getPanelType() == 'c') { //collect the item to the backpack
			player->pushItem(getChest());						 
		}

		if ((getPanelType() != 's') && (getPanelType() != 'e') && (getPanelType() != 'x')) {
			setPanelType(' ');
		}
		if ((getDown()->getPanelType() != 's') && (getDown()->getPanelType() != 'e') && (getDown()->getPanelType() != 'x')) {
			getDown()->setPanelType('p');
		}

		getDown()->setPlayer(getPlayer());
		setPlayer(NULL);
		return getDown();
	}	
	return this;
}