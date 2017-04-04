#ifndef NIMBLE_H
#define NIMBLE_H
#include "subclass.h"

/**
 * @brief The Nimble class: concrete class of subclass
 */
class Nimble: public SubClass{
public:
    Nimble();
	void setSpecialAbility(std::string ability);
	void setSubClass(std::string subClass);
};

#endif // NIMBLE_H
