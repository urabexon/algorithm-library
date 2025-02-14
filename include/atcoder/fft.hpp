#pragma once
#include <complex>
#include <vector>
#include <cmath>
using namespace std;
typedef complex<double> cd;
const double PI = acos(-1);

// 離散フーリエ変換(FFT、未検証&あんまり自信ない)
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if(n == 1)
        return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[i * 2];
        a1[i] = a[i * 2 + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

// FFTで多項式 a と b の積を計算する。戻り値は係数の配列
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = int(round(fa[i].real()));
    // 必要なサイズ（a.size() + b.size() - 1）に調整する
    result.resize(a.size() + b.size() - 1);
    return result;
}