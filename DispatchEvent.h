#ifndef DISPATCHEVENT_H
#define DISPATCHEVENT_H

#include <iostream>

class DispatchEvent {
private:
    int droneId;
    int requestId;
    int dispatchTime;
    int waitingTime;

public:
    DispatchEvent();
    DispatchEvent(int droneId, int requestId,
                  int dispatchTime, int waitingTime);

    int getDroneId() const;
    int getRequestId() const;
    int getDispatchTime() const;
    int getWaitingTime() const;

    friend std::ostream& operator<<(std::ostream& os,
                                    const DispatchEvent& event);
};

#endif
