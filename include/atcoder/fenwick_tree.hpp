#pragma once
#include <vector>
using namespace std;

// Fenwick Tree
template<typename T>
struct FenwickTree {
    int n;
    vector<T> tree;
    FenwickTree(int n): n(n), tree(n+1, 0) {}

    void update(int i, T delta) {
        for (++i; i <= n; i += i & -i)
            tree[i] += delta;
    }

    T query(int i) {
        T sum = 0;
        for (++i; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }
};
