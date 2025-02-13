#pragma once
#include <bits/stdc++.h>
using namespace std;

// 二分探索 (lower_bound)
int lowerBoundExample(const vector<int>& a, int x) {
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it != a.end())
        return distance(a.begin(), it);
    else
        return -1;
}
