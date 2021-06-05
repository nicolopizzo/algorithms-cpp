#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    id = new int[n];
    size = n;

    for (int i = 0; i < n; i++) {
        id[i] = i;
    }
}

bool UnionFind::connected(int u, int v) {
    return id[u] == id[v];
}

void UnionFind::merge(int u, int v) {
    int p_u = find(u);
    int p_v = find(v);

    // Change all the parents of the set
    if (p_u != p_v) {
        for(int i = 0; i < size; i++) {
            if (id[i] == p_u) {
                id[i] = p_v;
            }
        }
    }
}

int UnionFind::find(int u) {
    return id[u];
}