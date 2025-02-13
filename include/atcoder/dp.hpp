#pragma once
#include <bits/stdc++.h>
using namespace std;

// DP（ナップサック）
int knapSack(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    }
    return dp[W];
}
