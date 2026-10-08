#ifndef DRONE_H
#define DRONE_H

#include <iostream>

class Drone {
private:
    int droneId;
    int nextAvailableTime;
    int batteryClass;

public:
    Drone();
    Drone(int droneId);

    int getDroneId() const;
    int getNextAvailableTime() const;
    int getBatteryClass() const;

    void setNextAvailableTime(int time);
    bool isAvailableAt(int currentTime) const;

    friend std::ostream& operator<<(std::ostream& os, const Drone& drone);
};

#endif
