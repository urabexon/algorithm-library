#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

// Hopcroft-Karp
struct HopcroftKarp {
    int n, m;
    vector<vector<int>> graph;
    vector<int> dist;
    vector<int> matchL, matchR;

    HopcroftKarp(int n, int m): n(n), m(m) {
        graph.assign(n, vector<int>());
        dist.assign(n, 0);
        matchL.assign(n, -1);
        matchR.assign(m, -1);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (matchL[i] == -1) {
                dist[i] = 0;
                q.push(i);
            } else {
                dist[i] = numeric_limits<int>::max();
            }
        }
        int d = numeric_limits<int>::max();
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < d) {
                for (int v : graph[u]) {
                    if (matchR[v] == -1) {
                        d = dist[u] + 1;
                    } else if (dist[matchR[v]] == numeric_limits<int>::max()) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
                }
            }
        }
        return d != numeric_limits<int>::max();
    }

    bool dfs(int u, int d) {
        if (dist[u] == d) {
            dist[u] = numeric_limits<int>::max();
            for (int v : graph[u]) {
                int w = matchR[v];
                if (w == -1 || (dist[w] == d + 1 && dfs(w, d + 1))) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maxMatching() {
        int matching = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                if (matchL[i] == -1 && dfs(i, 0))
                    matching++;
            }
        }
        return matching;
    }
};
