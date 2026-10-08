#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

class Drone;

class Request {
private:
    int requestId;
    int arrivalTime;
    int severityLevel;
    int distanceToZone;
    int serviceTime;
    int packageType;
    int dispatchTime;

public:
    Request();
    Request(int requestId, int arrivalTime, int severityLevel,
            int distanceToZone, int serviceTime, int packageType);

    int getRequestId() const;
    int getArrivalTime() const;
    int getSeverityLevel() const;
    int getDistanceToZone() const;
    int getServiceTime() const;
    int getPackageType() const;
    int getDispatchTime() const;

    void setDispatchTime(int dispatchTime);
    int getWaitingTime() const;

    bool isEligibleFor(const Drone& drone) const;

    friend std::ostream& operator<<(std::ostream& os, const Request& req);
};

#endif
