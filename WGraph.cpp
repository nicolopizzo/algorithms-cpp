#include "WGraph.h"

WGraph::WGraph(int n) {
    V = n;
    E = 0;
}

void WGraph::insertEdge(int u, int v, int w) {
    edge* e = new edge(u, v, w);

    adjList[u].push_back(e);
    adjList[v].push_back(e);
}

vector<edge*> WGraph::neighbours(int v) {
    return adjList[v];
}