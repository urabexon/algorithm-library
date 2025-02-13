#pragma once
#include <bits/stdc++.h>
using namespace std;

// UnionFind
struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};
