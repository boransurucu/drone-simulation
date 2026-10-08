#include "Drone.h"

Drone::Drone() {
    // TODO
    droneId = 0;
    nextAvailableTime = 0;
    batteryClass = 0;
}

Drone::Drone(int droneId) {
    // TODO
    this->droneId = droneId;
    if(droneId % 2 == 0){
        batteryClass = 2;
    }
    else{batteryClass = 1;}
    this->nextAvailableTime = 0;
}

int Drone::getDroneId() const {
    // TODO
    return droneId;
}

int Drone::getNextAvailableTime() const {
    // TODO
    return nextAvailableTime;
}

int Drone::getBatteryClass() const {
    // TODO
    return batteryClass;
}

void Drone::setNextAvailableTime(int time) {
    // TODO
    this->nextAvailableTime = time;
}

bool Drone::isAvailableAt(int currentTime) const {
    // TODO
    if(nextAvailableTime <= currentTime){
        return true;
    }
    else{return false;}
}

std::ostream& operator<<(std::ostream& os, const Drone& drone) {
    // TODO
    os<<"Drone "<<drone.droneId<<" ( available at : "<<drone.nextAvailableTime<<", battery : "<<drone.batteryClass<<" )";
    return os;
}
