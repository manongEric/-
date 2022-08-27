/*************************************************************************
	> File Name: toposort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Jan 2022 10:28:53 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct edge {
    int e, next;
};
edge edg[1005];
int n, m, cnt, num[105], head[105], in_degree[105];

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
    
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int temp = que.front();
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
    }
    for (int i = 0; i < cnt; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}

