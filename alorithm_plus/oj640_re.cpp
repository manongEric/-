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
int in_degree[5005], ans[5005], out_degree[5005], n, m;
int main() {
    cin >> n >> m;
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
            in_degree[e]--;
            ans[e] = (ans[e] + ans[temp]) % 100000007 ;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            sum = (sum + ans[i]) % 100000007;
        }
    }
    cout << sum << endl;
    return 0;
}

