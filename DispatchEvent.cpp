#include "DispatchEvent.h"

DispatchEvent::DispatchEvent() {
    // TODO
    droneId = 0;
    requestId = -1;
    dispatchTime = -1;
    waitingTime = -1;
}

DispatchEvent::DispatchEvent(int droneId, int requestId,
                             int dispatchTime, int waitingTime) {
    // TODO
    this->droneId = droneId;
    this->requestId = requestId;
    this->dispatchTime = dispatchTime;
    this->waitingTime = waitingTime;
}

int DispatchEvent::getDroneId() const {
    // TODO
    return this->droneId;
}

int DispatchEvent::getRequestId() const {
    // TODO
    return this->requestId;
}

int DispatchEvent::getDispatchTime() const {
    // TODO
    return this->dispatchTime;
}

int DispatchEvent::getWaitingTime() const {
    // TODO
    return this->waitingTime;
}

std::ostream& operator<<(std::ostream& os, const DispatchEvent& event) {
    // TODO
    os<<"Drone "<<event.droneId<<" dispatches request "<<event.requestId<<" at minute "<<event.dispatchTime<<" ( wait : "<<event.waitingTime<<" mins )";
    return os;
}
