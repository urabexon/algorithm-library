#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// Sparse Table
template<typename T>
struct SparseTable {
    int n;
    int log_n;
    vector<vector<T>> st;

    SparseTable(const vector<T>& a) {
        n = a.size();
        log_n = 32 - __builtin_clz(n);
        st.assign(log_n, vector<T>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];
        for (int k = 1; k < log_n; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    // 区間 [l, r) の最小値を返す
    T query(int l, int r) {
        int k = 31 - __builtin_clz(r - l);
        return min(st[k][l], st[k][r - (1 << k)]);
    }
};
