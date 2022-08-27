/*************************************************************************
	> File Name: oj636.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2022 04:26:01 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
int in_degree[100005], ans[100005], n, m;
int main() {
    cin >> n >> m;
    vector<vector<int> > edg(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        in_degree[b]++;
        edg[a].push_back(b);
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            ans[i] = 1;
            que.push(i);
        }
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        for (int i = 0; i < edg[temp].size(); i++) {
            int e = edg[temp][i];
            in_degree[e]--;
            if (in_degree[e] == 0) {
                ans[e] = ans[temp] + 1;
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

