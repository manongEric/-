/*************************************************************************
	> File Name: oj640.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2022 07:22:47 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n, m, in_degree[5005], out_degree[5005], ans[5005];
int main() {
    scanf("%d%d", &n, &m);
    vector<vector<int> > edg(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        in_degree[b]++;
        out_degree[a]++;
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
        for (auto e : edg[temp]) {
            ans[e] += ans[temp];
            ans[e] %= 100000007;
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            ans[i] %= 100000007;
            sum += ans[i];
        }
    }
    cout << sum << endl;
    return 0;
}

