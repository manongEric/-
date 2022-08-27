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
int n, m, cnt, qcnt, num[105], head[105], in_degree[105];

void quick_sort(int *num, int l, int r) {
    if (l > r) return;
    int x = l, y = r, z = num[x];
    while (x < y) {
        while(x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
            while(x < y && num[x] < z) x++;
            if (x < y) num[y--] = num[x];
        }
        num[x] = z;
        quick_sort(num, l, x - 1);
        quick_sort(num, x + 1, r);
    }
int toposort(edge* edg) {
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        qcnt = max(qcnt, (int)que.size());
        cout << que.size()  << " size"<< endl;
        cout << que.front() << " f " << endl;
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
    return qcnt;
}
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
    int q = toposort(edg);
    if (qcnt != 1) {
        quick_sort(num, 0, cnt - 1);
    }
    for (int i = 0; i < cnt; i++) {
        if (i != 0) {
            cout << " " << num[i];
        }else cout << num[i]; 
    }
    cout << endl;

    return 0;
}

