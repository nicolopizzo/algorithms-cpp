#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

template <class T>
Queue<T>::Queue() {
    head = nullptr;
}

template <class T>
void Queue<T>::enqueue(int x) {
    enqueue(head, x);
}

template <class T>
void Queue<T>::enqueue(node<T>*& n, int x) {
    node<T>* m = new node<T>;
    m->value = x;
    m->next = nullptr;

    if (!n) {
        n = m;
        return;
    }

    node<T>* ptr = n;
    while(ptr->next != nullptr) {
        ptr = ptr->next;
    }

    ptr->next = m;
}

template <class T>
T Queue<T>::dequeue() {
    return dequeue(head);
}

template <class T>
T Queue<T>::dequeue(node<T>*& n) {
    T res = n->value;
    n = n->next;
    return res;
} 

template <class T>
void Queue<T>::print() {
    node<T>* ptr = head;

    while(ptr != nullptr) {
        cout << ptr->value << "->";
        ptr = ptr->next;
    }

    cout << "null" << endl;
}

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}