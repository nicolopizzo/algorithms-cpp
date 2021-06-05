#include <algorithm>
#include "WGraph.h"
#include "../base/UnionFind.h"

using std::sort;

WGraph::WGraph(int n) {
    V = n;
    E = 0;
    adjList = new vector<edge*>[n];
}

void WGraph::insertEdge(int u, int v, int w) {
    edge* e = new edge(u, v, w);

    adjList[u].push_back(e);
    adjList[v].push_back(e);

    E++;
}

vector<edge*> WGraph::neighbours(int v) {
    return adjList[v];
}

bool contains(vector<edge*> v, edge* x) {
    for (edge* y : v) {
        if (y == x) {
            return true;
        }
    }

    return false;
}

bool compareWeights(edge* a, edge* b) {
    return a->w < b->w;
}

vector<edge*> WGraph::mstKruskal() {
    vector<edge*> edges;

    // Populate all the edges
    for (int i = 0; i < V; i++) {
        for (edge* e : adjList[i]) {
            if (!contains(edges, e)) {
                edges.push_back(e);
            }
        }
    }

    // Sort the edges by weight
    sort(edges.begin(), edges.end(), compareWeights);

    UnionFind s = UnionFind(V);
    vector<edge*> res;

    // Find the mst
    for (edge* e : edges) {
        int u = e->u;
        int v = e->v;

        if (s.find(u) != s.find(v)) {
            s.merge(u, v);
            res.push_back(e);
        }
    }

    return res;
}