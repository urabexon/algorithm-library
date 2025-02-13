#pragma once
#include <bits/stdc++.h>
using namespace std;

// クラスカル法（最小全域木）
struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

long long kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    long long total = 0;
    for (auto &e : edges) {
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            total += e.w;
        }
    }
    return total;
}
