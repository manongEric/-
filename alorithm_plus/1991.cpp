/*************************************************************************
	> File Name: 1991.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Mar 2022 08:30:06 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct edge {
    int s, e;
    double v;
    bool operator< (const edge &b) const {
        return this->v < b.v;
    }
};
edge edg[25005];
int n, k, cnt, edg_cnt, xy[2][505], my_union[505];
void func(int a, int b) {
    long long t1 = xy[0][a] - xy[0][b];
    long long t2 = xy[1][a] - xy[1][b];
    edg[edg_cnt].s = a;
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = sqrt(t1 * t1 + t2 * t2);
    edg_cnt++;
}
int find_fa(int x) {
    if (my_union[x] == x) return x;
    return my_union[x] = find_fa(my_union[x]);
}
int main() {
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        my_union[i] = i;
        cin >> xy[0][i] >> xy[1][i];
        for (int j = 1; j < i; j++) {
            func(i, j);
        }
    }
    sort(edg, edg + edg_cnt);
    for (int i = 0; i < edg_cnt; i++) {
        int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
        if (fa != fb) {
            my_union[fa] = fb;
            cnt++;
            if (cnt == n - k) {
                printf("%.2f\n", edg[i].v);
            }
        }
    }
    return 0;
}

