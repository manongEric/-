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
edge edg[50005];
int head[1505], mark[1505], n, m, s, edg_cnt, ans[1505];
void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;

} 
void init() {
    for (int i = 1; i <= n; i++) {
        ans[i] = -2100000000;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    init();
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edg(a, b, c);
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
           // cout << e << endl;
            if (ans[e] < ans[temp] + v) {
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
        }
    }
        if (ans[n] == -2100000000) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", ans[n]);
        }
    return 0;
}

