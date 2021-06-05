#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using std::vector;

class Graph {
    vector<int>* adjList;
    int V;
    int E;

    public:
        Graph(int n);
        void insertEdge(int u, int v);
        vector<int> getAdj(int v);
        
        // visits
        void dfs(int v);
        void bfs(int v);

        // ~Graph();

    private:
        void dfs(bool* marked, int v);
};

#include "Graph.cpp"

#endif