/*************************************************************************
	> File Name: dijkstra_746_vec.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Mar 2022 11:00:07 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
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
    int e, v;
};
int n, m, s, ans[100005];
int main() {
    memset(ans, 0x3f, sizeof(ans));
    scanf("%d%d%d", &n, &m, &s);
    vector<vector<edge> > edg(n + 1, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edg[a].push_back((edge){b, c});
        edg[b].push_back((edge){a, c});
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
        for (int i = 0; i < edg[temp.now].size(); i++) {
            int e = edg[temp.now][i].e, v = edg[temp.now][i].v;
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
