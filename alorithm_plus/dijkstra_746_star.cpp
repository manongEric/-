/*************************************************************************
	> File Name: dijkstra_746_star.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 02:33:05 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int now, dis;
    bool operator<(const node &b) const{
        return this->dis > b.dis;
    }
};
struct edge{
    int e, v, next;
};
edge edg[200005];
priority_queue<node> que;
int n, m, s, edg_cnt, head[100005], ans[100005];
void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    que.push((node){s, 0});
    ans[s] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dis > ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > temp.dis + v) {
                ans[e] = temp.dis + v;
                que.push((node){e, ans[e]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            cout << -1 << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
