#ifndef TANK_H
#define TANK_H
#include "subclass.h"


class Tank: public SubClass{
public:
    Tank();
    void setSpecialAbility(std::string ability);
    void setSubClass(std::string subClass);
};

#endif // TANK_H
