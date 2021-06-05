#include "DGraph.h"
#include <iostream>
#include "base/Stack.h"

using namespace std;

DGraph::DGraph(int n) {
    V = n;
    E = 0;
    adjList = new vector<int>[n];
}

void DGraph::insertEdge(int u, int v) {
    adjList[u].push_back(v);
    E++;
}

vector<int> DGraph::getAdj(int v) {
    return adjList[v];
}

void DGraph::dfs(int v) {
    bool* marked = new bool[V]{false};
    dfs(marked, v);

    cout << endl;
}

void DGraph::dfs(bool* marked, int v) {
    marked[v] = true;

    for(int u : getAdj(v)) {
        if (!marked[u]) {
            dfs(u);
        }
    }

    // apply visit function
    cout << v << " ";
}

Stack<int> DGraph::topological() {
    Stack<int> s;
    if(!isAcyclic()) {
        return s;
    }

    bool* marked = new bool[V]{false};
    topological(marked, s);

    return s;
}

void DGraph::topological(bool* marked, Stack<int> s, int v) {
    marked[v] = true;
    
    for (int u : getAdj(v)) {
        topological(marked, s, u);
    }

    s.push(v);
}

bool DGraph::isAcyclic() {
    bool* marked = new bool[V]{false};

    return isAcyclic(marked);
}

bool DGraph::isAcyclic(bool* marked, int v) {
    marked[v] = true;

    for (int u : getAdj(v)) {
        if (marked[u]) {
            return false;
        }
        dfs(u);
    }

    return true;
}