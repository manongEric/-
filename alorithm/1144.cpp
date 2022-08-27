/*************************************************************************
	> File Name: 1144.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Jan 2022 06:28:11 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
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
edge edg[4000005];
int n, m, edg_cnt, head[2000005], ans_cnt[2000005], ans[2000005];


void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = 1;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue <node> que;
    que.push((node){1, 0});
    ans[1] = 0;
    ans_cnt[1] = 1;
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (ans[temp.now] < temp.dis) {
            continue;
        }
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp.now] + v) {
                ans[e] = ans[temp.now] + v;
                que.push((node){e, ans[e]});
                ans_cnt[e] = ans_cnt[temp.now] % 100003;
            }else if (ans[e] == ans[temp.now] + v) {
                ans_cnt[e]  = (ans_cnt[e] + ans_cnt[temp.now]) % 100003;
            }
        }
    }  
    for (int i = 1; i <= n; i++) {
        cout << ans_cnt[i] % 100003 << endl;
    }
    
}

