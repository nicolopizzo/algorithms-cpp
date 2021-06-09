#ifndef PQ_H
#define PQ_H

class PriorityQueue {
    int num;
    int* pq;
    int* qp;
    float* keys;

    public:
        PriorityQueue(int n);
        void insert(int i, float key);
        void decreaseKey(int i, float key);
        int deleteMin();
        int min();

        bool contains(int w);
        bool isEmpty();

    private:
        void bubbleUp(int i);
        void bubbleDown(int i);

};

#include "PriorityQueue.cpp"

#endif