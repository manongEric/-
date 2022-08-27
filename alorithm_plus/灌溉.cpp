/*************************************************************************
	> File Name: prim.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Mar 2022 04:06:37 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int e, v;
    bool operator< (const node &b) const {
        return this->v > b.v;
    }
};
struct edge {
    int e, v, next;
};
edge edg[200005];
int head[100005], mark[100005],num[100005], n, x, cnt, edg_cnt ,ans;
void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(num, 0x3f, sizeof(num));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            add_edg(i, j, x);
        }
    }
    priority_queue<node> que;
    que.push((node){n, 0});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.e] == 1) {
            continue;
        }
        mark[temp.e] = 1;
        ans += temp.v;
        cnt++;
        if (cnt == n) {
            cout << ans << endl;
            return 0;
        }
        for (int i = head[temp.e]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (mark[e] == 0 && num[e] > v) {
                num[e] = v;
                que.push((node){e, v});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

