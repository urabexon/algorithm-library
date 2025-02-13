#pragma once
#include <bits/stdc++.h>
using namespace std;

// 貪欲法
vector<int> ChangeGreedy(int amount, vector<int> coins) {
    // 降順にソート（例として硬貨）
    sort(coins.rbegin(), coins.rend());
    vector<int> count(coins.size(), 0);
    for (size_t i = 0; i < coins.size(); i++) {
        count[i] = amount / coins[i];
        amount %= coins[i];
    }
    if (amount != 0) {
        // 組み合わせで表せない場合は空のベクトルを返す
        return vector<int>();
    }
    return count;
}
