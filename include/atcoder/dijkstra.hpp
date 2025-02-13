#pragma once
#include <bits/stdc++.h>
using namespace std;

// ダイクストラ（単一始点最短経路）
vector<long long> dijkstra(int s, const vector<vector<pair<int, long long>>>& graph) {
    int n = graph.size();
    const long long INF = 1LL << 60;
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] < d)
            continue;
        for (auto [nv, w] : graph[v]) {
            if (dist[nv] > dist[v] + w) {
                dist[nv] = dist[v] + w;
                pq.push({dist[nv], nv});
            }
        }
    }
    return dist;
}
