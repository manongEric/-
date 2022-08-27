/*************************************************************************
	> File Name: oj636.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Jan 2022 09:39:14 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int n, m, t,ans[5005], in_degree[5005], out_degree[5005];
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
        for (int i = 0; i < edg[temp].size(); i++) {
            int e = edg[temp][i];
            in_degree[e]--;
            ans[e] += ans[temp];
            ans[e] %= 10000007;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0){
            t += ans[i];
        }
    }
    cout << t  << endl;
    return 0;
}

