#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Request.h"
#include "Drone.h"

class PriorityQueue {
private:
    struct Node {
        Request data;
        Node* next;

        Node(const Request& data, Node* next = 0);
    };

    Node* head;
    int size;
    int capacity;

    bool higherPriority(const Request& a,
                        const Request& b,
                        int currentTime) const;

public:
    PriorityQueue(int capacity = 500);
    ~PriorityQueue();

    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;

    void enqueue(const Request& req, int currentTime);
    Request peek(int currentTime) const;
    Request dequeue(int currentTime);
    bool hasEligibleRequest(const Drone& drone, int currentTime) const;
};

#endif
