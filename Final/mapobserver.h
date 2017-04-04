#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "map.h"

//! Class implementing a game map

class Map;
class MapObserver {

public:
    MapObserver(Map *subject);
    void update(std::string s);
    int getOutputCount();
    Map* getMap();

private:
    Map *map;
    int outputCount;
};
