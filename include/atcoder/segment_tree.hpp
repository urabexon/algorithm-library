#pragma once
#include <bits/stdc++.h>
using namespace std;

// Segment Tree
template<typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    T defaultValue;
    function<T(T, T)> func;

    SegmentTree(vector<T> v, T defaultValue, function<T(T, T)> func)
        : defaultValue(defaultValue), func(func) {
        n = v.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; i++)
            tree[n + i] = v[i];
        for (int i = n - 1; i > 0; i--)
            tree[i] = func(tree[2 * i], tree[2 * i + 1]);
    }

    void update(int i, T val) {
        i += n;
        tree[i] = val;
        while (i > 1) {
            i /= 2;
            tree[i] = func(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(int l, int r) {
        T leftRes = defaultValue, rightRes = defaultValue;
        l += n; r += n;
        while (l < r) {
            if (l & 1)
                leftRes = func(leftRes, tree[l++]);
            if (r & 1)
                rightRes = func(tree[--r], rightRes);
            l /= 2;
            r /= 2;
        }
        return func(leftRes, rightRes);
    }
};
