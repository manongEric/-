/*************************************************************************
	> File Name: oj636_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Apr 2022 10:33:48 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int in_degree[100005], ans[100005], n, m;
int main() {
    scanf("%d%d", &n, &m);
    vector<vector<int>> edg(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edg[a].push_back(b);
        in_degree[b]++;
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
            ans[e] = ans[temp] + 1;
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]); 
    }
    return 0;
}
