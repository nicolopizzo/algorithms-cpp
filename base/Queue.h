#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct node {
    T value;
    node* next;
};


template <class T>
class Queue {
    node<T>* head;

    public:
        Queue();

        void enqueue(int x);
        T dequeue();
        bool isEmpty();

        void print();

    private:
        void enqueue(node<T>*& n, int x);
        T dequeue(node<T>*& n);
};

#include "Queue.cpp"

#endif