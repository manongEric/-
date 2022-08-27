/*************************************************************************
	> File Name: oj242.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 May 2022 02:52:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
long long arr[MAX_N + 5];
long long  n, m, l, r;

int f(int x, int m) {
    arr[0] = x;
    long long pre = 0, si = 0, sj = 0;
    for (int i = 1; i <= n; i++) {
        si += (arr[i] - x);
        if (i < m) continue;
        sj += (arr[i - m] - x);
        pre = min(pre, sj);
        if (si - pre >= 0) return 1;
    }
    return 0;
}
int bs(int l, int r, int m) {
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        if (f(mid, m)) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
        if (i == 1) l = r = arr[i];
        l = min(arr[i], l);
        r = max(arr[i], r);
    }
    cout << bs(l, r, m) << endl;
    return 0;
}
