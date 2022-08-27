/*************************************************************************
	> File Name: oj638_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Apr 2022 02:04:08 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct edge{
    int e, v;
};
int mark[1505], in_degree[1505], ans[1505], n, m;
int func(int now, vector<vector<edge>> &edg) {
    if (now == n) {
        return 1;
    }
    for (int i = 0; i < edg[now].size(); i++) {
        int e = edg[now][i].e;
        if (mark[e] == 0) {
            mark[e] = 1;
            if (func(e, edg) == 1) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    cin >> n >> m;
    vector<vector<edge>> edg(n + 1, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        in_degree[b]++;
        edg[a].push_back({b, c});
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        ans[i] = -2100000000;
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    ans[1] = 0;
    if (func(1, edg) == 0) {
        cout << -1 << endl;
        return 0;
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        for (int i = 0; i < edg[temp].size(); i++) {
            int e = edg[temp][i].e, v = edg[temp][i].v;
            ans[e] = max(ans[e], ans[temp] + v);
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    cout << ans[n] << endl;
    return 0;
}
