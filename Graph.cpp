#include "Graph.h"
#include "base/Queue.h"
#include <iostream>

using namespace std;

Graph::Graph(int n) {
    V = n;
    E = 0;
    adjList = new vector<int>[n];
}

void Graph::insertEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    E++;
}

vector<int> Graph::getAdj(int v) {
    return adjList[v];
}

void Graph::dfs(int v) {
    bool* marked = new bool[V]{false};
    dfs(marked, v);
}

void Graph::dfs(bool* marked, int v) {
    marked[v] = true;

    for(int u : getAdj(v)) {
        if (!marked[u]) {
            dfs(marked, u);
        }

    }

    cout << v << " ";
}

void Graph::bfs(int v) {
    Queue<int> q;
    bool* marked = new bool[V]{false};
    
    q.enqueue(v);
    marked[v] = true;

    while(!q.isEmpty()) {
        int w = q.dequeue();
        for (int u : adjList[w]) {
            if (!marked[u]) {
                q.enqueue(u);
                marked[u] = true;
            }
        }

        cout << w << " ";
    }

    cout << endl;
}