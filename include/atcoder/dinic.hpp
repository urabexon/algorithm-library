#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

// Dinic法
struct Dinic {
    struct Edge {
        int to, rev;
        long long cap;
    };
    int n;
    vector<vector<Edge>> graph;
    vector<int> level, iter;
    Dinic(int n): n(n), graph(n), level(n), iter(n) {}

    void add_edge(int s, int t, long long cap) {
        graph[s].push_back({t, (int)graph[t].size(), cap});
        graph[t].push_back({s, (int)graph[s].size() - 1, 0});
    }

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : graph[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    long long dfs(int v, int t, long long flow) {
        if (v == t)
            return flow;
        for (int &i = iter[v]; i < graph[v].size(); i++) {
            Edge &e = graph[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                long long d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        const long long INF = numeric_limits<long long>::max();
        while (true) {
            bfs(s);
            if (level[t] < 0)
                break;
            fill(iter.begin(), iter.end(), 0);
            while (long long f = dfs(s, t, INF))
                flow += f;
        }
        return flow;
    }
};
