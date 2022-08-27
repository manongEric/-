/*************************************************************************
	> File Name: 1629.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Mar 2022 08:16:22 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct edge {
    int e, v, next;
};
edge edg[2][100005];
int n, m, head[2][1005], ans[2][1005], mark[1005];
void add_edg(int ind, int cnt ,int a, int b, int c) {
    edg[ind][cnt].e = b;
    edg[ind][cnt].v = c;
    edg[ind][cnt].next = head[ind][a];
    head[ind][a] = cnt; 
}
void func(int ind) {
    queue<int> que;
    que.push(1);
    ans[ind][1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[ind][temp]; i != -1; i = edg[ind][i].next) {
            int e = edg[ind][i].e, v = edg[ind][i].v;
            if (ans[ind][e] > ans[ind][temp] + v) {
                ans[ind][e] = ans[ind][temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
        }
    }
}
int main() {
    memset(ans,0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(0, i, a, b, c);
        add_edg(1, i, b, a, c);
    }
    func(0);
    func(1);
    long long t = 0;
    for (int i = 1; i <= n; i++) {
        t += ans[0][i] + ans[1][i];
    }
    cout << t << endl;
    return 0;
} 
