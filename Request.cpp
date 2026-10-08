#include "Request.h"
#include "Drone.h"

Request::Request() {
    // TODO
    requestId = 0;
    arrivalTime = 0;
    severityLevel = 0;
    distanceToZone = 0;
    serviceTime = 0;
    packageType = 0;
    dispatchTime = -1;
}

Request::Request(int requestId, int arrivalTime, int severityLevel,
                 int distanceToZone, int serviceTime, int packageType) {
    // TODO
    this->requestId = requestId;
    this->arrivalTime = arrivalTime;
    this->severityLevel = severityLevel;
    this->distanceToZone = distanceToZone;
    this->serviceTime = serviceTime;
    this->packageType = packageType;
    dispatchTime = 0;
}

int Request::getRequestId() const {
    // TODO
    return this->requestId;
}

int Request::getArrivalTime() const {
    // TODO
    return this->arrivalTime;
}

int Request::getSeverityLevel() const {
    // TODO
    return this->severityLevel;
}

int Request::getDistanceToZone() const {
    // TODO
    return this->distanceToZone;
}

int Request::getServiceTime() const {
    // TODO
    return this->serviceTime;
}

int Request::getPackageType() const {
    // TODO
    return this->packageType;
}

int Request::getDispatchTime() const {
    // TODO
    return this->dispatchTime;
}

void Request::setDispatchTime(int dispatchTime) {
    // TODO
    this->dispatchTime = dispatchTime;
}

int Request::getWaitingTime() const {
    // TODO
    return dispatchTime - arrivalTime;
}

bool Request::isEligibleFor(const Drone& drone) const {
    // TODO
    if(packageType == 2 && distanceToZone > 10){
        if(drone.getBatteryClass() == 2){return true;}
        return false;
    }
    else{return true;}
}

std::ostream& operator<<(std::ostream& os, const Request& req) {
    // TODO
    os<<"Request "<<req.requestId<<" arrived at minute "<<req.arrivalTime<<" (severity : "<<req.severityLevel<<", distance : "<<req.distanceToZone<<", service : "<<req.serviceTime<<", package : "<<req.packageType<<" )";
    return os;
}
