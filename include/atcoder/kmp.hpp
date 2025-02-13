#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// KMP
// 最長共通接頭辞の長さ（i > 0の場合、自己一致を除く）
vector<int> buildPrefix(const string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// text中のpattern出現位置を返す
vector<int> kmpSearch(const string &text, const string &pattern) {
    vector<int> result;
    if (pattern.empty())
        return result;
    int n = text.size(), m = pattern.size();
    vector<int> pi = buildPrefix(pattern);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m) {
            result.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return result;
}
