#pragma once
#include <bits/stdc++.h>
using namespace std;

// XORの性質
int xorAll(const vector<int>& a) {
    int res = 0;
    for (auto x : a)
        res ^= x;
    return res;
}
