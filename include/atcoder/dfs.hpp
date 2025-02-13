#pragma once
#include <bits/stdc++.h>
using namespace std;

// DFS (深さ優先探索)
void dfs(int v, const vector<vector<int>>& graph, vector<bool>& seen) {
    seen[v] = true;
    // ここに処理を記述
    for (auto nv : graph[v]) {
        if (!seen[nv])
            dfs(nv, graph, seen);
    }
}
