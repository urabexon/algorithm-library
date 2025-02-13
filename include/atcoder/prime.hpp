#pragma once
#include <bits/stdc++.h>
using namespace std;

// 素数判定
bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
