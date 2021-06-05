#ifndef UNION_FIND_H
#define UNION_FIND_H

class UnionFind {
    int* id;
    int size;

    public:
        UnionFind(int n);

        bool connected(int u, int v);
        void merge(int u, int v);
        int find(int u);

};

#include "UnionFind.cpp"

#endif