/*************************************************************************
	> File Name: bellman_ford_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Jan 2022 04:25:34 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct edge{
    int e, v, next;
};

edge edg[2000005];
int n, m, s, edg_cnt, head[100005], ans[100005], mark[100005];

void add_cnt(int a, int b, int c) {
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
        add_cnt(a, b, c);
        add_cnt(b, a, c);
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
            cout << -1 << endl;
        }
        cout << ans[i] << endl;
    }


    return 0;
}

