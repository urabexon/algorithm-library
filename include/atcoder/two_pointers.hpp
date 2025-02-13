#pragma once
#include <bits/stdc++.h>
using namespace std;

// しゃくとり法（Two Pointers）
// 連続部分列の和がk以下の最大長を求める時など
int twoPointersExample(const vector<int>& a, int k) {
    int n = a.size();
    int sum = 0, ans = 0, r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && sum + a[r] <= k) {
            sum += a[r];
            r++;
        }
        ans = max(ans, r - l);
        if (l < r)
            sum -= a[l];
        else
            r++;
    }
    return ans;
}
