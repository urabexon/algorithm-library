#pragma once
#include <bits/stdc++.h>
using namespace std;

// bit全探索
void bitFullSearch(int n) {
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                // i番目の要素
            }
        }
    }
}
