#pragma once
#include <bits/stdc++.h>
using namespace std;

// imos法
// updates: (l, r, value) -> 区間 [l, r) に value を加算
vector<long long> imosMethod(int n, const vector<tuple<int, int, long long>>& updates) {
    vector<long long> imos(n + 1, 0);
    for (auto [l, r, v] : updates) {
        imos[l] += v;
        if (r < n)
            imos[r] -= v;
    }
    for (int i = 0; i < n; i++)
        imos[i + 1] += imos[i];
    imos.pop_back();
    return imos;
}
