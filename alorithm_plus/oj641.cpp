/*************************************************************************
	> File Name: toposort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2022 04:50:58 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct edge {
    int e, next;
};
edge edg[400005];
int n, m, cnt, head[2005], in_degree[2005], num[2005];
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in_degree[b]++;
        edg[i].e = b;
        edg[i].next = head[a];
        head[a] = i;
    }
    priority_queue<int, vector<int>, greater<int> > que; 
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int temp = que.top();
        que.pop();
        num[cnt] = temp;
        cnt++;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    if (cnt != n) {
        cout << "no" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return 0;
}
