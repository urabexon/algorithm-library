#pragma once
#include <bits/stdc++.h>
using namespace std;

// プリム法（最小全域木）
long long prim(int n, const vector<vector<pair<int, long long>>>& graph) {
    const long long INF = 1LL << 60;
    vector<bool> used(n, false);
    long long total = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (used[v])
            continue;
        used[v] = true;
        total += w;
        for (auto [nv, nw] : graph[v]) {
            if (!used[nv])
                pq.push({nw, nv});
        }
    }
    return total;
}