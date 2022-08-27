/*************************************************************************
	> File Name: dijkstra_746.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Mar 2022 04:30:13 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{
    int now, dis;
    bool operator< (const node &b) const{
        return this->dis > b.dis;
    }
};
struct edge{
    int e, v;
};
int n, m, ans[1000005], ans_cnt[1000005];
int main() {
    memset(ans, 0x3f, sizeof(ans));
    //cin >> n >> m >> s;
    scanf("%d%d", &n, &m);
    vector<vector<edge> > edg(n + 1, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
       // cin >> a >> b >> c;
        scanf("%d%d", &a, &b);
        edg[a].push_back((edge){b, 1});
        edg[b].push_back((edge){a, 1});
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    ans[1] = 0;
    ans_cnt[1] = 1;
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dis > ans[temp.now]) {
            continue;
        }
        for (int i = 0; i < edg[temp.now].size(); i++) {
            int e = edg[temp.now][i].e, v = edg[temp.now][i].v;
            if (ans[e] > ans[temp.now] + v) {
                ans[e] = ans[temp.now] + v;
                ans_cnt[e] = ans_cnt[temp.now] % 100003; 
                que.push((node){e, ans[e]});
            } else if (ans[e] == ans[temp.now] + v) {
                ans_cnt[e] = (ans_cnt[temp.now] + ans_cnt[e]) % 100003;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans_cnt[i]);
    }
    return 0;
}

