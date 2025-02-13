#pragma once
#include <bits/stdc++.h>
using namespace std;

// バックトラッキングアルゴリズム
void backtracking(vector<int>& cur, int n, int k) {
    if (cur.size() == k) {
        // 解の出力
        for (auto v : cur)
            cout << v << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cur.push_back(i);
        backtracking(cur, n, k);
        cur.pop_back();
    }
}
