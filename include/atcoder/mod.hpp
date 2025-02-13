#pragma once
#include <bits/stdc++.h>
using namespace std;

// mod
const long long MOD = 1000000007;

long long modAdd(long long a, long long b) {
    return (a + b) % MOD;
}

long long modMul(long long a, long long b) {
    return (a * b) % MOD;
}

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = modMul(res, a);
        a = modMul(a, a);
        b >>= 1;
    }
    return res;
}

long long modInv(long long a) {
    return modPow(a, MOD - 2); // MODが素数の場合
}
