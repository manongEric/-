/*************************************************************************
	> File Name: dijkstra_746_vec.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Mar 2022 11:00:07 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct node {
    int now, dis;
    bool operator< (const node &b) const {
        return this->dis > b.dis;
    }
};
struct edge {
    int e, v, next;
};
edge edg[200005];
int n, m, s, ans[100005], head[100005], edg_cnt;
void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue<node> que;
    que.push((node){s, 0});
    ans[s] = 0;
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dis > ans[temp.now]) {
            continue;
        }
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
            printf("%d\n", -1);
        } else {
            printf("%d\n", ans[i]);
        }
    }


    return 0;
}
