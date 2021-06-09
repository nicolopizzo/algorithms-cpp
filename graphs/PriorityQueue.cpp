#include "PriorityQueue.h"
#include <limits>

PriorityQueue::PriorityQueue(int n) {
    num = 0;
    pq = new int[n+1];
    qp = new int[n];
    keys = new float[n+1];
    for (int i = 0; i < n+1; i++) {
        keys[i] = std::numeric_limits<float>::infinity();
    }
}

void PriorityQueue::insert(int i, float key) {
    num++;
    qp[i] = num;
    pq[num] = i;
    keys[i] = key;

    bubbleUp(num);
}

void PriorityQueue::decreaseKey(int i, float key) {
    if (keys[i] > key) {
        keys[i] = key;
    }

    bubbleUp(qp[i]);
}

int PriorityQueue::min() {
    return pq[1];
}

int PriorityQueue::deleteMin() {
    int v = pq[1];
    pq[1] = pq[num];
    keys[1] = keys[num];
    num--;

    // Ripristino l'heap order della PQ
    bubbleDown(1);

    return v;
}

bool PriorityQueue::contains(int w) {
    // Check lineare
    for (int i = 0; i < num; i++) {
        if (pq[i] == w) {
            return true;
        }
    }

    return false;
}

bool PriorityQueue::isEmpty() {
    return num == 0;
}

void swap(int& a, int& b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

void swapFloat(float& a, float& b) {
    float tmp = a;
    a = b;
    b = tmp;
}

// Definire le operazioni di bubbleUp e bubbleDown
void PriorityQueue::bubbleUp(int i) {
    if (i <= 1) {
        return ;
    }

    int child = pq[i];
    int father = pq[i/2];
    if (keys[i] < keys[i/2]) {
        swap(pq[i/2], pq[i]);
        swapFloat(keys[i], keys[i/2]);
        // swap(qp[i/2], qp[i]);

        bubbleUp(i/2);
    }
}

void PriorityQueue::bubbleDown(int i) {
    if (i*2 > num) {
        return ;
    }

    int k = i*2;
    int c1 = pq[k];
    int c2 = pq[k+1];

    // Take min of the keys
    if (k+1 <= num && keys[k+1] < keys[k]) {
        k++;
    }

    if (keys[i] > keys[k]) {
        swap(pq[i], pq[k]);
        swapFloat(keys[i], keys[k]);
        // swap(qp[i], qp[k]);

        bubbleDown(k);
    }
}