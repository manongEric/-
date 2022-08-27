/*************************************************************************
	> File Name: oj637.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Jan 2022 06:35:49 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

int n, m, in_degree[30], cnt;
char ans[30];

int func(vector<vector<int> > &edg) {
    cnt = 0;
    int in[30], qcnt = 0;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        in[i] = in_degree[i];
        if (in[i] == 0) {
            que.push(i);
  //          cout << que.front() << endl;
        }
    }
//        cout << que.size() << " size "<<endl;

    while(!que.empty()) {
        qcnt = max(qcnt, (int)que.size());
       // cout << qcnt << " " <<"qcnt" << endl;
        int temp = que.front();
        que.pop();
        ans[cnt++] = temp + 'A';
        for (auto e : edg[temp]) {
            in[e]--;
            if (in[e] == 0) {
                que.push(e);
            }
        }
    }
   // cout << qcnt << endl;
        if (cnt < n) {
            return 1;
        }
        if (qcnt == 1) {
            return 2;
        }
        return 0;
}
int main() {
    cin >> n >> m;
    vector<vector<int> > edg(n, vector<int>());
    for (int i = 1; i <=m; i++) {
        char t[4];
        cin >> t;
        int a = t[0] - 'A', b = t[2] - 'A';
        edg[a].push_back(b);
        in_degree[b]++;
        cout << in_degree[a] << "a" << in_degree[b] << "b"<<endl;
        int x = func(edg);
        if (x == 1) {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
        if (x == 2) {
            printf("Sorted sequence determined after %d relations: %s.\n", i, ans);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}

