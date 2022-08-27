/*************************************************************************
	> File Name: all_toposort_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 11:09:31 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int num[105], in_degree[105], n, m, f, mark[105];
void func(int now, vector<vector<int>> &edg) {
    if (now == n + 1) {
        for (int i = 1; i <= n; i++) {
            if (i != 1) cout << " ";
            cout << num[i];
        }
        cout << endl;
        f = 1;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0 && mark[i] == 0) {
            mark[i] = 1;
            num[now] = i;
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

    return 0;
}
