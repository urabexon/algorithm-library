#pragma once
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

// 拡張ユークリッドの互除法を利用
pair<long long, long long> chineseRemainder(const vector<long long>& r, const vector<long long>& m) {
    long long x = 0, lcm = 1;
    int n = r.size();
    for (int i = 0; i < n; i++) {
        auto [g, p, q] = extendedGCD(lcm, m[i]);
        if ((r[i] - x) % g != 0)
            return {0, -1}; // 解なし
        long long mod = m[i] / g;
        x = x + lcm * (((r[i] - x) / g * p) % mod);
        lcm = lcm / g * m[i];
        x = (x % lcm + lcm) % lcm;
    }
    return {x, lcm};
}
