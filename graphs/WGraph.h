#ifndef WGRAPH_H
#define WGRAPH_H

#include <vector>

using std::vector;

struct edge {
    int u;
    int v;
    float w;

    edge(int x, int y, int z) {
        u = x;
        v = y;
        w = z;
    }

    edge(){}
};

class WGraph {
    vector<edge*>* adjList;
    int V;
    int E;

    public:
        WGraph(int n);
        void insertEdge(int u, int v, int w);
        vector<edge*> neighbours(int u);

        vector<edge*> mstKruskal();
        vector<edge*> mstPrim(int s);
};

#include "WGraph.cpp"

#endif