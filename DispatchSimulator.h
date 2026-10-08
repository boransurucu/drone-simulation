#ifndef DISPATCHSIMULATOR_H
#define DISPATCHSIMULATOR_H

#include "Request.h"

class DispatchSimulator {
private:
    Request* requests;
    int requestCount;
    double maxAvgWaitingTime;

public:
    DispatchSimulator();
    DispatchSimulator(Request* requests, int requestCount, double maxAvgWaitingTime);
    DispatchSimulator(const DispatchSimulator& other);
    DispatchSimulator& operator=(const DispatchSimulator& other);
    ~DispatchSimulator();

    double simulate(int droneCount, bool printTrace);
    int findMinimumDroneCount();
};

#endif
