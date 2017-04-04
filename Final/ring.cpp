#include "ring.h" 

Ring::Ring() {
	srand(time(NULL));
	armor_class = rand() % 3;
	strength_amount = rand() % 3;
	constitution_amount = rand() % 3;
	wisdom_amount = rand() % 3;
	charisma_amount = rand() % 3;
	itemName = randomName();

}
Ring::Ring(Character *decoratedCharacter) {
	armor_class = rand() % 3;
	strength_amount = rand() % 3;
	constitution_amount = rand() % 3;
	wisdom_amount = rand() % 3;
	charisma_amount = rand() % 3;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
Ring::Ring(Character *decoratedCharacter, int a, int s, int ca, int w, int cb, int lvl) {
	armor_class = a;
	strength_amount = s;
	charisma_amount = ca;
	wisdom_amount = w;
	constitution_amount = cb;
	level = lvl;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}

void Ring::levelStat(int level) {
	armor_class = (level*0.3)*armor_class;
	strength_amount = (level*0.3)*strength_amount;
	constitution_amount = (level*0.3)*constitution_amount;
	wisdom_amount = (level*0.3)*wisdom_amount;
	charisma_amount = (level*0.3)*charisma_amount; 
	 
}

std::string Ring::getItem() {
	return "ring";
}

//return the charisma amount for this item
double Ring::getCharisma() {
	return charisma_amount;
}
double Ring::getDexterity()
{
	return NULL;
}
double Ring::getDamage()
{
	return NULL;
}
double Ring::getAttack()
{
	return NULL;
}
double Ring::getLevel()
{
	return level;
}
double Ring::getArmorClass() {
	return armor_class;
}
//return the constitution amount for this item
double Ring::getConstitution() {
	return constitution_amount;
}
//return the strength amount for this item
double Ring::getStrength() {
	return strength_amount;
}
//return wisdom amount for this item
double Ring::getWisdom() {
	return wisdom_amount;
}
double Ring::getIntelligence() {
	return NULL;
}

std::string Ring::getType() {
	return itemName;
}

std::string Ring::randomName() {
	names = std::vector<std::string>();
	double r = 0;
	r = rand() % 3;
	names.push_back("energy immunity");
	names.push_back("chaotic fury");
	names.push_back("epic wizardry");


	itemName = names.at(r);
	return itemName;
}