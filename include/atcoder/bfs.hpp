#pragma once
#include <bits/stdc++.h>
using namespace std;

// BFS (幅優先探索)
void bfs(int start, const vector<vector<int>>& graph, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, -1);
    queue<int> que;
    dist[start] = 0;
    que.push(start);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : graph[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
}
