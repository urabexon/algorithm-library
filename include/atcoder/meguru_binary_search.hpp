#pragma once
#include <bits/stdc++.h>
using namespace std;

// めぐる式二分探索
// ok: 条件を満たす初期値, ng: 条件を満たさない初期値
template<typename T, typename F>
T meguruBinarySearch(T ok, T ng, F isOK) {
    while (abs(ok - ng) > 1) {
        T mid = ok + (ng - ok) / 2;
        if (isOK(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}
