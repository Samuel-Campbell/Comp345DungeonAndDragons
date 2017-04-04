#ifndef BULLY_H
#define BULLY_H
#include "subclass.h"

/**
 * @brief The Bully class: Concrete class of subclass
 */
class Bully: public SubClass{
public:
    Bully();
	void setSpecialAbility(std::string ability);
	void setSubClass(std::string subClass);
};

#endif // BULLY_H
