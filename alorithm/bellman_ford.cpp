/*************************************************************************
	> File Name: bellman_ford.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jan 2022 03:43:04 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

struct edge{
    int s, e, v;
};

edge edg[200005];
int s, n, m, edg_cnt, ans[100005];

void add_edg(int a, int b, int c) {
    edg[edg_cnt].s = a;
    edg[edg_cnt].e = b;
    edg[edg_cnt++].v = c;
}
int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    ans[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < edg_cnt; j++) {
            int s = edg[j].s, e = edg[j].e, v = edg[j].v;
            ans[e] = min(ans[s] + v, ans[e]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            cout << -1 << endl;
        }
        cout << ans[i] << endl;
    }

    return 0;
}
