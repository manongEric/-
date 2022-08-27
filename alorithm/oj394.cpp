/*************************************************************************
	> File Name: oj394.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Feb 2022 10:16:21 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[50005], l, n, m, rawl = 1000000001;
int func(int x) {
    int last = 0, t = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (num[i] - last < x) {
            t++;
        }else {
            last = num[i];
        }
    }
    return t;
}
int bs() {
    int le = rawl, ri = l;
    while (le != ri) {
        int mid = (le + ri + 1) / 2;
        int s = func(mid);
        if (s <= m) {
            le = mid;
        }else {
            ri = mid - 1;
        }
    }
    
    return le;
}
int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        rawl = min(rawl, num[i]- num[i - 1]);
    }
    num[n + 1] = l;
    rawl = min(rawl, l - num[n]);
    cout << bs() << endl;
    return 0;
}

