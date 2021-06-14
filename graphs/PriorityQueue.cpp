#include "PriorityQueue.h"
#include <limits>

// L'array qp mantiene l'indice del vertice i su pq
// Dunque, qp[v] = i indica che nell'array pq, il vertice v
// si trova nella i-esima posizione
PriorityQueue::PriorityQueue(int n) {
	num = 0;
	pq = new int[n+1];
	qp = new int[n];

	keys = new float[n];
	for (int i = 0; i < n; i++) {
		keys[i] = std::numeric_limits<float>::infinity();
		qp[i] = 0;
		pq[i] = -1;
	}
}

void PriorityQueue::insert(int v, float key) {
	num++;
	qp[v] = num;
	pq[num] = v;
	keys[v] = key;

	bubbleUp(num);
}

void PriorityQueue::decreaseKey(int v, float key) {
	if (keys[v] > key) {
		keys[v] = key;
	}

	bubbleUp(qp[v]);
}

int PriorityQueue::min() {
	return pq[1];
}

int PriorityQueue::deleteMin() {
	int v = pq[1];
	pq[1] = pq[num];
	qp[pq[1]] = 1;
	qp[v] = 0;
	num--;

	// Ripristino l'heap order della PQ
	bubbleDown(1);

	return v;
}

bool PriorityQueue::contains(int w) {
	return qp[w];
}

bool PriorityQueue::isEmpty() {
	return num == 0;
}

void swap(int& a, int& b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void PriorityQueue::bubbleUp(int i) {
	if (i <= 1) {
		return ;
	}

	int child = pq[i];
	int father = pq[i/2];
	if (keys[father] > keys[child]) {
		swap(pq[i/2], pq[i]);
		swap(qp[father], qp[child]);

		bubbleUp(i/2);
	}
}

void PriorityQueue::bubbleDown(int i) {
	if (i*2 > num) {
		return ;
	}

	int father = pq[i];

	int k = i*2;
	int child = pq[k];
	int c2 = pq[k+1];

	if (k+1 <= num && keys[c2] < keys[child]) {
		child = c2;
		k++;
	}

	if (keys[father] > keys[child]) {
		swap(pq[i], pq[k]);
		swap(qp[father], qp[child]);

		bubbleDown(k);
	}
}