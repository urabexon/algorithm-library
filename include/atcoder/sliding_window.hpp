#pragma once
#include <bits/stdc++.h>
using namespace std;

// スライディングウィンドウ（例：長さ k の部分列の最大和）
long long slidingWindow(const vector<long long>& a, int k) {
    int n = a.size();
    if (n < k)
        return 0;
    long long sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];
    ans = sum;
    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];
        ans = max(ans, sum);
    }
    return ans;
}
