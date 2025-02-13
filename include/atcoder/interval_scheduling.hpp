#pragma once
#include <bits/stdc++.h>
using namespace std;

// 区間スケジューリング問題（非重複区間の最大個数）
// 各区間を (開始時刻, 終了時刻) として、終了時刻でソート
int intervalScheduling(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
        return a.second < b.second;
    });
    int cnt = 0, last = -1;
    for (auto [s, e] : intervals) {
        if (s >= last) {
            cnt++;
            last = e;
        }
    }
    return cnt;
}
