#pragma once
#include <bits/stdc++.h>
using namespace std;

// 累積和
vector<long long> prefixSum(const vector<long long>& a) {
    int n = a.size();
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    return sum;
}
