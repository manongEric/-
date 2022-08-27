/*************************************************************************
	> File Name: 1991.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Jan 2022 04:38:06 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct edge {
    int s, e;
    double v;
    bool operator< (const edge &b) const {
        return v < b.v;
    }
};
edge edg[250005];
int k, n, edg_cnt, xy[505][2], my_union[505];


double func(int a, int b) {
    edg[edg_cnt].s = a;
    edg[edg_cnt].e = b;
    long long x = xy[a][0] - xy[b][0];
    long long y = xy[a][1] - xy[b][1]; 
    edg[edg_cnt].v = sqrt(x * x - y * y);
    edg_cnt++;
}
int main() {
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
        for (int j = 1; j < i; j++) {
            double v = func(i, j);
        }
    }
    


    return 0;
}

