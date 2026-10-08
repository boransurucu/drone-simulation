#include "DispatchSimulator.h"
#include "PriorityQueue.h"
#include "Drone.h"
#include "DispatchEvent.h"
#include <iostream>


DispatchSimulator::DispatchSimulator(Request* requests, int requestCount, double maxAvgWaitingTime) {
//TODO
this->requestCount = requestCount;
this->maxAvgWaitingTime = maxAvgWaitingTime;
this->requests = new Request[requestCount];
for(int i = 0;i < this->requestCount;i++){
    this->requests[i] = requests[i];
}
}

DispatchSimulator::DispatchSimulator(const DispatchSimulator& other) {
//TODO
requestCount = other.requestCount;
maxAvgWaitingTime = other.maxAvgWaitingTime;
if(other.requestCount > 0 && other.requests != 0){
    this->requests = new Request[requestCount];
    for(int i = 0;i < requestCount;i++){
        this->requests[i] = other.requests[i];
    }
}
else{this->requests = 0;}    
}

DispatchSimulator& DispatchSimulator::operator=(const DispatchSimulator& other) {
//TODO
if(this != &other){
    this->requestCount = other.requestCount;
    this->maxAvgWaitingTime = other.maxAvgWaitingTime;
    delete[] this->requests;
    if(other.requestCount > 0 && other.requests != 0){
        this->requests = new Request[requestCount];
        for(int i  = 0;i < requestCount;i++){
            this->requests[i] = other.requests[i];
        }
    }
    else{this->requests = 0;}
}
return *this;    
}

DispatchSimulator::~DispatchSimulator() {
//TODO
delete[] requests;
}

DispatchSimulator::DispatchSimulator() {
    // TODO
    this->requests = 0;
    this->requestCount = 0;
    this->maxAvgWaitingTime = 0;
}


double DispatchSimulator::simulate(int droneCount, bool printTrace) {
    // TODO
    int t = requests[0].getArrivalTime();
    int finished_request = 0;
    double total_wait = 0.0;
    int request_index = 0;

    Drone* drones = new Drone[droneCount];
    for(int i = 0;i < droneCount;i++){
        drones[i] = Drone(i);
    }

    PriorityQueue waiting(requestCount);

    while(finished_request < requestCount){
        while(request_index < requestCount && requests[request_index].getArrivalTime() <= t){
            waiting.enqueue(requests[request_index], t);
            request_index++;
        }
        for(int i = 0;i < droneCount;i++){
            PriorityQueue temp(requestCount);
            if(drones[i].isAvailableAt(t) && waiting.hasEligibleRequest(drones[i], t)){
                while(!waiting.isEmpty()){
                    Request current = waiting.dequeue(t);
                    if(current.isEligibleFor(drones[i])){
                        total_wait += t - current.getArrivalTime();
                        drones[i].setNextAvailableTime(t + current.getServiceTime());
                        finished_request++;
                        if(printTrace){
                            DispatchEvent event(drones[i].getDroneId(), current.getRequestId(), t, (t - current.getArrivalTime()));
                            std::cout<<event<<std::endl;
                        }
                        break;
                    }
                    else{
                        temp.enqueue(current, t);
                    }
                }
                while(!temp.isEmpty()){
                    waiting.enqueue(temp.dequeue(t), t);
                }
            }
        }
        if(finished_request < requestCount){
            int t_jump = -1;
            if(request_index < requestCount){
                t_jump = requests[request_index].getArrivalTime();
            }
            for(int i = 0; i < droneCount;i++){
                if(drones[i].getNextAvailableTime() > t){
                    if(t_jump == -1 || drones[i].getNextAvailableTime() < t_jump){
                        t_jump = drones[i].getNextAvailableTime();
                    }    
                }
            }
            if(t_jump != -1){
                t = t_jump;
            }
        }
    }
    
    delete[] drones;
    return total_wait / requestCount;
}

int DispatchSimulator::findMinimumDroneCount() {
    // TODO
    int number = 1;
    while(simulate(number, false) > maxAvgWaitingTime){
        number++;
    }
    std::cout<<"Minimum number of drones required : "<<number<<std::endl;
    std::cout<<"Simulation with "<<number<<" drones :"<<std::endl;
    simulate(number, true);
    double average = simulate(number, false);    
    std::cout<<"Average waiting time : "<<average<<std::endl;
    return number;
}
