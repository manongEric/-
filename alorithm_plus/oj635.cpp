/*************************************************************************
	> File Name: oj635.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2022 11:08:13 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct edge{
    int e, v;
};
int n, m, c[105], u[105], in_degree[105], out_degree[105];
int main() {
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        if (c[i] != 0) {
            que.push(i);
        }
    }
    vector<vector<edge> > edg(n + 1, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        in_degree[b]++;
        out_degree[a]++;
        edg[a].push_back((edge){b, c});
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        for (int i = 0; i < edg[temp].size(); i++) {
            int e = edg[temp][i].e, v = edg[temp][i].v;
            in_degree[e]--;
            if (c[temp] > 0) {
                c[e] += c[temp] * v;
            }
            if (in_degree[e] == 0) {
                que.push(e);
                c[e] -= u[e];
            }
        }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0 && c[i] > 0) {
            cout << i << " " << c[i] << endl;
            f = 1;
        }
    }
    if (f == 0) {
        cout << "NULL" << endl;
    }
    return 0;
}

