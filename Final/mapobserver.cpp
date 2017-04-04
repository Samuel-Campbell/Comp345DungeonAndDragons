#include "mapobserver.h"


MapObserver::MapObserver(Map * subject) {
        map = subject;
        outputCount = 0;
        map->attach(this);
    }

int MapObserver::getOutputCount() {
    return outputCount;
}

Map * MapObserver::getMap(){
    return map;
}

void MapObserver::update(std::string s) {
    std::cout << std::endl << "UPDATE: " << s << std::endl;
    map->printMap();
    outputCount++;
}
