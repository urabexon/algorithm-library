#pragma once
#include <bits/stdc++.h>
using namespace std;

// 順列全探索 (next_permutation)
void permutationExample(vector<int> perm) {
    sort(perm.begin(), perm.end());
    do {
        for (auto v : perm)
            cout << v << " ";
        cout << "\n";
    } while (next_permutation(perm.begin(), perm.end()));
}
