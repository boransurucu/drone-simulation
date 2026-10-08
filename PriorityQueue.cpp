#include "PriorityQueue.h"

PriorityQueue::Node::Node(const Request& data, Node* next)
    : data(data), next(next) {
}

PriorityQueue::PriorityQueue(int capacity) {
    // TODO
    this->head = 0;
    this->size = 0;
    this->capacity = capacity;

}

PriorityQueue::~PriorityQueue() {
    // TODO
    while(head != 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool PriorityQueue::isEmpty() const {
    // TODO
    if(size == 0){return true;}
    else{return false;}
}

bool PriorityQueue::isFull() const {
    // TODO
    if(size == capacity){return true;}
    else{return false;}
}

int PriorityQueue::getSize() const {
    // TODO
    return this->size;
}

bool PriorityQueue::higherPriority(const Request& a,
                                   const Request& b,
                                   int currentTime) const {
    // TODO
    if(a.getSeverityLevel() > b.getSeverityLevel()){return true;}
    else if(a.getSeverityLevel() < b.getSeverityLevel()){return false;}
    else{
        if(a.getPackageType() > b.getPackageType()){return true;}
        else if(a.getPackageType() < b.getPackageType()){return false;}
        else{
            if(a.getDistanceToZone() < b.getDistanceToZone()){return true;}
            else if(a.getDistanceToZone() > b.getDistanceToZone()){return false;}
            else{
                if(a.getWaitingTime() > b.getWaitingTime()){return true;}
                else if(a.getWaitingTime() < b.getWaitingTime()){return false;}
                else{
                    if(a.getRequestId() < b.getRequestId()){return true;}
                    else if(a.getRequestId() > b.getRequestId()){return false;}
                }
            }
        }
    }
}

void PriorityQueue::enqueue(const Request& req, int currentTime) {
    // TODO
    if(isFull()){return;}
    else{
        Node* newnode = new Node(req, head);
        head = newnode;
        size++;
    }
}

Request PriorityQueue::peek(int currentTime) const {
    // TODO
    if(isEmpty()){return Request();}

    Node* highest = head;
    Node* temp = head->next;
    while(temp != 0){
        if(higherPriority(highest->data, temp->data, currentTime)){
            temp = temp->next;
        }
        else if(higherPriority(temp->data, highest->data, currentTime)){
            highest = temp;
            temp = temp->next;
        }
    }
    return highest->data;
}

Request PriorityQueue::dequeue(int currentTime) {
    // TODO   
    if(isEmpty()){return Request();}

    Node* highest = head;
    Node* temp = head;
    Node* prev = head;
    while(temp->next != 0){
        if(higherPriority(highest->data, temp->next->data, currentTime)){
            temp = temp->next;
        }
        else if(higherPriority(temp->next->data, highest->data, currentTime)){
            highest = temp->next;
            prev = temp;
            temp = temp->next;
        }
    }
    if(highest == head){
        head = head->next;
    }
    else{
        prev->next = highest->next;
    }
    Request x = highest->data;
    delete highest;
    size--;
    return x;
        
}

bool PriorityQueue::hasEligibleRequest(const Drone& drone, int currentTime) const {
    // TODO
    Node* temp = head;
    while(temp != 0){
        if(temp->data.isEligibleFor(drone)){
            return true;
        }
        else{
            temp = temp->next;
        }
    }
    return false;
}
