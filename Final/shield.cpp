#include "shield.h" 

Shield::Shield() {
	armor_class = rand() % 7;
	itemName = randomName();

}
Shield::Shield(Character *decoratedCharacter) {
	armor_class = rand() % 7;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
Shield::Shield(Character *decoratedCharacter, int a, int l) {
	this->armor_class = a;
	this->level = l;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
double Shield::getIntelligence()
{
	return NULL;
}
double Shield::getWisdom()
{
	return NULL;
}
double Shield::getArmorClass()
{
	return armor_class;
}
double Shield::getStrength()
{
	return NULL;
}
double Shield::getConstitution()
{
	return NULL;
}
double Shield::getCharisma()
{
	return NULL;
}
double Shield::getDexterity()
{
	return NULL;
}
double Shield::getDamage()
{
	return NULL;
}
double Shield::getAttack()
{
	return NULL;
}
double Shield::getLevel()
{
	return level;
}
std::string Shield::getItem() {
	return "shield";
}
std::string Shield::randomName()
{
	names = std::vector<std::string>();
	double r = 0;
	r = rand() % 3;
	names.push_back("Energy");
	names.push_back("Heavy");
	names.push_back("Tower");


	itemName = names.at(r);
	return itemName;
}

void Shield::levelStat(int level) {
	armor_class = (level*0.3)*armor_class;

}

std::string Shield::getType()
{
	return itemName;
}
