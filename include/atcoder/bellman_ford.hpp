#pragma once
#include <bits/stdc++.h>
using namespace std;

// ベルマンフォード（単一始点最短経路・負閉路検出）
pair<bool, vector<long long>> bellmanFord(int s, int n, const vector<tuple<int, int, long long>>& edges) {
    const long long INF = 1LL << 60;
    vector<long long> dist(n, INF);
    dist[s] = 0;
    bool updated;
    for (int i = 0; i < n; i++) {
        updated = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }
    // 負閉路検出
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w)
            return {false, {}};
    }
    return {true, dist};
}