/*************************************************************************
	> File Name: all_toposort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2022 07:03:37 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int n, m, f, num[105], in_degree[105], mark[105];
void func(int now, vector<vector<int> > &edg) {
    if (now == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << num[i] << " ";
        }
        f = 1;
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0 && mark[i] == 0) {
            num[now] = i;
            mark[i] = 1;
            for (int j = 0; j < edg[i].size(); j++) {
                in_degree[edg[i][j]]--;
            }
            func(now + 1, edg);
            mark[i] = 0;
            for (int j = 0; j < edg[i].size(); j++) {
                in_degree[edg[i][j]]++;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    vector<vector<int> > edg(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in_degree[b]++;
        edg[a].push_back(b);
    }
    func(1, edg);
    if (f == 0) {
        cout << "no" << endl;
    }
    return 0;
}
