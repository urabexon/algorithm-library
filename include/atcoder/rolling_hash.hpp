#pragma once
#include <string>
#include <vector>
using namespace std;

// Rolling Hash
struct RollingHash {
    typedef unsigned long long ull;
    vector<ull> hash, power;
    const ull base = 131;  // 基数31, 131 など用途に応じて選択する
    RollingHash(const string &s) {
        int n = s.size();
        hash.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for (int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + s[i];
            power[i + 1] = power[i] * base;
        }
    }
    // substring [l, r) のハッシュ値を返す
    ull get(int l, int r) {
        return hash[r] - hash[l] * power[r - l];
    }
};
