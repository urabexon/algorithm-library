#pragma once
#include <bits/stdc++.h>
using namespace std;

// 全探索（例：各部分集合の列挙）
void bruteForceExample(int n) {
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i))
                cout << i << " ";
        }
        cout << "\n";
    }
}
