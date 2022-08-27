/*************************************************************************
	> File Name: 1144_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 08:10:26 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
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
int n, m, ans[1000005], ans_cnt[1000005];
int main() {
    memset(ans, 0x3f, sizeof(ans));
    scanf("%d%d", &n, &m);
    vector<vector<edge> > edg(n + 1, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edg[a].push_back((edge){b, 1});
        edg[b].push_back((edge){a, 1});
    }
    priority_queue<node> que;
    que.push({1, 0});
    ans[1] = 0;
    ans_cnt[1] = 1;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dis > ans[temp.now]) continue;
        for (int i = 0; i < edg[temp.now].size(); i++) {
            int e = edg[temp.now][i].e, v = edg[temp.now][i].v;
            if (ans[e] > temp.dis + v) {
                ans[e] = temp.dis + v;
                ans_cnt[e] = ans_cnt[temp.now];
                que.push({e, ans[e]});
            } else if (ans[e] == temp.dis + v){
                ans_cnt[e] += ans_cnt[temp.now];
            }
        }
    }
   // cout << ans[4] << " " << ans_cnt[4] << endl;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            printf("%d\n", 1);
        } else {
            printf("%d\n" ,ans_cnt[i] % 100003);
        }
    }
    return 0;
}
