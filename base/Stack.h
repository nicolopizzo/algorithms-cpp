#ifndef STACK_H
#define STACK_H

template <class T>
struct node {
    T value;
    node<T>* next;
};

template <class T>
class Stack {
    node<T>* head;
    int sz;

    public:
        Stack();

        void push(T value);
        T pop();
        T top();
        int size();
        bool isEmpty();
        bool contains(T value);

        void print();

};

#include "Stack.cpp"

#endif