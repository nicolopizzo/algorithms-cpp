#include <algorithm>
#include "WGraph.h"
#include "../base/UnionFind.h"
#include "PriorityQueue.h"
#include <limits>

using std::sort;
using namespace std;

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

vector<edge*> WGraph::mstPrim(int s) {
    float distTo[V];
    edge* edgeTo[V];
    bool marked[V];
    vector<edge*> mst;

    for (int i = 0; i < V; i++) {
        distTo[i] = numeric_limits<float>::infinity();
        edgeTo[i] = nullptr;
        marked[i] = false;
    }
    
    PriorityQueue pq = PriorityQueue(V);
    distTo[s] = s;

    pq.insert(s, distTo[s]);

    while(!pq.isEmpty()) {
        int v = pq.deleteMin();
        marked[v] = true;
        if (edgeTo[v]) {
            mst.push_back(edgeTo[v]);
        }

        for (edge* e : adjList[v]) {
            int w = v == e->v ? e->u : e->v;

            if (marked[w]) {
                continue;
            }

            if (e->w < distTo[w]) {
                distTo[w] = e->w;
                edgeTo[w] = e;
                if (pq.contains(w)) {
                    pq.decreaseKey(w, distTo[w]);
                }
                else {
                    pq.insert(w, distTo[w]);
                }
            }
        }
    }

    return mst;
}