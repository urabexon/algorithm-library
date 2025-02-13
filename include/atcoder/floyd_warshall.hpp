#pragma once
#include <bits/stdc++.h>
using namespace std;

// ワーシャルフロイド（全点間最短経路）
vector<vector<long long>> floydWarshall(int n, vector<vector<long long>> dist) {
    const long long INF = 1LL << 60;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}