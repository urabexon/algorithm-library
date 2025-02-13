#pragma once
#include <bits/stdc++.h>
using namespace std;

// トポロジカルソート
vector<int> topologicalSort(int n, const vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto v : graph[i])
            indegree[v]++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            que.push(i);
    }
    vector<int> order;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        order.push_back(v);
        for (auto nv : graph[v]) {
            indegree[nv]--;
            if (indegree[nv] == 0)
                que.push(nv);
        }
    }
    return order;
}
