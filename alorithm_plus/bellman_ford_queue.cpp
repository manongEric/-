/*************************************************************************
	> File Name: bellman_ford_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 04:35:59 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct edge {
    int e, v, next;
};
edge edg[200005];
int head[100005], mark[100005], n, m, s, edg_cnt, ans[100005];
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
        add_edg(b, a ,c);
    }
    queue<int> que;
    que.push(s);
    ans[s] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) {
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
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

