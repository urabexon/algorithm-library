#pragma once
#include <vector>
#include <cassert>
using namespace std;

// 行列累乗
// 行列の掛け算（多分もっと効率化できるかも）
template<typename T>
vector<vector<T>> multiplyMatrix(const vector<vector<T>>& A, const vector<vector<T>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();
    vector<vector<T>> C(n, vector<T>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < p; k++) {
            for (int j = 0; j < m; j++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

// 行列の累乗
template<typename T>
vector<vector<T>> matrixPower(vector<vector<T>> base, long long exp) {
    int n = base.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while(exp > 0) {
        if(exp & 1)
            res = multiplyMatrix(res, base);
        base = multiplyMatrix(base, base);
        exp >>= 1;
    }
    return res;
}
