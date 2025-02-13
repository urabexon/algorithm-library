#pragma once
#include <tuple>
using namespace std;

// 拡張ユークリッドの互除法
tuple<long long, long long, long long> extendedGCD(long long a, long long b) {
    if (b == 0)
        return {a, 1, 0};
    auto [g, x1, y1] = extendedGCD(b, a % b);
    return {g, y1, x1 - (a / b) * y1};
}
