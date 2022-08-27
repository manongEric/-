/*************************************************************************
	> File Name: 1991_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 07:26:42 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m, n, cnt, edg_cnt, ans, xy[505][2], my_union[505];
struct edge{
    int s, e;
    double v;
    bool operator< (const edge &b) const{
        return this->v < b.v;
    }
};
edge edg[250005];
void func(int a, int b) {
    long long t1 = xy[a][0] - xy[b][0];
    long long t2 = xy[a][1] - xy[b][1];
    double c = sqrt(t1 * t1 + t2 * t2);
    edg[edg_cnt].s = a;
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg_cnt++;
}
int find_fa(int x) {
    if (my_union[x] == x) {
        return x;
    }
    return my_union[x] = find_fa(my_union[x]);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        my_union[i] = i;
        cin >> xy[i][0] >> xy[i][1];
        for (int j = 1; j < i; j++) {
            func(j, i);
        }
    }
    sort(edg, edg + edg_cnt);
    for (int i = 0; i < edg_cnt; i++) {
        int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
        if (fa != fb) {
            my_union[fa] = fb;
            cnt++;
            if (cnt == m - n) {
                printf("%.2f\n", edg[i].v);
                return 0;
            }
        }
    }
    return 0;
}
