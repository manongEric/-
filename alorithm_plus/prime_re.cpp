/*************************************************************************
	> File Name: prime_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 04:01:25 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int e, v;
    bool operator< (const node &b) const{
        return this->v > b.v;
    }
};
struct edge {
    int e, v, next;
};
edge edg[200005];
int num[100005], head[100005], mark[100005], n, m, cnt, ans, edg_cnt;
void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(num, 0x3f, sizeof(num));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue<node> que;
    que.push({n, 0});
        while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.e] == 1) {
            continue;
        }
        ans += temp.v;
        cnt++;
        if (cnt == n) {
            cout << ans << endl;
            return 0;
        }
        mark[temp.e] = 1;
        for (int i = head[temp.e]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (mark[e] == 0 && num[e] > v) {
                num[e] = v;
                que.push({e, v});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

