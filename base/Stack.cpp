#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack() {
    head = nullptr;
    sz = 0;
}

template <class T>
void Stack<T>::push(T value) {
    node<T>* n = new node<T>;
    n->next = head;
    n->value = value;

    head = n;
    sz++;
}

template <class T>
T Stack<T>::pop() {
    const T value = head->value;
    head = head->next;
    sz--;

    return value;
}

template <class T>
T Stack<T>::top() {
    return head->value;
}

template <class T>
bool Stack<T>::isEmpty() {
    return sz == 0;
}

template <class T>
int Stack<T>::size() {
    return sz;
}

template <class T>
bool Stack<T>::contains(T value) {
    node<T>* ptr = head;

    for (int i = 0; i < sz; i++, ptr = ptr->next) {
        if (ptr->value == value) {
            return true;
        }
    }

    return false;
}