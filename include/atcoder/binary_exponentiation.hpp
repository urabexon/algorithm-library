#pragma once
#include <bits/stdc++.h>
using namespace std;

// 繰り返し２乗法（一般的な累乗）
long long binaryExponentiation(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
