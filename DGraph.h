#ifndef DGRAPH_H
#define DGRAPH_H

#include <vector>
#include "base/Stack.h"

using std::vector;

class DGraph {
    vector<int>* adjList;
    int V;
    int E;

    public:
        DGraph(int n);
        void insertEdge(int u, int v);
        vector<int> getAdj(int v);
        
        // visits
        void dfs(int v);
        void bfs(int v);
        Stack<int> topological();

        bool isAcyclic();

    private:
        void dfs(bool* marked, int v);
        bool isAcyclic(bool* marked, int v=0);
        void topological(bool* marked, Stack<int> s, int v=0);
};

#include "DGraph.cpp"

#endif