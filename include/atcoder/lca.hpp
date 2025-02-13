#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// Lowest Common Ancestor
struct LCA {
    int n;
    int log_n;
    vector<int> depth;
    vector<vector<int>> parent;

    LCA(int n): n(n) {
        log_n = 32 - __builtin_clz(n);
        depth.assign(n, 0);
        parent.assign(log_n, vector<int>(n, -1));
    }

    void dfs(const vector<vector<int>>& tree, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (int nv : tree[v]) {
            if (nv == p)
                continue;
            dfs(tree, nv, v, d + 1);
        }
    }

    void init(const vector<vector<int>>& tree, int root = 0) {
        dfs(tree, root, -1, 0);
        for (int k = 0; k + 1 < log_n; k++) {
            for (int v = 0; v < n; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int query(int u, int v) {
        if (depth[u] > depth[v])
            swap(u, v);
        for (int k = 0; k < log_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1)
                v = parent[k][v];
        }
        if (u == v)
            return u;
        for (int k = log_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};
