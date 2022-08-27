/*************************************************************************
	> File Name: oj391.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Feb 2022 07:41:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long  num[100005];
int n, m;
long long l ,r;
long long func(long long x) {
    long long t = 0, now = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] > x) {
            now = num[i];
            t++;
        }else if(now + num[i] == x) {
            t++;
            now = 0;
        }else {
            now += num[i];
        }
    }
        if (now != 0) {
            t++;
        }
    return t;
}
long long bs() {
    while (l != r) {
        long long mid = (l + r) >> 1;
        if (func(mid) <= m) {
            r = mid ;
        }else {
            l  = mid + 1;
        }
    }
    return r;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        l = max(l, num[i]);
        r += num[i];
    }
    cout << bs() << endl;
    return 0;
}
